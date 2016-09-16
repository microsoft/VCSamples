# Microsoft Developer Studio Generated NMAKE File, Based on superpad.dsp
!IF "$(CFG)" == ""
CFG=SuperPad - Win32 Release
!MESSAGE No configuration specified. Defaulting to SuperPad - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "SuperPad - Win32 Release" && "$(CFG)" != "SuperPad - Win32 Debug" && "$(CFG)" != "SuperPad - Win32 Unicode Debug" && "$(CFG)" != "SuperPad - Win32 Unicode Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "superpad.mak" CFG="SuperPad - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SuperPad - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "SuperPad - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "SuperPad - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE "SuperPad - Win32 Unicode Release" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "SuperPad - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\superpad.exe"


CLEAN :
	-@erase "$(INTDIR)\aboutbox.obj"
	-@erase "$(INTDIR)\ipframe.obj"
	-@erase "$(INTDIR)\linkitem.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\paddoc.obj"
	-@erase "$(INTDIR)\padframe.obj"
	-@erase "$(INTDIR)\paditem.obj"
	-@erase "$(INTDIR)\padview.obj"
	-@erase "$(INTDIR)\pageset.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\superpad.obj"
	-@erase "$(INTDIR)\superpad.pch"
	-@erase "$(INTDIR)\superpad.res"
	-@erase "$(INTDIR)\tabstop.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\superpad.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\superpad.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\superpad.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\superpad.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\superpad.pdb" /machine:I386 /out:"$(OUTDIR)\superpad.exe" 
LINK32_OBJS= \
	"$(INTDIR)\aboutbox.obj" \
	"$(INTDIR)\ipframe.obj" \
	"$(INTDIR)\linkitem.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\paddoc.obj" \
	"$(INTDIR)\padframe.obj" \
	"$(INTDIR)\paditem.obj" \
	"$(INTDIR)\padview.obj" \
	"$(INTDIR)\pageset.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\superpad.obj" \
	"$(INTDIR)\tabstop.obj" \
	"$(INTDIR)\superpad.res"

"$(OUTDIR)\superpad.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "SuperPad - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\superpad.exe"


CLEAN :
	-@erase "$(INTDIR)\aboutbox.obj"
	-@erase "$(INTDIR)\ipframe.obj"
	-@erase "$(INTDIR)\linkitem.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\paddoc.obj"
	-@erase "$(INTDIR)\padframe.obj"
	-@erase "$(INTDIR)\paditem.obj"
	-@erase "$(INTDIR)\padview.obj"
	-@erase "$(INTDIR)\pageset.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\superpad.obj"
	-@erase "$(INTDIR)\superpad.pch"
	-@erase "$(INTDIR)\superpad.res"
	-@erase "$(INTDIR)\tabstop.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\superpad.exe"
	-@erase "$(OUTDIR)\superpad.ilk"
	-@erase "$(OUTDIR)\superpad.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\superpad.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\superpad.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\superpad.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\superpad.pdb" /debug /machine:I386 /out:"$(OUTDIR)\superpad.exe" 
LINK32_OBJS= \
	"$(INTDIR)\aboutbox.obj" \
	"$(INTDIR)\ipframe.obj" \
	"$(INTDIR)\linkitem.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\paddoc.obj" \
	"$(INTDIR)\padframe.obj" \
	"$(INTDIR)\paditem.obj" \
	"$(INTDIR)\padview.obj" \
	"$(INTDIR)\pageset.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\superpad.obj" \
	"$(INTDIR)\tabstop.obj" \
	"$(INTDIR)\superpad.res"

"$(OUTDIR)\superpad.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "SuperPad - Win32 Unicode Debug"

OUTDIR=.\UniDebug
INTDIR=.\UniDebug
# Begin Custom Macros
OutDir=.\.\UniDebug
# End Custom Macros

ALL : "$(OUTDIR)\superpad.exe"


CLEAN :
	-@erase "$(INTDIR)\aboutbox.obj"
	-@erase "$(INTDIR)\ipframe.obj"
	-@erase "$(INTDIR)\linkitem.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\paddoc.obj"
	-@erase "$(INTDIR)\padframe.obj"
	-@erase "$(INTDIR)\paditem.obj"
	-@erase "$(INTDIR)\padview.obj"
	-@erase "$(INTDIR)\pageset.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\superpad.obj"
	-@erase "$(INTDIR)\superpad.pch"
	-@erase "$(INTDIR)\superpad.res"
	-@erase "$(INTDIR)\tabstop.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\superpad.exe"
	-@erase "$(OUTDIR)\superpad.ilk"
	-@erase "$(OUTDIR)\superpad.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\superpad.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\superpad.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\superpad.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\superpad.pdb" /debug /machine:I386 /out:"$(OUTDIR)\superpad.exe" 
