#pragma once

#include "AdvancedPage.g.h"

namespace winrt::PropertySheetPage::implementation
{
    struct AdvancedPage : AdvancedPageT<AdvancedPage>
    {
        AdvancedPage()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        void OnSave();
        winrt::hstring GetTitle();
        winrt::Microsoft::UI::Xaml::UIElement GetXamlContent();
    };
}

namespace winrt::PropertySheetPage::factory_implementation
{
    struct AdvancedPage : AdvancedPageT<AdvancedPage, implementation::AdvancedPage>
    {
    };
}
