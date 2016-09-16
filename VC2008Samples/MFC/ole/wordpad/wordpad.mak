# Microsoft Developer Studio Generated NMAKE File, Based on wordpad.dsp
!IF "$(CFG)" == ""
CFG=WordPad - Win32 Release
!MESSAGE No configuration specified. Defaulting to WordPad - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "WordPad - Win32 Release" && "$(CFG)" != "WordPad - Win32 Debug" && "$(CFG)" != "WordPad - Win32 Unicode Release" && "$(CFG)" != "WordPad - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "wordpad.mak" CFG="WordPad - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "WordPad - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "WordPad - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "WordPad - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "WordPad - Win32 Unicode Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "WordPad - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\wordpad.exe" "$(OUTDIR)\wordpad.bsc"


CLEAN :
	-@erase "$(INTDIR)\buttondi.obj"
	-@erase "$(INTDIR)\buttondi.sbr"
	-@erase "$(INTDIR)\chicdial.obj"
	-@erase "$(INTDIR)\chicdial.sbr"
	-@erase "$(INTDIR)\cntritem.obj"
	-@erase "$(INTDIR)\cntritem.sbr"
	-@erase "$(INTDIR)\colorlis.obj"
	-@erase "$(INTDIR)\colorlis.sbr"
	-@erase "$(INTDIR)\datedial.obj"
	-@erase "$(INTDIR)\datedial.sbr"
	-@erase "$(INTDIR)\ddxm.obj"
	-@erase "$(INTDIR)\ddxm.sbr"
	-@erase "$(INTDIR)\docopt.obj"
	-@erase "$(INTDIR)\docopt.sbr"
	-@erase "$(INTDIR)\doctype.obj"
	-@erase "$(INTDIR)\doctype.sbr"
	-@erase "$(INTDIR)\filenewd.obj"
	-@erase "$(INTDIR)\filenewd.sbr"
	-@erase "$(INTDIR)\formatba.obj"
	-@erase "$(INTDIR)\formatba.sbr"
	-@erase "$(INTDIR)\formatpa.obj"
	-@erase "$(INTDIR)\formatpa.sbr"
	-@erase "$(INTDIR)\formatta.obj"
	-@erase "$(INTDIR)\formatta.sbr"
	-@erase "$(INTDIR)\ipframe.obj"
	-@erase "$(INTDIR)\ipframe.sbr"
	-@erase "$(INTDIR)\key.obj"
	-@erase "$(INTDIR)\key.sbr"
	-@erase "$(INTDIR)\listdlg.obj"
	-@erase "$(INTDIR)\listdlg.sbr"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\mainfrm.sbr"
	-@erase "$(INTDIR)\multconv.obj"
	-@erase "$(INTDIR)\multconv.sbr"
	-@erase "$(INTDIR)\options.obj"
	-@erase "$(INTDIR)\options.sbr"
	-@erase "$(INTDIR)\optionsh.obj"
	-@erase "$(INTDIR)\optionsh.sbr"
	-@erase "$(INTDIR)\pageset.obj"
	-@erase "$(INTDIR)\pageset.sbr"
	-@erase "$(INTDIR)\ruler.obj"
	-@erase "$(INTDIR)\ruler.sbr"
	-@erase "$(INTDIR)\splash.obj"
	-@erase "$(INTDIR)\splash.sbr"
	-@erase "$(INTDIR)\srvritem.obj"
	-@erase "$(INTDIR)\srvritem.sbr"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\stdafx.sbr"
	-@erase "$(INTDIR)\strings.obj"
	-@erase "$(INTDIR)\strings.sbr"
	-@erase "$(INTDIR)\unitspag.obj"
	-@erase "$(INTDIR)\unitspag.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\wordpad.obj"
	-@erase "$(INTDIR)\wordpad.pch"
	-@erase "$(INTDIR)\wordpad.res"
	-@erase "$(INTDIR)\wordpad.sbr"
	-@erase "$(INTDIR)\wordpdoc.obj"
	-@erase "$(INTDIR)\wordpdoc.sbr"
	-@erase "$(INTDIR)\wordpvw.obj"
	-@erase "$(INTDIR)\wordpvw.sbr"
	-@erase "$(OUTDIR)\wordpad.bsc"
	-@erase "$(OUTDIR)\wordpad.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/Zc:wchar_t /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\wordpad.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\wordpad.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\wordpad.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\buttondi.sbr" \
	"$(INTDIR)\chicdial.sbr" \
	"$(INTDIR)\cntritem.sbr" \
	"$(INTDIR)\colorlis.sbr" \
	"$(INTDIR)\datedial.sbr" \
	"$(INTDIR)\ddxm.sbr" \
	"$(INTDIR)\docopt.sbr" \
	"$(INTDIR)\doctype.sbr" \
	"$(INTDIR)\filenewd.sbr" \
	"$(INTDIR)\formatba.sbr" \
	"$(INTDIR)\formatpa.sbr" \
	"$(INTDIR)\formatta.sbr" \
	"$(INTDIR)\ipframe.sbr" \
	"$(INTDIR)\key.sbr" \
	"$(INTDIR)\listdlg.sbr" \
	"$(INTDIR)\mainfrm.sbr" \
	"$(INTDIR)\multconv.sbr" \
	"$(INTDIR)\options.sbr" \
	"$(INTDIR)\optionsh.sbr" \
	"$(INTDIR)\pageset.sbr" \
	"$(INTDIR)\ruler.sbr" \
	"$(INTDIR)\splash.sbr" \
	"$(INTDIR)\srvritem.sbr" \
	"$(INTDIR)\stdafx.sbr" \
	"$(INTDIR)\strings.sbr" \
	"$(INTDIR)\unitspag.sbr" \
	"$(INTDIR)\wordpad.sbr" \
	"$(INTDIR)\wordpdoc.sbr" \
	"$(INTDIR)\wordpvw.sbr"

