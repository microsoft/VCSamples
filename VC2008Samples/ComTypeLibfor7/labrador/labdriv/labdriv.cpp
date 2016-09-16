// labdriv.cpp : driver for the Labrador sample
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "prelabdr.h"

#pragma warning( disable : 4100)

///////////////////////////////////////////////////////////////

// helper to do print traces
void _cdecl Trace(LPCTSTR lpszFormat, ...)
{
	va_list args;
	va_start(args, lpszFormat);

	TCHAR szBuffer[512];

	_vstprintf_s(szBuffer, 512, lpszFormat, args);

	_tprintf(szBuffer);
	OutputDebugString(szBuffer);
	va_end(args);
}

// helper function to do the work
void _cdecl CallLabrador()
{
	unsigned char szTmp[32];

	Trace(_T("\nSTARTING\n=============================\n"));
	Trace(_T("Calling CoCreateInstance()...\n"));
    IMammalPtr pMammal(__uuidof(Labrador));

	Trace(_T("Calling through IMammal methods...\n"));
	pMammal->GetSpeciesName(szTmp);
	Trace(_T("Species name is <%ls>\n"), szTmp);
	LONG bIsAlive;
	pMammal->IsAlive(&bIsAlive);
	if (bIsAlive)
		Trace(_T("And it's alive!\n"));
	else
		Trace(_T("And it's dead!\n"));

	IDogPtr pDog = pMammal;

	Trace(_T("Calling through IDog methods...\n"));
	LONG bIsBarking;
	pDog->GetPetName(szTmp);
	Trace(_T("Dog's name is <%ls>\n"), szTmp);

	pDog->IsBarking(&bIsBarking);
	if (bIsBarking)
		printf("BARK! BARK! BARK! BARK!\n");

	unsigned char kiva[] = "KIVA";
	pDog->SetPetName(kiva);

	pDog->GetPetName(szTmp);
	printf("Dog's New name is <%ls>\n", szTmp);

	Trace(_T("Releasing Object\n"));
	pDog = NULL;
	pMammal = NULL;
	Trace(_T("\nDONE!!!\n=============================\n"));
}

int main( int argc, char *argv[ ])
{

	if (FAILED(CoInitialize(NULL)))
		return -1;

	CallLabrador();

#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif
	CoUninitialize();
	return 0;
}
