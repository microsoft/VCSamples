# Microsoft Developer Studio Generated NMAKE File, Based on duck.dsp
!IF "$(CFG)" == ""
CFG=duck - Win32 Unicode Release
!MESSAGE No configuration specified. Defaulting to duck - Win32 Unicode Release.
!ENDIF 

!IF "$(CFG)" != "duck - Win32 Debug" && "$(CFG)" != "duck - Win32 Unicode Debug" && "$(CFG)" != "duck - Win32 Release" && "$(CFG)" != "duck - Win32 Unicode Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "duck.mak" CFG="duck - Win32 Unicode Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "duck - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "duck - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE "duck - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "duck - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "duck - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\duck.exe" "$(OUTDIR)\duck.bsc"


CLEAN :
	-@erase "$(INTDIR)\duck.obj"
	-@erase "$(INTDIR)\duck.pch"
	-@erase "$(INTDIR)\duck.res"
	-@erase "$(INTDIR)\duck.sbr"
	-@erase "$(INTDIR)\DuckInt.obj"
	-@erase "$(INTDIR)\DuckInt.sbr"
	-@erase "$(INTDIR)\mydlg.obj"
	-@erase "$(INTDIR)\mydlg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\duck.bsc"
	-@erase "$(OUTDIR)\duck.exe"
	-@erase "$(OUTDIR)\duck.ilk"
	-@erase "$(OUTDIR)\duck.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\duck.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\duck.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\duck.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\duck.sbr" \
	"$(INTDIR)\DuckInt.sbr" \
	"$(INTDIR)\mydlg.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\duck.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\duck.pdb" /debug /machine:I386 /out:"$(OUTDIR)\duck.exe" /pdbtype:sept /idlout:_duck.idl 
LINK32_OBJS= \
	"$(INTDIR)\duck.obj" \
	"$(INTDIR)\DuckInt.obj" \
	"$(INTDIR)\mydlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\duck.res"

"$(OUTDIR)\duck.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "duck - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\DebugU
# End Custom Macros

ALL : "$(OUTDIR)\duck.exe"


CLEAN :
	-@erase "$(INTDIR)\duck.obj"
	-@erase "$(INTDIR)\duck.pch"
	-@erase "$(INTDIR)\duck.res"
	-@erase "$(INTDIR)\DuckInt.obj"
	-@erase "$(INTDIR)\mydlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\duck.exe"
	-@erase "$(OUTDIR)\duck.ilk"
	-@erase "$(OUTDIR)\duck.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "_UNICODE" /D "WIN32" /D "_WINDOWS" /Fp"$(INTDIR)\duck.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\duck.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\duck.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\duck.pdb" /debug /machine:I386 /out:"$(OUTDIR)\duck.exe" /pdbtype:sept /idlout:_duck.idl 
LINK32_OBJS= \
	"$(INTDIR)\duck.obj" \
	"$(INTDIR)\DuckInt.obj" \
	"$(INTDIR)\mydlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\duck.res"

"$(OUTDIR)\duck.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "duck - Win32 Release"

OUTDIR=.\duck___W
INTDIR=.\duck___W

ALL : ".\release\duck.exe"


CLEAN :
	-@erase "$(INTDIR)\duck.obj"
	-@erase "$(INTDIR)\duck.pch"
	-@erase "$(INTDIR)\duck.res"
	-@erase "$(INTDIR)\DuckInt.obj"
	-@erase "$(INTDIR)\mydlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\duck.pdb"
	-@erase ".\release\duck.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /Gm /GX /Zi /O1 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /Fp"$(INTDIR)\duck.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\duck.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\duck.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\duck.pdb" /debug /machine:I386 /out:"release/duck.exe" /pdbtype:sept /idlout:_duck.idl 
LINK32_OBJS= \
	"$(INTDIR)\duck.obj" \
	"$(INTDIR)\DuckInt.obj" \
	"$(INTDIR)\mydlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\duck.res"

".\release\duck.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "duck - Win32 Unicode Release"

OUTDIR=.\duck___0
INTDIR=.\duck___0
# Begin Custom Macros
OutDir=.\duck___0
# End Custom Macros

ALL : ".\ReleaseU\duck.exe" "$(OUTDIR)\duck.bsc"


