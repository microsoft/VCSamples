# Microsoft Visual C++ Generated NMAKE File, Format Version 40001
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101
# TARGTYPE "Power Macintosh Application" 0x0401
# TARGTYPE "Macintosh Application" 0x0301

!IF "$(CFG)" == ""
CFG=Scribble - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Scribble - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Scribble - Macintosh Release" && "$(CFG)" !=\
 "Scribble - Macintosh Debug" && "$(CFG)" != "Scribble - Win32 Release" &&\
 "$(CFG)" != "Scribble - Win32 Debug" && "$(CFG)" !=\
 "Scribble - Power Macintosh Release" && "$(CFG)" !=\
 "Scribble - Power Macintosh Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "scribble.mak" CFG="Scribble - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Scribble - Macintosh Release" (based on "Macintosh Application")
!MESSAGE "Scribble - Macintosh Debug" (based on "Macintosh Application")
!MESSAGE "Scribble - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Scribble - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "Scribble - Power Macintosh Release" (based on\
 "Power Macintosh Application")
!MESSAGE "Scribble - Power Macintosh Debug" (based on\
 "Power Macintosh Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "Scribble - Power Macintosh Debug"

!IF  "$(CFG)" == "Scribble - Macintosh Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir MacRel
# PROP BASE Intermediate_Dir MacRel
# PROP BASE Target_Dir
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir MacRel
# PROP Intermediate_Dir MacRel
# PROP Target_Dir
OUTDIR=.\MacRel
INTDIR=.\MacRel

ALL : "$(OUTDIR)\scribble.exe" "$(OUTDIR)\scribble.trg"\
 "$(OUTDIR)\scribbleMac.hlp"

CLEAN : 
	-@erase ".\MacRel\scribble.trg"
	-@erase ".\MacRel\scribble.exe"
	-@erase ".\MacRel\scribvw.obj"
	-@erase ".\MacRel\scribble.pch"
	-@erase ".\MacRel\scribble.obj"
	-@erase ".\MacRel\stdafx.obj"
	-@erase ".\MacRel\ipframe.obj"
	-@erase ".\MacRel\scribitm.obj"
	-@erase ".\MacRel\pendlg.obj"
	-@erase ".\MacRel\childfrm.obj"
	-@erase ".\MacRel\scribdoc.obj"
	-@erase ".\MacRel\mainfrm.obj"
	-@erase ".\MacRel\scrimac.rsc"
	-@erase ".\MacRel\scribble.rsc"
	-@erase ".\MacRel\scribbleMac.hlp"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

MTL=mktyplib.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mac
# ADD MTL /nologo /D "NDEBUG" /mac
MTL_PROJ=/nologo /D "NDEBUG" /mac 
CPP=cl.exe
# ADD BASE CPP /nologo /AL /Q68s /W3 /GX /O2 /D "_WINDOWS" /D "_MAC" /D "_68K_" /D "WIN32" /D "NDEBUG" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /AL /Q68s /W3 /GX /O2 /D "_WINDOWS" /D "_MAC" /D "_68K_" /D "WIN32" /D "NDEBUG" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /AL /Q68s /W3 /GX /O2 /D "_WINDOWS" /D "_MAC" /D "_68K_" /D\
 "WIN32" /D "NDEBUG" /D "_MBCS" /Fp"$(INTDIR)/scribble.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\MacRel/
CPP_SBRS=

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

RSC=rc.exe
# ADD BASE RSC /l 0x409 /r /d "_MAC" /d "_68K_" /d "NDEBUG"
# ADD RSC /l 0x409 /r /d "_MAC" /d "_68K_" /d "NDEBUG"
RSC_PROJ=/l 0x409 /r /m /fo"$(INTDIR)/scribble.rsc" /d "_MAC" /d "_68K_" /d\
 "NDEBUG" 
MRC=mrc.exe
# ADD BASE MRC /D "_68K_" /D "_MAC" /D "NDEBUG" /NOLOGO
# ADD MRC /D "_68K_" /D "_MAC" /D "NDEBUG" /NOLOGO
MRC_PROJ=/D "_68K_" /D "_MAC" /D "NDEBUG" /l 0x409 /NOLOGO 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/scribble.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 /nologo /MAC:bundle /machine:M68K
# ADD LINK32 /nologo /MAC:bundle /MAC:creator="SCRI" /machine:M68K
LINK32_FLAGS=/nologo /MAC:bundle /MAC:type="APPL" /MAC:creator="SCRI"\
 /pdb:"$(OUTDIR)/scribble.pdb" /machine:M68K /out:"$(OUTDIR)/scribble.exe" 
LINK32_OBJS= \
	"$(INTDIR)/scribvw.obj" \
	"$(INTDIR)/scribble.obj" \
	"$(INTDIR)/stdafx.obj" \
	"$(INTDIR)/ipframe.obj" \
	"$(INTDIR)/scribitm.obj" \
	"$(INTDIR)/pendlg.obj" \
	"$(INTDIR)/childfrm.obj" \
	"$(INTDIR)/scribdoc.obj" \
	"$(INTDIR)/mainfrm.obj" \
	"$(INTDIR)/scrimac.rsc" \
	"$(INTDIR)/scribble.rsc"

"$(OUTDIR)\scribble.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

MFILE32=mfile.exe
# ADD BASE MFILE32 COPY /NOLOGO
# ADD MFILE32 COPY /NOLOGO
MFILE32_FLAGS=COPY /NOLOGO 
MFILE32_FILES= \
	"$(OUTDIR)/scribble.exe"

"$(OUTDIR)\scribble.trg" : "$(OUTDIR)" $(MFILE32_FILES)
    $(MFILE32) $(MFILE32_FLAGS) .\MacRel\scribble.exe\
 "$(MFILE32_DEST):scribble.exe">"$(OUTDIR)\scribble.trg"

DOWNLOAD : "$(OUTDIR)" $(MFILE32_FILES)
    $(MFILE32) $(MFILE32_FLAGS) .\MacRel\scribble.exe\
 "$(MFILE32_DEST):scribble.exe">"$(OUTDIR)\scribble.trg"

!ELSEIF  "$(CFG)" == "Scribble - Macintosh Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir MacDbg
# PROP BASE Intermediate_Dir MacDbg
# PROP BASE Target_Dir
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir MacDbg
# PROP Intermediate_Dir MacDbg
# PROP Target_Dir
OUTDIR=.\MacDbg
INTDIR=.\MacDbg

ALL : "$(OUTDIR)\scribble.exe" "$(OUTDIR)\scribble.trg"\
 "$(OUTDIR)\scribbleMac.hlp"

CLEAN : 
	-@erase ".\MacDbg\vc40.pdb"
	-@erase ".\MacDbg\scribble.pch"
	-@erase ".\MacDbg\scribble.pdb"
	-@erase ".\MacDbg\stdafx.obj"
	-@erase ".\MacDbg\scribble.obj"
	-@erase ".\MacDbg\mainfrm.obj"
	-@erase ".\MacDbg\scribitm.obj"
	-@erase ".\MacDbg\scribvw.obj"
	-@erase ".\MacDbg\ipframe.obj"
	-@erase ".\MacDbg\pendlg.obj"
	-@erase ".\MacDbg\childfrm.obj"
	-@erase ".\MacDbg\scribdoc.obj"
	-@erase ".\MacDbg\scrimac.rsc"
	-@erase ".\MacDbg\scribble.rsc"
	-@erase ".\MacDbg\scribble.trg"
	-@erase ".\MacDbg\scribble.exe"
	-@erase ".\MacDbg\scribbleMac.hlp"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

MTL=mktyplib.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mac
# ADD MTL /nologo /D "_DEBUG" /mac
MTL_PROJ=/nologo /D "_DEBUG" /mac 
CPP=cl.exe
# ADD BASE CPP /nologo /AL /Q68s /Q68m /W3 /GX /Zi /Od /D "_WINDOWS" /D "_MAC" /D "_68K_" /D "WIN32" /D "_DEBUG" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /AL /Q68s /Q68m /W3 /GX /Zi /Od /D "_WINDOWS" /D "_MAC" /D "_68K_" /D "WIN32" /D "_DEBUG" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /AL /Q68s /Q68m /W3 /GX /Zi /Od /D "_WINDOWS" /D "_MAC" /D\
 "_68K_" /D "WIN32" /D "_DEBUG" /D "_MBCS" /Fp"$(INTDIR)/scribble.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\MacDbg/
CPP_SBRS=

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

RSC=rc.exe
# ADD BASE RSC /l 0x409 /r /d "_MAC" /d "_68K_" /d "_DEBUG"
# ADD RSC /l 0x409 /r /d "_MAC" /d "_68K_" /d "_DEBUG"
RSC_PROJ=/l 0x409 /r /m /fo"$(INTDIR)/scribble.rsc" /d "_MAC" /d "_68K_" /d\
 "_DEBUG" 
MRC=mrc.exe
# ADD BASE MRC /D "_68K_" /D "_MAC" /D "_DEBUG" /NOLOGO
# ADD MRC /D "_68K_" /D "_MAC" /D "_DEBUG" /NOLOGO
MRC_PROJ=/D "_68K_" /D "_MAC" /D "_DEBUG" /l 0x409 /NOLOGO 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/scribble.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 /nologo /MAC:bundle /debug /machine:M68K
# ADD LINK32 /nologo /MAC:bundle /MAC:creator="SCRI" /debug /machine:M68K
LINK32_FLAGS=/nologo /MAC:bundle /MAC:type="APPL" /MAC:creator="SCRI"\
 /pdb:"$(OUTDIR)/scribble.pdb" /debug /machine:M68K\
 /out:"$(OUTDIR)/scribble.exe" 
LINK32_OBJS= \
	"$(INTDIR)/stdafx.obj" \
	"$(INTDIR)/scribble.obj" \
	"$(INTDIR)/mainfrm.obj" \
	"$(INTDIR)/scribitm.obj" \
	"$(INTDIR)/scribvw.obj" \
	"$(INTDIR)/ipframe.obj" \
	"$(INTDIR)/pendlg.obj" \
	"$(INTDIR)/childfrm.obj" \
	"$(INTDIR)/scribdoc.obj" \
	"$(INTDIR)/scrimac.rsc" \
	"$(INTDIR)/scribble.rsc"

"$(OUTDIR)\scribble.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

MFILE32=mfile.exe
# ADD BASE MFILE32 COPY /NOLOGO
# ADD MFILE32 COPY /NOLOGO
MFILE32_FLAGS=COPY /NOLOGO 
MFILE32_FILES= \
	"$(OUTDIR)/scribble.exe"

"$(OUTDIR)\scribble.trg" : "$(OUTDIR)" $(MFILE32_FILES)
    $(MFILE32) $(MFILE32_FLAGS) .\MacDbg\scribble.exe\
 "$(MFILE32_DEST):scribble.exe">"$(OUTDIR)\scribble.trg"

DOWNLOAD : "$(OUTDIR)" $(MFILE32_FILES)
    $(MFILE32) $(MFILE32_FLAGS) .\MacDbg\scribble.exe\
 "$(MFILE32_DEST):scribble.exe">"$(OUTDIR)\scribble.trg"

!ELSEIF  "$(CFG)" == "Scribble - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir Release
# PROP BASE Intermediate_Dir Release
# PROP BASE Target_Dir
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir Release
# PROP Intermediate_Dir Release
# PROP Target_Dir
OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\scribble.exe" "$(OUTDIR)\scribble.hlp"

CLEAN : 
	-@erase ".\Release\scribble.exe"
	-@erase ".\Release\pendlg.obj"
	-@erase ".\Release\scribble.pch"
	-@erase ".\Release\mainfrm.obj"
	-@erase ".\Release\scribble.obj"
	-@erase ".\Release\scribvw.obj"
	-@erase ".\Release\scribitm.obj"
	-@erase ".\Release\ipframe.obj"
	-@erase ".\Release\stdafx.obj"
	-@erase ".\Release\childfrm.obj"
	-@erase ".\Release\scribdoc.obj"
	-@erase ".\Release\scribble.res"
	-@erase ".\Release\scribble.hlp"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
# ADD BASE F90 /I "Release/"
# ADD F90 /I "Release/"
F90_PROJ=/I "Release/" /Fo"Release/" 
F90_OBJS=.\Release/

.for{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

.f{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

.f90{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

CPP=cl.exe
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/scribble.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/"\
 /c 
CPP_OBJS=.\Release/
CPP_SBRS=

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

MTL=mktyplib.exe
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/scribble.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/scribble.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/scribble.pdb" /machine:I386 /out:"$(OUTDIR)/scribble.exe" 
LINK32_OBJS= \
	"$(INTDIR)/pendlg.obj" \
	"$(INTDIR)/mainfrm.obj" \
	"$(INTDIR)/scribble.obj" \
	"$(INTDIR)/scribvw.obj" \
	"$(INTDIR)/scribitm.obj" \
	"$(INTDIR)/ipframe.obj" \
	"$(INTDIR)/stdafx.obj" \
	"$(INTDIR)/childfrm.obj" \
	"$(INTDIR)/scribdoc.obj" \
	"$(INTDIR)/scribble.res"

"$(OUTDIR)\scribble.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Scribble - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir Debug
# PROP BASE Intermediate_Dir Debug
# PROP BASE Target_Dir
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir Debug
# PROP Intermediate_Dir Debug
# PROP Target_Dir
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "$(OUTDIR)\scribble.exe" "$(OUTDIR)\scribble.hlp"

CLEAN : 
	-@erase ".\Debug\vc40.pdb"
	-@erase ".\Debug\scribble.pch"
	-@erase ".\Debug\scribble.exe"
	-@erase ".\Debug\scribitm.obj"
	-@erase ".\Debug\mainfrm.obj"
	-@erase ".\Debug\pendlg.obj"
	-@erase ".\Debug\scribvw.obj"
	-@erase ".\Debug\childfrm.obj"
	-@erase ".\Debug\ipframe.obj"
	-@erase ".\Debug\scribdoc.obj"
	-@erase ".\Debug\scribble.obj"
	-@erase ".\Debug\stdafx.obj"
	-@erase ".\Debug\scribble.res"
	-@erase ".\Debug\scribble.ilk"
	-@erase ".\Debug\scribble.pdb"
	-@erase ".\Debug\scribble.hlp"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
# ADD BASE F90 /I "Debug/"
# ADD F90 /I "Debug/"
F90_PROJ=/I "Debug/" /Fo"Debug/" 
F90_OBJS=.\Debug/

.for{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

.f{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

.f90{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

CPP=cl.exe
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/scribble.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

MTL=mktyplib.exe
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/scribble.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/scribble.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/scribble.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/scribble.exe" 
LINK32_OBJS= \
	"$(INTDIR)/scribitm.obj" \
	"$(INTDIR)/mainfrm.obj" \
	"$(INTDIR)/pendlg.obj" \
	"$(INTDIR)/scribvw.obj" \
	"$(INTDIR)/childfrm.obj" \
	"$(INTDIR)/ipframe.obj" \
	"$(INTDIR)/scribdoc.obj" \
	"$(INTDIR)/scribble.obj" \
	"$(INTDIR)/stdafx.obj" \
	"$(INTDIR)/scribble.res"

"$(OUTDIR)\scribble.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir PMacRel
# PROP BASE Intermediate_Dir PMacRel
# PROP BASE Target_Dir
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir PMacRel
# PROP Intermediate_Dir PMacRel
# PROP Target_Dir
OUTDIR=.\PMacRel
INTDIR=.\PMacRel

ALL : "$(OUTDIR)\scribble.exe" "$(OUTDIR)\scribble.trg"\
 "$(OUTDIR)\scribbleMac.hlp"

CLEAN : 
	-@erase ".\PMacRel\scribble.trg"
	-@erase ".\PMacRel\scribble.exe"
	-@erase ".\PMacRel\scribvw.obj"
	-@erase ".\PMacRel\scribble.pch"
	-@erase ".\PMacRel\childfrm.obj"
	-@erase ".\PMacRel\stdafx.obj"
	-@erase ".\PMacRel\ipframe.obj"
	-@erase ".\PMacRel\scribdoc.obj"
	-@erase ".\PMacRel\scribble.obj"
	-@erase ".\PMacRel\pendlg.obj"
	-@erase ".\PMacRel\scribitm.obj"
	-@erase ".\PMacRel\mainfrm.obj"
	-@erase ".\PMacRel\scribble.rsc"
	-@erase ".\PMacRel\scrimac.rsc"
	-@erase ".\PMacRel\scribbleMac.hlp"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

MTL=mktyplib.exe
# ADD BASE MTL /nologo /D "NDEBUG"
# ADD MTL /nologo /D "NDEBUG"
MTL_PROJ=/nologo /D "NDEBUG" 
CPP=cl.exe
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "_MAC" /D "_MPPC_" /D "_WINDOWS" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "_MAC" /D "_MPPC_" /D "_WINDOWS" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_AFXDLL" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "_MAC" /D "_MPPC_" /D "_WINDOWS" /D "WIN32"\
 /D "NDEBUG" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)/scribble.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\PMacRel/
CPP_SBRS=

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

RSC=rc.exe
# ADD BASE RSC /l 0x409 /r /d "_MAC" /d "_MPPC_" /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /r /d "_MAC" /d "_MPPC_" /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /r /m /fo"$(INTDIR)/scribble.rsc" /d "_MAC" /d "_MPPC_" /d\
 "NDEBUG" /d "_AFXDLL" 
MRC=mrc.exe
# ADD BASE MRC /D "_MPPC_" /D "_MAC" /D "NDEBUG" /NOLOGO
# ADD MRC /D "_MPPC_" /D "_MAC" /D "NDEBUG" /NOLOGO
MRC_PROJ=/D "_MPPC_" /D "_MAC" /D "NDEBUG" /l 0x409 /NOLOGO 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/scribble.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 /nologo /mac:bundle /machine:MPPC
# ADD LINK32 /nologo /mac:bundle /mac:creator="SCRI" /machine:MPPC
LINK32_FLAGS=/nologo /mac:bundle /mac:type="APPL" /mac:creator="SCRI"\
 /incremental:no /pdb:"$(OUTDIR)/scribble.pdb" /machine:MPPC\
 /out:"$(OUTDIR)/scribble.exe" 
LINK32_OBJS= \
	"$(INTDIR)/scribvw.obj" \
	"$(INTDIR)/childfrm.obj" \
	"$(INTDIR)/stdafx.obj" \
	"$(INTDIR)/ipframe.obj" \
	"$(INTDIR)/scribdoc.obj" \
	"$(INTDIR)/scribble.obj" \
	"$(INTDIR)/pendlg.obj" \
	"$(INTDIR)/scribitm.obj" \
	"$(INTDIR)/mainfrm.obj" \
	"$(INTDIR)/scribble.rsc" \
	"$(INTDIR)/scrimac.rsc"

"$(OUTDIR)\scribble.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

MFILE32=mfile.exe
# ADD BASE MFILE32 COPY /NOLOGO
# ADD MFILE32 COPY /NOLOGO
MFILE32_FLAGS=COPY /NOLOGO 
MFILE32_FILES= \
	"$(OUTDIR)/scribble.exe"

"$(OUTDIR)\scribble.trg" : "$(OUTDIR)" $(MFILE32_FILES)
    $(MFILE32) $(MFILE32_FLAGS) .\PMacRel\scribble.exe\
 "$(MFILE32_DEST):scribble.exe">"$(OUTDIR)\scribble.trg"

DOWNLOAD : "$(OUTDIR)" $(MFILE32_FILES)
    $(MFILE32) $(MFILE32_FLAGS) .\PMacRel\scribble.exe\
 "$(MFILE32_DEST):scribble.exe">"$(OUTDIR)\scribble.trg"

!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir PMacDbg
# PROP BASE Intermediate_Dir PMacDbg
# PROP BASE Target_Dir
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir PMacDbg
# PROP Intermediate_Dir PMacDbg
# PROP Target_Dir
OUTDIR=.\PMacDbg
INTDIR=.\PMacDbg

ALL : "$(OUTDIR)\scribble.exe" "$(OUTDIR)\scribble.trg"\
 "$(OUTDIR)\scribbleMac.hlp"

CLEAN : 
	-@erase ".\PMacDbg\vc40.pdb"
	-@erase ".\PMacDbg\scribble.pch"
	-@erase ".\PMacDbg\scribble.ilk"
	-@erase ".\PMacDbg\stdafx.obj"
	-@erase ".\PMacDbg\childfrm.obj"
	-@erase ".\PMacDbg\mainfrm.obj"
	-@erase ".\PMacDbg\scribvw.obj"
	-@erase ".\PMacDbg\scribdoc.obj"
	-@erase ".\PMacDbg\pendlg.obj"
	-@erase ".\PMacDbg\ipframe.obj"
	-@erase ".\PMacDbg\scribble.obj"
	-@erase ".\PMacDbg\scribitm.obj"
	-@erase ".\PMacDbg\scribble.rsc"
	-@erase ".\PMacDbg\scrimac.rsc"
	-@erase ".\PMacDbg\scribble.pdb"
	-@erase ".\PMacDbg\scribble.trg"
	-@erase ".\PMacDbg\scribble.exe"
	-@erase ".\PMacDbg\scribbleMac.hlp"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

MTL=mktyplib.exe
# ADD BASE MTL /nologo /D "_DEBUG"
# ADD MTL /nologo /D "_DEBUG"
MTL_PROJ=/nologo /D "_DEBUG" 
CPP=cl.exe
# ADD BASE CPP /nologo /MDd /W3 /GX /Zi /Od /D "_MAC" /D "_MPPC_" /D "_WINDOWS" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_AFXDLL" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /GX /Zi /Od /D "_MAC" /D "_MPPC_" /D "_WINDOWS" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_AFXDLL" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MDd /W3 /GX /Zi /Od /D "_MAC" /D "_MPPC_" /D "_WINDOWS" /D\
 "WIN32" /D "_DEBUG" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)/scribble.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\PMacDbg/
CPP_SBRS=

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

RSC=rc.exe
# ADD BASE RSC /l 0x409 /r /d "_MAC" /d "_MPPC_" /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /r /d "_MAC" /d "_MPPC_" /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /r /m /fo"$(INTDIR)/scribble.rsc" /d "_MAC" /d "_MPPC_" /d\
 "_DEBUG" /d "_AFXDLL" 
MRC=mrc.exe
# ADD BASE MRC /D "_MPPC_" /D "_MAC" /D "_DEBUG" /NOLOGO
# ADD MRC /D "_MPPC_" /D "_MAC" /D "_DEBUG" /NOLOGO
MRC_PROJ=/D "_MPPC_" /D "_MAC" /D "_DEBUG" /l 0x409 /NOLOGO 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/scribble.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 /nologo /mac:bundle /debug /machine:MPPC
# ADD LINK32 /nologo /mac:bundle /mac:creator="SCRI" /debug /machine:MPPC
LINK32_FLAGS=/nologo /mac:bundle /mac:type="APPL" /mac:creator="SCRI"\
 /incremental:yes /pdb:"$(OUTDIR)/scribble.pdb" /debug /machine:MPPC\
 /out:"$(OUTDIR)/scribble.exe" 
LINK32_OBJS= \
	"$(INTDIR)/stdafx.obj" \
	"$(INTDIR)/childfrm.obj" \
	"$(INTDIR)/mainfrm.obj" \
	"$(INTDIR)/scribvw.obj" \
	"$(INTDIR)/scribdoc.obj" \
	"$(INTDIR)/pendlg.obj" \
	"$(INTDIR)/ipframe.obj" \
	"$(INTDIR)/scribble.obj" \
	"$(INTDIR)/scribitm.obj" \
	"$(INTDIR)/scribble.rsc" \
	"$(INTDIR)/scrimac.rsc"

"$(OUTDIR)\scribble.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

MFILE32=mfile.exe
# ADD BASE MFILE32 COPY /NOLOGO
# ADD MFILE32 COPY /NOLOGO
MFILE32_FLAGS=COPY /NOLOGO 
MFILE32_FILES= \
	"$(OUTDIR)/scribble.exe"

"$(OUTDIR)\scribble.trg" : "$(OUTDIR)" $(MFILE32_FILES)
    $(MFILE32) $(MFILE32_FLAGS) .\PMacDbg\scribble.exe\
 "$(MFILE32_DEST):scribble.exe">"$(OUTDIR)\scribble.trg"

DOWNLOAD : "$(OUTDIR)" $(MFILE32_FILES)
    $(MFILE32) $(MFILE32_FLAGS) .\PMacDbg\scribble.exe\
 "$(MFILE32_DEST):scribble.exe">"$(OUTDIR)\scribble.trg"

!ENDIF 

################################################################################
# Begin Target

# Name "Scribble - Macintosh Release"
# Name "Scribble - Macintosh Debug"
# Name "Scribble - Win32 Release"
# Name "Scribble - Win32 Debug"
# Name "Scribble - Power Macintosh Release"
# Name "Scribble - Power Macintosh Debug"

!IF  "$(CFG)" == "Scribble - Macintosh Release"

!ELSEIF  "$(CFG)" == "Scribble - Macintosh Debug"

!ELSEIF  "$(CFG)" == "Scribble - Win32 Release"

!ELSEIF  "$(CFG)" == "Scribble - Win32 Debug"

!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Release"

!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\readme.txt

!IF  "$(CFG)" == "Scribble - Macintosh Release"

!ELSEIF  "$(CFG)" == "Scribble - Macintosh Debug"

!ELSEIF  "$(CFG)" == "Scribble - Win32 Release"

!ELSEIF  "$(CFG)" == "Scribble - Win32 Debug"

!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Release"

!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\scribble.cpp
DEP_CPP_SCRIB=\
	".\childfrm.h"\
	".\ipframe.h"\
	".\mainfrm.h"\
	".\scribdoc.h"\
	".\scribvw.h"\
	".\scribble.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Scribble - Macintosh Release"


"$(INTDIR)\scribble.obj" : $(SOURCE) $(DEP_CPP_SCRIB) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Macintosh Debug"


"$(INTDIR)\scribble.obj" : $(SOURCE) $(DEP_CPP_SCRIB) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_SCRIB) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Win32 Release"


"$(INTDIR)\scribble.obj" : $(SOURCE) $(DEP_CPP_SCRIB) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Win32 Debug"


"$(INTDIR)\scribble.obj" : $(SOURCE) $(DEP_CPP_SCRIB) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_SCRIB) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Release"


"$(INTDIR)\scribble.obj" : $(SOURCE) $(DEP_CPP_SCRIB) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Debug"


"$(INTDIR)\scribble.obj" : $(SOURCE) $(DEP_CPP_SCRIB) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_SCRIB) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\stdafx.cpp
DEP_CPP_STDAF=\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Scribble - Macintosh Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /AL /Q68s /W3 /GX /O2 /D "_WINDOWS" /D "_MAC" /D "_68K_" /D\
 "WIN32" /D "NDEBUG" /D "_MBCS" /Fp"$(INTDIR)/scribble.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\stdafx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\scribble.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Scribble - Macintosh Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /AL /Q68s /Q68m /W3 /GX /Zi /Od /D "_WINDOWS" /D "_MAC" /D\
 "_68K_" /D "WIN32" /D "_DEBUG" /D "_MBCS" /Fp"$(INTDIR)/scribble.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\stdafx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\scribble.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Scribble - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/scribble.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/"\
 /c $(SOURCE) \
	

"$(INTDIR)\stdafx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\scribble.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Scribble - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/scribble.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\stdafx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\scribble.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /O2 /D "_MAC" /D "_MPPC_" /D "_WINDOWS" /D "WIN32"\
 /D "NDEBUG" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)/scribble.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\stdafx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\scribble.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /GX /Zi /Od /D "_MAC" /D "_MPPC_" /D "_WINDOWS" /D\
 "WIN32" /D "_DEBUG" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)/scribble.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\stdafx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\scribble.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\mainfrm.cpp
DEP_CPP_MAINF=\
	".\mainfrm.h"\
	".\scribble.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Scribble - Macintosh Release"


"$(INTDIR)\mainfrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Macintosh Debug"


"$(INTDIR)\mainfrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Win32 Release"


"$(INTDIR)\mainfrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Win32 Debug"


"$(INTDIR)\mainfrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Release"


"$(INTDIR)\mainfrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Debug"


"$(INTDIR)\mainfrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\childfrm.cpp
DEP_CPP_CHILD=\
	".\childfrm.h"\
	".\scribble.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Scribble - Macintosh Release"


"$(INTDIR)\childfrm.obj" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Macintosh Debug"


"$(INTDIR)\childfrm.obj" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Win32 Release"


"$(INTDIR)\childfrm.obj" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Win32 Debug"


"$(INTDIR)\childfrm.obj" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Release"


"$(INTDIR)\childfrm.obj" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Debug"


"$(INTDIR)\childfrm.obj" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\scribdoc.cpp
DEP_CPP_SCRIBD=\
	".\pendlg.h"\
	".\scribdoc.h"\
	".\scribitm.h"\
	".\scribvw.h"\
	".\scribble.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Scribble - Macintosh Release"


"$(INTDIR)\scribdoc.obj" : $(SOURCE) $(DEP_CPP_SCRIBD) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Macintosh Debug"


"$(INTDIR)\scribdoc.obj" : $(SOURCE) $(DEP_CPP_SCRIBD) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_SCRIBD) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Win32 Release"


"$(INTDIR)\scribdoc.obj" : $(SOURCE) $(DEP_CPP_SCRIBD) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Win32 Debug"


"$(INTDIR)\scribdoc.obj" : $(SOURCE) $(DEP_CPP_SCRIBD) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_SCRIBD) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Release"


"$(INTDIR)\scribdoc.obj" : $(SOURCE) $(DEP_CPP_SCRIBD) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Debug"


"$(INTDIR)\scribdoc.obj" : $(SOURCE) $(DEP_CPP_SCRIBD) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_SCRIBD) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\scribvw.cpp
DEP_CPP_SCRIBV=\
	".\scribdoc.h"\
	".\scribvw.h"\
	".\scribble.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Scribble - Macintosh Release"


