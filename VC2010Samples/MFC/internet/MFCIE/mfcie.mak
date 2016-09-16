# Microsoft Developer Studio Generated NMAKE File, Based on mfcie.dsp
!IF "$(CFG)" == ""
CFG=mfcie - Win32 Static Debug
!MESSAGE No configuration specified. Defaulting to mfcie - Win32 Static Debug.
!ENDIF 

!IF "$(CFG)" != "mfcie - Win32 Release" && "$(CFG)" != "mfcie - Win32 Debug" && "$(CFG)" != "mfcie - Win32 Unicode Debug" && "$(CFG)" != "mfcie - Win32 Unicode Release" && "$(CFG)" != "mfcie - Win32 Static Debug" && "$(CFG)" != "mfcie - Win32 Static Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mfcie.mak" CFG="mfcie - Win32 Static Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mfcie - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "mfcie - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "mfcie - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE "mfcie - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "mfcie - Win32 Static Debug" (based on "Win32 (x86) Application")
!MESSAGE "mfcie - Win32 Static Release" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "mfcie - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\mfcie.exe"


CLEAN :
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\mfcie.obj"
	-@erase "$(INTDIR)\mfcie.pch"
	-@erase "$(INTDIR)\mfcie.res"
	-@erase "$(INTDIR)\mfcieDoc.obj"
	-@erase "$(INTDIR)\mfcieVw.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\mfcie.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\mfcie.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\mfcie.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mfcie.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\mfcie.pdb" /machine:I386 /out:"$(OUTDIR)\mfcie.exe" 
LINK32_OBJS= \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\mfcie.obj" \
	"$(INTDIR)\mfcieDoc.obj" \
	"$(INTDIR)\mfcieVw.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\mfcie.res"

"$(OUTDIR)\mfcie.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "mfcie - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\mfcie.exe"


CLEAN :
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\mfcie.obj"
	-@erase "$(INTDIR)\mfcie.pch"
	-@erase "$(INTDIR)\mfcie.res"
	-@erase "$(INTDIR)\mfcieDoc.obj"
	-@erase "$(INTDIR)\mfcieVw.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\mfcie.exe"
	-@erase "$(OUTDIR)\mfcie.ilk"
	-@erase "$(OUTDIR)\mfcie.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\mfcie.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\mfcie.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mfcie.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\mfcie.pdb" /debug /machine:I386 /out:"$(OUTDIR)\mfcie.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\mfcie.obj" \
	"$(INTDIR)\mfcieDoc.obj" \
	"$(INTDIR)\mfcieVw.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\mfcie.res"

"$(OUTDIR)\mfcie.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "mfcie - Win32 Unicode Debug"

OUTDIR=.\UDebug
INTDIR=.\UDebug
# Begin Custom Macros
OutDir=.\UDebug
# End Custom Macros

ALL : "$(OUTDIR)\mfcie.exe"


CLEAN :
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\mfcie.obj"
	-@erase "$(INTDIR)\mfcie.pch"
	-@erase "$(INTDIR)\mfcie.res"
	-@erase "$(INTDIR)\mfcieDoc.obj"
	-@erase "$(INTDIR)\mfcieVw.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\mfcie.exe"
	-@erase "$(OUTDIR)\mfcie.ilk"
	-@erase "$(OUTDIR)\mfcie.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /Fp"$(INTDIR)\mfcie.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\mfcie.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mfcie.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\mfcie.pdb" /debug /machine:I386 /out:"$(OUTDIR)\mfcie.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\mfcie.obj" \
	"$(INTDIR)\mfcieDoc.obj" \
	"$(INTDIR)\mfcieVw.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\mfcie.res"

"$(OUTDIR)\mfcie.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "mfcie - Win32 Unicode Release"

OUTDIR=.\URelease
INTDIR=.\URelease
# Begin Custom Macros
OutDir=.\URelease
# End Custom Macros

ALL : "$(OUTDIR)\mfcie.exe"


