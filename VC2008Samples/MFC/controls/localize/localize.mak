# Microsoft Developer Studio Generated NMAKE File, Based on localize.dsp
!IF "$(CFG)" == ""
CFG=Localize - Win32 Release
!MESSAGE No configuration specified. Defaulting to Localize - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Localize - Win32 Release" && "$(CFG)" != "Localize - Win32 Debug" && "$(CFG)" != "Localize - Win32 Unicode Release" && "$(CFG)" != "Localize - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "localize.mak" CFG="Localize - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Localize - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Localize - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Localize - Win32 Unicode Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Localize - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "Localize - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\Localize.ocx"


CLEAN :
	-@erase "$(INTDIR)\localctl.obj"
	-@erase "$(INTDIR)\localize.obj"
	-@erase "$(INTDIR)\localize.pch"
	-@erase "$(INTDIR)\localize.res"
	-@erase "$(INTDIR)\localize.tlb"
	-@erase "$(INTDIR)\localppg.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\Localize.exp"
	-@erase "$(OUTDIR)\Localize.lib"
	-@erase "$(OUTDIR)\Localize.ocx"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W4 /GX /Ox /D "NDEBUG" /D "_WINDOWS" /D "_AFXCTL" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\localize.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /D "_WIN32" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\localize.res" /d "NDEBUG" /d "_WIN32" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\localize.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\Localize.pdb" /machine:IX86 /def:".\localize.def" /out:"$(OUTDIR)\Localize.ocx" /implib:"$(OUTDIR)\Localize.lib" 
DEF_FILE= \
	".\localize.def"
LINK32_OBJS= \
	"$(INTDIR)\localctl.obj" \
	"$(INTDIR)\localize.obj" \
	"$(INTDIR)\localppg.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\localize.res"

"$(OUTDIR)\Localize.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Localize - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Localize.ocx"


CLEAN :
	-@erase "$(INTDIR)\localctl.obj"
	-@erase "$(INTDIR)\localize.obj"
	-@erase "$(INTDIR)\localize.pch"
	-@erase "$(INTDIR)\localize.res"
	-@erase "$(INTDIR)\localize.tlb"
	-@erase "$(INTDIR)\localppg.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Localize.exp"
	-@erase "$(OUTDIR)\Localize.ilk"
	-@erase "$(OUTDIR)\Localize.lib"
	-@erase "$(OUTDIR)\Localize.ocx"
	-@erase "$(OUTDIR)\Localize.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W4 /Gm /GX /ZI /Od /D "_DEBUG" /D "_WINDOWS" /D "_AFXCTL" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\localize.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /D "_WIN32" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\localize.res" /d "_DEBUG" /d "_WIN32" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\localize.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\Localize.pdb" /debug /machine:IX86 /def:".\localize.def" /out:"$(OUTDIR)\Localize.ocx" /implib:"$(OUTDIR)\Localize.lib" 
DEF_FILE= \
	".\localize.def"
LINK32_OBJS= \
	"$(INTDIR)\localctl.obj" \
	"$(INTDIR)\localize.obj" \
	"$(INTDIR)\localppg.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\localize.res"

"$(OUTDIR)\Localize.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Localize - Win32 Unicode Release"

OUTDIR=.\UniRelease
INTDIR=.\UniRelease
# Begin Custom Macros
OutDir=.\.\UniRelease
# End Custom Macros

ALL : "$(OUTDIR)\Localize.ocx"


CLEAN :
	-@erase "$(INTDIR)\localctl.obj"
	-@erase "$(INTDIR)\localize.obj"
	-@erase "$(INTDIR)\localize.pch"
	-@erase "$(INTDIR)\localize.res"
	-@erase "$(INTDIR)\localize.tlb"
	-@erase "$(INTDIR)\localppg.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\Localize.exp"
	-@erase "$(OUTDIR)\Localize.lib"
	-@erase "$(OUTDIR)\Localize.ocx"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W4 /GX /Ox /D "NDEBUG" /D "_UNICODE" /D "_WINDOWS" /D "_AFXCTL" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\localize.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /D "_UNICODE" /D "_WIN32" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\localize.res" /d "NDEBUG" /d "_WIN32" /d "_UNICODE" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\localize.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\Localize.pdb" /machine:IX86 /def:".\localize.def" /out:"$(OUTDIR)\Localize.ocx" /implib:"$(OUTDIR)\Localize.lib" 
DEF_FILE= \
	".\localize.def"
LINK32_OBJS= \
	"$(INTDIR)\localctl.obj" \
	"$(INTDIR)\localize.obj" \
	"$(INTDIR)\localppg.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\localize.res"

"$(OUTDIR)\Localize.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Localize - Win32 Unicode Debug"