"$(OUTDIR)\wordpad.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\wordpad.pdb" /machine:I386 /out:"$(OUTDIR)\wordpad.exe" 
LINK32_OBJS= \
	"$(INTDIR)\buttondi.obj" \
	"$(INTDIR)\chicdial.obj" \
	"$(INTDIR)\cntritem.obj" \
	"$(INTDIR)\colorlis.obj" \
	"$(INTDIR)\datedial.obj" \
	"$(INTDIR)\ddxm.obj" \
	"$(INTDIR)\docopt.obj" \
	"$(INTDIR)\doctype.obj" \
	"$(INTDIR)\filenewd.obj" \
	"$(INTDIR)\formatba.obj" \
	"$(INTDIR)\formatpa.obj" \
	"$(INTDIR)\formatta.obj" \
	"$(INTDIR)\ipframe.obj" \
	"$(INTDIR)\key.obj" \
	"$(INTDIR)\listdlg.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\multconv.obj" \
	"$(INTDIR)\options.obj" \
	"$(INTDIR)\optionsh.obj" \
	"$(INTDIR)\pageset.obj" \
	"$(INTDIR)\ruler.obj" \
	"$(INTDIR)\splash.obj" \
	"$(INTDIR)\srvritem.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\strings.obj" \
	"$(INTDIR)\unitspag.obj" \
	"$(INTDIR)\wordpad.obj" \
	"$(INTDIR)\wordpdoc.obj" \
	"$(INTDIR)\wordpvw.obj" \
	"$(INTDIR)\wordpad.res"

"$(OUTDIR)\wordpad.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "WordPad - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\wordpad.exe" "$(OUTDIR)\wordpad.bsc"


