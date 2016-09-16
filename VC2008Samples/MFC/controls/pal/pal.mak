# Microsoft Developer Studio Generated NMAKE File, Based on pal.dsp
!IF "$(CFG)" == ""
CFG=Pal - Win32 Release
!MESSAGE No configuration specified. Defaulting to Pal - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Pal - Win32 Release" && "$(CFG)" != "Pal - Win32 Debug" && "$(CFG)" != "Pal - Win32 Unicode Debug" && "$(CFG)" != "Pal - Win32 Unicode Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "pal.mak" CFG="Pal - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Pal - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Pal - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Pal - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Pal - Win32 Unicode Release" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "Pal - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\pal.ocx" ".\.\Release\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\pal.obj"
	-@erase "$(INTDIR)\pal.pch"
	-@erase "$(INTDIR)\pal.res"
	-@erase "$(INTDIR)\pal.tlb"
	-@erase "$(INTDIR)\palctl.obj"
	-@erase "$(INTDIR)\palppg.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\pal.exp"
	-@erase "$(OUTDIR)\pal.lib"
	-@erase "$(OUTDIR)\pal.ocx"
	-@erase ".\.\Release\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\pal.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\pal.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\pal.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\pal.pdb" /machine:I386 /def:".\pal.def" /out:"$(OUTDIR)\pal.ocx" /implib:"$(OUTDIR)\pal.lib" 
DEF_FILE= \
	".\pal.def"
LINK32_OBJS= \
	"$(INTDIR)\pal.obj" \
	"$(INTDIR)\palctl.obj" \
	"$(INTDIR)\palppg.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\pal.res"

"$(OUTDIR)\pal.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\pal.ocx
InputPath=.\Release\pal.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "Pal - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\pal.ocx" ".\.\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\pal.obj"
	-@erase "$(INTDIR)\pal.pch"
	-@erase "$(INTDIR)\pal.res"
	-@erase "$(INTDIR)\pal.tlb"
	-@erase "$(INTDIR)\palctl.obj"
	-@erase "$(INTDIR)\palppg.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\pal.exp"
	-@erase "$(OUTDIR)\pal.ilk"
	-@erase "$(OUTDIR)\pal.lib"
	-@erase "$(OUTDIR)\pal.ocx"
	-@erase "$(OUTDIR)\pal.pdb"
	-@erase ".\.\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\pal.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\pal.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\pal.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\pal.pdb" /debug /machine:I386 /def:".\pal.def" /out:"$(OUTDIR)\pal.ocx" /implib:"$(OUTDIR)\pal.lib" 
DEF_FILE= \
	".\pal.def"
LINK32_OBJS= \
	"$(INTDIR)\pal.obj" \
	"$(INTDIR)\palctl.obj" \
	"$(INTDIR)\palppg.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\pal.res"

"$(OUTDIR)\pal.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\pal.ocx
InputPath=.\Debug\pal.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "Pal - Win32 Unicode Debug"

OUTDIR=.\UniDebug
INTDIR=.\UniDebug
# Begin Custom Macros
OutDir=.\.\UniDebug
# End Custom Macros

ALL : "$(OUTDIR)\pal.ocx" ".\.\UniDebug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\pal.obj"
	-@erase "$(INTDIR)\pal.pch"
	-@erase "$(INTDIR)\pal.res"
	-@erase "$(INTDIR)\pal.tlb"
	-@erase "$(INTDIR)\palctl.obj"
	-@erase "$(INTDIR)\palppg.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\pal.exp"
	-@erase "$(OUTDIR)\pal.ilk"
	-@erase "$(OUTDIR)\pal.lib"
	-@erase "$(OUTDIR)\pal.ocx"
	-@erase "$(OUTDIR)\pal.pdb"
	-@erase ".\.\UniDebug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\pal.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\pal.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\pal.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\pal.pdb" /debug /machine:I386 /def:".\pal.def" /out:"$(OUTDIR)\pal.ocx" /implib:"$(OUTDIR)\pal.lib" 
DEF_FILE= \
	".\pal.def"
LINK32_OBJS= \
	"$(INTDIR)\pal.obj" \
	"$(INTDIR)\palctl.obj" \
	"$(INTDIR)\palppg.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\pal.res"

"$(OUTDIR)\pal.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\UniDebug
TargetPath=.\UniDebug\pal.ocx
InputPath=.\UniDebug\pal.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "Pal - Win32 Unicode Release"

OUTDIR=.\UniRelease
INTDIR=.\UniRelease
# Begin Custom Macros
OutDir=.\.\UniRelease
# End Custom Macros

ALL : "$(OUTDIR)\pal.ocx" ".\.\UniRelease\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\pal.obj"
	-@erase "$(INTDIR)\pal.pch"
	-@erase "$(INTDIR)\pal.res"
	-@erase "$(INTDIR)\pal.tlb"
	-@erase "$(INTDIR)\palctl.obj"
	-@erase "$(INTDIR)\palppg.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\pal.exp"
	-@erase "$(OUTDIR)\pal.lib"
	-@erase "$(OUTDIR)\pal.ocx"
	-@erase ".\.\UniRelease\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\pal.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\pal.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\pal.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\pal.pdb" /machine:I386 /def:".\pal.def" /out:"$(OUTDIR)\pal.ocx" /implib:"$(OUTDIR)\pal.lib" 
DEF_FILE= \
	".\pal.def"
LINK32_OBJS= \
	"$(INTDIR)\pal.obj" \
	"$(INTDIR)\palctl.obj" \
	"$(INTDIR)\palppg.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\pal.res"

"$(OUTDIR)\pal.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\UniRelease
TargetPath=.\UniRelease\pal.ocx
InputPath=.\UniRelease\pal.ocx
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
!IF EXISTS("pal.dep")
!INCLUDE "pal.dep"
!ELSE 
!MESSAGE Warning: cannot find "pal.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Pal - Win32 Release" || "$(CFG)" == "Pal - Win32 Debug" || "$(CFG)" == "Pal - Win32 Unicode Debug" || "$(CFG)" == "Pal - Win32 Unicode Release"
SOURCE=.\pal.cpp

"$(INTDIR)\pal.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\pal.pch"


SOURCE=.\pal.odl

!IF  "$(CFG)" == "Pal - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\pal.tlb" /mktyplib203 /win32 

"$(OUTDIR)\pal.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Pal - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\pal.tlb" /mktyplib203 /win32 

"$(OUTDIR)\pal.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Pal - Win32 Unicode Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\pal.tlb" /mktyplib203 /win32 

"$(OUTDIR)\pal.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Pal - Win32 Unicode Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\pal.tlb" /mktyplib203 /win32 

"$(OUTDIR)\pal.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\pal.rc

!IF  "$(CFG)" == "Pal - Win32 Release"


"$(INTDIR)\pal.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\pal.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\pal.res" /i ".\Release" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "Pal - Win32 Debug"


"$(INTDIR)\pal.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\pal.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\pal.res" /i ".\Debug" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "Pal - Win32 Unicode Debug"


"$(INTDIR)\pal.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\pal.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\pal.res" /i ".\UniDebug" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "Pal - Win32 Unicode Release"


"$(INTDIR)\pal.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\pal.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\pal.res" /i ".\UniRelease" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ENDIF 

SOURCE=.\palctl.cpp

"$(INTDIR)\palctl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\pal.pch"


SOURCE=.\palppg.cpp

"$(INTDIR)\palppg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\pal.pch"


SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "Pal - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\pal.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\pal.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Pal - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\pal.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\pal.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Pal - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\pal.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\pal.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Pal - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\pal.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\pal.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

