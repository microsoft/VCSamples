# Microsoft Developer Studio Generated NMAKE File, Based on DrawCtl.dsp
!IF "$(CFG)" == ""
CFG=DrawCtl - Win32 Release
!MESSAGE No configuration specified. Defaulting to DrawCtl - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "DrawCtl - Win32 Release" && "$(CFG)" !=\
 "DrawCtl - Win32 Debug" && "$(CFG)" != "DrawCtl - Win32 Unicode Release" &&\
 "$(CFG)" != "DrawCtl - Win32 Unicode Debug" && "$(CFG)" !=\
 "DrawCtl - Win32 MinCRT" && "$(CFG)" != "DrawCtl - Win32 Unicode MinCRT"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "DrawCtl.mak" CFG="DrawCtl - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DrawCtl - Win32 Release" (based on\
 "Win32 (x86) Win32 Dynamic-Link Library")
!MESSAGE "DrawCtl - Win32 Debug" (based on\
 "Win32 (x86) Win32 Dynamic-Link Library")
!MESSAGE "DrawCtl - Win32 Unicode Release" (based on\
 "Win32 (x86) Win32 Dynamic-Link Library")
!MESSAGE "DrawCtl - Win32 Unicode Debug" (based on\
 "Win32 (x86) Win32 Dynamic-Link Library")
!MESSAGE "DrawCtl - Win32 MinCRT" (based on\
 "Win32 (x86) Win32 Dynamic-Link Library")
!MESSAGE "DrawCtl - Win32 Unicode MinCRT" (based on\
 "Win32 (x86) Win32 Dynamic-Link Library")
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

!IF  "$(CFG)" == "DrawCtl - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "DrawCtl_i.c" "DrawCtl.tlb" "DrawCtl.h" "$(OUTDIR)\DrawCtl.dll"\
 "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "DrawCtl_i.c" "DrawCtl.tlb" "DrawCtl.h" "$(OUTDIR)\DrawCtl.dll"\
 "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Draw.obj"
	-@erase "$(INTDIR)\DrawCtl.obj"
	-@erase "$(INTDIR)\DrawCtl.pch"
	-@erase "$(INTDIR)\DrawCtl.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\DrawCtl.dll"
	-@erase "$(OUTDIR)\DrawCtl.exp"
	-@erase "$(OUTDIR)\DrawCtl.lib"
	-@erase "$(OutDir)\regsvr32.trg"
	-@erase "DrawCtl.h"
	-@erase "DrawCtl.tlb"
	-@erase "DrawCtl_i.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_MBCS" /D "_USRDLL" /D "_WIN32_DCOM" /D "_WINDLL" /D "_AFXDLL"\
 /Fp"$(INTDIR)\DrawCtl.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\DrawCtl.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\DrawCtl.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)\DrawCtl.pdb" /machine:I386 /def:".\DrawCtl.def"\
 /out:"$(OUTDIR)\DrawCtl.dll" /implib:"$(OUTDIR)\DrawCtl.lib" 
DEF_FILE= \
	".\DrawCtl.def"
LINK32_OBJS= \
	"$(INTDIR)\Draw.obj" \
	"$(INTDIR)\DrawCtl.obj" \
	"$(INTDIR)\DrawCtl.res" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\DrawCtl.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\DrawCtl.dll
InputPath=.\Release\DrawCtl.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "DrawCtl_i.c" "DrawCtl.tlb" "DrawCtl.h" "$(OUTDIR)\DrawCtl.dll"\
 "$(OUTDIR)\DrawCtl.bsc" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "DrawCtl_i.c" "DrawCtl.tlb" "DrawCtl.h" "$(OUTDIR)\DrawCtl.dll"\
 "$(OUTDIR)\DrawCtl.bsc" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Draw.obj"
	-@erase "$(INTDIR)\Draw.sbr"
	-@erase "$(INTDIR)\DrawCtl.obj"
	-@erase "$(INTDIR)\DrawCtl.pch"
	-@erase "$(INTDIR)\DrawCtl.res"
	-@erase "$(INTDIR)\DrawCtl.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\DrawCtl.bsc"
	-@erase "$(OUTDIR)\DrawCtl.dll"
	-@erase "$(OUTDIR)\DrawCtl.exp"
	-@erase "$(OUTDIR)\DrawCtl.ilk"
	-@erase "$(OUTDIR)\DrawCtl.lib"
	-@erase "$(OUTDIR)\DrawCtl.pdb"
	-@erase "$(OutDir)\regsvr32.trg"
	-@erase "DrawCtl.h"
	-@erase "DrawCtl.tlb"
	-@erase "DrawCtl_i.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_MBCS" /D "_USRDLL" /D "_WIN32_DCOM" /D "_WINDLL" /D "_AFXDLL"\
 /FR"$(INTDIR)\\" /Fp"$(INTDIR)\DrawCtl.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\Debug/
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\DrawCtl.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\DrawCtl.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Draw.sbr" \
	"$(INTDIR)\DrawCtl.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\DrawCtl.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)\DrawCtl.pdb" /debug /machine:I386 /def:".\DrawCtl.def"\
 /out:"$(OUTDIR)\DrawCtl.dll" /implib:"$(OUTDIR)\DrawCtl.lib" 