"$(INTDIR)\scribvw.obj" : $(SOURCE) $(DEP_CPP_SCRIBV) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Macintosh Debug"


"$(INTDIR)\scribvw.obj" : $(SOURCE) $(DEP_CPP_SCRIBV) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_SCRIBV) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Win32 Release"


"$(INTDIR)\scribvw.obj" : $(SOURCE) $(DEP_CPP_SCRIBV) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Win32 Debug"


"$(INTDIR)\scribvw.obj" : $(SOURCE) $(DEP_CPP_SCRIBV) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_SCRIBV) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Release"


"$(INTDIR)\scribvw.obj" : $(SOURCE) $(DEP_CPP_SCRIBV) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Debug"


"$(INTDIR)\scribvw.obj" : $(SOURCE) $(DEP_CPP_SCRIBV) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_SCRIBV) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ipframe.cpp
DEP_CPP_IPFRA=\
	".\ipframe.h"\
	".\scribble.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Scribble - Macintosh Release"


"$(INTDIR)\ipframe.obj" : $(SOURCE) $(DEP_CPP_IPFRA) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Macintosh Debug"


"$(INTDIR)\ipframe.obj" : $(SOURCE) $(DEP_CPP_IPFRA) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_IPFRA) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Win32 Release"


"$(INTDIR)\ipframe.obj" : $(SOURCE) $(DEP_CPP_IPFRA) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Win32 Debug"


