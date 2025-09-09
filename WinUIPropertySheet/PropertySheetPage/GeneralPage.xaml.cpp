#include "pch.h"
#include "GeneralPage.xaml.h"
#if __has_include("GeneralPage.g.cpp")
#include "GeneralPage.g.cpp"
#endif
#include <winrt/Microsoft.UI.Xaml.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::PropertySheetPage::implementation
{
	void GeneralPage::OnSave()
	{
		ContentTextBlock().Text(L"General Page Saved");
	}
	winrt::hstring GeneralPage::GetTitle()
	{
		return L"General Page";
	}
	winrt::Microsoft::UI::Xaml::UIElement GeneralPage::GetXamlContent()
	{
		return *this;
	}
}
