# Microsoft Developer Studio Generated NMAKE File, Based on atlduck.dsp
!IF "$(CFG)" == ""
CFG=atlduck - Win32 Unicode Release
!MESSAGE No configuration specified. Defaulting to atlduck - Win32 Unicode Release.
!ENDIF 

!IF "$(CFG)" != "atlduck - Win32 Debug" && "$(CFG)" != "atlduck - Win32 Unicode Debug" && "$(CFG)" != "atlduck - Win32 Release" && "$(CFG)" != "atlduck - Win32 Unicode Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "atlduck.mak" CFG="atlduck - Win32 Unicode Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "atlduck - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "atlduck - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE "atlduck - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "atlduck - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "atlduck - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\atlduck.exe" "$(OUTDIR)\atlduck.bsc"

!ELSE 

ALL : "duck - Win32 Debug" "$(OUTDIR)\atlduck.exe" "$(OUTDIR)\atlduck.bsc"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"duck - Win32 DebugCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\atlduck.obj"
	-@erase "$(INTDIR)\atlduck.pch"
	-@erase "$(INTDIR)\atlduck.res"
	-@erase "$(INTDIR)\atlduck.sbr"
	-@erase "$(INTDIR)\DuckDoer.obj"
	-@erase "$(INTDIR)\DuckDoer.sbr"
	-@erase "$(INTDIR)\DuckDoerDlg.obj"
	-@erase "$(INTDIR)\DuckDoerDlg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\atlduck.bsc"
	-@erase "$(OUTDIR)\atlduck.exe"
	-@erase "$(OUTDIR)\atlduck.ilk"
	-@erase "$(OUTDIR)\atlduck.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MLd /W3 /Gm /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\atlduck.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\atlduck.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\atlduck.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\atlduck.sbr" \
	"$(INTDIR)\DuckDoer.sbr" \
	"$(INTDIR)\DuckDoerDlg.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\atlduck.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\atlduck.pdb" /debug /machine:I386 /out:"$(OUTDIR)\atlduck.exe" /pdbtype:sept /idlout:_atlduck.idl 
LINK32_OBJS= \
	"$(INTDIR)\atlduck.obj" \
	"$(INTDIR)\DuckDoer.obj" \
	"$(INTDIR)\DuckDoerDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\atlduck.res"

"$(OUTDIR)\atlduck.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "atlduck - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\DebugU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\atlduck.exe"

!ELSE 

ALL : "duck - Win32 Unicode Debug" "$(OUTDIR)\atlduck.exe"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"duck - Win32 Unicode DebugCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\atlduck.obj"
	-@erase "$(INTDIR)\atlduck.pch"
	-@erase "$(INTDIR)\atlduck.res"
	-@erase "$(INTDIR)\DuckDoer.obj"
	-@erase "$(INTDIR)\DuckDoerDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\atlduck.exe"
	-@erase "$(OUTDIR)\atlduck.ilk"
	-@erase "$(OUTDIR)\atlduck.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MLd /W3 /Gm /ZI /Od /D "_DEBUG" /D "_UNICODE" /D "WIN32" /D "_WINDOWS" /Fp"$(INTDIR)\atlduck.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\atlduck.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\atlduck.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\atlduck.pdb" /debug /machine:I386 /out:"$(OUTDIR)\atlduck.exe" /pdbtype:sept /idlout:_atlduck.idl 
LINK32_OBJS= \
	"$(INTDIR)\atlduck.obj" \
	"$(INTDIR)\DuckDoer.obj" \
	"$(INTDIR)\DuckDoerDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\atlduck.res"

"$(OUTDIR)\atlduck.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "atlduck - Win32 Release"

OUTDIR=.\atlduck_
INTDIR=.\atlduck_
# Begin Custom Macros
OutDir=.\atlduck_
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : ".\release\atlduck.exe" "$(OUTDIR)\atlduck.bsc"

!ELSE 