"$(INTDIR)\ipframe.obj" : $(SOURCE) $(DEP_CPP_IPFRA) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_IPFRA) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Release"


"$(INTDIR)\ipframe.obj" : $(SOURCE) $(DEP_CPP_IPFRA) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Debug"


"$(INTDIR)\ipframe.obj" : $(SOURCE) $(DEP_CPP_IPFRA) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_IPFRA) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\scrimac.r

!IF  "$(CFG)" == "Scribble - Macintosh Release"


"$(INTDIR)\scrimac.rsc" : $(SOURCE) "$(INTDIR)"
   $(MRC) /o"$(INTDIR)/scrimac.rsc" /D "_68K_" /D "_MAC" /D "NDEBUG" /l 0x409\
 /NOLOGO $(SOURCE)


!ELSEIF  "$(CFG)" == "Scribble - Macintosh Debug"


"$(INTDIR)\scrimac.rsc" : $(SOURCE) "$(INTDIR)"
   $(MRC) /o"$(INTDIR)/scrimac.rsc" /D "_68K_" /D "_MAC" /D "_DEBUG" /l 0x409\
 /NOLOGO $(SOURCE)


!ELSEIF  "$(CFG)" == "Scribble - Win32 Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Scribble - Win32 Debug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Release"


"$(INTDIR)\scrimac.rsc" : $(SOURCE) "$(INTDIR)"
   $(MRC) /o"$(INTDIR)/scrimac.rsc" /D "_MPPC_" /D "_MAC" /D "NDEBUG" /l 0x409\
 /NOLOGO $(SOURCE)