CLEAN :
	-@erase "$(INTDIR)\buttondi.obj"
	-@erase "$(INTDIR)\buttondi.sbr"
	-@erase "$(INTDIR)\chicdial.obj"
	-@erase "$(INTDIR)\chicdial.sbr"
	-@erase "$(INTDIR)\cntritem.obj"
	-@erase "$(INTDIR)\cntritem.sbr"
	-@erase "$(INTDIR)\colorlis.obj"
	-@erase "$(INTDIR)\colorlis.sbr"
	-@erase "$(INTDIR)\datedial.obj"
	-@erase "$(INTDIR)\datedial.sbr"
	-@erase "$(INTDIR)\ddxm.obj"
	-@erase "$(INTDIR)\ddxm.sbr"
	-@erase "$(INTDIR)\docopt.obj"
	-@erase "$(INTDIR)\docopt.sbr"
	-@erase "$(INTDIR)\doctype.obj"
	-@erase "$(INTDIR)\doctype.sbr"
	-@erase "$(INTDIR)\filenewd.obj"
	-@erase "$(INTDIR)\filenewd.sbr"
	-@erase "$(INTDIR)\formatba.obj"
	-@erase "$(INTDIR)\formatba.sbr"
	-@erase "$(INTDIR)\formatpa.obj"
	-@erase "$(INTDIR)\formatpa.sbr"
	-@erase "$(INTDIR)\formatta.obj"
	-@erase "$(INTDIR)\formatta.sbr"
	-@erase "$(INTDIR)\ipframe.obj"
	-@erase "$(INTDIR)\ipframe.sbr"
	-@erase "$(INTDIR)\key.obj"
	-@erase "$(INTDIR)\key.sbr"
	-@erase "$(INTDIR)\listdlg.obj"
	-@erase "$(INTDIR)\listdlg.sbr"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\mainfrm.sbr"
	-@erase "$(INTDIR)\multconv.obj"
	-@erase "$(INTDIR)\multconv.sbr"
	-@erase "$(INTDIR)\options.obj"
	-@erase "$(INTDIR)\options.sbr"
	-@erase "$(INTDIR)\optionsh.obj"
	-@erase "$(INTDIR)\optionsh.sbr"
	-@erase "$(INTDIR)\pageset.obj"
	-@erase "$(INTDIR)\pageset.sbr"
	-@erase "$(INTDIR)\ruler.obj"
	-@erase "$(INTDIR)\ruler.sbr"
	-@erase "$(INTDIR)\splash.obj"
	-@erase "$(INTDIR)\splash.sbr"
	-@erase "$(INTDIR)\srvritem.obj"
	-@erase "$(INTDIR)\srvritem.sbr"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\stdafx.sbr"
	-@erase "$(INTDIR)\strings.obj"
	-@erase "$(INTDIR)\strings.sbr"
	-@erase "$(INTDIR)\unitspag.obj"
	-@erase "$(INTDIR)\unitspag.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\wordpad.obj"
	-@erase "$(INTDIR)\wordpad.pch"
	-@erase "$(INTDIR)\wordpad.res"
	-@erase "$(INTDIR)\wordpad.sbr"
	-@erase "$(INTDIR)\wordpdoc.obj"
	-@erase "$(INTDIR)\wordpdoc.sbr"
	-@erase "$(INTDIR)\wordpvw.obj"
	-@erase "$(INTDIR)\wordpvw.sbr"
	-@erase "$(OUTDIR)\wordpad.bsc"
	-@erase "$(OUTDIR)\wordpad.exe"
	-@erase "$(OUTDIR)\wordpad.ilk"
	-@erase "$(OUTDIR)\wordpad.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/Zc:wchar_t /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\wordpad.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\wordpad.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\wordpad.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\buttondi.sbr" \
	"$(INTDIR)\chicdial.sbr" \
	"$(INTDIR)\cntritem.sbr" \
	"$(INTDIR)\colorlis.sbr" \
	"$(INTDIR)\datedial.sbr" \
	"$(INTDIR)\ddxm.sbr" \
	"$(INTDIR)\docopt.sbr" \
	"$(INTDIR)\doctype.sbr" \
	"$(INTDIR)\filenewd.sbr" \
	"$(INTDIR)\formatba.sbr" \
	"$(INTDIR)\formatpa.sbr" \
	"$(INTDIR)\formatta.sbr" \
	"$(INTDIR)\ipframe.sbr" \
	"$(INTDIR)\key.sbr" \
	"$(INTDIR)\listdlg.sbr" \
	"$(INTDIR)\mainfrm.sbr" \
	"$(INTDIR)\multconv.sbr" \
	"$(INTDIR)\options.sbr" \
	"$(INTDIR)\optionsh.sbr" \
	"$(INTDIR)\pageset.sbr" \
	"$(INTDIR)\ruler.sbr" \
	"$(INTDIR)\splash.sbr" \
	"$(INTDIR)\srvritem.sbr" \
	"$(INTDIR)\stdafx.sbr" \
	"$(INTDIR)\strings.sbr" \
	"$(INTDIR)\unitspag.sbr" \
	"$(INTDIR)\wordpad.sbr" \
	"$(INTDIR)\wordpdoc.sbr" \
	"$(INTDIR)\wordpvw.sbr"

