# This is a part of the Microsoft Foundation Classes C++ library.
# Copyright (c) Microsoft Corporation.  All rights reserved.
#
# This source code is only intended as a supplement to the
# Microsoft Foundation Classes Reference and related
# electronic documentation provided with the library.
# See these sources for detailed information regarding the
# Microsoft Foundation Classes product.

PROJ=MFCCALC
OBJS=mfccalc.obj calcdlg.obj
USES_OLE=1

!if "$(PLATFORM)" == "M68K" || "$(PLATFORM)" == "MPPC"
MACPROJ=MFCCalculator
MACSIG=CALC
!else
EXTRA_LIBS=/subsystem:windows,4.0
!endif

!include <mfcsamps.mak>
