#include "pch.h"
#include <winrt/Microsoft.UI.Xaml.XamlTypeInfo.h>
#include <PropertySheetHostApp.h>

namespace winrt::PropertySheetWinUI::implementation
{
    PropertySheetHostApp::PropertySheetHostApp()
    {
        m_metaDataProvider = winrt::Microsoft::UI::Xaml::XamlTypeInfo::XamlControlsXamlMetaDataProvider();
        m_windowsXamlManager = winrt::Microsoft::UI::Xaml::Hosting::WindowsXamlManager::InitializeForCurrentThread();
    }

    winrt::Microsoft::UI::Xaml::Markup::IXamlMetadataProvider PropertySheetHostApp::AppProvider()
    {
        return m_metaDataProvider;
	}

    void PropertySheetHostApp::OnLaunched(winrt::Microsoft::UI::Xaml::LaunchActivatedEventArgs const& /* e */)
    {
        auto resources = winrt::Microsoft::UI::Xaml::Controls::XamlControlsResources();
        winrt::Microsoft::UI::Xaml::Application::Current().Resources().MergedDictionaries().InsertAt(0, resources);
    }
}