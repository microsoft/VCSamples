// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Visual C++ Language  Reference and related
// electronic documentation provided with Microsoft Visual C++.
// See these sources for detailed information regarding the
// Microsoft Visual C++ product.

#import "..\server\adosamp.tlb" no_namespace rename("EOF", "ADOEOF")
#include <stdio.h>
#include <tchar.h>

//#define SQLSERVER

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

struct InitOle {
	InitOle() { CoInitialize(NULL); }
	~InitOle() { CoUninitialize(); }
} _init_InitOle_ ;

void main()
{
	try {
	IADOTierPtr p(__uuidof(CADOTier));
	p->Open("HotBikes", "sa", "");

	try {
	p->ExecuteConnection("DROP TABLE HotBikes", VARIANT_FALSE);
	} catch (_com_error& e) {
	printf("TABLE does not exist -- ok, go create it...\n");
	dump_com_error(e);
	}

	printf("\nCreate table with 3 fields: an ID, model, and manufacturer.\n");
	p->ExecuteConnection("CREATE TABLE HotBikes (ID INTEGER, Model VarChar(25), Manufacturer VarChar(80))", VARIANT_FALSE);

	printf("\nShove some data in it.\n");
	p->AppendParameter(adInteger, 20L, adParamInput, -1);
	p->AppendParameter(adVarChar, "ZX-11", adParamInput, 25);
	p->AppendParameter(adVarChar, "Kawasaki", adParamInput, 80);
	p->CommandText = "insert into HotBikes (ID, Model, Manufacturer) values (?, ?, ?)";
	p->ExecuteCommand(VARIANT_FALSE, VARIANT_FALSE);

	_bstr_t query = "insert into HotBikes (ID, Model, Manufacturer) values (?, ?, ?)";
	p->ParamQuery(query, 21, "Trail Breaker", "Rokon");
	p->ParamQuery(query, 33, "900 Trident", "Triumph");

	p->OpenRecordset("SELECT * FROM HotBikes ORDER BY ID");
	if (!p->Empty)
	{
		p->First();
		while (!p->ADOEOF)
		{
			printf("%d. %S, %S\n", (long) p->Field[0L], (BSTR) (_bstr_t) p->Field[1L], (BSTR) (_bstr_t) p->Field[2L]);
			p->Next();
		}
		p->First();
		printf ("Now empty out the table.\n");
		while (!p->ADOEOF)
		{
			p->Delete();
			p->Next();
		}
	}

	printf("\nToo slow, and I feel the need for speed.  Put some bikes back in the table\n");
	p->Requery();
	if (!p->Empty)
        {
	    for (p->First(); !p->ADOEOF; p->Next())
		printf("%d. %S, %S\n", (long) p->Field[0L], (BSTR) (_bstr_t) p->Field[1L], (BSTR) (_bstr_t) p->Field[2L]);
	}

	p->ParamQuery(query, 1, "ZX-11", "Kawasaki");
	p->ParamQuery(query, 2, "CBR-900RR", "Honda");
	p->ParamQuery(query, 9, "GSX-R 1000", "Suzuki");
	p->ParamQuery(query, 4, "ZX6.5", "Kawasaki");
	p->ParamQuery(query, 5, "900SS", "Ducati");
	p->ParamQuery(query, 6, "YB9SR", "Bimota");
	p->ParamQuery(query, 7, "1400RR", "Buell");
	p->ParamQuery(query, 8, "FZR 1000", "Yamaha");
	p->ParamQuery(query, 3, "Trail 90", "Honda");
	p->ParamQuery(query, 10, "R1100R", "BMW");
	p->ParamQuery(query, 11, "Daytona", "Triumph");

	p->Requery();
	if (!p->Empty)
        {
	    for (p->First(); !p->ADOEOF; p->Next())
		printf("%d, %S, %S\n", (long) p->Field[0L], (BSTR) (_bstr_t) p->Field[1L], (BSTR) (_bstr_t) p->Field[2L]);
	}

	p->ExecuteConnection("UPDATE HotBikes SET Model='ZX7' WHERE ID=4", VARIANT_FALSE);

	printf("\nFix Typo...ZX7, not ZX6.5\n");
	p->Requery();
	if (!p->Empty)
        {
	    for (p->First(); !p->ADOEOF; p->Next())
		printf("%d. %S, %S\n", (long) p->Field[0L], (BSTR) (_bstr_t) p->Field[1L], (BSTR) (_bstr_t) p->Field[2L]);
	}

	printf("\nThat's better -- hey, how did the Trail 90 make it on this list???\n");

	p->CloseRecordset();
	printf("\nAdd a new field for top speed, enter relevant data and order by TopSpeed.\n");
	p->ExecuteConnection("ALTER TABLE HotBikes ADD TopSpeed INTEGER", VARIANT_FALSE);

	p->ExecuteConnection("UPDATE HotBikes SET TopSpeed=170 WHERE ID=1", VARIANT_FALSE);
	p->ExecuteConnection("UPDATE HotBikes SET TopSpeed=163 WHERE ID=2", VARIANT_FALSE);
	p->ExecuteConnection("UPDATE HotBikes SET TopSpeed=0 WHERE ID=3", VARIANT_FALSE);
	p->ExecuteConnection("UPDATE HotBikes SET TopSpeed=155 WHERE ID=4", VARIANT_FALSE);
	p->ExecuteConnection("UPDATE HotBikes SET TopSpeed=137 WHERE ID=5", VARIANT_FALSE);
	p->ExecuteConnection("UPDATE HotBikes SET TopSpeed=132 WHERE ID=6", VARIANT_FALSE);
	p->ExecuteConnection("UPDATE HotBikes SET TopSpeed=130 WHERE ID=7", VARIANT_FALSE);
	p->ExecuteConnection("UPDATE HotBikes SET TopSpeed=164  WHERE ID=8", VARIANT_FALSE);
	p->ExecuteConnection("UPDATE HotBikes SET TopSpeed=165 WHERE ID=9", VARIANT_FALSE);
	p->ExecuteConnection("UPDATE HotBikes SET TopSpeed=125 WHERE ID=10", VARIANT_FALSE);
	p->ExecuteConnection("UPDATE HotBikes SET TopSpeed=150 WHERE ID=11", VARIANT_FALSE);

	p->OpenRecordset("SELECT * FROM HotBikes ORDER BY TopSpeed");
	if (!p->Empty)
        {
	    for (p->First(); !p->ADOEOF; p->Next())
	        printf("ID=%d, TopSpeed=%d, %S, %S\n", (long) p->Field[0L], (long) p->Field[3L], (BSTR) (_bstr_t) p->Field[1L], (BSTR) (_bstr_t) p->Field[2L]);
	}

	p->ExecuteConnection("DELETE FROM HotBikes WHERE TopSpeed=0", VARIANT_FALSE);

	printf("\nDelete all entries with NO TopSpeed.\n");
	p->Requery();
	if (!p->Empty)
	{
	    for (p->First(); !p->ADOEOF; p->Next())
		printf("ID=%d, TopSpeed=%d, %S, %S\n", (long) p->Field[0L], (long) p->Field[3L], (BSTR) (_bstr_t) p->Field[1L], (BSTR) (_bstr_t) p->Field[2L]);
	}

	p->CloseRecordset();
#ifndef SQLSERVER
	// NOTE:  SQLServer does not allow this command
	p->ExecuteConnection("ALTER TABLE HotBikes DROP COLUMN ID", VARIANT_FALSE);

	printf("\nDrop the ID field\n");
	p->OpenRecordset("SELECT * FROM HotBikes ORDER BY TopSpeed");
	if (!p->Empty)
        {
	    for (p->First(); !p->ADOEOF; p->Next())
		printf("TopSpeed=%d, %S, %S\n", (long) p->Field[2L], (BSTR) (_bstr_t) p->Field[0L], (BSTR) (_bstr_t) p->Field[1L]);
	}

	p->CloseRecordset();
#endif
	printf("\nDelete all entries with insufficient top speed  (Okay, less than 160).\n");
	p->OpenRecordset("SELECT * FROM HotBikes WHERE TopSpeed<160");
	p->First();
	while (!p->ADOEOF)
	{
		p->Delete();
		p->Next();
	}

	p->CloseRecordset();
	p->OpenRecordset("SELECT * FROM HotBikes ORDER BY TopSpeed DESC");
	if (!p->Empty)
        {
	    for (p->First(); !p->ADOEOF; p->Next())
#ifdef SQLSERVER
		printf("ID=%d, TopSpeed=%d, %S, %S\n", (long) p->Field[0L], (long) p->Field[3L], (BSTR) (_bstr_t) p->Field[1L], (BSTR) (_bstr_t) p->Field[2L]);
#else
		printf("TopSpeed=%d, %S, %S\n", (long) p->Field[2L], (BSTR) (_bstr_t) p->Field[0L], (BSTR) (_bstr_t) p->Field[1L]);
#endif
	}

	p->CloseRecordset();
	p->Close();
	p->ADORelease();

	} catch (_com_error& e) {
	dump_com_error(e);
	}
}
