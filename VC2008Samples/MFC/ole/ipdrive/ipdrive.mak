# Microsoft Developer Studio Generated NMAKE File, Based on ipdrive.dsp
!IF "$(CFG)" == ""
CFG=IpDrive - Win32 Release
!MESSAGE No configuration specified. Defaulting to IpDrive - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "IpDrive - Win32 Release" && "$(CFG)" != "IpDrive - Win32 Debug" && "$(CFG)" != "IpDrive - Win32 Unicode Release" && "$(CFG)" != "IpDrive - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ipdrive.mak" CFG="IpDrive - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "IpDrive - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "IpDrive - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "IpDrive - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "IpDrive - Win32 Unicode Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "IpDrive - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\ipdrive.exe" "$(OUTDIR)\ipdrive.bsc"


CLEAN :
	-@erase "$(INTDIR)\Ipdridoc.obj"
	-@erase "$(INTDIR)\Ipdridoc.sbr"
	-@erase "$(INTDIR)\Ipdrive.obj"
	-@erase "$(INTDIR)\ipdrive.pch"
	-@erase "$(INTDIR)\Ipdrive.res"
	-@erase "$(INTDIR)\Ipdrive.sbr"
	-@erase "$(INTDIR)\Ipdrivw.obj"
	-@erase "$(INTDIR)\Ipdrivw.sbr"
	-@erase "$(INTDIR)\Ipremote.obj"
	-@erase "$(INTDIR)\Ipremote.sbr"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Mainfrm.sbr"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\Stdafx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\ipdrive.bsc"
	-@erase "$(OUTDIR)\ipdrive.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ipdrive.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Ipdrive.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ipdrive.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Ipdridoc.sbr" \
	"$(INTDIR)\Ipdrive.sbr" \
	"$(INTDIR)\Ipdrivw.sbr" \
	"$(INTDIR)\Ipremote.sbr" \
	"$(INTDIR)\Mainfrm.sbr" \
	"$(INTDIR)\Stdafx.sbr"

"$(OUTDIR)\ipdrive.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\ipdrive.pdb" /machine:I386 /out:"$(OUTDIR)\ipdrive.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Ipdridoc.obj" \
	"$(INTDIR)\Ipdrive.obj" \
	"$(INTDIR)\Ipdrivw.obj" \
	"$(INTDIR)\Ipremote.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Ipdrive.res"

"$(OUTDIR)\ipdrive.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "IpDrive - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\ipdrive.exe" "$(OUTDIR)\ipdrive.bsc"


CLEAN :
	-@erase "$(INTDIR)\Ipdridoc.obj"
	-@erase "$(INTDIR)\Ipdridoc.sbr"
	-@erase "$(INTDIR)\Ipdrive.obj"
	-@erase "$(INTDIR)\ipdrive.pch"
	-@erase "$(INTDIR)\Ipdrive.res"
	-@erase "$(INTDIR)\Ipdrive.sbr"
	-@erase "$(INTDIR)\Ipdrivw.obj"
	-@erase "$(INTDIR)\Ipdrivw.sbr"
	-@erase "$(INTDIR)\Ipremote.obj"
	-@erase "$(INTDIR)\Ipremote.sbr"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Mainfrm.sbr"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\Stdafx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\ipdrive.bsc"
	-@erase "$(OUTDIR)\ipdrive.exe"
	-@erase "$(OUTDIR)\ipdrive.ilk"
	-@erase "$(OUTDIR)\ipdrive.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ipdrive.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Ipdrive.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ipdrive.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Ipdridoc.sbr" \
	"$(INTDIR)\Ipdrive.sbr" \
	"$(INTDIR)\Ipdrivw.sbr" \
	"$(INTDIR)\Ipremote.sbr" \
	"$(INTDIR)\Mainfrm.sbr" \
	"$(INTDIR)\Stdafx.sbr"

"$(OUTDIR)\ipdrive.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\ipdrive.pdb" /debug /machine:I386 /out:"$(OUTDIR)\ipdrive.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Ipdridoc.obj" \
	"$(INTDIR)\Ipdrive.obj" \
	"$(INTDIR)\Ipdrivw.obj" \
	"$(INTDIR)\Ipremote.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Ipdrive.res"

"$(OUTDIR)\ipdrive.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "IpDrive - Win32 Unicode Release"

OUTDIR=.\UniRelease
INTDIR=.\UniRelease
# Begin Custom Macros
OutDir=.\.\UniRelease
# End Custom Macros

ALL : "$(OUTDIR)\ipdrive.exe" "$(OUTDIR)\ipdrive.bsc"


