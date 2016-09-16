# Microsoft Developer Studio Generated NMAKE File, Based on circ.dsp
!IF "$(CFG)" == ""
CFG=circ - Win32 MinSize
!MESSAGE No configuration specified. Defaulting to circ - Win32 MinSize.
!ENDIF 

!IF "$(CFG)" != "circ - Win32 MinSize" && "$(CFG)" != "circ - Win32 MinDep" && "$(CFG)" != "circ - Win32 Debug" && "$(CFG)" != "circ - Win32 Unicode MinSize" && "$(CFG)" != "circ - Win32 Unicode MinDep" && "$(CFG)" != "circ - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "circ.mak" CFG="circ - Win32 MinSize"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "circ - Win32 MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "circ - Win32 MinDep" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "circ - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "circ - Win32 Unicode MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "circ - Win32 Unicode MinDep" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "circ - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "circ - Win32 MinSize"

OUTDIR=.\MinSize
INTDIR=.\MinSize
# Begin Custom Macros
OutDir=.\.\MinSize
# End Custom Macros

ALL : "$(OUTDIR)\circ.dll" "$(OUTDIR)\circ.bsc" ".\circ_i.c" ".\circ.h" ".\.\MinSize\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\circ.obj"
	-@erase "$(INTDIR)\circ.pch"
	-@erase "$(INTDIR)\circ.res"
	-@erase "$(INTDIR)\circ.sbr"
	-@erase "$(INTDIR)\CircCtl.obj"
	-@erase "$(INTDIR)\CircCtl.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\circ.bsc"
	-@erase "$(OUTDIR)\circ.dll"
	-@erase "$(OUTDIR)\circ.exp"
	-@erase "$(OUTDIR)\circ.lib"
	-@erase ".\circ.h"
	-@erase ".\circ.tlb"
	-@erase ".\circ_i.c"
	-@erase ".\.\MinSize\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
CPP_PROJ=/nologo /MD /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\circ.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\circ.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\circ.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\circ.sbr" \
	"$(INTDIR)\CircCtl.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\circ.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\circ.pdb" /machine:I386 /def:".\circ.def" /out:"$(OUTDIR)\circ.dll" /implib:"$(OUTDIR)\circ.lib" 
DEF_FILE= \
	".\circ.def"
LINK32_OBJS= \
	"$(INTDIR)\circ.obj" \
	"$(INTDIR)\CircCtl.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\circ.res"

"$(OUTDIR)\circ.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\MinSize
TargetPath=.\MinSize\circ.dll
InputPath=.\MinSize\circ.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "circ - Win32 MinDep"

OUTDIR=.\MinDep
INTDIR=.\MinDep
# Begin Custom Macros
OutDir=.\.\MinDep
# End Custom Macros

ALL : "$(OUTDIR)\circ.dll" ".\circ_i.c" ".\circ.h" ".\.\MinDep\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\circ.obj"
	-@erase "$(INTDIR)\circ.pch"
	-@erase "$(INTDIR)\circ.res"
	-@erase "$(INTDIR)\CircCtl.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\circ.dll"
	-@erase "$(OUTDIR)\circ.exp"
	-@erase "$(OUTDIR)\circ.lib"
	-@erase ".\circ.h"
	-@erase ".\circ.tlb"
	-@erase ".\circ_i.c"
	-@erase ".\.\MinDep\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
CPP_PROJ=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\circ.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\circ.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\circ.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"DllMain" /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\circ.pdb" /machine:I386 /def:".\circ.def" /out:"$(OUTDIR)\circ.dll" /implib:"$(OUTDIR)\circ.lib" 
DEF_FILE= \
	".\circ.def"
LINK32_OBJS= \
	"$(INTDIR)\circ.obj" \
	"$(INTDIR)\CircCtl.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\circ.res"

"$(OUTDIR)\circ.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\MinDep
TargetPath=.\MinDep\circ.dll
InputPath=.\MinDep\circ.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "circ - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\circ.dll" "$(OUTDIR)\circ.bsc" ".\circ_i.c" ".\circ.h" ".\.\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\circ.obj"
	-@erase "$(INTDIR)\circ.pch"
	-@erase "$(INTDIR)\circ.res"
	-@erase "$(INTDIR)\circ.sbr"
	-@erase "$(INTDIR)\CircCtl.obj"
	-@erase "$(INTDIR)\CircCtl.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\circ.bsc"
	-@erase "$(OUTDIR)\circ.dll"
	-@erase "$(OUTDIR)\circ.exp"
	-@erase "$(OUTDIR)\circ.ilk"
	-@erase "$(OUTDIR)\circ.lib"
	-@erase "$(OUTDIR)\circ.pdb"
	-@erase ".\circ.h"
	-@erase ".\circ.tlb"
	-@erase ".\circ_i.c"
	-@erase ".\.\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\circ.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\circ.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\circ.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\circ.sbr" \
	"$(INTDIR)\CircCtl.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\circ.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\circ.pdb" /debug /machine:I386 /def:".\circ.def" /out:"$(OUTDIR)\circ.dll" /implib:"$(OUTDIR)\circ.lib" 
