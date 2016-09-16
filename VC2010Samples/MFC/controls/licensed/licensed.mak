# Microsoft Developer Studio Generated NMAKE File, Based on licensed.dsp
!IF "$(CFG)" == ""
CFG=Licensed - Win32 Release
!MESSAGE No configuration specified. Defaulting to Licensed - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Licensed - Win32 Release" && "$(CFG)" != "Licensed - Win32 Debug" && "$(CFG)" != "Licensed - Win32 Unicode Debug" && "$(CFG)" != "Licensed - Win32 Unicode Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "licensed.mak" CFG="Licensed - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Licensed - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Licensed - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Licensed - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Licensed - Win32 Unicode Release" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "Licensed - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\licensed.ocx" ".\.\Release\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\licenctl.obj"
	-@erase "$(INTDIR)\licenppg.obj"
	-@erase "$(INTDIR)\licensed.obj"
	-@erase "$(INTDIR)\licensed.pch"
	-@erase "$(INTDIR)\licensed.res"
	-@erase "$(INTDIR)\licensed.tlb"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\licensed.exp"
	-@erase "$(OUTDIR)\licensed.lib"
	-@erase "$(OUTDIR)\licensed.ocx"
	-@erase ".\.\Release\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\licensed.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\licensed.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\licensed.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\licensed.pdb" /machine:I386 /def:".\licensed.def" /out:"$(OUTDIR)\licensed.ocx" /implib:"$(OUTDIR)\licensed.lib" 
DEF_FILE= \
	".\licensed.def"
LINK32_OBJS= \
	"$(INTDIR)\licenctl.obj" \
	"$(INTDIR)\licenppg.obj" \
	"$(INTDIR)\licensed.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\licensed.res"

"$(OUTDIR)\licensed.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\licensed.ocx
InputPath=.\Release\licensed.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "Licensed - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\licensed.ocx" ".\.\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\licenctl.obj"
	-@erase "$(INTDIR)\licenppg.obj"
	-@erase "$(INTDIR)\licensed.obj"
	-@erase "$(INTDIR)\licensed.pch"
	-@erase "$(INTDIR)\licensed.res"
	-@erase "$(INTDIR)\licensed.tlb"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\licensed.exp"
	-@erase "$(OUTDIR)\licensed.ilk"
	-@erase "$(OUTDIR)\licensed.lib"
	-@erase "$(OUTDIR)\licensed.ocx"
	-@erase "$(OUTDIR)\licensed.pdb"
	-@erase ".\.\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\licensed.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\licensed.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\licensed.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\licensed.pdb" /debug /machine:I386 /def:".\licensed.def" /out:"$(OUTDIR)\licensed.ocx" /implib:"$(OUTDIR)\licensed.lib" 
DEF_FILE= \
	".\licensed.def"
LINK32_OBJS= \
	"$(INTDIR)\licenctl.obj" \
	"$(INTDIR)\licenppg.obj" \
	"$(INTDIR)\licensed.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\licensed.res"

"$(OUTDIR)\licensed.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\licensed.ocx
InputPath=.\Debug\licensed.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "Licensed - Win32 Unicode Debug"

OUTDIR=.\UniDebug
INTDIR=.\UniDebug
# Begin Custom Macros
OutDir=.\.\UniDebug
# End Custom Macros

ALL : "$(OUTDIR)\licensed.ocx" ".\.\UniDebug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\licenctl.obj"
	-@erase "$(INTDIR)\licenppg.obj"
	-@erase "$(INTDIR)\licensed.obj"
	-@erase "$(INTDIR)\licensed.pch"
	-@erase "$(INTDIR)\licensed.res"
	-@erase "$(INTDIR)\licensed.tlb"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\licensed.exp"
	-@erase "$(OUTDIR)\licensed.ilk"
	-@erase "$(OUTDIR)\licensed.lib"
	-@erase "$(OUTDIR)\licensed.ocx"
	-@erase "$(OUTDIR)\licensed.pdb"
	-@erase ".\.\UniDebug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\licensed.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\licensed.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\licensed.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\licensed.pdb" /debug /machine:I386 /def:".\licensed.def" /out:"$(OUTDIR)\licensed.ocx" /implib:"$(OUTDIR)\licensed.lib" 
