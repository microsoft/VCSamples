# Microsoft Developer Studio Generated NMAKE File, Based on AtlAgent.dsp
!IF "$(CFG)" == ""
CFG=AtlAgent - Win32 Debug
!MESSAGE No configuration specified. Defaulting to AtlAgent - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "AtlAgent - Win32 Debug" && "$(CFG)" != "AtlAgent - Win32 Unicode Debug" && "$(CFG)" != "AtlAgent - Win32 Release MinSize" && "$(CFG)" != "AtlAgent - Win32 Release MinDependency" && "$(CFG)" != "AtlAgent - Win32 Unicode Release MinSize" && "$(CFG)" != "AtlAgent - Win32 Unicode Release MinDependency"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "AtlAgent.mak" CFG="AtlAgent - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "AtlAgent - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "AtlAgent - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "AtlAgent - Win32 Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "AtlAgent - Win32 Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "AtlAgent - Win32 Unicode Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "AtlAgent - Win32 Unicode Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "AtlAgent - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\AtlAgent.dll" "$(OUTDIR)\AtlAgent.bsc" ".\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\AgentCtl.obj"
	-@erase "$(INTDIR)\AgentCtl.sbr"
	-@erase "$(INTDIR)\AtlAgent.obj"
	-@erase "$(INTDIR)\AtlAgent.pch"
	-@erase "$(INTDIR)\AtlAgent.res"
	-@erase "$(INTDIR)\AtlAgent.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\AtlAgent.bsc"
	-@erase "$(OUTDIR)\AtlAgent.dll"
	-@erase "$(OUTDIR)\AtlAgent.exp"
	-@erase "$(OUTDIR)\AtlAgent.ilk"
	-@erase "$(OUTDIR)\AtlAgent.lib"
	-@erase "$(OUTDIR)\AtlAgent.pdb"
	-@erase ".\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W4 /Gm /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "_ATL_ATTRIBUTES" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\AtlAgent.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\AtlAgent.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\AtlAgent.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\AgentCtl.sbr" \
	"$(INTDIR)\AtlAgent.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\AtlAgent.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\AtlAgent.pdb" /debug /machine:I386 /out:"$(OUTDIR)\AtlAgent.dll" /implib:"$(OUTDIR)\AtlAgent.lib" /pdbtype:sept /idlout:_atlagent.idl 
LINK32_OBJS= \
	"$(INTDIR)\AgentCtl.obj" \
	"$(INTDIR)\AtlAgent.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\AtlAgent.res"

"$(OUTDIR)\AtlAgent.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Debug
TargetPath=.\Debug\AtlAgent.dll
InputPath=.\Debug\AtlAgent.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "AtlAgent - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\DebugU
# End Custom Macros

ALL : "$(OUTDIR)\AtlAgent.dll" ".\DebugU\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\AgentCtl.obj"
	-@erase "$(INTDIR)\AtlAgent.obj"
	-@erase "$(INTDIR)\AtlAgent.pch"
	-@erase "$(INTDIR)\AtlAgent.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\AtlAgent.dll"
	-@erase "$(OUTDIR)\AtlAgent.exp"
	-@erase "$(OUTDIR)\AtlAgent.ilk"
	-@erase "$(OUTDIR)\AtlAgent.lib"
	-@erase "$(OUTDIR)\AtlAgent.pdb"
	-@erase ".\DebugU\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W4 /Gm /ZI /Od /D "_DEBUG" /D "_UNICODE" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "_ATL_ATTRIBUTES" /Fp"$(INTDIR)\AtlAgent.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\AtlAgent.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\AtlAgent.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\AtlAgent.pdb" /debug /machine:I386 /out:"$(OUTDIR)\AtlAgent.dll" /implib:"$(OUTDIR)\AtlAgent.lib" /pdbtype:sept /idlout:_atlagent.idl 
LINK32_OBJS= \
	"$(INTDIR)\AgentCtl.obj" \
	"$(INTDIR)\AtlAgent.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\AtlAgent.res"

"$(OUTDIR)\AtlAgent.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\DebugU
TargetPath=.\DebugU\AtlAgent.dll
InputPath=.\DebugU\AtlAgent.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "AtlAgent - Win32 Release MinSize"

OUTDIR=.\ReleaseMinSize
INTDIR=.\ReleaseMinSize
# Begin Custom Macros
OutDir=.\ReleaseMinSize
# End Custom Macros

ALL : "$(OUTDIR)\AtlAgent.dll" ".\ReleaseMinSize\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\AgentCtl.obj"
	-@erase "$(INTDIR)\AtlAgent.obj"
	-@erase "$(INTDIR)\AtlAgent.pch"
	-@erase "$(INTDIR)\AtlAgent.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\AtlAgent.dll"
	-@erase "$(OUTDIR)\AtlAgent.exp"
	-@erase "$(OUTDIR)\AtlAgent.lib"
	-@erase ".\ReleaseMinSize\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W4 /O1 /D "_ATL_DLL" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "_ATL_ATTRIBUTES" /Fp"$(INTDIR)\AtlAgent.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\AtlAgent.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\AtlAgent.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\AtlAgent.pdb" /machine:I386 /out:"$(OUTDIR)\AtlAgent.dll" /implib:"$(OUTDIR)\AtlAgent.lib" /idlout:_atlagent.idl 
