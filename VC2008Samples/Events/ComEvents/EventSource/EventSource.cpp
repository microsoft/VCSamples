// EventSource.cpp : Implementation of DLL Exports.

#include "stdafx.h"
#include "resource.h"
#include "..\ifaces.h"
// The module attribute causes DllMain, DllRegisterServer and DllUnregisterServer to be automatically implemented for you
[ module(dll, uuid = "{DFF2CBF1-2ECC-414D-9DB7-8F43A0260CAD}", 
		 name = "EventSource", 
		 helpstring = "EventSource 1.0 Type Library",
		 resource_name = "IDR_EVENTSOURCE") ];
[coclass, threading(both), event_source(com)]
struct CSource : public IBase {
    __event __interface IEvent;
    __event __interface IEvent2;
    __event __interface N::IJW;

    HRESULT doSomething() {
    	IEvent_event1((E) 'h', "hi");
     	VARIANT v;
       	VariantInit(&v);
       	V_VT(&v) = VT_I4;
       	V_I4(&v) = 866;
       	IEvent_event2(0, 3.14159, v);
       	IEvent2_event1(366);        
       	IEvent2_event2(97, 2.71);
       	IEvent2_event3();
       	return  N_IJW_event1();
    }
};