#include "pch.h"
#include "RegisterForCom.h"
#include "Win32BGClass.h"

using namespace winrt;

namespace winrt::WinMainCOMBGTaskSample
{
    RegisterForCom::~RegisterForCom()
    {
        if (ComRegistrationToken != 0)
        {
            CoRevokeClassObject(ComRegistrationToken);
        }
    }

    hresult RegisterForCom::RegisterAndWaitSingle(guid classId)
    {
        hresult hr;
        try
        {
            handle _taskFactoryCompletionEvent{ CreateEvent(nullptr, false, false, nullptr) };
            com_ptr<IClassFactory> taskFactory = make<Win32BGTaskFactory>();
            // Verify the global handle is correctly constructed.
            //check_bool(bool{ Win32BGTaskFactory::_taskFactoryCompletionEvent });

            check_hresult(CoRegisterClassObject(classId,
                taskFactory.get(),
                CLSCTX_LOCAL_SERVER,
                REGCLS_MULTIPLEUSE,
                &ComRegistrationToken));

            check_hresult(WaitForSingleObject(_taskFactoryCompletionEvent.get(),
                INFINITE));

            hr = S_OK;
        }
        catch (...)
        {
            hr = to_hresult();
        }

        return hr;
    }
};