#pragma once

#include "GeneralPage.g.h"

namespace winrt::PropertySheetPage::implementation
{
    struct GeneralPage : GeneralPageT<GeneralPage>
    {
        GeneralPage()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

    };
}

namespace winrt::PropertySheetPage::factory_implementation
{
    struct GeneralPage : GeneralPageT<GeneralPage, implementation::GeneralPage>
    {
    };
}
