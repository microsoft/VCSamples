# Microsoft Developer Studio Generated NMAKE File, Based on Aggreg.dsp
!IF "$(CFG)" == ""
CFG=Aggreg - Win32 Release
!MESSAGE No configuration specified. Defaulting to Aggreg - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Aggreg - Win32 Release" && "$(CFG)" != "Aggreg - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Aggreg.mak" CFG="Aggreg - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Aggreg - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Aggreg - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "Aggreg - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\Aggreg.dll" ".\.\Release\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\Agg.obj"
	-@erase "$(INTDIR)\AggBlind.obj"
	-@erase "$(INTDIR)\Aggreg.obj"
	-@erase "$(INTDIR)\Aggreg.pch"
	-@erase "$(INTDIR)\Aggreg.res"
	-@erase "$(INTDIR)\AutoAgg.obj"
	-@erase "$(INTDIR)\AutoAggB.obj"
	-@erase "$(INTDIR)\preagg.obj"
	-@erase "$(OUTDIR)\Aggreg.dll"
	-@erase "$(OUTDIR)\Aggreg.exp"
	-@erase "$(OUTDIR)\Aggreg.lib"
	-@erase ".\Aggreg.h"
	-@erase ".\Aggreg.tlb"
	-@erase ".\Aggreg_i.c"
	-@erase ".\.\Release\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W4 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\Aggreg.pch" /Yu"preagg.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Aggreg.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Aggreg.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\Aggreg.pdb" /machine:I386 /def:".\Aggreg.def" /out:"$(OUTDIR)\Aggreg.dll" /implib:"$(OUTDIR)\Aggreg.lib" 
DEF_FILE= \
	".\Aggreg.def"
LINK32_OBJS= \
	"$(INTDIR)\Aggreg.obj" \
	"$(INTDIR)\Agg.obj" \
	"$(INTDIR)\AggBlind.obj" \
	"$(INTDIR)\AutoAgg.obj" \
	"$(INTDIR)\AutoAggB.obj" \
	"$(INTDIR)\preagg.obj" \
	"$(INTDIR)\Aggreg.res"

"$(OUTDIR)\Aggreg.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\Aggreg.dll
InputPath=.\Release\Aggreg.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
<< 
	

!ELSEIF  "$(CFG)" == "Aggreg - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Aggreg.dll" ".\.\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\Agg.obj"
	-@erase "$(INTDIR)\AggBlind.obj"
	-@erase "$(INTDIR)\Aggreg.obj"
	-@erase "$(INTDIR)\Aggreg.pch"
	-@erase "$(INTDIR)\Aggreg.res"
	-@erase "$(INTDIR)\AutoAgg.obj"
	-@erase "$(INTDIR)\AutoAggB.obj"
	-@erase "$(INTDIR)\preagg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Aggreg.dll"
	-@erase "$(OUTDIR)\Aggreg.exp"
	-@erase "$(OUTDIR)\Aggreg.ilk"
	-@erase "$(OUTDIR)\Aggreg.lib"
	-@erase "$(OUTDIR)\Aggreg.pdb"
	-@erase ".\Aggreg.h"
	-@erase ".\Aggreg.tlb"
	-@erase ".\Aggreg_i.c"
	-@erase ".\.\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W4 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\Aggreg.pch" /Yu"preagg.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Aggreg.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Aggreg.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\Aggreg.pdb" /debug /machine:I386 /def:".\Aggreg.def" /out:"$(OUTDIR)\Aggreg.dll" /implib:"$(OUTDIR)\Aggreg.lib" 
DEF_FILE= \
	".\Aggreg.def"
LINK32_OBJS= \
	"$(INTDIR)\Aggreg.obj" \
	"$(INTDIR)\Agg.obj" \
	"$(INTDIR)\AggBlind.obj" \
	"$(INTDIR)\AutoAgg.obj" \
	"$(INTDIR)\AutoAggB.obj" \
	"$(INTDIR)\preagg.obj" \
	"$(INTDIR)\Aggreg.res"

"$(OUTDIR)\Aggreg.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\Aggreg.dll
InputPath=.\Debug\Aggreg.dll
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
!IF EXISTS("Aggreg.dep")
!INCLUDE "Aggreg.dep"
!ELSE 
!MESSAGE Warning: cannot find "Aggreg.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Aggreg - Win32 Release" || "$(CFG)" == "Aggreg - Win32 Debug"
SOURCE=.\Agg.cpp

"$(INTDIR)\Agg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Aggreg.pch" ".\Aggreg.h"


SOURCE=.\AggBlind.cpp

"$(INTDIR)\AggBlind.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Aggreg.pch" ".\Aggreg.h"


SOURCE=.\Aggreg.cpp

"$(INTDIR)\Aggreg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Aggreg.pch" ".\Aggreg.h" ".\Aggreg_i.c"


SOURCE=.\Aggreg.idl

!IF  "$(CFG)" == "Aggreg - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb ".\Aggreg.tlb" /h "Aggreg.h" /iid "Aggreg_i.c" /mktyplib203 /win32 

".\Aggreg.tlb"	".\Aggreg.h"	".\Aggreg_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Aggreg - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb ".\Aggreg.tlb" /h "Aggreg.h" /iid "Aggreg_i.c" /mktyplib203 /win32 

".\Aggreg.tlb"	".\Aggreg.h"	".\Aggreg_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Aggreg.rc

"$(INTDIR)\Aggreg.res" : $(SOURCE) "$(INTDIR)" ".\Aggreg.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\AutoAgg.cpp

"$(INTDIR)\AutoAgg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Aggreg.pch" ".\Aggreg.h"


SOURCE=.\AutoAggB.cpp

"$(INTDIR)\AutoAggB.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Aggreg.pch" ".\Aggreg.h"


SOURCE=.\preagg.cpp

!IF  "$(CFG)" == "Aggreg - Win32 Release"

CPP_SWITCHES=/nologo /MT /W4 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\Aggreg.pch" /Yc"preagg.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\preagg.obj"	"$(INTDIR)\Aggreg.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Aggreg - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W4 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\Aggreg.pch" /Yc"preagg.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\preagg.obj"	"$(INTDIR)\Aggreg.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

