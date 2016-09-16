# Microsoft Developer Studio Generated NMAKE File, Based on inproc.dsp
!IF "$(CFG)" == ""
CFG=InProc - Win32 Release
!MESSAGE No configuration specified.  Defaulting to InProc - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "InProc - Win32 Release" && "$(CFG)" != "InProc - Win32 Debug"\
 && "$(CFG)" != "InProc - Win32 Unicode Release" && "$(CFG)" !=\
 "InProc - Win32 Unicode Debug" && "$(CFG)" != "InProc - Win32 Dll Release" &&\
 "$(CFG)" != "InProc - Win32 Dll Debug" && "$(CFG)" !=\
 "InProc - Win32 Unicode Dll Release" && "$(CFG)" !=\
 "InProc - Win32 Unicode Dll Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "inproc.mak" CFG="InProc - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "InProc - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "InProc - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "InProc - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "InProc - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE "InProc - Win32 Dll Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "InProc - Win32 Dll Debug" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "InProc - Win32 Unicode Dll Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "InProc - Win32 Unicode Dll Debug" (based on\
 "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "InProc - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\inproc.exe" "$(OUTDIR)\inproc.tlb" "$(OUTDIR)\inproc.bsc"

CLEAN : 
	-@erase "$(INTDIR)\enumvar.obj"
	-@erase "$(INTDIR)\enumvar.sbr"
	-@erase "$(INTDIR)\inproc.obj"
	-@erase "$(INTDIR)\inproc.pch"
	-@erase "$(INTDIR)\inproc.res"
	-@erase "$(INTDIR)\inproc.sbr"
	-@erase "$(INTDIR)\inproc.tlb"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\stdafx.sbr"
	-@erase "$(INTDIR)\strcoll.obj"
	-@erase "$(INTDIR)\strcoll.sbr"
	-@erase "$(INTDIR)\varassoc.obj"
	-@erase "$(INTDIR)\varassoc.sbr"
	-@erase "$(INTDIR)\varmap.obj"
	-@erase "$(INTDIR)\varmap.sbr"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\inproc.bsc"
	-@erase "$(OUTDIR)\inproc.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /D "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\inproc.pch" /Yu"Stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\Release/
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\inproc.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\inproc.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\enumvar.sbr" \
	"$(INTDIR)\inproc.sbr" \
	"$(INTDIR)\stdafx.sbr" \
	"$(INTDIR)\strcoll.sbr" \
	"$(INTDIR)\varassoc.sbr" \
	"$(INTDIR)\varmap.sbr"

"$(OUTDIR)\inproc.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\inproc.pdb" /machine:I386 /out:"$(OUTDIR)\inproc.exe" 
LINK32_OBJS= \
	"$(INTDIR)\enumvar.obj" \
	"$(INTDIR)\inproc.obj" \
	"$(INTDIR)\inproc.res" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\strcoll.obj" \
	"$(INTDIR)\varassoc.obj" \
	"$(INTDIR)\varmap.obj"

"$(OUTDIR)\inproc.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "InProc - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\inproc.exe" "$(OUTDIR)\inproc.tlb" "$(OUTDIR)\inproc.bsc"

CLEAN : 
	-@erase "$(INTDIR)\enumvar.obj"
	-@erase "$(INTDIR)\enumvar.sbr"
	-@erase "$(INTDIR)\inproc.obj"
	-@erase "$(INTDIR)\inproc.pch"
	-@erase "$(INTDIR)\inproc.res"
	-@erase "$(INTDIR)\inproc.sbr"
	-@erase "$(INTDIR)\inproc.tlb"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\stdafx.sbr"
	-@erase "$(INTDIR)\strcoll.obj"
	-@erase "$(INTDIR)\strcoll.sbr"
	-@erase "$(INTDIR)\varassoc.obj"
	-@erase "$(INTDIR)\varassoc.sbr"
	-@erase "$(INTDIR)\varmap.obj"
	-@erase "$(INTDIR)\varmap.sbr"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\inproc.bsc"
	-@erase "$(OUTDIR)\inproc.exe"
	-@erase "$(OUTDIR)\inproc.ilk"
	-@erase "$(OUTDIR)\inproc.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /D "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\inproc.pch"\
 /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\Debug/
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\inproc.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\inproc.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\enumvar.sbr" \
	"$(INTDIR)\inproc.sbr" \
	"$(INTDIR)\stdafx.sbr" \
	"$(INTDIR)\strcoll.sbr" \
	"$(INTDIR)\varassoc.sbr" \
	"$(INTDIR)\varmap.sbr"

"$(OUTDIR)\inproc.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\inproc.pdb" /debug /machine:I386 /out:"$(OUTDIR)\inproc.exe" 
LINK32_OBJS= \
	"$(INTDIR)\enumvar.obj" \
	"$(INTDIR)\inproc.obj" \
	"$(INTDIR)\inproc.res" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\strcoll.obj" \
	"$(INTDIR)\varassoc.obj" \
	"$(INTDIR)\varmap.obj"

"$(OUTDIR)\inproc.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Release"

OUTDIR=.\UniRelease
INTDIR=.\UniRelease
# Begin Custom Macros
OutDir=.\.\UniRelease
# End Custom Macros

ALL : "$(OUTDIR)\inproc.exe" "$(OUTDIR)\inproc.tlb" "$(OUTDIR)\inproc.bsc"

CLEAN : 
	-@erase "$(INTDIR)\enumvar.obj"
	-@erase "$(INTDIR)\enumvar.sbr"
	-@erase "$(INTDIR)\inproc.obj"
	-@erase "$(INTDIR)\inproc.pch"
	-@erase "$(INTDIR)\inproc.res"
	-@erase "$(INTDIR)\inproc.sbr"
	-@erase "$(INTDIR)\inproc.tlb"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\stdafx.sbr"
	-@erase "$(INTDIR)\strcoll.obj"
	-@erase "$(INTDIR)\strcoll.sbr"
	-@erase "$(INTDIR)\varassoc.obj"
	-@erase "$(INTDIR)\varassoc.sbr"
	-@erase "$(INTDIR)\varmap.obj"
	-@erase "$(INTDIR)\varmap.sbr"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\inproc.bsc"
	-@erase "$(OUTDIR)\inproc.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_UNICODE" /D "_MBCS" /D "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\inproc.pch"\
 /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\UniRelease/
CPP_SBRS=.\UniRelease/
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\inproc.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\inproc.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\enumvar.sbr" \
	"$(INTDIR)\inproc.sbr" \
	"$(INTDIR)\stdafx.sbr" \
	"$(INTDIR)\strcoll.sbr" \
	"$(INTDIR)\varassoc.sbr" \
	"$(INTDIR)\varmap.sbr"

"$(OUTDIR)\inproc.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows\
 /incremental:no /pdb:"$(OUTDIR)\inproc.pdb" /machine:I386\
 /out:"$(OUTDIR)\inproc.exe" 
LINK32_OBJS= \
	"$(INTDIR)\enumvar.obj" \
	"$(INTDIR)\inproc.obj" \
	"$(INTDIR)\inproc.res" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\strcoll.obj" \
	"$(INTDIR)\varassoc.obj" \
	"$(INTDIR)\varmap.obj"

"$(OUTDIR)\inproc.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Debug"

OUTDIR=.\UniDebug
INTDIR=.\UniDebug
# Begin Custom Macros
OutDir=.\.\UniDebug
# End Custom Macros

ALL : "$(OUTDIR)\inproc.exe" "$(OUTDIR)\inproc.tlb" "$(OUTDIR)\inproc.bsc"

CLEAN : 
	-@erase "$(INTDIR)\enumvar.obj"
	-@erase "$(INTDIR)\enumvar.sbr"
	-@erase "$(INTDIR)\inproc.obj"
	-@erase "$(INTDIR)\inproc.pch"
	-@erase "$(INTDIR)\inproc.res"
	-@erase "$(INTDIR)\inproc.sbr"
	-@erase "$(INTDIR)\inproc.tlb"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\stdafx.sbr"
	-@erase "$(INTDIR)\strcoll.obj"
	-@erase "$(INTDIR)\strcoll.sbr"
	-@erase "$(INTDIR)\varassoc.obj"
	-@erase "$(INTDIR)\varassoc.sbr"
	-@erase "$(INTDIR)\varmap.obj"
	-@erase "$(INTDIR)\varmap.sbr"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\inproc.bsc"
	-@erase "$(OUTDIR)\inproc.exe"
	-@erase "$(OUTDIR)\inproc.ilk"
	-@erase "$(OUTDIR)\inproc.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_UNICODE" /D "_MBCS" /D "_AFXDLL" /FR"$(INTDIR)\\"\
 /Fp"$(INTDIR)\inproc.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 
CPP_OBJS=.\UniDebug/
CPP_SBRS=.\UniDebug/
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\inproc.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\inproc.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\enumvar.sbr" \
	"$(INTDIR)\inproc.sbr" \
	"$(INTDIR)\stdafx.sbr" \
	"$(INTDIR)\strcoll.sbr" \
	"$(INTDIR)\varassoc.sbr" \
	"$(INTDIR)\varmap.sbr"

"$(OUTDIR)\inproc.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows\
 /incremental:yes /pdb:"$(OUTDIR)\inproc.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)\inproc.exe" 
