# Microsoft Developer Studio Generated NMAKE File, Based on connect.dsp
!IF "$(CFG)" == ""
CFG=Connect - Win32 Release
!MESSAGE No configuration specified. Defaulting to Connect - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Connect - Win32 Release" && "$(CFG)" != "Connect - Win32 Debug" && "$(CFG)" != "Connect - Win32 Unicode Release" && "$(CFG)" != "Connect - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "connect.mak" CFG="Connect - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Connect - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Connect - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Connect - Win32 Unicode Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Connect - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "Connect - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\connect.dll" ".\.\Release\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\Connect.obj"
	-@erase "$(INTDIR)\connect.pch"
	-@erase "$(INTDIR)\Connect.res"
	-@erase "$(INTDIR)\preconn.obj"
	-@erase "$(INTDIR)\Random.obj"
	-@erase "$(OUTDIR)\connect.dll"
	-@erase "$(OUTDIR)\connect.exp"
	-@erase "$(OUTDIR)\connect.lib"
	-@erase ".\Connect.h"
	-@erase ".\Connect.tlb"
	-@erase ".\Connect_i.c"
	-@erase ".\.\Release\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\connect.pch" /Yu"preconn.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Connect.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\connect.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\connect.pdb" /machine:I386 /def:".\Connect.def" /out:"$(OUTDIR)\connect.dll" /implib:"$(OUTDIR)\connect.lib" 
DEF_FILE= \
	".\Connect.def"
LINK32_OBJS= \
	"$(INTDIR)\Connect.obj" \
	"$(INTDIR)\Random.obj" \
	"$(INTDIR)\preconn.obj" \
	"$(INTDIR)\Connect.res"

"$(OUTDIR)\connect.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\connect.dll
InputPath=.\Release\connect.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
<< 
	

!ELSEIF  "$(CFG)" == "Connect - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\connect.dll" ".\.\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\Connect.obj"
	-@erase "$(INTDIR)\connect.pch"
	-@erase "$(INTDIR)\Connect.res"
	-@erase "$(INTDIR)\preconn.obj"
	-@erase "$(INTDIR)\Random.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\connect.dll"
	-@erase "$(OUTDIR)\connect.exp"
	-@erase "$(OUTDIR)\connect.ilk"
	-@erase "$(OUTDIR)\connect.lib"
	-@erase "$(OUTDIR)\connect.pdb"
	-@erase ".\Connect.h"
	-@erase ".\Connect.tlb"
	-@erase ".\Connect_i.c"
	-@erase ".\.\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\connect.pch" /Yu"preconn.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Connect.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\connect.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\connect.pdb" /debug /machine:I386 /def:".\Connect.def" /out:"$(OUTDIR)\connect.dll" /implib:"$(OUTDIR)\connect.lib" 
DEF_FILE= \
	".\Connect.def"
LINK32_OBJS= \
	"$(INTDIR)\Connect.obj" \
	"$(INTDIR)\Random.obj" \
	"$(INTDIR)\preconn.obj" \
	"$(INTDIR)\Connect.res"

"$(OUTDIR)\connect.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\connect.dll
InputPath=.\Debug\connect.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
<< 
	

!ELSEIF  "$(CFG)" == "Connect - Win32 Unicode Release"

OUTDIR=.\ReleaseU
INTDIR=.\ReleaseU
# Begin Custom Macros
OutDir=.\.\ReleaseU
# End Custom Macros

ALL : "$(OUTDIR)\connect.dll" ".\.\ReleaseU\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\Connect.obj"
	-@erase "$(INTDIR)\connect.pch"
	-@erase "$(INTDIR)\Connect.res"
	-@erase "$(INTDIR)\preconn.obj"
	-@erase "$(INTDIR)\Random.obj"
	-@erase "$(OUTDIR)\connect.dll"
	-@erase "$(OUTDIR)\connect.exp"
	-@erase "$(OUTDIR)\connect.lib"
	-@erase ".\Connect.h"
	-@erase ".\Connect.tlb"
	-@erase ".\Connect_i.c"
	-@erase ".\.\ReleaseU\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\connect.pch" /Yu"preconn.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Connect.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\connect.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\connect.pdb" /machine:I386 /def:".\Connect.def" /out:"$(OUTDIR)\connect.dll" /implib:"$(OUTDIR)\connect.lib" 
