# Microsoft Developer Studio Generated NMAKE File, Based on dynamenu.dsp
!IF "$(CFG)" == ""
CFG=DynaMenu - Win32 Release
!MESSAGE No configuration specified. Defaulting to DynaMenu - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "DynaMenu - Win32 Release" && "$(CFG)" != "DynaMenu - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "dynamenu.mak" CFG="DynaMenu - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DynaMenu - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "DynaMenu - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "DynaMenu - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\dynamenu.exe"


CLEAN :
	-@erase "$(INTDIR)\coloropt.obj"
	-@erase "$(INTDIR)\dmdoc.obj"
	-@erase "$(INTDIR)\dmview.obj"
	-@erase "$(INTDIR)\dynamenu.obj"
	-@erase "$(INTDIR)\dynamenu.pch"
	-@erase "$(INTDIR)\dynamenu.res"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\mdichild.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\dynamenu.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\dynamenu.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\dynamenu.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\dynamenu.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\dynamenu.pdb" /machine:I386 /out:"$(OUTDIR)\dynamenu.exe" 
LINK32_OBJS= \
	"$(INTDIR)\coloropt.obj" \
	"$(INTDIR)\dmdoc.obj" \
	"$(INTDIR)\dmview.obj" \
	"$(INTDIR)\dynamenu.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\mdichild.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\dynamenu.res"

"$(OUTDIR)\dynamenu.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "DynaMenu - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\dynamenu.exe"


CLEAN :
	-@erase "$(INTDIR)\coloropt.obj"
	-@erase "$(INTDIR)\dmdoc.obj"
	-@erase "$(INTDIR)\dmview.obj"
	-@erase "$(INTDIR)\dynamenu.obj"
	-@erase "$(INTDIR)\dynamenu.pch"
	-@erase "$(INTDIR)\dynamenu.res"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\mdichild.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\dynamenu.exe"
	-@erase "$(OUTDIR)\dynamenu.ilk"
	-@erase "$(OUTDIR)\dynamenu.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\dynamenu.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\dynamenu.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\dynamenu.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\dynamenu.pdb" /debug /machine:I386 /out:"$(OUTDIR)\dynamenu.exe" 
LINK32_OBJS= \
	"$(INTDIR)\coloropt.obj" \
	"$(INTDIR)\dmdoc.obj" \
	"$(INTDIR)\dmview.obj" \
	"$(INTDIR)\dynamenu.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\mdichild.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\dynamenu.res"

"$(OUTDIR)\dynamenu.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("dynamenu.dep")
!INCLUDE "dynamenu.dep"
!ELSE 
!MESSAGE Warning: cannot find "dynamenu.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "DynaMenu - Win32 Release" || "$(CFG)" == "DynaMenu - Win32 Debug"
SOURCE=.\coloropt.cpp

"$(INTDIR)\coloropt.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\dynamenu.pch"


SOURCE=.\dmdoc.cpp

"$(INTDIR)\dmdoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\dynamenu.pch"


SOURCE=.\dmview.cpp

"$(INTDIR)\dmview.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\dynamenu.pch"


SOURCE=.\dynamenu.cpp

"$(INTDIR)\dynamenu.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\dynamenu.pch"


SOURCE=.\dynamenu.rc

"$(INTDIR)\dynamenu.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\mainfrm.cpp

"$(INTDIR)\mainfrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\dynamenu.pch"


SOURCE=.\mdichild.cpp

"$(INTDIR)\mdichild.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\dynamenu.pch"


SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "DynaMenu - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\dynamenu.pch" /Yc"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\dynamenu.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DynaMenu - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\dynamenu.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\dynamenu.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

