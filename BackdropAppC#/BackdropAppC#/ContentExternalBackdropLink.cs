using ABI.Microsoft.UI.Composition;
using ABI.Microsoft.UI.Content;
using ABI.System;
using Microsoft.Foundation;
using Microsoft.UI.Composition;
using Microsoft.UI.Dispatching;
using System;
using System.Collections.Concurrent;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Threading;
using Windows.Foundation.Metadata;
using WinRT;
using WinRT.Interop;

namespace Microsoft.UI.Content
{
    [WindowsRuntimeType("Microsoft.UI")]
    [global::System.Runtime.InteropServices.Guid("1054BF83-B35B-5FDE-8DD7-AC3BB3E6CE27")]
    [WindowsRuntimeHelperType(typeof(ABI.Microsoft.UI.Content.IExperimentalContentExternalBackdropLink))]
    [ContractVersion(typeof(WindowsAppSDKContract), 65542u)]
    internal interface IExperimentalContentExternalBackdropLink
    {
        DispatcherQueue DispatcherQueue { get; }

        CompositionBorderMode ExternalBackdropBorderMode { get; set; }

        Microsoft.UI.Composition.Visual PlacementVisual { get; }
    }

    [WindowsRuntimeType("Microsoft.UI")]
    [WindowsRuntimeHelperType(typeof(ABI.Microsoft.UI.Content.ExperimentalContentExternalBackdropLink))]
    [ExperimentalContentExternalBackdropLinkRcwFactory]
    [ProjectedRuntimeClass(typeof(IExperimentalContentExternalBackdropLink))]
    [ContractVersion(typeof(WindowsAppSDKContract), 65542u)]
    public sealed class ExperimentalContentExternalBackdropLink : IDisposable, Microsoft.UI.Composition.ICompositionSupportsSystemBackdrop, ICustomQueryInterface, IWinRTObject, IDynamicInterfaceCastable, IEquatable<ExperimentalContentExternalBackdropLink>
    {
        [StructLayout(LayoutKind.Sequential, Size = 1)]
        private struct InterfaceTag<I>
        {
        }

        private readonly IObjectReference _inner;

        private volatile IObjectReference ___objRef_global__System_IDisposable;

        private volatile IObjectReference ___objRef_global__Microsoft_UI_Composition_ICompositionSupportsSystemBackdrop;

        private static volatile IObjectReference ___objRef_global__Microsoft_UI_Content_IExperimentalContentExternalBackdropLinkStatics;

        private volatile ConcurrentDictionary<RuntimeTypeHandle, IObjectReference> _queryInterfaceCache;

        private volatile ConcurrentDictionary<RuntimeTypeHandle, object> _additionalTypeData;

        private IntPtr ThisPtr
        {
            get
            {
                if (_inner != null)
                {
                    return _inner.ThisPtr;
                }

                return ((IWinRTObject)this).NativeObject.ThisPtr;
            }
        }

        private IObjectReference _objRef_global__Microsoft_UI_Content_IExperimentalContentExternalBackdropLink => _inner;

        private IObjectReference _objRef_global__System_IDisposable => ___objRef_global__System_IDisposable ?? Make___objRef_global__System_IDisposable();

        private IObjectReference _objRef_global__Microsoft_UI_Composition_ICompositionSupportsSystemBackdrop => ___objRef_global__Microsoft_UI_Composition_ICompositionSupportsSystemBackdrop ?? Make___objRef_global__Microsoft_UI_Composition_ICompositionSupportsSystemBackdrop();

        private static IObjectReference _objRef_global__Microsoft_UI_Content_IExperimentalContentExternalBackdropLinkStatics
        {
            get
            {
                IObjectReference __objRef_global__Microsoft_UI_Content_IExperimentalContentExternalBackdropLinkStatics = ___objRef_global__Microsoft_UI_Content_IExperimentalContentExternalBackdropLinkStatics;
                if (__objRef_global__Microsoft_UI_Content_IExperimentalContentExternalBackdropLinkStatics != null && __objRef_global__Microsoft_UI_Content_IExperimentalContentExternalBackdropLinkStatics.IsInCurrentContext)
                {
                    return __objRef_global__Microsoft_UI_Content_IExperimentalContentExternalBackdropLinkStatics;
                }

                try
                {
                    ___objRef_global__Microsoft_UI_Content_IExperimentalContentExternalBackdropLinkStatics = ActivationFactory.Get("Microsoft.UI.Content.ContentExternalBackdropLink", IExperimentalContentExternalBackdropLinkStaticsMethods.IID);
                }
                catch
                {
                    ___objRef_global__Microsoft_UI_Content_IExperimentalContentExternalBackdropLinkStatics = null;
                }

                return ___objRef_global__Microsoft_UI_Content_IExperimentalContentExternalBackdropLinkStatics;
            }
        }

