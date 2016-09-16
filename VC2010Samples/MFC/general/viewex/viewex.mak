# Microsoft Developer Studio Generated NMAKE File, Based on viewex.dsp
!IF "$(CFG)" == ""
CFG=Viewex - Win32 Release
!MESSAGE No configuration specified. Defaulting to Viewex - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Viewex - Win32 Release" && "$(CFG)" != "Viewex - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "viewex.mak" CFG="Viewex - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Viewex - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Viewex - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "Viewex - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\viewex.exe"


CLEAN :
	-@erase "$(INTDIR)\Enterdlg.obj"
	-@erase "$(INTDIR)\Inputvw.obj"
	-@erase "$(INTDIR)\Maindoc.obj"
	-@erase "$(INTDIR)\Simpvw.obj"
	-@erase "$(INTDIR)\Splitter.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\Viewex.obj"
	-@erase "$(INTDIR)\viewex.pch"
	-@erase "$(INTDIR)\Viewex.res"
	-@erase "$(OUTDIR)\viewex.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\viewex.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Viewex.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\viewex.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\viewex.pdb" /machine:I386 /out:"$(OUTDIR)\viewex.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Enterdlg.obj" \
	"$(INTDIR)\Inputvw.obj" \
	"$(INTDIR)\Maindoc.obj" \
	"$(INTDIR)\Simpvw.obj" \
	"$(INTDIR)\Splitter.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Viewex.obj" \
	"$(INTDIR)\Viewex.res"

"$(OUTDIR)\viewex.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Viewex - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\viewex.exe"


CLEAN :
	-@erase "$(INTDIR)\Enterdlg.obj"
	-@erase "$(INTDIR)\Inputvw.obj"
	-@erase "$(INTDIR)\Maindoc.obj"
	-@erase "$(INTDIR)\Simpvw.obj"
	-@erase "$(INTDIR)\Splitter.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\Viewex.obj"
	-@erase "$(INTDIR)\viewex.pch"
	-@erase "$(INTDIR)\Viewex.res"
	-@erase "$(OUTDIR)\viewex.exe"
	-@erase "$(OUTDIR)\viewex.ilk"
	-@erase "$(OUTDIR)\viewex.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\viewex.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Viewex.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\viewex.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\viewex.pdb" /debug /machine:I386 /out:"$(OUTDIR)\viewex.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Enterdlg.obj" \
	"$(INTDIR)\Inputvw.obj" \
	"$(INTDIR)\Maindoc.obj" \
	"$(INTDIR)\Simpvw.obj" \
	"$(INTDIR)\Splitter.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Viewex.obj" \
	"$(INTDIR)\Viewex.res"

"$(OUTDIR)\viewex.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("viewex.dep")
!INCLUDE "viewex.dep"
!ELSE 
!MESSAGE Warning: cannot find "viewex.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Viewex - Win32 Release" || "$(CFG)" == "Viewex - Win32 Debug"
SOURCE=.\Enterdlg.cpp

"$(INTDIR)\Enterdlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\viewex.pch"


SOURCE=.\Inputvw.cpp

"$(INTDIR)\Inputvw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\viewex.pch"


SOURCE=.\Maindoc.cpp

"$(INTDIR)\Maindoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\viewex.pch"


SOURCE=.\Simpvw.cpp

"$(INTDIR)\Simpvw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\viewex.pch"


SOURCE=.\Splitter.cpp

"$(INTDIR)\Splitter.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\viewex.pch"


SOURCE=.\Stdafx.cpp

!IF  "$(CFG)" == "Viewex - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\viewex.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\viewex.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Viewex - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\viewex.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\viewex.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Viewex.cpp

"$(INTDIR)\Viewex.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\viewex.pch"


SOURCE=.\Viewex.rc

"$(INTDIR)\Viewex.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)



!ENDIF 

