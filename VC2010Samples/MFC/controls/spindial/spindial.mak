# Microsoft Developer Studio Generated NMAKE File, Based on spindial.dsp
!IF "$(CFG)" == ""
CFG=SpinDial - Win32 Release
!MESSAGE No configuration specified. Defaulting to SpinDial - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "SpinDial - Win32 Release" && "$(CFG)" != "SpinDial - Win32 Debug" && "$(CFG)" != "SpinDial - Win32 Unicode Debug" && "$(CFG)" != "SpinDial - Win32 Unicode Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "spindial.mak" CFG="SpinDial - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SpinDial - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "SpinDial - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "SpinDial - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "SpinDial - Win32 Unicode Release" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "SpinDial - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\spindial.ocx" ".\.\Release\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\spinctl.obj"
	-@erase "$(INTDIR)\spindial.obj"
	-@erase "$(INTDIR)\spindial.pch"
	-@erase "$(INTDIR)\spindial.res"
	-@erase "$(INTDIR)\spindial.tlb"
	-@erase "$(INTDIR)\spinppg.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\spindial.exp"
	-@erase "$(OUTDIR)\spindial.lib"
	-@erase "$(OUTDIR)\spindial.ocx"
	-@erase ".\.\Release\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\spindial.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\spindial.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\spindial.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\spindial.pdb" /machine:I386 /def:".\spindial.def" /out:"$(OUTDIR)\spindial.ocx" /implib:"$(OUTDIR)\spindial.lib" 
DEF_FILE= \
	".\spindial.def"
LINK32_OBJS= \
	"$(INTDIR)\spinctl.obj" \
	"$(INTDIR)\spindial.obj" \
	"$(INTDIR)\spinppg.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\spindial.res"

"$(OUTDIR)\spindial.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\spindial.ocx
InputPath=.\Release\spindial.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "SpinDial - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\spindial.ocx" ".\.\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\spinctl.obj"
	-@erase "$(INTDIR)\spindial.obj"
	-@erase "$(INTDIR)\spindial.pch"
	-@erase "$(INTDIR)\spindial.res"
	-@erase "$(INTDIR)\spindial.tlb"
	-@erase "$(INTDIR)\spinppg.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\spindial.exp"
	-@erase "$(OUTDIR)\spindial.ilk"
	-@erase "$(OUTDIR)\spindial.lib"
	-@erase "$(OUTDIR)\spindial.ocx"
	-@erase "$(OUTDIR)\spindial.pdb"
	-@erase ".\.\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\spindial.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\spindial.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\spindial.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\spindial.pdb" /debug /machine:I386 /def:".\spindial.def" /out:"$(OUTDIR)\spindial.ocx" /implib:"$(OUTDIR)\spindial.lib" 
DEF_FILE= \
	".\spindial.def"
LINK32_OBJS= \
	"$(INTDIR)\spinctl.obj" \
	"$(INTDIR)\spindial.obj" \
	"$(INTDIR)\spinppg.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\spindial.res"

"$(OUTDIR)\spindial.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\spindial.ocx
InputPath=.\Debug\spindial.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "SpinDial - Win32 Unicode Debug"

OUTDIR=.\UniDebug
INTDIR=.\UniDebug
# Begin Custom Macros
OutDir=.\.\UniDebug
# End Custom Macros

ALL : "$(OUTDIR)\spindial.ocx" ".\.\UniDebug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\spinctl.obj"
	-@erase "$(INTDIR)\spindial.obj"
	-@erase "$(INTDIR)\spindial.pch"
	-@erase "$(INTDIR)\spindial.res"
	-@erase "$(INTDIR)\spindial.tlb"
	-@erase "$(INTDIR)\spinppg.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\spindial.exp"
	-@erase "$(OUTDIR)\spindial.ilk"
	-@erase "$(OUTDIR)\spindial.lib"
	-@erase "$(OUTDIR)\spindial.ocx"
	-@erase "$(OUTDIR)\spindial.pdb"
	-@erase ".\.\UniDebug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\spindial.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\spindial.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\spindial.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\spindial.pdb" /debug /machine:I386 /def:".\spindial.def" /out:"$(OUTDIR)\spindial.ocx" /implib:"$(OUTDIR)\spindial.lib" 
