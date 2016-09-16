# Microsoft Developer Studio Generated NMAKE File, Based on CDInfo.dsp
!IF "$(CFG)" == ""
CFG=CDInfo - Win32 Release
!MESSAGE No configuration specified. Defaulting to CDInfo - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "CDInfo - Win32 Release" && "$(CFG)" != "CDInfo - Win32 Debug" && "$(CFG)" != "CDInfo - Win32 Unicode Release" && "$(CFG)" != "CDInfo - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CDInfo.mak" CFG="CDInfo - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CDInfo - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "CDInfo - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "CDInfo - Win32 Unicode Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "CDInfo - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "CDInfo - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\CDInfo.dll" ".\.\Release\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\CCDInfo.obj"
	-@erase "$(INTDIR)\CDInfo.obj"
	-@erase "$(INTDIR)\CDInfo.pch"
	-@erase "$(INTDIR)\CDInfo.res"
	-@erase "$(INTDIR)\CDInfo1.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\CDInfo.dll"
	-@erase "$(OUTDIR)\CDInfo.exp"
	-@erase "$(OUTDIR)\CDInfo.lib"
	-@erase ".\CDInfo.h"
	-@erase ".\CDInfo.tlb"
	-@erase ".\CDInfo_i.c"
	-@erase ".\.\Release\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W4 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\CDInfo.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CDInfo.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CDInfo.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=winmm.lib comctl32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\CDInfo.pdb" /machine:I386 /def:".\CDInfo.def" /out:"$(OUTDIR)\CDInfo.dll" /implib:"$(OUTDIR)\CDInfo.lib" 
DEF_FILE= \
	".\CDInfo.def"
LINK32_OBJS= \
	"$(INTDIR)\CCDInfo.obj" \
	"$(INTDIR)\CDInfo.obj" \
	"$(INTDIR)\CDInfo1.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\CDInfo.res"

"$(OUTDIR)\CDInfo.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\CDInfo.dll
InputPath=.\Release\CDInfo.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "CDInfo - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\CDInfo.dll" "$(OUTDIR)\CDInfo.bsc" ".\CDInfo_i.c" ".\CDInfo.h" ".\.\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\CCDInfo.obj"
	-@erase "$(INTDIR)\CCDInfo.sbr"
	-@erase "$(INTDIR)\CDInfo.obj"
	-@erase "$(INTDIR)\CDInfo.pch"
	-@erase "$(INTDIR)\CDInfo.res"
	-@erase "$(INTDIR)\CDInfo.sbr"
	-@erase "$(INTDIR)\CDInfo1.obj"
	-@erase "$(INTDIR)\CDInfo1.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\CDInfo.bsc"
	-@erase "$(OUTDIR)\CDInfo.dll"
	-@erase "$(OUTDIR)\CDInfo.exp"
	-@erase "$(OUTDIR)\CDInfo.ilk"
	-@erase "$(OUTDIR)\CDInfo.lib"
	-@erase "$(OUTDIR)\CDInfo.pdb"
	-@erase ".\CDInfo.h"
	-@erase ".\CDInfo.tlb"
	-@erase ".\CDInfo_i.c"
	-@erase ".\.\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W4 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\CDInfo.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CDInfo.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CDInfo.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\CCDInfo.sbr" \
	"$(INTDIR)\CDInfo.sbr" \
	"$(INTDIR)\CDInfo1.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\CDInfo.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=winmm.lib comctl32.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\CDInfo.pdb" /debug /machine:I386 /def:".\CDInfo.def" /out:"$(OUTDIR)\CDInfo.dll" /implib:"$(OUTDIR)\CDInfo.lib" 
DEF_FILE= \
	".\CDInfo.def"
LINK32_OBJS= \
	"$(INTDIR)\CCDInfo.obj" \
	"$(INTDIR)\CDInfo.obj" \
	"$(INTDIR)\CDInfo1.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\CDInfo.res"

