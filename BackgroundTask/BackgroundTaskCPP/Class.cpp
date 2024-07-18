#include "pch.h"
#include "Class.h"
#if __has_include("Class.g.cpp")
#include "Class.g.cpp"
#endif
#include "winrt/Windows.UI.Notifications.h"
#include "winrt/Windows.Data.Xml.Dom.h"

using namespace winrt;
using namespace Windows::Data::Xml::Dom;
using namespace Windows::UI::Notifications;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::BackgroundTaskCPP::implementation
{
    int32_t Class::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void Class::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void Class::Run(const Windows::ApplicationModel::Background::IBackgroundTaskInstance& taskInstance)
    {
        createNotification();
    }

    void Class::createNotification()
    {
        // Create the toast XML template
        XmlDocument toastXml;
        toastXml.LoadXml(LR"(
        <toast>
            <visual>
                <binding template="ToastGeneric">
                    <text>Background Task Execution</text>
                    <text>This is to notify that Background Task have been executed</text>
                </binding>
            </visual>
        </toast>)");

        // Create the toast notification
        ToastNotification toast(toastXml);

        // Create a ToastNotifier and show the toast
        ToastNotificationManager::CreateToastNotifier().Show(toast);
    }
}