"$(OUTDIR)\wordpad.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\wordpad.pdb" /debug /machine:I386 /out:"$(OUTDIR)\wordpad.exe" 
LINK32_OBJS= \
	"$(INTDIR)\buttondi.obj" \
	"$(INTDIR)\chicdial.obj" \
	"$(INTDIR)\cntritem.obj" \
	"$(INTDIR)\colorlis.obj" \
	"$(INTDIR)\datedial.obj" \
	"$(INTDIR)\ddxm.obj" \
	"$(INTDIR)\docopt.obj" \
	"$(INTDIR)\doctype.obj" \
	"$(INTDIR)\filenewd.obj" \
	"$(INTDIR)\formatba.obj" \
	"$(INTDIR)\formatpa.obj" \
	"$(INTDIR)\formatta.obj" \
	"$(INTDIR)\ipframe.obj" \
	"$(INTDIR)\key.obj" \
	"$(INTDIR)\listdlg.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\multconv.obj" \
	"$(INTDIR)\options.obj" \
	"$(INTDIR)\optionsh.obj" \
	"$(INTDIR)\pageset.obj" \
	"$(INTDIR)\ruler.obj" \
	"$(INTDIR)\splash.obj" \
	"$(INTDIR)\srvritem.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\strings.obj" \
	"$(INTDIR)\unitspag.obj" \
	"$(INTDIR)\wordpad.obj" \
	"$(INTDIR)\wordpdoc.obj" \
	"$(INTDIR)\wordpvw.obj" \
	"$(INTDIR)\wordpad.res"

"$(OUTDIR)\wordpad.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "WordPad - Win32 Unicode Release"

OUTDIR=.\UniRelease
INTDIR=.\UniRelease
# Begin Custom Macros
OutDir=.\.\UniRelease
# End Custom Macros

ALL : "$(OUTDIR)\wordpad.exe" "$(OUTDIR)\wordpad.bsc"


