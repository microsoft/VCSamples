# Microsoft Developer Studio Generated NMAKE File, Based on autodriv.dsp
!IF "$(CFG)" == ""
CFG=autodriv - Win32 (80x86) Debug
!MESSAGE No configuration specified. Defaulting to autodriv - Win32 (80x86) Debug.
!ENDIF 

!IF "$(CFG)" != "autodriv - Win32 (80x86) Debug" && "$(CFG)" != "autodriv - Win32 (80x86) Release" && "$(CFG)" != "autodriv - Win32 (80x86) Unicode Debug" && "$(CFG)" != "autodriv - Win32 (80x86) Unicode Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "autodriv.mak" CFG="autodriv - Win32 (80x86) Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "autodriv - Win32 (80x86) Debug" (based on "Win32 (x86) Application")
!MESSAGE "autodriv - Win32 (80x86) Release" (based on "Win32 (x86) Application")
!MESSAGE "autodriv - Win32 (80x86) Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE "autodriv - Win32 (80x86) Unicode Release" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "autodriv - Win32 (80x86) Debug"

OUTDIR=.\WinDebug
INTDIR=.\WinDebug
# Begin Custom Macros
OutDir=.\.\WinDebug
# End Custom Macros

ALL : "$(OUTDIR)\autodriv.exe" "$(OUTDIR)\autodriv.bsc"


CLEAN :
	-@erase "$(INTDIR)\autoclik.obj"
	-@erase "$(INTDIR)\autoclik.sbr"
	-@erase "$(INTDIR)\autoddlg.obj"
	-@erase "$(INTDIR)\autoddlg.sbr"
	-@erase "$(INTDIR)\autodriv.obj"
	-@erase "$(INTDIR)\autodriv.pch"
	-@erase "$(INTDIR)\autodriv.res"
	-@erase "$(INTDIR)\autodriv.sbr"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\stdafx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\autodriv.bsc"
	-@erase "$(OUTDIR)\autodriv.exe"
	-@erase "$(OUTDIR)\autodriv.ilk"
	-@erase "$(OUTDIR)\autodriv.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\autodriv.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\autodriv.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\autodriv.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\autoclik.sbr" \
	"$(INTDIR)\autoddlg.sbr" \
	"$(INTDIR)\autodriv.sbr" \
	"$(INTDIR)\stdafx.sbr"

"$(OUTDIR)\autodriv.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\autodriv.pdb" /debug /machine:I386 /out:"$(OUTDIR)\autodriv.exe" 
LINK32_OBJS= \
	"$(INTDIR)\autoclik.obj" \
	"$(INTDIR)\autoddlg.obj" \
	"$(INTDIR)\autodriv.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\autodriv.res"

"$(OUTDIR)\autodriv.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "autodriv - Win32 (80x86) Release"

OUTDIR=.\WinRel
INTDIR=.\WinRel
# Begin Custom Macros
OutDir=.\.\WinRel
# End Custom Macros

ALL : "$(OUTDIR)\autodriv.exe" "$(OUTDIR)\autodriv.bsc"


CLEAN :
	-@erase "$(INTDIR)\autoclik.obj"
	-@erase "$(INTDIR)\autoclik.sbr"
	-@erase "$(INTDIR)\autoddlg.obj"
	-@erase "$(INTDIR)\autoddlg.sbr"
	-@erase "$(INTDIR)\autodriv.obj"
	-@erase "$(INTDIR)\autodriv.pch"
	-@erase "$(INTDIR)\autodriv.res"
	-@erase "$(INTDIR)\autodriv.sbr"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\stdafx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\autodriv.bsc"
	-@erase "$(OUTDIR)\autodriv.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\autodriv.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\autodriv.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\autodriv.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\autoclik.sbr" \
	"$(INTDIR)\autoddlg.sbr" \
	"$(INTDIR)\autodriv.sbr" \
	"$(INTDIR)\stdafx.sbr"

"$(OUTDIR)\autodriv.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\autodriv.pdb" /machine:I386 /out:"$(OUTDIR)\autodriv.exe" 
LINK32_OBJS= \
	"$(INTDIR)\autoclik.obj" \
	"$(INTDIR)\autoddlg.obj" \
	"$(INTDIR)\autodriv.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\autodriv.res"

"$(OUTDIR)\autodriv.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "autodriv - Win32 (80x86) Unicode Debug"

OUTDIR=.\UniDebug
INTDIR=.\UniDebug
# Begin Custom Macros
OutDir=.\.\UniDebug
# End Custom Macros

