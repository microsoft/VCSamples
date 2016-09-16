# Microsoft Developer Studio Generated NMAKE File, Based on ctlcomm.dsp
!IF "$(CFG)" == ""
CFG=ctlcomm - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to ctlcomm - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "ctlcomm - Win32 Release" && "$(CFG)" !=\
 "ctlcomm - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "ctlcomm.mak" CFG="ctlcomm - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ctlcomm - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "ctlcomm - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "ctlcomm - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\ctlcomm.exe"

CLEAN : 
	-@erase "$(INTDIR)\ctlcomm.obj"
	-@erase "$(INTDIR)\ctlcomm.pch"
	-@erase "$(INTDIR)\ctlcomm.res"
	-@erase "$(INTDIR)\ctlcommDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\ctlcomm.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /Fp"$(INTDIR)\ctlcomm.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ctlcomm.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ctlcomm.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\ctlcomm.pdb" /machine:I386 /out:"$(OUTDIR)\ctlcomm.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ctlcomm.obj" \
	"$(INTDIR)\ctlcomm.res" \
	"$(INTDIR)\ctlcommDlg.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\ctlcomm.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ctlcomm - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\ctlcomm.exe"

CLEAN : 
	-@erase "$(INTDIR)\ctlcomm.obj"
	-@erase "$(INTDIR)\ctlcomm.pch"
	-@erase "$(INTDIR)\ctlcomm.res"
	-@erase "$(INTDIR)\ctlcommDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\ctlcomm.exe"
	-@erase "$(OUTDIR)\ctlcomm.ilk"
	-@erase "$(OUTDIR)\ctlcomm.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /Fp"$(INTDIR)\ctlcomm.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ctlcomm.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ctlcomm.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\ctlcomm.pdb" /debug /machine:I386 /out:"$(OUTDIR)\ctlcomm.exe"\
 /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\ctlcomm.obj" \
	"$(INTDIR)\ctlcomm.res" \
	"$(INTDIR)\ctlcommDlg.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\ctlcomm.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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


!IF "$(CFG)" == "ctlcomm - Win32 Release" || "$(CFG)" ==\
 "ctlcomm - Win32 Debug"
SOURCE=.\ctlcomm.cpp

!IF  "$(CFG)" == "ctlcomm - Win32 Release"

DEP_CPP_CTLCO=\
	".\ctlcomm.h"\
	".\ctlcommDlg.h"\
	

"$(INTDIR)\ctlcomm.obj" : $(SOURCE) $(DEP_CPP_CTLCO) "$(INTDIR)"\
 "$(INTDIR)\ctlcomm.pch"


!ELSEIF  "$(CFG)" == "ctlcomm - Win32 Debug"

DEP_CPP_CTLCO=\
	".\ctlcomm.h"\
	".\ctlcommDlg.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ctlcomm.obj" : $(SOURCE) $(DEP_CPP_CTLCO) "$(INTDIR)"\
 "$(INTDIR)\ctlcomm.pch"


!ENDIF 

SOURCE=.\ctlcomm.rc
DEP_RSC_CTLCOM=\
	".\res\ctlcomm.ico"\
	".\res\ctlcomm.rc2"\
	

"$(INTDIR)\ctlcomm.res" : $(SOURCE) $(DEP_RSC_CTLCOM) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\ctlcommDlg.cpp

!IF  "$(CFG)" == "ctlcomm - Win32 Release"

DEP_CPP_CTLCOMM=\
	".\ctlcomm.h"\
	".\ctlcommDlg.h"\
	

"$(INTDIR)\ctlcommDlg.obj" : $(SOURCE) $(DEP_CPP_CTLCOMM) "$(INTDIR)"\
 "$(INTDIR)\ctlcomm.pch"


!ELSEIF  "$(CFG)" == "ctlcomm - Win32 Debug"

DEP_CPP_CTLCOMM=\
	".\ctlcomm.h"\
	".\ctlcommDlg.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ctlcommDlg.obj" : $(SOURCE) $(DEP_CPP_CTLCOMM) "$(INTDIR)"\
 "$(INTDIR)\ctlcomm.pch"


!ENDIF 

SOURCE=.\ReadMe.txt
SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "ctlcomm - Win32 Release"

DEP_CPP_STDAF=\
	"..\commap.tlb"\
	".\StdAfx.h"\
	"d:\msdev\include\zmouse.h"\
	

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ctlcomm.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /Fp"$(INTDIR)\ctlcomm.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ELSEIF  "$(CFG)" == "ctlcomm - Win32 Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ctlcomm.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /Fp"$(INTDIR)\ctlcomm.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ENDIF 

SOURCE=.\ctlcomm.h
SOURCE=.\ctlcommDlg.h
SOURCE=.\Resource.h
SOURCE=.\StdAfx.h
SOURCE=.\res\ctlcomm.ico
SOURCE=.\res\ctlcomm.rc2

!ENDIF 

