/*+==========================================================================
  File:      PRECLIEN.H

  Summary:   Precompiled header include file of controller for the 
       aggregatable COBall COM server preserver.dll.


  Origin:    10-1-96: paulring -- port to VC5 native COM support.

----------------------------------------------------------------------------
  This file is part of the Microsoft OLE Tutorial Code Samples.

  Copyright (c) Microsoft Corporation, 1996.  All rights reserved.

  This source code is intended only as a supplement to Microsoft
  Development Tools and/or on-line documentation.  See these other
  materials for detailed information regarding Microsoft code samples.

  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
  PARTICULAR PURPOSE.
==========================================================================+*/

#ifndef _PRECLIEN_H_
#define _PRECLIEN_H_

#include <windows.h>
#include <tchar.h>
#include "..\server\apputil.h"

#import "..\server\iball.tlb" exclude("tagRECT") exclude("tagPOINT")
using namespace BallLib;

#include "guiball.h"
#include "freclien.h"

// NOTE:  There are problems with iball.tlb containing definitions for
//  tagRECT and tagPOINT and thus in iball.tlh.  The "exclude" import
//  attribute solves this problem.
//    

#endif // _PRECLIEN_H_
