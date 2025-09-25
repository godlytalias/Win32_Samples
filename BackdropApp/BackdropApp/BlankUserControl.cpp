#include "pch.h"
#include "BlankUserControl.h"
#if __has_include("BlankUserControl.g.cpp")
#include "BlankUserControl.g.cpp"
#endif
#include <roapi.h>
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

        auto backdroplink = winrt::BackdropApp::ContentExternalBackdropLink::Create(CurrentWindow().Compositor());


        m_backdroptarget = backdroplink;
        m_backdropController.AddSystemBackdropTarget(m_backdroptarget);
        winrt::Microsoft::UI::Xaml::Hosting::ElementCompositionPreview::SetElementChildVisual(backdropContainer(), backdroplink.PlacementVisual());


        MainButton().Loaded([this, backdroplink](auto const&, auto const&) {
			AdjustPlacementVisualForButton(backdroplink);
        });
    }

    void BlankUserControl::AdjustPlacementVisualForButton(winrt::BackdropApp::ContentExternalBackdropLink const& backdroplink)
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

void* winrt_make_BackdropApp_ContentExternalBackdropLink()
{
    return nullptr;
}
WINRT_EXPORT namespace winrt::BackdropApp
{
    winrt::BackdropApp::ContentExternalBackdropLink ContentExternalBackdropLink::Create(winrt::Microsoft::UI::Composition::Compositor const& compositor)
    {
        winrt::guid IContentExternalBackdropLinkStaticsGuid{ 0x46CAC6FB, 0xBB51, 0x510A, { 0x95,0x8D,0xE0,0xEB,0x41,0x60,0xF6,0x78 } };
        winrt::com_ptr<winrt::BackdropApp::IContentExternalBackdropLinkStatics> factory;
        winrt::hstring activationClass = L"Microsoft.UI.Content.ContentExternalBackdropLink";
        RoGetActivationFactory(static_cast<HSTRING>(winrt::get_abi(activationClass)), IContentExternalBackdropLinkStaticsGuid, reinterpret_cast<void**>(&factory));
        winrt::BackdropApp::ContentExternalBackdropLink instance{ nullptr };
        factory->Create(winrt::get_abi(compositor), reinterpret_cast<void**>(&instance));
		return instance;
    }
}