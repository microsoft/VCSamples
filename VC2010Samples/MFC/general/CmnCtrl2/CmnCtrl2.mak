# Microsoft Developer Studio Generated NMAKE File, Based on CmnCtrl2.dsp
!IF "$(CFG)" == ""
CFG=CmnCtrl2 - Win32 Debug Unicode
!MESSAGE No configuration specified. Defaulting to CmnCtrl2 - Win32 Debug Unicode.
!ENDIF 

!IF "$(CFG)" != "CmnCtrl2 - Win32 Release" && "$(CFG)" != "CmnCtrl2 - Win32 Debug" && "$(CFG)" != "CmnCtrl2 - Win32 Debug static" && "$(CFG)" != "CmnCtrl2 - Win32 Release static" && "$(CFG)" != "CmnCtrl2 - Win32 Debug Unicode" && "$(CFG)" != "CmnCtrl2 - Win32 Release Unicode"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CmnCtrl2.mak" CFG="CmnCtrl2 - Win32 Debug Unicode"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CmnCtrl2 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "CmnCtrl2 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "CmnCtrl2 - Win32 Debug static" (based on "Win32 (x86) Application")
!MESSAGE "CmnCtrl2 - Win32 Release static" (based on "Win32 (x86) Application")
!MESSAGE "CmnCtrl2 - Win32 Debug Unicode" (based on "Win32 (x86) Application")
!MESSAGE "CmnCtrl2 - Win32 Release Unicode" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "CmnCtrl2 - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\CmnCtrl2.exe"


CLEAN :
	-@erase "$(INTDIR)\CmnCtrl2.obj"
	-@erase "$(INTDIR)\CmnCtrl2.pch"
	-@erase "$(INTDIR)\CmnCtrl2.res"
	-@erase "$(INTDIR)\notifwdw.obj"
	-@erase "$(INTDIR)\progctrl.obj"
	-@erase "$(INTDIR)\propsht.obj"
	-@erase "$(INTDIR)\slidctrl.obj"
	-@erase "$(INTDIR)\spinctrl.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\CmnCtrl2.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\CmnCtrl2.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o /win32 NUL 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CmnCtrl2.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CmnCtrl2.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\CmnCtrl2.pdb" /machine:I386 /out:"$(OUTDIR)\CmnCtrl2.exe" 
LINK32_OBJS= \
	"$(INTDIR)\CmnCtrl2.obj" \
	"$(INTDIR)\notifwdw.obj" \
	"$(INTDIR)\progctrl.obj" \
	"$(INTDIR)\propsht.obj" \
	"$(INTDIR)\slidctrl.obj" \
	"$(INTDIR)\spinctrl.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\CmnCtrl2.res"

"$(OUTDIR)\CmnCtrl2.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CmnCtrl2 - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\CmnCtrl2.exe"


CLEAN :
	-@erase "$(INTDIR)\CmnCtrl2.obj"
	-@erase "$(INTDIR)\CmnCtrl2.pch"
	-@erase "$(INTDIR)\CmnCtrl2.res"
	-@erase "$(INTDIR)\notifwdw.obj"
	-@erase "$(INTDIR)\progctrl.obj"
	-@erase "$(INTDIR)\propsht.obj"
	-@erase "$(INTDIR)\slidctrl.obj"
	-@erase "$(INTDIR)\spinctrl.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\CmnCtrl2.exe"
	-@erase "$(OUTDIR)\CmnCtrl2.ilk"
	-@erase "$(OUTDIR)\CmnCtrl2.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\CmnCtrl2.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o /win32 NUL 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CmnCtrl2.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CmnCtrl2.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\CmnCtrl2.pdb" /debug /machine:I386 /out:"$(OUTDIR)\CmnCtrl2.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\CmnCtrl2.obj" \
	"$(INTDIR)\notifwdw.obj" \
	"$(INTDIR)\progctrl.obj" \
	"$(INTDIR)\propsht.obj" \
	"$(INTDIR)\slidctrl.obj" \
	"$(INTDIR)\spinctrl.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\CmnCtrl2.res"

