# Microsoft Developer Studio Generated NMAKE File, Based on cube.dsp
!IF "$(CFG)" == ""
CFG=Cube - Win32 Release
!MESSAGE No configuration specified. Defaulting to Cube - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Cube - Win32 Release" && "$(CFG)" != "Cube - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "cube.mak" CFG="Cube - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Cube - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Cube - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "Cube - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\cube.exe"


CLEAN :
	-@erase "$(INTDIR)\Cube.obj"
	-@erase "$(INTDIR)\cube.pch"
	-@erase "$(INTDIR)\Cube.res"
	-@erase "$(INTDIR)\Cubedoc.obj"
	-@erase "$(INTDIR)\Cubeview.obj"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\cube.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\cube.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Cube.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\cube.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=opengl32.lib glu32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\cube.pdb" /machine:I386 /out:"$(OUTDIR)\cube.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Cube.obj" \
	"$(INTDIR)\Cubedoc.obj" \
	"$(INTDIR)\Cubeview.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Cube.res"

"$(OUTDIR)\cube.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Cube - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\cube.exe"


CLEAN :
	-@erase "$(INTDIR)\Cube.obj"
	-@erase "$(INTDIR)\cube.pch"
	-@erase "$(INTDIR)\Cube.res"
	-@erase "$(INTDIR)\Cubedoc.obj"
	-@erase "$(INTDIR)\Cubeview.obj"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\cube.exe"
	-@erase "$(OUTDIR)\cube.ilk"
	-@erase "$(OUTDIR)\cube.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\cube.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Cube.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\cube.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=opengl32.lib glu32.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\cube.pdb" /debug /machine:I386 /out:"$(OUTDIR)\cube.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Cube.obj" \
	"$(INTDIR)\Cubedoc.obj" \
	"$(INTDIR)\Cubeview.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Cube.res"

"$(OUTDIR)\cube.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("cube.dep")
!INCLUDE "cube.dep"
!ELSE 
!MESSAGE Warning: cannot find "cube.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Cube - Win32 Release" || "$(CFG)" == "Cube - Win32 Debug"
SOURCE=.\Cube.cpp

"$(INTDIR)\Cube.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\cube.pch"


SOURCE=.\Cube.rc

"$(INTDIR)\Cube.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\Cubedoc.cpp

"$(INTDIR)\Cubedoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\cube.pch"


SOURCE=.\Cubeview.cpp

"$(INTDIR)\Cubeview.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\cube.pch"


SOURCE=.\Mainfrm.cpp

"$(INTDIR)\Mainfrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\cube.pch"


SOURCE=.\Stdafx.cpp

!IF  "$(CFG)" == "Cube - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\cube.pch" /Yc"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\cube.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Cube - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\cube.pch" /Yc"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\cube.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

