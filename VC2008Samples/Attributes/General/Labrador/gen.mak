# General make file for attribute projects.


#################################################################################################
# Check CFG. If CFG is not given, use  "Win32 Release" as the default. Otherwise make sure a 
# valid config is given.
#################################################################################################
!IF "$(CFG)" == ""
CFG=Win32 Release
!MESSAGE No configuration specified. Defaulting to Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Win32 Release" \
&& "$(CFG)" != "Win32 Debug" \
&& "$(CFG)" != "Win32 Unicode Debug" \
&& "$(CFG)" != "Win32 Unicode Release"

!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "gen.mak" CFG="Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Win32 Unicode Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF  "$(CFG)" == "Win32 Release"
CONFIG=2
OUTDIR=.\Release
!ELSEIF "$(CFG)" == "Win32 Debug"
CONFIG=0
OUTDIR=.\Debug
!ELSEIF "$(CFG)" == "Win32 Unicode Release"
CONFIG=3
OUTDIR=.\URelease
!ELSEIF "$(CFG)" == "Win32 Unicode Debug"
CONFIG=1
OUTDIR=.\UDebug
!ENDIF
#################################################################################################
# Set the output dir and common exes.
#################################################################################################
!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe
BSC32=bscmake.exe
LINK32=link.exe
AIM=Labrador.exe
AIMTYPE=EXE
ROOTNAME=Labrador
PREHEADER=Labrador.pch
THEPRE=prelab.h
FRES=$(ROOTNAME).res
FBSC=$(ROOTNAME).bsc
FPDB=$(ROOTNAME).pdb
FMAP=$(ROOTNAME).map
FLIB=$(ROOTNAME).lib
FIDL=_Labrador.idl

!IF "$(AIMTYPE)" == "DLL"
THREADTYPE=/MD
!ELSE
THREADTYPE=/MT
!ENDIF

!IF $(CONFIG) & 2
CONFI=$(THREADTYPE) /W3 /GX /O2 /D "NDEBUG"
DEBUG=NDEBUG
MT=MTd
GM=
!ELSE
CONFI=$(THREADTYPE)d /W3 /Gm /GX /ZI /Od /D "_DEBUG"
DEBUG=_DEBUG
MT=MT
GM=/Gm
!ENDIF


!IF $(CONFIG) & 1
UNICODE=_UNICODE
!ELSE
UNICODE=NOMEANING
!ENDIF

!IF $(CONFIG) == 2
MYSUFFIX=/FD /F0x0 /c
!ELSE
MYSUFFIX=/FD /c
!ENDIF

CPP_PROJ=/nologo $(CONFI) /D "$(UNICODE)" /D "_ATL_DLL" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_ATL_ATTRIBUTES" /Fp"$(OUTDIR)\$(PREHEADER)" /Yu"$(THEPRE)" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\"  $(MYSUFFIX)
CPP_SWITCHES=/nologo $(CONFI) /D "$(UNICODE)" /D "_ATL_DLL" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_ATL_ATTRIBUTES" /Fp"$(OUTDIR)\$(PREHEADER)" /Yc"$(THEPRE)" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(MYSUFFIX)
MTL_PROJ=/nologo /D "$(DEBUG)" /win32 
RSC_PROJ=/l 0x409 /fo"$(OUTDIR)\$(FRES)" /d "$(DEBUG)" 
BSC32_FLAGS=/nologo /o"$(OUTDIR)\$(FBSC)" 
BSC32_SBRS= \
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\$(FPDB)" /map:"$(OUTDIR)\$(FMAP)" /machine:I386 /out:"$(OUTDIR)\$(AIM)" /implib:"$(OUTDIR)\$(FLIB)" /idlout:$(FIDL)
#################################################################################################
# Project dependent stuff.
#################################################################################################

ALL : "$(OUTDIR)\$(AIM)" "$(OUTDIR)\regsvr32.trg"

CLEAN :
	del /F /Q $(OUTDIR)\*.* $(OUTDIR)\*
	
SOURCE=.\$(ROOTNAME).rc
"$(OUTDIR)\$(FRES)" : $(SOURCE) "$(OUTDIR)" MYCLEAN
	$(RSC) $(RSC_PROJ) $(SOURCE)
MYCLEAN:
	del /F /Q $(OUTDIR)\*.* $(OUTDIR)\*

SOURCE=.\Labrador.cpp
"$(OUTDIR)\Labrador.obj" : $(SOURCE) "$(OUTDIR)" "$(OUTDIR)\$(PREHEADER)"
	$(CPP) @<<
   $(CPP_PROJ) $(SOURCE)
<<

SOURCE=.\LabObj.cpp
"$(OUTDIR)\LabObj.obj" : $(SOURCE) "$(OUTDIR)" "$(OUTDIR)\$(PREHEADER)"
	$(CPP) @<<
   $(CPP_PROJ) $(SOURCE)
<<

SOURCE=.\prelab.cpp

"$(OUTDIR)\prelab.obj"	"$(OUTDIR)\$(PREHEADER)" : $(SOURCE) "$(OUTDIR)" MYCLEAN
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"
    
LINK32_OBJS= \
	"$(OUTDIR)\Labrador.obj" \
	"$(OUTDIR)\Labrador.res" \
	"$(OUTDIR)\prelab.obj" \
	"$(OUTDIR)\LabObj.obj"
 
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\$(FPDB)" /map:"$(OUTDIR)\$(FMAP)" /machine:I386 /out:"$(OUTDIR)\$(AIM)" /implib:"$(OUTDIR)\$(FLIB)" /idlout:$(FIDL)
"$(OUTDIR)\$(AIM)" :: "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

TargetPath=$(OUTDIR)\$(AIM)

"$(OUTDIR)\regsvr32.trg" : "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	"$(TargetPath)" /RegServer
	echo regsvr32 exec. time > "$(OUTDIR)\regsvr32.trg" 
<< 
	


