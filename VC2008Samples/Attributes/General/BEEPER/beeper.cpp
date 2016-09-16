// beeper.cpp : Implementation of CBeeperApp and DLL registration.
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "prebeep.h"
#include "beepres.h"
#include "beeper.h"

/////////////////////////////////////////////////////////////////////////////
//
#ifndef _WINDLL

[ module(exe, name = "BeeperAttribLib", uuid = "{283624D8-1862-11D3-ABE1-00C04F797AB7}", version = "1.0")];

#else

[ module(dll, name = "BeeperAttribLib", uuid = "{283624D8-1862-11D3-ABE1-00C04F797AB7}", version = "1.0")];

#endif //!_WINDLL

[emitidl];