"$(OUTDIR)\CmnCtrl2.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CmnCtrl2 - Win32 Debug static"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\CmnCtrl2.exe"


CLEAN :
	-@erase "$(INTDIR)\CmnCtrl2.obj"
	-@erase "$(INTDIR)\CmnCtrl2.pch"
	-@erase "$(INTDIR)\CmnCtrl2.res"
	-@erase "$(INTDIR)\notifwdw.obj"
	-@erase "$(INTDIR)\progctrl.obj"
	-@erase "$(INTDIR)\propsht.obj"
	-@erase "$(INTDIR)\slidctrl.obj"
	-@erase "$(INTDIR)\spinctrl.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\CmnCtrl2.exe"
	-@erase "$(OUTDIR)\CmnCtrl2.ilk"
	-@erase "$(OUTDIR)\CmnCtrl2.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\CmnCtrl2.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o /win32 NUL 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CmnCtrl2.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CmnCtrl2.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\CmnCtrl2.pdb" /debug /machine:I386 /out:"$(OUTDIR)\CmnCtrl2.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\CmnCtrl2.obj" \
	"$(INTDIR)\notifwdw.obj" \
	"$(INTDIR)\progctrl.obj" \
	"$(INTDIR)\propsht.obj" \
	"$(INTDIR)\slidctrl.obj" \
	"$(INTDIR)\spinctrl.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\CmnCtrl2.res"

"$(OUTDIR)\CmnCtrl2.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CmnCtrl2 - Win32 Release static"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\CmnCtrl2.exe"


CLEAN :
	-@erase "$(INTDIR)\CmnCtrl2.obj"
	-@erase "$(INTDIR)\CmnCtrl2.pch"
	-@erase "$(INTDIR)\CmnCtrl2.res"
	-@erase "$(INTDIR)\notifwdw.obj"
	-@erase "$(INTDIR)\progctrl.obj"
	-@erase "$(INTDIR)\propsht.obj"
	-@erase "$(INTDIR)\slidctrl.obj"
	-@erase "$(INTDIR)\spinctrl.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\CmnCtrl2.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\CmnCtrl2.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o /win32 NUL 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CmnCtrl2.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CmnCtrl2.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\CmnCtrl2.pdb" /machine:I386 /out:"$(OUTDIR)\CmnCtrl2.exe" 
LINK32_OBJS= \
	"$(INTDIR)\CmnCtrl2.obj" \
	"$(INTDIR)\notifwdw.obj" \
	"$(INTDIR)\progctrl.obj" \
	"$(INTDIR)\propsht.obj" \
	"$(INTDIR)\slidctrl.obj" \
	"$(INTDIR)\spinctrl.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\CmnCtrl2.res"

"$(OUTDIR)\CmnCtrl2.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CmnCtrl2 - Win32 Debug Unicode"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\CmnCtrl2.exe"


CLEAN :
	-@erase "$(INTDIR)\CmnCtrl2.obj"
	-@erase "$(INTDIR)\CmnCtrl2.pch"
	-@erase "$(INTDIR)\CmnCtrl2.res"
	-@erase "$(INTDIR)\notifwdw.obj"
	-@erase "$(INTDIR)\progctrl.obj"
	-@erase "$(INTDIR)\propsht.obj"
	-@erase "$(INTDIR)\slidctrl.obj"
	-@erase "$(INTDIR)\spinctrl.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\CmnCtrl2.exe"
	-@erase "$(OUTDIR)\CmnCtrl2.ilk"
	-@erase "$(OUTDIR)\CmnCtrl2.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /Fp"$(INTDIR)\CmnCtrl2.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o /win32 NUL 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CmnCtrl2.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CmnCtrl2.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\CmnCtrl2.pdb" /debug /machine:I386 /out:"$(OUTDIR)\CmnCtrl2.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\CmnCtrl2.obj" \
	"$(INTDIR)\notifwdw.obj" \
	"$(INTDIR)\progctrl.obj" \
	"$(INTDIR)\propsht.obj" \
	"$(INTDIR)\slidctrl.obj" \
	"$(INTDIR)\spinctrl.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\CmnCtrl2.res"

