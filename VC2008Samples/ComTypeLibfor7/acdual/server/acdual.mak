# Microsoft Developer Studio Generated NMAKE File, Based on acdual.dsp
!IF "$(CFG)" == ""
CFG=ACDual - Win32 Release
!MESSAGE No configuration specified.  Defaulting to ACDual - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "ACDual - Win32 Release" && "$(CFG)" != "ACDual - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "acdual.mak" CFG="ACDual - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ACDual - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "ACDual - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ACDual - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\acdual.exe" "$(OUTDIR)\Autoclik.tlb"

CLEAN : 
	-@erase "$(INTDIR)\acdual.pch"
	-@erase "$(INTDIR)\Aclikdoc.obj"
	-@erase "$(INTDIR)\Aclikvw.obj"
	-@erase "$(INTDIR)\Autoclik.obj"
	-@erase "$(INTDIR)\Autoclik.res"
	-@erase "$(INTDIR)\Autoclik.tlb"
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\Clikpnt.obj"
	-@erase "$(INTDIR)\Dialogs.obj"
	-@erase "$(INTDIR)\initIIDs.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MFCDual.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\acdual.exe"
	-@erase ".\ACDual.h"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\acdual.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Autoclik.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\acdual.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\acdual.pdb" /machine:I386 /out:"$(OUTDIR)\acdual.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Aclikdoc.obj" \
	"$(INTDIR)\Aclikvw.obj" \
	"$(INTDIR)\Autoclik.obj" \
	"$(INTDIR)\Autoclik.res" \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\Clikpnt.obj" \
	"$(INTDIR)\Dialogs.obj" \
	"$(INTDIR)\initIIDs.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MFCDual.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\acdual.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ACDual - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\acdual.exe" "$(OUTDIR)\Autoclik.tlb"

CLEAN : 
	-@erase "$(INTDIR)\acdual.pch"
	-@erase "$(INTDIR)\Aclikdoc.obj"
	-@erase "$(INTDIR)\Aclikvw.obj"
	-@erase "$(INTDIR)\Autoclik.obj"
	-@erase "$(INTDIR)\Autoclik.res"
	-@erase "$(INTDIR)\Autoclik.tlb"
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\Clikpnt.obj"
	-@erase "$(INTDIR)\Dialogs.obj"
	-@erase "$(INTDIR)\initIIDs.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MFCDual.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\acdual.exe"
	-@erase "$(OUTDIR)\acdual.ilk"
	-@erase "$(OUTDIR)\acdual.pdb"
	-@erase ".\ACDual.h"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\acdual.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Autoclik.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\acdual.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\acdual.pdb" /debug /machine:I386 /out:"$(OUTDIR)\acdual.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Aclikdoc.obj" \
	"$(INTDIR)\Aclikvw.obj" \
	"$(INTDIR)\Autoclik.obj" \
	"$(INTDIR)\Autoclik.res" \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\Clikpnt.obj" \
	"$(INTDIR)\Dialogs.obj" \
	"$(INTDIR)\initIIDs.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MFCDual.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\acdual.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj::
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr::
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) $(CPP_PROJ) $<  


!IF "$(CFG)" == "ACDual - Win32 Release" || "$(CFG)" == "ACDual - Win32 Debug"
SOURCE=.\Aclikdoc.cpp

!IF  "$(CFG)" == "ACDual - Win32 Release"

DEP_CPP_ACLIK=\
	".\AClikDoc.h"\
	".\AutoClik.h"\
	".\ClikPnt.h"\
	".\Dialogs.h"\
	

"$(INTDIR)\Aclikdoc.obj" : $(SOURCE) $(DEP_CPP_ACLIK) "$(INTDIR)"\
 "$(INTDIR)\acdual.pch"


!ELSEIF  "$(CFG)" == "ACDual - Win32 Debug"