DEF_FILE= \
	".\Connect.def"
LINK32_OBJS= \
	"$(INTDIR)\Connect.obj" \
	"$(INTDIR)\Random.obj" \
	"$(INTDIR)\preconn.obj" \
	"$(INTDIR)\Connect.res"

"$(OUTDIR)\connect.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\ReleaseU
TargetPath=.\ReleaseU\connect.dll
InputPath=.\ReleaseU\connect.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg"
<< 
	

!ELSEIF  "$(CFG)" == "Connect - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\.\DebugU
# End Custom Macros

ALL : "$(OUTDIR)\connect.dll" ".\.\DebugU\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\Connect.obj"
	-@erase "$(INTDIR)\connect.pch"
	-@erase "$(INTDIR)\Connect.res"
	-@erase "$(INTDIR)\preconn.obj"
	-@erase "$(INTDIR)\Random.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\connect.dll"
	-@erase "$(OUTDIR)\connect.exp"
	-@erase "$(OUTDIR)\connect.ilk"
	-@erase "$(OUTDIR)\connect.lib"
	-@erase "$(OUTDIR)\connect.pdb"
	-@erase ".\Connect.h"
	-@erase ".\Connect.tlb"
	-@erase ".\Connect_i.c"
	-@erase ".\.\DebugU\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\connect.pch" /Yu"preconn.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Connect.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\connect.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\connect.pdb" /debug /machine:I386 /def:".\Connect.def" /out:"$(OUTDIR)\connect.dll" /implib:"$(OUTDIR)\connect.lib" 
DEF_FILE= \
	".\Connect.def"
LINK32_OBJS= \
	"$(INTDIR)\Connect.obj" \
	"$(INTDIR)\Random.obj" \
	"$(INTDIR)\preconn.obj" \
	"$(INTDIR)\Connect.res"

"$(OUTDIR)\connect.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\DebugU
TargetPath=.\DebugU\connect.dll
InputPath=.\DebugU\connect.dll
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
!IF EXISTS("connect.dep")
!INCLUDE "connect.dep"
!ELSE 
!MESSAGE Warning: cannot find "connect.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Connect - Win32 Release" || "$(CFG)" == "Connect - Win32 Debug" || "$(CFG)" == "Connect - Win32 Unicode Release" || "$(CFG)" == "Connect - Win32 Unicode Debug"
SOURCE=.\Connect.cpp

"$(INTDIR)\Connect.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\connect.pch" ".\Connect.h" ".\Connect_i.c"


SOURCE=.\Connect.idl

!IF  "$(CFG)" == "Connect - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb ".\Connect.tlb" /h "Connect.h" /iid "Connect_i.c" /win32 

".\Connect.tlb"	".\Connect.h"	".\Connect_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Connect - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb ".\Connect.tlb" /h "Connect.h" /iid "Connect_i.c" /win32 

".\Connect.tlb"	".\Connect.h"	".\Connect_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Connect - Win32 Unicode Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb ".\Connect.tlb" /h "Connect.h" /iid "Connect_i.c" /win32 

".\Connect.tlb"	".\Connect.h"	".\Connect_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Connect - Win32 Unicode Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb ".\Connect.tlb" /h "Connect.h" /iid "Connect_i.c" /win32 

".\Connect.tlb"	".\Connect.h"	".\Connect_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Connect.rc

"$(INTDIR)\Connect.res" : $(SOURCE) "$(INTDIR)" ".\Connect.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\preconn.cpp

!IF  "$(CFG)" == "Connect - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\connect.pch" /Yc"preconn.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\preconn.obj"	"$(INTDIR)\connect.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Connect - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\connect.pch" /Yc"preconn.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\preconn.obj"	"$(INTDIR)\connect.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Connect - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\connect.pch" /Yc"preconn.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\preconn.obj"	"$(INTDIR)\connect.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Connect - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\connect.pch" /Yc"preconn.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\preconn.obj"	"$(INTDIR)\connect.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Random.cpp

"$(INTDIR)\Random.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\connect.pch" ".\Connect.h"



!ENDIF 

