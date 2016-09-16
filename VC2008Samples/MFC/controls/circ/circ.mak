# Microsoft Developer Studio Generated NMAKE File, Based on circ.dsp
!IF "$(CFG)" == ""
CFG=Circ - Win32 Release
!MESSAGE No configuration specified. Defaulting to Circ - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Circ - Win32 Release" && "$(CFG)" != "Circ - Win32 Debug" && "$(CFG)" != "Circ - Win32 Unicode Debug" && "$(CFG)" != "Circ - Win32 Unicode Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "circ.mak" CFG="Circ - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Circ - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Circ - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Circ - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Circ - Win32 Unicode Release" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "Circ - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\circ.ocx" ".\.\Release\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\circ.obj"
	-@erase "$(INTDIR)\circ.pch"
	-@erase "$(INTDIR)\circ.res"
	-@erase "$(INTDIR)\circ.tlb"
	-@erase "$(INTDIR)\circctl.obj"
	-@erase "$(INTDIR)\circppg.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\circ.exp"
	-@erase "$(OUTDIR)\circ.lib"
	-@erase "$(OUTDIR)\circ.ocx"
	-@erase ".\.\Release\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\circ.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\circ.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\circ.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\circ.pdb" /machine:I386 /def:".\circ.def" /out:"$(OUTDIR)\circ.ocx" /implib:"$(OUTDIR)\circ.lib" 
DEF_FILE= \
	".\circ.def"
LINK32_OBJS= \
	"$(INTDIR)\circ.obj" \
	"$(INTDIR)\circctl.obj" \
	"$(INTDIR)\circppg.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\circ.res"

"$(OUTDIR)\circ.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\circ.ocx
InputPath=.\Release\circ.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "Circ - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\circ.ocx" ".\.\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\circ.obj"
	-@erase "$(INTDIR)\circ.pch"
	-@erase "$(INTDIR)\circ.res"
	-@erase "$(INTDIR)\circ.tlb"
	-@erase "$(INTDIR)\circctl.obj"
	-@erase "$(INTDIR)\circppg.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\circ.exp"
	-@erase "$(OUTDIR)\circ.ilk"
	-@erase "$(OUTDIR)\circ.lib"
	-@erase "$(OUTDIR)\circ.ocx"
	-@erase "$(OUTDIR)\circ.pdb"
	-@erase ".\.\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\circ.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\circ.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\circ.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\circ.pdb" /debug /machine:I386 /def:".\circ.def" /out:"$(OUTDIR)\circ.ocx" /implib:"$(OUTDIR)\circ.lib" 
DEF_FILE= \
	".\circ.def"
LINK32_OBJS= \
	"$(INTDIR)\circ.obj" \
	"$(INTDIR)\circctl.obj" \
	"$(INTDIR)\circppg.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\circ.res"

"$(OUTDIR)\circ.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\circ.ocx
InputPath=.\Debug\circ.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "Circ - Win32 Unicode Debug"

OUTDIR=.\UniDebug
INTDIR=.\UniDebug
# Begin Custom Macros
OutDir=.\.\UniDebug
# End Custom Macros

ALL : "$(OUTDIR)\circ.ocx" ".\.\UniDebug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\circ.obj"
	-@erase "$(INTDIR)\circ.pch"
	-@erase "$(INTDIR)\circ.res"
	-@erase "$(INTDIR)\circ.tlb"
	-@erase "$(INTDIR)\circctl.obj"
	-@erase "$(INTDIR)\circppg.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\circ.exp"
	-@erase "$(OUTDIR)\circ.ilk"
	-@erase "$(OUTDIR)\circ.lib"
	-@erase "$(OUTDIR)\circ.ocx"
	-@erase "$(OUTDIR)\circ.pdb"
	-@erase ".\.\UniDebug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\circ.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\circ.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\circ.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\circ.pdb" /debug /machine:I386 /def:".\circ.def" /out:"$(OUTDIR)\circ.ocx" /implib:"$(OUTDIR)\circ.lib" 
DEF_FILE= \
	".\circ.def"
LINK32_OBJS= \
	"$(INTDIR)\circ.obj" \
	"$(INTDIR)\circctl.obj" \
	"$(INTDIR)\circppg.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\circ.res"

"$(OUTDIR)\circ.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\UniDebug
TargetPath=.\UniDebug\circ.ocx
InputPath=.\UniDebug\circ.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "Circ - Win32 Unicode Release"

OUTDIR=.\UniRelease
INTDIR=.\UniRelease
# Begin Custom Macros
OutDir=.\.\UniRelease
# End Custom Macros

ALL : "$(OUTDIR)\circ.ocx" ".\.\UniRelease\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\circ.obj"
	-@erase "$(INTDIR)\circ.pch"
	-@erase "$(INTDIR)\circ.res"
	-@erase "$(INTDIR)\circ.tlb"
	-@erase "$(INTDIR)\circctl.obj"
	-@erase "$(INTDIR)\circppg.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\circ.exp"
	-@erase "$(OUTDIR)\circ.lib"
	-@erase "$(OUTDIR)\circ.ocx"
	-@erase ".\.\UniRelease\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\circ.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\circ.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\circ.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\circ.pdb" /machine:I386 /def:".\circ.def" /out:"$(OUTDIR)\circ.ocx" /implib:"$(OUTDIR)\circ.lib" 
DEF_FILE= \
	".\circ.def"
LINK32_OBJS= \
	"$(INTDIR)\circ.obj" \
	"$(INTDIR)\circctl.obj" \
	"$(INTDIR)\circppg.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\circ.res"

"$(OUTDIR)\circ.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\UniRelease
TargetPath=.\UniRelease\circ.ocx
InputPath=.\UniRelease\circ.ocx
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
!IF EXISTS("circ.dep")
!INCLUDE "circ.dep"
!ELSE 
!MESSAGE Warning: cannot find "circ.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Circ - Win32 Release" || "$(CFG)" == "Circ - Win32 Debug" || "$(CFG)" == "Circ - Win32 Unicode Debug" || "$(CFG)" == "Circ - Win32 Unicode Release"
SOURCE=.\circ.cpp

"$(INTDIR)\circ.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\circ.pch"


SOURCE=.\circ.odl

!IF  "$(CFG)" == "Circ - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\circ.tlb" /mktyplib203 /win32 

"$(OUTDIR)\circ.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Circ - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\circ.tlb" /mktyplib203 /win32 

"$(OUTDIR)\circ.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Circ - Win32 Unicode Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\circ.tlb" /mktyplib203 /win32 

"$(OUTDIR)\circ.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Circ - Win32 Unicode Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\circ.tlb" /mktyplib203 /win32 

"$(OUTDIR)\circ.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\circ.rc

!IF  "$(CFG)" == "Circ - Win32 Release"


"$(INTDIR)\circ.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\circ.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\circ.res" /i ".\Release" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "Circ - Win32 Debug"


"$(INTDIR)\circ.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\circ.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\circ.res" /i ".\Debug" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "Circ - Win32 Unicode Debug"


"$(INTDIR)\circ.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\circ.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\circ.res" /i ".\UniDebug" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "Circ - Win32 Unicode Release"


"$(INTDIR)\circ.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\circ.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\circ.res" /i ".\UniRelease" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ENDIF 

SOURCE=.\circctl.cpp

"$(INTDIR)\circctl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\circ.pch"


SOURCE=.\circppg.cpp

"$(INTDIR)\circppg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\circ.pch"


SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "Circ - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\circ.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\circ.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Circ - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\circ.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\circ.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Circ - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\circ.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\circ.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Circ - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\circ.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\circ.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

