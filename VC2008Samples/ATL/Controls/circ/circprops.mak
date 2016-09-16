# Microsoft Developer Studio Generated NMAKE File, Based on circprops.dsp
!IF "$(CFG)" == ""
CFG=circprops - Win32 Release
!MESSAGE No configuration specified. Defaulting to circprops - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "circprops - Win32 Release" && "$(CFG)" != "circprops - Win32 Debug" && "$(CFG)" != "circprops - Win32 Unicode Release" && "$(CFG)" != "circprops - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "circprops.mak" CFG="circprops - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "circprops - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "circprops - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "circprops - Win32 Unicode Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "circprops - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "circprops - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\circprops.dll" ".\.\Release\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\circprops.dll" ".\.\Release\regsvr32.trg"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\CircProps.obj"
	-@erase "$(INTDIR)\circprops.pch"
	-@erase "$(INTDIR)\circprops.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\circprops.dll"
	-@erase "$(OUTDIR)\circprops.exp"
	-@erase "$(OUTDIR)\circprops.lib"
	-@erase "$(OUTDIR)\circprops.map"
	-@erase ".\.\Release\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
CPP_PROJ=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\circprops.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\circprops.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\circprops.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=comdlg32.lib /nologo /entry:"DllMain" /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\circprops.pdb" /map:"$(INTDIR)\circprops.map" /machine:I386 /def:".\circprops.def" /out:"$(OUTDIR)\circprops.dll" /implib:"$(OUTDIR)\circprops.lib" 
DEF_FILE= \
	".\circprops.def"
LINK32_OBJS= \
	"$(INTDIR)\CircProps.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\circprops.res"

"$(OUTDIR)\circprops.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\circprops.dll
InputPath=.\Release\circprops.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "circprops - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\circprops.dll" "$(OUTDIR)\circprops.bsc" ".\.\Debug\regsvr32.trg"

!ELSE 

ALL : "circ - Win32 Debug" "$(OUTDIR)\circprops.dll" "$(OUTDIR)\circprops.bsc" ".\.\Debug\regsvr32.trg"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"circ - Win32 DebugCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\CircProps.obj"
	-@erase "$(INTDIR)\circprops.pch"
	-@erase "$(INTDIR)\circprops.res"
	-@erase "$(INTDIR)\CircProps.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\circprops.bsc"
	-@erase "$(OUTDIR)\circprops.dll"
	-@erase "$(OUTDIR)\circprops.exp"
	-@erase "$(OUTDIR)\circprops.ilk"
	-@erase "$(OUTDIR)\circprops.lib"
	-@erase "$(OUTDIR)\circprops.pdb"
	-@erase ".\.\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\circprops.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\circprops.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\circprops.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\CircProps.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\circprops.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=comdlg32.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\circprops.pdb" /debug /machine:I386 /def:".\circprops.def" /out:"$(OUTDIR)\circprops.dll" /implib:"$(OUTDIR)\circprops.lib" 
DEF_FILE= \
	".\circprops.def"
LINK32_OBJS= \
	"$(INTDIR)\CircProps.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\circprops.res" \
	"$(OUTDIR)\circ.lib"

"$(OUTDIR)\circprops.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\circprops.dll
InputPath=.\Debug\circprops.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "circprops - Win32 Unicode Release"

OUTDIR=.\ReleaseU
INTDIR=.\ReleaseU
# Begin Custom Macros
OutDir=.\.\ReleaseU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\circprops.dll" ".\.\ReleaseU\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\circprops.dll" ".\.\ReleaseU\regsvr32.trg"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\CircProps.obj"
	-@erase "$(INTDIR)\circprops.pch"
	-@erase "$(INTDIR)\circprops.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\circprops.dll"
	-@erase "$(OUTDIR)\circprops.exp"
	-@erase "$(OUTDIR)\circprops.lib"
	-@erase ".\.\ReleaseU\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
CPP_PROJ=/nologo /MT /W3 /O1 /D "_UNICODE" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\circprops.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\circprops.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\circprops.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=comdlg32.lib /nologo /entry:"DllMain" /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\circprops.pdb" /machine:I386 /def:".\circprops.def" /out:"$(OUTDIR)\circprops.dll" /implib:"$(OUTDIR)\circprops.lib" 
DEF_FILE= \
	".\circprops.def"
LINK32_OBJS= \
	"$(INTDIR)\CircProps.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\circprops.res"

