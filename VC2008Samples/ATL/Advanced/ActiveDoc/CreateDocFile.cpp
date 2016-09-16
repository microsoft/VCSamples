#include <windows.h>
#include "ActiveDoc_i.c"

// Creates a compound file which can be used to host ActiveDoc in Internet Explorer
// Compile with 
// cl createdocfile.cpp /link ole32.lib
// Use ActiveDoc.htm to test - after this program has been run.

void main ()
{
    HRESULT hr = CoInitialize(NULL);
	if (FAILED(hr))
		return;

    IStorage  * pStorage = NULL;
    
    hr = StgCreateDocfile(
        L"ActiveDoc.AAA", 
        STGM_CREATE | STGM_READWRITE | STGM_SHARE_EXCLUSIVE , 
        NULL, 
        &pStorage);

    if (SUCCEEDED(hr))
	{
		pStorage->SetClass(CLSID_CActiveDoc);
	    pStorage->Release();
	}

	CoUninitialize();
}