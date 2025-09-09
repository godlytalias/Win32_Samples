# Property Sheet Solution

A modern C++ solution demonstrating property sheet implementation using Win32 and WinUI 3. This solution showcases how to create a traditional property sheet dialog using WinUI 3 controls, bridging the gap between classic Win32 applications and modern UI frameworks.

## Overview

This solution consists of three interconnected projects that work together to provide a complete property sheet implementation:

- **PropertySheetApp** - Win32 host application
- **PropertySheetPage** - Property sheet page implementations  
- **PropertySheetWinUI** - WinUI 3 property sheet control

## Projects

### PropertySheetApp

**Purpose**: Pure Win32 application that serves as the host for the property sheet functionality.

**Key Features**:
- Traditional Win32 application entry point with message loop
- Integrates Windows App SDK for WinUI 3 support
- Demonstrates how to invoke and display property sheets from Win32 code
- Provides menu-driven interface to launch property sheet dialogs
- Handles application lifecycle and window management

**Main Components**:
- `PropertySheetApp.cpp` - Main application entry point and window procedures
- Menu system with "Show Property Sheet" option
- Windows App SDK initialization and bootstrapping
- Integration with WinUI 3 components

### PropertySheetPage

**Purpose**: Contains the implementation of individual property sheet pages that populate each tab of the property sheet.

**Key Features**:
- Implements `IWinUIPropSheetPage` interface for property sheet integration
- Provides XAML-based user interfaces for property pages
- Supports save operations and data validation
- Includes multiple page implementations (General and Advanced)

**Main Components**:
- `GeneralPage.xaml/.cpp/.h` - General settings page implementation
- `AdvancedPage.xaml/.cpp/.h` - Advanced settings page implementation
- Each page implements `IWinUIPropSheetPage`:
  - `OnSave()` - Handles save operations when Apply/OK is clicked
  - `GetTitle()` - Returns the tab title text
  - `GetXamlContent()` - Returns the XAML UI element for the page


### PropertySheetWinUI

**Purpose**: WinUI 3 control that hosts property sheet pages, providing functionality similar to the traditional ComCtl Property Sheet but with modern UI capabilities.

**Key Features**:
- Modern WinUI 3-based property sheet implementation
- Tab-based interface using `TabView` control
- Automatic page management and lifecycle handling
- Event-driven architecture with save notifications
- Window styling to match traditional property sheet appearance
- Support for Apply, OK, and Cancel operations

**Main Components**:
- `WinUIPropertySheet` - Main property sheet control class
- `PropSheetWindow` - XAML window hosting the property sheet
- `WinUIPropSheetHeader` - Configuration class for property sheet setup
- `PropertySheetHostApp` - XAML application host for WinUI integration

**Key Functionality**:
- Dynamic page addition and management
- Event handling for save operations across all pages
- Window styling (non-resizable, specific dimensions)
- Integration with Win32 window handles for proper embedding

## Architecture

The solution follows a layered architecture:

1. **Win32 Host Layer** (PropertySheetApp) - Provides the native Windows application shell
2. **UI Framework Layer** (PropertySheetWinUI) - Implements the property sheet container using WinUI 3
3. **Content Layer** (PropertySheetPage) - Contains the actual property page implementations

## Building and Running

**Prerequisites**:
- Visual Studio 2019/2022 with C++ development tools
- Windows 10 SDK (version 10.0.19041.0 or later)
- Windows App SDK 1.4 or later
- C++17 support

**Build Configuration**:
- Target: C++17
- Platform: x64
- Windows App SDK integration enabled

**To Run**:
1. Build the entire solution
2. Run PropertySheetApp.exe
3. Use the menu to select "Property Sheet" > "Show Property Sheet"
4. Interact with the General and Advanced tabs
5. Use Apply/OK buttons to test save functionality

## Key Technologies

- **C++/WinRT** - Modern C++ projections for Windows Runtime APIs
- **WinUI 3** - Microsoft's modern UI framework for Windows applications
- **XAML** - Declarative UI markup for page layouts
- **Windows App SDK** - Unified platform for Windows app development
- **Win32 API** - Traditional Windows application programming interface

This solution demonstrates how to modernize traditional Win32 property sheet dialogs while maintaining compatibility with existing Win32 applications.