LINK32_OBJS= \
	"$(INTDIR)\aboutbox.obj" \
	"$(INTDIR)\ipframe.obj" \
	"$(INTDIR)\linkitem.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\paddoc.obj" \
	"$(INTDIR)\padframe.obj" \
	"$(INTDIR)\paditem.obj" \
	"$(INTDIR)\padview.obj" \
	"$(INTDIR)\pageset.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\superpad.obj" \
	"$(INTDIR)\tabstop.obj" \
	"$(INTDIR)\superpad.res"

"$(OUTDIR)\superpad.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "SuperPad - Win32 Unicode Release"

OUTDIR=.\UniRelease
INTDIR=.\UniRelease
# Begin Custom Macros
OutDir=.\.\UniRelease
# End Custom Macros

ALL : "$(OUTDIR)\superpad.exe"


CLEAN :
	-@erase "$(INTDIR)\aboutbox.obj"
	-@erase "$(INTDIR)\ipframe.obj"
	-@erase "$(INTDIR)\linkitem.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\paddoc.obj"
	-@erase "$(INTDIR)\padframe.obj"
	-@erase "$(INTDIR)\paditem.obj"
	-@erase "$(INTDIR)\padview.obj"
	-@erase "$(INTDIR)\pageset.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\superpad.obj"
	-@erase "$(INTDIR)\superpad.pch"
	-@erase "$(INTDIR)\superpad.res"
	-@erase "$(INTDIR)\tabstop.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\superpad.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\superpad.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\superpad.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\superpad.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\superpad.pdb" /machine:I386 /out:"$(OUTDIR)\superpad.exe" 
LINK32_OBJS= \
	"$(INTDIR)\aboutbox.obj" \
	"$(INTDIR)\ipframe.obj" \
	"$(INTDIR)\linkitem.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\paddoc.obj" \
	"$(INTDIR)\padframe.obj" \
	"$(INTDIR)\paditem.obj" \
	"$(INTDIR)\padview.obj" \
	"$(INTDIR)\pageset.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\superpad.obj" \
	"$(INTDIR)\tabstop.obj" \
	"$(INTDIR)\superpad.res"

"$(OUTDIR)\superpad.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("superpad.dep")
!INCLUDE "superpad.dep"
!ELSE 
!MESSAGE Warning: cannot find "superpad.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "SuperPad - Win32 Release" || "$(CFG)" == "SuperPad - Win32 Debug" || "$(CFG)" == "SuperPad - Win32 Unicode Debug" || "$(CFG)" == "SuperPad - Win32 Unicode Release"
SOURCE=.\aboutbox.cpp

"$(INTDIR)\aboutbox.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\superpad.pch"


SOURCE=.\ipframe.cpp

"$(INTDIR)\ipframe.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\superpad.pch"


SOURCE=.\linkitem.cpp

"$(INTDIR)\linkitem.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\superpad.pch"


SOURCE=.\mainfrm.cpp

"$(INTDIR)\mainfrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\superpad.pch"


SOURCE=.\paddoc.cpp

"$(INTDIR)\paddoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\superpad.pch"


SOURCE=.\padframe.cpp

"$(INTDIR)\padframe.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\superpad.pch"


SOURCE=.\paditem.cpp

"$(INTDIR)\paditem.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\superpad.pch"


SOURCE=.\padview.cpp

"$(INTDIR)\padview.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\superpad.pch"


SOURCE=.\pageset.cpp

"$(INTDIR)\pageset.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\superpad.pch"


SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "SuperPad - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\superpad.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\superpad.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SuperPad - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\superpad.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\superpad.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SuperPad - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\superpad.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\superpad.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SuperPad - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\superpad.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\superpad.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\superpad.cpp

"$(INTDIR)\superpad.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\superpad.pch"


SOURCE=.\superpad.rc

"$(INTDIR)\superpad.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\tabstop.cpp

"$(INTDIR)\tabstop.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\superpad.pch"



!ENDIF 

