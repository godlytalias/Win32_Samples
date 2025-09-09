#pragma once
#include "PropSheetWindow.g.h"

namespace winrt::PropertySheetWinUI::implementation
{
    struct PropSheetWindow : PropSheetWindowT<PropSheetWindow>
    {
        PropSheetWindow()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

		void AddPage(winrt::PropertySheetWinUI::IWinUIPropSheetPage page);
        void OnOkClickedEvent(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
		void OnApplyClickedEvent(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);

        // Add this method to properly implement the event handler registration
        winrt::event_token PropertySheetSave(winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Foundation::IInspectable, winrt::Microsoft::UI::Xaml::RoutedEventArgs> const& handler);
        void PropertySheetSave(winrt::event_token const& token) noexcept;

    private:
        winrt::event<winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Foundation::IInspectable, winrt::Microsoft::UI::Xaml::RoutedEventArgs>> m_propertySheetSave;
    };
}

namespace winrt::PropertySheetWinUI::factory_implementation
{
    struct PropSheetWindow : PropSheetWindowT<PropSheetWindow, implementation::PropSheetWindow>
    {
    };
}
