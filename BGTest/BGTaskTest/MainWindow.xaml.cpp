#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
#include <winrt/Microsoft.Windows.ApplicationModel.Background.h>
#include "Win32BGClass.h"
#include "winrt/Windows.Data.Xml.Dom.h"
#include "winrt/Windows.UI.Notifications.h"

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::Windows::ApplicationModel::Background;

using namespace Windows::Data::Xml::Dom;
using namespace Windows::UI::Notifications;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::BGTaskTest::implementation
{
    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainWindow::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {

        // Create the toast XML template
        XmlDocument toastXml;
        toastXml.LoadXml(LR"(
        <toast>
            <visual>
                <binding template="ToastGeneric">
                    <text>Notification: BGTaskTest</text>
                    <text>Delete this notification to trigger BGTask</text>
                </binding>
            </visual>
        </toast>)");

        // Create the toast notification
        ToastNotification toast(toastXml);

        // Create a ToastNotifier and show the toast
        ToastNotificationManager::CreateToastNotifier().Show(toast);



        myButton().Content(box_value(L"Clicked"));
        BackgroundTaskBuilder builder;

        builder.Name(L"12345678-1234-1234-1234-1234567890CD");
        winrt::Windows::ApplicationModel::Background::ToastNotificationHistoryChangedTrigger trigger;
        auto backgroundTrigger = trigger.as<winrt::Windows::ApplicationModel::Background::IBackgroundTrigger>();
        builder.SetTrigger(backgroundTrigger);
        builder.TaskEntryPoint(L"12345678-1234-1234-1234-1234567890CD");
        builder.Register();
    }
}
