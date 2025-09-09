#pragma once

#include <winrt/Microsoft.UI.Xaml.h>
#include <winrt/Microsoft.UI.Xaml.Markup.h>
#include <winrt/Windows.UI.Xaml.Interop.h>

namespace winrt::PropertySheetWinUI::implementation
{
    template <typename D, typename ... Interfaces>
    struct AppT : public ::winrt::Microsoft::UI::Xaml::ApplicationT<D, ::winrt::Microsoft::UI::Xaml::Markup::IXamlMetadataProvider, Interfaces...>
    {
        using IXamlType = ::winrt::Microsoft::UI::Xaml::Markup::IXamlType;

        void InitializeComponent()
        {
        }

        IXamlType GetXamlType(::winrt::Windows::UI::Xaml::Interop::TypeName const& type)
        {
            return AppProvider().GetXamlType(type);
        }

        IXamlType GetXamlType(::winrt::hstring const& fullName)
        {
            return AppProvider().GetXamlType(fullName);
        }

        ::winrt::com_array<::winrt::Microsoft::UI::Xaml::Markup::XmlnsDefinition> GetXmlnsDefinitions()
        {
            return AppProvider().GetXmlnsDefinitions();
        }

        virtual winrt::Microsoft::UI::Xaml::Markup::IXamlMetadataProvider AppProvider() = 0;
    };
}