        bool IWinRTObject.HasUnwrappableNativeObject => true;

        IObjectReference IWinRTObject.NativeObject => _inner;

        ConcurrentDictionary<RuntimeTypeHandle, IObjectReference> IWinRTObject.QueryInterfaceCache => _queryInterfaceCache ?? MakeQueryInterfaceCache();

        ConcurrentDictionary<RuntimeTypeHandle, object> IWinRTObject.AdditionalTypeData => _additionalTypeData ?? MakeAdditionalTypeData();

        public DispatcherQueue DispatcherQueue => IExperimentalContentExternalBackdropLinkMethods.get_DispatcherQueue(_objRef_global__Microsoft_UI_Content_IExperimentalContentExternalBackdropLink);

        public Microsoft.UI.Composition.CompositionBorderMode ExternalBackdropBorderMode
        {
            get
            {
                return IExperimentalContentExternalBackdropLinkMethods.get_ExternalBackdropBorderMode(_objRef_global__Microsoft_UI_Content_IExperimentalContentExternalBackdropLink);
            }
            set
            {
                IExperimentalContentExternalBackdropLinkMethods.set_ExternalBackdropBorderMode(_objRef_global__Microsoft_UI_Content_IExperimentalContentExternalBackdropLink, value);
            }
        }

        public Microsoft.UI.Composition.Visual PlacementVisual => IExperimentalContentExternalBackdropLinkMethods.get_PlacementVisual(_objRef_global__Microsoft_UI_Content_IExperimentalContentExternalBackdropLink);

        public global::Windows.UI.Composition.CompositionBrush SystemBackdrop
        {
            get
            {
                return ICompositionSupportsSystemBackdropMethods.get_SystemBackdrop(_objRef_global__Microsoft_UI_Composition_ICompositionSupportsSystemBackdrop);
            }
            set
            {
                ICompositionSupportsSystemBackdropMethods.set_SystemBackdrop(_objRef_global__Microsoft_UI_Composition_ICompositionSupportsSystemBackdrop, value);
            }
        }

        private IObjectReference Make___objRef_global__System_IDisposable()
        {
            Interlocked.CompareExchange(ref ___objRef_global__System_IDisposable, ((IWinRTObject)this).NativeObject.As<IUnknownVftbl>(IDisposableMethods.IID), null);
            return ___objRef_global__System_IDisposable;
        }

        private IObjectReference Make___objRef_global__Microsoft_UI_Composition_ICompositionSupportsSystemBackdrop()
        {
            Interlocked.CompareExchange(ref ___objRef_global__Microsoft_UI_Composition_ICompositionSupportsSystemBackdrop, ((IWinRTObject)this).NativeObject.As<IUnknownVftbl>(ICompositionSupportsSystemBackdropMethods.IID), null);
            return ___objRef_global__Microsoft_UI_Composition_ICompositionSupportsSystemBackdrop;
        }

        public static I As<I>()
        {
            return ActivationFactory.Get("Microsoft.UI.Content.ExperimentalContentExternalBackdropLink").AsInterface<I>();
        }

        public static ExperimentalContentExternalBackdropLink Create(Microsoft.UI.Composition.Compositor compositor)
        {
            return IExperimentalContentExternalBackdropLinkStaticsMethods.Create(_objRef_global__Microsoft_UI_Content_IExperimentalContentExternalBackdropLinkStatics, compositor);
        }

        public static ExperimentalContentExternalBackdropLink FromAbi(IntPtr thisPtr)
        {
            if (thisPtr == IntPtr.Zero)
            {
                return null;
            }

            return MarshalInspectable<ExperimentalContentExternalBackdropLink>.FromAbi(thisPtr);
        }

