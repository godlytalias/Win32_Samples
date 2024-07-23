#include "pch.h"
#include "Win32BGClass.h"

using namespace winrt;
namespace winrt
{
    using namespace winrt::Windows::ApplicationModel::Background;
}

namespace winrt::WinMainCOMBGTaskSample {

        void Win32BGTask::Run(_In_ IBackgroundTaskInstance taskInstance)
        {
            OutputDebugString(L"BG Task Run");

            taskInstance.Canceled({ this, &Win32BGTask::OnCanceled });

            TaskDeferral = taskInstance.GetDeferral();

            //check_bool(SetEvent(Win32BGTaskFactory::_taskFactoryCompletionEvent.get()));
            TaskDeferral.Complete();
        }

        void Win32BGTask::OnCanceled(_In_ IBackgroundTaskInstance /* taskInstance */, _In_ BackgroundTaskCancellationReason /* cancelReason */)
        {
            OutputDebugString(L"BG Task Cancelled");
            IsCanceled = true;
        }

}