CLEAN :
	-@erase "$(INTDIR)\buttondi.obj"
	-@erase "$(INTDIR)\buttondi.sbr"
	-@erase "$(INTDIR)\chicdial.obj"
	-@erase "$(INTDIR)\chicdial.sbr"
	-@erase "$(INTDIR)\cntritem.obj"
	-@erase "$(INTDIR)\cntritem.sbr"
	-@erase "$(INTDIR)\colorlis.obj"
	-@erase "$(INTDIR)\colorlis.sbr"
	-@erase "$(INTDIR)\datedial.obj"
	-@erase "$(INTDIR)\datedial.sbr"
	-@erase "$(INTDIR)\ddxm.obj"
	-@erase "$(INTDIR)\ddxm.sbr"
	-@erase "$(INTDIR)\docopt.obj"
	-@erase "$(INTDIR)\docopt.sbr"
	-@erase "$(INTDIR)\doctype.obj"
	-@erase "$(INTDIR)\doctype.sbr"
	-@erase "$(INTDIR)\filenewd.obj"
	-@erase "$(INTDIR)\filenewd.sbr"
	-@erase "$(INTDIR)\formatba.obj"
	-@erase "$(INTDIR)\formatba.sbr"
	-@erase "$(INTDIR)\formatpa.obj"
	-@erase "$(INTDIR)\formatpa.sbr"
	-@erase "$(INTDIR)\formatta.obj"
	-@erase "$(INTDIR)\formatta.sbr"
	-@erase "$(INTDIR)\ipframe.obj"
	-@erase "$(INTDIR)\ipframe.sbr"
	-@erase "$(INTDIR)\key.obj"
	-@erase "$(INTDIR)\key.sbr"
	-@erase "$(INTDIR)\listdlg.obj"
	-@erase "$(INTDIR)\listdlg.sbr"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\mainfrm.sbr"
	-@erase "$(INTDIR)\multconv.obj"
	-@erase "$(INTDIR)\multconv.sbr"
	-@erase "$(INTDIR)\options.obj"
	-@erase "$(INTDIR)\options.sbr"
	-@erase "$(INTDIR)\optionsh.obj"
	-@erase "$(INTDIR)\optionsh.sbr"
	-@erase "$(INTDIR)\pageset.obj"
	-@erase "$(INTDIR)\pageset.sbr"
	-@erase "$(INTDIR)\ruler.obj"
	-@erase "$(INTDIR)\ruler.sbr"
	-@erase "$(INTDIR)\splash.obj"
	-@erase "$(INTDIR)\splash.sbr"
	-@erase "$(INTDIR)\srvritem.obj"
	-@erase "$(INTDIR)\srvritem.sbr"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\stdafx.sbr"
	-@erase "$(INTDIR)\strings.obj"
	-@erase "$(INTDIR)\strings.sbr"
	-@erase "$(INTDIR)\unitspag.obj"
	-@erase "$(INTDIR)\unitspag.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\wordpad.obj"
	-@erase "$(INTDIR)\wordpad.pch"
	-@erase "$(INTDIR)\wordpad.res"
	-@erase "$(INTDIR)\wordpad.sbr"
	-@erase "$(INTDIR)\wordpdoc.obj"
	-@erase "$(INTDIR)\wordpdoc.sbr"
	-@erase "$(INTDIR)\wordpvw.obj"
	-@erase "$(INTDIR)\wordpvw.sbr"
	-@erase "$(OUTDIR)\wordpad.bsc"
	-@erase "$(OUTDIR)\wordpad.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/Zc:wchar_t /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D "_UNICODE" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\wordpad.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\wordpad.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\wordpad.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\buttondi.sbr" \
	"$(INTDIR)\chicdial.sbr" \
	"$(INTDIR)\cntritem.sbr" \
	"$(INTDIR)\colorlis.sbr" \
	"$(INTDIR)\datedial.sbr" \
	"$(INTDIR)\ddxm.sbr" \
	"$(INTDIR)\docopt.sbr" \
	"$(INTDIR)\doctype.sbr" \
	"$(INTDIR)\filenewd.sbr" \
	"$(INTDIR)\formatba.sbr" \
	"$(INTDIR)\formatpa.sbr" \
	"$(INTDIR)\formatta.sbr" \
	"$(INTDIR)\ipframe.sbr" \
	"$(INTDIR)\key.sbr" \
	"$(INTDIR)\listdlg.sbr" \
	"$(INTDIR)\mainfrm.sbr" \
	"$(INTDIR)\multconv.sbr" \
	"$(INTDIR)\options.sbr" \
	"$(INTDIR)\optionsh.sbr" \
	"$(INTDIR)\pageset.sbr" \
	"$(INTDIR)\ruler.sbr" \
	"$(INTDIR)\splash.sbr" \
	"$(INTDIR)\srvritem.sbr" \
	"$(INTDIR)\stdafx.sbr" \
	"$(INTDIR)\strings.sbr" \
	"$(INTDIR)\unitspag.sbr" \
	"$(INTDIR)\wordpad.sbr" \
	"$(INTDIR)\wordpdoc.sbr" \
	"$(INTDIR)\wordpvw.sbr"

