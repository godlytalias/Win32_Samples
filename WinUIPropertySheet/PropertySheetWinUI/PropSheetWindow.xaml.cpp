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
    void PropSheetWindow::AddPage(winrt::PropertySheetWinUI::WinUIPropSheetPage page)
    {
        auto tabViewItem = winrt::Microsoft::UI::Xaml::Controls::TabViewItem();
        tabViewItem.Header(winrt::box_value(page.Title()));
        tabViewItem.Content(page.Content());
        tabViewItem.IsClosable(false);
        PropertySheetTabView().TabItems().Append(tabViewItem);
        PropertySheetTabView().SelectedItem(tabViewItem);
	}
}