"$(OUTDIR)\CDInfo.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\CDInfo.dll
InputPath=.\Debug\CDInfo.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "CDInfo - Win32 Unicode Release"

OUTDIR=.\ReleaseU
INTDIR=.\ReleaseU
# Begin Custom Macros
OutDir=.\.\ReleaseU
# End Custom Macros

ALL : "$(OUTDIR)\CDInfo.dll" ".\CDInfo_i.c" ".\CDInfo.h" ".\.\ReleaseU\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\CCDInfo.obj"
	-@erase "$(INTDIR)\CDInfo.obj"
	-@erase "$(INTDIR)\CDInfo.pch"
	-@erase "$(INTDIR)\CDInfo.res"
	-@erase "$(INTDIR)\CDInfo1.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\CDInfo.dll"
	-@erase "$(OUTDIR)\CDInfo.exp"
	-@erase "$(OUTDIR)\CDInfo.lib"
	-@erase ".\CDInfo.h"
	-@erase ".\CDInfo.tlb"
	-@erase ".\CDInfo_i.c"
	-@erase ".\.\ReleaseU\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W4 /GX /O1 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\CDInfo.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CDInfo.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CDInfo.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=winmm.lib comctl32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\CDInfo.pdb" /machine:I386 /def:".\CDInfo.def" /out:"$(OUTDIR)\CDInfo.dll" /implib:"$(OUTDIR)\CDInfo.lib" 
DEF_FILE= \
	".\CDInfo.def"
LINK32_OBJS= \
	"$(INTDIR)\CCDInfo.obj" \
	"$(INTDIR)\CDInfo.obj" \
	"$(INTDIR)\CDInfo1.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\CDInfo.res"

"$(OUTDIR)\CDInfo.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\ReleaseU
TargetPath=.\ReleaseU\CDInfo.dll
InputPath=.\ReleaseU\CDInfo.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "CDInfo - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\.\DebugU
# End Custom Macros

ALL : "$(OUTDIR)\CDInfo.dll" ".\CDInfo_i.c" ".\CDInfo.h" ".\.\DebugU\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\CCDInfo.obj"
	-@erase "$(INTDIR)\CDInfo.obj"
	-@erase "$(INTDIR)\CDInfo.pch"
	-@erase "$(INTDIR)\CDInfo.res"
	-@erase "$(INTDIR)\CDInfo1.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\CDInfo.dll"
	-@erase "$(OUTDIR)\CDInfo.exp"
	-@erase "$(OUTDIR)\CDInfo.ilk"
	-@erase "$(OUTDIR)\CDInfo.lib"
	-@erase "$(OUTDIR)\CDInfo.pdb"
	-@erase ".\CDInfo.h"
	-@erase ".\CDInfo.tlb"
	-@erase ".\CDInfo_i.c"
	-@erase ".\.\DebugU\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W4 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\CDInfo.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CDInfo.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CDInfo.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=winmm.lib comctl32.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\CDInfo.pdb" /debug /machine:I386 /def:".\CDInfo.def" /out:"$(OUTDIR)\CDInfo.dll" /implib:"$(OUTDIR)\CDInfo.lib" 
DEF_FILE= \
	".\CDInfo.def"
LINK32_OBJS= \
	"$(INTDIR)\CCDInfo.obj" \
	"$(INTDIR)\CDInfo.obj" \
	"$(INTDIR)\CDInfo1.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\CDInfo.res"

"$(OUTDIR)\CDInfo.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\DebugU
TargetPath=.\DebugU\CDInfo.dll
InputPath=.\DebugU\CDInfo.dll
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
!IF EXISTS("CDInfo.dep")
!INCLUDE "CDInfo.dep"
!ELSE 
!MESSAGE Warning: cannot find "CDInfo.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "CDInfo - Win32 Release" || "$(CFG)" == "CDInfo - Win32 Debug" || "$(CFG)" == "CDInfo - Win32 Unicode Release" || "$(CFG)" == "CDInfo - Win32 Unicode Debug"
SOURCE=.\CCDInfo.cpp

