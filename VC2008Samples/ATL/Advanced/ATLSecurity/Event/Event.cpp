// Event.cpp
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

// Event.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#ifdef _UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	CDacl dacl;
	dacl.AddAllowedAce(Sids::World(), GENERIC_READ);
	dacl.AddAllowedAce(Sids::Admins(), GENERIC_ALL);
	dacl.AddDeniedAce(Sids::Network(), GENERIC_ALL);
	dacl.AddAllowedAce(Sids::System(), GENERIC_ALL);

	CSecurityDesc sd;
	sd.SetDacl(dacl);
	sd.SetOwner(Sids::Admins());

	CSecurityAttributes sa;
	sa.Set(sd);

	CEvent event(&sa, FALSE, FALSE, _T("MyEvent"));

	_getch();
	return 0;
}
