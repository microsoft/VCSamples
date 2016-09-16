# Microsoft Developer Studio Generated NMAKE File, Based on snapvw.dsp
!IF "$(CFG)" == ""
CFG=Snap - Win32 Release
!MESSAGE No configuration specified. Defaulting to Snap - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Snap - Win32 Release" && "$(CFG)" != "Snap - Win32 Debug" && "$(CFG)" != "Snap - Win32 Unicode Release" && "$(CFG)" != "Snap - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "snapvw.mak" CFG="Snap - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Snap - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Snap - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "Snap - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "Snap - Win32 Unicode Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "Snap - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\snapvw.exe"


CLEAN :
	-@erase "$(INTDIR)\BkfstPg.obj"
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\DinnerPg.obj"
	-@erase "$(INTDIR)\LunchPg.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\SnapDoc.obj"
	-@erase "$(INTDIR)\SnapPs.obj"
	-@erase "$(INTDIR)\SnapView.obj"
	-@erase "$(INTDIR)\snapvw.obj"
	-@erase "$(INTDIR)\snapvw.pch"
	-@erase "$(INTDIR)\snapvw.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\snapvw.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\snapvw.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\snapvw.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\snapvw.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\snapvw.pdb" /machine:I386 /out:"$(OUTDIR)\snapvw.exe" 
LINK32_OBJS= \
	"$(INTDIR)\BkfstPg.obj" \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\DinnerPg.obj" \
	"$(INTDIR)\LunchPg.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\SnapDoc.obj" \
	"$(INTDIR)\SnapPs.obj" \
	"$(INTDIR)\SnapView.obj" \
	"$(INTDIR)\snapvw.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\snapvw.res"

"$(OUTDIR)\snapvw.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Snap - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\snapvw.exe"


CLEAN :
	-@erase "$(INTDIR)\BkfstPg.obj"
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\DinnerPg.obj"
	-@erase "$(INTDIR)\LunchPg.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\SnapDoc.obj"
	-@erase "$(INTDIR)\SnapPs.obj"
	-@erase "$(INTDIR)\SnapView.obj"
	-@erase "$(INTDIR)\snapvw.obj"
	-@erase "$(INTDIR)\snapvw.pch"
	-@erase "$(INTDIR)\snapvw.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\snapvw.exe"
	-@erase "$(OUTDIR)\snapvw.ilk"
	-@erase "$(OUTDIR)\snapvw.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\snapvw.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\snapvw.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\snapvw.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\snapvw.pdb" /debug /machine:I386 /out:"$(OUTDIR)\snapvw.exe" 
LINK32_OBJS= \
	"$(INTDIR)\BkfstPg.obj" \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\DinnerPg.obj" \
	"$(INTDIR)\LunchPg.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\SnapDoc.obj" \
	"$(INTDIR)\SnapPs.obj" \
	"$(INTDIR)\SnapView.obj" \
	"$(INTDIR)\snapvw.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\snapvw.res"

"$(OUTDIR)\snapvw.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Snap - Win32 Unicode Release"

OUTDIR=.\UniRel
INTDIR=.\UniRel
# Begin Custom Macros
OutDir=.\.\UniRel
# End Custom Macros

ALL : "$(OUTDIR)\snapvw.exe"


CLEAN :
	-@erase "$(INTDIR)\BkfstPg.obj"
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\DinnerPg.obj"
	-@erase "$(INTDIR)\LunchPg.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\SnapDoc.obj"
	-@erase "$(INTDIR)\SnapPs.obj"
	-@erase "$(INTDIR)\SnapView.obj"
	-@erase "$(INTDIR)\snapvw.obj"
	-@erase "$(INTDIR)\snapvw.pch"
	-@erase "$(INTDIR)\snapvw.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\snapvw.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D "_UNICODE" /Fp"$(INTDIR)\snapvw.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\snapvw.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\snapvw.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\snapvw.pdb" /machine:I386 /out:"$(OUTDIR)\snapvw.exe" 
LINK32_OBJS= \
	"$(INTDIR)\BkfstPg.obj" \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\DinnerPg.obj" \
	"$(INTDIR)\LunchPg.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\SnapDoc.obj" \
	"$(INTDIR)\SnapPs.obj" \
	"$(INTDIR)\SnapView.obj" \
	"$(INTDIR)\snapvw.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\snapvw.res"

"$(OUTDIR)\snapvw.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Snap - Win32 Unicode Debug"

OUTDIR=.\UniDebug
INTDIR=.\UniDebug
# Begin Custom Macros
OutDir=.\.\UniDebug
# End Custom Macros

ALL : "$(OUTDIR)\snapvw.exe"


CLEAN :
	-@erase "$(INTDIR)\BkfstPg.obj"
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\DinnerPg.obj"
	-@erase "$(INTDIR)\LunchPg.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\SnapDoc.obj"
	-@erase "$(INTDIR)\SnapPs.obj"
	-@erase "$(INTDIR)\SnapView.obj"
	-@erase "$(INTDIR)\snapvw.obj"
	-@erase "$(INTDIR)\snapvw.pch"
	-@erase "$(INTDIR)\snapvw.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\snapvw.exe"
	-@erase "$(OUTDIR)\snapvw.ilk"
	-@erase "$(OUTDIR)\snapvw.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D "_UNICODE" /Fp"$(INTDIR)\snapvw.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\snapvw.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\snapvw.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\snapvw.pdb" /debug /machine:I386 /out:"$(OUTDIR)\snapvw.exe" 
LINK32_OBJS= \
	"$(INTDIR)\BkfstPg.obj" \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\DinnerPg.obj" \
	"$(INTDIR)\LunchPg.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\SnapDoc.obj" \
	"$(INTDIR)\SnapPs.obj" \
	"$(INTDIR)\SnapView.obj" \
	"$(INTDIR)\snapvw.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\snapvw.res"

"$(OUTDIR)\snapvw.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
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
!IF EXISTS("snapvw.dep")
!INCLUDE "snapvw.dep"
!ELSE 
!MESSAGE Warning: cannot find "snapvw.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Snap - Win32 Release" || "$(CFG)" == "Snap - Win32 Debug" || "$(CFG)" == "Snap - Win32 Unicode Release" || "$(CFG)" == "Snap - Win32 Unicode Debug"
SOURCE=.\BkfstPg.cpp

"$(INTDIR)\BkfstPg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\snapvw.pch"


SOURCE=.\ChildFrm.cpp

"$(INTDIR)\ChildFrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\snapvw.pch"


SOURCE=.\DinnerPg.cpp

"$(INTDIR)\DinnerPg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\snapvw.pch"


SOURCE=.\LunchPg.cpp

"$(INTDIR)\LunchPg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\snapvw.pch"


SOURCE=.\MainFrm.cpp

"$(INTDIR)\MainFrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\snapvw.pch"


SOURCE=.\SnapDoc.cpp

"$(INTDIR)\SnapDoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\snapvw.pch"


SOURCE=.\SnapPs.cpp

"$(INTDIR)\SnapPs.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\snapvw.pch"


SOURCE=.\SnapView.cpp

"$(INTDIR)\SnapView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\snapvw.pch"


SOURCE=.\snapvw.cpp

"$(INTDIR)\snapvw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\snapvw.pch"


SOURCE=.\snapvw.rc

"$(INTDIR)\snapvw.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "Snap - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\snapvw.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\snapvw.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Snap - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\snapvw.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\snapvw.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Snap - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D "_UNICODE" /Fp"$(INTDIR)\snapvw.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\snapvw.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Snap - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D "_UNICODE" /Fp"$(INTDIR)\snapvw.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\snapvw.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

