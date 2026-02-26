#include "pch.h"
#include "VerbHandler.h"

namespace PropertiesVerb
{
    IFACEMETHODIMP VerbHandler::SetSelection(IShellItemArray* psia)
    {
        _pSelection.Reset();
        if (psia)
        {
            return psia->QueryInterface(IID_PPV_ARGS(&_pSelection));
        }
        return S_OK;
    }

    IFACEMETHODIMP VerbHandler::GetSelection(REFIID riid, void** ppv)
    {
        *ppv = nullptr;
        return _pSelection ? _pSelection->QueryInterface(riid, ppv) : E_FAIL;
    }

    // IExecuteCommand
    IFACEMETHODIMP VerbHandler::SetKeyState(DWORD grfKeyState)
    {
        _grfKeyState = grfKeyState;
        return S_OK;
    }

    IFACEMETHODIMP VerbHandler::SetParameters(PCWSTR /* pszParameters */)
    {
        return S_OK;
    }

    IFACEMETHODIMP VerbHandler::SetPosition(POINT /* pt */)
    {
        return S_OK;
    }

    IFACEMETHODIMP VerbHandler::SetShowWindow(int /* nShow */)
    {
        return S_OK;
    }

    IFACEMETHODIMP VerbHandler::SetNoShowUI(BOOL /* fNoShowUI */)
    {
        return S_OK;
    }

    IFACEMETHODIMP VerbHandler::SetDirectory(PCWSTR /* pszDirectory */)
    {
        return S_OK;
    }

    IFACEMETHODIMP VerbHandler::Execute()
    {
        ShowVerbMessage(_pSelection.Get());
        return S_OK;
    }

    void VerbHandler::ShowVerbMessage(IShellItemArray* psia)
    {
        WCHAR szMessage[2048] = L"Verb executed from new DLL\r\n";

        if (psia)
        {
            DWORD count = 0;
            if (SUCCEEDED(psia->GetCount(&count)))
            {
                for (DWORD i = 0; i < count; i++)
                {
                    Microsoft::WRL::ComPtr<IShellItem> psi;
                    if (SUCCEEDED(psia->GetItemAt(i, &psi)))
                    {
                        PWSTR pszName = nullptr;
                        if (SUCCEEDED(psi->GetDisplayName(SIGDN_FILESYSPATH, &pszName)))
                        {
                            StringCchCatW(szMessage, ARRAYSIZE(szMessage), L"\r\n");
                            StringCchCatW(szMessage, ARRAYSIZE(szMessage), pszName);
                            CoTaskMemFree(pszName);
                        }
                    }
                }
            }
        }

        MessageBoxW(nullptr, szMessage, L"VerbHandler", MB_OK);
    }
}