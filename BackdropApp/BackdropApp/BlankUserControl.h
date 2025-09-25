#pragma once

#include <winrt/Microsoft.UI.Composition.h>
#include <winrt/Microsoft.UI.Composition.Effects.h>
#include <winrt/Microsoft.UI.Composition.SystemBackdrops.h>
#include <winrt/Microsoft.UI.Content.h>
#include <winrt/Microsoft.UI.Xaml.Hosting.h>
#include "MainWindow.g.h"
#include <winrt/Windows.UI.h>
#include <winrt/BackdropApp.h>
#include "BlankUserControl.g.h"
#include "ContentExternalBackdropLink.g.h"

namespace winrt::BackdropApp::implementation
{
    struct BlankUserControl : BlankUserControlT<BlankUserControl>
    {
        BlankUserControl() 
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        winrt::Microsoft::UI::Xaml::Window CurrentWindow();
        void CurrentWindow(winrt::Microsoft::UI::Xaml::Window value)
        {
            currentWindow = value;
        }
        void CreateAcrylicOnButton();
        void ClickHandler(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

    private:
        void InitializeAcrylicBackdrop();
		void AdjustPlacementVisualForButton(winrt::BackdropApp::ContentExternalBackdropLink const& backdroplink);
        winrt::Microsoft::UI::Composition::SystemBackdrops::ISystemBackdropControllerWithTargets m_backdropController{ nullptr };
        winrt::Microsoft::UI::Composition::ICompositionSupportsSystemBackdrop m_backdroptarget{ nullptr };
        winrt::Microsoft::UI::Xaml::Window currentWindow{ nullptr };
    };

}

namespace winrt::BackdropApp::factory_implementation
{
    struct BlankUserControl : BlankUserControlT<BlankUserControl, implementation::BlankUserControl>
    {
    };
}