!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Debug"


"$(INTDIR)\scrimac.rsc" : $(SOURCE) "$(INTDIR)"
   $(MRC) /o"$(INTDIR)/scrimac.rsc" /D "_MPPC_" /D "_MAC" /D "_DEBUG" /l 0x409\
 /NOLOGO $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\scribble.rc
DEP_RSC_SCRIBB=\
	".\res\scribble.ico"\
	".\res\scribdoc.ico"\
	".\res\toolbar.bmp"\
	".\res\itoolbar.bmp"\
	".\res\scribble.rc2"\
	

!IF  "$(CFG)" == "Scribble - Macintosh Release"


"$(INTDIR)\scribble.rsc" : $(SOURCE) $(DEP_RSC_SCRIBB) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Scribble - Macintosh Debug"


"$(INTDIR)\scribble.rsc" : $(SOURCE) $(DEP_RSC_SCRIBB) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Scribble - Win32 Release"


"$(INTDIR)\scribble.res" : $(SOURCE) $(DEP_RSC_SCRIBB) "$(INTDIR)"
   $(RSC) /l 0x409 /fo"$(INTDIR)/scribble.res" /d "NDEBUG" /d "_AFXDLL"\
 $(SOURCE)


!ELSEIF  "$(CFG)" == "Scribble - Win32 Debug"