CLEAN :
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\mfcie.obj"
	-@erase "$(INTDIR)\mfcie.pch"
	-@erase "$(INTDIR)\mfcie.res"
	-@erase "$(INTDIR)\mfcieDoc.obj"
	-@erase "$(INTDIR)\mfcieVw.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\mfcie.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /Fp"$(INTDIR)\mfcie.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\mfcie.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mfcie.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\mfcie.pdb" /machine:I386 /out:"$(OUTDIR)\mfcie.exe" 
LINK32_OBJS= \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\mfcie.obj" \
	"$(INTDIR)\mfcieDoc.obj" \
	"$(INTDIR)\mfcieVw.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\mfcie.res"

"$(OUTDIR)\mfcie.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "mfcie - Win32 Static Debug"

OUTDIR=.\StaticDebug
INTDIR=.\StaticDebug
# Begin Custom Macros
OutDir=.\StaticDebug
# End Custom Macros

ALL : "$(OUTDIR)\mfcie.exe"


CLEAN :
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\mfcie.obj"
	-@erase "$(INTDIR)\mfcie.pch"
	-@erase "$(INTDIR)\mfcie.res"
	-@erase "$(INTDIR)\mfcieDoc.obj"
	-@erase "$(INTDIR)\mfcieVw.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\mfcie.exe"
	-@erase "$(OUTDIR)\mfcie.ilk"
	-@erase "$(OUTDIR)\mfcie.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\mfcie.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\mfcie.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mfcie.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\mfcie.pdb" /debug /machine:I386 /out:"$(OUTDIR)\mfcie.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\mfcie.obj" \
	"$(INTDIR)\mfcieDoc.obj" \
	"$(INTDIR)\mfcieVw.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\mfcie.res"

"$(OUTDIR)\mfcie.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "mfcie - Win32 Static Release"

OUTDIR=.\StaticRelease
INTDIR=.\StaticRelease
# Begin Custom Macros
OutDir=.\StaticRelease
# End Custom Macros

ALL : "$(OUTDIR)\mfcie.exe"


CLEAN :
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\mfcie.obj"
	-@erase "$(INTDIR)\mfcie.pch"
	-@erase "$(INTDIR)\mfcie.res"
	-@erase "$(INTDIR)\mfcieDoc.obj"
	-@erase "$(INTDIR)\mfcieVw.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\mfcie.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\mfcie.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\mfcie.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mfcie.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\mfcie.pdb" /machine:I386 /out:"$(OUTDIR)\mfcie.exe" 
LINK32_OBJS= \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\mfcie.obj" \
	"$(INTDIR)\mfcieDoc.obj" \
	"$(INTDIR)\mfcieVw.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\mfcie.res"

"$(OUTDIR)\mfcie.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("mfcie.dep")
!INCLUDE "mfcie.dep"
!ELSE 
!MESSAGE Warning: cannot find "mfcie.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "mfcie - Win32 Release" || "$(CFG)" == "mfcie - Win32 Debug" || "$(CFG)" == "mfcie - Win32 Unicode Debug" || "$(CFG)" == "mfcie - Win32 Unicode Release" || "$(CFG)" == "mfcie - Win32 Static Debug" || "$(CFG)" == "mfcie - Win32 Static Release"
SOURCE=.\MainFrm.cpp

"$(INTDIR)\MainFrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mfcie.pch"


SOURCE=.\mfcie.cpp

"$(INTDIR)\mfcie.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mfcie.pch"


SOURCE=.\mfcie.rc

"$(INTDIR)\mfcie.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\mfcieDoc.cpp

"$(INTDIR)\mfcieDoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mfcie.pch"


SOURCE=.\mfcieVw.cpp

"$(INTDIR)\mfcieVw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mfcie.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "mfcie - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\mfcie.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\mfcie.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "mfcie - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\mfcie.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\mfcie.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "mfcie - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /Fp"$(INTDIR)\mfcie.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\mfcie.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "mfcie - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /Fp"$(INTDIR)\mfcie.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\mfcie.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "mfcie - Win32 Static Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\mfcie.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\mfcie.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "mfcie - Win32 Static Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\mfcie.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\mfcie.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