LINK32_OBJS= \
	"$(INTDIR)\AgentCtl.obj" \
	"$(INTDIR)\AtlAgent.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\AtlAgent.res"

"$(OUTDIR)\AtlAgent.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseMinSize
TargetPath=.\ReleaseMinSize\AtlAgent.dll
InputPath=.\ReleaseMinSize\AtlAgent.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "AtlAgent - Win32 Release MinDependency"

OUTDIR=.\ReleaseMinDependency
INTDIR=.\ReleaseMinDependency
# Begin Custom Macros
OutDir=.\ReleaseMinDependency
# End Custom Macros

ALL : "$(OUTDIR)\AtlAgent.dll" ".\ReleaseMinDependency\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\AgentCtl.obj"
	-@erase "$(INTDIR)\AtlAgent.obj"
	-@erase "$(INTDIR)\AtlAgent.pch"
	-@erase "$(INTDIR)\AtlAgent.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\AtlAgent.dll"
	-@erase "$(OUTDIR)\AtlAgent.exp"
	-@erase "$(OUTDIR)\AtlAgent.lib"
	-@erase ".\ReleaseMinDependency\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W4 /O1 /D "_ATL_STATIC_REGISTRY" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "_ATL_ATTRIBUTES" /Fp"$(INTDIR)\AtlAgent.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\AtlAgent.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\AtlAgent.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\AtlAgent.pdb" /machine:I386 /out:"$(OUTDIR)\AtlAgent.dll" /implib:"$(OUTDIR)\AtlAgent.lib" /idlout:_atlagent.idl 
LINK32_OBJS= \
	"$(INTDIR)\AgentCtl.obj" \
	"$(INTDIR)\AtlAgent.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\AtlAgent.res"

"$(OUTDIR)\AtlAgent.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseMinDependency
TargetPath=.\ReleaseMinDependency\AtlAgent.dll
InputPath=.\ReleaseMinDependency\AtlAgent.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "AtlAgent - Win32 Unicode Release MinSize"

OUTDIR=.\ReleaseUMinSize
INTDIR=.\ReleaseUMinSize
# Begin Custom Macros
OutDir=.\ReleaseUMinSize
# End Custom Macros

ALL : "$(OUTDIR)\AtlAgent.dll" ".\ReleaseUMinSize\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\AgentCtl.obj"
	-@erase "$(INTDIR)\AtlAgent.obj"
	-@erase "$(INTDIR)\AtlAgent.pch"
	-@erase "$(INTDIR)\AtlAgent.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\AtlAgent.dll"
	-@erase "$(OUTDIR)\AtlAgent.exp"
	-@erase "$(OUTDIR)\AtlAgent.lib"
	-@erase ".\ReleaseUMinSize\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W4 /O1 /D "_UNICODE" /D "_ATL_DLL" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "_ATL_ATTRIBUTES" /Fp"$(INTDIR)\AtlAgent.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\AtlAgent.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\AtlAgent.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\AtlAgent.pdb" /machine:I386 /out:"$(OUTDIR)\AtlAgent.dll" /implib:"$(OUTDIR)\AtlAgent.lib" /idlout:_atlagent.idl 
LINK32_OBJS= \
	"$(INTDIR)\AgentCtl.obj" \
	"$(INTDIR)\AtlAgent.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\AtlAgent.res"

"$(OUTDIR)\AtlAgent.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseUMinSize
TargetPath=.\ReleaseUMinSize\AtlAgent.dll
InputPath=.\ReleaseUMinSize\AtlAgent.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "AtlAgent - Win32 Unicode Release MinDependency"

OUTDIR=.\ReleaseUMinDependency
INTDIR=.\ReleaseUMinDependency
# Begin Custom Macros
OutDir=.\ReleaseUMinDependency
# End Custom Macros

ALL : "$(OUTDIR)\AtlAgent.dll" ".\ReleaseUMinDependency\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\AgentCtl.obj"
	-@erase "$(INTDIR)\AtlAgent.obj"
	-@erase "$(INTDIR)\AtlAgent.pch"
	-@erase "$(INTDIR)\AtlAgent.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\AtlAgent.dll"
	-@erase "$(OUTDIR)\AtlAgent.exp"
	-@erase "$(OUTDIR)\AtlAgent.lib"
	-@erase ".\ReleaseUMinDependency\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W4 /O1 /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "_ATL_ATTRIBUTES" /Fp"$(INTDIR)\AtlAgent.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\AtlAgent.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\AtlAgent.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\AtlAgent.pdb" /machine:I386 /out:"$(OUTDIR)\AtlAgent.dll" /implib:"$(OUTDIR)\AtlAgent.lib" /idlout:_atlagent.idl 