ALL : "duck - Win32 Release" ".\release\atlduck.exe" "$(OUTDIR)\atlduck.bsc"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"duck - Win32 ReleaseCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\atlduck.obj"
	-@erase "$(INTDIR)\atlduck.pch"
	-@erase "$(INTDIR)\atlduck.res"
	-@erase "$(INTDIR)\atlduck.sbr"
	-@erase "$(INTDIR)\DuckDoer.obj"
	-@erase "$(INTDIR)\DuckDoer.sbr"
	-@erase "$(INTDIR)\DuckDoerDlg.obj"
	-@erase "$(INTDIR)\DuckDoerDlg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\atlduck.bsc"
	-@erase ".\release\atlduck.exe"
	-@erase ".\release\atlduck.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /O1 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\atlduck.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\atlduck.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\atlduck.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\atlduck.sbr" \
	"$(INTDIR)\DuckDoer.sbr" \
	"$(INTDIR)\DuckDoerDlg.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\atlduck.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\atlduck.pdb" /machine:I386 /out:"release/atlduck.exe" /pdbtype:sept /idlout:_atlduck.idl 
LINK32_OBJS= \
	"$(INTDIR)\atlduck.obj" \
	"$(INTDIR)\DuckDoer.obj" \
	"$(INTDIR)\DuckDoerDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\atlduck.res"

".\release\atlduck.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "atlduck - Win32 Unicode Release"

OUTDIR=.\atlduck0
INTDIR=.\atlduck0
# Begin Custom Macros
OutDir=.\atlduck0
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : ".\releaseu\atlduck.exe" "$(OUTDIR)\atlduck.bsc"

!ELSE 

ALL : "duck - Win32 Unicode Release" ".\releaseu\atlduck.exe" "$(OUTDIR)\atlduck.bsc"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"duck - Win32 Unicode ReleaseCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\atlduck.obj"
	-@erase "$(INTDIR)\atlduck.pch"
	-@erase "$(INTDIR)\atlduck.res"
	-@erase "$(INTDIR)\atlduck.sbr"
	-@erase "$(INTDIR)\DuckDoer.obj"
	-@erase "$(INTDIR)\DuckDoer.sbr"
	-@erase "$(INTDIR)\DuckDoerDlg.obj"
	-@erase "$(INTDIR)\DuckDoerDlg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\atlduck.bsc"
	-@erase ".\releaseu\atlduck.exe"
	-@erase ".\releaseu\atlduck.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /GX /O1 /D "NDEBUG" /D "_UNICODE" /D "WIN32" /D "_WINDOWS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\atlduck.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\atlduck.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\atlduck.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\atlduck.sbr" \
	"$(INTDIR)\DuckDoer.sbr" \
	"$(INTDIR)\DuckDoerDlg.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\atlduck.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\atlduck.pdb" /machine:I386 /out:"releaseu/atlduck.exe" /pdbtype:sept /idlout:_atlduck.idl 
LINK32_OBJS= \
	"$(INTDIR)\atlduck.obj" \
	"$(INTDIR)\DuckDoer.obj" \
	"$(INTDIR)\DuckDoerDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\atlduck.res"

".\releaseu\atlduck.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("atlduck.dep")
!INCLUDE "atlduck.dep"
!ELSE 
!MESSAGE Warning: cannot find "atlduck.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "atlduck - Win32 Debug" || "$(CFG)" == "atlduck - Win32 Unicode Debug" || "$(CFG)" == "atlduck - Win32 Release" || "$(CFG)" == "atlduck - Win32 Unicode Release"
SOURCE=.\atlduck.cpp

!IF  "$(CFG)" == "atlduck - Win32 Debug"


"$(INTDIR)\atlduck.obj"	"$(INTDIR)\atlduck.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\atlduck.pch"


!ELSEIF  "$(CFG)" == "atlduck - Win32 Unicode Debug"


"$(INTDIR)\atlduck.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\atlduck.pch"


!ELSEIF  "$(CFG)" == "atlduck - Win32 Release"


"$(INTDIR)\atlduck.obj"	"$(INTDIR)\atlduck.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\atlduck.pch"


!ELSEIF  "$(CFG)" == "atlduck - Win32 Unicode Release"


"$(INTDIR)\atlduck.obj"	"$(INTDIR)\atlduck.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\atlduck.pch"


!ENDIF 

SOURCE=.\atlduck.rc

"$(INTDIR)\atlduck.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\DuckDoer.cpp

!IF  "$(CFG)" == "atlduck - Win32 Debug"


"$(INTDIR)\DuckDoer.obj"	"$(INTDIR)\DuckDoer.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\atlduck.pch"