"$(OUTDIR)\wordpad.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\wordpad.pdb" /machine:I386 /out:"$(OUTDIR)\wordpad.exe" 
LINK32_OBJS= \
	"$(INTDIR)\buttondi.obj" \
	"$(INTDIR)\chicdial.obj" \
	"$(INTDIR)\cntritem.obj" \
	"$(INTDIR)\colorlis.obj" \
	"$(INTDIR)\datedial.obj" \
	"$(INTDIR)\ddxm.obj" \
	"$(INTDIR)\docopt.obj" \
	"$(INTDIR)\doctype.obj" \
	"$(INTDIR)\filenewd.obj" \
	"$(INTDIR)\formatba.obj" \
	"$(INTDIR)\formatpa.obj" \
	"$(INTDIR)\formatta.obj" \
	"$(INTDIR)\ipframe.obj" \
	"$(INTDIR)\key.obj" \
	"$(INTDIR)\listdlg.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\multconv.obj" \
	"$(INTDIR)\options.obj" \
	"$(INTDIR)\optionsh.obj" \
	"$(INTDIR)\pageset.obj" \
	"$(INTDIR)\ruler.obj" \
	"$(INTDIR)\splash.obj" \
	"$(INTDIR)\srvritem.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\strings.obj" \
	"$(INTDIR)\unitspag.obj" \
	"$(INTDIR)\wordpad.obj" \
	"$(INTDIR)\wordpdoc.obj" \
	"$(INTDIR)\wordpvw.obj" \
	"$(INTDIR)\wordpad.res"

"$(OUTDIR)\wordpad.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "WordPad - Win32 Unicode Debug"

OUTDIR=.\UniDebug
INTDIR=.\UniDebug
# Begin Custom Macros
OutDir=.\.\UniDebug
# End Custom Macros

ALL : "$(OUTDIR)\wordpad.exe" "$(OUTDIR)\wordpad.bsc"


CLEAN :
	-@erase "$(INTDIR)\buttondi.obj"
	-@erase "$(INTDIR)\buttondi.sbr"
	-@erase "$(INTDIR)\chicdial.obj"
	-@erase "$(INTDIR)\chicdial.sbr"
	-@erase "$(INTDIR)\cntritem.obj"
	-@erase "$(INTDIR)\cntritem.sbr"
	-@erase "$(INTDIR)\colorlis.obj"
	-@erase "$(INTDIR)\colorlis.sbr"
	-@erase "$(INTDIR)\datedial.obj"
	-@erase "$(INTDIR)\datedial.sbr"
	-@erase "$(INTDIR)\ddxm.obj"
	-@erase "$(INTDIR)\ddxm.sbr"
	-@erase "$(INTDIR)\docopt.obj"
	-@erase "$(INTDIR)\docopt.sbr"
	-@erase "$(INTDIR)\doctype.obj"
	-@erase "$(INTDIR)\doctype.sbr"
	-@erase "$(INTDIR)\filenewd.obj"
	-@erase "$(INTDIR)\filenewd.sbr"
	-@erase "$(INTDIR)\formatba.obj"
	-@erase "$(INTDIR)\formatba.sbr"
	-@erase "$(INTDIR)\formatpa.obj"
	-@erase "$(INTDIR)\formatpa.sbr"
	-@erase "$(INTDIR)\formatta.obj"
	-@erase "$(INTDIR)\formatta.sbr"
	-@erase "$(INTDIR)\ipframe.obj"
	-@erase "$(INTDIR)\ipframe.sbr"
	-@erase "$(INTDIR)\key.obj"
	-@erase "$(INTDIR)\key.sbr"
	-@erase "$(INTDIR)\listdlg.obj"
	-@erase "$(INTDIR)\listdlg.sbr"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\mainfrm.sbr"
	-@erase "$(INTDIR)\multconv.obj"
	-@erase "$(INTDIR)\multconv.sbr"
	-@erase "$(INTDIR)\options.obj"
	-@erase "$(INTDIR)\options.sbr"
	-@erase "$(INTDIR)\optionsh.obj"
	-@erase "$(INTDIR)\optionsh.sbr"
	-@erase "$(INTDIR)\pageset.obj"
	-@erase "$(INTDIR)\pageset.sbr"
	-@erase "$(INTDIR)\ruler.obj"
	-@erase "$(INTDIR)\ruler.sbr"
	-@erase "$(INTDIR)\splash.obj"
	-@erase "$(INTDIR)\splash.sbr"
	-@erase "$(INTDIR)\srvritem.obj"
	-@erase "$(INTDIR)\srvritem.sbr"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\stdafx.sbr"
	-@erase "$(INTDIR)\strings.obj"
	-@erase "$(INTDIR)\strings.sbr"
	-@erase "$(INTDIR)\unitspag.obj"
	-@erase "$(INTDIR)\unitspag.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\wordpad.obj"
	-@erase "$(INTDIR)\wordpad.pch"
	-@erase "$(INTDIR)\wordpad.res"
	-@erase "$(INTDIR)\wordpad.sbr"
	-@erase "$(INTDIR)\wordpdoc.obj"
	-@erase "$(INTDIR)\wordpdoc.sbr"
	-@erase "$(INTDIR)\wordpvw.obj"
	-@erase "$(INTDIR)\wordpvw.sbr"
	-@erase "$(OUTDIR)\wordpad.bsc"
	-@erase "$(OUTDIR)\wordpad.exe"
	-@erase "$(OUTDIR)\wordpad.ilk"
	-@erase "$(OUTDIR)\wordpad.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/Zc:wchar_t /nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D "_UNICODE" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\wordpad.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\wordpad.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\wordpad.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\buttondi.sbr" \
	"$(INTDIR)\chicdial.sbr" \
	"$(INTDIR)\cntritem.sbr" \
	"$(INTDIR)\colorlis.sbr" \
	"$(INTDIR)\datedial.sbr" \
	"$(INTDIR)\ddxm.sbr" \
	"$(INTDIR)\docopt.sbr" \
	"$(INTDIR)\doctype.sbr" \
	"$(INTDIR)\filenewd.sbr" \
	"$(INTDIR)\formatba.sbr" \
	"$(INTDIR)\formatpa.sbr" \
	"$(INTDIR)\formatta.sbr" \
	"$(INTDIR)\ipframe.sbr" \
	"$(INTDIR)\key.sbr" \
	"$(INTDIR)\listdlg.sbr" \
	"$(INTDIR)\mainfrm.sbr" \
	"$(INTDIR)\multconv.sbr" \
	"$(INTDIR)\options.sbr" \
	"$(INTDIR)\optionsh.sbr" \
	"$(INTDIR)\pageset.sbr" \
	"$(INTDIR)\ruler.sbr" \
	"$(INTDIR)\splash.sbr" \
	"$(INTDIR)\srvritem.sbr" \
	"$(INTDIR)\stdafx.sbr" \
	"$(INTDIR)\strings.sbr" \
	"$(INTDIR)\unitspag.sbr" \
	"$(INTDIR)\wordpad.sbr" \
	"$(INTDIR)\wordpdoc.sbr" \
	"$(INTDIR)\wordpvw.sbr"

