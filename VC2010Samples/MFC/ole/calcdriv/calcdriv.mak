# Microsoft Developer Studio Generated NMAKE File, Based on calcdriv.dsp
!IF "$(CFG)" == ""
CFG=CalcDriv - Win32 Release
!MESSAGE No configuration specified. Defaulting to CalcDriv - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "CalcDriv - Win32 Release" && "$(CFG)" != "CalcDriv - Win32 Debug" && "$(CFG)" != "CalcDriv - Win32 Unicode Release" && "$(CFG)" != "CalcDriv - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "calcdriv.mak" CFG="CalcDriv - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CalcDriv - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "CalcDriv - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "CalcDriv - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "CalcDriv - Win32 Unicode Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "CalcDriv - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\calcdriv.exe"


CLEAN :
	-@erase "$(INTDIR)\calcdriv.obj"
	-@erase "$(INTDIR)\calcdriv.pch"
	-@erase "$(INTDIR)\Calcdriv.res"
	-@erase "$(INTDIR)\Calctype.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\calcdriv.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/Zc:wchar_t /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\calcdriv.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Calcdriv.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\calcdriv.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/subsystem:windows /incremental:no /pdb:"$(OUTDIR)\calcdriv.pdb" /machine:I386 /out:"$(OUTDIR)\calcdriv.exe" 
LINK32_OBJS= \
	"$(INTDIR)\calcdriv.obj" \
	"$(INTDIR)\Calctype.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Calcdriv.res"

"$(OUTDIR)\calcdriv.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CalcDriv - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\calcdriv.exe"


CLEAN :
	-@erase "$(INTDIR)\calcdriv.obj"
	-@erase "$(INTDIR)\calcdriv.pch"
	-@erase "$(INTDIR)\Calcdriv.res"
	-@erase "$(INTDIR)\Calctype.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\calcdriv.exe"
	-@erase "$(OUTDIR)\calcdriv.ilk"
	-@erase "$(OUTDIR)\calcdriv.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/Zc:wchar_t /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\calcdriv.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Calcdriv.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\calcdriv.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\calcdriv.pdb" /debug /machine:I386 /out:"$(OUTDIR)\calcdriv.exe" 
LINK32_OBJS= \
	"$(INTDIR)\calcdriv.obj" \
	"$(INTDIR)\Calctype.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Calcdriv.res"

"$(OUTDIR)\calcdriv.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CalcDriv - Win32 Unicode Release"

OUTDIR=.\UniRelease
INTDIR=.\UniRelease
# Begin Custom Macros
OutDir=.\.\UniRelease
# End Custom Macros

ALL : "$(OUTDIR)\calcdriv.exe"


CLEAN :
	-@erase "$(INTDIR)\calcdriv.obj"
	-@erase "$(INTDIR)\calcdriv.pch"
	-@erase "$(INTDIR)\Calcdriv.res"
	-@erase "$(INTDIR)\Calctype.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\calcdriv.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/Zc:wchar_t /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\calcdriv.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Calcdriv.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\calcdriv.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\calcdriv.pdb" /machine:I386 /out:"$(OUTDIR)\calcdriv.exe" 
LINK32_OBJS= \
	"$(INTDIR)\calcdriv.obj" \
	"$(INTDIR)\Calctype.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Calcdriv.res"

"$(OUTDIR)\calcdriv.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CalcDriv - Win32 Unicode Debug"

OUTDIR=.\UniDebug
INTDIR=.\UniDebug
# Begin Custom Macros
OutDir=.\.\UniDebug
# End Custom Macros

ALL : "$(OUTDIR)\calcdriv.exe"


CLEAN :
	-@erase "$(INTDIR)\calcdriv.obj"
	-@erase "$(INTDIR)\calcdriv.pch"
	-@erase "$(INTDIR)\Calcdriv.res"
	-@erase "$(INTDIR)\Calctype.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\calcdriv.exe"
	-@erase "$(OUTDIR)\calcdriv.ilk"
	-@erase "$(OUTDIR)\calcdriv.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/Zc:wchar_t /nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\calcdriv.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Calcdriv.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\calcdriv.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\calcdriv.pdb" /debug /machine:I386 /out:"$(OUTDIR)\calcdriv.exe" 
LINK32_OBJS= \
	"$(INTDIR)\calcdriv.obj" \
	"$(INTDIR)\Calctype.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Calcdriv.res"

"$(OUTDIR)\calcdriv.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("calcdriv.dep")
!INCLUDE "calcdriv.dep"
!ELSE 
!MESSAGE Warning: cannot find "calcdriv.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "CalcDriv - Win32 Release" || "$(CFG)" == "CalcDriv - Win32 Debug" || "$(CFG)" == "CalcDriv - Win32 Unicode Release" || "$(CFG)" == "CalcDriv - Win32 Unicode Debug"
SOURCE=.\calcdriv.cpp

"$(INTDIR)\calcdriv.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\calcdriv.pch"


SOURCE=.\Calcdriv.rc

"$(INTDIR)\Calcdriv.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\Calctype.cpp

"$(INTDIR)\Calctype.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\calcdriv.pch"


SOURCE=.\Stdafx.cpp

!IF  "$(CFG)" == "CalcDriv - Win32 Release"

CPP_SWITCHES=/Zc:wchar_t /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\calcdriv.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\calcdriv.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CalcDriv - Win32 Debug"

CPP_SWITCHES=/Zc:wchar_t /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\calcdriv.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\calcdriv.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CalcDriv - Win32 Unicode Release"

CPP_SWITCHES=/Zc:wchar_t /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\calcdriv.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\calcdriv.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CalcDriv - Win32 Unicode Debug"

CPP_SWITCHES=/Zc:wchar_t /nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\calcdriv.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\calcdriv.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