LINK32_OBJS= \
	"$(INTDIR)\enumvar.obj" \
	"$(INTDIR)\inproc.obj" \
	"$(INTDIR)\inproc.res" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\strcoll.obj" \
	"$(INTDIR)\varassoc.obj" \
	"$(INTDIR)\varmap.obj"

"$(OUTDIR)\inproc.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "InProc - Win32 Dll Release"

OUTDIR=.\DllRelease
INTDIR=.\DllRelease
# Begin Custom Macros
OutDir=.\.\DllRelease
# End Custom Macros

ALL : "$(OUTDIR)\inproc.dll" "$(OUTDIR)\inproc.tlb" "$(OUTDIR)\inproc.bsc"\
 "$(OutDir)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\enumvar.obj"
	-@erase "$(INTDIR)\enumvar.sbr"
	-@erase "$(INTDIR)\inproc.obj"
	-@erase "$(INTDIR)\inproc.pch"
	-@erase "$(INTDIR)\inproc.res"
	-@erase "$(INTDIR)\inproc.sbr"
	-@erase "$(INTDIR)\inproc.tlb"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\stdafx.sbr"
	-@erase "$(INTDIR)\strcoll.obj"
	-@erase "$(INTDIR)\strcoll.sbr"
	-@erase "$(INTDIR)\varassoc.obj"
	-@erase "$(INTDIR)\varassoc.sbr"
	-@erase "$(INTDIR)\varmap.obj"
	-@erase "$(INTDIR)\varmap.sbr"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\inproc.bsc"
	-@erase "$(OUTDIR)\inproc.dll"
	-@erase "$(OUTDIR)\inproc.exp"
	-@erase "$(OUTDIR)\inproc.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_MBCS" /D "_WINDLL" /D "_AFXDLL" /FR"$(INTDIR)\\"\
 /Fp"$(INTDIR)\inproc.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 
