# Microsoft Developer Studio Generated NMAKE File, Based on DrawCtl.dsp
!IF "$(CFG)" == ""
CFG=DrawCtl - Win32 Release
!MESSAGE No configuration specified. Defaulting to DrawCtl - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "DrawCtl - Win32 Release" && "$(CFG)" != "DrawCtl - Win32 Debug" && "$(CFG)" != "DrawCtl - Win32 Unicode Release" && "$(CFG)" != "DrawCtl - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "DrawCtl.mak" CFG="DrawCtl - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DrawCtl - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "DrawCtl - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "DrawCtl - Win32 Unicode Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "DrawCtl - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
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

ALL : "$(OUTDIR)\DrawCtl.dll" ".\.\Release\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\Draw.obj"
	-@erase "$(INTDIR)\DrawCtl.obj"
	-@erase "$(INTDIR)\DrawCtl.pch"
	-@erase "$(INTDIR)\DrawCtl.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(OUTDIR)\DrawCtl.dll"
	-@erase "$(OUTDIR)\DrawCtl.exp"
	-@erase "$(OUTDIR)\DrawCtl.lib"
	-@erase ".\DrawCtl.h"
	-@erase ".\DrawCtl.tlb"
	-@erase ".\DrawCtl_i.c"
	-@erase ".\.\Release\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_WIN32_DCOM" /Fp"$(INTDIR)\DrawCtl.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\DrawCtl.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\DrawCtl.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\DrawCtl.pdb" /machine:I386 /def:".\DrawCtl.def" /out:"$(OUTDIR)\DrawCtl.dll" /implib:"$(OUTDIR)\DrawCtl.lib" 
DEF_FILE= \
	".\DrawCtl.def"
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\DrawCtl.obj" \
	"$(INTDIR)\Draw.obj" \
	"$(INTDIR)\DrawCtl.res"

"$(OUTDIR)\DrawCtl.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\DrawCtl.dll
InputPath=.\Release\DrawCtl.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
<< 
	

!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\DrawCtl.dll" "$(OUTDIR)\DrawCtl.bsc" ".\.\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\Draw.obj"
	-@erase "$(INTDIR)\Draw.sbr"
	-@erase "$(INTDIR)\DrawCtl.obj"
	-@erase "$(INTDIR)\DrawCtl.pch"
	-@erase "$(INTDIR)\DrawCtl.res"
	-@erase "$(INTDIR)\DrawCtl.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\DrawCtl.bsc"
	-@erase "$(OUTDIR)\DrawCtl.dll"
	-@erase "$(OUTDIR)\DrawCtl.exp"
	-@erase "$(OUTDIR)\DrawCtl.ilk"
	-@erase "$(OUTDIR)\DrawCtl.lib"
	-@erase "$(OUTDIR)\DrawCtl.pdb"
	-@erase ".\DrawCtl.h"
	-@erase ".\DrawCtl.tlb"
	-@erase ".\DrawCtl_i.c"
	-@erase ".\.\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_WIN32_DCOM" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\DrawCtl.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\DrawCtl.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\DrawCtl.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\DrawCtl.sbr" \
	"$(INTDIR)\Draw.sbr"

"$(OUTDIR)\DrawCtl.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\DrawCtl.pdb" /debug /machine:I386 /def:".\DrawCtl.def" /out:"$(OUTDIR)\DrawCtl.dll" /implib:"$(OUTDIR)\DrawCtl.lib" 
DEF_FILE= \
	".\DrawCtl.def"
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\DrawCtl.obj" \
	"$(INTDIR)\Draw.obj" \
	"$(INTDIR)\DrawCtl.res"

"$(OUTDIR)\DrawCtl.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\DrawCtl.dll
InputPath=.\Debug\DrawCtl.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
<< 
	

!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode Release"

OUTDIR=.\ReleaseU
INTDIR=.\ReleaseU
# Begin Custom Macros
OutDir=.\.\ReleaseU
# End Custom Macros

ALL : "$(OUTDIR)\DrawCtl.dll" ".\.\ReleaseU\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\Draw.obj"
	-@erase "$(INTDIR)\DrawCtl.obj"
	-@erase "$(INTDIR)\DrawCtl.pch"
	-@erase "$(INTDIR)\DrawCtl.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(OUTDIR)\DrawCtl.dll"
	-@erase "$(OUTDIR)\DrawCtl.exp"
	-@erase "$(OUTDIR)\DrawCtl.lib"
	-@erase ".\DrawCtl.h"
	-@erase ".\DrawCtl.tlb"
	-@erase ".\DrawCtl_i.c"
	-@erase ".\.\ReleaseU\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "_UNICODE" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_WIN32_DCOM" /Fp"$(INTDIR)\DrawCtl.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\DrawCtl.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\DrawCtl.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\DrawCtl.pdb" /machine:I386 /def:".\DrawCtl.def" /out:"$(OUTDIR)\DrawCtl.dll" /implib:"$(OUTDIR)\DrawCtl.lib" 
DEF_FILE= \
	".\DrawCtl.def"
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\DrawCtl.obj" \
	"$(INTDIR)\Draw.obj" \
	"$(INTDIR)\DrawCtl.res"

"$(OUTDIR)\DrawCtl.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\ReleaseU
TargetPath=.\ReleaseU\DrawCtl.dll
InputPath=.\ReleaseU\DrawCtl.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
<< 
	

