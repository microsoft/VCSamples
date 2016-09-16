# Microsoft Developer Studio Generated NMAKE File, Based on regsvr32.dsp
!IF "$(CFG)" == ""
CFG=RegSvr32 - Win32 Release
!MESSAGE No configuration specified. Defaulting to RegSvr32 - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "RegSvr32 - Win32 Release" && "$(CFG)" != "RegSvr32 - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "regsvr32.mak" CFG="RegSvr32 - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "RegSvr32 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "RegSvr32 - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "RegSvr32 - Win32 Release"

OUTDIR=.\WinRel
INTDIR=.\WinRel
# Begin Custom Macros
OutDir=.\.\WinRel
# End Custom Macros

ALL : "$(OUTDIR)\regsvr32.exe" "$(OUTDIR)\regsvr32.bsc"


CLEAN :
	-@erase "$(INTDIR)\REGSVR.OBJ"
	-@erase "$(INTDIR)\regsvr.res"
	-@erase "$(INTDIR)\REGSVR.SBR"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\regsvr32.bsc"
	-@erase "$(OUTDIR)\regsvr32.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /O1 /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\regsvr32.pch" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\regsvr.res" /d "NDEBUG" /d "_WIN32" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\regsvr32.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\REGSVR.SBR"

"$(OUTDIR)\regsvr32.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib ole32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\regsvr32.pdb" /machine:IX86 /out:"$(OUTDIR)\regsvr32.exe" 
LINK32_OBJS= \
	"$(INTDIR)\REGSVR.OBJ" \
	"$(INTDIR)\regsvr.res"

"$(OUTDIR)\regsvr32.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "RegSvr32 - Win32 Debug"

OUTDIR=.\WinDebug
INTDIR=.\WinDebug
# Begin Custom Macros
OutDir=.\.\WinDebug
# End Custom Macros

ALL : "$(OUTDIR)\regsvr32.exe" "$(OUTDIR)\regsvr32.bsc"


CLEAN :
	-@erase "$(INTDIR)\REGSVR.OBJ"
	-@erase "$(INTDIR)\regsvr.res"
	-@erase "$(INTDIR)\REGSVR.SBR"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\regsvr32.bsc"
	-@erase "$(OUTDIR)\regsvr32.exe"
	-@erase "$(OUTDIR)\regsvr32.ilk"
	-@erase "$(OUTDIR)\regsvr32.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\regsvr32.pch" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\regsvr.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\regsvr32.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\REGSVR.SBR"

"$(OUTDIR)\regsvr32.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib ole32.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\regsvr32.pdb" /debug /machine:IX86 /out:"$(OUTDIR)\regsvr32.exe" 
LINK32_OBJS= \
	"$(INTDIR)\REGSVR.OBJ" \
	"$(INTDIR)\regsvr.res"

"$(OUTDIR)\regsvr32.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("regsvr32.dep")
!INCLUDE "regsvr32.dep"
!ELSE 
!MESSAGE Warning: cannot find "regsvr32.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "RegSvr32 - Win32 Release" || "$(CFG)" == "RegSvr32 - Win32 Debug"
SOURCE=.\REGSVR.CPP

"$(INTDIR)\REGSVR.OBJ"	"$(INTDIR)\REGSVR.SBR" : $(SOURCE) "$(INTDIR)"


SOURCE=.\regsvr.rc

"$(INTDIR)\regsvr.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)



!ENDIF 