"$(OUTDIR)\wordpad.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\wordpad.pdb" /debug /machine:I386 /out:"$(OUTDIR)\wordpad.exe" 
LINK32_OBJS= \
	"$(INTDIR)\buttondi.obj" \
	"$(INTDIR)\chicdial.obj" \
	"$(INTDIR)\cntritem.obj" \
	"$(INTDIR)\colorlis.obj" \
	"$(INTDIR)\datedial.obj" \
	"$(INTDIR)\ddxm.obj" \
	"$(INTDIR)\docopt.obj" \
	"$(INTDIR)\doctype.obj" \
	"$(INTDIR)\filenewd.obj" \
	"$(INTDIR)\formatba.obj" \
	"$(INTDIR)\formatpa.obj" \
	"$(INTDIR)\formatta.obj" \
	"$(INTDIR)\ipframe.obj" \
	"$(INTDIR)\key.obj" \
	"$(INTDIR)\listdlg.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\multconv.obj" \
	"$(INTDIR)\options.obj" \
	"$(INTDIR)\optionsh.obj" \
	"$(INTDIR)\pageset.obj" \
	"$(INTDIR)\ruler.obj" \
	"$(INTDIR)\splash.obj" \
	"$(INTDIR)\srvritem.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\strings.obj" \
	"$(INTDIR)\unitspag.obj" \
	"$(INTDIR)\wordpad.obj" \
	"$(INTDIR)\wordpdoc.obj" \
	"$(INTDIR)\wordpvw.obj" \
	"$(INTDIR)\wordpad.res"