ALL : "$(OUTDIR)\autodriv.exe" "$(OUTDIR)\autodriv.bsc"


CLEAN :
	-@erase "$(INTDIR)\autoclik.obj"
	-@erase "$(INTDIR)\autoclik.sbr"
	-@erase "$(INTDIR)\autoddlg.obj"
	-@erase "$(INTDIR)\autoddlg.sbr"
	-@erase "$(INTDIR)\autodriv.obj"
	-@erase "$(INTDIR)\autodriv.pch"
	-@erase "$(INTDIR)\autodriv.res"
	-@erase "$(INTDIR)\autodriv.sbr"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\stdafx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\autodriv.bsc"
	-@erase "$(OUTDIR)\autodriv.exe"
	-@erase "$(OUTDIR)\autodriv.ilk"
	-@erase "$(OUTDIR)\autodriv.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\autodriv.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\autodriv.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\autodriv.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\autoclik.sbr" \
	"$(INTDIR)\autoddlg.sbr" \
	"$(INTDIR)\autodriv.sbr" \
	"$(INTDIR)\stdafx.sbr"

"$(OUTDIR)\autodriv.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\autodriv.pdb" /debug /machine:I386 /out:"$(OUTDIR)\autodriv.exe" 
LINK32_OBJS= \
	"$(INTDIR)\autoclik.obj" \
	"$(INTDIR)\autoddlg.obj" \
	"$(INTDIR)\autodriv.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\autodriv.res"

"$(OUTDIR)\autodriv.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "autodriv - Win32 (80x86) Unicode Release"

OUTDIR=.\UniRel
INTDIR=.\UniRel
# Begin Custom Macros
OutDir=.\.\UniRel
# End Custom Macros

ALL : "$(OUTDIR)\autodriv.exe" "$(OUTDIR)\autodriv.bsc"


CLEAN :
	-@erase "$(INTDIR)\autoclik.obj"
	-@erase "$(INTDIR)\autoclik.sbr"
	-@erase "$(INTDIR)\autoddlg.obj"
	-@erase "$(INTDIR)\autoddlg.sbr"
	-@erase "$(INTDIR)\autodriv.obj"
	-@erase "$(INTDIR)\autodriv.pch"
	-@erase "$(INTDIR)\autodriv.res"
	-@erase "$(INTDIR)\autodriv.sbr"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\stdafx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\autodriv.bsc"
	-@erase "$(OUTDIR)\autodriv.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\autodriv.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\autodriv.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\autodriv.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\autoclik.sbr" \
	"$(INTDIR)\autoddlg.sbr" \
	"$(INTDIR)\autodriv.sbr" \
	"$(INTDIR)\stdafx.sbr"

"$(OUTDIR)\autodriv.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\autodriv.pdb" /machine:I386 /out:"$(OUTDIR)\autodriv.exe" 
LINK32_OBJS= \
	"$(INTDIR)\autoclik.obj" \
	"$(INTDIR)\autoddlg.obj" \
	"$(INTDIR)\autodriv.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\autodriv.res"

"$(OUTDIR)\autodriv.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

MTL_PROJ=/mktyplib203 

!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("autodriv.dep")
!INCLUDE "autodriv.dep"
!ELSE 
!MESSAGE Warning: cannot find "autodriv.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "autodriv - Win32 (80x86) Debug" || "$(CFG)" == "autodriv - Win32 (80x86) Release" || "$(CFG)" == "autodriv - Win32 (80x86) Unicode Debug" || "$(CFG)" == "autodriv - Win32 (80x86) Unicode Release"
SOURCE=.\autoclik.cpp

"$(INTDIR)\autoclik.obj"	"$(INTDIR)\autoclik.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\autodriv.pch"


SOURCE=.\autoddlg.cpp

"$(INTDIR)\autoddlg.obj"	"$(INTDIR)\autoddlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\autodriv.pch"


SOURCE=.\autodriv.cpp

"$(INTDIR)\autodriv.obj"	"$(INTDIR)\autodriv.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\autodriv.pch"


SOURCE=.\autodriv.rc

"$(INTDIR)\autodriv.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "autodriv - Win32 (80x86) Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\autodriv.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\autodriv.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "autodriv - Win32 (80x86) Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\autodriv.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\autodriv.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "autodriv - Win32 (80x86) Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\autodriv.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\autodriv.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "autodriv - Win32 (80x86) Unicode Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\autodriv.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\autodriv.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

