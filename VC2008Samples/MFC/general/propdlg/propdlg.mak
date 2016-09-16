# Microsoft Developer Studio Generated NMAKE File, Based on propdlg.dsp
!IF "$(CFG)" == ""
CFG=PropDlg - Win32 Release
!MESSAGE No configuration specified. Defaulting to PropDlg - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "PropDlg - Win32 Release" && "$(CFG)" != "PropDlg - Win32 Debug" && "$(CFG)" != "PropDlg - Win32 Unicode Release" && "$(CFG)" != "PropDlg - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "propdlg.mak" CFG="PropDlg - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PropDlg - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "PropDlg - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "PropDlg - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "PropDlg - Win32 Unicode Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "PropDlg - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\propdlg.exe"


CLEAN :
	-@erase "$(INTDIR)\Colorpge.obj"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Minifrm.obj"
	-@erase "$(INTDIR)\Preview.obj"
	-@erase "$(INTDIR)\Propdlg.obj"
	-@erase "$(INTDIR)\propdlg.pch"
	-@erase "$(INTDIR)\Propdlg.res"
	-@erase "$(INTDIR)\Propsht.obj"
	-@erase "$(INTDIR)\Propsht2.obj"
	-@erase "$(INTDIR)\Shapedoc.obj"
	-@erase "$(INTDIR)\Shapeobj.obj"
	-@erase "$(INTDIR)\Shapesvw.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\Stylepge.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\propdlg.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\propdlg.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Propdlg.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\propdlg.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\propdlg.pdb" /machine:I386 /out:"$(OUTDIR)\propdlg.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Colorpge.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Minifrm.obj" \
	"$(INTDIR)\Preview.obj" \
	"$(INTDIR)\Propdlg.obj" \
	"$(INTDIR)\Propsht.obj" \
	"$(INTDIR)\Propsht2.obj" \
	"$(INTDIR)\Shapedoc.obj" \
	"$(INTDIR)\Shapeobj.obj" \
	"$(INTDIR)\Shapesvw.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Stylepge.obj" \
	"$(INTDIR)\Propdlg.res"

"$(OUTDIR)\propdlg.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "PropDlg - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\propdlg.exe"


CLEAN :
	-@erase "$(INTDIR)\Colorpge.obj"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Minifrm.obj"
	-@erase "$(INTDIR)\Preview.obj"
	-@erase "$(INTDIR)\Propdlg.obj"
	-@erase "$(INTDIR)\propdlg.pch"
	-@erase "$(INTDIR)\Propdlg.res"
	-@erase "$(INTDIR)\Propsht.obj"
	-@erase "$(INTDIR)\Propsht2.obj"
	-@erase "$(INTDIR)\Shapedoc.obj"
	-@erase "$(INTDIR)\Shapeobj.obj"
	-@erase "$(INTDIR)\Shapesvw.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\Stylepge.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\propdlg.exe"
	-@erase "$(OUTDIR)\propdlg.ilk"
	-@erase "$(OUTDIR)\propdlg.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\propdlg.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Propdlg.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\propdlg.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\propdlg.pdb" /debug /machine:I386 /out:"$(OUTDIR)\propdlg.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Colorpge.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Minifrm.obj" \
	"$(INTDIR)\Preview.obj" \
	"$(INTDIR)\Propdlg.obj" \
	"$(INTDIR)\Propsht.obj" \
	"$(INTDIR)\Propsht2.obj" \
	"$(INTDIR)\Shapedoc.obj" \
	"$(INTDIR)\Shapeobj.obj" \
	"$(INTDIR)\Shapesvw.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Stylepge.obj" \
	"$(INTDIR)\Propdlg.res"

"$(OUTDIR)\propdlg.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "PropDlg - Win32 Unicode Release"

OUTDIR=.\UniRelease
INTDIR=.\UniRelease
# Begin Custom Macros
OutDir=.\.\UniRelease
# End Custom Macros

ALL : "$(OUTDIR)\propdlg.exe"


