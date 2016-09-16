# Microsoft Developer Studio Generated NMAKE File, Based on button.dsp
!IF "$(CFG)" == ""
CFG=Button - Win32 Release
!MESSAGE No configuration specified. Defaulting to Button - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Button - Win32 Release" && "$(CFG)" != "Button - Win32 Debug" && "$(CFG)" != "Button - Win32 Unicode Debug" && "$(CFG)" != "Button - Win32 Unicode Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "button.mak" CFG="Button - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Button - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Button - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Button - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Button - Win32 Unicode Release" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "Button - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\button.ocx" ".\.\Release\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\btnctl.obj"
	-@erase "$(INTDIR)\btnppg.obj"
	-@erase "$(INTDIR)\button.obj"
	-@erase "$(INTDIR)\button.pch"
	-@erase "$(INTDIR)\button.res"
	-@erase "$(INTDIR)\button.tlb"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\button.exp"
	-@erase "$(OUTDIR)\button.lib"
	-@erase "$(OUTDIR)\button.ocx"
	-@erase ".\.\Release\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\button.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\button.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\button.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\button.pdb" /machine:I386 /def:".\button.def" /out:"$(OUTDIR)\button.ocx" /implib:"$(OUTDIR)\button.lib" 
DEF_FILE= \
	".\button.def"
LINK32_OBJS= \
	"$(INTDIR)\btnctl.obj" \
	"$(INTDIR)\btnppg.obj" \
	"$(INTDIR)\button.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\button.res"

"$(OUTDIR)\button.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\button.ocx
InputPath=.\Release\button.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "Button - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\button.ocx" ".\.\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\btnctl.obj"
	-@erase "$(INTDIR)\btnppg.obj"
	-@erase "$(INTDIR)\button.obj"
	-@erase "$(INTDIR)\button.pch"
	-@erase "$(INTDIR)\button.res"
	-@erase "$(INTDIR)\button.tlb"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\button.exp"
	-@erase "$(OUTDIR)\button.ilk"
	-@erase "$(OUTDIR)\button.lib"
	-@erase "$(OUTDIR)\button.ocx"
	-@erase "$(OUTDIR)\button.pdb"
	-@erase ".\.\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\button.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\button.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\button.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\button.pdb" /debug /machine:I386 /def:".\button.def" /out:"$(OUTDIR)\button.ocx" /implib:"$(OUTDIR)\button.lib" 
DEF_FILE= \
	".\button.def"
LINK32_OBJS= \
	"$(INTDIR)\btnctl.obj" \
	"$(INTDIR)\btnppg.obj" \
	"$(INTDIR)\button.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\button.res"

"$(OUTDIR)\button.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\button.ocx
InputPath=.\Debug\button.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "Button - Win32 Unicode Debug"

OUTDIR=.\UniDebug
INTDIR=.\UniDebug
# Begin Custom Macros
OutDir=.\.\UniDebug
# End Custom Macros

ALL : "$(OUTDIR)\button.ocx" ".\.\UniDebug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\btnctl.obj"
	-@erase "$(INTDIR)\btnppg.obj"
	-@erase "$(INTDIR)\button.obj"
	-@erase "$(INTDIR)\button.pch"
	-@erase "$(INTDIR)\button.res"
	-@erase "$(INTDIR)\button.tlb"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\button.exp"
	-@erase "$(OUTDIR)\button.ilk"
	-@erase "$(OUTDIR)\button.lib"
	-@erase "$(OUTDIR)\button.ocx"
	-@erase "$(OUTDIR)\button.pdb"
	-@erase ".\.\UniDebug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\button.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\button.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\button.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\button.pdb" /debug /machine:I386 /def:".\button.def" /out:"$(OUTDIR)\button.ocx" /implib:"$(OUTDIR)\button.lib" 
DEF_FILE= \
	".\button.def"
LINK32_OBJS= \
	"$(INTDIR)\btnctl.obj" \
	"$(INTDIR)\btnppg.obj" \
	"$(INTDIR)\button.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\button.res"

"$(OUTDIR)\button.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\UniDebug
TargetPath=.\UniDebug\button.ocx
InputPath=.\UniDebug\button.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "Button - Win32 Unicode Release"

OUTDIR=.\UniRelease
INTDIR=.\UniRelease
# Begin Custom Macros
OutDir=.\.\UniRelease
# End Custom Macros

ALL : "$(OUTDIR)\button.ocx" ".\.\UniRelease\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\btnctl.obj"
	-@erase "$(INTDIR)\btnppg.obj"
	-@erase "$(INTDIR)\button.obj"
	-@erase "$(INTDIR)\button.pch"
	-@erase "$(INTDIR)\button.res"
	-@erase "$(INTDIR)\button.tlb"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\button.exp"
	-@erase "$(OUTDIR)\button.lib"
	-@erase "$(OUTDIR)\button.ocx"
	-@erase ".\.\UniRelease\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\button.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\button.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\button.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\button.pdb" /machine:I386 /def:".\button.def" /out:"$(OUTDIR)\button.ocx" /implib:"$(OUTDIR)\button.lib" 
DEF_FILE= \
	".\button.def"
LINK32_OBJS= \
	"$(INTDIR)\btnctl.obj" \
	"$(INTDIR)\btnppg.obj" \
	"$(INTDIR)\button.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\button.res"

"$(OUTDIR)\button.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\UniRelease
TargetPath=.\UniRelease\button.ocx
InputPath=.\UniRelease\button.ocx
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
!IF EXISTS("button.dep")
!INCLUDE "button.dep"
!ELSE 
!MESSAGE Warning: cannot find "button.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Button - Win32 Release" || "$(CFG)" == "Button - Win32 Debug" || "$(CFG)" == "Button - Win32 Unicode Debug" || "$(CFG)" == "Button - Win32 Unicode Release"
SOURCE=.\btnctl.cpp

"$(INTDIR)\btnctl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\button.pch"


SOURCE=.\btnppg.cpp

"$(INTDIR)\btnppg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\button.pch"


SOURCE=.\button.cpp

"$(INTDIR)\button.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\button.pch"


SOURCE=.\button.odl

!IF  "$(CFG)" == "Button - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\button.tlb" /mktyplib203 /win32 

"$(OUTDIR)\button.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Button - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\button.tlb" /mktyplib203 /win32 

"$(OUTDIR)\button.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Button - Win32 Unicode Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\button.tlb" /mktyplib203 /win32 

"$(OUTDIR)\button.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Button - Win32 Unicode Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\button.tlb" /mktyplib203 /win32 

"$(OUTDIR)\button.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\button.rc

!IF  "$(CFG)" == "Button - Win32 Release"


"$(INTDIR)\button.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\button.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\button.res" /i ".\Release" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "Button - Win32 Debug"


"$(INTDIR)\button.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\button.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\button.res" /i ".\Debug" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "Button - Win32 Unicode Debug"


"$(INTDIR)\button.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\button.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\button.res" /i ".\UniDebug" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "Button - Win32 Unicode Release"


"$(INTDIR)\button.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\button.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\button.res" /i ".\UniRelease" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ENDIF 

SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "Button - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\button.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\button.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Button - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\button.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\button.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Button - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\button.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\button.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Button - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\button.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\button.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

