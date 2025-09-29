#include "winrt/Microsoft.UI.Composition.h"
#include "Windows.Foundation.h"
#include <inspectable.h>

#include <roapi.h>
#if !defined(____x_Microsoft_CUI_CContent_CIContentExternalBackdropLink_INTERFACE_DEFINED__)
#define ____x_Microsoft_CUI_CContent_CIContentExternalBackdropLink_INTERFACE_DEFINED__
extern const __declspec(selectany) _Null_terminated_ WCHAR InterfaceName_Microsoft_UI_Content_IContentExternalBackdropLink[] = L"Microsoft.UI.Content.IContentExternalBackdropLink";
namespace ABI {
    namespace Microsoft {
        namespace UI {
            namespace Composition {
                enum CompositionBorderMode : int
                {
                    CompositionBorderMode_Hard = 0,
                    CompositionBorderMode_Soft = 1,
                };
                typedef ::IInspectable IVisual;
                typedef ::IInspectable ICompositor;
            } /* Composition */
            namespace Dispatching {
                typedef ::IInspectable IDispatcherQueue;
            } /* Dispatching */
            namespace Content {
                MIDL_INTERFACE("1054bf83-b35b-5fde-8dd7-ac3bb3e6ce27")
                    IContentExternalBackdropLink : public IInspectable
                {
                public:
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_DispatcherQueue(
                        /* [out, retval] */__RPC__deref_out_opt ABI::Microsoft::UI::Dispatching::IDispatcherQueue * *value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_ExternalBackdropBorderMode(
                        /* [out, retval] */__RPC__out ABI::Microsoft::UI::Composition::CompositionBorderMode* value
                        ) = 0;
                    /* [propput] */virtual HRESULT STDMETHODCALLTYPE put_ExternalBackdropBorderMode(
                        /* [in] */ABI::Microsoft::UI::Composition::CompositionBorderMode value
                        ) = 0;
                    /* [propget] */virtual HRESULT STDMETHODCALLTYPE get_PlacementVisual(
                        /* [out, retval] */__RPC__deref_out_opt ABI::Microsoft::UI::Composition::IVisual** value
                        ) = 0;

                };
                /* [uuid("46cac6fb-bb51-510a-958d-e0eb4160f678"), feature, contract, object, exclusiveto] */
                MIDL_INTERFACE("46cac6fb-bb51-510a-958d-e0eb4160f678")
                    IContentExternalBackdropLinkStatics : public IInspectable
                {
                public:
                    virtual HRESULT STDMETHODCALLTYPE Create(
                        /* [in] */__RPC__in_opt ABI::Microsoft::UI::Composition::ICompositor * compositor,
                        /* [out, retval] */__RPC__deref_out_opt ABI::Microsoft::UI::Content::IContentExternalBackdropLink * *result
                        ) = 0;

                };
                class ContentExternalBackdropLink {
                public:
                    static BOOL Create(winrt::Microsoft::UI::Composition::Compositor compositor, ABI::Microsoft::UI::Content::IContentExternalBackdropLink** link)
                    {
                        winrt::hstring activationClass = L"Microsoft.UI.Content.ContentExternalBackdropLink";
                        ABI::Microsoft::UI::Content::IContentExternalBackdropLinkStatics* statics{ nullptr };
						ABI::Microsoft::UI::Content::IContentExternalBackdropLink* backdroplink{ nullptr };
                        if (SUCCEEDED(RoGetActivationFactory(static_cast<HSTRING>(winrt::get_abi(activationClass)), __uuidof(statics), reinterpret_cast<void**>(&statics))))
                            statics->Create(reinterpret_cast<ABI::Microsoft::UI::Composition::ICompositor*>(winrt::get_abi(compositor)), &backdroplink);
                        else return FALSE;

                        if (FAILED(backdroplink->QueryInterface(__uuidof(ABI::Microsoft::UI::Content::IContentExternalBackdropLink), reinterpret_cast<void**>(link))))
                        {
                            return FALSE;
                        }
                        return TRUE;
                    }
                };
            } /* Content */
        } /* UI */
    } /* Microsoft */
}

#endif /* !defined(____x_Microsoft_CUI_CContent_CIContentExternalBackdropLink_INTERFACE_DEFINED__) */