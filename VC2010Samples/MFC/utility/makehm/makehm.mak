# Microsoft Developer Studio Generated NMAKE File, Based on makehm.dsp
!IF "$(CFG)" == ""
CFG=MakeHm - Win32 Release
!MESSAGE No configuration specified. Defaulting to MakeHm - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "MakeHm - Win32 Release" && "$(CFG)" != "MakeHm - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "makehm.mak" CFG="MakeHm - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MakeHm - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "MakeHm - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "MakeHm - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\makehm.exe" "$(OUTDIR)\makehm.bsc"


CLEAN :
	-@erase "$(INTDIR)\Makehm.obj"
	-@erase "$(INTDIR)\makehm.res"
	-@erase "$(INTDIR)\Makehm.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\makehm.bsc"
	-@erase "$(OUTDIR)\makehm.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\makehm.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\makehm.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\makehm.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Makehm.sbr"

"$(OUTDIR)\makehm.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\makehm.pdb" /machine:I386 /out:"$(OUTDIR)\makehm.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Makehm.obj" \
	"$(INTDIR)\makehm.res"

"$(OUTDIR)\makehm.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MakeHm - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\makehm.exe" "$(OUTDIR)\makehm.bsc"


CLEAN :
	-@erase "$(INTDIR)\Makehm.obj"
	-@erase "$(INTDIR)\makehm.res"
	-@erase "$(INTDIR)\Makehm.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\makehm.bsc"
	-@erase "$(OUTDIR)\makehm.exe"
	-@erase "$(OUTDIR)\makehm.ilk"
	-@erase "$(OUTDIR)\makehm.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\makehm.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\makehm.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\makehm.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Makehm.sbr"

"$(OUTDIR)\makehm.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\makehm.pdb" /debug /machine:I386 /out:"$(OUTDIR)\makehm.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Makehm.obj" \
	"$(INTDIR)\makehm.res"

"$(OUTDIR)\makehm.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("makehm.dep")
!INCLUDE "makehm.dep"
!ELSE 
!MESSAGE Warning: cannot find "makehm.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "MakeHm - Win32 Release" || "$(CFG)" == "MakeHm - Win32 Debug"
SOURCE=.\Makehm.cpp

"$(INTDIR)\Makehm.obj"	"$(INTDIR)\Makehm.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\makehm.rc

"$(INTDIR)\makehm.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)



!ENDIF 