LINK32_OBJS= \
	"$(INTDIR)\AgentCtl.obj" \
	"$(INTDIR)\AtlAgent.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\AtlAgent.res"

"$(OUTDIR)\AtlAgent.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseUMinDependency
TargetPath=.\ReleaseUMinDependency\AtlAgent.dll
InputPath=.\ReleaseUMinDependency\AtlAgent.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("AtlAgent.dep")
!INCLUDE "AtlAgent.dep"
!ELSE 
!MESSAGE Warning: cannot find "AtlAgent.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "AtlAgent - Win32 Debug" || "$(CFG)" == "AtlAgent - Win32 Unicode Debug" || "$(CFG)" == "AtlAgent - Win32 Release MinSize" || "$(CFG)" == "AtlAgent - Win32 Release MinDependency" || "$(CFG)" == "AtlAgent - Win32 Unicode Release MinSize" || "$(CFG)" == "AtlAgent - Win32 Unicode Release MinDependency"
SOURCE=.\AgentCtl.cpp

!IF  "$(CFG)" == "AtlAgent - Win32 Debug"


"$(INTDIR)\AgentCtl.obj"	"$(INTDIR)\AgentCtl.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AtlAgent.pch"


!ELSEIF  "$(CFG)" == "AtlAgent - Win32 Unicode Debug"


"$(INTDIR)\AgentCtl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AtlAgent.pch"


!ELSEIF  "$(CFG)" == "AtlAgent - Win32 Release MinSize"


"$(INTDIR)\AgentCtl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AtlAgent.pch"


!ELSEIF  "$(CFG)" == "AtlAgent - Win32 Release MinDependency"


"$(INTDIR)\AgentCtl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AtlAgent.pch"


!ELSEIF  "$(CFG)" == "AtlAgent - Win32 Unicode Release MinSize"


"$(INTDIR)\AgentCtl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AtlAgent.pch"


!ELSEIF  "$(CFG)" == "AtlAgent - Win32 Unicode Release MinDependency"


"$(INTDIR)\AgentCtl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AtlAgent.pch"


!ENDIF 

SOURCE=.\AtlAgent.cpp

!IF  "$(CFG)" == "AtlAgent - Win32 Debug"


"$(INTDIR)\AtlAgent.obj"	"$(INTDIR)\AtlAgent.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AtlAgent.pch"


!ELSEIF  "$(CFG)" == "AtlAgent - Win32 Unicode Debug"


"$(INTDIR)\AtlAgent.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AtlAgent.pch"


!ELSEIF  "$(CFG)" == "AtlAgent - Win32 Release MinSize"


"$(INTDIR)\AtlAgent.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AtlAgent.pch"


!ELSEIF  "$(CFG)" == "AtlAgent - Win32 Release MinDependency"


"$(INTDIR)\AtlAgent.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AtlAgent.pch"


!ELSEIF  "$(CFG)" == "AtlAgent - Win32 Unicode Release MinSize"


"$(INTDIR)\AtlAgent.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AtlAgent.pch"


!ELSEIF  "$(CFG)" == "AtlAgent - Win32 Unicode Release MinDependency"


"$(INTDIR)\AtlAgent.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\AtlAgent.pch"


!ENDIF 

SOURCE=.\AtlAgent.rc

"$(INTDIR)\AtlAgent.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "AtlAgent - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W4 /Gm /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "_ATL_ATTRIBUTES" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\AtlAgent.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\AtlAgent.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "AtlAgent - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MTd /W4 /Gm /ZI /Od /D "_DEBUG" /D "_UNICODE" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "_ATL_ATTRIBUTES" /Fp"$(INTDIR)\AtlAgent.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\AtlAgent.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "AtlAgent - Win32 Release MinSize"

CPP_SWITCHES=/nologo /MT /W4 /O1 /D "_ATL_DLL" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "_ATL_ATTRIBUTES" /Fp"$(INTDIR)\AtlAgent.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\AtlAgent.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "AtlAgent - Win32 Release MinDependency"

CPP_SWITCHES=/nologo /MT /W4 /O1 /D "_ATL_STATIC_REGISTRY" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "_ATL_ATTRIBUTES" /Fp"$(INTDIR)\AtlAgent.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\AtlAgent.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "AtlAgent - Win32 Unicode Release MinSize"

CPP_SWITCHES=/nologo /MT /W4 /O1 /D "_UNICODE" /D "_ATL_DLL" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "_ATL_ATTRIBUTES" /Fp"$(INTDIR)\AtlAgent.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\AtlAgent.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "AtlAgent - Win32 Unicode Release MinDependency"

CPP_SWITCHES=/nologo /MT /W4 /O1 /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "_ATL_ATTRIBUTES" /Fp"$(INTDIR)\AtlAgent.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\AtlAgent.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

