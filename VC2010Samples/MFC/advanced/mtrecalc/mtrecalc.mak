# Microsoft Developer Studio Generated NMAKE File, Based on mtrecalc.dsp
!IF "$(CFG)" == ""
CFG=MtRecalc - Win32 Release
!MESSAGE No configuration specified. Defaulting to MtRecalc - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "MtRecalc - Win32 Release" && "$(CFG)" != "MtRecalc - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mtrecalc.mak" CFG="MtRecalc - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MtRecalc - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "MtRecalc - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "MtRecalc - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\mtrecalc.exe"


CLEAN :
	-@erase "$(INTDIR)\Calcthrd.obj"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Mtrecalc.obj"
	-@erase "$(INTDIR)\mtrecalc.pch"
	-@erase "$(INTDIR)\Mtrecalc.res"
	-@erase "$(INTDIR)\Recalcvw.obj"
	-@erase "$(INTDIR)\Recaldoc.obj"
	-@erase "$(INTDIR)\Slowcalc.obj"
	-@erase "$(INTDIR)\Speeddlg.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\mtrecalc.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mtrecalc.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Mtrecalc.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mtrecalc.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\mtrecalc.pdb" /machine:I386 /out:"$(OUTDIR)\mtrecalc.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Calcthrd.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Mtrecalc.obj" \
	"$(INTDIR)\Recalcvw.obj" \
	"$(INTDIR)\Recaldoc.obj" \
	"$(INTDIR)\Slowcalc.obj" \
	"$(INTDIR)\Speeddlg.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Mtrecalc.res"

"$(OUTDIR)\mtrecalc.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MtRecalc - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\mtrecalc.exe"


CLEAN :
	-@erase "$(INTDIR)\Calcthrd.obj"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Mtrecalc.obj"
	-@erase "$(INTDIR)\mtrecalc.pch"
	-@erase "$(INTDIR)\Mtrecalc.res"
	-@erase "$(INTDIR)\Recalcvw.obj"
	-@erase "$(INTDIR)\Recaldoc.obj"
	-@erase "$(INTDIR)\Slowcalc.obj"
	-@erase "$(INTDIR)\Speeddlg.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\mtrecalc.exe"
	-@erase "$(OUTDIR)\mtrecalc.ilk"
	-@erase "$(OUTDIR)\mtrecalc.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mtrecalc.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Mtrecalc.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mtrecalc.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\mtrecalc.pdb" /debug /machine:I386 /out:"$(OUTDIR)\mtrecalc.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Calcthrd.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Mtrecalc.obj" \
	"$(INTDIR)\Recalcvw.obj" \
	"$(INTDIR)\Recaldoc.obj" \
	"$(INTDIR)\Slowcalc.obj" \
	"$(INTDIR)\Speeddlg.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Mtrecalc.res"

"$(OUTDIR)\mtrecalc.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("mtrecalc.dep")
!INCLUDE "mtrecalc.dep"
!ELSE 
!MESSAGE Warning: cannot find "mtrecalc.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "MtRecalc - Win32 Release" || "$(CFG)" == "MtRecalc - Win32 Debug"
SOURCE=.\Calcthrd.cpp

"$(INTDIR)\Calcthrd.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mtrecalc.pch"


SOURCE=.\Mainfrm.cpp

"$(INTDIR)\Mainfrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mtrecalc.pch"


SOURCE=.\Mtrecalc.cpp

"$(INTDIR)\Mtrecalc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mtrecalc.pch"


SOURCE=.\Mtrecalc.rc

"$(INTDIR)\Mtrecalc.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\Recalcvw.cpp

"$(INTDIR)\Recalcvw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mtrecalc.pch"


SOURCE=.\Recaldoc.cpp

"$(INTDIR)\Recaldoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mtrecalc.pch"


SOURCE=.\Slowcalc.cpp

"$(INTDIR)\Slowcalc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mtrecalc.pch"


SOURCE=.\Speeddlg.cpp

"$(INTDIR)\Speeddlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mtrecalc.pch"


SOURCE=.\Stdafx.cpp

!IF  "$(CFG)" == "MtRecalc - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mtrecalc.pch" /Yc"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\mtrecalc.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MtRecalc - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mtrecalc.pch" /Yc"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\mtrecalc.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

