# Microsoft Developer Studio Generated NMAKE File, Based on async.dsp
!IF "$(CFG)" == ""
CFG=Async - Win32 Release
!MESSAGE No configuration specified. Defaulting to Async - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Async - Win32 Release" && "$(CFG)" != "Async - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "async.mak" CFG="Async - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Async - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Async - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")

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

!IF  "$(CFG)" == "Async - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\async.dll" ".\.\Release\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\Async.obj"
	-@erase "$(INTDIR)\async.pch"
	-@erase "$(INTDIR)\Async.res"
	-@erase "$(INTDIR)\ATLAsync.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\async.dll"
	-@erase "$(OUTDIR)\async.exp"
	-@erase "$(OUTDIR)\async.lib"
	-@erase ".\async.h"
	-@erase ".\Async.tlb"
	-@erase ".\async_i.c"
	-@erase ".\.\Release\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\async.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Async.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\async.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\async.pdb" /machine:I386 /def:".\Async.def" /out:"$(OUTDIR)\async.dll" /implib:"$(OUTDIR)\async.lib" 
DEF_FILE= \
	".\Async.def"
LINK32_OBJS= \
	"$(INTDIR)\Async.obj" \
	"$(INTDIR)\ATLAsync.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Async.res"

"$(OUTDIR)\async.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\async.dll
InputPath=.\Release\async.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "Async - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\async.dll" ".\async_i.c" ".\async.h" ".\.\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\Async.obj"
	-@erase "$(INTDIR)\async.pch"
	-@erase "$(INTDIR)\Async.res"
	-@erase "$(INTDIR)\ATLAsync.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\async.dll"
	-@erase "$(OUTDIR)\async.exp"
	-@erase "$(OUTDIR)\async.ilk"
	-@erase "$(OUTDIR)\async.lib"
	-@erase "$(OUTDIR)\async.pdb"
	-@erase ".\async.h"
	-@erase ".\Async.tlb"
	-@erase ".\async_i.c"
	-@erase ".\.\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\async.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Async.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\async.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\async.pdb" /debug /machine:I386 /def:".\Async.def" /out:"$(OUTDIR)\async.dll" /implib:"$(OUTDIR)\async.lib" 
DEF_FILE= \
	".\Async.def"
LINK32_OBJS= \
	"$(INTDIR)\Async.obj" \
	"$(INTDIR)\ATLAsync.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Async.res"

"$(OUTDIR)\async.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\async.dll
InputPath=.\Debug\async.dll
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
!IF EXISTS("async.dep")
!INCLUDE "async.dep"
!ELSE 
!MESSAGE Warning: cannot find "async.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Async - Win32 Release" || "$(CFG)" == "Async - Win32 Debug"
SOURCE=.\Async.cpp

"$(INTDIR)\Async.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\async.pch" ".\async_i.c" ".\async.h"


SOURCE=.\Async.idl

!IF  "$(CFG)" == "Async - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "./Async.tlb" /h "Async.h" /iid "Async_i.c" /win32 

".\Async.tlb"	".\async.h"	".\async_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Async - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "./Async.tlb" /h "Async.h" /iid "Async_i.c" /win32 

".\Async.tlb"	".\async.h"	".\async_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Async.rc

"$(INTDIR)\Async.res" : $(SOURCE) "$(INTDIR)" ".\Async.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\ATLAsync.cpp

"$(INTDIR)\ATLAsync.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\async.pch" ".\async.h"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "Async - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\async.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\async.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Async - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\async.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\async.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

