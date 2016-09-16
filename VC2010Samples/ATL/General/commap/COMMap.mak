# Microsoft Developer Studio Generated NMAKE File, Based on COMMap.dsp
!IF "$(CFG)" == ""
CFG=COMMap - Win32 Release
!MESSAGE No configuration specified. Defaulting to COMMap - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "COMMap - Win32 Release" && "$(CFG)" != "COMMap - Win32 Debug" && "$(CFG)" != "COMMap - Win32 Unicode Release" && "$(CFG)" != "COMMap - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "COMMap.mak" CFG="COMMap - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "COMMap - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "COMMap - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "COMMap - Win32 Unicode Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "COMMap - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "COMMap - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\COMMap.dll" ".\.\Release\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\Chain.obj"
	-@erase "$(INTDIR)\COMMap.obj"
	-@erase "$(INTDIR)\COMMap.pch"
	-@erase "$(INTDIR)\COMMap.res"
	-@erase "$(INTDIR)\Outer.obj"
	-@erase "$(INTDIR)\premap.obj"
	-@erase "$(OUTDIR)\COMMap.dll"
	-@erase "$(OUTDIR)\COMMap.exp"
	-@erase "$(OUTDIR)\COMMap.lib"
	-@erase ".\COMMap.h"
	-@erase ".\COMMap.tlb"
	-@erase ".\COMMap_i.c"
	-@erase ".\.\Release\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W4 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\COMMap.pch" /Yu"premap.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\COMMap.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\COMMap.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\COMMap.pdb" /machine:I386 /def:".\COMMap.def" /out:"$(OUTDIR)\COMMap.dll" /implib:"$(OUTDIR)\COMMap.lib" 
DEF_FILE= \
	".\COMMap.def"
LINK32_OBJS= \
	"$(INTDIR)\COMMap.obj" \
	"$(INTDIR)\Outer.obj" \
	"$(INTDIR)\Chain.obj" \
	"$(INTDIR)\premap.obj" \
	"$(INTDIR)\COMMap.res"

"$(OUTDIR)\COMMap.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\COMMap.dll
InputPath=.\Release\COMMap.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
<< 
	

!ELSEIF  "$(CFG)" == "COMMap - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\COMMap.dll" "$(OUTDIR)\COMMap.bsc" ".\.\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\Chain.obj"
	-@erase "$(INTDIR)\Chain.sbr"
	-@erase "$(INTDIR)\COMMap.obj"
	-@erase "$(INTDIR)\COMMap.pch"
	-@erase "$(INTDIR)\COMMap.res"
	-@erase "$(INTDIR)\COMMap.sbr"
	-@erase "$(INTDIR)\Outer.obj"
	-@erase "$(INTDIR)\Outer.sbr"
	-@erase "$(INTDIR)\premap.obj"
	-@erase "$(INTDIR)\premap.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\COMMap.bsc"
	-@erase "$(OUTDIR)\COMMap.dll"
	-@erase "$(OUTDIR)\COMMap.exp"
	-@erase "$(OUTDIR)\COMMap.ilk"
	-@erase "$(OUTDIR)\COMMap.lib"
	-@erase "$(OUTDIR)\COMMap.pdb"
	-@erase ".\COMMap.h"
	-@erase ".\COMMap.tlb"
	-@erase ".\COMMap_i.c"
	-@erase ".\.\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W4 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\COMMap.pch" /Yu"premap.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\COMMap.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\COMMap.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\COMMap.sbr" \
	"$(INTDIR)\Outer.sbr" \
	"$(INTDIR)\Chain.sbr" \
	"$(INTDIR)\premap.sbr"

"$(OUTDIR)\COMMap.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\COMMap.pdb" /debug /machine:I386 /def:".\COMMap.def" /out:"$(OUTDIR)\COMMap.dll" /implib:"$(OUTDIR)\COMMap.lib" 
DEF_FILE= \
	".\COMMap.def"
LINK32_OBJS= \
	"$(INTDIR)\COMMap.obj" \
	"$(INTDIR)\Outer.obj" \
	"$(INTDIR)\Chain.obj" \
	"$(INTDIR)\premap.obj" \
	"$(INTDIR)\COMMap.res"

"$(OUTDIR)\COMMap.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\COMMap.dll
InputPath=.\Debug\COMMap.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
<< 
	