"$(INTDIR)\scribble.res" : $(SOURCE) $(DEP_RSC_SCRIBB) "$(INTDIR)"
   $(RSC) /l 0x409 /fo"$(INTDIR)/scribble.res" /d "_DEBUG" /d "_AFXDLL"\
 $(SOURCE)


!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Release"


"$(INTDIR)\scribble.rsc" : $(SOURCE) $(DEP_RSC_SCRIBB) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Debug"


"$(INTDIR)\scribble.rsc" : $(SOURCE) $(DEP_RSC_SCRIBB) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\hlp\scribble.hpj

!IF  "$(CFG)" == "Scribble - Macintosh Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Scribble - Macintosh Debug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Scribble - Win32 Release"

# Begin Custom Build - Making help file...
OutDir=.\Release
TargetName=scribble
InputPath=.\hlp\scribble.hpj

"$(OutDir)\$(TargetName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   makehelp.bat

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Win32 Debug"

# Begin Custom Build - Making help file...
OutDir=.\Debug
TargetName=scribble
InputPath=.\hlp\scribble.hpj

"$(OutDir)\$(TargetName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   makehelp.bat

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Debug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\hlp\scrimac.hpj

!IF  "$(CFG)" == "Scribble - Macintosh Release"

# Begin Custom Build - Making help file...
OutDir=.\MacRel
TargetName=scribble
InputPath=.\hlp\scrimac.hpj
RemoteTargetPath=machd:scribble