!ELSEIF  "$(CFG)" == "atlduck - Win32 Unicode Debug"


"$(INTDIR)\DuckDoer.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\atlduck.pch"


!ELSEIF  "$(CFG)" == "atlduck - Win32 Release"


"$(INTDIR)\DuckDoer.obj"	"$(INTDIR)\DuckDoer.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\atlduck.pch"


!ELSEIF  "$(CFG)" == "atlduck - Win32 Unicode Release"


"$(INTDIR)\DuckDoer.obj"	"$(INTDIR)\DuckDoer.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\atlduck.pch"


!ENDIF 

SOURCE=.\DuckDoerDlg.cpp

!IF  "$(CFG)" == "atlduck - Win32 Debug"


"$(INTDIR)\DuckDoerDlg.obj"	"$(INTDIR)\DuckDoerDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\atlduck.pch"


!ELSEIF  "$(CFG)" == "atlduck - Win32 Unicode Debug"


"$(INTDIR)\DuckDoerDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\atlduck.pch"


!ELSEIF  "$(CFG)" == "atlduck - Win32 Release"


"$(INTDIR)\DuckDoerDlg.obj"	"$(INTDIR)\DuckDoerDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\atlduck.pch"


!ELSEIF  "$(CFG)" == "atlduck - Win32 Unicode Release"


"$(INTDIR)\DuckDoerDlg.obj"	"$(INTDIR)\DuckDoerDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\atlduck.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "atlduck - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\atlduck.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\atlduck.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "atlduck - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /ZI /Od /D "_DEBUG" /D "_UNICODE" /D "WIN32" /D "_WINDOWS" /Fp"$(INTDIR)\atlduck.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\atlduck.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "atlduck - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /O1 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\atlduck.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\atlduck.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "atlduck - Win32 Unicode Release"

CPP_SWITCHES=/nologo /ML /W3 /GX /O1 /D "NDEBUG" /D "_UNICODE" /D "WIN32" /D "_WINDOWS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\atlduck.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\atlduck.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

!IF  "$(CFG)" == "atlduck - Win32 Debug"

"duck - Win32 Debug" : 
   cd ".\duck"
   $(MAKE) /$(MAKEFLAGS) /F .\duck.mak CFG="duck - Win32 Debug" 
   cd ".."

"duck - Win32 DebugCLEAN" : 
   cd ".\duck"
   $(MAKE) /$(MAKEFLAGS) /F .\duck.mak CFG="duck - Win32 Debug" RECURSE=1 CLEAN 
   cd ".."

!ELSEIF  "$(CFG)" == "atlduck - Win32 Unicode Debug"

"duck - Win32 Unicode Debug" : 
   cd ".\duck"
   $(MAKE) /$(MAKEFLAGS) /F .\duck.mak CFG="duck - Win32 Unicode Debug" 
   cd ".."

"duck - Win32 Unicode DebugCLEAN" : 
   cd ".\duck"
   $(MAKE) /$(MAKEFLAGS) /F .\duck.mak CFG="duck - Win32 Unicode Debug" RECURSE=1 CLEAN 
   cd ".."

!ELSEIF  "$(CFG)" == "atlduck - Win32 Release"

"duck - Win32 Release" : 
   cd ".\duck"
   $(MAKE) /$(MAKEFLAGS) /F .\duck.mak CFG="duck - Win32 Release" 
   cd ".."

"duck - Win32 ReleaseCLEAN" : 
   cd ".\duck"
   $(MAKE) /$(MAKEFLAGS) /F .\duck.mak CFG="duck - Win32 Release" RECURSE=1 CLEAN 
   cd ".."

!ELSEIF  "$(CFG)" == "atlduck - Win32 Unicode Release"

"duck - Win32 Unicode Release" : 
   cd ".\duck"
   $(MAKE) /$(MAKEFLAGS) /F .\duck.mak CFG="duck - Win32 Unicode Release" 
   cd ".."

"duck - Win32 Unicode ReleaseCLEAN" : 
   cd ".\duck"
   $(MAKE) /$(MAKEFLAGS) /F .\duck.mak CFG="duck - Win32 Unicode Release" RECURSE=1 CLEAN 
   cd ".."

!ENDIF 


!ENDIF 

