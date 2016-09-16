# Microsoft Developer Studio Generated NMAKE File, Based on ATLFire.dsp
!IF "$(CFG)" == ""
CFG=ATLFire - Win32 Debug
!MESSAGE No configuration specified. Defaulting to ATLFire - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "ATLFire - Win32 Debug" && "$(CFG)" != "ATLFire - Win32 Unicode Debug" && "$(CFG)" != "ATLFire - Win32 Release MinSize" && "$(CFG)" != "ATLFire - Win32 Release MinDependency" && "$(CFG)" != "ATLFire - Win32 Unicode Release MinSize" && "$(CFG)" != "ATLFire - Win32 Unicode Release MinDependency"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ATLFire.mak" CFG="ATLFire - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ATLFire - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ATLFire - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ATLFire - Win32 Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ATLFire - Win32 Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ATLFire - Win32 Unicode Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ATLFire - Win32 Unicode Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "ATLFire - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\ATLFire.dll" "$(OUTDIR)\ATLFire.bsc" ".\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\ATLFire.obj"
	-@erase "$(INTDIR)\ATLFire.pch"
	-@erase "$(INTDIR)\ATLFire.res"
	-@erase "$(INTDIR)\ATLFire.sbr"
	-@erase "$(INTDIR)\FireTabCtrl.obj"
	-@erase "$(INTDIR)\FireTabCtrl.sbr"
	-@erase "$(INTDIR)\FireWnd.obj"
	-@erase "$(INTDIR)\FireWnd.sbr"
	-@erase "$(INTDIR)\PropDlg.obj"
	-@erase "$(INTDIR)\PropDlg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\ATLFire.bsc"
	-@erase "$(OUTDIR)\ATLFire.dll"
	-@erase "$(OUTDIR)\ATLFire.exp"
	-@erase "$(OUTDIR)\ATLFire.ilk"
	-@erase "$(OUTDIR)\ATLFire.lib"
	-@erase "$(OUTDIR)\ATLFire.pdb"
	-@erase ".\ATLFire.h"
	-@erase ".\ATLFire.tlb"
	-@erase ".\ATLFire_i.c"
	-@erase ".\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ATLFire.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ATLFire.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ATLFire.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\ATLFire.sbr" \
	"$(INTDIR)\FireTabCtrl.sbr" \
	"$(INTDIR)\FireWnd.sbr" \
	"$(INTDIR)\PropDlg.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\ATLFire.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\ATLFire.pdb" /debug /machine:I386 /def:".\ATLFire.def" /out:"$(OUTDIR)\ATLFire.dll" /implib:"$(OUTDIR)\ATLFire.lib" /pdbtype:sept 
DEF_FILE= \
	".\ATLFire.def"
LINK32_OBJS= \
	"$(INTDIR)\ATLFire.obj" \
	"$(INTDIR)\FireTabCtrl.obj" \
	"$(INTDIR)\FireWnd.obj" \
	"$(INTDIR)\PropDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ATLFire.res"

"$(OUTDIR)\ATLFire.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Debug
TargetPath=.\Debug\ATLFire.dll
InputPath=.\Debug\ATLFire.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "ATLFire - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\DebugU
# End Custom Macros

ALL : ".\ATLFire_i.c" ".\ATLFire.tlb" ".\ATLFire.h" "$(OUTDIR)\ATLFire.dll" "$(OUTDIR)\ATLFire.bsc" ".\DebugU\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\ATLFire.obj"
	-@erase "$(INTDIR)\ATLFire.pch"
	-@erase "$(INTDIR)\ATLFire.res"
	-@erase "$(INTDIR)\ATLFire.sbr"
	-@erase "$(INTDIR)\FireTabCtrl.obj"
	-@erase "$(INTDIR)\FireTabCtrl.sbr"
	-@erase "$(INTDIR)\FireWnd.obj"
	-@erase "$(INTDIR)\FireWnd.sbr"
	-@erase "$(INTDIR)\PropDlg.obj"
	-@erase "$(INTDIR)\PropDlg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\ATLFire.bsc"
	-@erase "$(OUTDIR)\ATLFire.dll"
	-@erase "$(OUTDIR)\ATLFire.exp"
	-@erase "$(OUTDIR)\ATLFire.ilk"
	-@erase "$(OUTDIR)\ATLFire.lib"
	-@erase "$(OUTDIR)\ATLFire.pdb"
	-@erase ".\ATLFire.h"
	-@erase ".\ATLFire.tlb"
	-@erase ".\ATLFire_i.c"
	-@erase ".\DebugU\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_DEBUG_QI" /D "_ATL_DEBUG_REFCOUNT" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ATLFire.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ATLFire.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ATLFire.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\ATLFire.sbr" \
	"$(INTDIR)\FireTabCtrl.sbr" \
	"$(INTDIR)\FireWnd.sbr" \
	"$(INTDIR)\PropDlg.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\ATLFire.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\ATLFire.pdb" /debug /machine:I386 /def:".\ATLFire.def" /out:"$(OUTDIR)\ATLFire.dll" /implib:"$(OUTDIR)\ATLFire.lib" /pdbtype:sept 
