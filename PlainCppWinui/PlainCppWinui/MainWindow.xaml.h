#pragma once

#include "MainWindow.g.h"

namespace winrt::PlainCppWinui::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();
        Microsoft::UI::Xaml::Controls::MenuFlyout createFlyout();

        int32_t MyProperty();
        void MyProperty(int32_t value);
        int m = 0;
        void myButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void flyoutOpened(IInspectable const& handler, IInspectable const&);
        void MainWindow::fixIconIssue();
    private:
		Microsoft::UI::Xaml::Controls::BitmapIcon m_icon{ nullptr };
		Microsoft::UI::Xaml::Controls::MenuFlyout m_flyout{ nullptr };
    };
}

namespace winrt::PlainCppWinui::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