CPP_OBJS=.\DllRelease/
CPP_SBRS=.\DllRelease/
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\inproc.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\inproc.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\enumvar.sbr" \
	"$(INTDIR)\inproc.sbr" \
	"$(INTDIR)\stdafx.sbr" \
	"$(INTDIR)\strcoll.sbr" \
	"$(INTDIR)\varassoc.sbr" \
	"$(INTDIR)\varmap.sbr"

"$(OUTDIR)\inproc.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)\inproc.pdb" /machine:I386 /def:".\inproc.def"\
 /out:"$(OUTDIR)\inproc.dll" /implib:"$(OUTDIR)\inproc.lib" 
DEF_FILE= \
	".\inproc.def"
LINK32_OBJS= \
	"$(INTDIR)\enumvar.obj" \
	"$(INTDIR)\inproc.obj" \
	"$(INTDIR)\inproc.res" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\strcoll.obj" \
	"$(INTDIR)\varassoc.obj" \
	"$(INTDIR)\varmap.obj"

"$(OUTDIR)\inproc.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\DllRelease
TargetPath=.\DllRelease\inproc.dll
InputPath=.\DllRelease\inproc.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "InProc - Win32 Dll Debug"

OUTDIR=.\DllDebug
INTDIR=.\DllDebug
# Begin Custom Macros
OutDir=.\.\DllDebug
# End Custom Macros

ALL : "$(OUTDIR)\inproc.dll" "$(OUTDIR)\inproc.tlb" "$(OUTDIR)\inproc.bsc"

CLEAN : 
	-@erase "$(INTDIR)\enumvar.obj"
	-@erase "$(INTDIR)\enumvar.sbr"
	-@erase "$(INTDIR)\inproc.obj"
	-@erase "$(INTDIR)\inproc.pch"
	-@erase "$(INTDIR)\inproc.res"
	-@erase "$(INTDIR)\inproc.sbr"
	-@erase "$(INTDIR)\inproc.tlb"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\stdafx.sbr"
	-@erase "$(INTDIR)\strcoll.obj"
	-@erase "$(INTDIR)\strcoll.sbr"
	-@erase "$(INTDIR)\varassoc.obj"
	-@erase "$(INTDIR)\varassoc.sbr"
	-@erase "$(INTDIR)\varmap.obj"
	-@erase "$(INTDIR)\varmap.sbr"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\inproc.bsc"
	-@erase "$(OUTDIR)\inproc.dll"
	-@erase "$(OUTDIR)\inproc.exp"
	-@erase "$(OUTDIR)\inproc.ilk"
	-@erase "$(OUTDIR)\inproc.lib"
	-@erase "$(OUTDIR)\inproc.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_USRDLL" /D "_MBCS" /D "_WINDLL" /D "_AFXDLL" /FR"$(INTDIR)\\"\
 /Fp"$(INTDIR)\inproc.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 
CPP_OBJS=.\DllDebug/
CPP_SBRS=.\DllDebug/
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\inproc.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\inproc.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\enumvar.sbr" \
	"$(INTDIR)\inproc.sbr" \
	"$(INTDIR)\stdafx.sbr" \
	"$(INTDIR)\strcoll.sbr" \
	"$(INTDIR)\varassoc.sbr" \
	"$(INTDIR)\varmap.sbr"

"$(OUTDIR)\inproc.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)\inproc.pdb" /debug /machine:I386 /def:".\inproc.def"\
 /out:"$(OUTDIR)\inproc.dll" /implib:"$(OUTDIR)\inproc.lib" 
