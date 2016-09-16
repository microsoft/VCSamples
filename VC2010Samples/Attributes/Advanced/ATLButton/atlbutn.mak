# Microsoft Developer Studio Generated NMAKE File, Based on atlbutn.dsp
!IF "$(CFG)" == ""
CFG=atlbutn - Win32 MinSize
!MESSAGE No configuration specified. Defaulting to atlbutn - Win32 MinSize.
!ENDIF 

!IF "$(CFG)" != "atlbutn - Win32 MinSize" && "$(CFG)" != "atlbutn - Win32 Debug" && "$(CFG)" != "atlbutn - Win32 Unicode MinSize" && "$(CFG)" != "atlbutn - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "atlbutn.mak" CFG="atlbutn - Win32 MinSize"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "atlbutn - Win32 MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "atlbutn - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "atlbutn - Win32 Unicode MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "atlbutn - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "atlbutn - Win32 MinSize"

OUTDIR=.\MinSize
INTDIR=.\MinSize
# Begin Custom Macros
OutDir=.\MinSize
# End Custom Macros

ALL : "$(OUTDIR)\atlbutn.dll" "$(OUTDIR)\atlbutn.bsc" ".\MinSize\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\atlbutn.obj"
	-@erase "$(INTDIR)\atlbutn.pch"
	-@erase "$(INTDIR)\atlbutn.res"
	-@erase "$(INTDIR)\atlbutn.sbr"
	-@erase "$(INTDIR)\AtlButton.obj"
	-@erase "$(INTDIR)\AtlButton.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\atlbutn.bsc"
	-@erase "$(OUTDIR)\atlbutn.dll"
	-@erase "$(OUTDIR)\atlbutn.exp"
	-@erase "$(OUTDIR)\atlbutn.lib"
	-@erase ".\MinSize\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /O1 /D "NDEBUG" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_ATL_ATTRIBUTES" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\atlbutn.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\atlbutn.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\atlbutn.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\atlbutn.sbr" \
	"$(INTDIR)\AtlButton.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\atlbutn.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\atlbutn.pdb" /machine:I386 /out:"$(OUTDIR)\atlbutn.dll" /implib:"$(OUTDIR)\atlbutn.lib" /idlout:_atlbutn.idl 
LINK32_OBJS= \
	"$(INTDIR)\atlbutn.obj" \
	"$(INTDIR)\AtlButton.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\atlbutn.res"

"$(OUTDIR)\atlbutn.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\MinSize
TargetPath=.\MinSize\atlbutn.dll
InputPath=.\MinSize\atlbutn.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "atlbutn - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\atlbutn.dll" "$(OUTDIR)\atlbutn.bsc" ".\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\atlbutn.obj"
	-@erase "$(INTDIR)\atlbutn.pch"
	-@erase "$(INTDIR)\atlbutn.res"
	-@erase "$(INTDIR)\atlbutn.sbr"
	-@erase "$(INTDIR)\AtlButton.obj"
	-@erase "$(INTDIR)\AtlButton.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\atlbutn.bsc"
	-@erase "$(OUTDIR)\atlbutn.dll"
	-@erase "$(OUTDIR)\atlbutn.exp"
	-@erase "$(OUTDIR)\atlbutn.ilk"
	-@erase "$(OUTDIR)\atlbutn.lib"
	-@erase "$(OUTDIR)\atlbutn.pdb"
	-@erase ".\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /ZI /Od /D "_DEBUG" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_ATL_ATTRIBUTES" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\atlbutn.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\atlbutn.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\atlbutn.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\atlbutn.sbr" \
	"$(INTDIR)\AtlButton.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\atlbutn.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\atlbutn.pdb" /debug /debugtype:both /machine:I386 /out:"$(OUTDIR)\atlbutn.dll" /implib:"$(OUTDIR)\atlbutn.lib" /idlout:_atlbutn.idl 
LINK32_OBJS= \
	"$(INTDIR)\atlbutn.obj" \
	"$(INTDIR)\AtlButton.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\atlbutn.res"

"$(OUTDIR)\atlbutn.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Debug
TargetPath=.\Debug\atlbutn.dll
InputPath=.\Debug\atlbutn.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "atlbutn - Win32 Unicode MinSize"

OUTDIR=.\MinSizeU
INTDIR=.\MinSizeU
# Begin Custom Macros
OutDir=.\MinSizeU
# End Custom Macros

ALL : "$(OUTDIR)\atlbutn.dll" ".\MinSizeU\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\atlbutn.obj"
	-@erase "$(INTDIR)\atlbutn.pch"
	-@erase "$(INTDIR)\atlbutn.res"
	-@erase "$(INTDIR)\AtlButton.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\atlbutn.dll"
	-@erase "$(OUTDIR)\atlbutn.exp"
	-@erase "$(OUTDIR)\atlbutn.lib"
	-@erase ".\MinSizeU\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /O1 /D "NDEBUG" /D "_UNICODE" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_ATL_ATTRIBUTES" /Fp"$(INTDIR)\atlbutn.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\atlbutn.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\atlbutn.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\atlbutn.pdb" /machine:I386 /out:"$(OUTDIR)\atlbutn.dll" /implib:"$(OUTDIR)\atlbutn.lib" /idlout:_atlbutn.idl 