DEF_FILE= \
	".\ATLFire.def"
LINK32_OBJS= \
	"$(INTDIR)\ATLFire.obj" \
	"$(INTDIR)\FireTabCtrl.obj" \
	"$(INTDIR)\FireWnd.obj" \
	"$(INTDIR)\PropDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ATLFire.res"

"$(OUTDIR)\ATLFire.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\DebugU
TargetPath=.\DebugU\ATLFire.dll
InputPath=.\DebugU\ATLFire.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "ATLFire - Win32 Release MinSize"

OUTDIR=.\ReleaseMinSize
INTDIR=.\ReleaseMinSize
# Begin Custom Macros
OutDir=.\ReleaseMinSize
# End Custom Macros

ALL : ".\ATLFire_i.c" ".\ATLFire.tlb" ".\ATLFire.h" "$(OUTDIR)\ATLFire.dll" "$(OUTDIR)\ATLFire.bsc" ".\ReleaseMinSize\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\ATLFire.obj"
	-@erase "$(INTDIR)\ATLFire.pch"
	-@erase "$(INTDIR)\ATLFire.res"
	-@erase "$(INTDIR)\ATLFire.sbr"
	-@erase "$(INTDIR)\FireTabCtrl.obj"
	-@erase "$(INTDIR)\FireTabCtrl.sbr"
	-@erase "$(INTDIR)\FireWnd.obj"
	-@erase "$(INTDIR)\FireWnd.sbr"
	-@erase "$(INTDIR)\PropDlg.obj"
	-@erase "$(INTDIR)\PropDlg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\ATLFire.bsc"
	-@erase "$(OUTDIR)\ATLFire.dll"
	-@erase "$(OUTDIR)\ATLFire.exp"
	-@erase "$(OUTDIR)\ATLFire.lib"
	-@erase ".\ATLFire.h"
	-@erase ".\ATLFire.tlb"
	-@erase ".\ATLFire_i.c"
	-@erase ".\ReleaseMinSize\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_ATL_DLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ATLFire.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ATLFire.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ATLFire.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\ATLFire.sbr" \
	"$(INTDIR)\FireTabCtrl.sbr" \
	"$(INTDIR)\FireWnd.sbr" \
	"$(INTDIR)\PropDlg.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\ATLFire.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\ATLFire.pdb" /machine:I386 /def:".\ATLFire.def" /out:"$(OUTDIR)\ATLFire.dll" /implib:"$(OUTDIR)\ATLFire.lib" 
DEF_FILE= \
	".\ATLFire.def"
LINK32_OBJS= \
	"$(INTDIR)\ATLFire.obj" \
	"$(INTDIR)\FireTabCtrl.obj" \
	"$(INTDIR)\FireWnd.obj" \
	"$(INTDIR)\PropDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ATLFire.res"

"$(OUTDIR)\ATLFire.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseMinSize
TargetPath=.\ReleaseMinSize\ATLFire.dll
InputPath=.\ReleaseMinSize\ATLFire.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "ATLFire - Win32 Release MinDependency"

OUTDIR=.\ReleaseMinDependency
INTDIR=.\ReleaseMinDependency
# Begin Custom Macros
OutDir=.\ReleaseMinDependency
# End Custom Macros