CLEAN :
	-@erase "$(INTDIR)\Ipdridoc.obj"
	-@erase "$(INTDIR)\Ipdridoc.sbr"
	-@erase "$(INTDIR)\Ipdrive.obj"
	-@erase "$(INTDIR)\ipdrive.pch"
	-@erase "$(INTDIR)\Ipdrive.res"
	-@erase "$(INTDIR)\Ipdrive.sbr"
	-@erase "$(INTDIR)\Ipdrivw.obj"
	-@erase "$(INTDIR)\Ipdrivw.sbr"
	-@erase "$(INTDIR)\Ipremote.obj"
	-@erase "$(INTDIR)\Ipremote.sbr"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Mainfrm.sbr"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\Stdafx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\ipdrive.bsc"
	-@erase "$(OUTDIR)\ipdrive.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ipdrive.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Ipdrive.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ipdrive.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Ipdridoc.sbr" \
	"$(INTDIR)\Ipdrive.sbr" \
	"$(INTDIR)\Ipdrivw.sbr" \
	"$(INTDIR)\Ipremote.sbr" \
	"$(INTDIR)\Mainfrm.sbr" \
	"$(INTDIR)\Stdafx.sbr"

"$(OUTDIR)\ipdrive.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\ipdrive.pdb" /machine:I386 /out:"$(OUTDIR)\ipdrive.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Ipdridoc.obj" \
	"$(INTDIR)\Ipdrive.obj" \
	"$(INTDIR)\Ipdrivw.obj" \
	"$(INTDIR)\Ipremote.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Ipdrive.res"

"$(OUTDIR)\ipdrive.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "IpDrive - Win32 Unicode Debug"

OUTDIR=.\UniDebug
INTDIR=.\UniDebug
# Begin Custom Macros
OutDir=.\.\UniDebug
# End Custom Macros

ALL : "$(OUTDIR)\ipdrive.exe" "$(OUTDIR)\ipdrive.bsc"


CLEAN :
	-@erase "$(INTDIR)\Ipdridoc.obj"
	-@erase "$(INTDIR)\Ipdridoc.sbr"
	-@erase "$(INTDIR)\Ipdrive.obj"
	-@erase "$(INTDIR)\ipdrive.pch"
	-@erase "$(INTDIR)\Ipdrive.res"
	-@erase "$(INTDIR)\Ipdrive.sbr"
	-@erase "$(INTDIR)\Ipdrivw.obj"
	-@erase "$(INTDIR)\Ipdrivw.sbr"
	-@erase "$(INTDIR)\Ipremote.obj"
	-@erase "$(INTDIR)\Ipremote.sbr"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Mainfrm.sbr"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\Stdafx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\ipdrive.bsc"
	-@erase "$(OUTDIR)\ipdrive.exe"
	-@erase "$(OUTDIR)\ipdrive.ilk"
	-@erase "$(OUTDIR)\ipdrive.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ipdrive.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Ipdrive.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ipdrive.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Ipdridoc.sbr" \
	"$(INTDIR)\Ipdrive.sbr" \
	"$(INTDIR)\Ipdrivw.sbr" \
	"$(INTDIR)\Ipremote.sbr" \
	"$(INTDIR)\Mainfrm.sbr" \
	"$(INTDIR)\Stdafx.sbr"

"$(OUTDIR)\ipdrive.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\ipdrive.pdb" /debug /machine:I386 /out:"$(OUTDIR)\ipdrive.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Ipdridoc.obj" \
	"$(INTDIR)\Ipdrive.obj" \
	"$(INTDIR)\Ipdrivw.obj" \
	"$(INTDIR)\Ipremote.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Stdafx.obj" \
	"$(INTDIR)\Ipdrive.res"

"$(OUTDIR)\ipdrive.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("ipdrive.dep")
!INCLUDE "ipdrive.dep"
!ELSE 
!MESSAGE Warning: cannot find "ipdrive.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "IpDrive - Win32 Release" || "$(CFG)" == "IpDrive - Win32 Debug" || "$(CFG)" == "IpDrive - Win32 Unicode Release" || "$(CFG)" == "IpDrive - Win32 Unicode Debug"
SOURCE=.\Ipdridoc.cpp

"$(INTDIR)\Ipdridoc.obj"	"$(INTDIR)\Ipdridoc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ipdrive.pch"


SOURCE=.\Ipdrive.cpp

"$(INTDIR)\Ipdrive.obj"	"$(INTDIR)\Ipdrive.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ipdrive.pch"


SOURCE=.\Ipdrive.rc

"$(INTDIR)\Ipdrive.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\Ipdrivw.cpp

"$(INTDIR)\Ipdrivw.obj"	"$(INTDIR)\Ipdrivw.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ipdrive.pch"


SOURCE=.\Ipremote.cpp

"$(INTDIR)\Ipremote.obj"	"$(INTDIR)\Ipremote.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ipdrive.pch"


SOURCE=.\Mainfrm.cpp

"$(INTDIR)\Mainfrm.obj"	"$(INTDIR)\Mainfrm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ipdrive.pch"


SOURCE=.\Stdafx.cpp

!IF  "$(CFG)" == "IpDrive - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ipdrive.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\Stdafx.sbr"	"$(INTDIR)\ipdrive.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "IpDrive - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ipdrive.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\Stdafx.sbr"	"$(INTDIR)\ipdrive.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "IpDrive - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ipdrive.pch" /Yc"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\Stdafx.sbr"	"$(INTDIR)\ipdrive.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "IpDrive - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ipdrive.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\Stdafx.sbr"	"$(INTDIR)\ipdrive.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

