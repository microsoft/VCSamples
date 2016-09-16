/////////////////////////////////////////////////////////////////////
//
//  Copyright (c) Microsoft Corp 2000.  All rights reserved.
//
//  Run: nmake -f events.mak
//
//  Description: Shows how to use COM events
//
/////////////////////////////////////////////////////////////////////

// ifaces.h
[export] enum E {
        e = 17
};

[export] typedef struct S_struct {
        int i, j;
}S;

[dispinterface, uuid="ae17a339-6571-4302-8a84-6b27196f1e21"] __interface IEvent : IDispatch {
        [id(0x22)] void event1([in] E, [in] char*);
        [id(022)] HRESULT event2([in]S* a, [in]float b, [in]VARIANT c);
};

[object, library_block, uuid="8e46b2ec-a8b2-4b37-a75a-069c4336966d"] __interface IEvent2 : IUnknown {
        int event1([in]int);
        HRESULT event2([in]int, [in]float);
        void __cdecl event3(void);
};

namespace N {
        [dual, uuid="b6d8ff58-8e84-4b1e-8fb8-68fd6158154e"] __interface IJW {
        HRESULT event1();
    };
}

[dual, uuid="59fe2af1-cd5d-4845-9a99-d7b5500e45f5"] __interface IBase {
        HRESULT doSomething();
};
struct DECLSPEC_UUID("530DF3AD-6936-3214-A83B-27B63C7997C4") CSource;
