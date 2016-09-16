# Microsoft Developer Studio Generated NMAKE File, Based on dlgtemp.dsp
!IF "$(CFG)" == ""
CFG=dlgtemp - Win32 Release
!MESSAGE No configuration specified. Defaulting to dlgtemp - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "dlgtemp - Win32 Release" && "$(CFG)" != "dlgtemp - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "dlgtemp.mak" CFG="dlgtemp - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "dlgtemp - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "dlgtemp - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "dlgtemp - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\dlgtemp.exe"


CLEAN :
	-@erase "$(INTDIR)\dlgtemp.obj"
	-@erase "$(INTDIR)\dlgtemp.pch"
	-@erase "$(INTDIR)\dlgtemp.res"
	-@erase "$(INTDIR)\itemtemp.obj"
	-@erase "$(INTDIR)\setupdlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\dlgtemp.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\dlgtemp.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\dlgtemp.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\dlgtemp.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\dlgtemp.pdb" /machine:I386 /out:"$(OUTDIR)\dlgtemp.exe" 
LINK32_OBJS= \
	"$(INTDIR)\dlgtemp.obj" \
	"$(INTDIR)\itemtemp.obj" \
	"$(INTDIR)\setupdlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\dlgtemp.res"

"$(OUTDIR)\dlgtemp.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "dlgtemp - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\dlgtemp.exe" "$(OUTDIR)\dlgtemp.bsc"


CLEAN :
	-@erase "$(INTDIR)\dlgtemp.obj"
	-@erase "$(INTDIR)\dlgtemp.pch"
	-@erase "$(INTDIR)\dlgtemp.res"
	-@erase "$(INTDIR)\dlgtemp.sbr"
	-@erase "$(INTDIR)\itemtemp.obj"
	-@erase "$(INTDIR)\itemtemp.sbr"
	-@erase "$(INTDIR)\setupdlg.obj"
	-@erase "$(INTDIR)\setupdlg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\dlgtemp.bsc"
	-@erase "$(OUTDIR)\dlgtemp.exe"
	-@erase "$(OUTDIR)\dlgtemp.ilk"
	-@erase "$(OUTDIR)\dlgtemp.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\dlgtemp.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\dlgtemp.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\dlgtemp.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\dlgtemp.sbr" \
	"$(INTDIR)\itemtemp.sbr" \
	"$(INTDIR)\setupdlg.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\dlgtemp.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\dlgtemp.pdb" /debug /machine:I386 /out:"$(OUTDIR)\dlgtemp.exe" 
LINK32_OBJS= \
	"$(INTDIR)\dlgtemp.obj" \
	"$(INTDIR)\itemtemp.obj" \
	"$(INTDIR)\setupdlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\dlgtemp.res"

"$(OUTDIR)\dlgtemp.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("dlgtemp.dep")
!INCLUDE "dlgtemp.dep"
!ELSE 
!MESSAGE Warning: cannot find "dlgtemp.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "dlgtemp - Win32 Release" || "$(CFG)" == "dlgtemp - Win32 Debug"
SOURCE=.\dlgtemp.cpp

!IF  "$(CFG)" == "dlgtemp - Win32 Release"


"$(INTDIR)\dlgtemp.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\dlgtemp.pch"


!ELSEIF  "$(CFG)" == "dlgtemp - Win32 Debug"


"$(INTDIR)\dlgtemp.obj"	"$(INTDIR)\dlgtemp.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\dlgtemp.pch"


!ENDIF 

SOURCE=.\dlgtemp.rc

"$(INTDIR)\dlgtemp.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\itemtemp.cpp

!IF  "$(CFG)" == "dlgtemp - Win32 Release"


"$(INTDIR)\itemtemp.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\dlgtemp.pch"


!ELSEIF  "$(CFG)" == "dlgtemp - Win32 Debug"


"$(INTDIR)\itemtemp.obj"	"$(INTDIR)\itemtemp.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\dlgtemp.pch"


!ENDIF 

SOURCE=.\setupdlg.cpp

!IF  "$(CFG)" == "dlgtemp - Win32 Release"


"$(INTDIR)\setupdlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\dlgtemp.pch"


!ELSEIF  "$(CFG)" == "dlgtemp - Win32 Debug"


"$(INTDIR)\setupdlg.obj"	"$(INTDIR)\setupdlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\dlgtemp.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "dlgtemp - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\dlgtemp.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\dlgtemp.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "dlgtemp - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\dlgtemp.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\dlgtemp.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