ALL : ".\ATLFire_i.c" ".\ATLFire.tlb" ".\ATLFire.h" "$(OUTDIR)\ATLFire.dll" ".\ReleaseMinDependency\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\ATLFire.obj"
	-@erase "$(INTDIR)\ATLFire.pch"
	-@erase "$(INTDIR)\ATLFire.res"
	-@erase "$(INTDIR)\FireTabCtrl.obj"
	-@erase "$(INTDIR)\FireWnd.obj"
	-@erase "$(INTDIR)\PropDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\ATLFire.dll"
	-@erase "$(OUTDIR)\ATLFire.exp"
	-@erase "$(OUTDIR)\ATLFire.lib"
	-@erase ".\ATLFire.h"
	-@erase ".\ATLFire.tlb"
	-@erase ".\ATLFire_i.c"
	-@erase ".\ReleaseMinDependency\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\ATLFire.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ATLFire.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ATLFire.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\ATLFire.pdb" /machine:I386 /def:".\ATLFire.def" /out:"$(OUTDIR)\ATLFire.dll" /implib:"$(OUTDIR)\ATLFire.lib" 
DEF_FILE= \
	".\ATLFire.def"
LINK32_OBJS= \
	"$(INTDIR)\ATLFire.obj" \
	"$(INTDIR)\FireTabCtrl.obj" \
	"$(INTDIR)\FireWnd.obj" \
	"$(INTDIR)\PropDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ATLFire.res"

"$(OUTDIR)\ATLFire.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseMinDependency
TargetPath=.\ReleaseMinDependency\ATLFire.dll
InputPath=.\ReleaseMinDependency\ATLFire.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "ATLFire - Win32 Unicode Release MinSize"

OUTDIR=.\ReleaseUMinSize
INTDIR=.\ReleaseUMinSize
# Begin Custom Macros
OutDir=.\ReleaseUMinSize
# End Custom Macros

ALL : ".\ATLFire_i.c" ".\ATLFire.tlb" ".\ATLFire.h" "$(OUTDIR)\ATLFire.dll" ".\ReleaseUMinSize\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\ATLFire.obj"
	-@erase "$(INTDIR)\ATLFire.pch"
	-@erase "$(INTDIR)\ATLFire.res"
	-@erase "$(INTDIR)\FireTabCtrl.obj"
	-@erase "$(INTDIR)\FireWnd.obj"
	-@erase "$(INTDIR)\PropDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\ATLFire.dll"
	-@erase "$(OUTDIR)\ATLFire.exp"
	-@erase "$(OUTDIR)\ATLFire.lib"
	-@erase ".\ATLFire.h"
	-@erase ".\ATLFire.tlb"
	-@erase ".\ATLFire_i.c"
	-@erase ".\ReleaseUMinSize\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_DLL" /Fp"$(INTDIR)\ATLFire.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ATLFire.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ATLFire.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\ATLFire.pdb" /machine:I386 /def:".\ATLFire.def" /out:"$(OUTDIR)\ATLFire.dll" /implib:"$(OUTDIR)\ATLFire.lib" 
DEF_FILE= \
	".\ATLFire.def"
LINK32_OBJS= \
	"$(INTDIR)\ATLFire.obj" \
	"$(INTDIR)\FireTabCtrl.obj" \
	"$(INTDIR)\FireWnd.obj" \
	"$(INTDIR)\PropDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ATLFire.res"

"$(OUTDIR)\ATLFire.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseUMinSize
TargetPath=.\ReleaseUMinSize\ATLFire.dll
InputPath=.\ReleaseUMinSize\ATLFire.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "ATLFire - Win32 Unicode Release MinDependency"

OUTDIR=.\ReleaseUMinDependency
INTDIR=.\ReleaseUMinDependency
# Begin Custom Macros
OutDir=.\ReleaseUMinDependency
# End Custom Macros

ALL : ".\ATLFire_i.c" ".\ATLFire.tlb" ".\ATLFire.h" "$(OUTDIR)\ATLFire.dll" ".\ReleaseUMinDependency\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\ATLFire.obj"
	-@erase "$(INTDIR)\ATLFire.pch"
	-@erase "$(INTDIR)\ATLFire.res"
	-@erase "$(INTDIR)\FireTabCtrl.obj"
	-@erase "$(INTDIR)\FireWnd.obj"
	-@erase "$(INTDIR)\PropDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\ATLFire.dll"
	-@erase "$(OUTDIR)\ATLFire.exp"
	-@erase "$(OUTDIR)\ATLFire.lib"
	-@erase ".\ATLFire.h"
	-@erase ".\ATLFire.tlb"
	-@erase ".\ATLFire_i.c"
	-@erase ".\ReleaseUMinDependency\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\ATLFire.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ATLFire.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ATLFire.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\ATLFire.pdb" /machine:I386 /def:".\ATLFire.def" /out:"$(OUTDIR)\ATLFire.dll" /implib:"$(OUTDIR)\ATLFire.lib" 
