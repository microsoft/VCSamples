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

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\mdrive.exe"

!ELSE 

ALL : "$(OUTDIR)\mdrive.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\DriveDlg.obj"
	-@erase "$(INTDIR)\driver.obj"
	-@erase "$(INTDIR)\MDrive.obj"
	-@erase "$(INTDIR)\mdrive.pch"
	-@erase "$(INTDIR)\MDrive.res"
	-@erase "$(INTDIR)\premdriv.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\mdrive.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /D _WIN32_WINNT=0x400 /Fp"$(INTDIR)\mdrive.pch"\
 /Yu"premdriv.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\MDrive.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mdrive.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\mdrive.pdb" /machine:I386 /out:"$(OUTDIR)\mdrive.exe" 
LINK32_OBJS= \
	"$(INTDIR)\DriveDlg.obj" \
	"$(INTDIR)\driver.obj" \
	"$(INTDIR)\MDrive.obj" \
	"$(INTDIR)\MDrive.res" \
	"$(INTDIR)\premdriv.obj"

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

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\mdrive.exe"

!ELSE 

ALL : "$(OUTDIR)\mdrive.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\DriveDlg.obj"
	-@erase "$(INTDIR)\driver.obj"
	-@erase "$(INTDIR)\MDrive.obj"
	-@erase "$(INTDIR)\mdrive.pch"
	-@erase "$(INTDIR)\MDrive.res"
	-@erase "$(INTDIR)\premdriv.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\mdrive.exe"
	-@erase "$(OUTDIR)\mdrive.ilk"
	-@erase "$(OUTDIR)\mdrive.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /D _WIN32_WINNT=0x400 /Fp"$(INTDIR)\mdrive.pch"\
 /Yu"premdriv.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\MDrive.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mdrive.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\mdrive.pdb" /debug /machine:I386 /out:"$(OUTDIR)\mdrive.exe" 
LINK32_OBJS= \
	"$(INTDIR)\DriveDlg.obj" \
	"$(INTDIR)\driver.obj" \
	"$(INTDIR)\MDrive.obj" \
	"$(INTDIR)\MDrive.res" \
	"$(INTDIR)\premdriv.obj"

"$(OUTDIR)\mdrive.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(CFG)" == "MDrive - Win32 Release" || "$(CFG)" == "MDrive - Win32 Debug"
SOURCE=.\DriveDlg.cpp

!IF  "$(CFG)" == "MDrive - Win32 Release"

DEP_CPP_DRIVE=\
	".\DriveDlg.h"\
	".\Driver.h"\
	".\MDrive.h"\
	

"$(INTDIR)\DriveDlg.obj" : $(SOURCE) $(DEP_CPP_DRIVE) "$(INTDIR)"\
 "$(INTDIR)\mdrive.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "MDrive - Win32 Debug"

DEP_CPP_DRIVE=\
	".\DriveDlg.h"\
	".\Driver.h"\
	".\MDrive.h"\
	

"$(INTDIR)\DriveDlg.obj" : $(SOURCE) $(DEP_CPP_DRIVE) "$(INTDIR)"\
 "$(INTDIR)\mdrive.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\driver.cpp
DEP_CPP_DRIVER=\
	".\Driver.h"\
	

"$(INTDIR)\driver.obj" : $(SOURCE) $(DEP_CPP_DRIVER) "$(INTDIR)"\
 "$(INTDIR)\mdrive.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\MDrive.cpp
DEP_CPP_MDRIV=\
	".\DriveDlg.h"\
	".\MDrive.h"\
	

"$(INTDIR)\MDrive.obj" : $(SOURCE) $(DEP_CPP_MDRIV) "$(INTDIR)"\
 "$(INTDIR)\mdrive.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\MDrive.rc
DEP_RSC_MDRIVE=\
	".\res\MDrive.ico"\
	".\res\MDrive.rc2"\
	

"$(INTDIR)\MDrive.res" : $(SOURCE) $(DEP_RSC_MDRIVE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\premdriv.cpp
DEP_CPP_PREMD=\
	"..\server\connect.tlb"\
	".\premdriv.h"\
	

!IF  "$(CFG)" == "MDrive - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /D _WIN32_WINNT=0x400 /Fp"$(INTDIR)\mdrive.pch"\
 /Yc"premdriv.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\premdriv.obj"	"$(INTDIR)\mdrive.pch" : $(SOURCE) $(DEP_CPP_PREMD)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MDrive - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D _WIN32_WINNT=0x400\
 /Fp"$(INTDIR)\mdrive.pch" /Yc"premdriv.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 

"$(INTDIR)\premdriv.obj"	"$(INTDIR)\mdrive.pch" : $(SOURCE) $(DEP_CPP_PREMD)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\DriveDlg.h
SOURCE=.\Driver.h
SOURCE=.\MDrive.h
SOURCE=.\premdriv.h
SOURCE=.\res\MDrive.ico
SOURCE=.\res\MDrive.rc2

!ENDIF 

