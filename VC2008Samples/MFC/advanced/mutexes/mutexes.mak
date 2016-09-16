# Microsoft Developer Studio Generated NMAKE File, Based on mutexes.dsp
!IF "$(CFG)" == ""
CFG=mutexes - Win32 Release
!MESSAGE No configuration specified. Defaulting to mutexes - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "mutexes - Win32 Release" && "$(CFG)" != "mutexes - Win32 Debug" && "$(CFG)" != "mutexes - Win32 Unicode Release" && "$(CFG)" != "mutexes - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mutexes.mak" CFG="mutexes - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mutexes - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "mutexes - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "mutexes - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "mutexes - Win32 Unicode Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "mutexes - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\mutexes.exe" "$(OUTDIR)\mutexes.bsc"


CLEAN :
	-@erase "$(INTDIR)\MUTEXDLG.OBJ"
	-@erase "$(INTDIR)\MUTEXDLG.SBR"
	-@erase "$(INTDIR)\MUTEXES.OBJ"
	-@erase "$(INTDIR)\mutexes.pch"
	-@erase "$(INTDIR)\mutexes.res"
	-@erase "$(INTDIR)\MUTEXES.SBR"
	-@erase "$(INTDIR)\STDAFX.OBJ"
	-@erase "$(INTDIR)\STDAFX.SBR"
	-@erase "$(INTDIR)\THREADS.OBJ"
	-@erase "$(INTDIR)\THREADS.SBR"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\mutexes.bsc"
	-@erase "$(OUTDIR)\mutexes.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\mutexes.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\mutexes.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mutexes.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\MUTEXDLG.SBR" \
	"$(INTDIR)\MUTEXES.SBR" \
	"$(INTDIR)\STDAFX.SBR" \
	"$(INTDIR)\THREADS.SBR"

"$(OUTDIR)\mutexes.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\mutexes.pdb" /machine:I386 /out:"$(OUTDIR)\mutexes.exe" 
LINK32_OBJS= \
	"$(INTDIR)\MUTEXDLG.OBJ" \
	"$(INTDIR)\MUTEXES.OBJ" \
	"$(INTDIR)\STDAFX.OBJ" \
	"$(INTDIR)\THREADS.OBJ" \
	"$(INTDIR)\mutexes.res"

"$(OUTDIR)\mutexes.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "mutexes - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\mutexes.exe" "$(OUTDIR)\mutexes.bsc"


CLEAN :
	-@erase "$(INTDIR)\MUTEXDLG.OBJ"
	-@erase "$(INTDIR)\MUTEXDLG.SBR"
	-@erase "$(INTDIR)\MUTEXES.OBJ"
	-@erase "$(INTDIR)\mutexes.pch"
	-@erase "$(INTDIR)\mutexes.res"
	-@erase "$(INTDIR)\MUTEXES.SBR"
	-@erase "$(INTDIR)\STDAFX.OBJ"
	-@erase "$(INTDIR)\STDAFX.SBR"
	-@erase "$(INTDIR)\THREADS.OBJ"
	-@erase "$(INTDIR)\THREADS.SBR"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\mutexes.bsc"
	-@erase "$(OUTDIR)\mutexes.exe"
	-@erase "$(OUTDIR)\mutexes.ilk"
	-@erase "$(OUTDIR)\mutexes.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\mutexes.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\mutexes.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mutexes.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\MUTEXDLG.SBR" \
	"$(INTDIR)\MUTEXES.SBR" \
	"$(INTDIR)\STDAFX.SBR" \
	"$(INTDIR)\THREADS.SBR"

"$(OUTDIR)\mutexes.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\mutexes.pdb" /debug /machine:I386 /out:"$(OUTDIR)\mutexes.exe" 
LINK32_OBJS= \
	"$(INTDIR)\MUTEXDLG.OBJ" \
	"$(INTDIR)\MUTEXES.OBJ" \
	"$(INTDIR)\STDAFX.OBJ" \
	"$(INTDIR)\THREADS.OBJ" \
	"$(INTDIR)\mutexes.res"

"$(OUTDIR)\mutexes.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "mutexes - Win32 Unicode Release"

OUTDIR=.\ReleaseU
INTDIR=.\ReleaseU
# Begin Custom Macros
OutDir=.\ReleaseU
# End Custom Macros

ALL : "$(OUTDIR)\mutexes.exe" "$(OUTDIR)\mutexes.bsc"