DEF_FILE= \
	".\circ.def"
LINK32_OBJS= \
	"$(INTDIR)\circ.obj" \
	"$(INTDIR)\CircCtl.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\circ.res"

"$(OUTDIR)\circ.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\circ.dll
InputPath=.\Debug\circ.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "circ - Win32 Unicode MinSize"

OUTDIR=.\MinSizeU
INTDIR=.\MinSizeU
# Begin Custom Macros
OutDir=.\.\MinSizeU
# End Custom Macros

ALL : "$(OUTDIR)\circ.dll" ".\circ_i.c" ".\circ.h" ".\.\MinSizeU\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\circ.obj"
	-@erase "$(INTDIR)\circ.pch"
	-@erase "$(INTDIR)\circ.res"
	-@erase "$(INTDIR)\CircCtl.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\circ.dll"
	-@erase "$(OUTDIR)\circ.exp"
	-@erase "$(OUTDIR)\circ.lib"
	-@erase ".\circ.h"
	-@erase ".\circ.tlb"
	-@erase ".\circ_i.c"
	-@erase ".\.\MinSizeU\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
CPP_PROJ=/nologo /MD /W3 /O1 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_UNICODE" /Fp"$(INTDIR)\circ.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\circ.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\circ.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\circ.pdb" /machine:I386 /def:".\circ.def" /out:"$(OUTDIR)\circ.dll" /implib:"$(OUTDIR)\circ.lib" 
DEF_FILE= \
	".\circ.def"
LINK32_OBJS= \
	"$(INTDIR)\circ.obj" \
	"$(INTDIR)\CircCtl.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\circ.res"

"$(OUTDIR)\circ.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\MinSizeU
TargetPath=.\MinSizeU\circ.dll
InputPath=.\MinSizeU\circ.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "circ - Win32 Unicode MinDep"

OUTDIR=.\MinDepU
INTDIR=.\MinDepU
# Begin Custom Macros
OutDir=.\.\MinDepU
# End Custom Macros

ALL : "$(OUTDIR)\circ.dll" ".\circ_i.c" ".\circ.h" ".\.\MinDepU\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\circ.obj"
	-@erase "$(INTDIR)\circ.pch"
	-@erase "$(INTDIR)\circ.res"
	-@erase "$(INTDIR)\CircCtl.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\circ.dll"
	-@erase "$(OUTDIR)\circ.exp"
	-@erase "$(OUTDIR)\circ.lib"
	-@erase ".\circ.h"
	-@erase ".\circ.tlb"
	-@erase ".\circ_i.c"
	-@erase ".\.\MinDepU\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
CPP_PROJ=/nologo /MT /W3 /O1 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\circ.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\circ.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\circ.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"DllMain" /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\circ.pdb" /machine:I386 /def:".\circ.def" /out:"$(OUTDIR)\circ.dll" /implib:"$(OUTDIR)\circ.lib" 
DEF_FILE= \
	".\circ.def"
LINK32_OBJS= \
	"$(INTDIR)\circ.obj" \
	"$(INTDIR)\CircCtl.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\circ.res"

"$(OUTDIR)\circ.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\MinDepU
TargetPath=.\MinDepU\circ.dll
InputPath=.\MinDepU\circ.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "circ - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\.\DebugU
# End Custom Macros

ALL : "$(OUTDIR)\circ.dll" "$(OUTDIR)\circ.bsc" ".\circ_i.c" ".\circ.h" ".\.\DebugU\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\circ.obj"
	-@erase "$(INTDIR)\circ.pch"
	-@erase "$(INTDIR)\circ.res"
	-@erase "$(INTDIR)\circ.sbr"
	-@erase "$(INTDIR)\CircCtl.obj"
	-@erase "$(INTDIR)\CircCtl.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\circ.bsc"
	-@erase "$(OUTDIR)\circ.dll"
	-@erase "$(OUTDIR)\circ.exp"
	-@erase "$(OUTDIR)\circ.ilk"
	-@erase "$(OUTDIR)\circ.lib"
	-@erase "$(OUTDIR)\circ.pdb"
	-@erase ".\circ.h"
	-@erase ".\circ.tlb"
	-@erase ".\circ_i.c"
	-@erase ".\.\DebugU\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_UNICODE" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\circ.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\circ.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\circ.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\circ.sbr" \
	"$(INTDIR)\CircCtl.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\circ.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\circ.pdb" /debug /machine:I386 /def:".\circ.def" /out:"$(OUTDIR)\circ.dll" /implib:"$(OUTDIR)\circ.lib" 
