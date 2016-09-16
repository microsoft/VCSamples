# Microsoft Developer Studio Generated NMAKE File, Based on mfccalc.dsp
!IF "$(CFG)" == ""
CFG=MfcCalc - Win32 Release
!MESSAGE No configuration specified. Defaulting to MfcCalc - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "MfcCalc - Win32 Release" && "$(CFG)" != "MfcCalc - Win32 Debug" && "$(CFG)" != "MfcCalc - Win32 Unicode Release" && "$(CFG)" != "MfcCalc - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mfccalc.mak" CFG="MfcCalc - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MfcCalc - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "MfcCalc - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "MfcCalc - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "MfcCalc - Win32 Unicode Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "MfcCalc - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\mfccalc.exe"


CLEAN :
	-@erase "$(INTDIR)\calcdlg.obj"
	-@erase "$(INTDIR)\mfccalc.obj"
	-@erase "$(INTDIR)\mfccalc.pch"
	-@erase "$(INTDIR)\mfccalc.res"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\mfccalc.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/Zc:wchar_t /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfccalc.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\mfccalc.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mfccalc.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\mfccalc.pdb" /machine:I386 /out:"$(OUTDIR)\mfccalc.exe" 
LINK32_OBJS= \
	"$(INTDIR)\calcdlg.obj" \
	"$(INTDIR)\mfccalc.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\mfccalc.res"

"$(OUTDIR)\mfccalc.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MfcCalc - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\mfccalc.exe"


CLEAN :
	-@erase "$(INTDIR)\calcdlg.obj"
	-@erase "$(INTDIR)\mfccalc.obj"
	-@erase "$(INTDIR)\mfccalc.pch"
	-@erase "$(INTDIR)\mfccalc.res"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\mfccalc.exe"
	-@erase "$(OUTDIR)\mfccalc.ilk"
	-@erase "$(OUTDIR)\mfccalc.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/Zc:wchar_t /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfccalc.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\mfccalc.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mfccalc.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\mfccalc.pdb" /debug /machine:I386 /out:"$(OUTDIR)\mfccalc.exe" 
LINK32_OBJS= \
	"$(INTDIR)\calcdlg.obj" \
	"$(INTDIR)\mfccalc.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\mfccalc.res"

"$(OUTDIR)\mfccalc.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MfcCalc - Win32 Unicode Release"

OUTDIR=.\UniRelease
INTDIR=.\UniRelease
# Begin Custom Macros
OutDir=.\.\UniRelease
# End Custom Macros

ALL : "$(OUTDIR)\mfccalc.exe"


CLEAN :
	-@erase "$(INTDIR)\calcdlg.obj"
	-@erase "$(INTDIR)\mfccalc.obj"
	-@erase "$(INTDIR)\mfccalc.pch"
	-@erase "$(INTDIR)\mfccalc.res"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\mfccalc.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/Zc:wchar_t /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfccalc.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\mfccalc.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mfccalc.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\mfccalc.pdb" /machine:I386 /out:"$(OUTDIR)\mfccalc.exe" 
LINK32_OBJS= \
	"$(INTDIR)\calcdlg.obj" \
	"$(INTDIR)\mfccalc.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\mfccalc.res"

"$(OUTDIR)\mfccalc.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MfcCalc - Win32 Unicode Debug"

OUTDIR=.\UniDebug
INTDIR=.\UniDebug
# Begin Custom Macros
OutDir=.\.\UniDebug
# End Custom Macros

ALL : "$(OUTDIR)\mfccalc.exe"


CLEAN :
	-@erase "$(INTDIR)\calcdlg.obj"
	-@erase "$(INTDIR)\mfccalc.obj"
	-@erase "$(INTDIR)\mfccalc.pch"
	-@erase "$(INTDIR)\mfccalc.res"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\mfccalc.exe"
	-@erase "$(OUTDIR)\mfccalc.ilk"
	-@erase "$(OUTDIR)\mfccalc.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/Zc:wchar_t /nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfccalc.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\mfccalc.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mfccalc.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\mfccalc.pdb" /debug /machine:I386 /out:"$(OUTDIR)\mfccalc.exe" 
LINK32_OBJS= \
	"$(INTDIR)\calcdlg.obj" \
	"$(INTDIR)\mfccalc.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\mfccalc.res"

"$(OUTDIR)\mfccalc.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("mfccalc.dep")
!INCLUDE "mfccalc.dep"
!ELSE 
!MESSAGE Warning: cannot find "mfccalc.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "MfcCalc - Win32 Release" || "$(CFG)" == "MfcCalc - Win32 Debug" || "$(CFG)" == "MfcCalc - Win32 Unicode Release" || "$(CFG)" == "MfcCalc - Win32 Unicode Debug"
SOURCE=.\calcdlg.cpp

"$(INTDIR)\calcdlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mfccalc.pch"


SOURCE=.\mfccalc.cpp

"$(INTDIR)\mfccalc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mfccalc.pch"


SOURCE=.\mfccalc.rc

"$(INTDIR)\mfccalc.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "MfcCalc - Win32 Release"

CPP_SWITCHES=/Zc:wchar_t /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfccalc.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\mfccalc.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MfcCalc - Win32 Debug"

CPP_SWITCHES=/Zc:wchar_t /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfccalc.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\mfccalc.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MfcCalc - Win32 Unicode Release"

CPP_SWITCHES=/Zc:wchar_t /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfccalc.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\mfccalc.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MfcCalc - Win32 Unicode Debug"

CPP_SWITCHES=/Zc:wchar_t /nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfccalc.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\mfccalc.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

