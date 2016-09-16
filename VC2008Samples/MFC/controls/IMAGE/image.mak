# Microsoft Developer Studio Generated NMAKE File, Based on image.dsp
!IF "$(CFG)" == ""
CFG=image - Win32 Release
!MESSAGE No configuration specified. Defaulting to image - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "image - Win32 Release" && "$(CFG)" != "image - Win32 Debug" && "$(CFG)" != "image - Win32 Unicode Debug" && "$(CFG)" != "image - Win32 Unicode Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "image.mak" CFG="image - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "image - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "image - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "image - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "image - Win32 Unicode Release" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "image - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\image.ocx" "$(OUTDIR)\image.bsc" ".\.\Release\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\bmpprop.obj"
	-@erase "$(INTDIR)\bmpprop.sbr"
	-@erase "$(INTDIR)\image.obj"
	-@erase "$(INTDIR)\image.pch"
	-@erase "$(INTDIR)\image.res"
	-@erase "$(INTDIR)\image.sbr"
	-@erase "$(INTDIR)\image.tlb"
	-@erase "$(INTDIR)\ImageCtl.obj"
	-@erase "$(INTDIR)\ImageCtl.sbr"
	-@erase "$(INTDIR)\ImagePpg.obj"
	-@erase "$(INTDIR)\ImagePpg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\image.bsc"
	-@erase "$(OUTDIR)\image.exp"
	-@erase "$(OUTDIR)\image.lib"
	-@erase "$(OUTDIR)\image.ocx"
	-@erase ".\.\Release\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\image.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\image.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\image.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\bmpprop.sbr" \
	"$(INTDIR)\image.sbr" \
	"$(INTDIR)\ImageCtl.sbr" \
	"$(INTDIR)\ImagePpg.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\image.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\image.pdb" /machine:I386 /def:".\image.def" /out:"$(OUTDIR)\image.ocx" /implib:"$(OUTDIR)\image.lib" 
DEF_FILE= \
	".\image.def"
LINK32_OBJS= \
	"$(INTDIR)\bmpprop.obj" \
	"$(INTDIR)\image.obj" \
	"$(INTDIR)\ImageCtl.obj" \
	"$(INTDIR)\ImagePpg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\image.res"

"$(OUTDIR)\image.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\image.ocx
InputPath=.\Release\image.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "image - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\image.ocx" "$(OUTDIR)\image.bsc" ".\.\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\bmpprop.obj"
	-@erase "$(INTDIR)\bmpprop.sbr"
	-@erase "$(INTDIR)\image.obj"
	-@erase "$(INTDIR)\image.pch"
	-@erase "$(INTDIR)\image.res"
	-@erase "$(INTDIR)\image.sbr"
	-@erase "$(INTDIR)\image.tlb"
	-@erase "$(INTDIR)\ImageCtl.obj"
	-@erase "$(INTDIR)\ImageCtl.sbr"
	-@erase "$(INTDIR)\ImagePpg.obj"
	-@erase "$(INTDIR)\ImagePpg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\image.bsc"
	-@erase "$(OUTDIR)\image.exp"
	-@erase "$(OUTDIR)\image.ilk"
	-@erase "$(OUTDIR)\image.lib"
	-@erase "$(OUTDIR)\image.ocx"
	-@erase "$(OUTDIR)\image.pdb"
	-@erase ".\.\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\image.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\image.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\image.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\bmpprop.sbr" \
	"$(INTDIR)\image.sbr" \
	"$(INTDIR)\ImageCtl.sbr" \
	"$(INTDIR)\ImagePpg.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\image.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\image.pdb" /debug /machine:I386 /def:".\image.def" /out:"$(OUTDIR)\image.ocx" /implib:"$(OUTDIR)\image.lib" 
DEF_FILE= \
	".\image.def"
LINK32_OBJS= \
	"$(INTDIR)\bmpprop.obj" \
	"$(INTDIR)\image.obj" \
	"$(INTDIR)\ImageCtl.obj" \
	"$(INTDIR)\ImagePpg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\image.res"

"$(OUTDIR)\image.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\image.ocx
InputPath=.\Debug\image.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "image - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\.\DebugU
# End Custom Macros

ALL : "$(OUTDIR)\image.ocx" "$(OUTDIR)\image.bsc" ".\.\DebugU\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\bmpprop.obj"
	-@erase "$(INTDIR)\bmpprop.sbr"
	-@erase "$(INTDIR)\image.obj"
	-@erase "$(INTDIR)\image.pch"
	-@erase "$(INTDIR)\image.res"
	-@erase "$(INTDIR)\image.sbr"
	-@erase "$(INTDIR)\image.tlb"
	-@erase "$(INTDIR)\ImageCtl.obj"
	-@erase "$(INTDIR)\ImageCtl.sbr"
	-@erase "$(INTDIR)\ImagePpg.obj"
	-@erase "$(INTDIR)\ImagePpg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\image.bsc"
	-@erase "$(OUTDIR)\image.exp"
	-@erase "$(OUTDIR)\image.ilk"
	-@erase "$(OUTDIR)\image.lib"
	-@erase "$(OUTDIR)\image.ocx"
	-@erase "$(OUTDIR)\image.pdb"
	-@erase ".\.\DebugU\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\image.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\image.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\image.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\bmpprop.sbr" \
	"$(INTDIR)\image.sbr" \
	"$(INTDIR)\ImageCtl.sbr" \
	"$(INTDIR)\ImagePpg.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\image.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\image.pdb" /debug /machine:I386 /def:".\image.def" /out:"$(OUTDIR)\image.ocx" /implib:"$(OUTDIR)\image.lib" 
