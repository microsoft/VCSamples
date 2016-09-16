# Microsoft Developer Studio Generated NMAKE File, Based on drawcli.dsp
!IF "$(CFG)" == ""
CFG=DrawCli - Win32 Release
!MESSAGE No configuration specified. Defaulting to DrawCli - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "DrawCli - Win32 Release" && "$(CFG)" != "DrawCli - Win32 Debug" && "$(CFG)" != "DrawCli - Win32 Unicode Release" && "$(CFG)" != "DrawCli - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "drawcli.mak" CFG="DrawCli - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DrawCli - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "DrawCli - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "DrawCli - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "DrawCli - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "DrawCli - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\drawcli.exe"


CLEAN :
	-@erase "$(INTDIR)\cntritem.obj"
	-@erase "$(INTDIR)\drawcli.obj"
	-@erase "$(INTDIR)\drawcli.res"
	-@erase "$(INTDIR)\drawdoc.obj"
	-@erase "$(INTDIR)\drawobj.obj"
	-@erase "$(INTDIR)\drawtool.obj"
	-@erase "$(INTDIR)\drawvw.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\propset.obj"
	-@erase "$(INTDIR)\rectdlg.obj"
	-@erase "$(INTDIR)\splitfrm.obj"
	-@erase "$(INTDIR)\statpage.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\stdafx.pch"
	-@erase "$(INTDIR)\summinfo.obj"
	-@erase "$(INTDIR)\summpage.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\drawcli.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\stdafx.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\drawcli.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\drawcli.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\drawcli.pdb" /machine:I386 /out:"$(OUTDIR)\drawcli.exe" 
LINK32_OBJS= \
	"$(INTDIR)\cntritem.obj" \
	"$(INTDIR)\drawcli.obj" \
	"$(INTDIR)\drawdoc.obj" \
	"$(INTDIR)\drawobj.obj" \
	"$(INTDIR)\drawtool.obj" \
	"$(INTDIR)\drawvw.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\propset.obj" \
	"$(INTDIR)\rectdlg.obj" \
	"$(INTDIR)\splitfrm.obj" \
	"$(INTDIR)\statpage.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\summinfo.obj" \
	"$(INTDIR)\summpage.obj" \
	"$(INTDIR)\drawcli.res"

"$(OUTDIR)\drawcli.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "DrawCli - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\drawcli.exe"


CLEAN :
	-@erase "$(INTDIR)\cntritem.obj"
	-@erase "$(INTDIR)\drawcli.obj"
	-@erase "$(INTDIR)\drawcli.res"
	-@erase "$(INTDIR)\drawdoc.obj"
	-@erase "$(INTDIR)\drawobj.obj"
	-@erase "$(INTDIR)\drawtool.obj"
	-@erase "$(INTDIR)\drawvw.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\propset.obj"
	-@erase "$(INTDIR)\rectdlg.obj"
	-@erase "$(INTDIR)\splitfrm.obj"
	-@erase "$(INTDIR)\statpage.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\stdafx.pch"
	-@erase "$(INTDIR)\summinfo.obj"
	-@erase "$(INTDIR)\summpage.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\drawcli.exe"
	-@erase "$(OUTDIR)\drawcli.ilk"
	-@erase "$(OUTDIR)\drawcli.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\stdafx.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\drawcli.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\drawcli.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\drawcli.pdb" /debug /machine:I386 /out:"$(OUTDIR)\drawcli.exe" 
LINK32_OBJS= \
	"$(INTDIR)\cntritem.obj" \
	"$(INTDIR)\drawcli.obj" \
	"$(INTDIR)\drawdoc.obj" \
	"$(INTDIR)\drawobj.obj" \
	"$(INTDIR)\drawtool.obj" \
	"$(INTDIR)\drawvw.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\propset.obj" \
	"$(INTDIR)\rectdlg.obj" \
	"$(INTDIR)\splitfrm.obj" \
	"$(INTDIR)\statpage.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\summinfo.obj" \
	"$(INTDIR)\summpage.obj" \
	"$(INTDIR)\drawcli.res"

"$(OUTDIR)\drawcli.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "DrawCli - Win32 Unicode Release"

OUTDIR=.\UniRelease
INTDIR=.\UniRelease
# Begin Custom Macros
OutDir=.\UniRelease
# End Custom Macros

ALL : "$(OUTDIR)\drawcli.exe"


CLEAN :
	-@erase "$(INTDIR)\cntritem.obj"
	-@erase "$(INTDIR)\drawcli.obj"
	-@erase "$(INTDIR)\drawcli.res"
	-@erase "$(INTDIR)\drawdoc.obj"
	-@erase "$(INTDIR)\drawobj.obj"
	-@erase "$(INTDIR)\drawtool.obj"
	-@erase "$(INTDIR)\drawvw.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\propset.obj"
	-@erase "$(INTDIR)\rectdlg.obj"
	-@erase "$(INTDIR)\splitfrm.obj"
	-@erase "$(INTDIR)\statpage.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\summinfo.obj"
	-@erase "$(INTDIR)\summpage.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\drawcli.exe"
	-@erase ".\UniRel\stdafx.pch"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D "_UNICODE" /Fp".\UniRel\stdafx.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\drawcli.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\drawcli.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\drawcli.pdb" /machine:I386 /out:"$(OUTDIR)\drawcli.exe" 