DEF_FILE= \
	".\inproc.def"
LINK32_OBJS= \
	"$(INTDIR)\enumvar.obj" \
	"$(INTDIR)\inproc.obj" \
	"$(INTDIR)\inproc.res" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\strcoll.obj" \
	"$(INTDIR)\varassoc.obj" \
	"$(INTDIR)\varmap.obj"

"$(OUTDIR)\inproc.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Dll Release"

OUTDIR=.\UniDllRelease
INTDIR=.\UniDllRelease
# Begin Custom Macros
OutDir=.\.\UniDllRelease
# End Custom Macros

ALL : "$(OUTDIR)\inproc.dll" "$(OUTDIR)\inproc.tlb" "$(OUTDIR)\inproc.bsc"

CLEAN : 
	-@erase "$(INTDIR)\enumvar.obj"
	-@erase "$(INTDIR)\enumvar.sbr"
	-@erase "$(INTDIR)\inproc.obj"
	-@erase "$(INTDIR)\inproc.pch"
	-@erase "$(INTDIR)\inproc.res"
	-@erase "$(INTDIR)\inproc.sbr"
	-@erase "$(INTDIR)\inproc.tlb"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\stdafx.sbr"
	-@erase "$(INTDIR)\strcoll.obj"
	-@erase "$(INTDIR)\strcoll.sbr"
	-@erase "$(INTDIR)\varassoc.obj"
	-@erase "$(INTDIR)\varassoc.sbr"
	-@erase "$(INTDIR)\varmap.obj"
	-@erase "$(INTDIR)\varmap.sbr"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\inproc.bsc"
	-@erase "$(OUTDIR)\inproc.dll"
	-@erase "$(OUTDIR)\inproc.exp"
	-@erase "$(OUTDIR)\inproc.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_UNICODE" /D "_USRDLL" /D "_MBCS" /D "_WINDLL" /D "_AFXDLL" /FR"$(INTDIR)\\"\
 /Fp"$(INTDIR)\inproc.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 
CPP_OBJS=.\UniDllRelease/
CPP_SBRS=.\UniDllRelease/
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\inproc.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\inproc.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\enumvar.sbr" \
	"$(INTDIR)\inproc.sbr" \
	"$(INTDIR)\stdafx.sbr" \
	"$(INTDIR)\strcoll.sbr" \
	"$(INTDIR)\varassoc.sbr" \
	"$(INTDIR)\varmap.sbr"

"$(OUTDIR)\inproc.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)\inproc.pdb" /machine:I386 /def:".\inproc.def"\
 /out:"$(OUTDIR)\inproc.dll" /implib:"$(OUTDIR)\inproc.lib" 
DEF_FILE= \
	".\inproc.def"
LINK32_OBJS= \
	"$(INTDIR)\enumvar.obj" \
	"$(INTDIR)\inproc.obj" \
	"$(INTDIR)\inproc.res" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\strcoll.obj" \
	"$(INTDIR)\varassoc.obj" \
	"$(INTDIR)\varmap.obj"

"$(OUTDIR)\inproc.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Dll Debug"

OUTDIR=.\UniDllDebug
INTDIR=.\UniDllDebug
# Begin Custom Macros
OutDir=.\.\UniDllDebug
# End Custom Macros

ALL : "$(OUTDIR)\inproc.dll" "$(OUTDIR)\inproc.tlb" "$(OUTDIR)\inproc.bsc"

CLEAN : 
	-@erase "$(INTDIR)\enumvar.obj"
	-@erase "$(INTDIR)\enumvar.sbr"
	-@erase "$(INTDIR)\inproc.obj"
	-@erase "$(INTDIR)\inproc.pch"
	-@erase "$(INTDIR)\inproc.res"
	-@erase "$(INTDIR)\inproc.sbr"
	-@erase "$(INTDIR)\inproc.tlb"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\stdafx.sbr"
	-@erase "$(INTDIR)\strcoll.obj"
	-@erase "$(INTDIR)\strcoll.sbr"
	-@erase "$(INTDIR)\varassoc.obj"
	-@erase "$(INTDIR)\varassoc.sbr"
	-@erase "$(INTDIR)\varmap.obj"
	-@erase "$(INTDIR)\varmap.sbr"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\inproc.bsc"
	-@erase "$(OUTDIR)\inproc.dll"
	-@erase "$(OUTDIR)\inproc.exp"
	-@erase "$(OUTDIR)\inproc.ilk"
	-@erase "$(OUTDIR)\inproc.lib"
	-@erase "$(OUTDIR)\inproc.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_UNICODE" /D "_USRDLL" /D "_MBCS" /D "_WINDLL" /D "_AFXDLL"\
 /FR"$(INTDIR)\\" /Fp"$(INTDIR)\inproc.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\UniDllDebug/