        internal ExperimentalContentExternalBackdropLink(IObjectReference objRef)
        {
            _inner = objRef.As(IExperimentalContentExternalBackdropLinkMethods.IID);
        }

        public static bool operator ==(ExperimentalContentExternalBackdropLink x, ExperimentalContentExternalBackdropLink y)
        {
            return (x?.ThisPtr ?? IntPtr.Zero) == (y?.ThisPtr ?? IntPtr.Zero);
        }

        public static bool operator !=(ExperimentalContentExternalBackdropLink x, ExperimentalContentExternalBackdropLink y)
        {
            return !(x == y);
        }

        public bool Equals(ExperimentalContentExternalBackdropLink other)
        {
            return this == other;
        }

        public override bool Equals(object obj)
        {
            if (obj is ExperimentalContentExternalBackdropLink ExperimentalContentExternalBackdropLink)
            {
                return this == ExperimentalContentExternalBackdropLink;
            }

            return false;
        }

        public override int GetHashCode()
        {
            return ThisPtr.GetHashCode();
        }

        private ConcurrentDictionary<RuntimeTypeHandle, IObjectReference> MakeQueryInterfaceCache()
        {
            Interlocked.CompareExchange(ref _queryInterfaceCache, new ConcurrentDictionary<RuntimeTypeHandle, IObjectReference>(), null);
            return _queryInterfaceCache;
        }

        private ConcurrentDictionary<RuntimeTypeHandle, object> MakeAdditionalTypeData()
        {
            Interlocked.CompareExchange(ref _additionalTypeData, new ConcurrentDictionary<RuntimeTypeHandle, object>(), null);
            return _additionalTypeData;
        }

        public void Dispose()
        {
            IDisposableMethods.Dispose(_objRef_global__System_IDisposable);
        }

        private bool IsOverridableInterface(Guid iid)
        {
            return false;
        }

        CustomQueryInterfaceResult ICustomQueryInterface.GetInterface(ref Guid iid, out IntPtr ppv)
        {
            ppv = IntPtr.Zero;
            if (IsOverridableInterface(iid) || IID.IID_IInspectable == iid)
            {
                return CustomQueryInterfaceResult.NotHandled;
            }

            if (((IWinRTObject)this).NativeObject.TryAs(iid, out ppv) >= 0)
            {
                return CustomQueryInterfaceResult.Handled;
            }

            return CustomQueryInterfaceResult.NotHandled;
        }
    }
}

namespace ABI.Microsoft.UI.Content
{
    [EditorBrowsable(EditorBrowsableState.Never)]
    internal sealed class ExperimentalContentExternalBackdropLinkRcwFactoryAttribute : WinRTImplementationTypeRcwFactoryAttribute
    {
        public override object CreateInstance(IInspectable inspectable)
        {
            return new global::Microsoft.UI.Content.ExperimentalContentExternalBackdropLink(inspectable.ObjRef);
        }
    }

    internal static class IExperimentalContentExternalBackdropLinkMethods
    {
        public static ref readonly Guid IID
        {
            [MethodImpl(MethodImplOptions.AggressiveInlining)]
            get
            {
                return ref Unsafe.As<byte, Guid>(ref MemoryMarshal.GetReference((ReadOnlySpan<byte>)new byte[16]
                {
                131, 191, 84, 16, 91, 179, 222, 95, 141, 215,
                172, 59, 179, 230, 206, 39
                }));
            }
        }

        internal unsafe static global::Microsoft.UI.Dispatching.DispatcherQueue get_DispatcherQueue(IObjectReference _obj)
        {
            IntPtr thisPtr = _obj.ThisPtr;
            IntPtr intPtr = default(IntPtr);
            try
            {
                ExceptionHelpers.ThrowExceptionForHR(((delegate* unmanaged[Stdcall]<IntPtr, IntPtr*, int>)(*(IntPtr*)((nint)(*(IntPtr*)(void*)thisPtr) + (nint)6 * (nint)sizeof(delegate* unmanaged[Stdcall]<IntPtr, IntPtr*, int>))))(thisPtr, &intPtr));
                return ABI.Microsoft.UI.Dispatching.DispatcherQueue.FromAbi(intPtr);
            }
            finally
            {
                ABI.Microsoft.UI.Dispatching.DispatcherQueue.DisposeAbi(intPtr);
            }
        }

