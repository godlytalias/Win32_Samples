#include "pch.h"
#include "PropSheetWindow.xaml.h"
#if __has_include("PropSheetWindow.g.cpp")
#include "PropSheetWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::PropertySheetWinUI::implementation
{
    void PropSheetWindow::AddPage(winrt::PropertySheetWinUI::IWinUIPropSheetPage page)
    {
        auto tabViewItem = winrt::Microsoft::UI::Xaml::Controls::TabViewItem();
        tabViewItem.Header(winrt::box_value(page.GetTitle()));
        tabViewItem.Content(page.GetXamlContent());
        tabViewItem.IsClosable(false);
        PropertySheetTabView().TabItems().Append(tabViewItem);
        PropertySheetTabView().SelectedItem(tabViewItem);
	}

    void PropSheetWindow::OnOkClickedEvent(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&)
    {
        m_propertySheetSave(*this, nullptr);
        Close();
	}

    void PropSheetWindow::OnApplyClickedEvent(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&)
    {
        m_propertySheetSave(*this, nullptr);
    }

    winrt::event_token PropSheetWindow::PropertySheetSave(winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Foundation::IInspectable, winrt::Microsoft::UI::Xaml::RoutedEventArgs> const& handler)
    {
        return m_propertySheetSave.add(handler);
    }

    void PropSheetWindow::PropertySheetSave(winrt::event_token const& token) noexcept
    {
        m_propertySheetSave.remove(token);
    }
}