DEF_FILE= \
	".\DrawCtl.def"
LINK32_OBJS= \
	"$(INTDIR)\Draw.obj" \
	"$(INTDIR)\DrawCtl.obj" \
	"$(INTDIR)\DrawCtl.res" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\DrawCtl.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\DrawCtl.dll
InputPath=.\Debug\DrawCtl.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode Release"

OUTDIR=.\ReleaseU
INTDIR=.\ReleaseU
# Begin Custom Macros
OutDir=.\.\ReleaseU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "DrawCtl_i.c" "DrawCtl.tlb" "DrawCtl.h" "$(OUTDIR)\DrawCtl.dll"\
 "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "DrawCtl_i.c" "DrawCtl.tlb" "DrawCtl.h" "$(OUTDIR)\DrawCtl.dll"\
 "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Draw.obj"
	-@erase "$(INTDIR)\DrawCtl.obj"
	-@erase "$(INTDIR)\DrawCtl.pch"
	-@erase "$(INTDIR)\DrawCtl.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\DrawCtl.dll"
	-@erase "$(OUTDIR)\DrawCtl.exp"
	-@erase "$(OUTDIR)\DrawCtl.lib"
	-@erase "$(OutDir)\regsvr32.trg"
	-@erase "DrawCtl.h"
	-@erase "DrawCtl.tlb"
	-@erase "DrawCtl_i.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "_UNICODE" /D "WIN32" /D\
 "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_WIN32_DCOM" /D "_WINDLL" /D "_AFXDLL"\
 /Fp"$(INTDIR)\DrawCtl.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 
CPP_OBJS=.\ReleaseU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\DrawCtl.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\DrawCtl.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)\DrawCtl.pdb" /machine:I386 /def:".\DrawCtl.def"\
 /out:"$(OUTDIR)\DrawCtl.dll" /implib:"$(OUTDIR)\DrawCtl.lib" 
DEF_FILE= \
	".\DrawCtl.def"
LINK32_OBJS= \
	"$(INTDIR)\Draw.obj" \
	"$(INTDIR)\DrawCtl.obj" \
	"$(INTDIR)\DrawCtl.res" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\DrawCtl.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\ReleaseU
TargetPath=.\ReleaseU\DrawCtl.dll
InputPath=.\ReleaseU\DrawCtl.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\.\DebugU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "DrawCtl_i.c" "DrawCtl.tlb" "DrawCtl.h" "$(OUTDIR)\DrawCtl.dll"\
 "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "DrawCtl_i.c" "DrawCtl.tlb" "DrawCtl.h" "$(OUTDIR)\DrawCtl.dll"\
 "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Draw.obj"
	-@erase "$(INTDIR)\DrawCtl.obj"
	-@erase "$(INTDIR)\DrawCtl.pch"
	-@erase "$(INTDIR)\DrawCtl.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\DrawCtl.dll"
	-@erase "$(OUTDIR)\DrawCtl.exp"
	-@erase "$(OUTDIR)\DrawCtl.ilk"
	-@erase "$(OUTDIR)\DrawCtl.lib"
	-@erase "$(OUTDIR)\DrawCtl.pdb"
	-@erase "$(OutDir)\regsvr32.trg"
	-@erase "DrawCtl.h"
	-@erase "DrawCtl.tlb"
	-@erase "DrawCtl_i.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "_UNICODE" /D "WIN32"\
 /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_WIN32_DCOM" /D "_WINDLL" /D\
 "_AFXDLL" /Fp"$(INTDIR)\DrawCtl.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\DebugU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\DrawCtl.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\DrawCtl.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)\DrawCtl.pdb" /debug /machine:I386 /def:".\DrawCtl.def"\
 /out:"$(OUTDIR)\DrawCtl.dll" /implib:"$(OUTDIR)\DrawCtl.lib" 