!ELSEIF  "$(CFG)" == "COMMap - Win32 Unicode Release"

OUTDIR=.\ReleaseU
INTDIR=.\ReleaseU
# Begin Custom Macros
OutDir=.\.\ReleaseU
# End Custom Macros

ALL : "$(OUTDIR)\COMMap.dll" ".\.\ReleaseU\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\Chain.obj"
	-@erase "$(INTDIR)\COMMap.obj"
	-@erase "$(INTDIR)\COMMap.pch"
	-@erase "$(INTDIR)\COMMap.res"
	-@erase "$(INTDIR)\Outer.obj"
	-@erase "$(INTDIR)\premap.obj"
	-@erase "$(OUTDIR)\COMMap.dll"
	-@erase "$(OUTDIR)\COMMap.exp"
	-@erase "$(OUTDIR)\COMMap.lib"
	-@erase ".\COMMap.h"
	-@erase ".\COMMap.tlb"
	-@erase ".\COMMap_i.c"
	-@erase ".\.\ReleaseU\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W4 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\COMMap.pch" /Yu"premap.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\COMMap.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\COMMap.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\COMMap.pdb" /machine:I386 /def:".\COMMap.def" /out:"$(OUTDIR)\COMMap.dll" /implib:"$(OUTDIR)\COMMap.lib" 
DEF_FILE= \
	".\COMMap.def"
LINK32_OBJS= \
	"$(INTDIR)\COMMap.obj" \
	"$(INTDIR)\Outer.obj" \
	"$(INTDIR)\Chain.obj" \
	"$(INTDIR)\premap.obj" \
	"$(INTDIR)\COMMap.res"

"$(OUTDIR)\COMMap.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\ReleaseU
TargetPath=.\ReleaseU\COMMap.dll
InputPath=.\ReleaseU\COMMap.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
<< 
	

!ELSEIF  "$(CFG)" == "COMMap - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\.\DebugU
# End Custom Macros

ALL : "$(OUTDIR)\COMMap.dll" ".\.\DebugU\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\Chain.obj"
	-@erase "$(INTDIR)\COMMap.obj"
	-@erase "$(INTDIR)\COMMap.pch"
	-@erase "$(INTDIR)\COMMap.res"
	-@erase "$(INTDIR)\Outer.obj"
	-@erase "$(INTDIR)\premap.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\COMMap.dll"
	-@erase "$(OUTDIR)\COMMap.exp"
	-@erase "$(OUTDIR)\COMMap.ilk"
	-@erase "$(OUTDIR)\COMMap.lib"
	-@erase "$(OUTDIR)\COMMap.pdb"
	-@erase ".\COMMap.h"
	-@erase ".\COMMap.tlb"
	-@erase ".\COMMap_i.c"
	-@erase ".\.\DebugU\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W4 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\COMMap.pch" /Yu"premap.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\COMMap.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\COMMap.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\COMMap.pdb" /debug /machine:I386 /def:".\COMMap.def" /out:"$(OUTDIR)\COMMap.dll" /implib:"$(OUTDIR)\COMMap.lib" 
DEF_FILE= \
	".\COMMap.def"
LINK32_OBJS= \
	"$(INTDIR)\COMMap.obj" \
	"$(INTDIR)\Outer.obj" \
	"$(INTDIR)\Chain.obj" \
	"$(INTDIR)\premap.obj" \
	"$(INTDIR)\COMMap.res"

"$(OUTDIR)\COMMap.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\DebugU
TargetPath=.\DebugU\COMMap.dll
InputPath=.\DebugU\COMMap.dll
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
!IF EXISTS("COMMap.dep")
!INCLUDE "COMMap.dep"
!ELSE 
!MESSAGE Warning: cannot find "COMMap.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "COMMap - Win32 Release" || "$(CFG)" == "COMMap - Win32 Debug" || "$(CFG)" == "COMMap - Win32 Unicode Release" || "$(CFG)" == "COMMap - Win32 Unicode Debug"
SOURCE=.\Chain.cpp

!IF  "$(CFG)" == "COMMap - Win32 Release"


"$(INTDIR)\Chain.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COMMap.pch" ".\COMMap.h"


!ELSEIF  "$(CFG)" == "COMMap - Win32 Debug"


