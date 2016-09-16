# Microsoft Developer Studio Generated NMAKE File, Based on circcoll.dsp
!IF "$(CFG)" == ""
CFG=CircColl - Win32 Release
!MESSAGE No configuration specified. Defaulting to CircColl - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "CircColl - Win32 Release" && "$(CFG)" != "CircColl - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "circcoll.mak" CFG="CircColl - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CircColl - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "CircColl - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "CircColl - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\circcoll.dll" ".\.\Release\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\CircColl.obj"
	-@erase "$(INTDIR)\circcoll.pch"
	-@erase "$(INTDIR)\CircColl.res"
	-@erase "$(INTDIR)\objects.obj"
	-@erase "$(INTDIR)\precircc.obj"
	-@erase "$(OUTDIR)\circcoll.dll"
	-@erase "$(OUTDIR)\circcoll.exp"
	-@erase "$(OUTDIR)\circcoll.lib"
	-@erase ".\CircColl.h"
	-@erase ".\CircColl.tlb"
	-@erase ".\CircColl_i.c"
	-@erase ".\.\Release\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\circcoll.pch" /Yu"precircc.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CircColl.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\circcoll.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\circcoll.pdb" /machine:I386 /def:".\CircColl.def" /out:"$(OUTDIR)\circcoll.dll" /implib:"$(OUTDIR)\circcoll.lib" 
DEF_FILE= \
	".\CircColl.def"
LINK32_OBJS= \
	"$(INTDIR)\CircColl.obj" \
	"$(INTDIR)\objects.obj" \
	"$(INTDIR)\precircc.obj" \
	"$(INTDIR)\CircColl.res"

"$(OUTDIR)\circcoll.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\circcoll.dll
InputPath=.\Release\circcoll.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
<< 
	

!ELSEIF  "$(CFG)" == "CircColl - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\circcoll.dll" ".\.\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\CircColl.obj"
	-@erase "$(INTDIR)\circcoll.pch"
	-@erase "$(INTDIR)\CircColl.res"
	-@erase "$(INTDIR)\objects.obj"
	-@erase "$(INTDIR)\precircc.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\circcoll.dll"
	-@erase "$(OUTDIR)\circcoll.exp"
	-@erase "$(OUTDIR)\circcoll.ilk"
	-@erase "$(OUTDIR)\circcoll.lib"
	-@erase "$(OUTDIR)\circcoll.pdb"
	-@erase ".\.\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\circcoll.pch" /Yu"precircc.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CircColl.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\circcoll.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\circcoll.pdb" /debug /machine:I386 /def:".\CircColl.def" /out:"$(OUTDIR)\circcoll.dll" /implib:"$(OUTDIR)\circcoll.lib" 
DEF_FILE= \
	".\CircColl.def"
LINK32_OBJS= \
	"$(INTDIR)\CircColl.obj" \
	"$(INTDIR)\objects.obj" \
	"$(INTDIR)\precircc.obj" \
	"$(INTDIR)\CircColl.res"

"$(OUTDIR)\circcoll.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\circcoll.dll
InputPath=.\Debug\circcoll.dll
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
!IF EXISTS("circcoll.dep")
!INCLUDE "circcoll.dep"
!ELSE 
!MESSAGE Warning: cannot find "circcoll.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "CircColl - Win32 Release" || "$(CFG)" == "CircColl - Win32 Debug"
SOURCE=.\CircColl.cpp

"$(INTDIR)\CircColl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\circcoll.pch" ".\CircColl.h" ".\CircColl_i.c"


SOURCE=.\CircColl.idl

!IF  "$(CFG)" == "CircColl - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "./CircColl.tlb" /h "CircColl.h" /iid "CircColl_i.c" /win32 

".\CircColl.tlb"	".\CircColl.h"	".\CircColl_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CircColl - Win32 Debug"

InputPath=.\CircColl.idl

"CircColl.tlb"	"CircColl.h"	"CircColl_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	midl /h CircColl.h CircColl.idl
<< 
	

!ENDIF 

SOURCE=.\CircColl.rc

"$(INTDIR)\CircColl.res" : $(SOURCE) "$(INTDIR)" ".\CircColl.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\objects.cpp

!IF  "$(CFG)" == "CircColl - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\circcoll.pch" /Yu"precircc.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\objects.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\circcoll.pch" ".\CircColl.h"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CircColl - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\circcoll.pch" /Yu"precircc.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\objects.obj" : $(SOURCE) "$(INTDIR)" ".\CircColl.h" "$(INTDIR)\circcoll.pch"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\precircc.cpp

!IF  "$(CFG)" == "CircColl - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\circcoll.pch" /Yc"precircc.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\precircc.obj"	"$(INTDIR)\circcoll.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CircColl - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\circcoll.pch" /Yc"precircc.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\precircc.obj"	"$(INTDIR)\circcoll.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<



!ENDIF 


!ENDIF 

