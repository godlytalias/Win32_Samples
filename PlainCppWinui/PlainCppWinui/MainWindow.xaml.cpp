#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
#include "App.xaml.h"
#include "microsoft.ui.xaml.window.h"
#include "winrt/windows.applicationmodel.background.h"
#include "winrt/Microsoft.UI.Xaml.Controls.h"
#include "winrt/Windows.Foundation.h"
using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::PlainCppWinui::implementation
{
    MainWindow::MainWindow()
    {
        m_icon = BitmapIcon();
        m_icon.UriSource(Windows::Foundation::Uri(L"ms-appx:///Assets/StoreLogo.png"));
    }

    MenuFlyout MainWindow::createFlyout()
    {
	    m_flyout = MenuFlyout();
	    m_flyout.Opened({ this, &MainWindow::flyoutOpened });
	    RadioMenuFlyoutItem item = RadioMenuFlyoutItem();
	    item.Icon(m_icon);
	    item.Text(L"Hello World");
        m_flyout.Items().Append(item);
	    return m_flyout;
    }
    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainWindow::fixIconIssue()
    {
        m_icon = BitmapIcon();
        m_icon.UriSource(Windows::Foundation::Uri(L"ms-appx:///Assets/StoreLogo.png"));
    }

    void MainWindow::flyoutOpened(IInspectable const& handler, IInspectable const&)
    {
        // Below operations mimics async operations of re-parenting BitmapIcon to another RadioMenuFlyoutItem
        Microsoft::UI::Dispatching::DispatcherQueue queue = Microsoft::UI::Dispatching::DispatcherQueue::GetForCurrentThread();
        queue.TryEnqueue([this] {
            m_flyout.Items().Clear();
            //FIX: Uncomment below function call to fix issue with icon re-parenting
            //fixIconIssue();
            RadioMenuFlyoutItem item2 = RadioMenuFlyoutItem();
            // FIXME: At this point, m_icon gets re-parented which causes association failures
            item2.Icon(m_icon);
            item2.Text(L"Hello World");
            m_flyout.Items().Append(item2);
        });
    }

    void MainWindow::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        createFlyout().ShowAt(myButton());
    }
}
