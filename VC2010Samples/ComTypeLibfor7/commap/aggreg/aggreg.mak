# Microsoft Developer Studio Generated NMAKE File, Based on Aggreg.dsp
!IF "$(CFG)" == ""
CFG=Aggreg - Win32 Release
!MESSAGE No configuration specified.  Defaulting to Aggreg - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Aggreg - Win32 Release" && "$(CFG)" != "Aggreg - Win32 Debug"\
 && "$(CFG)" != "Aggreg - Win32 Unicode Release" && "$(CFG)" !=\
 "Aggreg - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "Aggreg.mak" CFG="Aggreg - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Aggreg - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Aggreg - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Aggreg - Win32 Unicode Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Aggreg - Win32 Unicode Debug" (based on\
 "Win32 (x86) Dynamic-Link Library")
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

ALL : "Aggreg_i.c" "Aggreg.tlb" "Aggreg.h" "$(OUTDIR)\Aggreg.dll"\
 "$(OutDir)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\Agg.obj"
	-@erase "$(INTDIR)\AggBlind.obj"
	-@erase "$(INTDIR)\Aggreg.obj"
	-@erase "$(INTDIR)\Aggreg.pch"
	-@erase "$(INTDIR)\Aggreg.res"
	-@erase "$(INTDIR)\AutoAgg.obj"
	-@erase "$(INTDIR)\AutoAggB.obj"
	-@erase "$(INTDIR)\preagg.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\Aggreg.dll"
	-@erase "$(OUTDIR)\Aggreg.exp"
	-@erase "$(OUTDIR)\Aggreg.lib"
	-@erase "$(OutDir)\regsvr32.trg"
	-@erase "Aggreg.h"
	-@erase "Aggreg.tlb"
	-@erase "Aggreg_i.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\Aggreg.pch" /Yu"preagg.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Aggreg.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Aggreg.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /base:"0x10020000" /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)\Aggreg.pdb" /machine:I386 /def:".\Aggreg.def"\
 /out:"$(OUTDIR)\Aggreg.dll" /implib:"$(OUTDIR)\Aggreg.lib" 
DEF_FILE= \
	".\Aggreg.def"
LINK32_OBJS= \
	"$(INTDIR)\Agg.obj" \
	"$(INTDIR)\AggBlind.obj" \
	"$(INTDIR)\Aggreg.obj" \
	"$(INTDIR)\Aggreg.res" \
	"$(INTDIR)\AutoAgg.obj" \
	"$(INTDIR)\AutoAggB.obj" \
	"$(INTDIR)\preagg.obj"

"$(OUTDIR)\Aggreg.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\Aggreg.dll
InputPath=.\Release\Aggreg.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "Aggreg - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "Aggreg_i.c" "Aggreg.tlb" "Aggreg.h" "$(OUTDIR)\Aggreg.dll"\
 "$(OutDir)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\Agg.obj"
	-@erase "$(INTDIR)\AggBlind.obj"
	-@erase "$(INTDIR)\Aggreg.obj"
	-@erase "$(INTDIR)\Aggreg.pch"
	-@erase "$(INTDIR)\Aggreg.res"
	-@erase "$(INTDIR)\AutoAgg.obj"
	-@erase "$(INTDIR)\AutoAggB.obj"
	-@erase "$(INTDIR)\preagg.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\Aggreg.dll"
	-@erase "$(OUTDIR)\Aggreg.exp"
	-@erase "$(OUTDIR)\Aggreg.ilk"
	-@erase "$(OUTDIR)\Aggreg.lib"
	-@erase "$(OUTDIR)\Aggreg.pdb"
	-@erase "$(OutDir)\regsvr32.trg"
	-@erase "Aggreg.h"
	-@erase "Aggreg.tlb"
	-@erase "Aggreg_i.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\Aggreg.pch" /Yu"preagg.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Aggreg.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Aggreg.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /base:"0x10020000" /subsystem:windows /dll\
 /incremental:yes /pdb:"$(OUTDIR)\Aggreg.pdb" /debug /machine:I386\
 /def:".\Aggreg.def" /out:"$(OUTDIR)\Aggreg.dll" /implib:"$(OUTDIR)\Aggreg.lib" 
DEF_FILE= \
	".\Aggreg.def"
LINK32_OBJS= \
	"$(INTDIR)\Agg.obj" \
	"$(INTDIR)\AggBlind.obj" \
	"$(INTDIR)\Aggreg.obj" \
	"$(INTDIR)\Aggreg.res" \
	"$(INTDIR)\AutoAgg.obj" \
	"$(INTDIR)\AutoAggB.obj" \
	"$(INTDIR)\preagg.obj"

