# Microsoft Developer Studio Generated NMAKE File, Based on hiersvr.dsp
!IF "$(CFG)" == ""
CFG=HierSvr - Win32 Release
!MESSAGE No configuration specified. Defaulting to HierSvr - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "HierSvr - Win32 Release" && "$(CFG)" != "HierSvr - Win32 Debug" && "$(CFG)" != "HierSvr - Win32 Unicode Debug" && "$(CFG)" != "HierSvr - Win32 Unicode Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "hiersvr.mak" CFG="HierSvr - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "HierSvr - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "HierSvr - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "HierSvr - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE "HierSvr - Win32 Unicode Release" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "HierSvr - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : ".\.\Release\hiersvr.HLP" "$(OUTDIR)\hiersvr.exe"


CLEAN :
	-@erase "$(INTDIR)\hiersvr.obj"
	-@erase "$(INTDIR)\hiersvr.pch"
	-@erase "$(INTDIR)\hiersvr.res"
	-@erase "$(INTDIR)\ipframe.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\svrdoc.obj"
	-@erase "$(INTDIR)\svritem.obj"
	-@erase "$(INTDIR)\svrview.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\zoomdlg.obj"
	-@erase "$(OUTDIR)\hiersvr.exe"
	-@erase ".\.\Release\hiersvr.HLP"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/Zc:wchar_t /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\hiersvr.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\hiersvr.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\hiersvr.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\hiersvr.pdb" /machine:I386 /out:"$(OUTDIR)\hiersvr.exe" 
LINK32_OBJS= \
	"$(INTDIR)\hiersvr.obj" \
	"$(INTDIR)\ipframe.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\svrdoc.obj" \
	"$(INTDIR)\svritem.obj" \
	"$(INTDIR)\svrview.obj" \
	"$(INTDIR)\zoomdlg.obj" \
	"$(INTDIR)\hiersvr.res"

"$(OUTDIR)\hiersvr.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "HierSvr - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : ".\.\Debug\hiersvr.HLP" "$(OUTDIR)\hiersvr.exe"


CLEAN :
	-@erase "$(INTDIR)\hiersvr.obj"
	-@erase "$(INTDIR)\hiersvr.pch"
	-@erase "$(INTDIR)\hiersvr.res"
	-@erase "$(INTDIR)\ipframe.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\svrdoc.obj"
	-@erase "$(INTDIR)\svritem.obj"
	-@erase "$(INTDIR)\svrview.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\zoomdlg.obj"
	-@erase "$(OUTDIR)\hiersvr.exe"
	-@erase "$(OUTDIR)\hiersvr.ilk"
	-@erase "$(OUTDIR)\hiersvr.pdb"
	-@erase ".\.\Debug\hiersvr.HLP"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/Zc:wchar_t /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\hiersvr.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\hiersvr.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\hiersvr.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\hiersvr.pdb" /debug /machine:I386 /out:"$(OUTDIR)\hiersvr.exe" 
LINK32_OBJS= \
	"$(INTDIR)\hiersvr.obj" \
	"$(INTDIR)\ipframe.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\svrdoc.obj" \
	"$(INTDIR)\svritem.obj" \
	"$(INTDIR)\svrview.obj" \
	"$(INTDIR)\zoomdlg.obj" \
	"$(INTDIR)\hiersvr.res"

"$(OUTDIR)\hiersvr.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "HierSvr - Win32 Unicode Debug"

OUTDIR=.\UniDebug
INTDIR=.\UniDebug
# Begin Custom Macros
OutDir=.\.\UniDebug
# End Custom Macros

ALL : ".\.\UniDebug\hiersvr.HLP" "$(OUTDIR)\hiersvr.exe"


CLEAN :
	-@erase "$(INTDIR)\hiersvr.obj"
	-@erase "$(INTDIR)\hiersvr.pch"
	-@erase "$(INTDIR)\hiersvr.res"
	-@erase "$(INTDIR)\ipframe.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\svrdoc.obj"
	-@erase "$(INTDIR)\svritem.obj"
	-@erase "$(INTDIR)\svrview.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\zoomdlg.obj"
	-@erase "$(OUTDIR)\hiersvr.exe"
	-@erase "$(OUTDIR)\hiersvr.ilk"
	-@erase "$(OUTDIR)\hiersvr.pdb"
	-@erase ".\.\UniDebug\hiersvr.HLP"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/Zc:wchar_t /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\hiersvr.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\hiersvr.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\hiersvr.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\hiersvr.pdb" /debug /machine:I386 /out:"$(OUTDIR)\hiersvr.exe" 
LINK32_OBJS= \
	"$(INTDIR)\hiersvr.obj" \
	"$(INTDIR)\ipframe.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\svrdoc.obj" \
	"$(INTDIR)\svritem.obj" \
	"$(INTDIR)\svrview.obj" \
	"$(INTDIR)\zoomdlg.obj" \
	"$(INTDIR)\hiersvr.res"

"$(OUTDIR)\hiersvr.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "HierSvr - Win32 Unicode Release"

OUTDIR=.\UniRelease
INTDIR=.\UniRelease
# Begin Custom Macros
OutDir=.\.\UniRelease
# End Custom Macros

ALL : ".\.\UniRelease\hiersvr.HLP" "$(OUTDIR)\hiersvr.exe"


