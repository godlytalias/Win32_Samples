#pragma once
#include "Windows.Foundation.h"
#include "WinUIPropertySheet.g.h"
#include <winrt/Microsoft.UI.Xaml.Hosting.h>

namespace winrt::PropertySheetWinUI::implementation
{
    struct WinUIPropertySheet : WinUIPropertySheetT<WinUIPropertySheet>
    {
        WinUIPropertySheet();
        void CreatePropertySheet();
        void ApplyPropertySheetWindowStyle();

		winrt::Microsoft::UI::Dispatching::DispatcherQueueController m_dispatcherQueueControler{ nullptr };
		winrt::Microsoft::UI::Xaml::Hosting::WindowsXamlManager m_windowsXamlManager{ nullptr };
		winrt::PropertySheetWinUI::PropSheetWindow m_window{ nullptr };
    };
}

namespace winrt::PropertySheetWinUI::factory_implementation
{
    struct WinUIPropertySheet : WinUIPropertySheetT<WinUIPropertySheet, implementation::WinUIPropertySheet>
    {
		winrt::Windows::Foundation::IInspectable ActivateInstance() { return winrt::make<implementation::WinUIPropertySheet>(); }
    };
}
