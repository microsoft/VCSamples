# Microsoft Developer Studio Generated NMAKE File, Based on drive.dsp
!IF "$(CFG)" == ""
CFG=Drive - Win32 Release
!MESSAGE No configuration specified. Defaulting to Drive - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Drive - Win32 Release" && "$(CFG)" != "Drive - Win32 Debug" && "$(CFG)" != "Drive - Win32 Unicode Release" && "$(CFG)" != "Drive - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "drive.mak" CFG="Drive - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Drive - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Drive - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "Drive - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "Drive - Win32 Unicode Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "Drive - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\drive.exe"


CLEAN :
	-@erase "$(INTDIR)\Drive.obj"
	-@erase "$(INTDIR)\drive.pch"
	-@erase "$(INTDIR)\predrive.obj"
	-@erase "$(OUTDIR)\drive.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
F90_OBJS=.\Release/
F90_PROJ=/I "Release/" /Fo"Release/" 

.for{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

.f{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

.f90{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\drive.pch" /Yu"predrive.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\drive.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"WinMainCRTStartup" /subsystem:console /incremental:no /pdb:"$(OUTDIR)\drive.pdb" /machine:I386 /out:"$(OUTDIR)\drive.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Drive.obj" \
	"$(INTDIR)\predrive.obj"

"$(OUTDIR)\drive.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Drive - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\drive.exe"


CLEAN :
	-@erase "$(INTDIR)\Drive.obj"
	-@erase "$(INTDIR)\drive.pch"
	-@erase "$(INTDIR)\predrive.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\drive.exe"
	-@erase "$(OUTDIR)\drive.ilk"
	-@erase "$(OUTDIR)\drive.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
F90_OBJS=.\Debug/
F90_PROJ=/I "Release/" /Fo"Release/" 

.for{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

.f{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

.f90{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\drive.pch" /Yu"predrive.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\drive.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"WinMainCRTStartup" /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\drive.pdb" /debug /machine:I386 /out:"$(OUTDIR)\drive.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Drive.obj" \
	"$(INTDIR)\predrive.obj"

"$(OUTDIR)\drive.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Drive - Win32 Unicode Release"

OUTDIR=.\ReleaseU
INTDIR=.\ReleaseU
# Begin Custom Macros
OutDir=.\.\ReleaseU
# End Custom Macros

ALL : "$(OUTDIR)\drive.exe"


CLEAN :
	-@erase "$(INTDIR)\Drive.obj"
	-@erase "$(INTDIR)\drive.pch"
	-@erase "$(INTDIR)\predrive.obj"
	-@erase "$(OUTDIR)\drive.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
F90_OBJS=.\ReleaseU/
F90_PROJ=/I "Release/" /Fo"Release/" 

.for{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

.f{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

.f90{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "_UNICODE" /Fp"$(INTDIR)\drive.pch" /Yu"predrive.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\drive.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:console /incremental:no /pdb:"$(OUTDIR)\drive.pdb" /machine:I386 /out:"$(OUTDIR)\drive.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Drive.obj" \
	"$(INTDIR)\predrive.obj"

"$(OUTDIR)\drive.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Drive - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\.\DebugU
# End Custom Macros

ALL : "$(OUTDIR)\drive.exe"


CLEAN :
	-@erase "$(INTDIR)\Drive.obj"
	-@erase "$(INTDIR)\drive.pch"
	-@erase "$(INTDIR)\predrive.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\drive.exe"
	-@erase "$(OUTDIR)\drive.ilk"
	-@erase "$(OUTDIR)\drive.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
F90_OBJS=.\DebugU/
F90_PROJ=/I "Release/" /Fo"Release/" 

.for{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

.f{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

.f90{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "_UNICODE" /Fp"$(INTDIR)\drive.pch" /Yu"predrive.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\drive.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\drive.pdb" /debug /machine:I386 /out:"$(OUTDIR)\drive.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Drive.obj" \
	"$(INTDIR)\predrive.obj"

"$(OUTDIR)\drive.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("drive.dep")
!INCLUDE "drive.dep"
!ELSE 
!MESSAGE Warning: cannot find "drive.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Drive - Win32 Release" || "$(CFG)" == "Drive - Win32 Debug" || "$(CFG)" == "Drive - Win32 Unicode Release" || "$(CFG)" == "Drive - Win32 Unicode Debug"
SOURCE=.\Drive.cpp

"$(INTDIR)\Drive.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\drive.pch"


SOURCE=.\predrive.cpp

!IF  "$(CFG)" == "Drive - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\drive.pch" /Yc"predrive.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\predrive.obj"	"$(INTDIR)\drive.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Drive - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\drive.pch" /Yc"predrive.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\predrive.obj"	"$(INTDIR)\drive.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Drive - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "_UNICODE" /Fp"$(INTDIR)\drive.pch" /Yc"predrive.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\predrive.obj"	"$(INTDIR)\drive.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Drive - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "_UNICODE" /Fp"$(INTDIR)\drive.pch" /Yc"predrive.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\predrive.obj"	"$(INTDIR)\drive.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

