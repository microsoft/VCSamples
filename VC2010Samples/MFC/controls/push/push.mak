# Microsoft Developer Studio Generated NMAKE File, Based on push.dsp
!IF "$(CFG)" == ""
CFG=Push - Win32 Release
!MESSAGE No configuration specified. Defaulting to Push - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Push - Win32 Release" && "$(CFG)" != "Push - Win32 Debug" && "$(CFG)" != "Push - Win32 Unicode Debug" && "$(CFG)" != "Push - Win32 Unicode Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "push.mak" CFG="Push - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Push - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Push - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Push - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Push - Win32 Unicode Release" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "Push - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\push.ocx" ".\.\Release\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\push.obj"
	-@erase "$(INTDIR)\push.pch"
	-@erase "$(INTDIR)\push.res"
	-@erase "$(INTDIR)\push.tlb"
	-@erase "$(INTDIR)\pushctl.obj"
	-@erase "$(INTDIR)\pushppg.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\push.exp"
	-@erase "$(OUTDIR)\push.lib"
	-@erase "$(OUTDIR)\push.ocx"
	-@erase ".\.\Release\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\push.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\push.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\push.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\push.pdb" /machine:I386 /def:".\push.def" /out:"$(OUTDIR)\push.ocx" /implib:"$(OUTDIR)\push.lib" 
DEF_FILE= \
	".\push.def"
LINK32_OBJS= \
	"$(INTDIR)\push.obj" \
	"$(INTDIR)\pushctl.obj" \
	"$(INTDIR)\pushppg.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\push.res"

"$(OUTDIR)\push.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\push.ocx
InputPath=.\Release\push.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "Push - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\push.ocx" ".\.\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\push.obj"
	-@erase "$(INTDIR)\push.pch"
	-@erase "$(INTDIR)\push.res"
	-@erase "$(INTDIR)\push.tlb"
	-@erase "$(INTDIR)\pushctl.obj"
	-@erase "$(INTDIR)\pushppg.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\push.exp"
	-@erase "$(OUTDIR)\push.ilk"
	-@erase "$(OUTDIR)\push.lib"
	-@erase "$(OUTDIR)\push.ocx"
	-@erase "$(OUTDIR)\push.pdb"
	-@erase ".\.\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\push.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\push.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\push.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\push.pdb" /debug /machine:I386 /def:".\push.def" /out:"$(OUTDIR)\push.ocx" /implib:"$(OUTDIR)\push.lib" 
DEF_FILE= \
	".\push.def"
LINK32_OBJS= \
	"$(INTDIR)\push.obj" \
	"$(INTDIR)\pushctl.obj" \
	"$(INTDIR)\pushppg.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\push.res"

"$(OUTDIR)\push.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\push.ocx
InputPath=.\Debug\push.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "Push - Win32 Unicode Debug"

OUTDIR=.\UniDebug
INTDIR=.\UniDebug
# Begin Custom Macros
OutDir=.\.\UniDebug
# End Custom Macros

ALL : "$(OUTDIR)\push.ocx" ".\.\UniDebug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\push.obj"
	-@erase "$(INTDIR)\push.pch"
	-@erase "$(INTDIR)\push.res"
	-@erase "$(INTDIR)\push.tlb"
	-@erase "$(INTDIR)\pushctl.obj"
	-@erase "$(INTDIR)\pushppg.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\push.exp"
	-@erase "$(OUTDIR)\push.ilk"
	-@erase "$(OUTDIR)\push.lib"
	-@erase "$(OUTDIR)\push.ocx"
	-@erase "$(OUTDIR)\push.pdb"
	-@erase ".\.\UniDebug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\push.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\push.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\push.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\push.pdb" /debug /machine:I386 /def:".\push.def" /out:"$(OUTDIR)\push.ocx" /implib:"$(OUTDIR)\push.lib" 
DEF_FILE= \
	".\push.def"
LINK32_OBJS= \
	"$(INTDIR)\push.obj" \
	"$(INTDIR)\pushctl.obj" \
	"$(INTDIR)\pushppg.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\push.res"

"$(OUTDIR)\push.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\UniDebug
TargetPath=.\UniDebug\push.ocx
InputPath=.\UniDebug\push.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "Push - Win32 Unicode Release"

OUTDIR=.\UniRelease
INTDIR=.\UniRelease
# Begin Custom Macros
OutDir=.\.\UniRelease
# End Custom Macros

ALL : "$(OUTDIR)\push.ocx" ".\.\UniRelease\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\push.obj"
	-@erase "$(INTDIR)\push.pch"
	-@erase "$(INTDIR)\push.res"
	-@erase "$(INTDIR)\push.tlb"
	-@erase "$(INTDIR)\pushctl.obj"
	-@erase "$(INTDIR)\pushppg.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\push.exp"
	-@erase "$(OUTDIR)\push.lib"
	-@erase "$(OUTDIR)\push.ocx"
	-@erase ".\.\UniRelease\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\push.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\push.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\push.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\push.pdb" /machine:I386 /def:".\push.def" /out:"$(OUTDIR)\push.ocx" /implib:"$(OUTDIR)\push.lib" 
DEF_FILE= \
	".\push.def"
LINK32_OBJS= \
	"$(INTDIR)\push.obj" \
	"$(INTDIR)\pushctl.obj" \
	"$(INTDIR)\pushppg.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\push.res"

"$(OUTDIR)\push.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\UniRelease
TargetPath=.\UniRelease\push.ocx
InputPath=.\UniRelease\push.ocx
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
!IF EXISTS("push.dep")
!INCLUDE "push.dep"
!ELSE 
!MESSAGE Warning: cannot find "push.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Push - Win32 Release" || "$(CFG)" == "Push - Win32 Debug" || "$(CFG)" == "Push - Win32 Unicode Debug" || "$(CFG)" == "Push - Win32 Unicode Release"
SOURCE=.\push.cpp

"$(INTDIR)\push.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\push.pch"


SOURCE=.\push.odl

!IF  "$(CFG)" == "Push - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\push.tlb" /mktyplib203 /win32 

"$(OUTDIR)\push.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Push - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\push.tlb" /mktyplib203 /win32 

"$(OUTDIR)\push.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Push - Win32 Unicode Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\push.tlb" /mktyplib203 /win32 

"$(OUTDIR)\push.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Push - Win32 Unicode Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\push.tlb" /mktyplib203 /win32 

"$(OUTDIR)\push.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\push.rc

!IF  "$(CFG)" == "Push - Win32 Release"


"$(INTDIR)\push.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\push.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\push.res" /i ".\Release" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "Push - Win32 Debug"


"$(INTDIR)\push.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\push.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\push.res" /i ".\Debug" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "Push - Win32 Unicode Debug"


"$(INTDIR)\push.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\push.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\push.res" /i ".\UniDebug" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "Push - Win32 Unicode Release"


"$(INTDIR)\push.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\push.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\push.res" /i ".\UniRelease" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ENDIF 

SOURCE=.\pushctl.cpp

"$(INTDIR)\pushctl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\push.pch"


SOURCE=.\pushppg.cpp

"$(INTDIR)\pushppg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\push.pch"


SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "Push - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\push.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\push.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Push - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\push.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\push.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Push - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\push.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\push.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Push - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\push.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\push.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