"$(OUTDIR)\circprops.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\ReleaseU
TargetPath=.\ReleaseU\circprops.dll
InputPath=.\ReleaseU\circprops.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "circprops - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\.\DebugU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\circprops.dll" ".\.\DebugU\regsvr32.trg"

!ELSE 

ALL : "circ - Win32 Unicode Debug" "$(OUTDIR)\circprops.dll" ".\.\DebugU\regsvr32.trg"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"circ - Win32 Unicode DebugCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\CircProps.obj"
	-@erase "$(INTDIR)\circprops.pch"
	-@erase "$(INTDIR)\circprops.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\circprops.dll"
	-@erase "$(OUTDIR)\circprops.exp"
	-@erase "$(OUTDIR)\circprops.ilk"
	-@erase "$(OUTDIR)\circprops.lib"
	-@erase "$(OUTDIR)\circprops.pdb"
	-@erase ".\.\DebugU\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "_UNICODE" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "NO_DISPATCH_TRACE" /Fp"$(INTDIR)\circprops.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\circprops.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\circprops.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=comdlg32.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\circprops.pdb" /debug /machine:I386 /def:".\circprops.def" /out:"$(OUTDIR)\circprops.dll" /implib:"$(OUTDIR)\circprops.lib" 
DEF_FILE= \
	".\circprops.def"
LINK32_OBJS= \
	"$(INTDIR)\CircProps.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\circprops.res" \
	"$(OUTDIR)\circ.lib"

"$(OUTDIR)\circprops.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\DebugU
TargetPath=.\DebugU\circprops.dll
InputPath=.\DebugU\circprops.dll
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
!IF EXISTS("circprops.dep")
!INCLUDE "circprops.dep"
!ELSE 
!MESSAGE Warning: cannot find "circprops.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "circprops - Win32 Release" || "$(CFG)" == "circprops - Win32 Debug" || "$(CFG)" == "circprops - Win32 Unicode Release" || "$(CFG)" == "circprops - Win32 Unicode Debug"
SOURCE=.\CircProps.cpp

!IF  "$(CFG)" == "circprops - Win32 Release"


"$(INTDIR)\CircProps.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\circprops.pch"


!ELSEIF  "$(CFG)" == "circprops - Win32 Debug"


"$(INTDIR)\CircProps.obj"	"$(INTDIR)\CircProps.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\circprops.pch"


!ELSEIF  "$(CFG)" == "circprops - Win32 Unicode Release"


"$(INTDIR)\CircProps.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\circprops.pch"


!ELSEIF  "$(CFG)" == "circprops - Win32 Unicode Debug"


"$(INTDIR)\CircProps.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\circprops.pch"


!ENDIF 

SOURCE=.\circprops.rc

"$(INTDIR)\circprops.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "circprops - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\circprops.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\circprops.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "circprops - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\circprops.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\circprops.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "circprops - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MT /W3 /O1 /D "_UNICODE" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\circprops.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\circprops.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "circprops - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "_UNICODE" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "NO_DISPATCH_TRACE" /Fp"$(INTDIR)\circprops.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\circprops.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

!IF  "$(CFG)" == "circprops - Win32 Release"

!ELSEIF  "$(CFG)" == "circprops - Win32 Debug"

"circ - Win32 Debug" : 
   cd "."
   $(MAKE) /$(MAKEFLAGS) /F .\circ.mak CFG="circ - Win32 Debug" 
   cd "."

"circ - Win32 DebugCLEAN" : 
   cd "."
   $(MAKE) /$(MAKEFLAGS) /F .\circ.mak CFG="circ - Win32 Debug" RECURSE=1 CLEAN 
   cd "."

!ELSEIF  "$(CFG)" == "circprops - Win32 Unicode Release"

!ELSEIF  "$(CFG)" == "circprops - Win32 Unicode Debug"

"circ - Win32 Unicode Debug" : 
   cd "."
   $(MAKE) /$(MAKEFLAGS) /F .\circ.mak CFG="circ - Win32 Unicode Debug" 
   cd "."

"circ - Win32 Unicode DebugCLEAN" : 
   cd "."
   $(MAKE) /$(MAKEFLAGS) /F .\circ.mak CFG="circ - Win32 Unicode Debug" RECURSE=1 CLEAN 
   cd "."

!ENDIF 

SOURCE=.\circ_i.c

!ENDIF 