CPP_SBRS=.\UniDllDebug/
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\inproc.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\inproc.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\enumvar.sbr" \
	"$(INTDIR)\inproc.sbr" \
	"$(INTDIR)\stdafx.sbr" \
	"$(INTDIR)\strcoll.sbr" \
	"$(INTDIR)\varassoc.sbr" \
	"$(INTDIR)\varmap.sbr"

"$(OUTDIR)\inproc.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)\inproc.pdb" /debug /machine:I386 /def:".\inproc.def"\
 /out:"$(OUTDIR)\inproc.dll" /implib:"$(OUTDIR)\inproc.lib" 
DEF_FILE= \
	".\inproc.def"
LINK32_OBJS= \
	"$(INTDIR)\enumvar.obj" \
	"$(INTDIR)\inproc.obj" \
	"$(INTDIR)\inproc.res" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\strcoll.obj" \
	"$(INTDIR)\varassoc.obj" \
	"$(INTDIR)\varmap.obj"

"$(OUTDIR)\inproc.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj::
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr::
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) $(CPP_PROJ) $<  


!IF "$(CFG)" == "InProc - Win32 Release" || "$(CFG)" == "InProc - Win32 Debug"\
 || "$(CFG)" == "InProc - Win32 Unicode Release" || "$(CFG)" ==\
 "InProc - Win32 Unicode Debug" || "$(CFG)" == "InProc - Win32 Dll Release" ||\
 "$(CFG)" == "InProc - Win32 Dll Debug" || "$(CFG)" ==\
 "InProc - Win32 Unicode Dll Release" || "$(CFG)" ==\
 "InProc - Win32 Unicode Dll Debug"
SOURCE=.\enumvar.cpp

!IF  "$(CFG)" == "InProc - Win32 Release"

DEP_CPP_ENUMV=\
	".\enumvar.h"\
	".\inproc.h"\
	

"$(INTDIR)\enumvar.obj"	"$(INTDIR)\enumvar.sbr" : $(SOURCE) $(DEP_CPP_ENUMV)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Debug"

DEP_CPP_ENUMV=\
	".\enumvar.h"\
	".\inproc.h"\
	

"$(INTDIR)\enumvar.obj"	"$(INTDIR)\enumvar.sbr" : $(SOURCE) $(DEP_CPP_ENUMV)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Release"

DEP_CPP_ENUMV=\
	".\enumvar.h"\
	".\inproc.h"\
	

"$(INTDIR)\enumvar.obj"	"$(INTDIR)\enumvar.sbr" : $(SOURCE) $(DEP_CPP_ENUMV)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Debug"

DEP_CPP_ENUMV=\
	".\enumvar.h"\
	".\inproc.h"\
	

"$(INTDIR)\enumvar.obj"	"$(INTDIR)\enumvar.sbr" : $(SOURCE) $(DEP_CPP_ENUMV)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Dll Release"

DEP_CPP_ENUMV=\
	".\enumvar.h"\
	".\inproc.h"\
	

"$(INTDIR)\enumvar.obj"	"$(INTDIR)\enumvar.sbr" : $(SOURCE) $(DEP_CPP_ENUMV)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Dll Debug"

DEP_CPP_ENUMV=\
	".\enumvar.h"\
	".\inproc.h"\
	

"$(INTDIR)\enumvar.obj"	"$(INTDIR)\enumvar.sbr" : $(SOURCE) $(DEP_CPP_ENUMV)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Dll Release"

DEP_CPP_ENUMV=\
	".\enumvar.h"\
	".\inproc.h"\
	

"$(INTDIR)\enumvar.obj"	"$(INTDIR)\enumvar.sbr" : $(SOURCE) $(DEP_CPP_ENUMV)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Dll Debug"

DEP_CPP_ENUMV=\
	".\enumvar.h"\
	".\inproc.h"\
	

"$(INTDIR)\enumvar.obj"	"$(INTDIR)\enumvar.sbr" : $(SOURCE) $(DEP_CPP_ENUMV)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ENDIF 

SOURCE=.\inproc.cpp
DEP_CPP_INPRO=\
	".\inproc.h"\
	

!IF  "$(CFG)" == "InProc - Win32 Release"


"$(INTDIR)\inproc.obj"	"$(INTDIR)\inproc.sbr" : $(SOURCE) $(DEP_CPP_INPRO)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Debug"


"$(INTDIR)\inproc.obj"	"$(INTDIR)\inproc.sbr" : $(SOURCE) $(DEP_CPP_INPRO)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Release"


"$(INTDIR)\inproc.obj"	"$(INTDIR)\inproc.sbr" : $(SOURCE) $(DEP_CPP_INPRO)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Debug"


"$(INTDIR)\inproc.obj"	"$(INTDIR)\inproc.sbr" : $(SOURCE) $(DEP_CPP_INPRO)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Dll Release"


"$(INTDIR)\inproc.obj"	"$(INTDIR)\inproc.sbr" : $(SOURCE) $(DEP_CPP_INPRO)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Dll Debug"


