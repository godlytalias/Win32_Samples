#pragma once
#include <shobjidl_core.h>
#include <wrl/implements.h>
#include <wrl/module.h>
#include <shlwapi.h>
#include <strsafe.h>
#include <propkey.h>
#include <propsys.h>
#include <knownfolders.h>
#include <shlobj.h>

// {C2F0A74D-5B89-4F1C-8D6E-2A9B7E4F1C03}
static constexpr CLSID CLSID_VerbHandler =
{ 0xc2f0a74d, 0x5b89, 0x4f1c, { 0x8d, 0x6e, 0x2a, 0x9b, 0x7e, 0x4f, 0x1c, 0x03 } };

namespace PropertiesVerb
{

    class VerbHandler
        : public Microsoft::WRL::RuntimeClass<
        Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::ClassicCom>,
        IExecuteCommand, IObjectWithSelection >
    {
    public:
        VerbHandler() = default;

        // IObjectWithSelection
        IFACEMETHODIMP SetSelection(IShellItemArray* psia) override;

        IFACEMETHODIMP GetSelection(REFIID riid, void** ppv) override;

        // IExecuteCommand
        IFACEMETHODIMP SetKeyState(DWORD grfKeyState) override;

        IFACEMETHODIMP SetParameters(PCWSTR /* pszParameters */) override;

        IFACEMETHODIMP SetPosition(POINT /* pt */) override;

        IFACEMETHODIMP SetShowWindow(int /* nShow */) override;

        IFACEMETHODIMP SetNoShowUI(BOOL /* fNoShowUI */) override;

        IFACEMETHODIMP SetDirectory(PCWSTR /* pszDirectory */) override;

        IFACEMETHODIMP Execute() override;

    private:
        void ShowVerbMessage(IShellItemArray* psia);

        IUnknown* _punkSite = nullptr;
        Microsoft::WRL::ComPtr<IShellItemArray> _pSelection;
        DWORD _grfKeyState = 0;
    };
}