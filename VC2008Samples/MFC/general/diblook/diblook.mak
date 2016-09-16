# Microsoft Developer Studio Generated NMAKE File, Based on diblook.dsp
!IF "$(CFG)" == ""
CFG=DibLook - Win32 Release
!MESSAGE No configuration specified. Defaulting to DibLook - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "DibLook - Win32 Release" && "$(CFG)" != "DibLook - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "diblook.mak" CFG="DibLook - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DibLook - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "DibLook - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "DibLook - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\diblook.exe"


CLEAN :
	-@erase "$(INTDIR)\dibapi.obj"
	-@erase "$(INTDIR)\dibdoc.obj"
	-@erase "$(INTDIR)\diblook.obj"
	-@erase "$(INTDIR)\diblook.pch"
	-@erase "$(INTDIR)\diblook.res"
	-@erase "$(INTDIR)\dibview.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\myfile.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\diblook.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\diblook.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\diblook.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\diblook.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\diblook.pdb" /machine:I386 /out:"$(OUTDIR)\diblook.exe" 
LINK32_OBJS= \
	"$(INTDIR)\dibapi.obj" \
	"$(INTDIR)\dibdoc.obj" \
	"$(INTDIR)\diblook.obj" \
	"$(INTDIR)\dibview.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\myfile.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\diblook.res"

"$(OUTDIR)\diblook.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "DibLook - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\diblook.exe"


CLEAN :
	-@erase "$(INTDIR)\dibapi.obj"
	-@erase "$(INTDIR)\dibdoc.obj"
	-@erase "$(INTDIR)\diblook.obj"
	-@erase "$(INTDIR)\diblook.pch"
	-@erase "$(INTDIR)\diblook.res"
	-@erase "$(INTDIR)\dibview.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\myfile.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\diblook.exe"
	-@erase "$(OUTDIR)\diblook.ilk"
	-@erase "$(OUTDIR)\diblook.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\diblook.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\diblook.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\diblook.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\diblook.pdb" /debug /machine:I386 /out:"$(OUTDIR)\diblook.exe" 
LINK32_OBJS= \
	"$(INTDIR)\dibapi.obj" \
	"$(INTDIR)\dibdoc.obj" \
	"$(INTDIR)\diblook.obj" \
	"$(INTDIR)\dibview.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\myfile.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\diblook.res"

"$(OUTDIR)\diblook.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("diblook.dep")
!INCLUDE "diblook.dep"
!ELSE 
!MESSAGE Warning: cannot find "diblook.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "DibLook - Win32 Release" || "$(CFG)" == "DibLook - Win32 Debug"
SOURCE=.\dibapi.cpp

"$(INTDIR)\dibapi.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\diblook.pch"


SOURCE=.\dibdoc.cpp

"$(INTDIR)\dibdoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\diblook.pch"


SOURCE=.\diblook.cpp

"$(INTDIR)\diblook.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\diblook.pch"


SOURCE=.\diblook.rc

"$(INTDIR)\diblook.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\dibview.cpp

"$(INTDIR)\dibview.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\diblook.pch"


SOURCE=.\mainfrm.cpp

"$(INTDIR)\mainfrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\diblook.pch"


SOURCE=.\myfile.cpp

"$(INTDIR)\myfile.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\diblook.pch"


SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "DibLook - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\diblook.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\diblook.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DibLook - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\diblook.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\diblook.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

