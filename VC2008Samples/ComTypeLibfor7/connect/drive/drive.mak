# Microsoft Developer Studio Generated NMAKE File, Based on drive.dsp
!IF "$(CFG)" == ""
CFG=Drive - Win32 Release
!MESSAGE No configuration specified. Defaulting to Drive - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Drive - Win32 Release" && "$(CFG)" != "Drive - Win32 Debug" &&\
 "$(CFG)" != "Drive - Win32 Unicode Release" && "$(CFG)" !=\
 "Drive - Win32 Unicode Debug"
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

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\drive.exe"

!ELSE 

ALL : "$(OUTDIR)\drive.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Drive.obj"
	-@erase "$(INTDIR)\drive.pch"
	-@erase "$(INTDIR)\predrive.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\drive.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D\
 "_MBCS" /Fp"$(INTDIR)\drive.pch" /Yu"predrive.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\drive.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /entry:"WinMainCRTStartup" /subsystem:console\
 /incremental:no /pdb:"$(OUTDIR)\drive.pdb" /machine:I386\
 /out:"$(OUTDIR)\drive.exe" 
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

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\drive.exe"

!ELSE 

ALL : "$(OUTDIR)\drive.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Drive.obj"
	-@erase "$(INTDIR)\drive.pch"
	-@erase "$(INTDIR)\predrive.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\drive.exe"
	-@erase "$(OUTDIR)\drive.ilk"
	-@erase "$(OUTDIR)\drive.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE"\
 /D "_MBCS" /Fp"$(INTDIR)\drive.pch" /Yu"predrive.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\drive.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /entry:"WinMainCRTStartup" /subsystem:console\
 /incremental:yes /pdb:"$(OUTDIR)\drive.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)\drive.exe" 
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

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\drive.exe"

!ELSE 

ALL : "$(OUTDIR)\drive.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Drive.obj"
	-@erase "$(INTDIR)\drive.pch"
	-@erase "$(INTDIR)\predrive.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\drive.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_CONSOLE" /D\
 "_MBCS" /D "_UNICODE" /Fp"$(INTDIR)\drive.pch" /Yu"predrive.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\drive.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /entry:"wWinMainCRTStartup" /subsystem:console\
 /incremental:no /pdb:"$(OUTDIR)\drive.pdb" /machine:I386\
 /out:"$(OUTDIR)\drive.exe" 
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

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\drive.exe"

!ELSE 

ALL : "$(OUTDIR)\drive.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Drive.obj"
	-@erase "$(INTDIR)\drive.pch"
	-@erase "$(INTDIR)\predrive.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\drive.exe"
	-@erase "$(OUTDIR)\drive.ilk"
	-@erase "$(OUTDIR)\drive.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_CONSOLE"\
 /D "_MBCS" /D "_UNICODE" /Fp"$(INTDIR)\drive.pch" /Yu"predrive.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\DebugU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\drive.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /entry:"wWinMainCRTStartup" /subsystem:console\
 /incremental:yes /pdb:"$(OUTDIR)\drive.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)\drive.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Drive.obj" \
	"$(INTDIR)\predrive.obj"

"$(OUTDIR)\drive.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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


!IF "$(CFG)" == "Drive - Win32 Release" || "$(CFG)" == "Drive - Win32 Debug" ||\
 "$(CFG)" == "Drive - Win32 Unicode Release" || "$(CFG)" ==\
 "Drive - Win32 Unicode Debug"
SOURCE=.\Drive.cpp

!IF  "$(CFG)" == "Drive - Win32 Release"


"$(INTDIR)\Drive.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\drive.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Drive - Win32 Debug"


"$(INTDIR)\Drive.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\drive.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Drive - Win32 Unicode Release"


"$(INTDIR)\Drive.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\drive.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Drive - Win32 Unicode Debug"

DEP_CPP_DRIVE=\
	".\predrive.h"\
	

"$(INTDIR)\Drive.obj" : $(SOURCE) $(DEP_CPP_DRIVE) "$(INTDIR)"\
 "$(INTDIR)\drive.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\predrive.cpp

!IF  "$(CFG)" == "Drive - Win32 Release"

DEP_CPP_PREDR=\
	"..\server\connect.tlb"\
	".\predrive.h"\
	
CPP_SWITCHES=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D\
 "_MBCS" /Fp"$(INTDIR)\drive.pch" /Yc"predrive.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\predrive.obj"	"$(INTDIR)\drive.pch" : $(SOURCE) $(DEP_CPP_PREDR)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Drive - Win32 Debug"

DEP_CPP_PREDR=\
	"..\server\connect.tlb"\
	".\predrive.h"\
	
CPP_SWITCHES=/nologo /MLd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\drive.pch" /Yc"predrive.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\predrive.obj"	"$(INTDIR)\drive.pch" : $(SOURCE) $(DEP_CPP_PREDR)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Drive - Win32 Unicode Release"

DEP_CPP_PREDR=\
	"..\server\connect.tlb"\
	".\predrive.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_CONSOLE" /D\
 "_MBCS" /D "_UNICODE" /Fp"$(INTDIR)\drive.pch" /Yc"predrive.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\predrive.obj"	"$(INTDIR)\drive.pch" : $(SOURCE) $(DEP_CPP_PREDR)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Drive - Win32 Unicode Debug"

DEP_CPP_PREDR=\
	".\predrive.h"\
	
CPP_SWITCHES=/nologo /MLd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D\
 "_CONSOLE" /D "_MBCS" /D "_UNICODE" /Fp"$(INTDIR)\drive.pch" /Yc"predrive.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\predrive.obj"	"$(INTDIR)\drive.pch" : $(SOURCE) $(DEP_CPP_PREDR)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\predrive.h

!ENDIF 

