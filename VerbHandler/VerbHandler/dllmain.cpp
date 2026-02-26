#include "pch.h"
#include "pch.h"
#include <wrl/module.h>
#include <shobjidl_core.h>
#include <shlwapi.h>
#include "VerbHandler.h"
#include "VerbHandlerClassFactory.h"

using namespace Microsoft::WRL;
using namespace PropertiesVerb;

HINSTANCE g_hInstance = nullptr;
LONG g_dllRefCount = 0;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID /*lpReserved*/)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        g_hInstance = hModule;
        DisableThreadLibraryCalls(hModule);
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

STDAPI DllGetClassObject(REFCLSID clsid, REFIID riid, void** ppv)
{
    if (!ppv)
    {
        return E_POINTER;
    }
    *ppv = nullptr;

    if (clsid == CLSID_VerbHandler)
    {
        auto factory = Make<VerbHandlerClassFactory<VerbHandler>>();
        return factory->QueryInterface(riid, ppv);
    }

    return CLASS_E_CLASSNOTAVAILABLE;
}

STDAPI DllCanUnloadNow()
{
    return Module<InProc>::GetModule().GetObjectCount() == 0 ? S_OK : S_FALSE;
}

static HRESULT SetRegistryKeyValue(HKEY hkeyRoot, PCWSTR pszKeyName, PCWSTR pszValueName, PCWSTR pszValue)
{
    HKEY hkey;
    LONG result = RegCreateKeyExW(hkeyRoot, pszKeyName, 0, nullptr, REG_OPTION_NON_VOLATILE, KEY_SET_VALUE, nullptr, &hkey, nullptr);
    if (result != ERROR_SUCCESS)
    {
        return HRESULT_FROM_WIN32(result);
    }
    result = RegSetValueExW(hkey, pszValueName, 0, REG_SZ, reinterpret_cast<const BYTE*>(pszValue), static_cast<DWORD>((wcslen(pszValue) + 1) * sizeof(WCHAR)));
    RegCloseKey(hkey);
    return HRESULT_FROM_WIN32(result);
}

static HRESULT RegisterClsid(REFCLSID clsid, PCWSTR pszName)
{
    WCHAR szClsid[40];
    if (StringFromGUID2(clsid, szClsid, ARRAYSIZE(szClsid)) == 0)
    {
        return E_FAIL;
    }

    WCHAR szModulePath[MAX_PATH];
    if (GetModuleFileNameW(g_hInstance, szModulePath, ARRAYSIZE(szModulePath)) == 0)
    {
        return HRESULT_FROM_WIN32(GetLastError());
    }

    WCHAR szKey[128];
    wsprintfW(szKey, L"SOFTWARE\\Classes\\CLSID\\%s", szClsid);
    HRESULT hr = SetRegistryKeyValue(HKEY_LOCAL_MACHINE, szKey, nullptr, pszName);
    if (FAILED(hr)) return hr;

    wsprintfW(szKey, L"SOFTWARE\\Classes\\CLSID\\%s\\InProcServer32", szClsid);
    hr = SetRegistryKeyValue(HKEY_LOCAL_MACHINE, szKey, nullptr, szModulePath);
    if (FAILED(hr)) return hr;

    return SetRegistryKeyValue(HKEY_LOCAL_MACHINE, szKey, L"ThreadingModel", L"Apartment");
}

static HRESULT UnregisterClsid(REFCLSID clsid)
{
    WCHAR szClsid[40];
    if (StringFromGUID2(clsid, szClsid, ARRAYSIZE(szClsid)) == 0)
    {
        return E_FAIL;
    }

    WCHAR szKey[128];
    wsprintfW(szKey, L"SOFTWARE\\Classes\\CLSID\\%s\\InProcServer32", szClsid);
    RegDeleteKeyW(HKEY_LOCAL_MACHINE, szKey);

    wsprintfW(szKey, L"SOFTWARE\\Classes\\CLSID\\%s", szClsid);
    LONG result = RegDeleteKeyW(HKEY_LOCAL_MACHINE, szKey);
    return HRESULT_FROM_WIN32(result);
}

STDAPI DllRegisterServer()
{
    HRESULT hr = RegisterClsid(CLSID_VerbHandler, L"VerbHandler");
     return hr;

}

STDAPI DllUnregisterServer()
{
    UnregisterClsid(CLSID_VerbHandler);
    return S_OK;
}
