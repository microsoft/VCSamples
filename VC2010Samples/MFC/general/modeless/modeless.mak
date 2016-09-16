# Microsoft Developer Studio Generated NMAKE File, Based on modeless.dsp
!IF "$(CFG)" == ""
CFG=modeless - Win32 Release
!MESSAGE No configuration specified. Defaulting to modeless - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "modeless - Win32 Release" && "$(CFG)" != "modeless - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "modeless.mak" CFG="modeless - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "modeless - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "modeless - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "modeless - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\modeless.exe" "$(OUTDIR)\modeless.bsc"


CLEAN :
	-@erase "$(INTDIR)\adderdlg.obj"
	-@erase "$(INTDIR)\adderdlg.sbr"
	-@erase "$(INTDIR)\modeldlg.obj"
	-@erase "$(INTDIR)\modeldlg.sbr"
	-@erase "$(INTDIR)\modeless.obj"
	-@erase "$(INTDIR)\modeless.pch"
	-@erase "$(INTDIR)\modeless.res"
	-@erase "$(INTDIR)\modeless.sbr"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\stdafx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\modeless.bsc"
	-@erase "$(OUTDIR)\modeless.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\modeless.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\modeless.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\modeless.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\adderdlg.sbr" \
	"$(INTDIR)\modeldlg.sbr" \
	"$(INTDIR)\modeless.sbr" \
	"$(INTDIR)\stdafx.sbr"

"$(OUTDIR)\modeless.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\modeless.pdb" /machine:I386 /out:"$(OUTDIR)\modeless.exe" 
LINK32_OBJS= \
	"$(INTDIR)\adderdlg.obj" \
	"$(INTDIR)\modeldlg.obj" \
	"$(INTDIR)\modeless.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\modeless.res"

"$(OUTDIR)\modeless.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "modeless - Win32 Debug"

OUTDIR=.\WinDebug
INTDIR=.\WinDebug
# Begin Custom Macros
OutDir=.\.\WinDebug
# End Custom Macros

ALL : "$(OUTDIR)\modeless.exe" "$(OUTDIR)\modeless.bsc"


CLEAN :
	-@erase "$(INTDIR)\adderdlg.obj"
	-@erase "$(INTDIR)\adderdlg.sbr"
	-@erase "$(INTDIR)\modeldlg.obj"
	-@erase "$(INTDIR)\modeldlg.sbr"
	-@erase "$(INTDIR)\modeless.obj"
	-@erase "$(INTDIR)\modeless.pch"
	-@erase "$(INTDIR)\modeless.res"
	-@erase "$(INTDIR)\modeless.sbr"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\stdafx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\modeless.bsc"
	-@erase "$(OUTDIR)\modeless.exe"
	-@erase "$(OUTDIR)\modeless.ilk"
	-@erase "$(OUTDIR)\modeless.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\modeless.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\modeless.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\modeless.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\adderdlg.sbr" \
	"$(INTDIR)\modeldlg.sbr" \
	"$(INTDIR)\modeless.sbr" \
	"$(INTDIR)\stdafx.sbr"

"$(OUTDIR)\modeless.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\modeless.pdb" /debug /machine:I386 /out:"$(OUTDIR)\modeless.exe" 
LINK32_OBJS= \
	"$(INTDIR)\adderdlg.obj" \
	"$(INTDIR)\modeldlg.obj" \
	"$(INTDIR)\modeless.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\modeless.res"

"$(OUTDIR)\modeless.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("modeless.dep")
!INCLUDE "modeless.dep"
!ELSE 
!MESSAGE Warning: cannot find "modeless.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "modeless - Win32 Release" || "$(CFG)" == "modeless - Win32 Debug"
SOURCE=.\adderdlg.cpp

"$(INTDIR)\adderdlg.obj"	"$(INTDIR)\adderdlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\modeless.pch"


SOURCE=.\modeldlg.cpp

"$(INTDIR)\modeldlg.obj"	"$(INTDIR)\modeldlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\modeless.pch"


SOURCE=.\modeless.cpp

"$(INTDIR)\modeless.obj"	"$(INTDIR)\modeless.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\modeless.pch"


SOURCE=.\modeless.rc

"$(INTDIR)\modeless.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "modeless - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\modeless.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\modeless.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "modeless - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\modeless.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\modeless.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