DEF_FILE= \
	".\circ.def"
LINK32_OBJS= \
	"$(INTDIR)\circ.obj" \
	"$(INTDIR)\CircCtl.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\circ.res"

"$(OUTDIR)\circ.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\DebugU
TargetPath=.\DebugU\circ.dll
InputPath=.\DebugU\circ.dll
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
!IF EXISTS("circ.dep")
!INCLUDE "circ.dep"
!ELSE 
!MESSAGE Warning: cannot find "circ.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "circ - Win32 MinSize" || "$(CFG)" == "circ - Win32 MinDep" || "$(CFG)" == "circ - Win32 Debug" || "$(CFG)" == "circ - Win32 Unicode MinSize" || "$(CFG)" == "circ - Win32 Unicode MinDep" || "$(CFG)" == "circ - Win32 Unicode Debug"
SOURCE=.\circ.cpp

!IF  "$(CFG)" == "circ - Win32 MinSize"


"$(INTDIR)\circ.obj"	"$(INTDIR)\circ.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\circ.pch"


!ELSEIF  "$(CFG)" == "circ - Win32 MinDep"


"$(INTDIR)\circ.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\circ.pch"


!ELSEIF  "$(CFG)" == "circ - Win32 Debug"


"$(INTDIR)\circ.obj"	"$(INTDIR)\circ.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\circ.pch"


!ELSEIF  "$(CFG)" == "circ - Win32 Unicode MinSize"


"$(INTDIR)\circ.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\circ.pch"


!ELSEIF  "$(CFG)" == "circ - Win32 Unicode MinDep"


"$(INTDIR)\circ.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\circ.pch"


!ELSEIF  "$(CFG)" == "circ - Win32 Unicode Debug"


"$(INTDIR)\circ.obj"	"$(INTDIR)\circ.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\circ.pch"


!ENDIF 

SOURCE=.\circ.idl

!IF  "$(CFG)" == "circ - Win32 MinSize"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "circ.tlb" /h "circ.h" /iid "circ_i.c" /win32 

".\circ.tlb"	".\circ.h"	".\circ_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "circ - Win32 MinDep"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "circ.tlb" /h "circ.h" /iid "circ_i.c" /win32 

".\circ.tlb"	".\circ.h"	".\circ_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "circ - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "circ.tlb" /h "circ.h" /iid "circ_i.c" /win32 

".\circ.tlb"	".\circ.h"	".\circ_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "circ - Win32 Unicode MinSize"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "circ.tlb" /h "circ.h" /iid "circ_i.c" /win32 

".\circ.tlb"	".\circ.h"	".\circ_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "circ - Win32 Unicode MinDep"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "circ.tlb" /h "circ.h" /iid "circ_i.c" /win32 

".\circ.tlb"	".\circ.h"	".\circ_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "circ - Win32 Unicode Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "circ.tlb" /h "circ.h" /iid "circ_i.c" /win32 

".\circ.tlb"	".\circ.h"	".\circ_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\circ.rc

"$(INTDIR)\circ.res" : $(SOURCE) "$(INTDIR)" ".\circ.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\CircCtl.cpp

!IF  "$(CFG)" == "circ - Win32 MinSize"


"$(INTDIR)\CircCtl.obj"	"$(INTDIR)\CircCtl.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\circ.pch"


!ELSEIF  "$(CFG)" == "circ - Win32 MinDep"


"$(INTDIR)\CircCtl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\circ.pch"


!ELSEIF  "$(CFG)" == "circ - Win32 Debug"


"$(INTDIR)\CircCtl.obj"	"$(INTDIR)\CircCtl.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\circ.pch"


!ELSEIF  "$(CFG)" == "circ - Win32 Unicode MinSize"


"$(INTDIR)\CircCtl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\circ.pch"


!ELSEIF  "$(CFG)" == "circ - Win32 Unicode MinDep"


"$(INTDIR)\CircCtl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\circ.pch"


!ELSEIF  "$(CFG)" == "circ - Win32 Unicode Debug"


"$(INTDIR)\CircCtl.obj"	"$(INTDIR)\CircCtl.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\circ.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "circ - Win32 MinSize"

CPP_SWITCHES=/nologo /MD /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\circ.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\circ.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "circ - Win32 MinDep"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\circ.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\circ.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "circ - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\circ.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\circ.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "circ - Win32 Unicode MinSize"

CPP_SWITCHES=/nologo /MD /W3 /O1 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_UNICODE" /Fp"$(INTDIR)\circ.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\circ.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "circ - Win32 Unicode MinDep"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\circ.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\circ.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "circ - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_UNICODE" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\circ.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\circ.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

