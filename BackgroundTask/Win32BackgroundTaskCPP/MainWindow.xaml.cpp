#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
#include <winrt/Windows.ApplicationModel.Background.h>
#include "winrt/Windows.UI.Notifications.h"
#include "winrt/Windows.Data.Xml.Dom.h"
#include "winrt/Windows.Storage.h"

using namespace winrt;
using namespace winrt::Windows::Foundation;
using namespace Microsoft::UI::Xaml;
using namespace Windows::Data::Xml::Dom;
using namespace Windows::UI::Notifications;
using namespace Windows::ApplicationModel::Background;
using namespace Windows::Storage;
using namespace std;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Win32BackgroundTaskCPP::implementation
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
        myButton().Content(box_value(L"BG Task Registered, Check Notifications"));
        BackgroundTaskBuilder builder;
        builder.Name(L"SampleBackgroundTask");
        //StorageFolder folder = co_await StorageFolder::GetFolderFromPathAsync(L"C:\\Users\\godlyalias\\Downloads\\");
        //StorageLibraryChangeTracker tracker = folder.TryGetChangeTracker();
        //if (tracker != nullptr)
        //{
        //    tracker.Enable();
        //    StorageLibraryChangeTrackerTrigger trigger{ tracker };
        //    auto backgroundTrigger = trigger.as<IBackgroundTrigger>();
        //    builder.SetTrigger(backgroundTrigger);
        //    builder.TaskEntryPoint(L"BackgroundTaskCPP.Class");
        //    builder.Register();
        //    createNotification();
        //}

        //MaintenanceTrigger trigger{ 15, false };

        ToastNotificationHistoryChangedTrigger trigger;
        auto backgroundTrigger = trigger.as<IBackgroundTrigger>();
        builder.SetTrigger(backgroundTrigger);
        builder.TaskEntryPoint(L"BackgroundTaskCPP.Class");
        builder.Register();
        createNotification();
    }

    void MainWindow::createNotification()
    {
        // Create the toast XML template
        XmlDocument toastXml;
        toastXml.LoadXml(LR"(
        <toast>
            <visual>
                <binding template="ToastGeneric">
                    <text>Notification from Win32BackgroundTaskCPP</text>
                    <text>Delete this notification to trigger background task.</text>
                </binding>
            </visual>
        </toast>)");

        // Create the toast notification
        ToastNotification toast(toastXml);

        // Create a ToastNotifier and show the toast
        ToastNotificationManager::CreateToastNotifier().Show(toast);
    }
}
