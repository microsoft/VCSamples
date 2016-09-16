// EventReceiver.cpp : Implementation of WinMain

#include "stdafx.h"
#include "resource.h"
#include "..\ifaces.h"

// The module attribute causes WinMain to be automatically implemented for you
[ module(uuid = "{7F52348D-4E5A-4570-8D5E-9BB27400C954}", 
		 name = "EventReceiver", 
		 helpstring = "EventReceiver 1.0 Type Library",
		 resource_name = "IDR_EVENTRECEIVER") ];
 
[ event_receiver(com)]
struct CSink {
    void __cdecl f1() { 
    printf("CSink::f1(this=%p)\n", this);
    }
    HRESULT f2() {
        printf("CSink::f2(this=%p)\n", this);
        return S_OK;
    }
    void f3(E c, char* pc) {
        printf("CSink::f3(this=%p,c=%c,pc=%s)\n", this, c, pc);
    }
    static HRESULT f4(S* i, float j, VARIANT c) {
        printf("CSink::f4(i=%p,j=%lf,c=%p)\n", i, j, &c);
        return S_OK;
    }
    int f5(int i) {
        printf("CSink::f5(this=%p,i=%d)\n", this, i);
        return 0;
    }
    HRESULT f6(int i, float j) {
        printf("CSink::f6(this=%p,i=%d,j=%lf)\n", this, i, j);
        return S_OK;
    }
    void method(HRESULT hr) {
        printf("CSink::method(hr=0x%x)\n", hr);
    }
    CSink(IBase* pS) {
        method(__hook(&IEvent::event2, pS, &CSink::f4));
        __hook(&IEvent2::event1, pS, &CSink::f5);
        __hook(&IEvent2::event2, pS, &CSink::f6);
        __hook(&IEvent2::event3, pS, &CSink::f1);
        __hook(&IEvent::event1, pS, &CSink::f3);
        __hook(&N::IJW::event1, pS, &CSink::f2);
    }
    void UnHook(IBase* pS) {
        __unhook(IEvent2, pS);
        __unhook(&IEvent::event1, pS, &CSink::f3);
        __unhook(&IEvent::event2, pS, &CSink::f4);
        __unhook(&N::IJW::event1, pS, &CSink::f2);
    }
    void UnHookAll(IBase* pS) {
        __unhook(pS);
    }
};

int main(int argc, char* argv[]) {
    CoInitialize(NULL);
	{
		IBase* pS = 0;
		HRESULT hr = CoCreateInstance(__uuidof(CSource), NULL, CLSCTX_ALL, __uuidof(IBase), (void **)&pS);
		if (FAILED(hr)) {
			return hr;
		}
		CSink sink(pS);
		printf("Hooked.\n");
		pS->doSomething();
		sink.UnHook(pS);
		printf("Unhooked.\n");
		pS->doSomething();
		printf("Done.\n");
	}
    CoUninitialize();
}

