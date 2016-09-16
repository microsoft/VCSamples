# Microsoft Developer Studio Generated NMAKE File, Based on ActiveDoc.dsp
!IF "$(CFG)" == ""
CFG=ActiveDoc - Win32 Release
!MESSAGE No configuration specified. Defaulting to ActiveDoc - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "ActiveDoc - Win32 Release" && "$(CFG)" != "ActiveDoc - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ActiveDoc.mak" CFG="ActiveDoc - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ActiveDoc - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ActiveDoc - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")

!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "ActiveDoc - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\ActiveDoc.dll" ".\.\Release\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\ActiveCtl.obj"
	-@erase "$(INTDIR)\ActiveDoc.obj"
	-@erase "$(INTDIR)\ActiveDoc.pch"
	-@erase "$(INTDIR)\ActiveDoc.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\ActiveDoc.dll"
	-@erase "$(OUTDIR)\ActiveDoc.exp"
	-@erase "$(OUTDIR)\ActiveDoc.lib"
	-@erase ".\ActiveDoc.h"
	-@erase ".\ActiveDoc.tlb"
	-@erase ".\ActiveDoc_i.c"
	-@erase ".\.\Release\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /Fp"$(INTDIR)\ActiveDoc.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ActiveDoc.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ActiveDoc.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=comctl32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\ActiveDoc.pdb" /machine:I386 /def:".\ActiveDoc.def" /out:"$(OUTDIR)\ActiveDoc.dll" /implib:"$(OUTDIR)\ActiveDoc.lib" 
DEF_FILE= \
	".\ActiveDoc.def"
LINK32_OBJS= \
	"$(INTDIR)\ActiveCtl.obj" \
	"$(INTDIR)\ActiveDoc.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ActiveDoc.res"

"$(OUTDIR)\ActiveDoc.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\ActiveDoc.dll
InputPath=.\Release\ActiveDoc.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "ActiveDoc - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\ActiveDoc.dll" "$(OUTDIR)\ActiveDoc.bsc" ".\ActiveDoc_i.c" ".\ActiveDoc.h" ".\.\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\ActiveCtl.obj"
	-@erase "$(INTDIR)\ActiveCtl.sbr"
	-@erase "$(INTDIR)\ActiveDoc.obj"
	-@erase "$(INTDIR)\ActiveDoc.pch"
	-@erase "$(INTDIR)\ActiveDoc.res"
	-@erase "$(INTDIR)\ActiveDoc.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\ActiveDoc.bsc"
	-@erase "$(OUTDIR)\ActiveDoc.dll"
	-@erase "$(OUTDIR)\ActiveDoc.exp"
	-@erase "$(OUTDIR)\ActiveDoc.ilk"
	-@erase "$(OUTDIR)\ActiveDoc.lib"
	-@erase "$(OUTDIR)\ActiveDoc.pdb"
	-@erase ".\ActiveDoc.h"
	-@erase ".\ActiveDoc.tlb"
	-@erase ".\ActiveDoc_i.c"
	-@erase ".\.\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ActiveDoc.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ActiveDoc.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ActiveDoc.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\ActiveCtl.sbr" \
	"$(INTDIR)\ActiveDoc.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\ActiveDoc.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=comctl32.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\ActiveDoc.pdb" /debug /machine:I386 /def:".\ActiveDoc.def" /out:"$(OUTDIR)\ActiveDoc.dll" /implib:"$(OUTDIR)\ActiveDoc.lib" 
DEF_FILE= \
	".\ActiveDoc.def"
LINK32_OBJS= \
	"$(INTDIR)\ActiveCtl.obj" \
	"$(INTDIR)\ActiveDoc.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ActiveDoc.res"

"$(OUTDIR)\ActiveDoc.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\ActiveDoc.dll
InputPath=.\Debug\ActiveDoc.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<<
	

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("ActiveDoc.dep")
!INCLUDE "ActiveDoc.dep"
!ELSE 
!MESSAGE Warning: cannot find "ActiveDoc.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "ActiveDoc - Win32 Release" || "$(CFG)" == "ActiveDoc - Win32 Debug"
SOURCE=.\ActiveCtl.cpp

!IF  "$(CFG)" == "ActiveDoc - Win32 Release"


"$(INTDIR)\ActiveCtl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ActiveDoc.pch" ".\ActiveDoc.h"


!ELSEIF  "$(CFG)" == "ActiveDoc - Win32 Debug"


"$(INTDIR)\ActiveCtl.obj"	"$(INTDIR)\ActiveCtl.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ActiveDoc.pch"


!ENDIF 

SOURCE=.\ActiveDoc.cpp

!IF  "$(CFG)" == "ActiveDoc - Win32 Release"


"$(INTDIR)\ActiveDoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ActiveDoc.pch" ".\ActiveDoc_i.c" ".\ActiveDoc.h"


!ELSEIF  "$(CFG)" == "ActiveDoc - Win32 Debug"


"$(INTDIR)\ActiveDoc.obj"	"$(INTDIR)\ActiveDoc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ActiveDoc.pch"


!ENDIF 

SOURCE=.\ActiveDoc.idl

!IF  "$(CFG)" == "ActiveDoc - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "./ActiveDoc.tlb" /h "ActiveDoc.h" /iid "ActiveDoc_i.c" /win32 

".\ActiveDoc.tlb"	".\ActiveDoc.h"	".\ActiveDoc_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ActiveDoc - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "./ActiveDoc.tlb" /h "ActiveDoc.h" /iid "ActiveDoc_i.c" /win32 

".\ActiveDoc.tlb"	".\ActiveDoc.h"	".\ActiveDoc_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\ActiveDoc.rc

"$(INTDIR)\ActiveDoc.res" : $(SOURCE) "$(INTDIR)" ".\ActiveDoc.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "ActiveDoc - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /Fp"$(INTDIR)\ActiveDoc.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ActiveDoc.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<

!ELSEIF  "$(CFG)" == "ActiveDoc - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ActiveDoc.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\ActiveDoc.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