DEF_FILE= \
	".\spindial.def"
LINK32_OBJS= \
	"$(INTDIR)\spinctl.obj" \
	"$(INTDIR)\spindial.obj" \
	"$(INTDIR)\spinppg.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\spindial.res"

"$(OUTDIR)\spindial.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\UniDebug
TargetPath=.\UniDebug\spindial.ocx
InputPath=.\UniDebug\spindial.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "SpinDial - Win32 Unicode Release"

OUTDIR=.\UniRelease
INTDIR=.\UniRelease
# Begin Custom Macros
OutDir=.\.\UniRelease
# End Custom Macros

ALL : "$(OUTDIR)\spindial.ocx" ".\.\UniRelease\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\spinctl.obj"
	-@erase "$(INTDIR)\spindial.obj"
	-@erase "$(INTDIR)\spindial.pch"
	-@erase "$(INTDIR)\spindial.res"
	-@erase "$(INTDIR)\spindial.tlb"
	-@erase "$(INTDIR)\spinppg.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\spindial.exp"
	-@erase "$(OUTDIR)\spindial.lib"
	-@erase "$(OUTDIR)\spindial.ocx"
	-@erase ".\.\UniRelease\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\spindial.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\spindial.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\spindial.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\spindial.pdb" /machine:I386 /def:".\spindial.def" /out:"$(OUTDIR)\spindial.ocx" /implib:"$(OUTDIR)\spindial.lib" 
DEF_FILE= \
	".\spindial.def"
LINK32_OBJS= \
	"$(INTDIR)\spinctl.obj" \
	"$(INTDIR)\spindial.obj" \
	"$(INTDIR)\spinppg.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\spindial.res"

"$(OUTDIR)\spindial.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\UniRelease
TargetPath=.\UniRelease\spindial.ocx
InputPath=.\UniRelease\spindial.ocx
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
!IF EXISTS("spindial.dep")
!INCLUDE "spindial.dep"
!ELSE 
!MESSAGE Warning: cannot find "spindial.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "SpinDial - Win32 Release" || "$(CFG)" == "SpinDial - Win32 Debug" || "$(CFG)" == "SpinDial - Win32 Unicode Debug" || "$(CFG)" == "SpinDial - Win32 Unicode Release"
SOURCE=.\spinctl.cpp

"$(INTDIR)\spinctl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\spindial.pch"


SOURCE=.\spindial.cpp

"$(INTDIR)\spindial.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\spindial.pch"


SOURCE=.\spindial.odl

!IF  "$(CFG)" == "SpinDial - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\spindial.tlb" /mktyplib203 /win32 

"$(OUTDIR)\spindial.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SpinDial - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\spindial.tlb" /mktyplib203 /win32 

"$(OUTDIR)\spindial.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SpinDial - Win32 Unicode Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\spindial.tlb" /mktyplib203 /win32 

"$(OUTDIR)\spindial.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SpinDial - Win32 Unicode Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\spindial.tlb" /mktyplib203 /win32 

"$(OUTDIR)\spindial.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\spindial.rc

!IF  "$(CFG)" == "SpinDial - Win32 Release"


"$(INTDIR)\spindial.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\spindial.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\spindial.res" /i ".\Release" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "SpinDial - Win32 Debug"


"$(INTDIR)\spindial.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\spindial.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\spindial.res" /i ".\Debug" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "SpinDial - Win32 Unicode Debug"


"$(INTDIR)\spindial.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\spindial.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\spindial.res" /i ".\UniDebug" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "SpinDial - Win32 Unicode Release"


"$(INTDIR)\spindial.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\spindial.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\spindial.res" /i ".\UniRelease" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ENDIF 

SOURCE=.\spinppg.cpp

"$(INTDIR)\spinppg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\spindial.pch"


SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "SpinDial - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\spindial.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\spindial.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SpinDial - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\spindial.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\spindial.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SpinDial - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\spindial.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\spindial.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SpinDial - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\spindial.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\spindial.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

