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


        void init()
        {
            auto backdropconfig = winrt::Microsoft::UI::Composition::SystemBackdrops::SystemBackdropConfiguration();
            auto acrylicbackdrop = winrt::Microsoft::UI::Composition::SystemBackdrops::DesktopAcrylicController();
            m_backdropController = acrylicbackdrop;
            acrylicbackdrop.LuminosityOpacity(0.0);
            auto color = winrt::Windows::UI::Color{ 0, 255, 255, 0 };
            acrylicbackdrop.TintColor(color);
            acrylicbackdrop.SetSystemBackdropConfiguration(backdropconfig);
            auto backdroplink = winrt::Microsoft::UI::Content::ContentExternalBackdropLink::Create(currentWindow.Compositor());
            backdroptarget = backdroplink;
            acrylicbackdrop.AddSystemBackdropTarget(backdroptarget);
            backdroplink.ExternalBackdropBorderMode(winrt::Microsoft::UI::Composition::CompositionBorderMode::Inherit);
            winrt::Microsoft::UI::Xaml::Hosting::ElementCompositionPreview::SetElementChildVisual(backdrop(), backdroplink.PlacementVisual());


            MainButton().Loaded([this, backdroplink](auto const&, auto const&) {
                backdroplink.PlacementVisual().Size(backdrop().ActualSize());
                backdroplink.PlacementVisual().Offset(backdrop().ActualOffset());
                auto backdropSize = backdrop().ActualSize();
                auto backdropOffset = backdrop().ActualOffset();
                auto rect = currentWindow.Compositor().CreateRectangleClip(backdropOffset.x, backdropOffset.y, backdropOffset.x + backdropSize.x, backdropOffset.y + backdropSize.y);
                rect.TopLeftRadius({ 8.0, 8.0 });
                rect.TopRightRadius({ 8.0, 8.0 });
                rect.BottomLeftRadius({ 8.0, 8.0 });
                rect.BottomRightRadius({ 8.0, 8.0 });
                backdroplink.PlacementVisual().Clip(rect);
            });
        }
        winrt::Microsoft::UI::Composition::SystemBackdrops::ISystemBackdropControllerWithTargets m_backdropController{ nullptr };
        winrt::Microsoft::UI::Composition::ICompositionSupportsSystemBackdrop backdroptarget;
        void ClickHandler(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        winrt::Microsoft::UI::Xaml::Window currentWindow{ nullptr };
    };

}

namespace winrt::BackdropApp::factory_implementation
{
    struct BlankUserControl : BlankUserControlT<BlankUserControl, implementation::BlankUserControl>
    {
    };
}