".\$(OutDir)\$(TargetName)Mac.hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   makehelp.bat MAC ":$(RemoteTargetPath) Help"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Macintosh Debug"

# Begin Custom Build - Making help file...
OutDir=.\MacDbg
TargetName=scribble
InputPath=.\hlp\scrimac.hpj
RemoteTargetPath=machd:debug:scrible

".\$(OutDir)\$(TargetName)Mac.hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   makehelp.bat MAC ":$(RemoteTargetPath) Help"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Win32 Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Scribble - Win32 Debug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Release"

# Begin Custom Build - Making help file...
OutDir=.\PMacRel
TargetName=scribble
InputPath=.\hlp\scrimac.hpj
RemoteTargetPath=machd:releasep

".\$(OutDir)\$(TargetName)Mac.hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   makehelp.bat MAC ":$(RemoteTargetPath) Help"

# End Custom Build

!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Debug"

# Begin Custom Build - Making help file...
OutDir=.\PMacDbg
TargetName=scribble
InputPath=.\hlp\scrimac.hpj
RemoteTargetPath=machd:debug:scrible

".\$(OutDir)\$(TargetName)Mac.hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   makehelp.bat MAC ":$(RemoteTargetPath) Help"

# End Custom Build

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\scribitm.cpp
DEP_CPP_SCRIBI=\
	".\scribdoc.h"\
	".\scribitm.h"\
	".\scribble.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Scribble - Macintosh Release"


