# Microsoft Developer Studio Generated NMAKE File, Based on inproc.dsp
!IF "$(CFG)" == ""
CFG=InProc - Win32 Release
!MESSAGE No configuration specified. Defaulting to InProc - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "InProc - Win32 Release" && "$(CFG)" != "InProc - Win32 Debug" && "$(CFG)" != "InProc - Win32 Unicode Release" && "$(CFG)" != "InProc - Win32 Unicode Debug" && "$(CFG)" != "InProc - Win32 Dll Release" && "$(CFG)" != "InProc - Win32 Dll Debug" && "$(CFG)" != "InProc - Win32 Unicode Dll Release" && "$(CFG)" != "InProc - Win32 Unicode Dll Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "inproc.mak" CFG="InProc - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "InProc - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "InProc - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "InProc - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "InProc - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE "InProc - Win32 Dll Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "InProc - Win32 Dll Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "InProc - Win32 Unicode Dll Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "InProc - Win32 Unicode Dll Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "InProc - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
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
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\inproc.bsc"
	-@erase "$(OUTDIR)\inproc.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\inproc.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
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
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\inproc.pdb" /machine:I386 /out:"$(OUTDIR)\inproc.exe" 
LINK32_OBJS= \
	"$(INTDIR)\enumvar.obj" \
	"$(INTDIR)\inproc.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\strcoll.obj" \
	"$(INTDIR)\varassoc.obj" \
	"$(INTDIR)\varmap.obj" \
	"$(INTDIR)\inproc.res"

"$(OUTDIR)\inproc.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "InProc - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
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
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\inproc.bsc"
	-@erase "$(OUTDIR)\inproc.exe"
	-@erase "$(OUTDIR)\inproc.ilk"
	-@erase "$(OUTDIR)\inproc.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\inproc.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
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
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\inproc.pdb" /debug /machine:I386 /out:"$(OUTDIR)\inproc.exe" 
LINK32_OBJS= \
	"$(INTDIR)\enumvar.obj" \
	"$(INTDIR)\inproc.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\strcoll.obj" \
	"$(INTDIR)\varassoc.obj" \
	"$(INTDIR)\varmap.obj" \
	"$(INTDIR)\inproc.res"

"$(OUTDIR)\inproc.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Release"

OUTDIR=.\UniRelease
INTDIR=.\UniRelease
# Begin Custom Macros
OutDir=.\UniRelease
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
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\inproc.bsc"
	-@erase "$(OUTDIR)\inproc.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\inproc.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
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
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\inproc.pdb" /machine:I386 /out:"$(OUTDIR)\inproc.exe" 
LINK32_OBJS= \
	"$(INTDIR)\enumvar.obj" \
	"$(INTDIR)\inproc.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\strcoll.obj" \
	"$(INTDIR)\varassoc.obj" \
	"$(INTDIR)\varmap.obj" \
	"$(INTDIR)\inproc.res"

"$(OUTDIR)\inproc.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Debug"

OUTDIR=.\UniDebug
INTDIR=.\UniDebug
# Begin Custom Macros
OutDir=.\UniDebug
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
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\inproc.bsc"
	-@erase "$(OUTDIR)\inproc.exe"
	-@erase "$(OUTDIR)\inproc.ilk"
	-@erase "$(OUTDIR)\inproc.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\inproc.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
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
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\inproc.pdb" /debug /machine:I386 /out:"$(OUTDIR)\inproc.exe" 
LINK32_OBJS= \
	"$(INTDIR)\enumvar.obj" \
	"$(INTDIR)\inproc.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\strcoll.obj" \
	"$(INTDIR)\varassoc.obj" \
	"$(INTDIR)\varmap.obj" \
	"$(INTDIR)\inproc.res"

"$(OUTDIR)\inproc.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "InProc - Win32 Dll Release"

