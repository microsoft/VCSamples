// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Visual C++ Language  Reference and related
// electronic documentation provided with Microsoft Visual C++.
// See these sources for detailed information regarding the
// Microsoft Visual C++ product.

// Compile with cl /GX commail.cpp
//To DO
#pragma message ("TO DO: add your Windows system directory ($(SystemRoot)\\system32 or $(SystemRoot)\\system)to Tools.Options.Projects and Solutions.VC++ Directories.Include files.")

//To Do
#pragma message("TO DO: If you have Office XP, define OFFICEXP as 1, otherwise define it as 0. If you couldn't find CDO.dll or olemsg32.dll, search for it in your machine and change the following path or install Office XP.")

#define OFFICEXP 1


#if OFFICEXP
#import "CDO.DLL" no_namespace auto_search auto_rename
#else
#import <olemsg32.dll> no_namespace
#endif

#include <stdio.h>
#include <assert.h>
#include <tchar.h>

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

// If this is placed in the scope of the smart pointers, they must be
// explicitly Release(d) before CoUninitialize() is called.  If any reference
// count is non-zero, a protection fault will occur.
struct StartOle {
    StartOle() { CoInitialize(NULL); }
    ~StartOle() { CoUninitialize(); }
} _inst_StartOle;

void AddFileToMessage(
MessagePtr  pMessage,
LPCTSTR pszFilename)
{
    FILE* fInfile;
	if (_tfopen_s(&fInfile, pszFilename, _T("r"))){
        _tprintf(_T("Cannot open file: %s.\n"), pszFilename);
        return;
    }
    TCHAR szBuffer[512];
    LPTSTR pszBuffer, pszMessage = new TCHAR[0x8000];
    *pszMessage = 0;
    int count = 0;

    while ((pszBuffer = _fgetts(szBuffer, sizeof(szBuffer), fInfile)))
    {
        count += sizeof(szBuffer)/sizeof(TCHAR);
        if (count >= 0x8000 || feof(fInfile) || pszBuffer != szBuffer)
            break;
        assert(!ferror(fInfile));
        _tcscat_s(pszMessage, 0x8000,pszBuffer);
    }
    pMessage->Text = pszMessage;
    delete [] pszMessage;
}

void main()
{
    try {

#if OFFICEXP
        _SessionPtr pSession("MAPI.Session");
#else
        SessionPtr pSession("MAPI.Session");
#endif

        //To DO
        #pragma message ("TO DO: Place profile name at line 87")
        pSession->Logon("Default Outlook Profile");

        FolderPtr   pFolder = pSession->Outbox;
        MessagesPtr pMessages = pFolder->Messages;
        MessagePtr  pMessage = pMessages->Add();

        pMessage->Subject = "VCCOM: MAPI Example";
        //To DO
        #pragma message ("TO DO: Change the absolute path to commsg.txt, line 96.  MUST DO.")
        AddFileToMessage(pMessage, _T("C:\\v7.sd\\samples\\C++\\Compiler TypeLibrary Support\\commail\\commsg.txt"));

        AttachmentsPtr pAttachments = pMessage->Attachments;
        //To DO
        #pragma message ("TO DO: Change the absolute path to this sample code, line 101.  MUST DO.")
        pAttachments->Add("Mapi example source code.txt", 15000L, (long) mapiFileData, "C:\\v7.sd\\samples\\C++\\Compiler TypeLibrary Support\\commail\\commail.cpp"); 
        
        RecipientsPtr pRecipients = pMessage->Recipients;
        RecipientPtr pRecipient = pRecipients->Add();
        //To DO
        #pragma message ("TO DO: Change the recipient name appropriately, line 107.  MUST DO.")
        pRecipient->Name = "paulring";
        pRecipient->Type = (long) mapiTo;
        bstr_t bstrName = pRecipient->Name;
        pRecipient->Resolve();

        pMessage->Send(false, false);
        pSession->Logoff();
        _tprintf(_T("Successfully sent message to %s.\n"), (LPCTSTR) bstrName );

    } 
	catch (_com_error &e) {
        dump_com_error(e);
    }
}