CLEAN :
	-@erase "$(INTDIR)\duck.obj"
	-@erase "$(INTDIR)\duck.pch"
	-@erase "$(INTDIR)\duck.res"
	-@erase "$(INTDIR)\duck.sbr"
	-@erase "$(INTDIR)\DuckInt.obj"
	-@erase "$(INTDIR)\DuckInt.sbr"
	-@erase "$(INTDIR)\mydlg.obj"
	-@erase "$(INTDIR)\mydlg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\duck.bsc"
	-@erase ".\ReleaseU\duck.exe"
	-@erase ".\ReleaseU\duck.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /GX /O1 /D "NDEBUG" /D "_UNICODE" /D "WIN32" /D "_WINDOWS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\duck.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\duck.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\duck.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\duck.sbr" \
	"$(INTDIR)\DuckInt.sbr" \
	"$(INTDIR)\mydlg.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\duck.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\duck.pdb" /machine:I386 /out:"ReleaseU/duck.exe" /pdbtype:sept /idlout:_duck.idl 
LINK32_OBJS= \
	"$(INTDIR)\duck.obj" \
	"$(INTDIR)\DuckInt.obj" \
	"$(INTDIR)\mydlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\duck.res"

".\ReleaseU\duck.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("duck.dep")
!INCLUDE "duck.dep"
!ELSE 
!MESSAGE Warning: cannot find "duck.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "duck - Win32 Debug" || "$(CFG)" == "duck - Win32 Unicode Debug" || "$(CFG)" == "duck - Win32 Release" || "$(CFG)" == "duck - Win32 Unicode Release"
SOURCE=.\duck.cpp

!IF  "$(CFG)" == "duck - Win32 Debug"


"$(INTDIR)\duck.obj"	"$(INTDIR)\duck.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\duck.pch"


!ELSEIF  "$(CFG)" == "duck - Win32 Unicode Debug"


"$(INTDIR)\duck.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\duck.pch"


!ELSEIF  "$(CFG)" == "duck - Win32 Release"


"$(INTDIR)\duck.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\duck.pch"


!ELSEIF  "$(CFG)" == "duck - Win32 Unicode Release"


"$(INTDIR)\duck.obj"	"$(INTDIR)\duck.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\duck.pch"


!ENDIF 

SOURCE=.\duck.rc

"$(INTDIR)\duck.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\DuckInt.cpp

!IF  "$(CFG)" == "duck - Win32 Debug"


"$(INTDIR)\DuckInt.obj"	"$(INTDIR)\DuckInt.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\duck.pch"


!ELSEIF  "$(CFG)" == "duck - Win32 Unicode Debug"


"$(INTDIR)\DuckInt.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\duck.pch"


!ELSEIF  "$(CFG)" == "duck - Win32 Release"


"$(INTDIR)\DuckInt.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\duck.pch"


!ELSEIF  "$(CFG)" == "duck - Win32 Unicode Release"


"$(INTDIR)\DuckInt.obj"	"$(INTDIR)\DuckInt.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\duck.pch"


!ENDIF 

SOURCE=.\mydlg.cpp

!IF  "$(CFG)" == "duck - Win32 Debug"


"$(INTDIR)\mydlg.obj"	"$(INTDIR)\mydlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\duck.pch"


!ELSEIF  "$(CFG)" == "duck - Win32 Unicode Debug"


"$(INTDIR)\mydlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\duck.pch"


!ELSEIF  "$(CFG)" == "duck - Win32 Release"


"$(INTDIR)\mydlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\duck.pch"


!ELSEIF  "$(CFG)" == "duck - Win32 Unicode Release"


"$(INTDIR)\mydlg.obj"	"$(INTDIR)\mydlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\duck.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "duck - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\duck.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\duck.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "duck - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "_UNICODE" /D "WIN32" /D "_WINDOWS" /Fp"$(INTDIR)\duck.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\duck.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "duck - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /Gm /GX /Zi /O1 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /Fp"$(INTDIR)\duck.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\duck.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "duck - Win32 Unicode Release"

CPP_SWITCHES=/nologo /ML /W3 /GX /O1 /D "NDEBUG" /D "_UNICODE" /D "WIN32" /D "_WINDOWS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\duck.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\duck.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

