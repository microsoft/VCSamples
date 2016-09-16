# Microsoft Developer Studio Generated NMAKE File, Based on guidgen.dsp
!IF "$(CFG)" == ""
CFG=GuidGen - Win32 Release
!MESSAGE No configuration specified. Defaulting to GuidGen - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "GuidGen - Win32 Release" && "$(CFG)" != "GuidGen - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "guidgen.mak" CFG="GuidGen - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "GuidGen - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "GuidGen - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "GuidGen - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\guidgen.exe" "$(OUTDIR)\guidgen.bsc"


CLEAN :
	-@erase "$(INTDIR)\Guidgdlg.obj"
	-@erase "$(INTDIR)\Guidgdlg.sbr"
	-@erase "$(INTDIR)\Guidgen.obj"
	-@erase "$(INTDIR)\guidgen.pch"
	-@erase "$(INTDIR)\Guidgen.res"
	-@erase "$(INTDIR)\Guidgen.sbr"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\Stdafx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\guidgen.bsc"
	-@erase "$(OUTDIR)\guidgen.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\guidgen.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Guidgen.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\guidgen.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Guidgdlg.sbr" \
	"$(INTDIR)\Guidgen.sbr" \
	"$(INTDIR)\Stdafx.sbr"

"$(OUTDIR)\guidgen.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=rpcrt4.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\guidgen.pdb" /machine:I386 /out:"$(OUTDIR)\guidgen.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Guidgdlg.obj" \
	"$(INTDIR)\Guidgen.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Guidgen.res"

"$(OUTDIR)\guidgen.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "GuidGen - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\guidgen.exe" "$(OUTDIR)\guidgen.bsc"


CLEAN :
	-@erase "$(INTDIR)\Guidgdlg.obj"
	-@erase "$(INTDIR)\Guidgdlg.sbr"
	-@erase "$(INTDIR)\Guidgen.obj"
	-@erase "$(INTDIR)\guidgen.pch"
	-@erase "$(INTDIR)\Guidgen.res"
	-@erase "$(INTDIR)\Guidgen.sbr"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\Stdafx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\guidgen.bsc"
	-@erase "$(OUTDIR)\guidgen.exe"
	-@erase "$(OUTDIR)\guidgen.ilk"
	-@erase "$(OUTDIR)\guidgen.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\guidgen.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Guidgen.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\guidgen.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Guidgdlg.sbr" \
	"$(INTDIR)\Guidgen.sbr" \
	"$(INTDIR)\Stdafx.sbr"

"$(OUTDIR)\guidgen.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\guidgen.pdb" /debug /machine:I386 /out:"$(OUTDIR)\guidgen.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Guidgdlg.obj" \
	"$(INTDIR)\Guidgen.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Guidgen.res"

"$(OUTDIR)\guidgen.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("guidgen.dep")
!INCLUDE "guidgen.dep"
!ELSE 
!MESSAGE Warning: cannot find "guidgen.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "GuidGen - Win32 Release" || "$(CFG)" == "GuidGen - Win32 Debug"
SOURCE=.\Guidgdlg.cpp

"$(INTDIR)\Guidgdlg.obj"	"$(INTDIR)\Guidgdlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\guidgen.pch"


SOURCE=.\Guidgen.cpp

"$(INTDIR)\Guidgen.obj"	"$(INTDIR)\Guidgen.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\guidgen.pch"


SOURCE=.\Guidgen.rc

"$(INTDIR)\Guidgen.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\Stdafx.cpp

!IF  "$(CFG)" == "GuidGen - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\guidgen.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\Stdafx.sbr"	"$(INTDIR)\guidgen.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "GuidGen - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\guidgen.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\Stdafx.sbr"	"$(INTDIR)\guidgen.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