"$(OUTDIR)\wordpad.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("wordpad.dep")
!INCLUDE "wordpad.dep"
!ELSE 
!MESSAGE Warning: cannot find "wordpad.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "WordPad - Win32 Release" || "$(CFG)" == "WordPad - Win32 Debug" || "$(CFG)" == "WordPad - Win32 Unicode Release" || "$(CFG)" == "WordPad - Win32 Unicode Debug"
SOURCE=.\buttondi.cpp

"$(INTDIR)\buttondi.obj"	"$(INTDIR)\buttondi.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\chicdial.cpp

"$(INTDIR)\chicdial.obj"	"$(INTDIR)\chicdial.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\cntritem.cpp

"$(INTDIR)\cntritem.obj"	"$(INTDIR)\cntritem.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\colorlis.cpp

"$(INTDIR)\colorlis.obj"	"$(INTDIR)\colorlis.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\datedial.cpp

"$(INTDIR)\datedial.obj"	"$(INTDIR)\datedial.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\ddxm.cpp

"$(INTDIR)\ddxm.obj"	"$(INTDIR)\ddxm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\docopt.cpp

"$(INTDIR)\docopt.obj"	"$(INTDIR)\docopt.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\doctype.cpp

"$(INTDIR)\doctype.obj"	"$(INTDIR)\doctype.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\filenewd.cpp

"$(INTDIR)\filenewd.obj"	"$(INTDIR)\filenewd.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\formatba.cpp

"$(INTDIR)\formatba.obj"	"$(INTDIR)\formatba.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\formatpa.cpp

"$(INTDIR)\formatpa.obj"	"$(INTDIR)\formatpa.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\formatta.cpp

"$(INTDIR)\formatta.obj"	"$(INTDIR)\formatta.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\ipframe.cpp

"$(INTDIR)\ipframe.obj"	"$(INTDIR)\ipframe.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\key.cpp

"$(INTDIR)\key.obj"	"$(INTDIR)\key.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\listdlg.cpp

"$(INTDIR)\listdlg.obj"	"$(INTDIR)\listdlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\mainfrm.cpp

"$(INTDIR)\mainfrm.obj"	"$(INTDIR)\mainfrm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\multconv.cpp

"$(INTDIR)\multconv.obj"	"$(INTDIR)\multconv.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\options.cpp

"$(INTDIR)\options.obj"	"$(INTDIR)\options.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\optionsh.cpp

"$(INTDIR)\optionsh.obj"	"$(INTDIR)\optionsh.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\pageset.cpp

"$(INTDIR)\pageset.obj"	"$(INTDIR)\pageset.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\ruler.cpp

"$(INTDIR)\ruler.obj"	"$(INTDIR)\ruler.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\splash.cpp

"$(INTDIR)\splash.obj"	"$(INTDIR)\splash.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\srvritem.cpp

"$(INTDIR)\srvritem.obj"	"$(INTDIR)\srvritem.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "WordPad - Win32 Release"

CPP_SWITCHES=/Zc:wchar_t /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\wordpad.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\wordpad.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "WordPad - Win32 Debug"

CPP_SWITCHES=/Zc:wchar_t /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\wordpad.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\wordpad.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "WordPad - Win32 Unicode Release"

CPP_SWITCHES=/Zc:wchar_t /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D "_UNICODE" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\wordpad.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\wordpad.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "WordPad - Win32 Unicode Debug"

CPP_SWITCHES=/Zc:wchar_t /nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D "_UNICODE" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\wordpad.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\wordpad.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\strings.cpp

"$(INTDIR)\strings.obj"	"$(INTDIR)\strings.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\unitspag.cpp

"$(INTDIR)\unitspag.obj"	"$(INTDIR)\unitspag.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\wordpad.cpp

"$(INTDIR)\wordpad.obj"	"$(INTDIR)\wordpad.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\wordpad.rc

"$(INTDIR)\wordpad.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\wordpdoc.cpp

"$(INTDIR)\wordpdoc.obj"	"$(INTDIR)\wordpdoc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"


SOURCE=.\wordpvw.cpp

"$(INTDIR)\wordpvw.obj"	"$(INTDIR)\wordpvw.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wordpad.pch"



!ENDIF 

