# Microsoft Developer Studio Generated NMAKE File, Based on COMMap.dsp
!IF "$(CFG)" == ""
CFG=COMMap - Win32 Release
!MESSAGE No configuration specified.  Defaulting to COMMap - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "COMMap - Win32 Release" && "$(CFG)" != "COMMap - Win32 Debug"\
 && "$(CFG)" != "COMMap - Win32 Unicode Release" && "$(CFG)" !=\
 "COMMap - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "COMMap.mak" CFG="COMMap - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "COMMap - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "COMMap - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "COMMap - Win32 Unicode Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "COMMap - Win32 Unicode Debug" (based on\
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

!IF  "$(CFG)" == "COMMap - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "COMMap_i.c" "COMMap.tlb" "COMMap.h" "$(OUTDIR)\COMMap.dll"\
 "$(OutDir)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\Chain.obj"
	-@erase "$(INTDIR)\COMMap.obj"
	-@erase "$(INTDIR)\COMMap.pch"
	-@erase "$(INTDIR)\COMMap.res"
	-@erase "$(INTDIR)\Outer.obj"
	-@erase "$(INTDIR)\premap.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\COMMap.dll"
	-@erase "$(OUTDIR)\COMMap.exp"
	-@erase "$(OUTDIR)\COMMap.lib"
	-@erase "$(OutDir)\regsvr32.trg"
	-@erase "COMMap.h"
	-@erase "COMMap.tlb"
	-@erase "COMMap_i.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\COMMap.pch" /Yu"premap.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\COMMap.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\COMMap.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)\COMMap.pdb" /machine:I386 /def:".\COMMap.def"\
 /out:"$(OUTDIR)\COMMap.dll" /implib:"$(OUTDIR)\COMMap.lib" 
DEF_FILE= \
	".\COMMap.def"
LINK32_OBJS= \
	"$(INTDIR)\Chain.obj" \
	"$(INTDIR)\COMMap.obj" \
	"$(INTDIR)\COMMap.res" \
	"$(INTDIR)\Outer.obj" \
	"$(INTDIR)\premap.obj"

"$(OUTDIR)\COMMap.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\COMMap.dll
InputPath=.\Release\COMMap.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "COMMap - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "COMMap_i.c" "COMMap.tlb" "COMMap.h" "$(OUTDIR)\COMMap.dll"\
 "$(OUTDIR)\COMMap.bsc" "$(OutDir)\regsvr32.trg"

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
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\COMMap.bsc"
	-@erase "$(OUTDIR)\COMMap.dll"
	-@erase "$(OUTDIR)\COMMap.exp"
	-@erase "$(OUTDIR)\COMMap.ilk"
	-@erase "$(OUTDIR)\COMMap.lib"
	-@erase "$(OUTDIR)\COMMap.pdb"
	-@erase "$(OutDir)\regsvr32.trg"
	-@erase "COMMap.h"
	-@erase "COMMap.tlb"
	-@erase "COMMap_i.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\COMMap.pch"\
 /Yu"premap.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\Debug/
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\COMMap.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\COMMap.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Chain.sbr" \
	"$(INTDIR)\COMMap.sbr" \
	"$(INTDIR)\Outer.sbr" \
	"$(INTDIR)\premap.sbr"

"$(OUTDIR)\COMMap.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)\COMMap.pdb" /debug /machine:I386 /def:".\COMMap.def"\
 /out:"$(OUTDIR)\COMMap.dll" /implib:"$(OUTDIR)\COMMap.lib" 
DEF_FILE= \
	".\COMMap.def"
LINK32_OBJS= \
	"$(INTDIR)\Chain.obj" \
	"$(INTDIR)\COMMap.obj" \
	"$(INTDIR)\COMMap.res" \
	"$(INTDIR)\Outer.obj" \
	"$(INTDIR)\premap.obj"

"$(OUTDIR)\COMMap.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\COMMap.dll
InputPath=.\Debug\COMMap.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "COMMap - Win32 Unicode Release"

OUTDIR=.\ReleaseU
INTDIR=.\ReleaseU
# Begin Custom Macros
OutDir=.\.\ReleaseU
# End Custom Macros

