# Microsoft Developer Studio Generated NMAKE File, Based on TCProps.dsp
!IF "$(CFG)" == ""
CFG=TCProps - Win32 Debug
!MESSAGE No configuration specified. Defaulting to TCProps - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "TCProps - Win32 Debug" && "$(CFG)" != "TCProps - Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TCProps.mak" CFG="TCProps - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TCProps - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "TCProps - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "TCProps - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\TCProps.dll" ".\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TCExtPg.obj"
	-@erase "$(INTDIR)\TCProps.obj"
	-@erase "$(INTDIR)\TCProps.pch"
	-@erase "$(INTDIR)\TCProps.res"
	-@erase "$(INTDIR)\TCProps.tlb"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\TCProps.dll"
	-@erase "$(OUTDIR)\TCProps.exp"
	-@erase "$(OUTDIR)\TCProps.ilk"
	-@erase "$(OUTDIR)\TCProps.lib"
	-@erase "$(OUTDIR)\TCProps.pdb"
	-@erase ".\TCProps.h"
	-@erase ".\TCProps_i.c"
	-@erase ".\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W4 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\TCProps.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\TCProps.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\TCProps.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\TCProps.pdb" /debug /machine:I386 /def:".\TCProps.def" /out:"$(OUTDIR)\TCProps.dll" /implib:"$(OUTDIR)\TCProps.lib" /pdbtype:sept 
DEF_FILE= \
	".\TCProps.def"
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TCExtPg.obj" \
	"$(INTDIR)\TCProps.obj" \
	"$(INTDIR)\TCProps.res"

"$(OUTDIR)\TCProps.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Debug
TargetPath=.\Debug\TCProps.dll
InputPath=.\Debug\TCProps.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "TCProps - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\TCProps.dll" ".\Release\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TCExtPg.obj"
	-@erase "$(INTDIR)\TCProps.obj"
	-@erase "$(INTDIR)\TCProps.pch"
	-@erase "$(INTDIR)\TCProps.res"
	-@erase "$(INTDIR)\TCProps.tlb"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\TCProps.dll"
	-@erase "$(OUTDIR)\TCProps.pdb"
	-@erase "$(OUTDIR)\TCProps.exp"
	-@erase "$(OUTDIR)\TCProps.lib"
	-@erase ".\TCProps.h"
	-@erase ".\TCProps_i.c"
	-@erase ".\Release\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /Zi /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\TCProps.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\TCProps.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\TCProps.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\TCProps.pdb" /debug /machine:I386 /def:".\TCProps.def" /out:"$(OUTDIR)\TCProps.dll" /implib:"$(OUTDIR)\TCProps.lib" 
DEF_FILE= \
	".\TCProps.def"
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TCExtPg.obj" \
	"$(INTDIR)\TCProps.obj" \
	"$(INTDIR)\TCProps.res"

"$(OUTDIR)\TCProps.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Release
TargetPath=.\Release\TCProps.dll
InputPath=.\Release\TCProps.dll
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

MTL_PROJ=

!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("TCProps.dep")
!INCLUDE "TCProps.dep"
!ELSE 
!MESSAGE Warning: cannot find "TCProps.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "TCProps - Win32 Debug" || "$(CFG)" == "TCProps - Win32 Release"
SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "TCProps - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W4 /Gm /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\TCProps.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\TCProps.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "TCProps - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /Zi /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\TCProps.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\TCProps.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\TCExtPg.Cpp

"$(INTDIR)\TCExtPg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TCProps.pch" ".\TCProps.h"


SOURCE=.\TCProps.cpp

"$(INTDIR)\TCProps.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TCProps.pch" ".\TCProps.h" ".\TCProps_i.c"


SOURCE=.\TCProps.idl
MTL_SWITCHES=/tlb "$(OUTDIR)\TCProps.tlb" /h "TCProps.h" /iid "TCProps_i.c" /Oicf 

"$(INTDIR)\TCProps.tlb"	".\TCProps.h"	".\TCProps_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


SOURCE=.\TCProps.rc

!IF  "$(CFG)" == "TCProps - Win32 Debug"


"$(INTDIR)\TCProps.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TCProps.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\TCProps.res" /i "Debug" /d "_DEBUG" $(SOURCE)


!ELSEIF  "$(CFG)" == "TCProps - Win32 Release"


"$(INTDIR)\TCProps.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TCProps.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\TCProps.res" /i "Release" /d "NDEBUG" $(SOURCE)


!ENDIF 


!ENDIF 

