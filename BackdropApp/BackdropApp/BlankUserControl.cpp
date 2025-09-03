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
        throw hresult_not_implemented();
    }

    void BlankUserControl::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        MainButton().Content(box_value(L"Clicked"));
    }
}
