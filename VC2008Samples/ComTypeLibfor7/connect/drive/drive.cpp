// Drive.cpp : Implementation of WinMain

// You will need the NT SUR Beta 2 SDK or VC 4.2 in order to build this 
// project.  This is because you will need MIDL 3.00.15 or higher and new
// headers and libs.  If you have VC 4.2 installed, then everything should
// already be configured correctly.

#include "predrive.h"

void dump_com_error(_com_error &e)
{
    _tprintf(_T("Oops - hit an error!\n"));
    _tprintf(_T("\a\tCode = %08lx\n"), e.Error());
    _tprintf(_T("\a\tCode meaning = %s\n"), e.ErrorMessage());
    _bstr_t bstrSource(e.Source());
    _bstr_t bstrDescription(e.Description());
    _tprintf(_T("\a\tSource = %s\n"), (LPCTSTR) bstrSource);
    _tprintf(_T("\a\tDescription = %s\n"), (LPCTSTR) bstrDescription);
}

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
    CRandomEvent() { m_cnt = 0L; }

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
  STDMETHOD(put_Fire(long ))
    {
        m_cs.Lock();
        // Fake out multiple conection points
        static int cnt = 0;
        _tprintf(_T("%d\n"), cnt++);
        m_cs.Unlock();
        return S_OK;
    }
    STDMETHOD(put_ID)(int ) { return S_OK; }

private:
// data
    LONG m_cnt;    
    CCriticalSection m_cs;
};

/////////////////////////////////////////////////////////////////////////////
//

// Force template instantiation outside C-linkage
int Drive()
{
    CoInitializeEx(NULL, COINIT_MULTITHREADED);
    try {
    IRandomPtr pM(__uuidof(CoRandom));

    long nID;
    nID = pM->Start;
    DWORD dwTick = GetTickCount();
    while (GetTickCount()-dwTick < 3000)
    {
        // Fake out CoCreateInstance
        // Suppress the PreFast warning here.  PreFast cannot do ref counting
        // and does not realize that this will in fact be deleted.
#pragma warning (suppress: 6014)
        CRandomEvent* pRandomEvent = new CRandomEvent;
        assert(pRandomEvent != NULL);
        InterlockedIncrement(&g_cObjCnt);
        pRandomEvent->AddRef();

        DWORD dwAdvise = 0;
        IConnectionPointContainerPtr pCPC;
        IConnectionPointPtr pCP;
        pCPC = pM;
        if (FAILED(pCPC->FindConnectionPoint(__uuidof(IRandomEvent), &pCP)))
	    continue;
        if (FAILED(pCP->Advise(pRandomEvent, &dwAdvise)))
            continue;
        puts("Connect");
        Sleep(1);
        if (FAILED(pCP->Unadvise(dwAdvise)))
            continue;
        puts("Disconnect");
        Sleep(1);
        pRandomEvent->Release();
    }
    pM->Stop = nID;
    pM = 0;
    } catch (_com_error& e) {
    dump_com_error(e);
    }

    assert(g_cObjCnt == 0L);
    CoUninitialize();
    return 0;
}

extern "C" int WINAPI _tWinMain(HINSTANCE , HINSTANCE ,
    LPTSTR , int ) {
    return Drive();
}

/////////////////////////////////////////////////////////////////////////////