DEF_FILE= \
	".\DrawCtl.def"
LINK32_OBJS= \
	"$(INTDIR)\Draw.obj" \
	"$(INTDIR)\DrawCtl.obj" \
	"$(INTDIR)\DrawCtl.res" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\DrawCtl.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\DebugU
TargetPath=.\DebugU\DrawCtl.dll
InputPath=.\DebugU\DrawCtl.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "DrawCtl - Win32 MinCRT"

OUTDIR=.\MinCRT
INTDIR=.\MinCRT
# Begin Custom Macros
OutDir=.\MinCRT
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "DrawCtl_i.c" "DrawCtl.tlb" "DrawCtl.h" "$(OUTDIR)\DrawCtl.dll"\
 "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "DrawCtl_i.c" "DrawCtl.tlb" "DrawCtl.h" "$(OUTDIR)\DrawCtl.dll"\
 "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Draw.obj"
	-@erase "$(INTDIR)\DrawCtl.obj"
	-@erase "$(INTDIR)\DrawCtl.pch"
	-@erase "$(INTDIR)\DrawCtl.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\DrawCtl.dll"
	-@erase "$(OUTDIR)\DrawCtl.exp"
	-@erase "$(OUTDIR)\DrawCtl.lib"
	-@erase "$(OutDir)\regsvr32.trg"
	-@erase "DrawCtl.h"
	-@erase "DrawCtl.tlb"
	-@erase "DrawCtl_i.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /O1 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL"\
 /D "_MBCS" /D "_USRDLL" /D "_WIN32_DCOM"\
 /Fp"$(INTDIR)\DrawCtl.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 
CPP_OBJS=.\MinCRT/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\DrawCtl.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\DrawCtl.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)\DrawCtl.pdb" /machine:I386 /def:".\DrawCtl.def"\
 /out:"$(OUTDIR)\DrawCtl.dll" /implib:"$(OUTDIR)\DrawCtl.lib" 
DEF_FILE= \
	".\DrawCtl.def"
LINK32_OBJS= \
	"$(INTDIR)\Draw.obj" \
	"$(INTDIR)\DrawCtl.obj" \
	"$(INTDIR)\DrawCtl.res" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\DrawCtl.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\MinCRT
TargetPath=.\MinCRT\DrawCtl.dll
InputPath=.\MinCRT\DrawCtl.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode MinCRT"

OUTDIR=.\MinCRTU
INTDIR=.\MinCRTU
# Begin Custom Macros
OutDir=.\MinCRTU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "DrawCtl_i.c" "DrawCtl.tlb" "DrawCtl.h" "$(OUTDIR)\DrawCtl.dll"\
 "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "DrawCtl_i.c" "DrawCtl.tlb" "DrawCtl.h" "$(OUTDIR)\DrawCtl.dll"\
 "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Draw.obj"
	-@erase "$(INTDIR)\DrawCtl.obj"
	-@erase "$(INTDIR)\DrawCtl.pch"
	-@erase "$(INTDIR)\DrawCtl.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\DrawCtl.dll"
	-@erase "$(OUTDIR)\DrawCtl.exp"
	-@erase "$(OUTDIR)\DrawCtl.lib"
	-@erase "$(OutDir)\regsvr32.trg"
	-@erase "DrawCtl.h"
	-@erase "DrawCtl.tlb"
	-@erase "DrawCtl_i.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /O1 /D "NDEBUG" /D "_UNICODE" /D "WIN32" /D "_WINDOWS"\
 /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_WIN32_DCOM" \
 /Fp"$(INTDIR)\DrawCtl.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 
CPP_OBJS=.\MinCRTU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\DrawCtl.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\DrawCtl.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)\DrawCtl.pdb" /machine:I386 /def:".\DrawCtl.def"\
 /out:"$(OUTDIR)\DrawCtl.dll" /implib:"$(OUTDIR)\DrawCtl.lib" 
DEF_FILE= \
	".\DrawCtl.def"
LINK32_OBJS= \
	"$(INTDIR)\Draw.obj" \
	"$(INTDIR)\DrawCtl.obj" \
	"$(INTDIR)\DrawCtl.res" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\DrawCtl.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\MinCRTU