LINK32_OBJS= \
	"$(INTDIR)\cntritem.obj" \
	"$(INTDIR)\drawcli.obj" \
	"$(INTDIR)\drawdoc.obj" \
	"$(INTDIR)\drawobj.obj" \
	"$(INTDIR)\drawtool.obj" \
	"$(INTDIR)\drawvw.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\propset.obj" \
	"$(INTDIR)\rectdlg.obj" \
	"$(INTDIR)\splitfrm.obj" \
	"$(INTDIR)\statpage.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\summinfo.obj" \
	"$(INTDIR)\summpage.obj" \
	"$(INTDIR)\drawcli.res"

"$(OUTDIR)\drawcli.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "DrawCli - Win32 Unicode Debug"

OUTDIR=.\UniDebug
INTDIR=.\UniDebug
# Begin Custom Macros
OutDir=.\UniDebug
# End Custom Macros

ALL : "$(OUTDIR)\drawcli.exe"


CLEAN :
	-@erase "$(INTDIR)\cntritem.obj"
	-@erase "$(INTDIR)\drawcli.obj"
	-@erase "$(INTDIR)\drawcli.res"
	-@erase "$(INTDIR)\drawdoc.obj"
	-@erase "$(INTDIR)\drawobj.obj"
	-@erase "$(INTDIR)\drawtool.obj"
	-@erase "$(INTDIR)\drawvw.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\propset.obj"
	-@erase "$(INTDIR)\rectdlg.obj"
	-@erase "$(INTDIR)\splitfrm.obj"
	-@erase "$(INTDIR)\statpage.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\stdafx.pch"
	-@erase "$(INTDIR)\summinfo.obj"
	-@erase "$(INTDIR)\summpage.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\drawcli.exe"
	-@erase "$(OUTDIR)\drawcli.ilk"
	-@erase "$(OUTDIR)\drawcli.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D "_UNICODE" /Fp"$(INTDIR)\stdafx.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\drawcli.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\drawcli.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\drawcli.pdb" /debug /machine:I386 /out:"$(OUTDIR)\drawcli.exe" 
LINK32_OBJS= \
	"$(INTDIR)\cntritem.obj" \
	"$(INTDIR)\drawcli.obj" \
	"$(INTDIR)\drawdoc.obj" \
	"$(INTDIR)\drawobj.obj" \
	"$(INTDIR)\drawtool.obj" \
	"$(INTDIR)\drawvw.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\propset.obj" \
	"$(INTDIR)\rectdlg.obj" \
	"$(INTDIR)\splitfrm.obj" \
	"$(INTDIR)\statpage.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\summinfo.obj" \
	"$(INTDIR)\summpage.obj" \
	"$(INTDIR)\drawcli.res"

"$(OUTDIR)\drawcli.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("drawcli.dep")
!INCLUDE "drawcli.dep"
!ELSE 
!MESSAGE Warning: cannot find "drawcli.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "DrawCli - Win32 Release" || "$(CFG)" == "DrawCli - Win32 Debug" || "$(CFG)" == "DrawCli - Win32 Unicode Release" || "$(CFG)" == "DrawCli - Win32 Unicode Debug"
SOURCE=.\cntritem.cpp

"$(INTDIR)\cntritem.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\stdafx.pch"


SOURCE=.\drawcli.cpp

"$(INTDIR)\drawcli.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\stdafx.pch"


SOURCE=.\drawcli.rc

"$(INTDIR)\drawcli.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\drawdoc.cpp

"$(INTDIR)\drawdoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\stdafx.pch"


SOURCE=.\drawobj.cpp

"$(INTDIR)\drawobj.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\stdafx.pch"


SOURCE=.\drawtool.cpp

"$(INTDIR)\drawtool.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\stdafx.pch"


SOURCE=.\drawvw.cpp

"$(INTDIR)\drawvw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\stdafx.pch"


SOURCE=.\mainfrm.cpp

"$(INTDIR)\mainfrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\stdafx.pch"


SOURCE=.\propset.cpp

"$(INTDIR)\propset.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\stdafx.pch"


SOURCE=.\rectdlg.cpp

"$(INTDIR)\rectdlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\stdafx.pch"


SOURCE=.\splitfrm.cpp

"$(INTDIR)\splitfrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\stdafx.pch"


SOURCE=.\statpage.cpp

"$(INTDIR)\statpage.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\stdafx.pch"


SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "DrawCli - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\stdafx.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DrawCli - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\stdafx.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DrawCli - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D "_UNICODE" /Fp".\UniRel\stdafx.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	".\UniRel\stdafx.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DrawCli - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D "_UNICODE" /Fp"$(INTDIR)\stdafx.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\summinfo.cpp

"$(INTDIR)\summinfo.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\stdafx.pch"


SOURCE=.\summpage.cpp

"$(INTDIR)\summpage.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\stdafx.pch"



!ENDIF 