!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\.\DebugU
# End Custom Macros

ALL : "$(OUTDIR)\DrawCtl.dll" ".\.\DebugU\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\Draw.obj"
	-@erase "$(INTDIR)\DrawCtl.obj"
	-@erase "$(INTDIR)\DrawCtl.pch"
	-@erase "$(INTDIR)\DrawCtl.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\DrawCtl.dll"
	-@erase "$(OUTDIR)\DrawCtl.exp"
	-@erase "$(OUTDIR)\DrawCtl.ilk"
	-@erase "$(OUTDIR)\DrawCtl.lib"
	-@erase "$(OUTDIR)\DrawCtl.pdb"
	-@erase ".\DrawCtl.h"
	-@erase ".\DrawCtl.tlb"
	-@erase ".\DrawCtl_i.c"
	-@erase ".\.\DebugU\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "_UNICODE" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_WIN32_DCOM" /Fp"$(INTDIR)\DrawCtl.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\DrawCtl.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\DrawCtl.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\DrawCtl.pdb" /debug /machine:I386 /def:".\DrawCtl.def" /out:"$(OUTDIR)\DrawCtl.dll" /implib:"$(OUTDIR)\DrawCtl.lib" 
DEF_FILE= \
	".\DrawCtl.def"
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\DrawCtl.obj" \
	"$(INTDIR)\Draw.obj" \
	"$(INTDIR)\DrawCtl.res"

"$(OUTDIR)\DrawCtl.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\DebugU
TargetPath=.\DebugU\DrawCtl.dll
InputPath=.\DebugU\DrawCtl.dll
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
!IF EXISTS("DrawCtl.dep")
!INCLUDE "DrawCtl.dep"
!ELSE 
!MESSAGE Warning: cannot find "DrawCtl.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "DrawCtl - Win32 Release" || "$(CFG)" == "DrawCtl - Win32 Debug" || "$(CFG)" == "DrawCtl - Win32 Unicode Release" || "$(CFG)" == "DrawCtl - Win32 Unicode Debug"
SOURCE=.\Draw.cpp

!IF  "$(CFG)" == "DrawCtl - Win32 Release"


"$(INTDIR)\Draw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\DrawCtl.pch" ".\DrawCtl.h"


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Debug"


"$(INTDIR)\Draw.obj"	"$(INTDIR)\Draw.sbr" : $(SOURCE) "$(INTDIR)" ".\DrawCtl.h" "$(INTDIR)\DrawCtl.pch"


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode Release"


"$(INTDIR)\Draw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\DrawCtl.pch" ".\DrawCtl.h"


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode Debug"


"$(INTDIR)\Draw.obj" : $(SOURCE) "$(INTDIR)" ".\DrawCtl.h" "$(INTDIR)\DrawCtl.pch"


!ENDIF 

SOURCE=.\DrawCtl.cpp

!IF  "$(CFG)" == "DrawCtl - Win32 Release"


"$(INTDIR)\DrawCtl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\DrawCtl.pch" ".\DrawCtl.h" ".\DrawCtl_i.c"


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Debug"


"$(INTDIR)\DrawCtl.obj"	"$(INTDIR)\DrawCtl.sbr" : $(SOURCE) "$(INTDIR)" ".\DrawCtl.h" ".\DrawCtl_i.c" "$(INTDIR)\DrawCtl.pch"


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode Release"


"$(INTDIR)\DrawCtl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\DrawCtl.pch" ".\DrawCtl.h" ".\DrawCtl_i.c"


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode Debug"


"$(INTDIR)\DrawCtl.obj" : $(SOURCE) "$(INTDIR)" ".\DrawCtl.h" ".\DrawCtl_i.c" "$(INTDIR)\DrawCtl.pch"


!ENDIF 

SOURCE=.\DrawCtl.idl

!IF  "$(CFG)" == "DrawCtl - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb ".\DrawCtl.tlb" /h "DrawCtl.h" /iid "DrawCtl_i.c" /win32 

".\DrawCtl.tlb"	".\DrawCtl.h"	".\DrawCtl_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb ".\DrawCtl.tlb" /h "DrawCtl.h" /iid "DrawCtl_i.c" /win32 

".\DrawCtl.tlb"	".\DrawCtl.h"	".\DrawCtl_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb ".\DrawCtl.tlb" /h "DrawCtl.h" /iid "DrawCtl_i.c" /win32 

".\DrawCtl.tlb"	".\DrawCtl.h"	".\DrawCtl_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb ".\DrawCtl.tlb" /h "DrawCtl.h" /iid "DrawCtl_i.c" /win32 

".\DrawCtl.tlb"	".\DrawCtl.h"	".\DrawCtl_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\DrawCtl.rc

"$(INTDIR)\DrawCtl.res" : $(SOURCE) "$(INTDIR)" ".\DrawCtl.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "DrawCtl - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_WIN32_DCOM" /Fp"$(INTDIR)\DrawCtl.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\DrawCtl.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_WIN32_DCOM" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\DrawCtl.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\DrawCtl.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "_UNICODE" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_WIN32_DCOM" /Fp"$(INTDIR)\DrawCtl.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\DrawCtl.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DrawCtl - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "_UNICODE" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_WIN32_DCOM" /Fp"$(INTDIR)\DrawCtl.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\DrawCtl.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

