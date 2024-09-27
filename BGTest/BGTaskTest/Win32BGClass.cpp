#include "pch.h"
#include "Win32BGClass.h"
#include "winrt/Windows.Data.Xml.Dom.h"
#include "winrt/Windows.UI.Notifications.h"

using namespace winrt;
namespace winrt
{
    using namespace winrt::Windows::ApplicationModel::Background;
    using namespace Windows::Data::Xml::Dom;
    using namespace Windows::UI::Notifications;
}

namespace winrt::BGTaskTest {

    void __stdcall Win32BGTask::Run(_In_ IBackgroundTaskInstance taskInstance)
    {
        OutputDebugString(L"BG Task Run");
        taskInstance.Canceled({ this, &Win32BGTask::OnCanceled });

        TaskDeferral = taskInstance.GetDeferral();
        CreateNotification();

        TaskDeferral.Complete();
    }

    void Win32BGTask::CreateNotification()
    {
        // Create the toast XML template
        XmlDocument toastXml;
        toastXml.LoadXml(LR"(
        <toast>
            <visual>
                <binding template="ToastGeneric">
                    <text>Background Task Execution IN WIN32</text>
                    <text>This is to notify that Background Task have been executed</text>
                </binding>
            </visual>
        </toast>)");

        // Create the toast notification
        winrt::ToastNotification toast(toastXml);

        // Create a ToastNotifier and show the toast
        winrt::ToastNotificationManager::CreateToastNotifier().Show(toast);
    }

    void __stdcall Win32BGTask::OnCanceled(_In_ IBackgroundTaskInstance /* taskInstance */, _In_ BackgroundTaskCancellationReason /* cancelReason */)
    {
        OutputDebugString(L"BG Task Cancelled");
        IsCanceled = true;
    }

}