LINK32_OBJS= \
	"$(INTDIR)\atlbutn.obj" \
	"$(INTDIR)\AtlButton.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\atlbutn.res"

"$(OUTDIR)\atlbutn.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\MinSizeU
TargetPath=.\MinSizeU\atlbutn.dll
InputPath=.\MinSizeU\atlbutn.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "atlbutn - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\DebugU
# End Custom Macros

ALL : "$(OUTDIR)\atlbutn.dll" ".\DebugU\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\atlbutn.obj"
	-@erase "$(INTDIR)\atlbutn.pch"
	-@erase "$(INTDIR)\atlbutn.res"
	-@erase "$(INTDIR)\AtlButton.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\atlbutn.dll"
	-@erase "$(OUTDIR)\atlbutn.exp"
	-@erase "$(OUTDIR)\atlbutn.ilk"
	-@erase "$(OUTDIR)\atlbutn.lib"
	-@erase "$(OUTDIR)\atlbutn.pdb"
	-@erase ".\DebugU\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /ZI /Od /D "_DEBUG" /D "_UNICODE" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_ATL_ATTRIBUTES" /Fp"$(INTDIR)\atlbutn.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\atlbutn.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\atlbutn.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\atlbutn.pdb" /debug /machine:I386 /out:"$(OUTDIR)\atlbutn.dll" /implib:"$(OUTDIR)\atlbutn.lib" /idlout:_atlbutn.idl 
LINK32_OBJS= \
	"$(INTDIR)\atlbutn.obj" \
	"$(INTDIR)\AtlButton.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\atlbutn.res"

"$(OUTDIR)\atlbutn.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\DebugU
TargetPath=.\DebugU\atlbutn.dll
InputPath=.\DebugU\atlbutn.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("atlbutn.dep")
!INCLUDE "atlbutn.dep"
!ELSE 
!MESSAGE Warning: cannot find "atlbutn.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "atlbutn - Win32 MinSize" || "$(CFG)" == "atlbutn - Win32 Debug" || "$(CFG)" == "atlbutn - Win32 Unicode MinSize" || "$(CFG)" == "atlbutn - Win32 Unicode Debug"
SOURCE=.\atlbutn.cpp

!IF  "$(CFG)" == "atlbutn - Win32 MinSize"


"$(INTDIR)\atlbutn.obj"	"$(INTDIR)\atlbutn.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\atlbutn.pch"


!ELSEIF  "$(CFG)" == "atlbutn - Win32 Debug"


"$(INTDIR)\atlbutn.obj"	"$(INTDIR)\atlbutn.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\atlbutn.pch"


!ELSEIF  "$(CFG)" == "atlbutn - Win32 Unicode MinSize"


"$(INTDIR)\atlbutn.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\atlbutn.pch"


!ELSEIF  "$(CFG)" == "atlbutn - Win32 Unicode Debug"


"$(INTDIR)\atlbutn.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\atlbutn.pch"


!ENDIF 

SOURCE=.\atlbutn.rc

"$(INTDIR)\atlbutn.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\AtlButton.cpp

!IF  "$(CFG)" == "atlbutn - Win32 MinSize"


"$(INTDIR)\AtlButton.obj"	"$(INTDIR)\AtlButton.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\atlbutn.pch"


!ELSEIF  "$(CFG)" == "atlbutn - Win32 Debug"


"$(INTDIR)\AtlButton.obj"	"$(INTDIR)\AtlButton.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\atlbutn.pch"


!ELSEIF  "$(CFG)" == "atlbutn - Win32 Unicode MinSize"


"$(INTDIR)\AtlButton.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\atlbutn.pch"


!ELSEIF  "$(CFG)" == "atlbutn - Win32 Unicode Debug"


"$(INTDIR)\AtlButton.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\atlbutn.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "atlbutn - Win32 MinSize"

CPP_SWITCHES=/nologo /MD /W3 /O1 /D "NDEBUG" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_ATL_ATTRIBUTES" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\atlbutn.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\atlbutn.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "atlbutn - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /ZI /Od /D "_DEBUG" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_ATL_ATTRIBUTES" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\atlbutn.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\atlbutn.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "atlbutn - Win32 Unicode MinSize"

CPP_SWITCHES=/nologo /MD /W3 /O1 /D "NDEBUG" /D "_UNICODE" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_ATL_ATTRIBUTES" /Fp"$(INTDIR)\atlbutn.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\atlbutn.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "atlbutn - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /ZI /Od /D "_DEBUG" /D "_UNICODE" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_ATL_ATTRIBUTES" /Fp"$(INTDIR)\atlbutn.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\atlbutn.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

