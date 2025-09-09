#pragma once
#include "Windows.Foundation.h"
#include "WinUIPropertySheet.g.h"
#include "WinUIPropSheetHeader.g.h"
#include <winrt/Microsoft.UI.Xaml.Hosting.h>
#include <PropertySheetHostApp.h>

namespace winrt::PropertySheetWinUI::implementation
{
    struct WinUIPropertySheet : WinUIPropertySheetT<WinUIPropertySheet>
    {
        WinUIPropertySheet();
        void CreatePropertySheet(winrt::PropertySheetWinUI::WinUIPropSheetHeader const& header);
        void ApplyPropertySheetWindowStyle();

    private:
		winrt::Microsoft::UI::Dispatching::DispatcherQueueController m_dispatcherQueueControler{ nullptr };
		winrt::PropertySheetWinUI::PropSheetWindow m_window{ nullptr };
		winrt::Microsoft::UI::Xaml::Application m_xamlApplication{ nullptr };
		winrt::PropertySheetWinUI::WinUIPropSheetHeader m_propSheetHeader{ nullptr };
        winrt::PropertySheetWinUI::IPropSheetWindow::PropertySheetSave_revoker m_PropertySheetRevoker{};
    };

    struct WinUIPropSheetHeader : WinUIPropSheetHeaderT<WinUIPropSheetHeader>
    {
        WinUIPropSheetHeader()
        {
			m_pages = winrt::single_threaded_vector<winrt::PropertySheetWinUI::IWinUIPropSheetPage>();
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
        winrt::Windows::Foundation::Collections::IVector<winrt::PropertySheetWinUI::IWinUIPropSheetPage> pages() {
            return m_pages;
		};
        void pages(winrt::Windows::Foundation::Collections::IVector<winrt::PropertySheetWinUI::IWinUIPropSheetPage> const& val) {
            m_pages = val;
		};


    private:
		bool m_IsWizard{ false };
        winrt::hstring m_caption;
        winrt::Windows::Foundation::Collections::IVector<winrt::PropertySheetWinUI::IWinUIPropSheetPage> m_pages;
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
}
