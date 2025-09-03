#pragma once

#include <winrt/Microsoft.UI.Composition.h>
#include <winrt/Microsoft.UI.Composition.SystemBackdrops.h>
#include <winrt/Microsoft.UI.Content.h>
#include <winrt/Microsoft.UI.Xaml.Hosting.h>
#include "MainWindow.g.h"
#include <winrt/Windows.UI.h>
#include <winrt/BackdropApp.h>

namespace winrt::BackdropApp::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
            auto content = winrt::BackdropApp::BlankUserControl();
            content.CurrentWindow(this->try_as<winrt::Microsoft::UI::Xaml::Window>());
            content.init();
            Content(content);
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);
    };
}

namespace winrt::BackdropApp::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