ALL : "COMMap_i.c" "COMMap.tlb" "COMMap.h" "$(OUTDIR)\COMMap.dll"\
 "$(OutDir)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\Chain.obj"
	-@erase "$(INTDIR)\COMMap.obj"
	-@erase "$(INTDIR)\COMMap.pch"
	-@erase "$(INTDIR)\COMMap.res"
	-@erase "$(INTDIR)\Outer.obj"
	-@erase "$(INTDIR)\premap.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\COMMap.dll"
	-@erase "$(OUTDIR)\COMMap.exp"
	-@erase "$(OUTDIR)\COMMap.lib"
	-@erase "$(OutDir)\regsvr32.trg"
	-@erase "COMMap.h"
	-@erase "COMMap.tlb"
	-@erase "COMMap_i.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\COMMap.pch" /Yu"premap.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\COMMap.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\COMMap.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)\COMMap.pdb" /machine:I386 /def:".\COMMap.def"\
 /out:"$(OUTDIR)\COMMap.dll" /implib:"$(OUTDIR)\COMMap.lib" 
DEF_FILE= \
	".\COMMap.def"
LINK32_OBJS= \
	"$(INTDIR)\Chain.obj" \
	"$(INTDIR)\COMMap.obj" \
	"$(INTDIR)\COMMap.res" \
	"$(INTDIR)\Outer.obj" \
	"$(INTDIR)\premap.obj"

"$(OUTDIR)\COMMap.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\ReleaseU
TargetPath=.\ReleaseU\COMMap.dll
InputPath=.\ReleaseU\COMMap.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "COMMap - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\.\DebugU
# End Custom Macros

ALL : "COMMap_i.c" "COMMap.tlb" "COMMap.h" "$(OUTDIR)\COMMap.dll"\
 "$(OutDir)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\Chain.obj"
	-@erase "$(INTDIR)\COMMap.obj"
	-@erase "$(INTDIR)\COMMap.pch"
	-@erase "$(INTDIR)\COMMap.res"
	-@erase "$(INTDIR)\Outer.obj"
	-@erase "$(INTDIR)\premap.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\COMMap.dll"
	-@erase "$(OUTDIR)\COMMap.exp"
	-@erase "$(OUTDIR)\COMMap.ilk"
	-@erase "$(OUTDIR)\COMMap.lib"
	-@erase "$(OUTDIR)\COMMap.pdb"
	-@erase "$(OutDir)\regsvr32.trg"
	-@erase "COMMap.h"
	-@erase "COMMap.tlb"
	-@erase "COMMap_i.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\COMMap.pch" /Yu"premap.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\DebugU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\COMMap.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\COMMap.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)\COMMap.pdb" /debug /machine:I386 /def:".\COMMap.def"\
 /out:"$(OUTDIR)\COMMap.dll" /implib:"$(OUTDIR)\COMMap.lib" 
DEF_FILE= \
	".\COMMap.def"
LINK32_OBJS= \
	"$(INTDIR)\Chain.obj" \
	"$(INTDIR)\COMMap.obj" \
	"$(INTDIR)\COMMap.res" \
	"$(INTDIR)\Outer.obj" \
	"$(INTDIR)\premap.obj"

"$(OUTDIR)\COMMap.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\DebugU
TargetPath=.\DebugU\COMMap.dll
InputPath=.\DebugU\COMMap.dll
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


!IF "$(CFG)" == "COMMap - Win32 Release" || "$(CFG)" == "COMMap - Win32 Debug"\
 || "$(CFG)" == "COMMap - Win32 Unicode Release" || "$(CFG)" ==\
 "COMMap - Win32 Unicode Debug"
SOURCE=.\Chain.cpp

!IF  "$(CFG)" == "COMMap - Win32 Release"

DEP_CPP_CHAIN=\
	".\Chain.h"\
	

"$(INTDIR)\Chain.obj" : $(SOURCE) $(DEP_CPP_CHAIN) "$(INTDIR)"\
 "$(INTDIR)\COMMap.pch"


!ELSEIF  "$(CFG)" == "COMMap - Win32 Debug"

DEP_CPP_CHAIN=\
	".\Chain.h"\
	".\premap.h"\
	