"$(INTDIR)\inproc.obj"	"$(INTDIR)\inproc.sbr" : $(SOURCE) $(DEP_CPP_INPRO)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Dll Release"


"$(INTDIR)\inproc.obj"	"$(INTDIR)\inproc.sbr" : $(SOURCE) $(DEP_CPP_INPRO)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Dll Debug"


"$(INTDIR)\inproc.obj"	"$(INTDIR)\inproc.sbr" : $(SOURCE) $(DEP_CPP_INPRO)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ENDIF 

SOURCE=.\inproc.def
SOURCE=.\inproc.odl

!IF  "$(CFG)" == "InProc - Win32 Release"


"$(OUTDIR)\inproc.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) /nologo /D "NDEBUG" /tlb "$(OUTDIR)\inproc.tlb" /mktyplib203 /win32\
 $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Debug"


"$(OUTDIR)\inproc.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) /nologo /D "_DEBUG" /tlb "$(OUTDIR)\inproc.tlb" /mktyplib203 /win32\
 $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Release"


"$(OUTDIR)\inproc.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) /nologo /D "NDEBUG" /tlb "$(OUTDIR)\inproc.tlb" /mktyplib203 /win32\
 $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Debug"


"$(OUTDIR)\inproc.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) /nologo /D "_DEBUG" /tlb "$(OUTDIR)\inproc.tlb" /mktyplib203 /win32\
 $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Dll Release"


"$(OUTDIR)\inproc.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) /nologo /D "NDEBUG" /tlb "$(OUTDIR)\inproc.tlb" /mktyplib203 /win32\
 $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Dll Debug"


"$(OUTDIR)\inproc.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) /nologo /D "_DEBUG" /tlb "$(OUTDIR)\inproc.tlb" /mktyplib203 /win32\
 $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Dll Release"


"$(OUTDIR)\inproc.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) /nologo /D "NDEBUG" /tlb "$(OUTDIR)\inproc.tlb" /mktyplib203 /win32\
 $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Dll Debug"


"$(OUTDIR)\inproc.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) /nologo /D "_DEBUG" /tlb "$(OUTDIR)\inproc.tlb" /mktyplib203 /win32\
 $(SOURCE)


!ENDIF 

SOURCE=.\inproc.rc
DEP_RSC_INPROC=\
	".\res\inproc.ico"\
	".\res\inproc.rc2"\
	

!IF  "$(CFG)" == "InProc - Win32 Release"


"$(INTDIR)\inproc.res" : $(SOURCE) $(DEP_RSC_INPROC) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\inproc.res" /i ".\Release" /d "NDEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Debug"


"$(INTDIR)\inproc.res" : $(SOURCE) $(DEP_RSC_INPROC) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\inproc.res" /i ".\Debug" /d "_DEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Release"


"$(INTDIR)\inproc.res" : $(SOURCE) $(DEP_RSC_INPROC) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\inproc.res" /i ".\UniRelease" /d "NDEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Debug"


"$(INTDIR)\inproc.res" : $(SOURCE) $(DEP_RSC_INPROC) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\inproc.res" /i ".\UniDebug" /d "_DEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Dll Release"


"$(INTDIR)\inproc.res" : $(SOURCE) $(DEP_RSC_INPROC) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\inproc.res" /i ".\DllRelease" /d "NDEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Dll Debug"


"$(INTDIR)\inproc.res" : $(SOURCE) $(DEP_RSC_INPROC) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\inproc.res" /i ".\DllDebug" /d "_DEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Dll Release"


"$(INTDIR)\inproc.res" : $(SOURCE) $(DEP_RSC_INPROC) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\inproc.res" /i ".\UniDllRelease" /d "NDEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Dll Debug"


"$(INTDIR)\inproc.res" : $(SOURCE) $(DEP_RSC_INPROC) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\inproc.res" /i ".\UniDllDebug" /d "_DEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ENDIF 

SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "InProc - Win32 Release"

DEP_CPP_STDAF=\
	".\stdafx.h"\
	"d:\msdev\include\zmouse.h"\
	

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\inproc.pch" : \
$(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
	$(CPP) /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS"\
 /D "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\inproc.pch" /Yc /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Debug"

DEP_CPP_STDAF=\
	".\stdafx.h"\
	"d:\msdev\include\zmouse.h"\
	

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\inproc.pch" : \
$(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /D "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\inproc.pch"\
 /Yc"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Release"

DEP_CPP_STDAF=\
	".\stdafx.h"\
	"d:\msdev\include\zmouse.h"\
	

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\inproc.pch" : \
$(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
	$(CPP) /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_UNICODE" /D "_MBCS" /D "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\inproc.pch"\
 /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Debug"