TargetPath=.\MinCRTU\DrawCtl.dll
InputPath=.\MinCRTU\DrawCtl.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ENDIF 

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(CFG)" == "DrawCtl - Win32 Release" || "$(CFG)" ==\
 "DrawCtl - Win32 Debug" || "$(CFG)" == "DrawCtl - Win32 Unicode Release" ||\
 "$(CFG)" == "DrawCtl - Win32 Unicode Debug" || "$(CFG)" ==\
 "DrawCtl - Win32 MinCRT" || "$(CFG)" == "DrawCtl - Win32 Unicode MinCRT"
SOURCE=.\Draw.cpp

!IF  "$(CFG)" == "DrawCtl - Win32 Release"

DEP_CPP_DRAW_=\
	".\Draw.h"\
	

"$(INTDIR)\Draw.obj" : $(SOURCE) $(DEP_CPP_DRAW_) "$(INTDIR)"\
 "$(INTDIR)\DrawCtl.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Debug"

DEP_CPP_DRAW_=\
	".\Draw.h"\
	

"$(INTDIR)\Draw.obj"	"$(INTDIR)\Draw.sbr" : $(SOURCE) $(DEP_CPP_DRAW_)\
 "$(INTDIR)" "$(INTDIR)\DrawCtl.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode Release"

DEP_CPP_DRAW_=\
	".\Draw.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Draw.obj" : $(SOURCE) $(DEP_CPP_DRAW_) "$(INTDIR)"\
 "$(INTDIR)\DrawCtl.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode Debug"

DEP_CPP_DRAW_=\
	".\Draw.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Draw.obj" : $(SOURCE) $(DEP_CPP_DRAW_) "$(INTDIR)"\
 "$(INTDIR)\DrawCtl.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 MinCRT"

DEP_CPP_DRAW_=\
	".\Draw.h"\
	

"$(INTDIR)\Draw.obj" : $(SOURCE) $(DEP_CPP_DRAW_) "$(INTDIR)"\
 "$(INTDIR)\DrawCtl.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode MinCRT"

DEP_CPP_DRAW_=\
	".\Draw.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Draw.obj" : $(SOURCE) $(DEP_CPP_DRAW_) "$(INTDIR)"\
 "$(INTDIR)\DrawCtl.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\DrawCtl.cpp

!IF  "$(CFG)" == "DrawCtl - Win32 Release"

DEP_CPP_DRAWC=\
	".\Draw.h"\
	

"$(INTDIR)\DrawCtl.obj" : $(SOURCE) $(DEP_CPP_DRAWC) "$(INTDIR)"\
 "$(INTDIR)\DrawCtl.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Debug"

DEP_CPP_DRAWC=\
	".\Draw.h"\
	

"$(INTDIR)\DrawCtl.obj"	"$(INTDIR)\DrawCtl.sbr" : $(SOURCE) $(DEP_CPP_DRAWC)\
 "$(INTDIR)" "$(INTDIR)\DrawCtl.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode Release"

DEP_CPP_DRAWC=\
	".\Draw.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\DrawCtl.obj" : $(SOURCE) $(DEP_CPP_DRAWC) "$(INTDIR)"\
 "$(INTDIR)\DrawCtl.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode Debug"

DEP_CPP_DRAWC=\
	".\Draw.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\DrawCtl.obj" : $(SOURCE) $(DEP_CPP_DRAWC) "$(INTDIR)"\
 "$(INTDIR)\DrawCtl.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 MinCRT"

DEP_CPP_DRAWC=\
	".\Draw.h"\
	

"$(INTDIR)\DrawCtl.obj" : $(SOURCE) $(DEP_CPP_DRAWC) "$(INTDIR)"\
 "$(INTDIR)\DrawCtl.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode MinCRT"

DEP_CPP_DRAWC=\
	".\Draw.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\DrawCtl.obj" : $(SOURCE) $(DEP_CPP_DRAWC) "$(INTDIR)"\
 "$(INTDIR)\DrawCtl.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\DrawCtl.def
SOURCE=.\DrawCtl.idl

!IF  "$(CFG)" == "DrawCtl - Win32 Release"

InputPath=.\DrawCtl.idl

"DrawCtl.tlb"	"DrawCtl.h"	"DrawCtl_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /h DrawCtl.h /iid DrawCtl_i.c DrawCtl.idl

!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Debug"

InputPath=.\DrawCtl.idl

"DrawCtl.tlb"	"DrawCtl.h"	"DrawCtl_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /h DrawCtl.h /iid DrawCtl_i.c DrawCtl.idl

!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode Release"

InputPath=.\DrawCtl.idl

