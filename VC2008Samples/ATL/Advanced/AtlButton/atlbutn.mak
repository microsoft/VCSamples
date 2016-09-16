# Microsoft Developer Studio Generated NMAKE File, Based on atlbutn.dsp
!IF "$(CFG)" == ""
CFG=atlbutn - Win32 Release
!MESSAGE No configuration specified. Defaulting to atlbutn - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "atlbutn - Win32 Release" && "$(CFG)" != "atlbutn - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "atlbutn.mak" CFG="atlbutn - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "atlbutn - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "atlbutn - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")

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

!IF  "$(CFG)" == "atlbutn - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\atlbutn.dll" "$(OUTDIR)\atlbutn.bsc" ".\.\Release\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\atlbutn.obj"
	-@erase "$(INTDIR)\atlbutn.pch"
	-@erase "$(INTDIR)\atlbutn.res"
	-@erase "$(INTDIR)\atlbutn.sbr"
	-@erase "$(INTDIR)\AtlButton.obj"
	-@erase "$(INTDIR)\AtlButton.sbr"
	-@erase "$(INTDIR)\dibapi.obj"
	-@erase "$(INTDIR)\dibapi.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\atlbutn.bsc"
	-@erase "$(OUTDIR)\atlbutn.dll"
	-@erase "$(OUTDIR)\atlbutn.exp"
	-@erase "$(OUTDIR)\atlbutn.lib"
	-@erase ".\atlbutn.h"
	-@erase ".\atlbutn.tlb"
	-@erase ".\atlbutn_i.c"
	-@erase ".\.\Release\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\atlbutn.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\atlbutn.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\atlbutn.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\atlbutn.sbr" \
	"$(INTDIR)\AtlButton.sbr" \
	"$(INTDIR)\dibapi.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\atlbutn.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\atlbutn.pdb" /machine:I386 /def:".\atlbutn.def" /out:"$(OUTDIR)\atlbutn.dll" /implib:"$(OUTDIR)\atlbutn.lib" 
DEF_FILE= \
	".\atlbutn.def"
LINK32_OBJS= \
	"$(INTDIR)\atlbutn.obj" \
	"$(INTDIR)\AtlButton.obj" \
	"$(INTDIR)\dibapi.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\atlbutn.res"

"$(OUTDIR)\atlbutn.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\atlbutn.dll
InputPath=.\Release\atlbutn.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "atlbutn - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\atlbutn.dll" ".\atlbutn.h" ".\atlbutn_i.c" "$(OUTDIR)\atlbutn.bsc" ".\.\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\atlbutn.obj"
	-@erase "$(INTDIR)\atlbutn.pch"
	-@erase "$(INTDIR)\atlbutn.res"
	-@erase "$(INTDIR)\atlbutn.sbr"
	-@erase "$(INTDIR)\AtlButton.obj"
	-@erase "$(INTDIR)\AtlButton.sbr"
	-@erase "$(INTDIR)\dibapi.obj"
	-@erase "$(INTDIR)\dibapi.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\atlbutn.bsc"
	-@erase "$(OUTDIR)\atlbutn.dll"
	-@erase "$(OUTDIR)\atlbutn.exp"
	-@erase "$(OUTDIR)\atlbutn.ilk"
	-@erase "$(OUTDIR)\atlbutn.lib"
	-@erase "$(OUTDIR)\atlbutn.pdb"
	-@erase ".\atlbutn.h"
	-@erase ".\atlbutn.tlb"
	-@erase ".\atlbutn_i.c"
	-@erase ".\.\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\atlbutn.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\atlbutn.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\atlbutn.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\atlbutn.sbr" \
	"$(INTDIR)\AtlButton.sbr" \
	"$(INTDIR)\dibapi.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\atlbutn.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\atlbutn.pdb" /debug /machine:I386 /def:".\atlbutn.def" /out:"$(OUTDIR)\atlbutn.dll" /implib:"$(OUTDIR)\atlbutn.lib" 
DEF_FILE= \
	".\atlbutn.def"
LINK32_OBJS= \
	"$(INTDIR)\atlbutn.obj" \
	"$(INTDIR)\AtlButton.obj" \
	"$(INTDIR)\dibapi.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\atlbutn.res"

"$(OUTDIR)\atlbutn.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\atlbutn.dll
InputPath=.\Debug\atlbutn.dll
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
!IF EXISTS("atlbutn.dep")
!INCLUDE "atlbutn.dep"
!ELSE 
!MESSAGE Warning: cannot find "atlbutn.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "atlbutn - Win32 Release" || "$(CFG)" == "atlbutn - Win32 Debug"
SOURCE=.\atlbutn.cpp

!IF  "$(CFG)" == "atlbutn - Win32 Release"


"$(INTDIR)\atlbutn.obj"	"$(INTDIR)\atlbutn.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\atlbutn.pch" ".\atlbutn.h" ".\atlbutn_i.c"


!ELSEIF  "$(CFG)" == "atlbutn - Win32 Debug"


"$(INTDIR)\atlbutn.obj"	"$(INTDIR)\atlbutn.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\atlbutn.pch"


!ENDIF 

SOURCE=.\atlbutn.idl

!IF  "$(CFG)" == "atlbutn - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "./atlbutn.tlb" /h "atlbutn.h" /iid "atlbutn_i.c" /win32 

".\atlbutn.tlb"	".\atlbutn.h"	".\atlbutn_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "atlbutn - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "./atlbutn.tlb" /h "atlbutn.h" /iid "atlbutn_i.c" /win32 

".\atlbutn.tlb"	".\atlbutn.h"	".\atlbutn_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\atlbutn.rc

"$(INTDIR)\atlbutn.res" : $(SOURCE) "$(INTDIR)" ".\atlbutn.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\AtlButton.cpp

!IF  "$(CFG)" == "atlbutn - Win32 Release"


"$(INTDIR)\AtlButton.obj"	"$(INTDIR)\AtlButton.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\atlbutn.pch" ".\atlbutn.h"


!ELSEIF  "$(CFG)" == "atlbutn - Win32 Debug"


"$(INTDIR)\AtlButton.obj"	"$(INTDIR)\AtlButton.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\atlbutn.pch"


!ENDIF 

SOURCE=.\dibapi.cpp

!IF  "$(CFG)" == "atlbutn - Win32 Release"


"$(INTDIR)\dibapi.obj"	"$(INTDIR)\dibapi.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\atlbutn.pch"


!ELSEIF  "$(CFG)" == "atlbutn - Win32 Debug"


"$(INTDIR)\dibapi.obj"	"$(INTDIR)\dibapi.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\atlbutn.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "atlbutn - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\atlbutn.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\atlbutn.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "atlbutn - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\atlbutn.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\atlbutn.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

