# Microsoft Developer Studio Generated NMAKE File, Based on docktool.dsp
!IF "$(CFG)" == ""
CFG=DockTool - Win32 Release
!MESSAGE No configuration specified. Defaulting to DockTool - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "DockTool - Win32 Release" && "$(CFG)" != "DockTool - Win32 Debug" && "$(CFG)" != "DockTool - Win32 Unicode Release" && "$(CFG)" != "DockTool - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "docktool.mak" CFG="DockTool - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DockTool - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "DockTool - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "DockTool - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "DockTool - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "DockTool - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\docktool.exe"


CLEAN :
	-@erase "$(INTDIR)\dockdoc.obj"
	-@erase "$(INTDIR)\docktool.obj"
	-@erase "$(INTDIR)\docktool.pch"
	-@erase "$(INTDIR)\docktool.res"
	-@erase "$(INTDIR)\dockvw.obj"
	-@erase "$(INTDIR)\editbar.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\palette.obj"
	-@erase "$(INTDIR)\searchbx.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\tooldlg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\docktool.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\docktool.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\docktool.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\docktool.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\docktool.pdb" /machine:I386 /out:"$(OUTDIR)\docktool.exe" 
LINK32_OBJS= \
	"$(INTDIR)\dockdoc.obj" \
	"$(INTDIR)\docktool.obj" \
	"$(INTDIR)\dockvw.obj" \
	"$(INTDIR)\editbar.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\palette.obj" \
	"$(INTDIR)\searchbx.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\tooldlg.obj" \
	"$(INTDIR)\docktool.res"

"$(OUTDIR)\docktool.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "DockTool - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\docktool.exe"


CLEAN :
	-@erase "$(INTDIR)\dockdoc.obj"
	-@erase "$(INTDIR)\docktool.obj"
	-@erase "$(INTDIR)\docktool.pch"
	-@erase "$(INTDIR)\docktool.res"
	-@erase "$(INTDIR)\dockvw.obj"
	-@erase "$(INTDIR)\editbar.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\palette.obj"
	-@erase "$(INTDIR)\searchbx.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\tooldlg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\docktool.exe"
	-@erase "$(OUTDIR)\docktool.ilk"
	-@erase "$(OUTDIR)\docktool.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\docktool.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\docktool.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\docktool.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\docktool.pdb" /debug /machine:I386 /out:"$(OUTDIR)\docktool.exe" 
LINK32_OBJS= \
	"$(INTDIR)\dockdoc.obj" \
	"$(INTDIR)\docktool.obj" \
	"$(INTDIR)\dockvw.obj" \
	"$(INTDIR)\editbar.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\palette.obj" \
	"$(INTDIR)\searchbx.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\tooldlg.obj" \
	"$(INTDIR)\docktool.res"

"$(OUTDIR)\docktool.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "DockTool - Win32 Unicode Release"

OUTDIR=.\UniRelease
INTDIR=.\UniRelease
# Begin Custom Macros
OutDir=.\UniRelease
# End Custom Macros

ALL : "$(OUTDIR)\docktool.exe"


CLEAN :
	-@erase "$(INTDIR)\dockdoc.obj"
	-@erase "$(INTDIR)\docktool.obj"
	-@erase "$(INTDIR)\docktool.pch"
	-@erase "$(INTDIR)\docktool.res"
	-@erase "$(INTDIR)\dockvw.obj"
	-@erase "$(INTDIR)\editbar.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\palette.obj"
	-@erase "$(INTDIR)\searchbx.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\tooldlg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\docktool.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\docktool.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\docktool.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\docktool.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\docktool.pdb" /machine:I386 /out:"$(OUTDIR)\docktool.exe" 
LINK32_OBJS= \
	"$(INTDIR)\dockdoc.obj" \
	"$(INTDIR)\docktool.obj" \
	"$(INTDIR)\dockvw.obj" \
	"$(INTDIR)\editbar.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\palette.obj" \
	"$(INTDIR)\searchbx.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\tooldlg.obj" \
	"$(INTDIR)\docktool.res"

"$(OUTDIR)\docktool.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "DockTool - Win32 Unicode Debug"

OUTDIR=.\UniDebug
INTDIR=.\UniDebug
# Begin Custom Macros
OutDir=.\UniDebug
# End Custom Macros

ALL : "$(OUTDIR)\docktool.exe"


CLEAN :
	-@erase "$(INTDIR)\dockdoc.obj"
	-@erase "$(INTDIR)\docktool.obj"
	-@erase "$(INTDIR)\docktool.pch"
	-@erase "$(INTDIR)\docktool.res"
	-@erase "$(INTDIR)\dockvw.obj"
	-@erase "$(INTDIR)\editbar.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\palette.obj"
	-@erase "$(INTDIR)\searchbx.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\tooldlg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\docktool.exe"
	-@erase "$(OUTDIR)\docktool.ilk"
	-@erase "$(OUTDIR)\docktool.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\docktool.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\docktool.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\docktool.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\docktool.pdb" /debug /machine:I386 /out:"$(OUTDIR)\docktool.exe" 
LINK32_OBJS= \
	"$(INTDIR)\dockdoc.obj" \
	"$(INTDIR)\docktool.obj" \
	"$(INTDIR)\dockvw.obj" \
	"$(INTDIR)\editbar.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\palette.obj" \
	"$(INTDIR)\searchbx.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\tooldlg.obj" \
	"$(INTDIR)\docktool.res"

"$(OUTDIR)\docktool.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("docktool.dep")
!INCLUDE "docktool.dep"
!ELSE 
!MESSAGE Warning: cannot find "docktool.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "DockTool - Win32 Release" || "$(CFG)" == "DockTool - Win32 Debug" || "$(CFG)" == "DockTool - Win32 Unicode Release" || "$(CFG)" == "DockTool - Win32 Unicode Debug"
SOURCE=.\dockdoc.cpp

"$(INTDIR)\dockdoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\docktool.pch"


SOURCE=.\docktool.cpp

"$(INTDIR)\docktool.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\docktool.pch"


SOURCE=.\docktool.rc

"$(INTDIR)\docktool.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\dockvw.cpp

"$(INTDIR)\dockvw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\docktool.pch"


SOURCE=.\editbar.cpp

"$(INTDIR)\editbar.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\docktool.pch"


SOURCE=.\mainfrm.cpp

"$(INTDIR)\mainfrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\docktool.pch"


SOURCE=.\palette.cpp

"$(INTDIR)\palette.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\docktool.pch"


SOURCE=.\searchbx.cpp

"$(INTDIR)\searchbx.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\docktool.pch"


SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "DockTool - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\docktool.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\docktool.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DockTool - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\docktool.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\docktool.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DockTool - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\docktool.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\docktool.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DockTool - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\docktool.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\docktool.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\tooldlg.cpp

"$(INTDIR)\tooldlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\docktool.pch"



!ENDIF 

