# Microsoft Developer Studio Generated NMAKE File, Based on SubEdit.dsp
!IF "$(CFG)" == ""
CFG=SubEdit - Win32 Release
!MESSAGE No configuration specified. Defaulting to SubEdit - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "SubEdit - Win32 Release" && "$(CFG)" != "SubEdit - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "SubEdit.mak" CFG="SubEdit - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SubEdit - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "SubEdit - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "SubEdit - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\SubEdit.dll" ".\.\Release\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\AtlEdit.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\SubEdit.obj"
	-@erase "$(INTDIR)\SubEdit.pch"
	-@erase "$(INTDIR)\SubEdit.res"
	-@erase "$(OUTDIR)\SubEdit.dll"
	-@erase "$(OUTDIR)\SubEdit.exp"
	-@erase "$(OUTDIR)\SubEdit.lib"
	-@erase ".\SubEdit.h"
	-@erase ".\SubEdit.tlb"
	-@erase ".\SubEdit_i.c"
	-@erase ".\.\Release\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\SubEdit.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\SubEdit.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\SubEdit.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\SubEdit.pdb" /machine:I386 /def:".\SubEdit.def" /out:"$(OUTDIR)\SubEdit.dll" /implib:"$(OUTDIR)\SubEdit.lib" 
DEF_FILE= \
	".\SubEdit.def"
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\SubEdit.obj" \
	"$(INTDIR)\AtlEdit.obj" \
	"$(INTDIR)\SubEdit.res"

"$(OUTDIR)\SubEdit.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\SubEdit.dll
InputPath=.\Release\SubEdit.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
<< 
	

!ELSEIF  "$(CFG)" == "SubEdit - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\SubEdit.dll" ".\.\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\AtlEdit.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\SubEdit.obj"
	-@erase "$(INTDIR)\SubEdit.pch"
	-@erase "$(INTDIR)\SubEdit.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\SubEdit.dll"
	-@erase "$(OUTDIR)\SubEdit.exp"
	-@erase "$(OUTDIR)\SubEdit.ilk"
	-@erase "$(OUTDIR)\SubEdit.lib"
	-@erase "$(OUTDIR)\SubEdit.pdb"
	-@erase ".\SubEdit.h"
	-@erase ".\SubEdit.tlb"
	-@erase ".\SubEdit_i.c"
	-@erase ".\.\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\SubEdit.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\SubEdit.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\SubEdit.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\SubEdit.pdb" /debug /machine:I386 /def:".\SubEdit.def" /out:"$(OUTDIR)\SubEdit.dll" /implib:"$(OUTDIR)\SubEdit.lib" 
DEF_FILE= \
	".\SubEdit.def"
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\SubEdit.obj" \
	"$(INTDIR)\AtlEdit.obj" \
	"$(INTDIR)\SubEdit.res"

"$(OUTDIR)\SubEdit.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\SubEdit.dll
InputPath=.\Debug\SubEdit.dll
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
!IF EXISTS("SubEdit.dep")
!INCLUDE "SubEdit.dep"
!ELSE 
!MESSAGE Warning: cannot find "SubEdit.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "SubEdit - Win32 Release" || "$(CFG)" == "SubEdit - Win32 Debug"
SOURCE=.\AtlEdit.cpp

"$(INTDIR)\AtlEdit.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\SubEdit.pch" ".\SubEdit.h"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "SubEdit - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\SubEdit.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\SubEdit.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SubEdit - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\SubEdit.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\SubEdit.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\SubEdit.cpp

"$(INTDIR)\SubEdit.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\SubEdit.pch" ".\SubEdit.h" ".\SubEdit_i.c"


SOURCE=.\SubEdit.idl

!IF  "$(CFG)" == "SubEdit - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb ".\SubEdit.tlb" /h "SubEdit.h" /iid "SubEdit_i.c" /win32 

".\SubEdit.tlb"	".\SubEdit.h"	".\SubEdit_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SubEdit - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb ".\SubEdit.tlb" /h "SubEdit.h" /iid "SubEdit_i.c" /win32 

".\SubEdit.tlb"	".\SubEdit.h"	".\SubEdit_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\SubEdit.rc

"$(INTDIR)\SubEdit.res" : $(SOURCE) "$(INTDIR)" ".\SubEdit.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)



!ENDIF 