"$(INTDIR)\Chain.obj"	"$(INTDIR)\Chain.sbr" : $(SOURCE) $(DEP_CPP_CHAIN)\
 "$(INTDIR)" "$(INTDIR)\COMMap.pch"


!ELSEIF  "$(CFG)" == "COMMap - Win32 Unicode Release"

DEP_CPP_CHAIN=\
	".\Chain.h"\
	".\premap.h"\
	

"$(INTDIR)\Chain.obj" : $(SOURCE) $(DEP_CPP_CHAIN) "$(INTDIR)"\
 "$(INTDIR)\COMMap.pch"


!ELSEIF  "$(CFG)" == "COMMap - Win32 Unicode Debug"

DEP_CPP_CHAIN=\
	".\Chain.h"\
	".\premap.h"\
	

"$(INTDIR)\Chain.obj" : $(SOURCE) $(DEP_CPP_CHAIN) "$(INTDIR)"\
 "$(INTDIR)\COMMap.pch"


!ENDIF 

SOURCE=.\Chain.rgs
SOURCE=.\COMMap.cpp

!IF  "$(CFG)" == "COMMap - Win32 Release"

DEP_CPP_COMMA=\
	".\Chain.h"\
	".\Outer.h"\
	

"$(INTDIR)\COMMap.obj" : $(SOURCE) $(DEP_CPP_COMMA) "$(INTDIR)"\
 "$(INTDIR)\COMMap.pch"


!ELSEIF  "$(CFG)" == "COMMap - Win32 Debug"

DEP_CPP_COMMA=\
	".\Chain.h"\
	".\Outer.h"\
	".\premap.h"\
	

"$(INTDIR)\COMMap.obj"	"$(INTDIR)\COMMap.sbr" : $(SOURCE) $(DEP_CPP_COMMA)\
 "$(INTDIR)" "$(INTDIR)\COMMap.pch"


!ELSEIF  "$(CFG)" == "COMMap - Win32 Unicode Release"

DEP_CPP_COMMA=\
	".\Chain.h"\
	".\Outer.h"\
	".\premap.h"\
	

"$(INTDIR)\COMMap.obj" : $(SOURCE) $(DEP_CPP_COMMA) "$(INTDIR)"\
 "$(INTDIR)\COMMap.pch"


!ELSEIF  "$(CFG)" == "COMMap - Win32 Unicode Debug"

DEP_CPP_COMMA=\
	".\Chain.h"\
	".\Outer.h"\
	".\premap.h"\
	

"$(INTDIR)\COMMap.obj" : $(SOURCE) $(DEP_CPP_COMMA) "$(INTDIR)"\
 "$(INTDIR)\COMMap.pch"


!ENDIF 

SOURCE=.\COMMap.def
SOURCE=.\COMMap.idl

!IF  "$(CFG)" == "COMMap - Win32 Release"

InputPath=.\COMMap.idl

".\COMMap.tlb"	".\COMMap.h"	".\COMMap_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl COMMap.idl

!ELSEIF  "$(CFG)" == "COMMap - Win32 Debug"

InputPath=.\COMMap.idl

".\COMMap.tlb"	".\COMMap.h"	".\COMMap_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl COMMap.idl

!ELSEIF  "$(CFG)" == "COMMap - Win32 Unicode Release"

InputPath=.\COMMap.idl

".\COMMap.tlb"	".\COMMap.h"	".\COMMap_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl COMMap.idl

!ELSEIF  "$(CFG)" == "COMMap - Win32 Unicode Debug"

InputPath=.\COMMap.idl

".\COMMap.tlb"	".\COMMap.h"	".\COMMap_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl COMMap.idl

!ENDIF 

SOURCE=.\COMMap.rc
DEP_RSC_COMMAP=\
	".\Chain.rgs"\
	".\COMMap.tlb"\
	".\Outer.rgs"\
	

!IF  "$(CFG)" == "COMMap - Win32 Release"


"$(INTDIR)\COMMap.res" : $(SOURCE) $(DEP_RSC_COMMAP) "$(INTDIR)" ".\COMMap.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "COMMap - Win32 Debug"