"$(INTDIR)\Chain.obj"	"$(INTDIR)\Chain.sbr" : $(SOURCE) "$(INTDIR)" ".\COMMap.h" "$(INTDIR)\COMMap.pch"


!ELSEIF  "$(CFG)" == "COMMap - Win32 Unicode Release"


"$(INTDIR)\Chain.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COMMap.pch" ".\COMMap.h"


!ELSEIF  "$(CFG)" == "COMMap - Win32 Unicode Debug"


"$(INTDIR)\Chain.obj" : $(SOURCE) "$(INTDIR)" ".\COMMap.h" "$(INTDIR)\COMMap.pch"


!ENDIF 

SOURCE=.\COMMap.cpp

!IF  "$(CFG)" == "COMMap - Win32 Release"


"$(INTDIR)\COMMap.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COMMap.pch" ".\COMMap.h" ".\COMMap_i.c"


!ELSEIF  "$(CFG)" == "COMMap - Win32 Debug"


"$(INTDIR)\COMMap.obj"	"$(INTDIR)\COMMap.sbr" : $(SOURCE) "$(INTDIR)" ".\COMMap.h" ".\COMMap_i.c" "$(INTDIR)\COMMap.pch"


!ELSEIF  "$(CFG)" == "COMMap - Win32 Unicode Release"


"$(INTDIR)\COMMap.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COMMap.pch" ".\COMMap.h" ".\COMMap_i.c"


!ELSEIF  "$(CFG)" == "COMMap - Win32 Unicode Debug"


"$(INTDIR)\COMMap.obj" : $(SOURCE) "$(INTDIR)" ".\COMMap.h" ".\COMMap_i.c" "$(INTDIR)\COMMap.pch"


!ENDIF 

SOURCE=.\COMMap.idl

!IF  "$(CFG)" == "COMMap - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb ".\COMMap.tlb" /h "COMMap.h" /iid "COMMap_i.c" /win32 

".\COMMap.tlb"	".\COMMap.h"	".\COMMap_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "COMMap - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb ".\COMMap.tlb" /h "COMMap.h" /iid "COMMap_i.c" /win32 

".\COMMap.tlb"	".\COMMap.h"	".\COMMap_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "COMMap - Win32 Unicode Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb ".\COMMap.tlb" /h "COMMap.h" /iid "COMMap_i.c" /win32 

".\COMMap.tlb"	".\COMMap.h"	".\COMMap_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "COMMap - Win32 Unicode Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb ".\COMMap.tlb" /h "COMMap.h" /iid "COMMap_i.c" /win32 

".\COMMap.tlb"	".\COMMap.h"	".\COMMap_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\COMMap.rc

"$(INTDIR)\COMMap.res" : $(SOURCE) "$(INTDIR)" ".\COMMap.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\Outer.cpp

!IF  "$(CFG)" == "COMMap - Win32 Release"


"$(INTDIR)\Outer.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COMMap.pch" ".\COMMap.h"


!ELSEIF  "$(CFG)" == "COMMap - Win32 Debug"


"$(INTDIR)\Outer.obj"	"$(INTDIR)\Outer.sbr" : $(SOURCE) "$(INTDIR)" ".\COMMap.h" "$(INTDIR)\COMMap.pch"


!ELSEIF  "$(CFG)" == "COMMap - Win32 Unicode Release"


"$(INTDIR)\Outer.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COMMap.pch" ".\COMMap.h"


!ELSEIF  "$(CFG)" == "COMMap - Win32 Unicode Debug"


"$(INTDIR)\Outer.obj" : $(SOURCE) "$(INTDIR)" ".\COMMap.h" "$(INTDIR)\COMMap.pch"


!ENDIF 

SOURCE=.\premap.cpp

!IF  "$(CFG)" == "COMMap - Win32 Release"

CPP_SWITCHES=/nologo /MT /W4 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\COMMap.pch" /Yc"premap.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\premap.obj"	"$(INTDIR)\COMMap.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "COMMap - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W4 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\COMMap.pch" /Yc"premap.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\premap.obj"	"$(INTDIR)\premap.sbr"	"$(INTDIR)\COMMap.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "COMMap - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MT /W4 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\COMMap.pch" /Yc"premap.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\premap.obj"	"$(INTDIR)\COMMap.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "COMMap - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MTd /W4 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\COMMap.pch" /Yc"premap.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\premap.obj"	"$(INTDIR)\COMMap.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