OUTDIR=.\DllRelease
INTDIR=.\DllRelease
# Begin Custom Macros
OutDir=.\DllRelease
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
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\inproc.bsc"
	-@erase "$(OUTDIR)\inproc.dll"
	-@erase "$(OUTDIR)\inproc.exp"
	-@erase "$(OUTDIR)\inproc.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_WINDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\inproc.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\inproc.res" /d "NDEBUG" 
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
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\inproc.pdb" /machine:I386 /def:".\inproc.def" /out:"$(OUTDIR)\inproc.dll" /implib:"$(OUTDIR)\inproc.lib" 
DEF_FILE= \
	".\inproc.def"
LINK32_OBJS= \
	"$(INTDIR)\enumvar.obj" \
	"$(INTDIR)\inproc.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\strcoll.obj" \
	"$(INTDIR)\varassoc.obj" \
	"$(INTDIR)\varmap.obj" \
	"$(INTDIR)\inproc.res"

"$(OUTDIR)\inproc.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "InProc - Win32 Dll Debug"

OUTDIR=.\DllDebug
INTDIR=.\DllDebug
# Begin Custom Macros
OutDir=.\DllDebug
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
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\inproc.bsc"
	-@erase "$(OUTDIR)\inproc.dll"
	-@erase "$(OUTDIR)\inproc.exp"
	-@erase "$(OUTDIR)\inproc.ilk"
	-@erase "$(OUTDIR)\inproc.lib"
	-@erase "$(OUTDIR)\inproc.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_WINDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\inproc.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\inproc.res" /d "_DEBUG" 
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
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\inproc.pdb" /debug /machine:I386 /def:".\inproc.def" /out:"$(OUTDIR)\inproc.dll" /implib:"$(OUTDIR)\inproc.lib" 
DEF_FILE= \
	".\inproc.def"
LINK32_OBJS= \
	"$(INTDIR)\enumvar.obj" \
	"$(INTDIR)\inproc.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\strcoll.obj" \
	"$(INTDIR)\varassoc.obj" \
	"$(INTDIR)\varmap.obj" \
	"$(INTDIR)\inproc.res"

"$(OUTDIR)\inproc.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Dll Release"

OUTDIR=.\UniDllRelease
INTDIR=.\UniDllRelease
# Begin Custom Macros
OutDir=.\UniDllRelease
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
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\inproc.bsc"
	-@erase "$(OUTDIR)\inproc.dll"
	-@erase "$(OUTDIR)\inproc.exp"
	-@erase "$(OUTDIR)\inproc.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_USRDLL" /D "_WINDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\inproc.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\inproc.res" /d "NDEBUG" 
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
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\inproc.pdb" /machine:I386 /def:".\inproc.def" /out:"$(OUTDIR)\inproc.dll" /implib:"$(OUTDIR)\inproc.lib" 
DEF_FILE= \
	".\inproc.def"
LINK32_OBJS= \
	"$(INTDIR)\enumvar.obj" \
	"$(INTDIR)\inproc.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\strcoll.obj" \
	"$(INTDIR)\varassoc.obj" \
	"$(INTDIR)\varmap.obj" \
	"$(INTDIR)\inproc.res"

"$(OUTDIR)\inproc.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Dll Debug"

OUTDIR=.\UniDllDebug
INTDIR=.\UniDllDebug
# Begin Custom Macros
OutDir=.\UniDllDebug
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
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\inproc.bsc"
	-@erase "$(OUTDIR)\inproc.dll"
	-@erase "$(OUTDIR)\inproc.exp"
	-@erase "$(OUTDIR)\inproc.ilk"
	-@erase "$(OUTDIR)\inproc.lib"
	-@erase "$(OUTDIR)\inproc.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_USRDLL" /D "_WINDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\inproc.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\inproc.res" /d "_DEBUG" 
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
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\inproc.pdb" /debug /machine:I386 /def:".\inproc.def" /out:"$(OUTDIR)\inproc.dll" /implib:"$(OUTDIR)\inproc.lib" 
DEF_FILE= \
	".\inproc.def"
LINK32_OBJS= \
	"$(INTDIR)\enumvar.obj" \
	"$(INTDIR)\inproc.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\strcoll.obj" \
	"$(INTDIR)\varassoc.obj" \
	"$(INTDIR)\varmap.obj" \
	"$(INTDIR)\inproc.res"