"$(OUTDIR)\Aggreg.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\Aggreg.dll
InputPath=.\Debug\Aggreg.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "Aggreg - Win32 Unicode Release"

OUTDIR=.\ReleaseU
INTDIR=.\ReleaseU
# Begin Custom Macros
OutDir=.\.\ReleaseU
# End Custom Macros

ALL : "Aggreg_i.c" "Aggreg.tlb" "Aggreg.h" "$(OUTDIR)\Aggreg.dll"\
 "$(OutDir)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\Agg.obj"
	-@erase "$(INTDIR)\AggBlind.obj"
	-@erase "$(INTDIR)\Aggreg.obj"
	-@erase "$(INTDIR)\Aggreg.pch"
	-@erase "$(INTDIR)\Aggreg.res"
	-@erase "$(INTDIR)\AutoAgg.obj"
	-@erase "$(INTDIR)\AutoAggB.obj"
	-@erase "$(INTDIR)\preagg.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\Aggreg.dll"
	-@erase "$(OUTDIR)\Aggreg.exp"
	-@erase "$(OUTDIR)\Aggreg.lib"
	-@erase "$(OutDir)\regsvr32.trg"
	-@erase "Aggreg.h"
	-@erase "Aggreg.tlb"
	-@erase "Aggreg_i.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\Aggreg.pch" /Yu"preagg.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Aggreg.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Aggreg.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /base:"0x10020000" /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)\Aggreg.pdb" /machine:I386 /def:".\Aggreg.def"\
 /out:"$(OUTDIR)\Aggreg.dll" /implib:"$(OUTDIR)\Aggreg.lib" 
DEF_FILE= \
	".\Aggreg.def"
LINK32_OBJS= \
	"$(INTDIR)\Agg.obj" \
	"$(INTDIR)\AggBlind.obj" \
	"$(INTDIR)\Aggreg.obj" \
	"$(INTDIR)\Aggreg.res" \
	"$(INTDIR)\AutoAgg.obj" \
	"$(INTDIR)\AutoAggB.obj" \
	"$(INTDIR)\preagg.obj"

"$(OUTDIR)\Aggreg.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\ReleaseU
TargetPath=.\ReleaseU\Aggreg.dll
InputPath=.\ReleaseU\Aggreg.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "Aggreg - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\.\DebugU
# End Custom Macros

ALL : "Aggreg_i.c" "Aggreg.tlb" "Aggreg.h" "$(OUTDIR)\Aggreg.dll"\
 "$(OutDir)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\Agg.obj"
	-@erase "$(INTDIR)\AggBlind.obj"
	-@erase "$(INTDIR)\Aggreg.obj"
	-@erase "$(INTDIR)\Aggreg.pch"
	-@erase "$(INTDIR)\Aggreg.res"
	-@erase "$(INTDIR)\AutoAgg.obj"
	-@erase "$(INTDIR)\AutoAggB.obj"
	-@erase "$(INTDIR)\preagg.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\Aggreg.dll"
	-@erase "$(OUTDIR)\Aggreg.exp"
	-@erase "$(OUTDIR)\Aggreg.ilk"
	-@erase "$(OUTDIR)\Aggreg.lib"
	-@erase "$(OUTDIR)\Aggreg.pdb"
	-@erase "$(OutDir)\regsvr32.trg"
	-@erase "Aggreg.h"
	-@erase "Aggreg.tlb"
	-@erase "Aggreg_i.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\Aggreg.pch" /Yu"preagg.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\DebugU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Aggreg.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Aggreg.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /base:"0x10020000" /subsystem:windows /dll\
 /incremental:yes /pdb:"$(OUTDIR)\Aggreg.pdb" /debug /machine:I386\
 /def:".\Aggreg.def" /out:"$(OUTDIR)\Aggreg.dll" /implib:"$(OUTDIR)\Aggreg.lib" 
DEF_FILE= \
	".\Aggreg.def"
LINK32_OBJS= \
	"$(INTDIR)\Agg.obj" \
	"$(INTDIR)\AggBlind.obj" \
	"$(INTDIR)\Aggreg.obj" \
	"$(INTDIR)\Aggreg.res" \
	"$(INTDIR)\AutoAgg.obj" \
	"$(INTDIR)\AutoAggB.obj" \
	"$(INTDIR)\preagg.obj"

