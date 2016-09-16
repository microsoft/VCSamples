# Microsoft Developer Studio Generated NMAKE File, Based on tracker.dsp
!IF "$(CFG)" == ""
CFG=Tracker - Win32 Release
!MESSAGE No configuration specified. Defaulting to Tracker - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Tracker - Win32 Release" && "$(CFG)" != "Tracker - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "tracker.mak" CFG="Tracker - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Tracker - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Tracker - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "Tracker - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\tracker.exe"


CLEAN :
	-@erase "$(INTDIR)\Dialogs.obj"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\Trackapp.obj"
	-@erase "$(INTDIR)\Trackdoc.obj"
	-@erase "$(INTDIR)\tracker.pch"
	-@erase "$(INTDIR)\Tracker.res"
	-@erase "$(INTDIR)\Trackvw.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\tracker.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\tracker.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Tracker.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\tracker.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\tracker.pdb" /machine:I386 /out:"$(OUTDIR)\tracker.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Dialogs.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Trackapp.obj" \
	"$(INTDIR)\Trackdoc.obj" \
	"$(INTDIR)\Trackvw.obj" \
	"$(INTDIR)\Tracker.res"

"$(OUTDIR)\tracker.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Tracker - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\tracker.exe"


CLEAN :
	-@erase "$(INTDIR)\Dialogs.obj"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\Trackapp.obj"
	-@erase "$(INTDIR)\Trackdoc.obj"
	-@erase "$(INTDIR)\tracker.pch"
	-@erase "$(INTDIR)\Tracker.res"
	-@erase "$(INTDIR)\Trackvw.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\tracker.exe"
	-@erase "$(OUTDIR)\tracker.ilk"
	-@erase "$(OUTDIR)\tracker.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\tracker.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Tracker.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\tracker.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\tracker.pdb" /debug /machine:I386 /out:"$(OUTDIR)\tracker.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Dialogs.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Trackapp.obj" \
	"$(INTDIR)\Trackdoc.obj" \
	"$(INTDIR)\Trackvw.obj" \
	"$(INTDIR)\Tracker.res"

"$(OUTDIR)\tracker.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("tracker.dep")
!INCLUDE "tracker.dep"
!ELSE 
!MESSAGE Warning: cannot find "tracker.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Tracker - Win32 Release" || "$(CFG)" == "Tracker - Win32 Debug"
SOURCE=.\Dialogs.cpp

"$(INTDIR)\Dialogs.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tracker.pch"


SOURCE=.\Mainfrm.cpp

"$(INTDIR)\Mainfrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tracker.pch"


SOURCE=.\Stdafx.cpp

!IF  "$(CFG)" == "Tracker - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\tracker.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\tracker.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Tracker - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\tracker.pch" /Yc"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\tracker.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Trackapp.cpp

"$(INTDIR)\Trackapp.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tracker.pch"


SOURCE=.\Trackdoc.cpp

"$(INTDIR)\Trackdoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tracker.pch"


SOURCE=.\Tracker.rc

"$(INTDIR)\Tracker.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\Trackvw.cpp

"$(INTDIR)\Trackvw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tracker.pch"



!ENDIF 