"$(INTDIR)\COMMap.res" : $(SOURCE) $(DEP_RSC_COMMAP) "$(INTDIR)" ".\COMMap.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "COMMap - Win32 Unicode Release"


"$(INTDIR)\COMMap.res" : $(SOURCE) $(DEP_RSC_COMMAP) "$(INTDIR)" ".\COMMap.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "COMMap - Win32 Unicode Debug"


"$(INTDIR)\COMMap.res" : $(SOURCE) $(DEP_RSC_COMMAP) "$(INTDIR)" ".\COMMap.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Outer.cpp

!IF  "$(CFG)" == "COMMap - Win32 Release"

DEP_CPP_OUTER=\
	".\Chain.h"\
	".\Outer.h"\
	

"$(INTDIR)\Outer.obj" : $(SOURCE) $(DEP_CPP_OUTER) "$(INTDIR)"\
 "$(INTDIR)\COMMap.pch"


!ELSEIF  "$(CFG)" == "COMMap - Win32 Debug"

DEP_CPP_OUTER=\
	".\Chain.h"\
	".\Outer.h"\
	".\premap.h"\
	

"$(INTDIR)\Outer.obj"	"$(INTDIR)\Outer.sbr" : $(SOURCE) $(DEP_CPP_OUTER)\
 "$(INTDIR)" "$(INTDIR)\COMMap.pch"


!ELSEIF  "$(CFG)" == "COMMap - Win32 Unicode Release"

DEP_CPP_OUTER=\
	".\Chain.h"\
	".\Outer.h"\
	".\premap.h"\
	

"$(INTDIR)\Outer.obj" : $(SOURCE) $(DEP_CPP_OUTER) "$(INTDIR)"\
 "$(INTDIR)\COMMap.pch"


!ELSEIF  "$(CFG)" == "COMMap - Win32 Unicode Debug"

DEP_CPP_OUTER=\
	".\Chain.h"\
	".\Outer.h"\
	".\premap.h"\
	

"$(INTDIR)\Outer.obj" : $(SOURCE) $(DEP_CPP_OUTER) "$(INTDIR)"\
 "$(INTDIR)\COMMap.pch"


!ENDIF 

SOURCE=.\Outer.rgs
SOURCE=.\premap.cpp

!IF  "$(CFG)" == "COMMap - Win32 Release"

DEP_CPP_PREMA=\
	".\aggreg\aggreg.tlb"\
	".\COMMap.tlb"\
	".\premap.h"\
	

"$(INTDIR)\premap.obj"	"$(INTDIR)\COMMap.pch" : $(SOURCE) $(DEP_CPP_PREMA)\
 "$(INTDIR)" ".\COMMap.tlb"
	$(CPP) /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS"\
 /D "_USRDLL" /Fp"$(INTDIR)\COMMap.pch" /Yc"premap.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ELSEIF  "$(CFG)" == "COMMap - Win32 Debug"

DEP_CPP_PREMA=\
	".\premap.h"\
	

"$(INTDIR)\premap.obj"	"$(INTDIR)\premap.sbr"	"$(INTDIR)\COMMap.pch" : \
$(SOURCE) $(DEP_CPP_PREMA) "$(INTDIR)"
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\COMMap.pch"\
 /Yc"premap.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ELSEIF  "$(CFG)" == "COMMap - Win32 Unicode Release"

DEP_CPP_PREMA=\
	".\premap.h"\
	

"$(INTDIR)\premap.obj"	"$(INTDIR)\COMMap.pch" : $(SOURCE) $(DEP_CPP_PREMA)\
 "$(INTDIR)"
	$(CPP) /nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS"\
 /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\COMMap.pch" /Yc"premap.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ELSEIF  "$(CFG)" == "COMMap - Win32 Unicode Debug"

DEP_CPP_PREMA=\
	".\premap.h"\
	

"$(INTDIR)\premap.obj"	"$(INTDIR)\COMMap.pch" : $(SOURCE) $(DEP_CPP_PREMA)\
 "$(INTDIR)"
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\COMMap.pch" /Yc"premap.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ENDIF 

SOURCE=.\Chain.h
SOURCE=.\COMMap.h
SOURCE=.\Outer.h
SOURCE=.\premap.h

!ENDIF 

