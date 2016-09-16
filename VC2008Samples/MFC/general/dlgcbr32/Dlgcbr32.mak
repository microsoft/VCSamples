# Microsoft Developer Studio Generated NMAKE File, Based on Dlgcbr32.dsp
!IF "$(CFG)" == ""
CFG=DLGCBAR - Win32 Release
!MESSAGE No configuration specified. Defaulting to DLGCBAR - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "DLGCBAR - Win32 Release" && "$(CFG)" != "DLGCBAR - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Dlgcbr32.mak" CFG="DLGCBAR - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DLGCBAR - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "DLGCBAR - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "DLGCBAR - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\Dlgcbr32.exe"


CLEAN :
	-@erase "$(INTDIR)\ABOUTDLG.OBJ"
	-@erase "$(INTDIR)\Dlgbars.obj"
	-@erase "$(INTDIR)\DLGCBAR.OBJ"
	-@erase "$(INTDIR)\DLGCBAR.res"
	-@erase "$(INTDIR)\Dlgcbr32.pch"
	-@erase "$(INTDIR)\MDLSMAIN.OBJ"
	-@erase "$(INTDIR)\MODELESS.OBJ"
	-@erase "$(INTDIR)\RATEDLG.OBJ"
	-@erase "$(INTDIR)\STDAFX.OBJ"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\WNDLIST.OBJ"
	-@erase "$(OUTDIR)\Dlgcbr32.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /WX /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Dlgcbr32.pch" /Yu"STDAFX.H" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\DLGCBAR.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Dlgcbr32.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=oldnames.lib /nologo /stack:0x2800 /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\Dlgcbr32.pdb" /machine:IX86 /out:"$(OUTDIR)\Dlgcbr32.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ABOUTDLG.OBJ" \
	"$(INTDIR)\Dlgbars.obj" \
	"$(INTDIR)\DLGCBAR.OBJ" \
	"$(INTDIR)\MDLSMAIN.OBJ" \
	"$(INTDIR)\MODELESS.OBJ" \
	"$(INTDIR)\RATEDLG.OBJ" \
	"$(INTDIR)\STDAFX.OBJ" \
	"$(INTDIR)\WNDLIST.OBJ" \
	"$(INTDIR)\DLGCBAR.res"

"$(OUTDIR)\Dlgcbr32.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "DLGCBAR - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Dlgcbr32.exe"


CLEAN :
	-@erase "$(INTDIR)\ABOUTDLG.OBJ"
	-@erase "$(INTDIR)\Dlgbars.obj"
	-@erase "$(INTDIR)\DLGCBAR.OBJ"
	-@erase "$(INTDIR)\DLGCBAR.res"
	-@erase "$(INTDIR)\Dlgcbr32.pch"
	-@erase "$(INTDIR)\MDLSMAIN.OBJ"
	-@erase "$(INTDIR)\MODELESS.OBJ"
	-@erase "$(INTDIR)\RATEDLG.OBJ"
	-@erase "$(INTDIR)\STDAFX.OBJ"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\WNDLIST.OBJ"
	-@erase "$(OUTDIR)\Dlgcbr32.exe"
	-@erase "$(OUTDIR)\Dlgcbr32.ilk"
	-@erase "$(OUTDIR)\Dlgcbr32.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /WX /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Dlgcbr32.pch" /Yu"STDAFX.H" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\DLGCBAR.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Dlgcbr32.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=oldnames.lib /nologo /stack:0x2800 /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\Dlgcbr32.pdb" /debug /machine:IX86 /out:"$(OUTDIR)\Dlgcbr32.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ABOUTDLG.OBJ" \
	"$(INTDIR)\Dlgbars.obj" \
	"$(INTDIR)\DLGCBAR.OBJ" \
	"$(INTDIR)\MDLSMAIN.OBJ" \
	"$(INTDIR)\MODELESS.OBJ" \
	"$(INTDIR)\RATEDLG.OBJ" \
	"$(INTDIR)\STDAFX.OBJ" \
	"$(INTDIR)\WNDLIST.OBJ" \
	"$(INTDIR)\DLGCBAR.res"

"$(OUTDIR)\Dlgcbr32.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("Dlgcbr32.dep")
!INCLUDE "Dlgcbr32.dep"
!ELSE 
!MESSAGE Warning: cannot find "Dlgcbr32.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "DLGCBAR - Win32 Release" || "$(CFG)" == "DLGCBAR - Win32 Debug"
SOURCE=.\ABOUTDLG.CPP

"$(INTDIR)\ABOUTDLG.OBJ" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Dlgcbr32.pch"


SOURCE=.\Dlgbars.cpp

"$(INTDIR)\Dlgbars.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Dlgcbr32.pch"


SOURCE=.\DLGCBAR.CPP

"$(INTDIR)\DLGCBAR.OBJ" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Dlgcbr32.pch"


SOURCE=.\DLGCBAR.RC

"$(INTDIR)\DLGCBAR.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\MDLSMAIN.CPP

"$(INTDIR)\MDLSMAIN.OBJ" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Dlgcbr32.pch"


SOURCE=.\MODELESS.CPP

"$(INTDIR)\MODELESS.OBJ" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Dlgcbr32.pch"


SOURCE=.\RATEDLG.CPP

"$(INTDIR)\RATEDLG.OBJ" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Dlgcbr32.pch"


SOURCE=.\STDAFX.CPP

!IF  "$(CFG)" == "DLGCBAR - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /WX /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Dlgcbr32.pch" /Yc"STDAFX.H" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\STDAFX.OBJ"	"$(INTDIR)\Dlgcbr32.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DLGCBAR - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /WX /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Dlgcbr32.pch" /Yc"STDAFX.H" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\STDAFX.OBJ"	"$(INTDIR)\Dlgcbr32.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\WNDLIST.CPP

"$(INTDIR)\WNDLIST.OBJ" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Dlgcbr32.pch"



!ENDIF 

