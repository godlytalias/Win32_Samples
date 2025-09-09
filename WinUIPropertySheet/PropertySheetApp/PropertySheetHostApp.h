#pragma once
#include "Windows.Foundation.h"
#include "WinUIPropertySheet.g.h"
#include <winrt/Microsoft.UI.Xaml.Hosting.h>
#include "App.xaml.g.h"

namespace winrt::PropertySheetWinUI::implementation
{
    struct PropertySheetHostApp : AppT<PropertySheetHostApp>
    {
        PropertySheetHostApp();

        winrt::Microsoft::UI::Xaml::Markup::IXamlMetadataProvider AppProvider();

        // Application overrides
        void OnLaunched(winrt::Microsoft::UI::Xaml::LaunchActivatedEventArgs const& e);

        winrt::Microsoft::UI::Xaml::Markup::IXamlMetadataProvider m_metaDataProvider{ nullptr };
        winrt::Microsoft::UI::Xaml::Hosting::WindowsXamlManager m_windowsXamlManager{ nullptr };
    };
}