        internal unsafe static CompositionBorderMode get_ExternalBackdropBorderMode(IObjectReference _obj)
        {
            IntPtr thisPtr = _obj.ThisPtr;
            CompositionBorderMode result = CompositionBorderMode.Inherit;
            ExceptionHelpers.ThrowExceptionForHR(((delegate* unmanaged[Stdcall]<IntPtr, CompositionBorderMode*, int>)(*(IntPtr*)((nint)(*(IntPtr*)(void*)thisPtr) + (nint)7 * (nint)sizeof(delegate* unmanaged[Stdcall]<IntPtr, CompositionBorderMode*, int>))))(thisPtr, &result));
            return result;
        }

        internal unsafe static void set_ExternalBackdropBorderMode(IObjectReference _obj, CompositionBorderMode value)
        {
            IntPtr thisPtr = _obj.ThisPtr;
            ExceptionHelpers.ThrowExceptionForHR(((delegate* unmanaged[Stdcall]<IntPtr, CompositionBorderMode, int>)(*(IntPtr*)((nint)(*(IntPtr*)(void*)thisPtr) + (nint)8 * (nint)sizeof(delegate* unmanaged[Stdcall]<IntPtr, CompositionBorderMode, int>))))(thisPtr, value));
        }

        internal unsafe static global::Microsoft.UI.Composition.Visual get_PlacementVisual(IObjectReference _obj)
        {
            IntPtr thisPtr = _obj.ThisPtr;
            IntPtr intPtr = default(IntPtr);
            try
            {
                ExceptionHelpers.ThrowExceptionForHR(((delegate* unmanaged[Stdcall]<IntPtr, IntPtr*, int>)(*(IntPtr*)((nint)(*(IntPtr*)(void*)thisPtr) + (nint)9 * (nint)sizeof(delegate* unmanaged[Stdcall]<IntPtr, IntPtr*, int>))))(thisPtr, &intPtr));
                return ABI.Microsoft.UI.Composition.Visual.FromAbi(intPtr);
            }
            finally
            {
                ABI.Microsoft.UI.Composition.Visual.DisposeAbi(intPtr);
            }
        }
    }

    internal static class IExperimentalContentExternalBackdropLinkStaticsMethods
    {
        public static ref readonly Guid IID
        {
            [MethodImpl(MethodImplOptions.AggressiveInlining)]
            get
            {
                return ref Unsafe.As<byte, Guid>(ref MemoryMarshal.GetReference((ReadOnlySpan<byte>)new byte[16]
                {
                251, 198, 202, 70, 81, 187, 10, 81, 149, 141,
                224, 235, 65, 96, 246, 120
                }));
            }
        }

        internal unsafe static global::Microsoft.UI.Content.ExperimentalContentExternalBackdropLink Create(IObjectReference _obj, global::Microsoft.UI.Composition.Compositor compositor)
        {
            if (_obj == null)
            {
                return null;
            }
            IntPtr thisPtr = _obj.ThisPtr;
            ObjectReferenceValue value = default(ObjectReferenceValue);
            IntPtr intPtr = default(IntPtr);
            try
            {
                value = ABI.Microsoft.UI.Composition.Compositor.CreateMarshaler2(compositor);
                ExceptionHelpers.ThrowExceptionForHR(((delegate* unmanaged[Stdcall]<IntPtr, IntPtr, IntPtr*, int>)(*(IntPtr*)((nint)(*(IntPtr*)(void*)thisPtr) + (nint)6 * (nint)sizeof(delegate* unmanaged[Stdcall]<IntPtr, IntPtr, IntPtr*, int>))))(thisPtr, MarshalInspectable<object>.GetAbi(value), &intPtr));
                return ExperimentalContentExternalBackdropLink.FromAbi(intPtr);
            }
            catch
            {
                global::System.Console.WriteLine("Exception in IExperimentalContentExternalBackdropLinkStaticsMethods.Create");
                return null;
            }
            finally
            {
                MarshalInspectable<object>.DisposeMarshaler(value);
                ExperimentalContentExternalBackdropLink.DisposeAbi(intPtr);
            }
        }
    }
    [global::System.Runtime.InteropServices.Guid("1054BF83-B35B-5FDE-8DD7-AC3BB3E6CE27")]
    internal interface IExperimentalContentExternalBackdropLink
    {
    }

