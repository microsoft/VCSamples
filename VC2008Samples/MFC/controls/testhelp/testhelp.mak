# Microsoft Developer Studio Generated NMAKE File, Based on testhelp.dsp
!IF "$(CFG)" == ""
CFG=testhelp - Win32 Release
!MESSAGE No configuration specified. Defaulting to testhelp - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "testhelp - Win32 Release" && "$(CFG)" != "testhelp - Win32 Debug" && "$(CFG)" != "testhelp - Win32 Unicode Debug" && "$(CFG)" != "testhelp - Win32 Unicode Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "testhelp.mak" CFG="testhelp - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "testhelp - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "testhelp - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "testhelp - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "testhelp - Win32 Unicode Release" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "testhelp - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\testhelp.ocx" ".\.\Release\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\testhelp.obj"
	-@erase "$(INTDIR)\testhelp.pch"
	-@erase "$(INTDIR)\testhelp.res"
	-@erase "$(INTDIR)\testhelp.tlb"
	-@erase "$(INTDIR)\ThelpCtl.obj"
	-@erase "$(INTDIR)\ThelpPpg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\testhelp.exp"
	-@erase "$(OUTDIR)\testhelp.lib"
	-@erase "$(OUTDIR)\testhelp.ocx"
	-@erase ".\.\Release\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\testhelp.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\testhelp.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\testhelp.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\testhelp.pdb" /machine:I386 /def:".\testhelp.def" /out:"$(OUTDIR)\testhelp.ocx" /implib:"$(OUTDIR)\testhelp.lib" 
DEF_FILE= \
	".\testhelp.def"
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\testhelp.obj" \
	"$(INTDIR)\ThelpCtl.obj" \
	"$(INTDIR)\ThelpPpg.obj" \
	"$(INTDIR)\testhelp.res"

"$(OUTDIR)\testhelp.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\testhelp.ocx
InputPath=.\Release\testhelp.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "testhelp - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\testhelp.ocx" ".\.\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\testhelp.obj"
	-@erase "$(INTDIR)\testhelp.pch"
	-@erase "$(INTDIR)\testhelp.res"
	-@erase "$(INTDIR)\testhelp.tlb"
	-@erase "$(INTDIR)\ThelpCtl.obj"
	-@erase "$(INTDIR)\ThelpPpg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\testhelp.exp"
	-@erase "$(OUTDIR)\testhelp.ilk"
	-@erase "$(OUTDIR)\testhelp.lib"
	-@erase "$(OUTDIR)\testhelp.ocx"
	-@erase "$(OUTDIR)\testhelp.pdb"
	-@erase ".\.\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\testhelp.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\testhelp.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\testhelp.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\testhelp.pdb" /debug /machine:I386 /def:".\testhelp.def" /out:"$(OUTDIR)\testhelp.ocx" /implib:"$(OUTDIR)\testhelp.lib" 
DEF_FILE= \
	".\testhelp.def"
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\testhelp.obj" \
	"$(INTDIR)\ThelpCtl.obj" \
	"$(INTDIR)\ThelpPpg.obj" \
	"$(INTDIR)\testhelp.res"

"$(OUTDIR)\testhelp.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\testhelp.ocx
InputPath=.\Debug\testhelp.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "testhelp - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\.\DebugU
# End Custom Macros

ALL : "$(OUTDIR)\testhelp.ocx" ".\.\DebugU\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\testhelp.obj"
	-@erase "$(INTDIR)\testhelp.pch"
	-@erase "$(INTDIR)\testhelp.res"
	-@erase "$(INTDIR)\testhelp.tlb"
	-@erase "$(INTDIR)\ThelpCtl.obj"
	-@erase "$(INTDIR)\ThelpPpg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\testhelp.exp"
	-@erase "$(OUTDIR)\testhelp.ilk"
	-@erase "$(OUTDIR)\testhelp.lib"
	-@erase "$(OUTDIR)\testhelp.ocx"
	-@erase "$(OUTDIR)\testhelp.pdb"
	-@erase ".\.\DebugU\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\testhelp.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\testhelp.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\testhelp.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\testhelp.pdb" /debug /machine:I386 /def:".\testhelp.def" /out:"$(OUTDIR)\testhelp.ocx" /implib:"$(OUTDIR)\testhelp.lib" 
