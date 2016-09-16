# Microsoft Developer Studio Generated NMAKE File, Based on time.dsp
!IF "$(CFG)" == ""
CFG=Time - Win32 Release
!MESSAGE No configuration specified. Defaulting to Time - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Time - Win32 Release" && "$(CFG)" != "Time - Win32 Debug" && "$(CFG)" != "Time - Win32 Unicode Debug" && "$(CFG)" != "Time - Win32 Unicode Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "time.mak" CFG="Time - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Time - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Time - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Time - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Time - Win32 Unicode Release" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "Time - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\time.ocx" ".\.\Release\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\time.obj"
	-@erase "$(INTDIR)\time.pch"
	-@erase "$(INTDIR)\time.res"
	-@erase "$(INTDIR)\time.tlb"
	-@erase "$(INTDIR)\timectl.obj"
	-@erase "$(INTDIR)\timeppg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\time.exp"
	-@erase "$(OUTDIR)\time.lib"
	-@erase "$(OUTDIR)\time.ocx"
	-@erase ".\.\Release\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\time.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\time.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\time.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\time.pdb" /machine:I386 /def:".\time.def" /out:"$(OUTDIR)\time.ocx" /implib:"$(OUTDIR)\time.lib" 
DEF_FILE= \
	".\time.def"
LINK32_OBJS= \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\time.obj" \
	"$(INTDIR)\timectl.obj" \
	"$(INTDIR)\timeppg.obj" \
	"$(INTDIR)\time.res"

"$(OUTDIR)\time.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\time.ocx
InputPath=.\Release\time.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "Time - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\time.ocx" ".\.\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\time.obj"
	-@erase "$(INTDIR)\time.pch"
	-@erase "$(INTDIR)\time.res"
	-@erase "$(INTDIR)\time.tlb"
	-@erase "$(INTDIR)\timectl.obj"
	-@erase "$(INTDIR)\timeppg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\time.exp"
	-@erase "$(OUTDIR)\time.ilk"
	-@erase "$(OUTDIR)\time.lib"
	-@erase "$(OUTDIR)\time.ocx"
	-@erase "$(OUTDIR)\time.pdb"
	-@erase ".\.\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\time.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\time.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\time.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\time.pdb" /debug /machine:I386 /def:".\time.def" /out:"$(OUTDIR)\time.ocx" /implib:"$(OUTDIR)\time.lib" 
DEF_FILE= \
	".\time.def"
LINK32_OBJS= \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\time.obj" \
	"$(INTDIR)\timectl.obj" \
	"$(INTDIR)\timeppg.obj" \
	"$(INTDIR)\time.res"

"$(OUTDIR)\time.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\time.ocx
InputPath=.\Debug\time.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "Time - Win32 Unicode Debug"

OUTDIR=.\UniDebug
INTDIR=.\UniDebug
# Begin Custom Macros
OutDir=.\.\UniDebug
# End Custom Macros

ALL : "$(OUTDIR)\time.ocx" ".\.\UniDebug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\time.obj"
	-@erase "$(INTDIR)\time.pch"
	-@erase "$(INTDIR)\time.res"
	-@erase "$(INTDIR)\time.tlb"
	-@erase "$(INTDIR)\timectl.obj"
	-@erase "$(INTDIR)\timeppg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\time.exp"
	-@erase "$(OUTDIR)\time.ilk"
	-@erase "$(OUTDIR)\time.lib"
	-@erase "$(OUTDIR)\time.ocx"
	-@erase "$(OUTDIR)\time.pdb"
	-@erase ".\.\UniDebug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\time.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\time.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\time.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\time.pdb" /debug /machine:I386 /def:".\time.def" /out:"$(OUTDIR)\time.ocx" /implib:"$(OUTDIR)\time.lib" 
DEF_FILE= \
	".\time.def"
LINK32_OBJS= \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\time.obj" \
	"$(INTDIR)\timectl.obj" \
	"$(INTDIR)\timeppg.obj" \
	"$(INTDIR)\time.res"

"$(OUTDIR)\time.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\UniDebug
TargetPath=.\UniDebug\time.ocx
InputPath=.\UniDebug\time.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "Time - Win32 Unicode Release"

OUTDIR=.\UniRelease
INTDIR=.\UniRelease
# Begin Custom Macros
OutDir=.\.\UniRelease
# End Custom Macros

ALL : "$(OUTDIR)\time.ocx" ".\.\UniRelease\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\time.obj"
	-@erase "$(INTDIR)\time.pch"
	-@erase "$(INTDIR)\time.res"
	-@erase "$(INTDIR)\time.tlb"
	-@erase "$(INTDIR)\timectl.obj"
	-@erase "$(INTDIR)\timeppg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\time.exp"
	-@erase "$(OUTDIR)\time.lib"
	-@erase "$(OUTDIR)\time.ocx"
	-@erase ".\.\UniRelease\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\time.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\time.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\time.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\time.pdb" /machine:I386 /def:".\time.def" /out:"$(OUTDIR)\time.ocx" /implib:"$(OUTDIR)\time.lib" 
DEF_FILE= \
	".\time.def"
LINK32_OBJS= \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\time.obj" \
	"$(INTDIR)\timectl.obj" \
	"$(INTDIR)\timeppg.obj" \
	"$(INTDIR)\time.res"

"$(OUTDIR)\time.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\UniRelease
TargetPath=.\UniRelease\time.ocx
InputPath=.\UniRelease\time.ocx
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
!IF EXISTS("time.dep")
!INCLUDE "time.dep"
!ELSE 
!MESSAGE Warning: cannot find "time.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Time - Win32 Release" || "$(CFG)" == "Time - Win32 Debug" || "$(CFG)" == "Time - Win32 Unicode Debug" || "$(CFG)" == "Time - Win32 Unicode Release"
SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "Time - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\time.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\time.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Time - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\time.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\time.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Time - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\time.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\time.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Time - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\time.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\time.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\time.cpp

"$(INTDIR)\time.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\time.pch"


SOURCE=.\time.odl

!IF  "$(CFG)" == "Time - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\time.tlb" /mktyplib203 /win32 

"$(OUTDIR)\time.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Time - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\time.tlb" /mktyplib203 /win32 

"$(OUTDIR)\time.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Time - Win32 Unicode Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\time.tlb" /mktyplib203 /win32 

"$(OUTDIR)\time.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Time - Win32 Unicode Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\time.tlb" /mktyplib203 /win32 

"$(OUTDIR)\time.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\time.rc

!IF  "$(CFG)" == "Time - Win32 Release"


"$(INTDIR)\time.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\time.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\time.res" /i ".\Release" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "Time - Win32 Debug"


"$(INTDIR)\time.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\time.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\time.res" /i ".\Debug" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "Time - Win32 Unicode Debug"


"$(INTDIR)\time.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\time.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\time.res" /i ".\UniDebug" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "Time - Win32 Unicode Release"


"$(INTDIR)\time.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\time.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\time.res" /i ".\UniRelease" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ENDIF 

SOURCE=.\timectl.cpp

"$(INTDIR)\timectl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\time.pch"


SOURCE=.\timeppg.cpp

"$(INTDIR)\timeppg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\time.pch"



!ENDIF 

