#pragma once
#include <unknwn.h>
#include <wrl/implements.h>
#include <atomic>

template <typename T>
class VerbHandlerClassFactory
    : public ::Microsoft::WRL::RuntimeClass<
    ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::ClassicCom>,
    IClassFactory>
{
public:
    // IClassFactory
    IFACEMETHODIMP CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppvObject) override;

    IFACEMETHODIMP LockServer(BOOL fLock) override;

private:
    std::atomic<LONG> m_lockCount{ 0 };
};

// Template definitions must be in the header to be visible at instantiation.

template <typename T>
IFACEMETHODIMP VerbHandlerClassFactory<T>::CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppvObject)
{
    *ppvObject = nullptr;
    if (pUnkOuter)
    {
        return CLASS_E_NOAGGREGATION;
    }

    auto instance = ::Microsoft::WRL::Make<T>();
    if (!instance)
    {
        return E_OUTOFMEMORY;
    }
    return instance->QueryInterface(riid, ppvObject);
}

template <typename T>
IFACEMETHODIMP VerbHandlerClassFactory<T>::LockServer(BOOL fLock)
{
    if (fLock)
    {
        ++m_lockCount;
    }
    else
    {
        --m_lockCount;
    }
    return S_OK;
}