CLEAN :
	-@erase "$(INTDIR)\hiersvr.obj"
	-@erase "$(INTDIR)\hiersvr.pch"
	-@erase "$(INTDIR)\hiersvr.res"
	-@erase "$(INTDIR)\ipframe.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\svrdoc.obj"
	-@erase "$(INTDIR)\svritem.obj"
	-@erase "$(INTDIR)\svrview.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\zoomdlg.obj"
	-@erase "$(OUTDIR)\hiersvr.exe"
	-@erase ".\.\UniRelease\hiersvr.HLP"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/Zc:wchar_t /MD /W3 /WX /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\hiersvr.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\hiersvr.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\hiersvr.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\hiersvr.pdb" /machine:I386 /out:"$(OUTDIR)\hiersvr.exe" 
LINK32_OBJS= \
	"$(INTDIR)\hiersvr.obj" \
	"$(INTDIR)\ipframe.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\svrdoc.obj" \
	"$(INTDIR)\svritem.obj" \
	"$(INTDIR)\svrview.obj" \
	"$(INTDIR)\zoomdlg.obj" \
	"$(INTDIR)\hiersvr.res"

"$(OUTDIR)\hiersvr.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("hiersvr.dep")
!INCLUDE "hiersvr.dep"
!ELSE 
!MESSAGE Warning: cannot find "hiersvr.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "HierSvr - Win32 Release" || "$(CFG)" == "HierSvr - Win32 Debug" || "$(CFG)" == "HierSvr - Win32 Unicode Debug" || "$(CFG)" == "HierSvr - Win32 Unicode Release"
SOURCE=.\hiersvr.cpp

"$(INTDIR)\hiersvr.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\hiersvr.pch"


SOURCE=.\hlp\hiersvr.hpj

!IF  "$(CFG)" == "HierSvr - Win32 Release"

OutDir=.\.\Release
ProjDir=.
TargetName=hiersvr
InputPath=.\hlp\hiersvr.hpj

"$(OutDir)\$(TargetName).HLP"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	"$(ProjDir)\makehelp.bat"
<< 
	

!ELSEIF  "$(CFG)" == "HierSvr - Win32 Debug"

OutDir=.\.\Debug
ProjDir=.
TargetName=hiersvr
InputPath=.\hlp\hiersvr.hpj

"$(OutDir)\$(TargetName).HLP"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	"$(ProjDir)\makehelp.bat"
<< 
	

!ELSEIF  "$(CFG)" == "HierSvr - Win32 Unicode Debug"

OutDir=.\.\UniDebug
ProjDir=.
TargetName=hiersvr
InputPath=.\hlp\hiersvr.hpj

"$(OutDir)\$(TargetName).HLP"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	"$(ProjDir)\makehelp.bat"
<< 
	

!ELSEIF  "$(CFG)" == "HierSvr - Win32 Unicode Release"

OutDir=.\.\UniRelease
ProjDir=.
TargetName=hiersvr
InputPath=.\hlp\hiersvr.hpj

"$(OutDir)\$(TargetName).HLP"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	"$(ProjDir)\makehelp.bat"
<< 
	

!ENDIF 

SOURCE=.\hiersvr.rc

"$(INTDIR)\hiersvr.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\ipframe.cpp

"$(INTDIR)\ipframe.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\hiersvr.pch"


SOURCE=.\mainfrm.cpp

"$(INTDIR)\mainfrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\hiersvr.pch"


SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "HierSvr - Win32 Release"

CPP_SWITCHES=/Zc:wchar_t /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\hiersvr.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\hiersvr.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "HierSvr - Win32 Debug"

CPP_SWITCHES=/Zc:wchar_t /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\hiersvr.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\hiersvr.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "HierSvr - Win32 Unicode Debug"

CPP_SWITCHES=/Zc:wchar_t /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\hiersvr.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\hiersvr.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "HierSvr - Win32 Unicode Release"

CPP_SWITCHES=/Zc:wchar_t /MD /W3 /WX /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\hiersvr.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\hiersvr.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\svrdoc.cpp

"$(INTDIR)\svrdoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\hiersvr.pch"


SOURCE=.\svritem.cpp

!IF  "$(CFG)" == "HierSvr - Win32 Release"

CPP_SWITCHES=/Zc:wchar_t /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\hiersvr.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\svritem.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\hiersvr.pch"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "HierSvr - Win32 Debug"

CPP_SWITCHES=/Zc:wchar_t /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\hiersvr.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\svritem.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\hiersvr.pch"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "HierSvr - Win32 Unicode Debug"

CPP_SWITCHES=/Zc:wchar_t /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\hiersvr.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\svritem.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\hiersvr.pch"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "HierSvr - Win32 Unicode Release"

CPP_SWITCHES=/Zc:wchar_t /MD /W3 /WX /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\hiersvr.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\svritem.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\hiersvr.pch"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\svrview.cpp

!IF  "$(CFG)" == "HierSvr - Win32 Release"

CPP_SWITCHES=/Zc:wchar_t /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\hiersvr.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\svrview.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\hiersvr.pch"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "HierSvr - Win32 Debug"

CPP_SWITCHES=/Zc:wchar_t /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\hiersvr.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\svrview.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\hiersvr.pch"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "HierSvr - Win32 Unicode Debug"

CPP_SWITCHES=/Zc:wchar_t /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\hiersvr.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\svrview.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\hiersvr.pch"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "HierSvr - Win32 Unicode Release"

CPP_SWITCHES=/Zc:wchar_t /MD /W3 /WX /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\hiersvr.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\svrview.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\hiersvr.pch"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\zoomdlg.cpp

"$(INTDIR)\zoomdlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\hiersvr.pch"



!ENDIF 

