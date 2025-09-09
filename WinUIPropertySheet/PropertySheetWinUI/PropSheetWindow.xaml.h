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

		void AddPage(winrt::PropertySheetWinUI::WinUIPropSheetPage page);
    };
}

namespace winrt::PropertySheetWinUI::factory_implementation
{
    struct PropSheetWindow : PropSheetWindowT<PropSheetWindow, implementation::PropSheetWindow>
    {
    };
}
