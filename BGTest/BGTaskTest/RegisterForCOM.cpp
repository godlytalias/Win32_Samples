#include "pch.h"
#include "RegisterForCom.h"
#include "Win32BGClass.h"

using namespace winrt;

namespace winrt::BGTaskTest
{
    RegisterForCom::~RegisterForCom()
    {
        if (ComRegistrationToken != 0)
        {
            CoRevokeClassObject(ComRegistrationToken);
        }
    }

    hresult RegisterForCom::RegisterAndWait(guid classId)
    {
        hresult hr;
        try
        {
            handle _taskFactoryCompletionEvent{ CreateEvent(nullptr, false, false, nullptr) };
            com_ptr<IClassFactory> taskFactory = make<Win32BGTaskFactory>();

            check_hresult(CoRegisterClassObject(classId,
                taskFactory.detach(),
                CLSCTX_LOCAL_SERVER,
                REGCLS_MULTIPLEUSE,
                &ComRegistrationToken));

            OutputDebugString(L"COM Registraton done");
            hr = S_OK;
        }
        catch (...)
        {
            hr = to_hresult();
        }

        return hr;
    }
};