DEP_CPP_STDAF=\
	".\stdafx.h"\
	"d:\msdev\include\zmouse.h"\
	

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\inproc.pch" : \
$(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_UNICODE" /D "_MBCS" /D "_AFXDLL" /FR"$(INTDIR)\\"\
 /Fp"$(INTDIR)\inproc.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c\
 $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Dll Release"

DEP_CPP_STDAF=\
	".\stdafx.h"\
	"d:\msdev\include\zmouse.h"\
	

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\inproc.pch" : \
$(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
	$(CPP) /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_MBCS" /D "_WINDLL" /D "_AFXDLL" /FR"$(INTDIR)\\"\
 /Fp"$(INTDIR)\inproc.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c\
 $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Dll Debug"

DEP_CPP_STDAF=\
	".\stdafx.h"\
	"d:\msdev\include\zmouse.h"\
	

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\inproc.pch" : \
$(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_USRDLL" /D "_MBCS" /D "_WINDLL" /D "_AFXDLL" /FR"$(INTDIR)\\"\
 /Fp"$(INTDIR)\inproc.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c\
 $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Dll Release"

DEP_CPP_STDAF=\
	".\stdafx.h"\
	"d:\msdev\include\zmouse.h"\
	

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\inproc.pch" : \
$(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
	$(CPP) /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_UNICODE" /D "_USRDLL" /D "_MBCS" /D "_WINDLL" /D "_AFXDLL" /FR"$(INTDIR)\\"\
 /Fp"$(INTDIR)\inproc.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c\
 $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Dll Debug"

DEP_CPP_STDAF=\
	".\stdafx.h"\
	"d:\msdev\include\zmouse.h"\
	

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\inproc.pch" : \
$(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_UNICODE" /D "_USRDLL" /D "_MBCS" /D "_WINDLL" /D "_AFXDLL"\
 /FR"$(INTDIR)\\" /Fp"$(INTDIR)\inproc.pch" /Yc /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ENDIF 

SOURCE=.\strcoll.cpp

!IF  "$(CFG)" == "InProc - Win32 Release"

DEP_CPP_STRCO=\
	".\enumvar.h"\
	".\inproc.h"\
	".\strcoll.h"\
	

"$(INTDIR)\strcoll.obj"	"$(INTDIR)\strcoll.sbr" : $(SOURCE) $(DEP_CPP_STRCO)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Debug"

DEP_CPP_STRCO=\
	".\enumvar.h"\
	".\inproc.h"\
	".\strcoll.h"\
	

"$(INTDIR)\strcoll.obj"	"$(INTDIR)\strcoll.sbr" : $(SOURCE) $(DEP_CPP_STRCO)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Release"

DEP_CPP_STRCO=\
	".\enumvar.h"\
	".\inproc.h"\
	".\strcoll.h"\
	

"$(INTDIR)\strcoll.obj"	"$(INTDIR)\strcoll.sbr" : $(SOURCE) $(DEP_CPP_STRCO)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Debug"

DEP_CPP_STRCO=\
	".\enumvar.h"\
	".\inproc.h"\
	".\strcoll.h"\
	

"$(INTDIR)\strcoll.obj"	"$(INTDIR)\strcoll.sbr" : $(SOURCE) $(DEP_CPP_STRCO)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Dll Release"

DEP_CPP_STRCO=\
	".\enumvar.h"\
	".\inproc.h"\
	".\strcoll.h"\
	

"$(INTDIR)\strcoll.obj"	"$(INTDIR)\strcoll.sbr" : $(SOURCE) $(DEP_CPP_STRCO)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Dll Debug"

DEP_CPP_STRCO=\
	".\enumvar.h"\
	".\inproc.h"\
	".\strcoll.h"\
	

"$(INTDIR)\strcoll.obj"	"$(INTDIR)\strcoll.sbr" : $(SOURCE) $(DEP_CPP_STRCO)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Dll Release"

DEP_CPP_STRCO=\
	".\enumvar.h"\
	".\inproc.h"\
	".\strcoll.h"\
	

"$(INTDIR)\strcoll.obj"	"$(INTDIR)\strcoll.sbr" : $(SOURCE) $(DEP_CPP_STRCO)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Dll Debug"

DEP_CPP_STRCO=\
	".\enumvar.h"\
	".\inproc.h"\
	".\strcoll.h"\
	

"$(INTDIR)\strcoll.obj"	"$(INTDIR)\strcoll.sbr" : $(SOURCE) $(DEP_CPP_STRCO)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ENDIF 

SOURCE=.\varassoc.cpp

!IF  "$(CFG)" == "InProc - Win32 Release"

DEP_CPP_VARAS=\
	".\inproc.h"\
	".\varassoc.h"\
	

"$(INTDIR)\varassoc.obj"	"$(INTDIR)\varassoc.sbr" : $(SOURCE) $(DEP_CPP_VARAS)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Debug"

DEP_CPP_VARAS=\
	".\inproc.h"\
	".\varassoc.h"\
	

"$(INTDIR)\varassoc.obj"	"$(INTDIR)\varassoc.sbr" : $(SOURCE) $(DEP_CPP_VARAS)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Release"

