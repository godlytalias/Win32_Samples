#include "pch.h"
#include "AdvancedPage.xaml.h"
#if __has_include("AdvancedPage.g.cpp")
#include "AdvancedPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::PropertySheetPage::implementation
{
	void AdvancedPage::OnSave()
	{
		ContentTextBlock().Text(L"Advanced Page Saved");
	}
	winrt::hstring AdvancedPage::GetTitle()
	{
		return L"Advanced Page";
	}
	winrt::Microsoft::UI::Xaml::UIElement AdvancedPage::GetXamlContent()
	{
		return *this;
	}
}
