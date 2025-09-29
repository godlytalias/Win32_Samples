#include "pch.h"
#include "BlankUserControl.h"
#if __has_include("BlankUserControl.g.cpp")
#include "BlankUserControl.g.cpp"
#endif
#include <roapi.h>
using namespace winrt;
using namespace winrt::Microsoft::UI::Xaml;

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
		ABI::Microsoft::UI::Content::IContentExternalBackdropLink* backdroplink{ nullptr };
        if (ABI::Microsoft::UI::Content::ContentExternalBackdropLink::Create(CurrentWindow().Compositor(), &backdroplink) == FALSE)
        {
            return;
		}
        
        // Query for the ICompositionSupportsSystemBackdrop interface
        winrt::com_ptr<::IInspectable> systemBackdropInspectable;
        winrt::check_hresult(backdroplink->QueryInterface(__uuidof(::IInspectable), systemBackdropInspectable.put_void()));
        
        // Convert to WinRT projected type
        m_backdroptarget = systemBackdropInspectable.as<winrt::Microsoft::UI::Composition::ICompositionSupportsSystemBackdrop>();

        m_backdropController.AddSystemBackdropTarget(m_backdroptarget);
        winrt::Microsoft::UI::Composition::Visual placementVisual{ nullptr };
        backdroplink->get_PlacementVisual(reinterpret_cast<ABI::Microsoft::UI::Composition::IVisual**>(put_abi(placementVisual)));
        winrt::Microsoft::UI::Xaml::Hosting::ElementCompositionPreview::SetElementChildVisual(backdropContainer(), placementVisual);


        MainButton().Loaded([this, backdroplink](auto const&, auto const&) {
			AdjustPlacementVisualForButton(backdroplink);
        });
    }

    void BlankUserControl::AdjustPlacementVisualForButton(ABI::Microsoft::UI::Content::IContentExternalBackdropLink* backdroplink)
    {
        winrt::Microsoft::UI::Composition::Visual placementVisual{ nullptr };
		backdroplink->get_PlacementVisual(reinterpret_cast<ABI::Microsoft::UI::Composition::IVisual**>(put_abi(placementVisual)));
        placementVisual.Size(backdropContainer().ActualSize());
        placementVisual.Offset(backdropContainer().ActualOffset());
        auto backdropSize = backdropContainer().ActualSize();
        auto backdropOffset = backdropContainer().ActualOffset();
        auto rect = CurrentWindow().Compositor().CreateRectangleClip(backdropOffset.x, backdropOffset.y, backdropOffset.x + backdropSize.x, backdropOffset.y + backdropSize.y);
        rect.TopLeftRadius({ 8.0, 8.0 });
        rect.TopRightRadius({ 8.0, 8.0 });
        rect.BottomLeftRadius({ 8.0, 8.0 });
        rect.BottomRightRadius({ 8.0, 8.0 });
        placementVisual.Clip(rect);
	}
}