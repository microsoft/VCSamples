# Microsoft Developer Studio Generated NMAKE File, Based on ATLCon.dsp
!IF "$(CFG)" == ""
CFG=ATLCon - Win32 Debug
!MESSAGE No configuration specified. Defaulting to ATLCon - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "ATLCon - Win32 Debug" && "$(CFG)" != "ATLCon - Win32 Unicode Debug" && "$(CFG)" != "ATLCon - Win32 Release MinSize" && "$(CFG)" != "ATLCon - Win32 Release MinDependency" && "$(CFG)" != "ATLCon - Win32 Unicode Release MinSize" && "$(CFG)" != "ATLCon - Win32 Unicode Release MinDependency"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ATLCon.mak" CFG="ATLCon - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ATLCon - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "ATLCon - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE "ATLCon - Win32 Release MinSize" (based on "Win32 (x86) Application")
!MESSAGE "ATLCon - Win32 Release MinDependency" (based on "Win32 (x86) Application")
!MESSAGE "ATLCon - Win32 Unicode Release MinSize" (based on "Win32 (x86) Application")
!MESSAGE "ATLCon - Win32 Unicode Release MinDependency" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "ATLCon - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\ATLCon.exe"


CLEAN :
	-@erase "$(INTDIR)\ATLCon.obj"
	-@erase "$(INTDIR)\ATLCon.pch"
	-@erase "$(INTDIR)\ATLCon.res"
	-@erase "$(INTDIR)\PropBrowseCtl.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\ATLCon.exe"
	-@erase "$(OUTDIR)\ATLCon.ilk"
	-@erase "$(OUTDIR)\ATLCon.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MLd /W3 /Gm /ZI /Od /D "_DEBUG" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "_ATL_ATTRIBUTES" /Fp"$(INTDIR)\ATLCon.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

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
MTL_PROJ=
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ATLCon.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ATLCon.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\ATLCon.pdb" /debug /machine:I386 /out:"$(OUTDIR)\ATLCon.exe" /pdbtype:sept /idlout:_atlcon.idl 
LINK32_OBJS= \
	"$(INTDIR)\ATLCon.obj" \
	"$(INTDIR)\PropBrowseCtl.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ATLCon.res"

"$(OUTDIR)\ATLCon.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ATLCon - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\DebugU
# End Custom Macros

ALL : "$(OUTDIR)\ATLCon.exe"


CLEAN :
	-@erase "$(INTDIR)\ATLCon.obj"
	-@erase "$(INTDIR)\ATLCon.pch"
	-@erase "$(INTDIR)\ATLCon.res"
	-@erase "$(INTDIR)\PropBrowseCtl.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\ATLCon.exe"
	-@erase "$(OUTDIR)\ATLCon.ilk"
	-@erase "$(OUTDIR)\ATLCon.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MLd /W3 /Gm /ZI /Od /D "_DEBUG" /D "_UNICODE" /D "WIN32" /D "_WINDOWS" /D "_ATL_ATTRIBUTES" /Fp"$(INTDIR)\ATLCon.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

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
MTL_PROJ=
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ATLCon.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ATLCon.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\ATLCon.pdb" /debug /machine:I386 /out:"$(OUTDIR)\ATLCon.exe" /pdbtype:sept /idlout:_atlcon.idl 
LINK32_OBJS= \
	"$(INTDIR)\ATLCon.obj" \
	"$(INTDIR)\PropBrowseCtl.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ATLCon.res"

"$(OUTDIR)\ATLCon.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ATLCon - Win32 Release MinSize"

OUTDIR=.\ReleaseMinSize
INTDIR=.\ReleaseMinSize
# Begin Custom Macros
OutDir=.\ReleaseMinSize
# End Custom Macros

ALL : "$(OUTDIR)\ATLCon.exe"


CLEAN :
	-@erase "$(INTDIR)\ATLCon.obj"
	-@erase "$(INTDIR)\ATLCon.pch"
	-@erase "$(INTDIR)\ATLCon.res"
	-@erase "$(INTDIR)\PropBrowseCtl.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\ATLCon.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /O1 /D "NDEBUG" /D "_MBCS" /D "_ATL_DLL" /D "WIN32" /D "_WINDOWS" /D "_ATL_ATTRIBUTES" /Fp"$(INTDIR)\ATLCon.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ATLCon.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ATLCon.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\ATLCon.pdb" /machine:I386 /out:"$(OUTDIR)\ATLCon.exe" /idlout:_atlcon.idl 
LINK32_OBJS= \
	"$(INTDIR)\ATLCon.obj" \
	"$(INTDIR)\PropBrowseCtl.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ATLCon.res"

"$(OUTDIR)\ATLCon.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ATLCon - Win32 Release MinDependency"

OUTDIR=.\ReleaseMinDependency
INTDIR=.\ReleaseMinDependency
# Begin Custom Macros
OutDir=.\ReleaseMinDependency
# End Custom Macros

ALL : "$(OUTDIR)\ATLCon.exe"


CLEAN :
	-@erase "$(INTDIR)\ATLCon.obj"
	-@erase "$(INTDIR)\ATLCon.pch"
	-@erase "$(INTDIR)\ATLCon.res"
	-@erase "$(INTDIR)\PropBrowseCtl.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\ATLCon.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /O1 /D "NDEBUG" /D "_MBCS" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "_WINDOWS" /D "_ATL_ATTRIBUTES" /Fp"$(INTDIR)\ATLCon.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ATLCon.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ATLCon.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\ATLCon.pdb" /machine:I386 /out:"$(OUTDIR)\ATLCon.exe" /idlout:_atlcon.idl 
