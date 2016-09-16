# Microsoft Developer Studio Generated NMAKE File, Based on Polygon.dsp
!IF "$(CFG)" == ""
CFG=Polygon - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Polygon - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Polygon - Win32 Debug" && "$(CFG)" != "Polygon - Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Polygon.mak" CFG="Polygon - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Polygon - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Polygon - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "Polygon - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Polygon.dll" ".\Polygon.tlb" ".\Polygon.h" ".\Polygon_i.c" "$(OUTDIR)\Polygon.bsc" ".\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\PolyCtl.obj"
	-@erase "$(INTDIR)\PolyCtl.sbr"
	-@erase "$(INTDIR)\Polygon.obj"
	-@erase "$(INTDIR)\Polygon.pch"
	-@erase "$(INTDIR)\Polygon.res"
	-@erase "$(INTDIR)\Polygon.sbr"
	-@erase "$(INTDIR)\PolyProp.obj"
	-@erase "$(INTDIR)\PolyProp.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Polygon.bsc"
	-@erase "$(OUTDIR)\Polygon.dll"
	-@erase "$(OUTDIR)\Polygon.exp"
	-@erase "$(OUTDIR)\Polygon.ilk"
	-@erase "$(OUTDIR)\Polygon.lib"
	-@erase "$(OUTDIR)\Polygon.pdb"
	-@erase ".\Polygon.h"
	-@erase ".\Polygon.tlb"
	-@erase ".\Polygon_i.c"
	-@erase ".\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\Polygon.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

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
MTL_PROJ=
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Polygon.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Polygon.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\PolyCtl.sbr" \
	"$(INTDIR)\Polygon.sbr" \
	"$(INTDIR)\PolyProp.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\Polygon.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\Polygon.pdb" /debug /machine:I386 /def:".\Polygon.def" /out:"$(OUTDIR)\Polygon.dll" /implib:"$(OUTDIR)\Polygon.lib" /pdbtype:sept 
DEF_FILE= \
	".\Polygon.def"
LINK32_OBJS= \
	"$(INTDIR)\PolyCtl.obj" \
	"$(INTDIR)\Polygon.obj" \
	"$(INTDIR)\PolyProp.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Polygon.res"

"$(OUTDIR)\Polygon.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Debug
TargetPath=.\Debug\Polygon.dll
InputPath=.\Debug\Polygon.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 


!ELSEIF  "$(CFG)" == "Polygon - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\Polygon.dll" ".\Polygon.tlb" ".\Polygon.h" ".\Polygon_i.c" ".\Release\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\PolyCtl.obj"
	-@erase "$(INTDIR)\Polygon.obj"
	-@erase "$(INTDIR)\Polygon.pch"
	-@erase "$(INTDIR)\Polygon.res"
	-@erase "$(INTDIR)\PolyProp.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\Polygon.dll"
	-@erase "$(OUTDIR)\Polygon.exp"
	-@erase "$(OUTDIR)\Polygon.lib"
	-@erase ".\Polygon.h"
	-@erase ".\Polygon.tlb"
	-@erase ".\Polygon_i.c"
	-@erase ".\Release\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /O1 /D "_MBCS" /D "_ATL_DLL" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\Polygon.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Polygon.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Polygon.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\Polygon.pdb" /machine:I386 /def:".\Polygon.def" /out:"$(OUTDIR)\Polygon.dll" /implib:"$(OUTDIR)\Polygon.lib" 
DEF_FILE= \
	".\Polygon.def"
LINK32_OBJS= \
	"$(INTDIR)\PolyCtl.obj" \
	"$(INTDIR)\Polygon.obj" \
	"$(INTDIR)\PolyProp.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Polygon.res"

"$(OUTDIR)\Polygon.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Release
TargetPath=.\Release\Polygon.dll
InputPath=.\Release\Polygon.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<<
	

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("Polygon.dep")
!INCLUDE "Polygon.dep"
!ELSE 
!MESSAGE Warning: cannot find "Polygon.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Polygon - Win32 Debug" || "$(CFG)" == "Polygon - Win32 Release"
SOURCE=.\PolyCtl.cpp

!IF  "$(CFG)" == "Polygon - Win32 Debug"


"$(INTDIR)\PolyCtl.obj"	"$(INTDIR)\PolyCtl.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Polygon.pch"


!ELSEIF  "$(CFG)" == "Polygon - Win32 Release"


"$(INTDIR)\PolyCtl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Polygon.pch"


!ENDIF 

SOURCE=.\Polygon.cpp

!IF  "$(CFG)" == "Polygon - Win32 Debug"


"$(INTDIR)\Polygon.obj"	"$(INTDIR)\Polygon.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Polygon.pch"


!ELSEIF  "$(CFG)" == "Polygon - Win32 Release"


"$(INTDIR)\Polygon.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Polygon.pch"


!ENDIF 

SOURCE=.\Polygon.idl

!IF  "$(CFG)" == "Polygon - Win32 Debug"

MTL_SWITCHES=/tlb ".\Polygon.tlb" /h "Polygon.h" /iid "Polygon_i.c" /Oicf 

".\Polygon.tlb"	".\Polygon.h"	".\Polygon_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Polygon - Win32 Release"

MTL_SWITCHES=/tlb ".\Polygon.tlb" /h "Polygon.h" /iid "Polygon_i.c" /Oicf 

".\Polygon.tlb"	".\Polygon.h"	".\Polygon_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Polygon.rc

"$(INTDIR)\Polygon.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\PolyProp.cpp

!IF  "$(CFG)" == "Polygon - Win32 Debug"


"$(INTDIR)\PolyProp.obj"	"$(INTDIR)\PolyProp.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Polygon.pch"


!ELSEIF  "$(CFG)" == "Polygon - Win32 Release"


"$(INTDIR)\PolyProp.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Polygon.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "Polygon - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\Polygon.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\Polygon.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Polygon - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "_MBCS" /D "_ATL_DLL" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\Polygon.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Polygon.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

