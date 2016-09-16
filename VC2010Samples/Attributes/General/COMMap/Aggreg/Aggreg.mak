
# Script generated makefile, DONT edit.
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

!MESSAGE Invalid configuration "$(CFG)" specified!
!MESSAGE Defaulting to Win32 Release.
CFG=Win32 Release
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
AIM=Aggreg.dll
AIMTYPE=dll
ROOTNAME=Aggreg
PREHEADER=Aggreg.pch
THEPRE=preagg.h
FRES=$(ROOTNAME).res
FBSC=$(ROOTNAME).bsc
FPDB=$(ROOTNAME).pdb
FMAP=$(ROOTNAME).map
FLIB=$(ROOTNAME).lib
FIDL=_Aggreg.idl

!IF "$(AIMTYPE)" == "dll"
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

CPP_PROJ=/nologo $(CONFI) /D "$(UNICODE)" /D "_WINDLL" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_ATL_ATTRIBUTES" /Fp"$(OUTDIR)\$(PREHEADER)" /Yu"$(THEPRE)" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\"  $(MYSUFFIX)
CPP_SWITCHES=/nologo $(CONFI) /D "$(UNICODE)" /D "_WINDLL" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_ATL_ATTRIBUTES" /Fp"$(OUTDIR)\$(PREHEADER)" /Yc"$(THEPRE)" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(MYSUFFIX)
MTL_PROJ=/nologo /D "$(DEBUG)" /win32 
RSC_PROJ=/l 0x409 /fo"$(OUTDIR)\$(FRES)" /d "$(DEBUG)" 
BSC32_FLAGS=/nologo /o"$(OUTDIR)\$(FBSC)" 
BSC32_SBRS= \
#################################################################################################
# Project dependent stuff.
#################################################################################################

ALL : "$(OUTDIR)\$(AIM)" "$(OUTDIR)\regsvr32.trg"

CLEAN :
	del /F /Q $(OUTDIR)\*.* $(OUTDIR)\*
	

SOURCE=.\$(ROOTNAME).rc
"$(OUTDIR)\$(FRES)" : $(SOURCE) "$(OUTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)

	


SOURCE=.\Aggreg.cpp
"$(OUTDIR)\Aggreg.obj"	"$(OUTDIR)\$(PREHEADER)" : $(SOURCE) "$(OUTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


SOURCE=.\Agg.cpp
"$(OUTDIR)\Agg.obj" : $(SOURCE) "$(OUTDIR)" "$(OUTDIR)\$(PREHEADER)"
	$(CPP) @<<
   $(CPP_PROJ) $(SOURCE)
<<


SOURCE=.\AggBlind.cpp
"$(OUTDIR)\AggBlind.obj" : $(SOURCE) "$(OUTDIR)" "$(OUTDIR)\$(PREHEADER)"
	$(CPP) @<<
   $(CPP_PROJ) $(SOURCE)
<<


SOURCE=.\AutoAgg.cpp
"$(OUTDIR)\AutoAgg.obj" : $(SOURCE) "$(OUTDIR)" "$(OUTDIR)\$(PREHEADER)"
	$(CPP) @<<
   $(CPP_PROJ) $(SOURCE)
<<


SOURCE=.\AutoAggB.cpp
"$(OUTDIR)\AutoAggB.obj" : $(SOURCE) "$(OUTDIR)" "$(OUTDIR)\$(PREHEADER)"
	$(CPP) @<<
   $(CPP_PROJ) $(SOURCE)
<<


SOURCE=.\preagg.cpp
"$(OUTDIR)\preagg.obj" : $(SOURCE) "$(OUTDIR)" "$(OUTDIR)\$(PREHEADER)"
	$(CPP) @<<
   $(CPP_PROJ) $(SOURCE)
<<


"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"
    
LINK32_OBJS= \
	"$(OUTDIR)\Aggreg.obj" \
	"$(OUTDIR)\Aggreg.res" \
	"$(OUTDIR)\Agg.obj" \
	"$(OUTDIR)\AggBlind.obj" \
	"$(OUTDIR)\AutoAgg.obj" \
	"$(OUTDIR)\AutoAggB.obj" \
	"$(OUTDIR)\preagg.obj" 

LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\$(FPDB)" /map:"$(OUTDIR)\$(FMAP)" /machine:I386 /out:"$(OUTDIR)\$(AIM)" /implib:"$(OUTDIR)\$(FLIB)" /idlout:$(FIDL)
"$(OUTDIR)\$(AIM)" :: "$(OUTDIR)" CLEAN $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS)  $(LINK32_OBJS)
<<

TargetPath=$(OUTDIR)\$(AIM)


"$(OUTDIR)\regsvr32.trg" : "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
!IF $(CONFIG) & 1
!IF "$(AIMTYPE)" == "dll"
	regsvr32 /s /c "$(TargetPath)" 
!ELSE
	"$(TargetPath)" /RegServer
!ENDIF
!ENDIF
	echo regsvr32 exec. time > "$(OUTDIR)\regsvr32.trg" 
<< 

