# Microsoft Developer Studio Generated NMAKE File, Based on ATLDraw.dsp
!IF "$(CFG)" == ""
CFG=ATLDraw - Win32 Release
!MESSAGE No configuration specified. Defaulting to ATLDraw - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "ATLDraw - Win32 Release" && "$(CFG)" != "ATLDraw - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ATLDraw.mak" CFG="ATLDraw - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ATLDraw - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "ATLDraw - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "ATLDraw - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\ATLDraw.exe" "$(OUTDIR)\ATLDraw.bsc"


CLEAN :
	-@erase "$(INTDIR)\ATLDDoc.obj"
	-@erase "$(INTDIR)\ATLDDoc.sbr"
	-@erase "$(INTDIR)\ATLDraw.obj"
	-@erase "$(INTDIR)\ATLDraw.res"
	-@erase "$(INTDIR)\ATLDraw.sbr"
	-@erase "$(INTDIR)\ATLDView.obj"
	-@erase "$(INTDIR)\ATLDView.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\preatldr.obj"
	-@erase "$(INTDIR)\preatldr.sbr"
	-@erase "$(OUTDIR)\ATLDraw.bsc"
	-@erase "$(OUTDIR)\ATLDraw.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D "_WIN32_DCOM" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ATLDraw.pch" /YX"preatldr.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ATLDraw.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ATLDraw.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\ATLDraw.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\preatldr.sbr" \
	"$(INTDIR)\ATLDDoc.sbr" \
	"$(INTDIR)\ATLDView.sbr"

"$(OUTDIR)\ATLDraw.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\ATLDraw.pdb" /machine:I386 /out:"$(OUTDIR)\ATLDraw.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ATLDraw.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\preatldr.obj" \
	"$(INTDIR)\ATLDDoc.obj" \
	"$(INTDIR)\ATLDView.obj" \
	"$(INTDIR)\ATLDraw.res"

"$(OUTDIR)\ATLDraw.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ATLDraw - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\ATLDraw.exe" "$(OUTDIR)\ATLDraw.bsc"


CLEAN :
	-@erase "$(INTDIR)\ATLDDoc.obj"
	-@erase "$(INTDIR)\ATLDDoc.sbr"
	-@erase "$(INTDIR)\ATLDraw.obj"
	-@erase "$(INTDIR)\ATLDraw.res"
	-@erase "$(INTDIR)\ATLDraw.sbr"
	-@erase "$(INTDIR)\ATLDView.obj"
	-@erase "$(INTDIR)\ATLDView.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\preatldr.obj"
	-@erase "$(INTDIR)\preatldr.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\ATLDraw.bsc"
	-@erase "$(OUTDIR)\ATLDraw.exe"
	-@erase "$(OUTDIR)\ATLDraw.ilk"
	-@erase "$(OUTDIR)\ATLDraw.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D "_WIN32_DCOM" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ATLDraw.pch" /YX"preatldr.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ATLDraw.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ATLDraw.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\ATLDraw.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\preatldr.sbr" \
	"$(INTDIR)\ATLDDoc.sbr" \
	"$(INTDIR)\ATLDView.sbr"

"$(OUTDIR)\ATLDraw.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\ATLDraw.pdb" /debug /machine:I386 /out:"$(OUTDIR)\ATLDraw.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ATLDraw.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\preatldr.obj" \
	"$(INTDIR)\ATLDDoc.obj" \
	"$(INTDIR)\ATLDView.obj" \
	"$(INTDIR)\ATLDraw.res"

"$(OUTDIR)\ATLDraw.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("ATLDraw.dep")
!INCLUDE "ATLDraw.dep"
!ELSE 
!MESSAGE Warning: cannot find "ATLDraw.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "ATLDraw - Win32 Release" || "$(CFG)" == "ATLDraw - Win32 Debug"
SOURCE=.\ATLDDoc.cpp

"$(INTDIR)\ATLDDoc.obj"	"$(INTDIR)\ATLDDoc.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ATLDraw.cpp

"$(INTDIR)\ATLDraw.obj"	"$(INTDIR)\ATLDraw.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ATLDraw.rc

"$(INTDIR)\ATLDraw.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\ATLDView.cpp

"$(INTDIR)\ATLDView.obj"	"$(INTDIR)\ATLDView.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MainFrm.cpp

"$(INTDIR)\MainFrm.obj"	"$(INTDIR)\MainFrm.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\preatldr.cpp

"$(INTDIR)\preatldr.obj"	"$(INTDIR)\preatldr.sbr" : $(SOURCE) "$(INTDIR)"



!ENDIF 

