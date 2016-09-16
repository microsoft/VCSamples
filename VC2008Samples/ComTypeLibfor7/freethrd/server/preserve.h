/*+==========================================================================
  File:      PRESERVE.H

  Summary:   Precompiled header include file for the aggregatable COBall 
       COM object class.

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

#ifndef _PRESERVE_H_
#define _PRESERVE_H_

#include "iball.h"
#include "apputil.h"
#include "server.h"

// NOTE:  There are problems with iball.tlb containing definitions for
//  tagRECT and tagPOINT and thus in iball.tlh.  Therefore iball.tlh
//  must be wrapped in a namespace to avoid duplicate definitions.  Whence
//  the property Ball and method Reset are actually defined for 
//  BallLib::tagRECT and BallLib::tagPOINT.  This situation will be 
//  temporary, yet some inconvenience can be alleviated with the following
//  macros.
//    
#define CAST_RECT(x) reinterpret_cast<BallLib::tagRECT> (x)
#define CAST_POINT(x) reinterpret_cast<BallLib::tagPOINT> (x)

#endif // _PRESERVE_H_