DEF_FILE= \
	".\testhelp.def"
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\testhelp.obj" \
	"$(INTDIR)\ThelpCtl.obj" \
	"$(INTDIR)\ThelpPpg.obj" \
	"$(INTDIR)\testhelp.res"

"$(OUTDIR)\testhelp.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\DebugU
TargetPath=.\DebugU\testhelp.ocx
InputPath=.\DebugU\testhelp.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "testhelp - Win32 Unicode Release"

OUTDIR=.\ReleaseU
INTDIR=.\ReleaseU
# Begin Custom Macros
OutDir=.\.\ReleaseU
# End Custom Macros

ALL : "$(OUTDIR)\testhelp.ocx" ".\.\ReleaseU\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\testhelp.obj"
	-@erase "$(INTDIR)\testhelp.pch"
	-@erase "$(INTDIR)\testhelp.res"
	-@erase "$(INTDIR)\testhelp.tlb"
	-@erase "$(INTDIR)\ThelpCtl.obj"
	-@erase "$(INTDIR)\ThelpPpg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\testhelp.exp"
	-@erase "$(OUTDIR)\testhelp.lib"
	-@erase "$(OUTDIR)\testhelp.ocx"
	-@erase ".\.\ReleaseU\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\testhelp.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\testhelp.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\testhelp.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\testhelp.pdb" /machine:I386 /def:".\testhelp.def" /out:"$(OUTDIR)\testhelp.ocx" /implib:"$(OUTDIR)\testhelp.lib" 
DEF_FILE= \
	".\testhelp.def"
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\testhelp.obj" \
	"$(INTDIR)\ThelpCtl.obj" \
	"$(INTDIR)\ThelpPpg.obj" \
	"$(INTDIR)\testhelp.res"

"$(OUTDIR)\testhelp.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\ReleaseU
TargetPath=.\ReleaseU\testhelp.ocx
InputPath=.\ReleaseU\testhelp.ocx
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
!IF EXISTS("testhelp.dep")
!INCLUDE "testhelp.dep"
!ELSE 
!MESSAGE Warning: cannot find "testhelp.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "testhelp - Win32 Release" || "$(CFG)" == "testhelp - Win32 Debug" || "$(CFG)" == "testhelp - Win32 Unicode Debug" || "$(CFG)" == "testhelp - Win32 Unicode Release"
SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "testhelp - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\testhelp.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\testhelp.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "testhelp - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\testhelp.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\testhelp.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "testhelp - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\testhelp.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\testhelp.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "testhelp - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\testhelp.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\testhelp.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\testhelp.cpp

"$(INTDIR)\testhelp.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\testhelp.pch"


SOURCE=.\testhelp.odl

!IF  "$(CFG)" == "testhelp - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\testhelp.tlb" /mktyplib203 /win32 

"$(OUTDIR)\testhelp.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "testhelp - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\testhelp.tlb" /mktyplib203 /win32 

"$(OUTDIR)\testhelp.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "testhelp - Win32 Unicode Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\testhelp.tlb" /mktyplib203 /win32 

"$(OUTDIR)\testhelp.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "testhelp - Win32 Unicode Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\testhelp.tlb" /mktyplib203 /win32 

"$(OUTDIR)\testhelp.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\testhelp.rc

!IF  "$(CFG)" == "testhelp - Win32 Release"


"$(INTDIR)\testhelp.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\testhelp.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\testhelp.res" /i ".\Release" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "testhelp - Win32 Debug"


"$(INTDIR)\testhelp.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\testhelp.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\testhelp.res" /i ".\Debug" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "testhelp - Win32 Unicode Debug"


"$(INTDIR)\testhelp.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\testhelp.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\testhelp.res" /i ".\DebugU" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "testhelp - Win32 Unicode Release"


"$(INTDIR)\testhelp.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\testhelp.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\testhelp.res" /i ".\ReleaseU" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ENDIF 

SOURCE=.\ThelpCtl.cpp

"$(INTDIR)\ThelpCtl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\testhelp.pch"


SOURCE=.\ThelpPpg.cpp

"$(INTDIR)\ThelpPpg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\testhelp.pch"



!ENDIF 