DEP_CPP_ACLIK=\
	".\AClikDoc.h"\
	".\AutoClik.h"\
	".\ClikPnt.h"\
	".\Dialogs.h"\
	

"$(INTDIR)\Aclikdoc.obj" : $(SOURCE) $(DEP_CPP_ACLIK) "$(INTDIR)"\
 "$(INTDIR)\acdual.pch"


!ENDIF 

SOURCE=.\Aclikvw.cpp

!IF  "$(CFG)" == "ACDual - Win32 Release"

DEP_CPP_ACLIKV=\
	".\AClikDoc.h"\
	".\AClikVw.h"\
	".\AutoClik.h"\
	

"$(INTDIR)\Aclikvw.obj" : $(SOURCE) $(DEP_CPP_ACLIKV) "$(INTDIR)"\
 "$(INTDIR)\acdual.pch"


!ELSEIF  "$(CFG)" == "ACDual - Win32 Debug"

DEP_CPP_ACLIKV=\
	".\AClikDoc.h"\
	".\AClikVw.h"\
	".\AutoClik.h"\
	

"$(INTDIR)\Aclikvw.obj" : $(SOURCE) $(DEP_CPP_ACLIKV) "$(INTDIR)"\
 "$(INTDIR)\acdual.pch"


!ENDIF 

SOURCE=.\Autoclik.cpp

!IF  "$(CFG)" == "ACDual - Win32 Release"

DEP_CPP_AUTOC=\
	".\AClikDoc.h"\
	".\AClikVw.h"\
	".\AutoClik.h"\
	".\ChildFrm.h"\
	".\MainFrm.h"\
	

"$(INTDIR)\Autoclik.obj" : $(SOURCE) $(DEP_CPP_AUTOC) "$(INTDIR)"\
 "$(INTDIR)\acdual.pch"


!ELSEIF  "$(CFG)" == "ACDual - Win32 Debug"

DEP_CPP_AUTOC=\
	".\AClikDoc.h"\
	".\AClikVw.h"\
	".\AutoClik.h"\
	".\ChildFrm.h"\
	".\MainFrm.h"\
	

"$(INTDIR)\Autoclik.obj" : $(SOURCE) $(DEP_CPP_AUTOC) "$(INTDIR)"\
 "$(INTDIR)\acdual.pch"


!ENDIF 

SOURCE=.\Autoclik.odl

!IF  "$(CFG)" == "ACDual - Win32 Release"


"$(OUTDIR)\Autoclik.tlb"	".\ACDual.h" : $(SOURCE) "$(OUTDIR)"
	$(MTL) /nologo /D "NDEBUG" /tlb "$(OUTDIR)\Autoclik.tlb" /h "ACDual.h"\
 /mktyplib203 /win32 $(SOURCE)


!ELSEIF  "$(CFG)" == "ACDual - Win32 Debug"


"$(OUTDIR)\Autoclik.tlb"	".\ACDual.h" : $(SOURCE) "$(OUTDIR)"
	$(MTL) /nologo /D "_DEBUG" /tlb "$(OUTDIR)\Autoclik.tlb" /h "ACDual.h"\
 /mktyplib203 /win32 $(SOURCE)


!ENDIF 

SOURCE=.\Autoclik.rc
DEP_RSC_AUTOCL=\
	".\res\AClikDoc.ico"\
	".\res\AutoClik.ico"\
	".\res\AutoClik.rc2"\
	".\res\Toolbar.bmp"\
	

!IF  "$(CFG)" == "ACDual - Win32 Release"


"$(INTDIR)\Autoclik.res" : $(SOURCE) $(DEP_RSC_AUTOCL) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\Autoclik.res" /i ".\Release" /d "NDEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "ACDual - Win32 Debug"


"$(INTDIR)\Autoclik.res" : $(SOURCE) $(DEP_RSC_AUTOCL) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\Autoclik.res" /i ".\Debug" /d "_DEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ENDIF 