"DrawCtl.tlb"	"DrawCtl.h"	"DrawCtl_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /h DrawCtl.h /iid DrawCtl_i.c DrawCtl.idl

!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode Debug"

InputPath=.\DrawCtl.idl

"DrawCtl.tlb"	"DrawCtl.h"	"DrawCtl_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /h DrawCtl.h /iid DrawCtl_i.c DrawCtl.idl

!ELSEIF  "$(CFG)" == "DrawCtl - Win32 MinCRT"

InputPath=.\DrawCtl.idl

"DrawCtl.tlb"	"DrawCtl.h"	"DrawCtl_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /h DrawCtl.h /iid DrawCtl_i.c DrawCtl.idl

!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode MinCRT"

InputPath=.\DrawCtl.idl

"DrawCtl.tlb"	"DrawCtl.h"	"DrawCtl_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /h DrawCtl.h /iid DrawCtl_i.c DrawCtl.idl

!ENDIF 

SOURCE=.\DrawCtl.rc
DEP_RSC_DRAWCT=\
	".\DrawCtl.rgs"\
	".\DrawCtl.tlb"\
	".\toolbtn.bmp"\
	

!IF  "$(CFG)" == "DrawCtl - Win32 Release"


"$(INTDIR)\DrawCtl.res" : $(SOURCE) $(DEP_RSC_DRAWCT) "$(INTDIR)"\
 ".\DrawCtl.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Debug"


"$(INTDIR)\DrawCtl.res" : $(SOURCE) $(DEP_RSC_DRAWCT) "$(INTDIR)"\
 ".\DrawCtl.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode Release"


"$(INTDIR)\DrawCtl.res" : $(SOURCE) $(DEP_RSC_DRAWCT) "$(INTDIR)"\
 ".\DrawCtl.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode Debug"


"$(INTDIR)\DrawCtl.res" : $(SOURCE) $(DEP_RSC_DRAWCT) "$(INTDIR)"\
 ".\DrawCtl.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 MinCRT"


"$(INTDIR)\DrawCtl.res" : $(SOURCE) $(DEP_RSC_DRAWCT) "$(INTDIR)"\
 ".\DrawCtl.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode MinCRT"


"$(INTDIR)\DrawCtl.res" : $(SOURCE) $(DEP_RSC_DRAWCT) "$(INTDIR)"\
 ".\DrawCtl.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "DrawCtl - Win32 Release"

DEP_CPP_STDAF=\
	".\DrawCtl.tlb"\
	".\StdAfx.h"\
	"d:\msdev\mcl\atl\include\atliface.h"\
	
CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_MBCS" /D "_USRDLL" /D "_WIN32_DCOM" /D "_WINDLL" /D "_AFXDLL"\
 /Fp"$(INTDIR)\DrawCtl.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\DrawCtl.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)" ".\DrawCtl.tlb"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Debug"

DEP_CPP_STDAF=\
	".\DrawCtl.tlb"\
	".\StdAfx.h"\
	"d:\msdev\mcl\atl\include\atliface.h"\
	
CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_WIN32_DCOM" /D "_WINDLL" /D "_AFXDLL"\
 /FR"$(INTDIR)\\" /Fp"$(INTDIR)\DrawCtl.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\DrawCtl.pch" : \
$(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)" ".\DrawCtl.tlb"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "_UNICODE" /D "WIN32" /D\
 "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_WIN32_DCOM" /D "_WINDLL" /D "_AFXDLL"\
 /Fp"$(INTDIR)\DrawCtl.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\DrawCtl.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "_UNICODE" /D\
 "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_WIN32_DCOM" /D "_WINDLL" /D\
 "_AFXDLL" /Fp"$(INTDIR)\DrawCtl.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\DrawCtl.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 MinCRT"

DEP_CPP_STDAF=\
	".\DrawCtl.tlb"\
	".\StdAfx.h"\
	"d:\msdev\mcl\atl\include\atliface.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O1 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_WIN32_DCOM"\
 /Fp"$(INTDIR)\DrawCtl.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\DrawCtl.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)" ".\DrawCtl.tlb"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode MinCRT"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O1 /D "NDEBUG" /D "_UNICODE" /D "WIN32" /D\
 "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_WIN32_DCOM" \
 /Fp"$(INTDIR)\DrawCtl.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\DrawCtl.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Draw.h
SOURCE=.\StdAfx.h
SOURCE=.\toolbtn.bmp
SOURCE=.\DrawCtl.rgs

!ENDIF 

