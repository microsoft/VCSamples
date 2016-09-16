# Microsoft Developer Studio Generated NMAKE File, Based on mtgdi.dsp
!IF "$(CFG)" == ""
CFG=MtGdi - Win32 Release
!MESSAGE No configuration specified. Defaulting to MtGdi - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "MtGdi - Win32 Release" && "$(CFG)" != "MtGdi - Win32 Debug" && "$(CFG)" != "MtGdi - Win32 Unicode Release" && "$(CFG)" != "MtGdi - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mtgdi.mak" CFG="MtGdi - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MtGdi - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "MtGdi - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "MtGdi - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "MtGdi - Win32 Unicode Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "MtGdi - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\mtgdi.exe"


CLEAN :
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Mtgdi.obj"
	-@erase "$(INTDIR)\mtgdi.pch"
	-@erase "$(INTDIR)\Mtgdi.res"
	-@erase "$(INTDIR)\Mtgdidoc.obj"
	-@erase "$(INTDIR)\Mtgdivw.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\Threads.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\mtgdi.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mtgdi.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Mtgdi.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mtgdi.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\mtgdi.pdb" /machine:I386 /out:"$(OUTDIR)\mtgdi.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Mtgdi.obj" \
	"$(INTDIR)\Mtgdidoc.obj" \
	"$(INTDIR)\Mtgdivw.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Threads.obj" \
	"$(INTDIR)\Mtgdi.res"

"$(OUTDIR)\mtgdi.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MtGdi - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\mtgdi.exe"


CLEAN :
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Mtgdi.obj"
	-@erase "$(INTDIR)\mtgdi.pch"
	-@erase "$(INTDIR)\Mtgdi.res"
	-@erase "$(INTDIR)\Mtgdidoc.obj"
	-@erase "$(INTDIR)\Mtgdivw.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\Threads.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\mtgdi.exe"
	-@erase "$(OUTDIR)\mtgdi.ilk"
	-@erase "$(OUTDIR)\mtgdi.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mtgdi.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Mtgdi.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mtgdi.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\mtgdi.pdb" /debug /machine:I386 /out:"$(OUTDIR)\mtgdi.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Mtgdi.obj" \
	"$(INTDIR)\Mtgdidoc.obj" \
	"$(INTDIR)\Mtgdivw.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Threads.obj" \
	"$(INTDIR)\Mtgdi.res"

"$(OUTDIR)\mtgdi.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MtGdi - Win32 Unicode Release"

OUTDIR=.\UniRelease
INTDIR=.\UniRelease
# Begin Custom Macros
OutDir=.\.\UniRelease
# End Custom Macros

ALL : "$(OUTDIR)\mtgdi.exe"


CLEAN :
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Mtgdi.obj"
	-@erase "$(INTDIR)\mtgdi.pch"
	-@erase "$(INTDIR)\Mtgdi.res"
	-@erase "$(INTDIR)\Mtgdidoc.obj"
	-@erase "$(INTDIR)\Mtgdivw.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\Threads.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\mtgdi.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mtgdi.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Mtgdi.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mtgdi.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\mtgdi.pdb" /machine:I386 /out:"$(OUTDIR)\mtgdi.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Mtgdi.obj" \
	"$(INTDIR)\Mtgdidoc.obj" \
	"$(INTDIR)\Mtgdivw.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Threads.obj" \
	"$(INTDIR)\Mtgdi.res"

"$(OUTDIR)\mtgdi.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MtGdi - Win32 Unicode Debug"

OUTDIR=.\UniDebug
INTDIR=.\UniDebug
# Begin Custom Macros
OutDir=.\.\UniDebug
# End Custom Macros

ALL : "$(OUTDIR)\mtgdi.exe"


CLEAN :
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Mtgdi.obj"
	-@erase "$(INTDIR)\mtgdi.pch"
	-@erase "$(INTDIR)\Mtgdi.res"
	-@erase "$(INTDIR)\Mtgdidoc.obj"
	-@erase "$(INTDIR)\Mtgdivw.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\Threads.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\mtgdi.exe"
	-@erase "$(OUTDIR)\mtgdi.ilk"
	-@erase "$(OUTDIR)\mtgdi.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mtgdi.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Mtgdi.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mtgdi.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\mtgdi.pdb" /debug /machine:I386 /out:"$(OUTDIR)\mtgdi.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Mtgdi.obj" \
	"$(INTDIR)\Mtgdidoc.obj" \
	"$(INTDIR)\Mtgdivw.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Threads.obj" \
	"$(INTDIR)\Mtgdi.res"

"$(OUTDIR)\mtgdi.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("mtgdi.dep")
!INCLUDE "mtgdi.dep"
!ELSE 
!MESSAGE Warning: cannot find "mtgdi.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "MtGdi - Win32 Release" || "$(CFG)" == "MtGdi - Win32 Debug" || "$(CFG)" == "MtGdi - Win32 Unicode Release" || "$(CFG)" == "MtGdi - Win32 Unicode Debug"
SOURCE=.\Mainfrm.cpp

"$(INTDIR)\Mainfrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mtgdi.pch"


SOURCE=.\Mtgdi.cpp

"$(INTDIR)\Mtgdi.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mtgdi.pch"


SOURCE=.\Mtgdi.rc

"$(INTDIR)\Mtgdi.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\Mtgdidoc.cpp

"$(INTDIR)\Mtgdidoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mtgdi.pch"


SOURCE=.\Mtgdivw.cpp

"$(INTDIR)\Mtgdivw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mtgdi.pch"


SOURCE=.\Stdafx.cpp

!IF  "$(CFG)" == "MtGdi - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mtgdi.pch" /Yc"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\mtgdi.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MtGdi - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mtgdi.pch" /Yc"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\mtgdi.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MtGdi - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mtgdi.pch" /Yc"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\mtgdi.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MtGdi - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mtgdi.pch" /Yc"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\mtgdi.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Threads.cpp

"$(INTDIR)\Threads.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mtgdi.pch"



!ENDIF 

