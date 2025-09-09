#pragma once
#include "Windows.Foundation.h"
#include "WinUIPropertySheet.g.h"
#include "WinUIPropSheetHeader.g.h"
#include "WinUIPropSheetPage.g.h"
#include <winrt/Microsoft.UI.Xaml.Hosting.h>
#include <PropertySheetHostApp.h>

namespace winrt::PropertySheetWinUI::implementation
{
    struct WinUIPropertySheet : WinUIPropertySheetT<WinUIPropertySheet>
    {
        WinUIPropertySheet();
        void CreatePropertySheet(winrt::PropertySheetWinUI::WinUIPropSheetHeader const& header);
        void ApplyPropertySheetWindowStyle();

		winrt::Microsoft::UI::Dispatching::DispatcherQueueController m_dispatcherQueueControler{ nullptr };
		winrt::PropertySheetWinUI::PropSheetWindow m_window{ nullptr };
		winrt::Microsoft::UI::Xaml::Application m_xamlApplication{ nullptr };
    };

    struct WinUIPropSheetPage : WinUIPropSheetPageT<WinUIPropSheetPage>
    {
        WinUIPropSheetPage() = default;
        winrt::hstring Title()
        {
            return m_title;
        };
        void Title(winrt::hstring const& val)
        {
            m_title = val;
        };
        winrt::Microsoft::UI::Xaml::UIElement Content()
        {
            return m_xamlContent;
        };
        void Content(winrt::Microsoft::UI::Xaml::UIElement const& val)
        {
            m_xamlContent = val;
        };

    private:
		winrt::hstring m_title;
		winrt::Microsoft::UI::Xaml::UIElement m_xamlContent{ nullptr };
	};

    struct WinUIPropSheetHeader : WinUIPropSheetHeaderT<WinUIPropSheetHeader>
    {
        WinUIPropSheetHeader()
        {
			m_pages = winrt::single_threaded_vector<winrt::PropertySheetWinUI::WinUIPropSheetPage>();
        }
        bool IsWizard() {
            return m_IsWizard;
        };
        void IsWizard(bool val) {
            m_IsWizard = val;
		};
        winrt::hstring Caption() {
            return m_caption;
		};
        void Caption(winrt::hstring const& val) {
            m_caption = val;
        };
        winrt::Windows::Foundation::Collections::IVector<winrt::PropertySheetWinUI::WinUIPropSheetPage> pages() {
            return m_pages;
		};
        void pages(winrt::Windows::Foundation::Collections::IVector<winrt::PropertySheetWinUI::WinUIPropSheetPage> const& val) {
            m_pages = val;
		};


    private:
		bool m_IsWizard{ false };
        winrt::hstring m_caption;
        winrt::Windows::Foundation::Collections::IVector<winrt::PropertySheetWinUI::WinUIPropSheetPage> m_pages;
    };
}

namespace winrt::PropertySheetWinUI::factory_implementation
{
    struct WinUIPropertySheet : WinUIPropertySheetT<WinUIPropertySheet, implementation::WinUIPropertySheet>
    {
		winrt::Windows::Foundation::IInspectable ActivateInstance() { return winrt::make<implementation::WinUIPropertySheet>(); }
    };
    struct WinUIPropSheetHeader : WinUIPropSheetHeaderT<WinUIPropSheetHeader, implementation::WinUIPropSheetHeader>
    {
    };
    struct WinUIPropSheetPage : WinUIPropSheetPageT<WinUIPropSheetPage, implementation::WinUIPropSheetPage>
    {
    };
}
