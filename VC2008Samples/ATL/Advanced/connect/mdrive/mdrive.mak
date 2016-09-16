# Microsoft Developer Studio Generated NMAKE File, Based on mdrive.dsp
!IF "$(CFG)" == ""
CFG=MDrive - Win32 Release
!MESSAGE No configuration specified. Defaulting to MDrive - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "MDrive - Win32 Release" && "$(CFG)" != "MDrive - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mdrive.mak" CFG="MDrive - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MDrive - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "MDrive - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "MDrive - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\mdrive.exe"


CLEAN :
	-@erase "$(INTDIR)\DriveDlg.obj"
	-@erase "$(INTDIR)\driver.obj"
	-@erase "$(INTDIR)\MDrive.obj"
	-@erase "$(INTDIR)\mdrive.pch"
	-@erase "$(INTDIR)\MDrive.res"
	-@erase "$(INTDIR)\premdriv.obj"
	-@erase "$(OUTDIR)\mdrive.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mdrive.pch" /Yu"premdriv.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\MDrive.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mdrive.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\mdrive.pdb" /machine:I386 /out:"$(OUTDIR)\mdrive.exe" 
LINK32_OBJS= \
	"$(INTDIR)\MDrive.obj" \
	"$(INTDIR)\DriveDlg.obj" \
	"$(INTDIR)\driver.obj" \
	"$(INTDIR)\premdriv.obj" \
	"$(INTDIR)\MDrive.res"

"$(OUTDIR)\mdrive.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MDrive - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\mdrive.exe"


CLEAN :
	-@erase "$(INTDIR)\DriveDlg.obj"
	-@erase "$(INTDIR)\driver.obj"
	-@erase "$(INTDIR)\MDrive.obj"
	-@erase "$(INTDIR)\mdrive.pch"
	-@erase "$(INTDIR)\MDrive.res"
	-@erase "$(INTDIR)\premdriv.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\mdrive.exe"
	-@erase "$(OUTDIR)\mdrive.ilk"
	-@erase "$(OUTDIR)\mdrive.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mdrive.pch" /Yu"premdriv.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\MDrive.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mdrive.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\mdrive.pdb" /debug /machine:I386 /out:"$(OUTDIR)\mdrive.exe" 
LINK32_OBJS= \
	"$(INTDIR)\MDrive.obj" \
	"$(INTDIR)\DriveDlg.obj" \
	"$(INTDIR)\driver.obj" \
	"$(INTDIR)\premdriv.obj" \
	"$(INTDIR)\MDrive.res"

"$(OUTDIR)\mdrive.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("mdrive.dep")
!INCLUDE "mdrive.dep"
!ELSE 
!MESSAGE Warning: cannot find "mdrive.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "MDrive - Win32 Release" || "$(CFG)" == "MDrive - Win32 Debug"
SOURCE=.\DriveDlg.cpp

"$(INTDIR)\DriveDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mdrive.pch"


SOURCE=.\driver.cpp

"$(INTDIR)\driver.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mdrive.pch"


SOURCE=.\MDrive.cpp

"$(INTDIR)\MDrive.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mdrive.pch"


SOURCE=.\MDrive.rc

"$(INTDIR)\MDrive.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\premdriv.cpp

!IF  "$(CFG)" == "MDrive - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mdrive.pch" /Yc"premdriv.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\premdriv.obj"	"$(INTDIR)\mdrive.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MDrive - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mdrive.pch" /Yc"premdriv.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\premdriv.obj"	"$(INTDIR)\mdrive.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