"$(INTDIR)\scribitm.obj" : $(SOURCE) $(DEP_CPP_SCRIBI) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Macintosh Debug"


"$(INTDIR)\scribitm.obj" : $(SOURCE) $(DEP_CPP_SCRIBI) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_SCRIBI) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Win32 Release"


"$(INTDIR)\scribitm.obj" : $(SOURCE) $(DEP_CPP_SCRIBI) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Win32 Debug"


"$(INTDIR)\scribitm.obj" : $(SOURCE) $(DEP_CPP_SCRIBI) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_SCRIBI) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Release"


"$(INTDIR)\scribitm.obj" : $(SOURCE) $(DEP_CPP_SCRIBI) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Debug"


"$(INTDIR)\scribitm.obj" : $(SOURCE) $(DEP_CPP_SCRIBI) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_SCRIBI) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\pendlg.cpp
DEP_CPP_PENDL=\
	".\pendlg.h"\
	".\scribble.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Scribble - Macintosh Release"


"$(INTDIR)\pendlg.obj" : $(SOURCE) $(DEP_CPP_PENDL) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Macintosh Debug"


"$(INTDIR)\pendlg.obj" : $(SOURCE) $(DEP_CPP_PENDL) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_PENDL) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Win32 Release"


"$(INTDIR)\pendlg.obj" : $(SOURCE) $(DEP_CPP_PENDL) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Win32 Debug"


"$(INTDIR)\pendlg.obj" : $(SOURCE) $(DEP_CPP_PENDL) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_PENDL) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Release"


"$(INTDIR)\pendlg.obj" : $(SOURCE) $(DEP_CPP_PENDL) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ELSEIF  "$(CFG)" == "Scribble - Power Macintosh Debug"


"$(INTDIR)\pendlg.obj" : $(SOURCE) $(DEP_CPP_PENDL) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_PENDL) "$(INTDIR)"\
 "$(INTDIR)\scribble.pch"


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