"$(OUTDIR)\Aggreg.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\DebugU
TargetPath=.\DebugU\Aggreg.dll
InputPath=.\DebugU\Aggreg.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ENDIF 

.c{$(CPP_OBJS)}.obj::
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr::
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) $(CPP_PROJ) $<  


!IF "$(CFG)" == "Aggreg - Win32 Release" || "$(CFG)" == "Aggreg - Win32 Debug"\
 || "$(CFG)" == "Aggreg - Win32 Unicode Release" || "$(CFG)" ==\
 "Aggreg - Win32 Unicode Debug"
SOURCE=.\Agg.cpp

!IF  "$(CFG)" == "Aggreg - Win32 Release"

DEP_CPP_AGG_C=\
	".\Agg.h"\
	

"$(INTDIR)\Agg.obj" : $(SOURCE) $(DEP_CPP_AGG_C) "$(INTDIR)"\
 "$(INTDIR)\Aggreg.pch"


!ELSEIF  "$(CFG)" == "Aggreg - Win32 Debug"

DEP_CPP_AGG_C=\
	".\Agg.h"\
	".\preagg.h"\
	

"$(INTDIR)\Agg.obj" : $(SOURCE) $(DEP_CPP_AGG_C) "$(INTDIR)"\
 "$(INTDIR)\Aggreg.pch"


!ELSEIF  "$(CFG)" == "Aggreg - Win32 Unicode Release"

DEP_CPP_AGG_C=\
	".\Agg.h"\
	".\preagg.h"\
	

"$(INTDIR)\Agg.obj" : $(SOURCE) $(DEP_CPP_AGG_C) "$(INTDIR)"\
 "$(INTDIR)\Aggreg.pch"


!ELSEIF  "$(CFG)" == "Aggreg - Win32 Unicode Debug"

DEP_CPP_AGG_C=\
	".\Agg.h"\
	".\preagg.h"\
	

"$(INTDIR)\Agg.obj" : $(SOURCE) $(DEP_CPP_AGG_C) "$(INTDIR)"\
 "$(INTDIR)\Aggreg.pch"


!ENDIF 

SOURCE=.\Agg.rgs
SOURCE=.\AggBlind.cpp

!IF  "$(CFG)" == "Aggreg - Win32 Release"

DEP_CPP_AGGBL=\
	".\AggBlind.h"\
	

"$(INTDIR)\AggBlind.obj" : $(SOURCE) $(DEP_CPP_AGGBL) "$(INTDIR)"\
 "$(INTDIR)\Aggreg.pch"


!ELSEIF  "$(CFG)" == "Aggreg - Win32 Debug"

DEP_CPP_AGGBL=\
	".\AggBlind.h"\
	".\preagg.h"\
	

"$(INTDIR)\AggBlind.obj" : $(SOURCE) $(DEP_CPP_AGGBL) "$(INTDIR)"\
 "$(INTDIR)\Aggreg.pch"


!ELSEIF  "$(CFG)" == "Aggreg - Win32 Unicode Release"

DEP_CPP_AGGBL=\
	".\AggBlind.h"\
	".\preagg.h"\
	

"$(INTDIR)\AggBlind.obj" : $(SOURCE) $(DEP_CPP_AGGBL) "$(INTDIR)"\
 "$(INTDIR)\Aggreg.pch"


!ELSEIF  "$(CFG)" == "Aggreg - Win32 Unicode Debug"

DEP_CPP_AGGBL=\
	".\AggBlind.h"\
	".\preagg.h"\
	

"$(INTDIR)\AggBlind.obj" : $(SOURCE) $(DEP_CPP_AGGBL) "$(INTDIR)"\
 "$(INTDIR)\Aggreg.pch"


!ENDIF 

SOURCE=.\AggBlind.rgs
SOURCE=.\Aggreg.cpp

!IF  "$(CFG)" == "Aggreg - Win32 Release"

DEP_CPP_AGGRE=\
	".\Agg.h"\
	".\AggBlind.h"\
	".\AutoAgg.h"\
	".\AutoAggB.h"\
	

"$(INTDIR)\Aggreg.obj" : $(SOURCE) $(DEP_CPP_AGGRE) "$(INTDIR)"\
 "$(INTDIR)\Aggreg.pch"


!ELSEIF  "$(CFG)" == "Aggreg - Win32 Debug"