DEF_FILE= \
	".\ATLFire.def"
LINK32_OBJS= \
	"$(INTDIR)\ATLFire.obj" \
	"$(INTDIR)\FireTabCtrl.obj" \
	"$(INTDIR)\FireWnd.obj" \
	"$(INTDIR)\PropDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ATLFire.res"

"$(OUTDIR)\ATLFire.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseUMinDependency
TargetPath=.\ReleaseUMinDependency\ATLFire.dll
InputPath=.\ReleaseUMinDependency\ATLFire.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
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
!IF EXISTS("ATLFire.dep")
!INCLUDE "ATLFire.dep"
!ELSE 
!MESSAGE Warning: cannot find "ATLFire.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "ATLFire - Win32 Debug" || "$(CFG)" == "ATLFire - Win32 Unicode Debug" || "$(CFG)" == "ATLFire - Win32 Release MinSize" || "$(CFG)" == "ATLFire - Win32 Release MinDependency" || "$(CFG)" == "ATLFire - Win32 Unicode Release MinSize" || "$(CFG)" == "ATLFire - Win32 Unicode Release MinDependency"
SOURCE=.\ATLFire.cpp

!IF  "$(CFG)" == "ATLFire - Win32 Debug"


"$(INTDIR)\ATLFire.obj"	"$(INTDIR)\ATLFire.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ATLFire.pch" ".\ATLFire.h" ".\ATLFire_i.c"


!ELSEIF  "$(CFG)" == "ATLFire - Win32 Unicode Debug"


"$(INTDIR)\ATLFire.obj"	"$(INTDIR)\ATLFire.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ATLFire.pch"


!ELSEIF  "$(CFG)" == "ATLFire - Win32 Release MinSize"


"$(INTDIR)\ATLFire.obj"	"$(INTDIR)\ATLFire.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ATLFire.pch"


!ELSEIF  "$(CFG)" == "ATLFire - Win32 Release MinDependency"


"$(INTDIR)\ATLFire.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ATLFire.pch"


!ELSEIF  "$(CFG)" == "ATLFire - Win32 Unicode Release MinSize"


"$(INTDIR)\ATLFire.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ATLFire.pch"


!ELSEIF  "$(CFG)" == "ATLFire - Win32 Unicode Release MinDependency"


"$(INTDIR)\ATLFire.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ATLFire.pch"


!ENDIF 

SOURCE=.\ATLFire.idl

!IF  "$(CFG)" == "ATLFire - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "./ATLFire.tlb" /h "ATLFire.h" /iid "ATLFire_i.c" /o "NUL" /win32 

".\ATLFire.tlb"	".\ATLFire.h"	".\ATLFire_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ATLFire - Win32 Unicode Debug"

InputPath=.\ATLFire.idl

".\ATLFire.tlb"	".\ATLFire.h"	".\ATLFire_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	midl /Oicf /h "ATLFire.h" /iid "ATLFire_i.c" "ATLFire.idl"
<< 
	

!ELSEIF  "$(CFG)" == "ATLFire - Win32 Release MinSize"

InputPath=.\ATLFire.idl

".\ATLFire.tlb"	".\ATLFire.h"	".\ATLFire_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	midl /Oicf /h "ATLFire.h" /iid "ATLFire_i.c" "ATLFire.idl"
<< 
	

!ELSEIF  "$(CFG)" == "ATLFire - Win32 Release MinDependency"

InputPath=.\ATLFire.idl

".\ATLFire.tlb"	".\ATLFire.h"	".\ATLFire_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	midl /Oicf /h "ATLFire.h" /iid "ATLFire_i.c" "ATLFire.idl"
<< 
	

!ELSEIF  "$(CFG)" == "ATLFire - Win32 Unicode Release MinSize"

InputPath=.\ATLFire.idl

".\ATLFire.tlb"	".\ATLFire.h"	".\ATLFire_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	midl /Oicf /h "ATLFire.h" /iid "ATLFire_i.c" "ATLFire.idl"
<< 
	

!ELSEIF  "$(CFG)" == "ATLFire - Win32 Unicode Release MinDependency"

InputPath=.\ATLFire.idl

".\ATLFire.tlb"	".\ATLFire.h"	".\ATLFire_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	midl /Oicf /h "ATLFire.h" /iid "ATLFire_i.c" "ATLFire.idl"
<< 
	