"$(OUTDIR)\CmnCtrl2.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CmnCtrl2 - Win32 Release Unicode"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\CmnCtrl2.exe"


CLEAN :
	-@erase "$(INTDIR)\CmnCtrl2.obj"
	-@erase "$(INTDIR)\CmnCtrl2.pch"
	-@erase "$(INTDIR)\CmnCtrl2.res"
	-@erase "$(INTDIR)\notifwdw.obj"
	-@erase "$(INTDIR)\progctrl.obj"
	-@erase "$(INTDIR)\propsht.obj"
	-@erase "$(INTDIR)\slidctrl.obj"
	-@erase "$(INTDIR)\spinctrl.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\CmnCtrl2.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /Fp"$(INTDIR)\CmnCtrl2.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o /win32 NUL 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CmnCtrl2.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CmnCtrl2.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\CmnCtrl2.pdb" /machine:I386 /out:"$(OUTDIR)\CmnCtrl2.exe" 
LINK32_OBJS= \
	"$(INTDIR)\CmnCtrl2.obj" \
	"$(INTDIR)\notifwdw.obj" \
	"$(INTDIR)\progctrl.obj" \
	"$(INTDIR)\propsht.obj" \
	"$(INTDIR)\slidctrl.obj" \
	"$(INTDIR)\spinctrl.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\CmnCtrl2.res"

"$(OUTDIR)\CmnCtrl2.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("CmnCtrl2.dep")
!INCLUDE "CmnCtrl2.dep"
!ELSE 
!MESSAGE Warning: cannot find "CmnCtrl2.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "CmnCtrl2 - Win32 Release" || "$(CFG)" == "CmnCtrl2 - Win32 Debug" || "$(CFG)" == "CmnCtrl2 - Win32 Debug static" || "$(CFG)" == "CmnCtrl2 - Win32 Release static" || "$(CFG)" == "CmnCtrl2 - Win32 Debug Unicode" || "$(CFG)" == "CmnCtrl2 - Win32 Release Unicode"
SOURCE=.\CmnCtrl2.cpp

"$(INTDIR)\CmnCtrl2.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CmnCtrl2.pch"


SOURCE=.\CmnCtrl2.rc

"$(INTDIR)\CmnCtrl2.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\notifwdw.cpp

"$(INTDIR)\notifwdw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CmnCtrl2.pch"


SOURCE=.\progctrl.cpp

"$(INTDIR)\progctrl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CmnCtrl2.pch"


SOURCE=.\propsht.cpp

"$(INTDIR)\propsht.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CmnCtrl2.pch"


SOURCE=.\slidctrl.cpp

"$(INTDIR)\slidctrl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CmnCtrl2.pch"


SOURCE=.\spinctrl.cpp

"$(INTDIR)\spinctrl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CmnCtrl2.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "CmnCtrl2 - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\CmnCtrl2.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CmnCtrl2.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CmnCtrl2 - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\CmnCtrl2.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CmnCtrl2.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CmnCtrl2 - Win32 Debug static"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\CmnCtrl2.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CmnCtrl2.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CmnCtrl2 - Win32 Release static"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\CmnCtrl2.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CmnCtrl2.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CmnCtrl2 - Win32 Debug Unicode"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /Fp"$(INTDIR)\CmnCtrl2.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CmnCtrl2.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CmnCtrl2 - Win32 Release Unicode"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /Fp"$(INTDIR)\CmnCtrl2.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CmnCtrl2.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