CLEAN :
	-@erase "$(INTDIR)\Colorpge.obj"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Minifrm.obj"
	-@erase "$(INTDIR)\Preview.obj"
	-@erase "$(INTDIR)\Propdlg.obj"
	-@erase "$(INTDIR)\propdlg.pch"
	-@erase "$(INTDIR)\Propdlg.res"
	-@erase "$(INTDIR)\Propsht.obj"
	-@erase "$(INTDIR)\Propsht2.obj"
	-@erase "$(INTDIR)\Shapedoc.obj"
	-@erase "$(INTDIR)\Shapeobj.obj"
	-@erase "$(INTDIR)\Shapesvw.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\Stylepge.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\propdlg.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\propdlg.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Propdlg.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\propdlg.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\propdlg.pdb" /machine:I386 /out:"$(OUTDIR)\propdlg.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Colorpge.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Minifrm.obj" \
	"$(INTDIR)\Preview.obj" \
	"$(INTDIR)\Propdlg.obj" \
	"$(INTDIR)\Propsht.obj" \
	"$(INTDIR)\Propsht2.obj" \
	"$(INTDIR)\Shapedoc.obj" \
	"$(INTDIR)\Shapeobj.obj" \
	"$(INTDIR)\Shapesvw.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Stylepge.obj" \
	"$(INTDIR)\Propdlg.res"

"$(OUTDIR)\propdlg.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "PropDlg - Win32 Unicode Debug"

OUTDIR=.\UniDebug
INTDIR=.\UniDebug
# Begin Custom Macros
OutDir=.\.\UniDebug
# End Custom Macros

ALL : "$(OUTDIR)\propdlg.exe"


CLEAN :
	-@erase "$(INTDIR)\Colorpge.obj"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Minifrm.obj"
	-@erase "$(INTDIR)\Preview.obj"
	-@erase "$(INTDIR)\Propdlg.obj"
	-@erase "$(INTDIR)\propdlg.pch"
	-@erase "$(INTDIR)\Propdlg.res"
	-@erase "$(INTDIR)\Propsht.obj"
	-@erase "$(INTDIR)\Propsht2.obj"
	-@erase "$(INTDIR)\Shapedoc.obj"
	-@erase "$(INTDIR)\Shapeobj.obj"
	-@erase "$(INTDIR)\Shapesvw.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\Stylepge.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\propdlg.exe"
	-@erase "$(OUTDIR)\propdlg.ilk"
	-@erase "$(OUTDIR)\propdlg.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\propdlg.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Propdlg.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\propdlg.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\propdlg.pdb" /debug /machine:I386 /out:"$(OUTDIR)\propdlg.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Colorpge.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Minifrm.obj" \
	"$(INTDIR)\Preview.obj" \
	"$(INTDIR)\Propdlg.obj" \
	"$(INTDIR)\Propsht.obj" \
	"$(INTDIR)\Propsht2.obj" \
	"$(INTDIR)\Shapedoc.obj" \
	"$(INTDIR)\Shapeobj.obj" \
	"$(INTDIR)\Shapesvw.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Stylepge.obj" \
	"$(INTDIR)\Propdlg.res"

"$(OUTDIR)\propdlg.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("propdlg.dep")
!INCLUDE "propdlg.dep"
!ELSE 
!MESSAGE Warning: cannot find "propdlg.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "PropDlg - Win32 Release" || "$(CFG)" == "PropDlg - Win32 Debug" || "$(CFG)" == "PropDlg - Win32 Unicode Release" || "$(CFG)" == "PropDlg - Win32 Unicode Debug"
SOURCE=.\Colorpge.cpp

"$(INTDIR)\Colorpge.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\propdlg.pch"


SOURCE=.\Mainfrm.cpp

"$(INTDIR)\Mainfrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\propdlg.pch"


SOURCE=.\Minifrm.cpp

"$(INTDIR)\Minifrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\propdlg.pch"


SOURCE=.\Preview.cpp

"$(INTDIR)\Preview.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\propdlg.pch"


SOURCE=.\Propdlg.cpp

"$(INTDIR)\Propdlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\propdlg.pch"


SOURCE=.\Propdlg.rc

"$(INTDIR)\Propdlg.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\Propsht.cpp

"$(INTDIR)\Propsht.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\propdlg.pch"


SOURCE=.\Propsht2.cpp

"$(INTDIR)\Propsht2.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\propdlg.pch"


SOURCE=.\Shapedoc.cpp

"$(INTDIR)\Shapedoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\propdlg.pch"


SOURCE=.\Shapeobj.cpp

"$(INTDIR)\Shapeobj.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\propdlg.pch"


SOURCE=.\Shapesvw.cpp

"$(INTDIR)\Shapesvw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\propdlg.pch"


SOURCE=.\Stdafx.cpp

!IF  "$(CFG)" == "PropDlg - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\propdlg.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\propdlg.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "PropDlg - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\propdlg.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\propdlg.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "PropDlg - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\propdlg.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\propdlg.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "PropDlg - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\propdlg.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\propdlg.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Stylepge.cpp

"$(INTDIR)\Stylepge.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\propdlg.pch"



!ENDIF 