DEF_FILE= \
	".\image.def"
LINK32_OBJS= \
	"$(INTDIR)\bmpprop.obj" \
	"$(INTDIR)\image.obj" \
	"$(INTDIR)\ImageCtl.obj" \
	"$(INTDIR)\ImagePpg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\image.res"

"$(OUTDIR)\image.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\DebugU
TargetPath=.\DebugU\image.ocx
InputPath=.\DebugU\image.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "image - Win32 Unicode Release"

OUTDIR=.\ReleaseU
INTDIR=.\ReleaseU
# Begin Custom Macros
OutDir=.\.\ReleaseU
# End Custom Macros

ALL : "$(OUTDIR)\image.ocx" "$(OUTDIR)\image.bsc" ".\.\ReleaseU\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\bmpprop.obj"
	-@erase "$(INTDIR)\bmpprop.sbr"
	-@erase "$(INTDIR)\image.obj"
	-@erase "$(INTDIR)\image.pch"
	-@erase "$(INTDIR)\image.res"
	-@erase "$(INTDIR)\image.sbr"
	-@erase "$(INTDIR)\image.tlb"
	-@erase "$(INTDIR)\ImageCtl.obj"
	-@erase "$(INTDIR)\ImageCtl.sbr"
	-@erase "$(INTDIR)\ImagePpg.obj"
	-@erase "$(INTDIR)\ImagePpg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\image.bsc"
	-@erase "$(OUTDIR)\image.exp"
	-@erase "$(OUTDIR)\image.lib"
	-@erase "$(OUTDIR)\image.ocx"
	-@erase ".\.\ReleaseU\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\image.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\image.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\image.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\bmpprop.sbr" \
	"$(INTDIR)\image.sbr" \
	"$(INTDIR)\ImageCtl.sbr" \
	"$(INTDIR)\ImagePpg.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\image.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\image.pdb" /machine:I386 /def:".\image.def" /out:"$(OUTDIR)\image.ocx" /implib:"$(OUTDIR)\image.lib" 
DEF_FILE= \
	".\image.def"
LINK32_OBJS= \
	"$(INTDIR)\bmpprop.obj" \
	"$(INTDIR)\image.obj" \
	"$(INTDIR)\ImageCtl.obj" \
	"$(INTDIR)\ImagePpg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\image.res"

"$(OUTDIR)\image.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\ReleaseU
TargetPath=.\ReleaseU\image.ocx
InputPath=.\ReleaseU\image.ocx
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
!IF EXISTS("image.dep")
!INCLUDE "image.dep"
!ELSE 
!MESSAGE Warning: cannot find "image.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "image - Win32 Release" || "$(CFG)" == "image - Win32 Debug" || "$(CFG)" == "image - Win32 Unicode Debug" || "$(CFG)" == "image - Win32 Unicode Release"
SOURCE=.\bmpprop.cpp

"$(INTDIR)\bmpprop.obj"	"$(INTDIR)\bmpprop.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\image.pch"


SOURCE=.\image.cpp

"$(INTDIR)\image.obj"	"$(INTDIR)\image.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\image.pch"


SOURCE=.\image.odl

!IF  "$(CFG)" == "image - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\image.tlb" /mktyplib203 /win32 

"$(OUTDIR)\image.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "image - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\image.tlb" /mktyplib203 /win32 

"$(OUTDIR)\image.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "image - Win32 Unicode Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\image.tlb" /mktyplib203 /win32 

"$(OUTDIR)\image.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "image - Win32 Unicode Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\image.tlb" /mktyplib203 /win32 

"$(OUTDIR)\image.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\image.rc

!IF  "$(CFG)" == "image - Win32 Release"


"$(INTDIR)\image.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\image.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\image.res" /i ".\Release" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "image - Win32 Debug"


"$(INTDIR)\image.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\image.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\image.res" /i ".\Debug" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "image - Win32 Unicode Debug"


"$(INTDIR)\image.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\image.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\image.res" /i ".\DebugU" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "image - Win32 Unicode Release"


"$(INTDIR)\image.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\image.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\image.res" /i ".\ReleaseU" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ENDIF 

SOURCE=.\ImageCtl.cpp

"$(INTDIR)\ImageCtl.obj"	"$(INTDIR)\ImageCtl.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\image.pch"


SOURCE=.\ImagePpg.cpp

"$(INTDIR)\ImagePpg.obj"	"$(INTDIR)\ImagePpg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\image.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "image - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\image.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\image.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "image - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\image.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\image.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "image - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\image.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\image.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "image - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\image.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\image.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