DEP_CPP_VARAS=\
	".\inproc.h"\
	".\varassoc.h"\
	

"$(INTDIR)\varassoc.obj"	"$(INTDIR)\varassoc.sbr" : $(SOURCE) $(DEP_CPP_VARAS)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Debug"

DEP_CPP_VARAS=\
	".\inproc.h"\
	".\varassoc.h"\
	

"$(INTDIR)\varassoc.obj"	"$(INTDIR)\varassoc.sbr" : $(SOURCE) $(DEP_CPP_VARAS)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Dll Release"

DEP_CPP_VARAS=\
	".\inproc.h"\
	".\varassoc.h"\
	

"$(INTDIR)\varassoc.obj"	"$(INTDIR)\varassoc.sbr" : $(SOURCE) $(DEP_CPP_VARAS)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Dll Debug"

DEP_CPP_VARAS=\
	".\inproc.h"\
	".\varassoc.h"\
	

"$(INTDIR)\varassoc.obj"	"$(INTDIR)\varassoc.sbr" : $(SOURCE) $(DEP_CPP_VARAS)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Dll Release"

DEP_CPP_VARAS=\
	".\inproc.h"\
	".\varassoc.h"\
	

"$(INTDIR)\varassoc.obj"	"$(INTDIR)\varassoc.sbr" : $(SOURCE) $(DEP_CPP_VARAS)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Dll Debug"

DEP_CPP_VARAS=\
	".\inproc.h"\
	".\varassoc.h"\
	

"$(INTDIR)\varassoc.obj"	"$(INTDIR)\varassoc.sbr" : $(SOURCE) $(DEP_CPP_VARAS)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ENDIF 

SOURCE=.\varmap.cpp

!IF  "$(CFG)" == "InProc - Win32 Release"

DEP_CPP_VARMA=\
	".\enumvar.h"\
	".\inproc.h"\
	".\varassoc.h"\
	".\varmap.h"\
	

"$(INTDIR)\varmap.obj"	"$(INTDIR)\varmap.sbr" : $(SOURCE) $(DEP_CPP_VARMA)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Debug"

DEP_CPP_VARMA=\
	".\enumvar.h"\
	".\inproc.h"\
	".\varassoc.h"\
	".\varmap.h"\
	

"$(INTDIR)\varmap.obj"	"$(INTDIR)\varmap.sbr" : $(SOURCE) $(DEP_CPP_VARMA)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Release"

DEP_CPP_VARMA=\
	".\enumvar.h"\
	".\inproc.h"\
	".\varassoc.h"\
	".\varmap.h"\
	

"$(INTDIR)\varmap.obj"	"$(INTDIR)\varmap.sbr" : $(SOURCE) $(DEP_CPP_VARMA)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Debug"

DEP_CPP_VARMA=\
	".\enumvar.h"\
	".\inproc.h"\
	".\varassoc.h"\
	".\varmap.h"\
	

"$(INTDIR)\varmap.obj"	"$(INTDIR)\varmap.sbr" : $(SOURCE) $(DEP_CPP_VARMA)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Dll Release"

DEP_CPP_VARMA=\
	".\enumvar.h"\
	".\inproc.h"\
	".\varassoc.h"\
	".\varmap.h"\
	

"$(INTDIR)\varmap.obj"	"$(INTDIR)\varmap.sbr" : $(SOURCE) $(DEP_CPP_VARMA)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Dll Debug"

DEP_CPP_VARMA=\
	".\enumvar.h"\
	".\inproc.h"\
	".\varassoc.h"\
	".\varmap.h"\
	

"$(INTDIR)\varmap.obj"	"$(INTDIR)\varmap.sbr" : $(SOURCE) $(DEP_CPP_VARMA)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Dll Release"

DEP_CPP_VARMA=\
	".\enumvar.h"\
	".\inproc.h"\
	".\varassoc.h"\
	".\varmap.h"\
	

"$(INTDIR)\varmap.obj"	"$(INTDIR)\varmap.sbr" : $(SOURCE) $(DEP_CPP_VARMA)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Dll Debug"

DEP_CPP_VARMA=\
	".\enumvar.h"\
	".\inproc.h"\
	".\varassoc.h"\
	".\varmap.h"\
	

"$(INTDIR)\varmap.obj"	"$(INTDIR)\varmap.sbr" : $(SOURCE) $(DEP_CPP_VARMA)\
 "$(INTDIR)" "$(INTDIR)\inproc.pch"


!ENDIF 

SOURCE=.\enumvar.h
SOURCE=.\inproc.h
SOURCE=.\resource.h
SOURCE=.\stdafx.h
SOURCE=.\strcoll.h
SOURCE=.\varassoc.h
SOURCE=.\varmap.h
SOURCE=.\res\inproc.ico
SOURCE=.\res\inproc.rc2

!ENDIF 

