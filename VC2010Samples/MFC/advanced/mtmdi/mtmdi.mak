# Microsoft Developer Studio Generated NMAKE File, Based on mtmdi.dsp
!IF "$(CFG)" == ""
CFG=MtMdi - Win32 Release
!MESSAGE No configuration specified. Defaulting to MtMdi - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "MtMdi - Win32 Release" && "$(CFG)" != "MtMdi - Win32 Debug" && "$(CFG)" != "MtMdi - Win32 Unicode Debug" && "$(CFG)" != "MtMdi - Win32 Unicode Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mtmdi.mak" CFG="MtMdi - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MtMdi - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "MtMdi - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "MtMdi - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE "MtMdi - Win32 Unicode Release" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "MtMdi - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\mtmdi.exe"


CLEAN :
	-@erase "$(INTDIR)\Bounce.obj"
	-@erase "$(INTDIR)\Hello.obj"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Mdi.obj"
	-@erase "$(INTDIR)\Mtbounce.obj"
	-@erase "$(INTDIR)\mtmdi.pch"
	-@erase "$(INTDIR)\Mtmdi.res"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\mtmdi.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mtmdi.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Mtmdi.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mtmdi.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\mtmdi.pdb" /machine:I386 /out:"$(OUTDIR)\mtmdi.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Bounce.obj" \
	"$(INTDIR)\Hello.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Mdi.obj" \
	"$(INTDIR)\Mtbounce.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Mtmdi.res"

"$(OUTDIR)\mtmdi.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MtMdi - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\mtmdi.exe"


CLEAN :
	-@erase "$(INTDIR)\Bounce.obj"
	-@erase "$(INTDIR)\Hello.obj"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Mdi.obj"
	-@erase "$(INTDIR)\Mtbounce.obj"
	-@erase "$(INTDIR)\mtmdi.pch"
	-@erase "$(INTDIR)\Mtmdi.res"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\mtmdi.exe"
	-@erase "$(OUTDIR)\mtmdi.ilk"
	-@erase "$(OUTDIR)\mtmdi.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mtmdi.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Mtmdi.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mtmdi.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\mtmdi.pdb" /debug /machine:I386 /out:"$(OUTDIR)\mtmdi.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Bounce.obj" \
	"$(INTDIR)\Hello.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Mdi.obj" \
	"$(INTDIR)\Mtbounce.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Mtmdi.res"

"$(OUTDIR)\mtmdi.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MtMdi - Win32 Unicode Debug"

OUTDIR=.\UniDebug
INTDIR=.\UniDebug
# Begin Custom Macros
OutDir=.\.\UniDebug
# End Custom Macros

ALL : "$(OUTDIR)\mtmdi.exe"


CLEAN :
	-@erase "$(INTDIR)\Bounce.obj"
	-@erase "$(INTDIR)\Hello.obj"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Mdi.obj"
	-@erase "$(INTDIR)\Mtbounce.obj"
	-@erase "$(INTDIR)\mtmdi.pch"
	-@erase "$(INTDIR)\Mtmdi.res"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\mtmdi.exe"
	-@erase "$(OUTDIR)\mtmdi.ilk"
	-@erase "$(OUTDIR)\mtmdi.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mtmdi.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Mtmdi.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mtmdi.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\mtmdi.pdb" /debug /machine:I386 /out:"$(OUTDIR)\mtmdi.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Bounce.obj" \
	"$(INTDIR)\Hello.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Mdi.obj" \
	"$(INTDIR)\Mtbounce.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Mtmdi.res"

"$(OUTDIR)\mtmdi.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MtMdi - Win32 Unicode Release"

OUTDIR=.\UniRelease
INTDIR=.\UniRelease
# Begin Custom Macros
OutDir=.\.\UniRelease
# End Custom Macros

ALL : "$(OUTDIR)\mtmdi.exe"


CLEAN :
	-@erase "$(INTDIR)\Bounce.obj"
	-@erase "$(INTDIR)\Hello.obj"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Mdi.obj"
	-@erase "$(INTDIR)\Mtbounce.obj"
	-@erase "$(INTDIR)\mtmdi.pch"
	-@erase "$(INTDIR)\Mtmdi.res"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\mtmdi.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mtmdi.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Mtmdi.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mtmdi.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\mtmdi.pdb" /machine:I386 /out:"$(OUTDIR)\mtmdi.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Bounce.obj" \
	"$(INTDIR)\Hello.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Mdi.obj" \
	"$(INTDIR)\Mtbounce.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Mtmdi.res"

"$(OUTDIR)\mtmdi.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("mtmdi.dep")
!INCLUDE "mtmdi.dep"
!ELSE 
!MESSAGE Warning: cannot find "mtmdi.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "MtMdi - Win32 Release" || "$(CFG)" == "MtMdi - Win32 Debug" || "$(CFG)" == "MtMdi - Win32 Unicode Debug" || "$(CFG)" == "MtMdi - Win32 Unicode Release"
SOURCE=.\Bounce.cpp

"$(INTDIR)\Bounce.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mtmdi.pch"


SOURCE=.\Hello.cpp

"$(INTDIR)\Hello.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mtmdi.pch"


SOURCE=.\Mainfrm.cpp

"$(INTDIR)\Mainfrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mtmdi.pch"


SOURCE=.\Mdi.cpp

"$(INTDIR)\Mdi.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mtmdi.pch"


SOURCE=.\Mtbounce.cpp

"$(INTDIR)\Mtbounce.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mtmdi.pch"


SOURCE=.\Mtmdi.rc

"$(INTDIR)\Mtmdi.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\Stdafx.cpp

!IF  "$(CFG)" == "MtMdi - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mtmdi.pch" /Yc"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\mtmdi.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MtMdi - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mtmdi.pch" /Yc"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\mtmdi.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MtMdi - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mtmdi.pch" /Yc"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\mtmdi.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MtMdi - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mtmdi.pch" /Yc"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\mtmdi.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