CLEAN :
	-@erase "$(INTDIR)\MUTEXDLG.OBJ"
	-@erase "$(INTDIR)\MUTEXDLG.SBR"
	-@erase "$(INTDIR)\MUTEXES.OBJ"
	-@erase "$(INTDIR)\mutexes.pch"
	-@erase "$(INTDIR)\mutexes.res"
	-@erase "$(INTDIR)\MUTEXES.SBR"
	-@erase "$(INTDIR)\STDAFX.OBJ"
	-@erase "$(INTDIR)\STDAFX.SBR"
	-@erase "$(INTDIR)\THREADS.OBJ"
	-@erase "$(INTDIR)\THREADS.SBR"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\mutexes.bsc"
	-@erase "$(OUTDIR)\mutexes.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\mutexes.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\mutexes.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mutexes.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\MUTEXDLG.SBR" \
	"$(INTDIR)\MUTEXES.SBR" \
	"$(INTDIR)\STDAFX.SBR" \
	"$(INTDIR)\THREADS.SBR"

"$(OUTDIR)\mutexes.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\mutexes.pdb" /machine:I386 /out:"$(OUTDIR)\mutexes.exe" 
LINK32_OBJS= \
	"$(INTDIR)\MUTEXDLG.OBJ" \
	"$(INTDIR)\MUTEXES.OBJ" \
	"$(INTDIR)\STDAFX.OBJ" \
	"$(INTDIR)\THREADS.OBJ" \
	"$(INTDIR)\mutexes.res"

"$(OUTDIR)\mutexes.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "mutexes - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\DebugU
# End Custom Macros

ALL : "$(OUTDIR)\mutexes.exe" "$(OUTDIR)\mutexes.bsc"


CLEAN :
	-@erase "$(INTDIR)\MUTEXDLG.OBJ"
	-@erase "$(INTDIR)\MUTEXDLG.SBR"
	-@erase "$(INTDIR)\MUTEXES.OBJ"
	-@erase "$(INTDIR)\mutexes.pch"
	-@erase "$(INTDIR)\mutexes.res"
	-@erase "$(INTDIR)\MUTEXES.SBR"
	-@erase "$(INTDIR)\STDAFX.OBJ"
	-@erase "$(INTDIR)\STDAFX.SBR"
	-@erase "$(INTDIR)\THREADS.OBJ"
	-@erase "$(INTDIR)\THREADS.SBR"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\mutexes.bsc"
	-@erase "$(OUTDIR)\mutexes.exe"
	-@erase "$(OUTDIR)\mutexes.ilk"
	-@erase "$(OUTDIR)\mutexes.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\mutexes.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\mutexes.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mutexes.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\MUTEXDLG.SBR" \
	"$(INTDIR)\MUTEXES.SBR" \
	"$(INTDIR)\STDAFX.SBR" \
	"$(INTDIR)\THREADS.SBR"

"$(OUTDIR)\mutexes.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\mutexes.pdb" /debug /machine:I386 /out:"$(OUTDIR)\mutexes.exe" 
LINK32_OBJS= \
	"$(INTDIR)\MUTEXDLG.OBJ" \
	"$(INTDIR)\MUTEXES.OBJ" \
	"$(INTDIR)\STDAFX.OBJ" \
	"$(INTDIR)\THREADS.OBJ" \
	"$(INTDIR)\mutexes.res"

"$(OUTDIR)\mutexes.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("mutexes.dep")
!INCLUDE "mutexes.dep"
!ELSE 
!MESSAGE Warning: cannot find "mutexes.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "mutexes - Win32 Release" || "$(CFG)" == "mutexes - Win32 Debug" || "$(CFG)" == "mutexes - Win32 Unicode Release" || "$(CFG)" == "mutexes - Win32 Unicode Debug"
SOURCE=.\MUTEXDLG.CPP

"$(INTDIR)\MUTEXDLG.OBJ"	"$(INTDIR)\MUTEXDLG.SBR" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mutexes.pch"


SOURCE=.\MUTEXES.CPP

"$(INTDIR)\MUTEXES.OBJ"	"$(INTDIR)\MUTEXES.SBR" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mutexes.pch"


SOURCE=.\mutexes.rc

"$(INTDIR)\mutexes.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\STDAFX.CPP

!IF  "$(CFG)" == "mutexes - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\mutexes.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\STDAFX.OBJ"	"$(INTDIR)\STDAFX.SBR"	"$(INTDIR)\mutexes.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "mutexes - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\mutexes.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\STDAFX.OBJ"	"$(INTDIR)\STDAFX.SBR"	"$(INTDIR)\mutexes.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "mutexes - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\mutexes.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\STDAFX.OBJ"	"$(INTDIR)\STDAFX.SBR"	"$(INTDIR)\mutexes.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "mutexes - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\mutexes.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\STDAFX.OBJ"	"$(INTDIR)\STDAFX.SBR"	"$(INTDIR)\mutexes.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\THREADS.CPP

"$(INTDIR)\THREADS.OBJ"	"$(INTDIR)\THREADS.SBR" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mutexes.pch"



!ENDIF 