    [StructLayout(LayoutKind.Sequential, Size = 1)]
    [EditorBrowsable(EditorBrowsableState.Never)]
    public struct ExperimentalContentExternalBackdropLink
    {
        public static IObjectReference CreateMarshaler(global::Microsoft.UI.Content.ExperimentalContentExternalBackdropLink obj)
        {
            if ((object)obj != null)
            {
                return MarshalInspectable<global::Microsoft.UI.Content.ExperimentalContentExternalBackdropLink>.CreateMarshaler<IUnknownVftbl>(obj, IExperimentalContentExternalBackdropLinkMethods.IID);
            }

            return null;
        }

        public static ObjectReferenceValue CreateMarshaler2(global::Microsoft.UI.Content.ExperimentalContentExternalBackdropLink obj)
        {
            return MarshalInspectable<object>.CreateMarshaler2(obj, IExperimentalContentExternalBackdropLinkMethods.IID);
        }

        public static IntPtr GetAbi(IObjectReference value)
        {
            if (value != null)
            {
                return MarshalInterfaceHelper<object>.GetAbi(value);
            }

            return IntPtr.Zero;
        }

        public static global::Microsoft.UI.Content.ExperimentalContentExternalBackdropLink FromAbi(IntPtr thisPtr)
        {
            return global::Microsoft.UI.Content.ExperimentalContentExternalBackdropLink.FromAbi(thisPtr);
        }

        public static IntPtr FromManaged(global::Microsoft.UI.Content.ExperimentalContentExternalBackdropLink obj)
        {
            if ((object)obj != null)
            {
                return CreateMarshaler2(obj).Detach();
            }

            return IntPtr.Zero;
        }

        public static MarshalInterfaceHelper<global::Microsoft.UI.Content.ExperimentalContentExternalBackdropLink>.MarshalerArray CreateMarshalerArray(global::Microsoft.UI.Content.ExperimentalContentExternalBackdropLink[] array)
        {
            return MarshalInterfaceHelper<global::Microsoft.UI.Content.ExperimentalContentExternalBackdropLink>.CreateMarshalerArray2(array, (global::Microsoft.UI.Content.ExperimentalContentExternalBackdropLink o) => CreateMarshaler2(o));
        }

        public static (int length, IntPtr data) GetAbiArray(object box)
        {
            return MarshalInterfaceHelper<global::Microsoft.UI.Content.ExperimentalContentExternalBackdropLink>.GetAbiArray(box);
        }

        public static global::Microsoft.UI.Content.ExperimentalContentExternalBackdropLink[] FromAbiArray(object box)
        {
            return MarshalInterfaceHelper<global::Microsoft.UI.Content.ExperimentalContentExternalBackdropLink>.FromAbiArray(box, FromAbi);
        }

        public static void CopyAbiArray(global::Microsoft.UI.Content.ExperimentalContentExternalBackdropLink[] array, object box)
        {
            MarshalInterfaceHelper<global::Microsoft.UI.Content.ExperimentalContentExternalBackdropLink>.CopyAbiArray(array, box, FromAbi);
        }

        public static (int length, IntPtr data) FromManagedArray(global::Microsoft.UI.Content.ExperimentalContentExternalBackdropLink[] array)
        {
            return MarshalInterfaceHelper<global::Microsoft.UI.Content.ExperimentalContentExternalBackdropLink>.FromManagedArray(array, (global::Microsoft.UI.Content.ExperimentalContentExternalBackdropLink o) => FromManaged(o));
        }

        public static void DisposeMarshaler(IObjectReference value)
        {
            MarshalInspectable<object>.DisposeMarshaler(value);
        }

        public static void DisposeMarshalerArray(MarshalInterfaceHelper<global::Microsoft.UI.Content.ExperimentalContentExternalBackdropLink>.MarshalerArray array)
        {
            MarshalInterfaceHelper<global::Microsoft.UI.Content.ExperimentalContentExternalBackdropLink>.DisposeMarshalerArray(array);
        }

        public static void DisposeAbi(IntPtr abi)
        {
            MarshalInspectable<object>.DisposeAbi(abi);
        }

        public static void DisposeAbiArray(object box)
        {
            MarshalInspectable<object>.DisposeAbiArray(box);
        }
    }
}