DEF_FILE= \
	".\licensed.def"
LINK32_OBJS= \
	"$(INTDIR)\licenctl.obj" \
	"$(INTDIR)\licenppg.obj" \
	"$(INTDIR)\licensed.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\licensed.res"

"$(OUTDIR)\licensed.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\UniDebug
TargetPath=.\UniDebug\licensed.ocx
InputPath=.\UniDebug\licensed.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "Licensed - Win32 Unicode Release"

OUTDIR=.\UniRelease
INTDIR=.\UniRelease
# Begin Custom Macros
OutDir=.\.\UniRelease
# End Custom Macros

ALL : "$(OUTDIR)\licensed.ocx" ".\.\UniRelease\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\licenctl.obj"
	-@erase "$(INTDIR)\licenppg.obj"
	-@erase "$(INTDIR)\licensed.obj"
	-@erase "$(INTDIR)\licensed.pch"
	-@erase "$(INTDIR)\licensed.res"
	-@erase "$(INTDIR)\licensed.tlb"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\licensed.exp"
	-@erase "$(OUTDIR)\licensed.lib"
	-@erase "$(OUTDIR)\licensed.ocx"
	-@erase ".\.\UniRelease\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\licensed.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\licensed.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\licensed.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\licensed.pdb" /machine:I386 /def:".\licensed.def" /out:"$(OUTDIR)\licensed.ocx" /implib:"$(OUTDIR)\licensed.lib" 
DEF_FILE= \
	".\licensed.def"
LINK32_OBJS= \
	"$(INTDIR)\licenctl.obj" \
	"$(INTDIR)\licenppg.obj" \
	"$(INTDIR)\licensed.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\licensed.res"

"$(OUTDIR)\licensed.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\UniRelease
TargetPath=.\UniRelease\licensed.ocx
InputPath=.\UniRelease\licensed.ocx
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
!IF EXISTS("licensed.dep")
!INCLUDE "licensed.dep"
!ELSE 
!MESSAGE Warning: cannot find "licensed.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Licensed - Win32 Release" || "$(CFG)" == "Licensed - Win32 Debug" || "$(CFG)" == "Licensed - Win32 Unicode Debug" || "$(CFG)" == "Licensed - Win32 Unicode Release"
SOURCE=.\licenctl.cpp

"$(INTDIR)\licenctl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\licensed.pch"


SOURCE=.\licenppg.cpp

"$(INTDIR)\licenppg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\licensed.pch"


SOURCE=.\licensed.cpp

"$(INTDIR)\licensed.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\licensed.pch"


SOURCE=.\licensed.odl

!IF  "$(CFG)" == "Licensed - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\licensed.tlb" /mktyplib203 /win32 

"$(OUTDIR)\licensed.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Licensed - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\licensed.tlb" /mktyplib203 /win32 

"$(OUTDIR)\licensed.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Licensed - Win32 Unicode Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\licensed.tlb" /mktyplib203 /win32 

"$(OUTDIR)\licensed.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Licensed - Win32 Unicode Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\licensed.tlb" /mktyplib203 /win32 

"$(OUTDIR)\licensed.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\licensed.rc

!IF  "$(CFG)" == "Licensed - Win32 Release"


"$(INTDIR)\licensed.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\licensed.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\licensed.res" /i ".\Release" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "Licensed - Win32 Debug"


"$(INTDIR)\licensed.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\licensed.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\licensed.res" /i ".\Debug" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "Licensed - Win32 Unicode Debug"


"$(INTDIR)\licensed.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\licensed.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\licensed.res" /i ".\UniDebug" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "Licensed - Win32 Unicode Release"


"$(INTDIR)\licensed.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\licensed.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\licensed.res" /i ".\UniRelease" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ENDIF 

SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "Licensed - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\licensed.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\licensed.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Licensed - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\licensed.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\licensed.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Licensed - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\licensed.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\licensed.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Licensed - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\licensed.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\licensed.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