!IF  "$(CFG)" == "CDInfo - Win32 Release"


"$(INTDIR)\CCDInfo.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CDInfo.pch"


!ELSEIF  "$(CFG)" == "CDInfo - Win32 Debug"


"$(INTDIR)\CCDInfo.obj"	"$(INTDIR)\CCDInfo.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CDInfo.pch"


!ELSEIF  "$(CFG)" == "CDInfo - Win32 Unicode Release"


"$(INTDIR)\CCDInfo.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CDInfo.pch"


!ELSEIF  "$(CFG)" == "CDInfo - Win32 Unicode Debug"


"$(INTDIR)\CCDInfo.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CDInfo.pch"


!ENDIF 

SOURCE=.\CDInfo.cpp

!IF  "$(CFG)" == "CDInfo - Win32 Release"


"$(INTDIR)\CDInfo.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CDInfo.pch" ".\CDInfo.h" ".\CDInfo_i.c"


!ELSEIF  "$(CFG)" == "CDInfo - Win32 Debug"


"$(INTDIR)\CDInfo.obj"	"$(INTDIR)\CDInfo.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CDInfo.pch"


!ELSEIF  "$(CFG)" == "CDInfo - Win32 Unicode Release"


"$(INTDIR)\CDInfo.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CDInfo.pch"


!ELSEIF  "$(CFG)" == "CDInfo - Win32 Unicode Debug"


"$(INTDIR)\CDInfo.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CDInfo.pch"


!ENDIF 

SOURCE=.\CDInfo.idl

!IF  "$(CFG)" == "CDInfo - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb ".\CDInfo.tlb" /h "CDInfo.h" /iid "CDInfo_i.c" /win32 

".\CDInfo.tlb"	".\CDInfo.h"	".\CDInfo_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CDInfo - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb ".\CDInfo.tlb" /h "CDInfo.h" /iid "CDInfo_i.c" /win32 

".\CDInfo.tlb"	".\CDInfo.h"	".\CDInfo_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CDInfo - Win32 Unicode Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb ".\CDInfo.tlb" /h "CDInfo.h" /iid "CDInfo_i.c" /win32 

".\CDInfo.tlb"	".\CDInfo.h"	".\CDInfo_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CDInfo - Win32 Unicode Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb ".\CDInfo.tlb" /h "CDInfo.h" /iid "CDInfo_i.c" /win32 

".\CDInfo.tlb"	".\CDInfo.h"	".\CDInfo_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\CDInfo.rc

"$(INTDIR)\CDInfo.res" : $(SOURCE) "$(INTDIR)" ".\CDInfo.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\CDInfo1.cpp

!IF  "$(CFG)" == "CDInfo - Win32 Release"


"$(INTDIR)\CDInfo1.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CDInfo.pch" ".\CDInfo.h"


!ELSEIF  "$(CFG)" == "CDInfo - Win32 Debug"


"$(INTDIR)\CDInfo1.obj"	"$(INTDIR)\CDInfo1.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CDInfo.pch"


!ELSEIF  "$(CFG)" == "CDInfo - Win32 Unicode Release"


"$(INTDIR)\CDInfo1.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CDInfo.pch"


!ELSEIF  "$(CFG)" == "CDInfo - Win32 Unicode Debug"


"$(INTDIR)\CDInfo1.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CDInfo.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "CDInfo - Win32 Release"

CPP_SWITCHES=/nologo /MT /W4 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\CDInfo.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CDInfo.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CDInfo - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W4 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\CDInfo.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\CDInfo.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CDInfo - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MT /W4 /GX /O1 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\CDInfo.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CDInfo.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CDInfo - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MTd /W4 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\CDInfo.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CDInfo.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