OUTDIR=.\UniDebug
INTDIR=.\UniDebug
# Begin Custom Macros
OutDir=.\.\UniDebug
# End Custom Macros

ALL : "$(OUTDIR)\Localize.ocx"


CLEAN :
	-@erase "$(INTDIR)\localctl.obj"
	-@erase "$(INTDIR)\localize.obj"
	-@erase "$(INTDIR)\localize.pch"
	-@erase "$(INTDIR)\localize.res"
	-@erase "$(INTDIR)\localize.tlb"
	-@erase "$(INTDIR)\localppg.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Localize.exp"
	-@erase "$(OUTDIR)\Localize.ilk"
	-@erase "$(OUTDIR)\Localize.lib"
	-@erase "$(OUTDIR)\Localize.ocx"
	-@erase "$(OUTDIR)\Localize.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W4 /Gm /GX /ZI /Od /D "_DEBUG" /D "_UNICODE" /D "_WINDOWS" /D "_AFXCTL" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\localize.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /D "_UNICODE" /D "_WIN32" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\localize.res" /d "_DEBUG" /d "_WIN32" /d "_UNICODE" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\localize.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\Localize.pdb" /debug /machine:IX86 /def:".\localize.def" /out:"$(OUTDIR)\Localize.ocx" /implib:"$(OUTDIR)\Localize.lib" 
DEF_FILE= \
	".\localize.def"
LINK32_OBJS= \
	"$(INTDIR)\localctl.obj" \
	"$(INTDIR)\localize.obj" \
	"$(INTDIR)\localppg.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\localize.res"

"$(OUTDIR)\Localize.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("localize.dep")
!INCLUDE "localize.dep"
!ELSE 
!MESSAGE Warning: cannot find "localize.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Localize - Win32 Release" || "$(CFG)" == "Localize - Win32 Debug" || "$(CFG)" == "Localize - Win32 Unicode Release" || "$(CFG)" == "Localize - Win32 Unicode Debug"
SOURCE=.\localctl.cpp

"$(INTDIR)\localctl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\localize.pch"


SOURCE=.\localize.cpp

"$(INTDIR)\localize.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\localize.pch"


SOURCE=.\localize.odl

!IF  "$(CFG)" == "Localize - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /D "_WIN32" /tlb "$(OUTDIR)\localize.tlb" /mktyplib203 /win32 

"$(OUTDIR)\localize.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Localize - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /D "_WIN32" /tlb "$(OUTDIR)\localize.tlb" /mktyplib203 /win32 

"$(OUTDIR)\localize.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Localize - Win32 Unicode Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /D "_UNICODE" /D "_WIN32" /tlb "$(OUTDIR)\localize.tlb" /mktyplib203 /win32 

"$(OUTDIR)\localize.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Localize - Win32 Unicode Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /D "_UNICODE" /D "_WIN32" /tlb "$(OUTDIR)\localize.tlb" /mktyplib203 /win32 

"$(OUTDIR)\localize.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\localize.rc

!IF  "$(CFG)" == "Localize - Win32 Release"


"$(INTDIR)\localize.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\localize.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\localize.res" /i ".\Release" /d "NDEBUG" /d "_WIN32" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "Localize - Win32 Debug"


"$(INTDIR)\localize.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\localize.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\localize.res" /i ".\Debug" /d "_DEBUG" /d "_WIN32" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "Localize - Win32 Unicode Release"


"$(INTDIR)\localize.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\localize.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\localize.res" /i ".\UniRelease" /d "NDEBUG" /d "_WIN32" /d "_UNICODE" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "Localize - Win32 Unicode Debug"


"$(INTDIR)\localize.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\localize.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\localize.res" /i ".\UniDebug" /d "_DEBUG" /d "_WIN32" /d "_UNICODE" /d "_AFXDLL" $(SOURCE)


!ENDIF 

SOURCE=.\localppg.cpp

"$(INTDIR)\localppg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\localize.pch"


SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "Localize - Win32 Release"

CPP_SWITCHES=/nologo /MD /W4 /GX /Ox /D "NDEBUG" /D "_WINDOWS" /D "_AFXCTL" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\localize.pch" /Yc"STDAFX.H" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\localize.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Localize - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W4 /Gm /GX /ZI /Od /D "_DEBUG" /D "_WINDOWS" /D "_AFXCTL" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\localize.pch" /Yc"STDAFX.H" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\localize.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Localize - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MD /W4 /GX /Ox /D "NDEBUG" /D "_UNICODE" /D "_WINDOWS" /D "_AFXCTL" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\localize.pch" /Yc"STDAFX.H" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\localize.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Localize - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W4 /Gm /GX /ZI /Od /D "_DEBUG" /D "_UNICODE" /D "_WINDOWS" /D "_AFXCTL" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\localize.pch" /Yc"STDAFX.H" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\localize.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

