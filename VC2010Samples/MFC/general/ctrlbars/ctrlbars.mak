# Microsoft Developer Studio Generated NMAKE File, Based on ctrlbars.dsp
!IF "$(CFG)" == ""
CFG=CtrlBars - Win32 Release
!MESSAGE No configuration specified. Defaulting to CtrlBars - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "CtrlBars - Win32 Release" && "$(CFG)" != "CtrlBars - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ctrlbars.mak" CFG="CtrlBars - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CtrlBars - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "CtrlBars - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "CtrlBars - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\ctrlbars.exe"


CLEAN :
	-@erase "$(INTDIR)\ctrlbars.obj"
	-@erase "$(INTDIR)\ctrlbars.pch"
	-@erase "$(INTDIR)\ctrlbars.res"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\palette.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\ctrlbars.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\ctrlbars.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ctrlbars.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ctrlbars.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\ctrlbars.pdb" /machine:I386 /out:"$(OUTDIR)\ctrlbars.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ctrlbars.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\palette.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\ctrlbars.res"

"$(OUTDIR)\ctrlbars.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CtrlBars - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\ctrlbars.exe"


CLEAN :
	-@erase "$(INTDIR)\ctrlbars.obj"
	-@erase "$(INTDIR)\ctrlbars.pch"
	-@erase "$(INTDIR)\ctrlbars.res"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\palette.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\ctrlbars.exe"
	-@erase "$(OUTDIR)\ctrlbars.ilk"
	-@erase "$(OUTDIR)\ctrlbars.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\ctrlbars.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ctrlbars.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ctrlbars.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\ctrlbars.pdb" /debug /machine:I386 /out:"$(OUTDIR)\ctrlbars.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ctrlbars.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\palette.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\ctrlbars.res"

"$(OUTDIR)\ctrlbars.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("ctrlbars.dep")
!INCLUDE "ctrlbars.dep"
!ELSE 
!MESSAGE Warning: cannot find "ctrlbars.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "CtrlBars - Win32 Release" || "$(CFG)" == "CtrlBars - Win32 Debug"
SOURCE=.\ctrlbars.cpp

"$(INTDIR)\ctrlbars.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ctrlbars.pch"


SOURCE=.\ctrlbars.rc

"$(INTDIR)\ctrlbars.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\mainfrm.cpp

"$(INTDIR)\mainfrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ctrlbars.pch"


SOURCE=.\palette.cpp

"$(INTDIR)\palette.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ctrlbars.pch"


SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "CtrlBars - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\ctrlbars.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\ctrlbars.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CtrlBars - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\ctrlbars.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\ctrlbars.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