DEP_CPP_AGGRE=\
	".\Agg.h"\
	".\AggBlind.h"\
	".\AutoAgg.h"\
	".\AutoAggB.h"\
	".\preagg.h"\
	

"$(INTDIR)\Aggreg.obj" : $(SOURCE) $(DEP_CPP_AGGRE) "$(INTDIR)"\
 "$(INTDIR)\Aggreg.pch"


!ELSEIF  "$(CFG)" == "Aggreg - Win32 Unicode Release"

DEP_CPP_AGGRE=\
	".\Agg.h"\
	".\AggBlind.h"\
	".\AutoAgg.h"\
	".\AutoAggB.h"\
	".\preagg.h"\
	

"$(INTDIR)\Aggreg.obj" : $(SOURCE) $(DEP_CPP_AGGRE) "$(INTDIR)"\
 "$(INTDIR)\Aggreg.pch"


!ELSEIF  "$(CFG)" == "Aggreg - Win32 Unicode Debug"

DEP_CPP_AGGRE=\
	".\Agg.h"\
	".\AggBlind.h"\
	".\AutoAgg.h"\
	".\AutoAggB.h"\
	".\preagg.h"\
	

"$(INTDIR)\Aggreg.obj" : $(SOURCE) $(DEP_CPP_AGGRE) "$(INTDIR)"\
 "$(INTDIR)\Aggreg.pch"


!ENDIF 

SOURCE=.\Aggreg.def
SOURCE=.\Aggreg.idl

!IF  "$(CFG)" == "Aggreg - Win32 Release"

InputPath=.\Aggreg.idl

".\Aggreg.tlb"	".\Aggreg.h"	".\Aggreg_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl Aggreg.idl

!ELSEIF  "$(CFG)" == "Aggreg - Win32 Debug"

InputPath=.\Aggreg.idl

".\Aggreg.tlb"	".\Aggreg.h"	".\Aggreg_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl Aggreg.idl

!ELSEIF  "$(CFG)" == "Aggreg - Win32 Unicode Release"

InputPath=.\Aggreg.idl

".\Aggreg.tlb"	".\Aggreg.h"	".\Aggreg_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl Aggreg.idl

!ELSEIF  "$(CFG)" == "Aggreg - Win32 Unicode Debug"

InputPath=.\Aggreg.idl

".\Aggreg.tlb"	".\Aggreg.h"	".\Aggreg_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl Aggreg.idl

!ENDIF 

SOURCE=.\Aggreg.rc
DEP_RSC_AGGREG=\
	".\Agg.rgs"\
	".\AggBlind.rgs"\
	".\Aggreg.tlb"\
	".\AutoAgg.rgs"\
	".\AutoAggB.rgs"\
	

!IF  "$(CFG)" == "Aggreg - Win32 Release"


"$(INTDIR)\Aggreg.res" : $(SOURCE) $(DEP_RSC_AGGREG) "$(INTDIR)" ".\Aggreg.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Aggreg - Win32 Debug"


"$(INTDIR)\Aggreg.res" : $(SOURCE) $(DEP_RSC_AGGREG) "$(INTDIR)" ".\Aggreg.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Aggreg - Win32 Unicode Release"


"$(INTDIR)\Aggreg.res" : $(SOURCE) $(DEP_RSC_AGGREG) "$(INTDIR)" ".\Aggreg.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Aggreg - Win32 Unicode Debug"


"$(INTDIR)\Aggreg.res" : $(SOURCE) $(DEP_RSC_AGGREG) "$(INTDIR)" ".\Aggreg.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\AutoAgg.cpp

!IF  "$(CFG)" == "Aggreg - Win32 Release"

DEP_CPP_AUTOA=\
	".\AutoAgg.h"\
	

"$(INTDIR)\AutoAgg.obj" : $(SOURCE) $(DEP_CPP_AUTOA) "$(INTDIR)"\
 "$(INTDIR)\Aggreg.pch"


!ELSEIF  "$(CFG)" == "Aggreg - Win32 Debug"

DEP_CPP_AUTOA=\
	".\AutoAgg.h"\
	".\preagg.h"\
	

"$(INTDIR)\AutoAgg.obj" : $(SOURCE) $(DEP_CPP_AUTOA) "$(INTDIR)"\
 "$(INTDIR)\Aggreg.pch"


!ELSEIF  "$(CFG)" == "Aggreg - Win32 Unicode Release"

DEP_CPP_AUTOA=\
	".\AutoAgg.h"\
	".\preagg.h"\
	