SOURCE=.\ChildFrm.cpp
DEP_CPP_CHILD=\
	".\AutoClik.h"\
	".\ChildFrm.h"\
	

"$(INTDIR)\ChildFrm.obj" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\acdual.pch"


SOURCE=.\Clikpnt.cpp
DEP_CPP_CLIKP=\
	".\AutoClik.h"\
	".\ClikPnt.h"\
	

"$(INTDIR)\Clikpnt.obj" : $(SOURCE) $(DEP_CPP_CLIKP) "$(INTDIR)"\
 "$(INTDIR)\acdual.pch"


SOURCE=.\Dialogs.cpp

!IF  "$(CFG)" == "ACDual - Win32 Release"

DEP_CPP_DIALO=\
	".\AutoClik.h"\
	".\Dialogs.h"\
	

"$(INTDIR)\Dialogs.obj" : $(SOURCE) $(DEP_CPP_DIALO) "$(INTDIR)"\
 "$(INTDIR)\acdual.pch"


!ELSEIF  "$(CFG)" == "ACDual - Win32 Debug"

DEP_CPP_DIALO=\
	".\AutoClik.h"\
	".\Dialogs.h"\
	

"$(INTDIR)\Dialogs.obj" : $(SOURCE) $(DEP_CPP_DIALO) "$(INTDIR)"\
 "$(INTDIR)\acdual.pch"


!ENDIF 

SOURCE=.\initIIDs.cpp
DEP_CPP_INITI=\
	".\ACDual.h"\
	

!IF  "$(CFG)" == "ACDual - Win32 Release"


"$(INTDIR)\initIIDs.obj" : $(SOURCE) $(DEP_CPP_INITI) "$(INTDIR)" ".\ACDual.h"
	$(CPP) /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ACDual - Win32 Debug"


"$(INTDIR)\initIIDs.obj" : $(SOURCE) $(DEP_CPP_INITI) "$(INTDIR)" ".\ACDual.h"
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ENDIF 

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "ACDual - Win32 Release"

DEP_CPP_MAINF=\
	".\AutoClik.h"\
	".\MainFrm.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\acdual.pch"


!ELSEIF  "$(CFG)" == "ACDual - Win32 Debug"

DEP_CPP_MAINF=\
	".\AutoClik.h"\
	".\MainFrm.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\acdual.pch"


!ENDIF 

SOURCE=.\MFCDual.cpp
DEP_CPP_MFCDU=\
	".\AutoClik.h"\
	

"$(INTDIR)\MFCDual.obj" : $(SOURCE) $(DEP_CPP_MFCDU) "$(INTDIR)"\
 "$(INTDIR)\acdual.pch"


SOURCE=.\ReadMe.txt
SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "ACDual - Win32 Release"

DEP_CPP_STDAF=\
	".\ACDual.h"\
	".\mfcdual.h"\
	".\StdAfx.h"\
	"d:\msdev\include\zmouse.h"\
	

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\acdual.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)" ".\ACDual.h"
	$(CPP) /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\acdual.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ACDual - Win32 Debug"

DEP_CPP_STDAF=\
	".\ACDual.h"\
	".\mfcdual.h"\
	".\StdAfx.h"\
	"d:\msdev\include\zmouse.h"\
	

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\acdual.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)" ".\ACDual.h"
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\acdual.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ENDIF 

SOURCE=.\ACDual.h
SOURCE=.\AClikDoc.h
SOURCE=.\AClikVw.h
SOURCE=.\AutoClik.h
SOURCE=.\ChildFrm.h
SOURCE=.\ClikPnt.h
SOURCE=.\Dialogs.h
SOURCE=.\MainFrm.h
SOURCE=.\mfcdual.h
SOURCE=.\StdAfx.h
SOURCE=.\res\AClikDoc.ico
SOURCE=.\res\AutoClik.ico
SOURCE=.\res\AutoClik.rc2
SOURCE=.\res\Toolbar.bmp

!ENDIF 

