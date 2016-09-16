// Driver.h : Declaration of the CRandomEvent


#include "mdrivres.h"       // main symbols
#include <afxtempl.h>
/////////////////////////////////////////////////////////////////////////////
// Drive
struct foo
{
    foo() {nPos = 0;nDir=1;}
    int nPos;
    int nDir;
};

class CCriticalSection
{
public:
    void Lock() { EnterCriticalSection(&m_sec); }
    void Unlock() { LeaveCriticalSection(&m_sec); }
    CCriticalSection() { InitializeCriticalSection(&m_sec); } 
    ~CCriticalSection() { DeleteCriticalSection(&m_sec); }
    CRITICAL_SECTION m_sec;
};

extern LONG g_cObjCnt;
class CRandomEvent : public IRandomEvent
{
public:
    CRandomEvent() { m_cnt = 0L; m_nID = 0; }

    STDMETHOD(GetTypeInfoCount)(UINT*) { return E_NOTIMPL; }
    STDMETHOD(GetTypeInfo)(UINT, LCID, ITypeInfo**) { return E_NOTIMPL; }
    STDMETHOD(GetIDsOfNames)(REFIID, LPOLESTR*, UINT, LCID, DISPID*) { return E_NOTIMPL; }
    STDMETHOD(Invoke)(DISPID, REFIID, LCID, WORD, DISPPARAMS*, VARIANT*, EXCEPINFO*, UINT*) { return E_NOTIMPL; }
    STDMETHOD(QueryInterface)(REFIID iid, LPVOID* ppv)
    { 
        if ((iid == __uuidof(IRandomEvent)) ||
        (iid == __uuidof(IDispatch)) ||
        (iid == __uuidof(IUnknown)))
            *ppv = this;
        else
        {
            *ppv = 0;
            return E_NOINTERFACE;
        }
        AddRef();
        return S_OK;
    }
    STDMETHOD_(ULONG,AddRef)() { return InterlockedIncrement(&m_cnt); }
    STDMETHOD_(ULONG,Release)()
    { 
    InterlockedDecrement(&m_cnt);
    if (m_cnt != 0)
        return m_cnt;
    InterlockedDecrement(&g_cObjCnt);
    delete this;
    return 0;
    }
        
// IRandomEvent
    STDMETHOD(put_Fire)(long l);
    STDMETHOD(put_ID)(int n) { m_nID = n; return S_OK; }

private:
// data
    LONG m_cnt;    
    int m_nID;
    CMap<long, long, foo, foo> m_mapPos;
    CCriticalSection m_cs;
};

// NOTE: CRandomEventClassFactory is not necessary for this example, one can just use new
extern LONG g_cLockCnt;
interface CRandomEventClassFactory : public IClassFactory
{
public:
    CRandomEventClassFactory() { m_cnt = 0L; }

    STDMETHOD(CreateInstance)(IUnknown* pUnkOuter, REFIID riid, void** ppvObject)
    {
        *ppvObject=NULL;
        if (pUnkOuter != 0)
            return CLASS_E_NOAGGREGATION;

	// We must suppress PreFast warning 6014 because our ClassFactory pumps out new
	// objects and returns it.  This could appear as a memory leak, but it is up
	// to the caller to ensure that these are deleted.
#pragma warning (suppress: 6014)

        CRandomEvent* pRandomEvent = new CRandomEvent;
        if (pRandomEvent == 0)
            return E_OUTOFMEMORY;

        HRESULT hr = pRandomEvent->QueryInterface(riid, ppvObject);
        if (FAILED(hr))
            delete pRandomEvent;
        else
            InterlockedIncrement(&g_cObjCnt);

        return hr;
    }
        
    STDMETHOD(LockServer)(BOOL fLock)
    {
        if (fLock)
            InterlockedIncrement(&g_cLockCnt);
        else
            InterlockedDecrement(&g_cLockCnt);
        return S_OK;
    }     
    STDMETHOD(QueryInterface)(REFIID iid, LPVOID* ppv)
    { 
        if ((iid == __uuidof(IClassFactory)) ||
        (iid == __uuidof(IUnknown)))
            *ppv = this;
        else
        {
            *ppv = 0;
            return E_NOINTERFACE;
        }
        AddRef();
        return S_OK;
    }
    STDMETHOD_(ULONG,AddRef)() { return InterlockedIncrement(&m_cnt); }
    STDMETHOD_(ULONG,Release)()
    {  
    InterlockedDecrement(&m_cnt);
    if (m_cnt != 0)
        return m_cnt;
    delete this;
    return 0;
    } 
private:
    LONG m_cnt;
};
/////////////////////////////////////////////////////////////////////////////


