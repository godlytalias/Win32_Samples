#include "pch.h"
#include "WinUIPropertySheet.h"
#if __has_include("WinUIPropertySheet.g.cpp")
#include "WinUIPropertySheet.g.cpp"
#endif
#include <winrt/PropertySheetWinUI.h>
#include <microsoft.ui.xaml.window.h>
#include <winrt/Microsoft.UI.Windowing.h>
#include <winrt/Microsoft.UI.Xaml.XamlTypeInfo.h>

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::PropertySheetWinUI::implementation
{
    WinUIPropertySheet::WinUIPropertySheet()
    {
        m_dispatcherQueueControler = winrt::Microsoft::UI::Dispatching::DispatcherQueueController::CreateOnCurrentThread();
        m_xamlApplication = winrt::make<PropertySheetHostApp>();
	}

    HWND GetWindowHandle(winrt::Microsoft::UI::Xaml::Window const& window)
    {
        HWND hwnd{ nullptr };
        auto windowNative{ window.as<::IWindowNative>() };
        windowNative->get_WindowHandle(&hwnd);
        return hwnd;
    }

    void WinUIPropertySheet::ApplyPropertySheetWindowStyle()
    {
        HWND hwnd = GetWindowHandle(m_window);
        SetWindowPos(hwnd, HWND_TOP, 100, 100, 400, 600, SWP_NOMOVE | SWP_NOZORDER | SWP_SHOWWINDOW);
        m_window.Activate();
        auto presenter = m_window.AppWindow().Presenter();
        if (auto overlappedPresenter = presenter.try_as<winrt::Microsoft::UI::Windowing::OverlappedPresenter>())
        {
            overlappedPresenter.IsMinimizable(false);
            overlappedPresenter.IsMaximizable(false);
        }
    }

    void WinUIPropertySheet::CreatePropertySheet()
    {
        m_dispatcherQueueControler.DispatcherQueue().TryEnqueue([this]()
            {
                m_window = winrt::PropertySheetWinUI::PropSheetWindow();
                ApplyPropertySheetWindowStyle();
            });
    }
}
