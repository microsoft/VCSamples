# Microsoft Developer Studio Generated NMAKE File, Based on npp.dsp
!IF "$(CFG)" == ""
CFG=NPP - Win32 Release
!MESSAGE No configuration specified. Defaulting to NPP - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "NPP - Win32 Release" && "$(CFG)" != "NPP - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "npp.mak" CFG="NPP - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "NPP - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "NPP - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "NPP - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\npp.exe" "$(OUTDIR)\npp.bsc"


CLEAN :
	-@erase "$(INTDIR)\Combobar.obj"
	-@erase "$(INTDIR)\Combobar.sbr"
	-@erase "$(INTDIR)\Finddlg.obj"
	-@erase "$(INTDIR)\Finddlg.sbr"
	-@erase "$(INTDIR)\Gotodlg.obj"
	-@erase "$(INTDIR)\Gotodlg.sbr"
	-@erase "$(INTDIR)\History.obj"
	-@erase "$(INTDIR)\History.sbr"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Mainfrm.sbr"
	-@erase "$(INTDIR)\Np.obj"
	-@erase "$(INTDIR)\Np.sbr"
	-@erase "$(INTDIR)\Npdoc.obj"
	-@erase "$(INTDIR)\Npdoc.sbr"
	-@erase "$(INTDIR)\npp.pch"
	-@erase "$(INTDIR)\Npp.res"
	-@erase "$(INTDIR)\Npview.obj"
	-@erase "$(INTDIR)\Npview.sbr"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\Stdafx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\npp.bsc"
	-@erase "$(OUTDIR)\npp.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\npp.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Npp.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\npp.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Combobar.sbr" \
	"$(INTDIR)\Finddlg.sbr" \
	"$(INTDIR)\Gotodlg.sbr" \
	"$(INTDIR)\History.sbr" \
	"$(INTDIR)\Mainfrm.sbr" \
	"$(INTDIR)\Np.sbr" \
	"$(INTDIR)\Npdoc.sbr" \
	"$(INTDIR)\Npview.sbr" \
	"$(INTDIR)\Stdafx.sbr"

"$(OUTDIR)\npp.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\npp.pdb" /machine:I386 /out:"$(OUTDIR)\npp.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Combobar.obj" \
	"$(INTDIR)\Finddlg.obj" \
	"$(INTDIR)\Gotodlg.obj" \
	"$(INTDIR)\History.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Np.obj" \
	"$(INTDIR)\Npdoc.obj" \
	"$(INTDIR)\Npview.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Npp.res"

"$(OUTDIR)\npp.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "NPP - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\npp.exe" "$(OUTDIR)\npp.bsc"


CLEAN :
	-@erase "$(INTDIR)\Combobar.obj"
	-@erase "$(INTDIR)\Combobar.sbr"
	-@erase "$(INTDIR)\Finddlg.obj"
	-@erase "$(INTDIR)\Finddlg.sbr"
	-@erase "$(INTDIR)\Gotodlg.obj"
	-@erase "$(INTDIR)\Gotodlg.sbr"
	-@erase "$(INTDIR)\History.obj"
	-@erase "$(INTDIR)\History.sbr"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Mainfrm.sbr"
	-@erase "$(INTDIR)\Np.obj"
	-@erase "$(INTDIR)\Np.sbr"
	-@erase "$(INTDIR)\Npdoc.obj"
	-@erase "$(INTDIR)\Npdoc.sbr"
	-@erase "$(INTDIR)\npp.pch"
	-@erase "$(INTDIR)\Npp.res"
	-@erase "$(INTDIR)\Npview.obj"
	-@erase "$(INTDIR)\Npview.sbr"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\Stdafx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\npp.bsc"
	-@erase "$(OUTDIR)\npp.exe"
	-@erase "$(OUTDIR)\npp.ilk"
	-@erase "$(OUTDIR)\npp.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\npp.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Npp.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\npp.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Combobar.sbr" \
	"$(INTDIR)\Finddlg.sbr" \
	"$(INTDIR)\Gotodlg.sbr" \
	"$(INTDIR)\History.sbr" \
	"$(INTDIR)\Mainfrm.sbr" \
	"$(INTDIR)\Np.sbr" \
	"$(INTDIR)\Npdoc.sbr" \
	"$(INTDIR)\Npview.sbr" \
	"$(INTDIR)\Stdafx.sbr"

"$(OUTDIR)\npp.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\npp.pdb" /debug /machine:I386 /out:"$(OUTDIR)\npp.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Combobar.obj" \
	"$(INTDIR)\Finddlg.obj" \
	"$(INTDIR)\Gotodlg.obj" \
	"$(INTDIR)\History.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Np.obj" \
	"$(INTDIR)\Npdoc.obj" \
	"$(INTDIR)\Npview.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Npp.res"

"$(OUTDIR)\npp.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("npp.dep")
!INCLUDE "npp.dep"
!ELSE 
!MESSAGE Warning: cannot find "npp.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "NPP - Win32 Release" || "$(CFG)" == "NPP - Win32 Debug"
SOURCE=.\Combobar.cpp

"$(INTDIR)\Combobar.obj"	"$(INTDIR)\Combobar.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\npp.pch"


SOURCE=.\Finddlg.cpp

"$(INTDIR)\Finddlg.obj"	"$(INTDIR)\Finddlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\npp.pch"


SOURCE=.\Gotodlg.cpp

"$(INTDIR)\Gotodlg.obj"	"$(INTDIR)\Gotodlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\npp.pch"


SOURCE=.\History.cpp

"$(INTDIR)\History.obj"	"$(INTDIR)\History.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\npp.pch"


SOURCE=.\Mainfrm.cpp

"$(INTDIR)\Mainfrm.obj"	"$(INTDIR)\Mainfrm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\npp.pch"


SOURCE=.\Np.cpp

"$(INTDIR)\Np.obj"	"$(INTDIR)\Np.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\npp.pch"


SOURCE=.\Npdoc.cpp

"$(INTDIR)\Npdoc.obj"	"$(INTDIR)\Npdoc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\npp.pch"


SOURCE=.\Npp.rc

"$(INTDIR)\Npp.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\Npview.cpp

"$(INTDIR)\Npview.obj"	"$(INTDIR)\Npview.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\npp.pch"


SOURCE=.\Stdafx.cpp

!IF  "$(CFG)" == "NPP - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\npp.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\Stdafx.sbr"	"$(INTDIR)\npp.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "NPP - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\npp.pch" /Yc"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\Stdafx.sbr"	"$(INTDIR)\npp.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