"$(OUTDIR)\inproc.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("inproc.dep")
!INCLUDE "inproc.dep"
!ELSE 
!MESSAGE Warning: cannot find "inproc.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "InProc - Win32 Release" || "$(CFG)" == "InProc - Win32 Debug" || "$(CFG)" == "InProc - Win32 Unicode Release" || "$(CFG)" == "InProc - Win32 Unicode Debug" || "$(CFG)" == "InProc - Win32 Dll Release" || "$(CFG)" == "InProc - Win32 Dll Debug" || "$(CFG)" == "InProc - Win32 Unicode Dll Release" || "$(CFG)" == "InProc - Win32 Unicode Dll Debug"
SOURCE=.\enumvar.cpp

"$(INTDIR)\enumvar.obj"	"$(INTDIR)\enumvar.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\inproc.pch"


SOURCE=.\inproc.cpp

"$(INTDIR)\inproc.obj"	"$(INTDIR)\inproc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\inproc.pch"


SOURCE=.\inproc.odl

!IF  "$(CFG)" == "InProc - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\inproc.tlb" /mktyplib203 /win32 

"$(OUTDIR)\inproc.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "InProc - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\inproc.tlb" /mktyplib203 /win32 

"$(OUTDIR)\inproc.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\inproc.tlb" /mktyplib203 /win32 

"$(OUTDIR)\inproc.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\inproc.tlb" /mktyplib203 /win32 

"$(OUTDIR)\inproc.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "InProc - Win32 Dll Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\inproc.tlb" /mktyplib203 /win32 

"$(OUTDIR)\inproc.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "InProc - Win32 Dll Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\inproc.tlb" /mktyplib203 /win32 

"$(OUTDIR)\inproc.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Dll Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\inproc.tlb" /mktyplib203 /win32 

"$(OUTDIR)\inproc.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Dll Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\inproc.tlb" /mktyplib203 /win32 

"$(OUTDIR)\inproc.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\inproc.rc

!IF  "$(CFG)" == "InProc - Win32 Release"


"$(INTDIR)\inproc.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\inproc.res" /i ".\Release" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Debug"


"$(INTDIR)\inproc.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\inproc.res" /i ".\Debug" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Release"


"$(INTDIR)\inproc.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\inproc.res" /i ".\UniRelease" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Debug"


"$(INTDIR)\inproc.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\inproc.res" /i ".\UniDebug" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Dll Release"


"$(INTDIR)\inproc.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\inproc.res" /i ".\DllRelease" /d "NDEBUG" $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Dll Debug"


"$(INTDIR)\inproc.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\inproc.res" /i ".\DllDebug" /d "_DEBUG" $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Dll Release"


"$(INTDIR)\inproc.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\inproc.res" /i ".\UniDllRelease" /d "NDEBUG" $(SOURCE)


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Dll Debug"


"$(INTDIR)\inproc.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\inproc.res" /i ".\UniDllDebug" /d "_DEBUG" $(SOURCE)


!ENDIF 

SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "InProc - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\inproc.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\inproc.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "InProc - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\inproc.pch" /Yc"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\inproc.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\inproc.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\inproc.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\inproc.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\inproc.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "InProc - Win32 Dll Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_WINDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\inproc.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\inproc.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "InProc - Win32 Dll Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_WINDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\inproc.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\inproc.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Dll Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_USRDLL" /D "_WINDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\inproc.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\inproc.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "InProc - Win32 Unicode Dll Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_USRDLL" /D "_WINDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\inproc.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\inproc.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\strcoll.cpp

"$(INTDIR)\strcoll.obj"	"$(INTDIR)\strcoll.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\inproc.pch"


SOURCE=.\varassoc.cpp

"$(INTDIR)\varassoc.obj"	"$(INTDIR)\varassoc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\inproc.pch"


SOURCE=.\varmap.cpp

"$(INTDIR)\varmap.obj"	"$(INTDIR)\varmap.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\inproc.pch"



!ENDIF 