!ENDIF 

SOURCE=.\ATLFire.rc

"$(INTDIR)\ATLFire.res" : $(SOURCE) "$(INTDIR)" ".\ATLFire.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\FireTabCtrl.cpp

!IF  "$(CFG)" == "ATLFire - Win32 Debug"


"$(INTDIR)\FireTabCtrl.obj"	"$(INTDIR)\FireTabCtrl.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ATLFire.pch" ".\ATLFire.h"


!ELSEIF  "$(CFG)" == "ATLFire - Win32 Unicode Debug"


"$(INTDIR)\FireTabCtrl.obj"	"$(INTDIR)\FireTabCtrl.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ATLFire.pch"


!ELSEIF  "$(CFG)" == "ATLFire - Win32 Release MinSize"


"$(INTDIR)\FireTabCtrl.obj"	"$(INTDIR)\FireTabCtrl.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ATLFire.pch"


!ELSEIF  "$(CFG)" == "ATLFire - Win32 Release MinDependency"


"$(INTDIR)\FireTabCtrl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ATLFire.pch"


!ELSEIF  "$(CFG)" == "ATLFire - Win32 Unicode Release MinSize"


"$(INTDIR)\FireTabCtrl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ATLFire.pch"


!ELSEIF  "$(CFG)" == "ATLFire - Win32 Unicode Release MinDependency"


"$(INTDIR)\FireTabCtrl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ATLFire.pch"


!ENDIF 

SOURCE=.\FireWnd.cpp

!IF  "$(CFG)" == "ATLFire - Win32 Debug"


"$(INTDIR)\FireWnd.obj"	"$(INTDIR)\FireWnd.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ATLFire.pch"


!ELSEIF  "$(CFG)" == "ATLFire - Win32 Unicode Debug"


"$(INTDIR)\FireWnd.obj"	"$(INTDIR)\FireWnd.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ATLFire.pch"


!ELSEIF  "$(CFG)" == "ATLFire - Win32 Release MinSize"


"$(INTDIR)\FireWnd.obj"	"$(INTDIR)\FireWnd.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ATLFire.pch"


!ELSEIF  "$(CFG)" == "ATLFire - Win32 Release MinDependency"


"$(INTDIR)\FireWnd.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ATLFire.pch"


!ELSEIF  "$(CFG)" == "ATLFire - Win32 Unicode Release MinSize"


"$(INTDIR)\FireWnd.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ATLFire.pch"


!ELSEIF  "$(CFG)" == "ATLFire - Win32 Unicode Release MinDependency"


"$(INTDIR)\FireWnd.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ATLFire.pch"


!ENDIF 

SOURCE=.\PropDlg.cpp

!IF  "$(CFG)" == "ATLFire - Win32 Debug"


"$(INTDIR)\PropDlg.obj"	"$(INTDIR)\PropDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ATLFire.pch"


!ELSEIF  "$(CFG)" == "ATLFire - Win32 Unicode Debug"


"$(INTDIR)\PropDlg.obj"	"$(INTDIR)\PropDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ATLFire.pch"


!ELSEIF  "$(CFG)" == "ATLFire - Win32 Release MinSize"


"$(INTDIR)\PropDlg.obj"	"$(INTDIR)\PropDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ATLFire.pch"


!ELSEIF  "$(CFG)" == "ATLFire - Win32 Release MinDependency"


"$(INTDIR)\PropDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ATLFire.pch"


!ELSEIF  "$(CFG)" == "ATLFire - Win32 Unicode Release MinSize"


"$(INTDIR)\PropDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ATLFire.pch"


!ELSEIF  "$(CFG)" == "ATLFire - Win32 Unicode Release MinDependency"


"$(INTDIR)\PropDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ATLFire.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "ATLFire - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ATLFire.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\ATLFire.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ATLFire - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_DEBUG_QI" /D "_ATL_DEBUG_REFCOUNT" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ATLFire.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\ATLFire.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ATLFire - Win32 Release MinSize"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_ATL_DLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ATLFire.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\ATLFire.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ATLFire - Win32 Release MinDependency"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\ATLFire.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ATLFire.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ATLFire - Win32 Unicode Release MinSize"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_DLL" /Fp"$(INTDIR)\ATLFire.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ATLFire.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ATLFire - Win32 Unicode Release MinDependency"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\ATLFire.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ATLFire.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