"$(INTDIR)\AutoAgg.obj" : $(SOURCE) $(DEP_CPP_AUTOA) "$(INTDIR)"\
 "$(INTDIR)\Aggreg.pch"


!ELSEIF  "$(CFG)" == "Aggreg - Win32 Unicode Debug"

DEP_CPP_AUTOA=\
	".\AutoAgg.h"\
	".\preagg.h"\
	

"$(INTDIR)\AutoAgg.obj" : $(SOURCE) $(DEP_CPP_AUTOA) "$(INTDIR)"\
 "$(INTDIR)\Aggreg.pch"


!ENDIF 

SOURCE=.\AutoAgg.rgs
SOURCE=.\AutoAggB.cpp

!IF  "$(CFG)" == "Aggreg - Win32 Release"

DEP_CPP_AUTOAG=\
	".\AutoAggB.h"\
	

"$(INTDIR)\AutoAggB.obj" : $(SOURCE) $(DEP_CPP_AUTOAG) "$(INTDIR)"\
 "$(INTDIR)\Aggreg.pch"


!ELSEIF  "$(CFG)" == "Aggreg - Win32 Debug"

DEP_CPP_AUTOAG=\
	".\AutoAggB.h"\
	".\preagg.h"\
	

"$(INTDIR)\AutoAggB.obj" : $(SOURCE) $(DEP_CPP_AUTOAG) "$(INTDIR)"\
 "$(INTDIR)\Aggreg.pch"


!ELSEIF  "$(CFG)" == "Aggreg - Win32 Unicode Release"

DEP_CPP_AUTOAG=\
	".\AutoAggB.h"\
	".\preagg.h"\
	

"$(INTDIR)\AutoAggB.obj" : $(SOURCE) $(DEP_CPP_AUTOAG) "$(INTDIR)"\
 "$(INTDIR)\Aggreg.pch"


!ELSEIF  "$(CFG)" == "Aggreg - Win32 Unicode Debug"

DEP_CPP_AUTOAG=\
	".\AutoAggB.h"\
	".\preagg.h"\
	

"$(INTDIR)\AutoAggB.obj" : $(SOURCE) $(DEP_CPP_AUTOAG) "$(INTDIR)"\
 "$(INTDIR)\Aggreg.pch"


!ENDIF 

SOURCE=.\AutoAggB.rgs
SOURCE=.\preagg.cpp

!IF  "$(CFG)" == "Aggreg - Win32 Release"

DEP_CPP_PREAG=\
	".\Aggreg.tlb"\
	".\preagg.h"\
	

"$(INTDIR)\preagg.obj"	"$(INTDIR)\Aggreg.pch" : $(SOURCE) $(DEP_CPP_PREAG)\
 "$(INTDIR)" ".\Aggreg.tlb"
	$(CPP) /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS"\
 /D "_USRDLL" /Fp"$(INTDIR)\Aggreg.pch" /Yc"preagg.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ELSEIF  "$(CFG)" == "Aggreg - Win32 Debug"

DEP_CPP_PREAG=\
	".\preagg.h"\
	

"$(INTDIR)\preagg.obj"	"$(INTDIR)\Aggreg.pch" : $(SOURCE) $(DEP_CPP_PREAG)\
 "$(INTDIR)"
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\Aggreg.pch" /Yc"preagg.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ELSEIF  "$(CFG)" == "Aggreg - Win32 Unicode Release"

DEP_CPP_PREAG=\
	".\preagg.h"\
	

"$(INTDIR)\preagg.obj"	"$(INTDIR)\Aggreg.pch" : $(SOURCE) $(DEP_CPP_PREAG)\
 "$(INTDIR)"
	$(CPP) /nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS"\
 /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\Aggreg.pch" /Yc"preagg.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ELSEIF  "$(CFG)" == "Aggreg - Win32 Unicode Debug"

DEP_CPP_PREAG=\
	".\preagg.h"\
	

"$(INTDIR)\preagg.obj"	"$(INTDIR)\Aggreg.pch" : $(SOURCE) $(DEP_CPP_PREAG)\
 "$(INTDIR)"
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\Aggreg.pch" /Yc"preagg.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ENDIF 

SOURCE=.\Agg.h
SOURCE=.\AggBlind.h
SOURCE=.\Aggreg.h
SOURCE=.\AutoAgg.h
SOURCE=.\AutoAggB.h
SOURCE=.\preagg.h
SOURCE=.\Aggreg.tlb
SOURCE=.\Aggreg_i.c

!ENDIF 

