#include "pch.h"
#include "BlankUserControl.h"
#if __has_include("BlankUserControl.g.cpp")
#include "BlankUserControl.g.cpp"
#endif
using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::BackdropApp::implementation
{
    winrt::Microsoft::UI::Xaml::Window BlankUserControl::CurrentWindow()
    {
        return currentWindow;
    }

    void BlankUserControl::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        MainButton().Content(box_value(L"Clicked"));
    }

    void BlankUserControl::InitializeAcrylicBackdrop()
    {
        if (m_backdropController != nullptr)
        {
            return;
        }
        auto backdropconfig = winrt::Microsoft::UI::Composition::SystemBackdrops::SystemBackdropConfiguration();
        auto acrylicbackdrop = winrt::Microsoft::UI::Composition::SystemBackdrops::DesktopAcrylicController();
        m_backdropController = acrylicbackdrop;
        acrylicbackdrop.LuminosityOpacity(0.0);
        auto color = winrt::Windows::UI::Color{ 0, 255, 255, 0 };
        acrylicbackdrop.TintColor(color);
        acrylicbackdrop.SetSystemBackdropConfiguration(backdropconfig);
	}

    void BlankUserControl::CreateAcrylicOnButton()
    {
        InitializeAcrylicBackdrop();

        auto backdroplink = winrt::MUCInternal::ContentExternalBackdropLink::Create(CurrentWindow().Compositor());
        m_backdroptarget = backdroplink;
        m_backdropController.AddSystemBackdropTarget(m_backdroptarget);
        winrt::Microsoft::UI::Xaml::Hosting::ElementCompositionPreview::SetElementChildVisual(backdropContainer(), backdroplink.PlacementVisual());


        MainButton().Loaded([this, backdroplink](auto const&, auto const&) {
			AdjustPlacementVisualForButton(backdroplink);
        });
    }

    void BlankUserControl::AdjustPlacementVisualForButton(winrt::MUCInternal::ContentExternalBackdropLink const& backdroplink)
    {
        backdroplink.PlacementVisual().Size(backdropContainer().ActualSize());
        backdroplink.PlacementVisual().Offset(backdropContainer().ActualOffset());
        auto backdropSize = backdropContainer().ActualSize();
        auto backdropOffset = backdropContainer().ActualOffset();
        auto rect = CurrentWindow().Compositor().CreateRectangleClip(backdropOffset.x, backdropOffset.y, backdropOffset.x + backdropSize.x, backdropOffset.y + backdropSize.y);
        rect.TopLeftRadius({ 8.0, 8.0 });
        rect.TopRightRadius({ 8.0, 8.0 });
        rect.BottomLeftRadius({ 8.0, 8.0 });
        rect.BottomRightRadius({ 8.0, 8.0 });
        backdroplink.PlacementVisual().Clip(rect);
	}
}


WINRT_EXPORT namespace winrt::MUCInternal
{
    winrt::MUCInternal::ContentExternalBackdropLink ContentExternalBackdropLink::Create(winrt::Microsoft::UI::Composition::Compositor const& compositor)
    {
        return MUCInternal::implementation::ContentExternalBackdropLink::Create(compositor);
    }
}