LINK32_OBJS= \
	"$(INTDIR)\ATLCon.obj" \
	"$(INTDIR)\PropBrowseCtl.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ATLCon.res"

"$(OUTDIR)\ATLCon.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ATLCon - Win32 Unicode Release MinSize"

OUTDIR=.\ReleaseUMinSize
INTDIR=.\ReleaseUMinSize
# Begin Custom Macros
OutDir=.\ReleaseUMinSize
# End Custom Macros

ALL : "$(OUTDIR)\ATLCon.exe"


CLEAN :
	-@erase "$(INTDIR)\ATLCon.obj"
	-@erase "$(INTDIR)\ATLCon.pch"
	-@erase "$(INTDIR)\ATLCon.res"
	-@erase "$(INTDIR)\PropBrowseCtl.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\ATLCon.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /O1 /D "NDEBUG" /D "_UNICODE" /D "_ATL_DLL" /D "WIN32" /D "_WINDOWS" /D "_ATL_ATTRIBUTES" /Fp"$(INTDIR)\ATLCon.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ATLCon.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ATLCon.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\ATLCon.pdb" /machine:I386 /out:"$(OUTDIR)\ATLCon.exe" /idlout:_atlcon.idl 
LINK32_OBJS= \
	"$(INTDIR)\ATLCon.obj" \
	"$(INTDIR)\PropBrowseCtl.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ATLCon.res"

"$(OUTDIR)\ATLCon.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ATLCon - Win32 Unicode Release MinDependency"

OUTDIR=.\ReleaseUMinDependency
INTDIR=.\ReleaseUMinDependency
# Begin Custom Macros
OutDir=.\ReleaseUMinDependency
# End Custom Macros

ALL : "$(OUTDIR)\ATLCon.exe"


CLEAN :
	-@erase "$(INTDIR)\ATLCon.obj"
	-@erase "$(INTDIR)\ATLCon.pch"
	-@erase "$(INTDIR)\ATLCon.res"
	-@erase "$(INTDIR)\PropBrowseCtl.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\ATLCon.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /O1 /D "NDEBUG" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "_WINDOWS" /D "_ATL_ATTRIBUTES" /Fp"$(INTDIR)\ATLCon.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ATLCon.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ATLCon.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\ATLCon.pdb" /machine:I386 /out:"$(OUTDIR)\ATLCon.exe" /idlout:_atlcon.idl 
LINK32_OBJS= \
	"$(INTDIR)\ATLCon.obj" \
	"$(INTDIR)\PropBrowseCtl.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ATLCon.res"

"$(OUTDIR)\ATLCon.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("ATLCon.dep")
!INCLUDE "ATLCon.dep"
!ELSE 
!MESSAGE Warning: cannot find "ATLCon.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "ATLCon - Win32 Debug" || "$(CFG)" == "ATLCon - Win32 Unicode Debug" || "$(CFG)" == "ATLCon - Win32 Release MinSize" || "$(CFG)" == "ATLCon - Win32 Release MinDependency" || "$(CFG)" == "ATLCon - Win32 Unicode Release MinSize" || "$(CFG)" == "ATLCon - Win32 Unicode Release MinDependency"
SOURCE=.\ATLCon.cpp

"$(INTDIR)\ATLCon.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ATLCon.pch"


SOURCE=.\ATLCon.rc

"$(INTDIR)\ATLCon.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\PropBrowseCtl.cpp

"$(INTDIR)\PropBrowseCtl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ATLCon.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "ATLCon - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /ZI /Od /D "_DEBUG" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "_ATL_ATTRIBUTES" /Fp"$(INTDIR)\ATLCon.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ATLCon.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ATLCon - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /ZI /Od /D "_DEBUG" /D "_UNICODE" /D "WIN32" /D "_WINDOWS" /D "_ATL_ATTRIBUTES" /Fp"$(INTDIR)\ATLCon.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ATLCon.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ATLCon - Win32 Release MinSize"

CPP_SWITCHES=/nologo /ML /W3 /O1 /D "NDEBUG" /D "_MBCS" /D "_ATL_DLL" /D "WIN32" /D "_WINDOWS" /D "_ATL_ATTRIBUTES" /Fp"$(INTDIR)\ATLCon.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ATLCon.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ATLCon - Win32 Release MinDependency"

CPP_SWITCHES=/nologo /ML /W3 /O1 /D "NDEBUG" /D "_MBCS" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "_WINDOWS" /D "_ATL_ATTRIBUTES" /Fp"$(INTDIR)\ATLCon.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ATLCon.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ATLCon - Win32 Unicode Release MinSize"

CPP_SWITCHES=/nologo /ML /W3 /O1 /D "NDEBUG" /D "_UNICODE" /D "_ATL_DLL" /D "WIN32" /D "_WINDOWS" /D "_ATL_ATTRIBUTES" /Fp"$(INTDIR)\ATLCon.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ATLCon.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ATLCon - Win32 Unicode Release MinDependency"

CPP_SWITCHES=/nologo /ML /W3 /O1 /D "NDEBUG" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "_WINDOWS" /D "_ATL_ATTRIBUTES" /Fp"$(INTDIR)\ATLCon.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ATLCon.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

