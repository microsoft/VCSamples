# Microsoft Developer Studio Generated NMAKE File, Based on CmnCtrl1.dsp
!IF "$(CFG)" == ""
CFG=CmnCtrl1 - Win32 Debug Unicode
!MESSAGE No configuration specified. Defaulting to CmnCtrl1 - Win32 Debug Unicode.
!ENDIF 

!IF "$(CFG)" != "CmnCtrl1 - Win32 Release" && "$(CFG)" != "CmnCtrl1 - Win32 Debug" && "$(CFG)" != "CmnCtrl1 - Win32 Debug static" && "$(CFG)" != "CmnCtrl1 - Win32 Release static" && "$(CFG)" != "CmnCtrl1 - Win32 Release Unicode" && "$(CFG)" != "CmnCtrl1 - Win32 Debug Unicode"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CmnCtrl1.mak" CFG="CmnCtrl1 - Win32 Debug Unicode"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CmnCtrl1 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "CmnCtrl1 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "CmnCtrl1 - Win32 Debug static" (based on "Win32 (x86) Application")
!MESSAGE "CmnCtrl1 - Win32 Release static" (based on "Win32 (x86) Application")
!MESSAGE "CmnCtrl1 - Win32 Release Unicode" (based on "Win32 (x86) Application")
!MESSAGE "CmnCtrl1 - Win32 Debug Unicode" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "CmnCtrl1 - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\CmnCtrl1.exe"


CLEAN :
	-@erase "$(INTDIR)\animctrl.obj"
	-@erase "$(INTDIR)\CmnCtrl1.obj"
	-@erase "$(INTDIR)\CmnCtrl1.pch"
	-@erase "$(INTDIR)\CmnCtrl1.res"
	-@erase "$(INTDIR)\DateTime.obj"
	-@erase "$(INTDIR)\MonthCal.obj"
	-@erase "$(INTDIR)\mtreectl.obj"
	-@erase "$(INTDIR)\notifwdw.obj"
	-@erase "$(INTDIR)\propsht.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\toolbar1.obj"
	-@erase "$(INTDIR)\toolbar2.obj"
	-@erase "$(INTDIR)\toolpage.obj"
	-@erase "$(INTDIR)\treecpg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\CmnCtrl1.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\CmnCtrl1.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CmnCtrl1.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CmnCtrl1.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\CmnCtrl1.pdb" /machine:I386 /out:"$(OUTDIR)\CmnCtrl1.exe" 
LINK32_OBJS= \
	"$(INTDIR)\animctrl.obj" \
	"$(INTDIR)\CmnCtrl1.obj" \
	"$(INTDIR)\DateTime.obj" \
	"$(INTDIR)\MonthCal.obj" \
	"$(INTDIR)\mtreectl.obj" \
	"$(INTDIR)\notifwdw.obj" \
	"$(INTDIR)\propsht.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\toolbar1.obj" \
	"$(INTDIR)\toolbar2.obj" \
	"$(INTDIR)\toolpage.obj" \
	"$(INTDIR)\treecpg.obj" \
	"$(INTDIR)\CmnCtrl1.res"

"$(OUTDIR)\CmnCtrl1.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CmnCtrl1 - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\CmnCtrl1.exe"


CLEAN :
	-@erase "$(INTDIR)\animctrl.obj"
	-@erase "$(INTDIR)\CmnCtrl1.obj"
	-@erase "$(INTDIR)\CmnCtrl1.pch"
	-@erase "$(INTDIR)\CmnCtrl1.res"
	-@erase "$(INTDIR)\DateTime.obj"
	-@erase "$(INTDIR)\MonthCal.obj"
	-@erase "$(INTDIR)\mtreectl.obj"
	-@erase "$(INTDIR)\notifwdw.obj"
	-@erase "$(INTDIR)\propsht.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\toolbar1.obj"
	-@erase "$(INTDIR)\toolbar2.obj"
	-@erase "$(INTDIR)\toolpage.obj"
	-@erase "$(INTDIR)\treecpg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\CmnCtrl1.exe"
	-@erase "$(OUTDIR)\CmnCtrl1.ilk"
	-@erase "$(OUTDIR)\CmnCtrl1.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\CmnCtrl1.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CmnCtrl1.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CmnCtrl1.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\CmnCtrl1.pdb" /debug /machine:I386 /out:"$(OUTDIR)\CmnCtrl1.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\animctrl.obj" \
	"$(INTDIR)\CmnCtrl1.obj" \
	"$(INTDIR)\DateTime.obj" \
	"$(INTDIR)\MonthCal.obj" \
	"$(INTDIR)\mtreectl.obj" \
	"$(INTDIR)\notifwdw.obj" \
	"$(INTDIR)\propsht.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\toolbar1.obj" \
	"$(INTDIR)\toolbar2.obj" \
	"$(INTDIR)\toolpage.obj" \
	"$(INTDIR)\treecpg.obj" \
	"$(INTDIR)\CmnCtrl1.res"

"$(OUTDIR)\CmnCtrl1.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CmnCtrl1 - Win32 Debug static"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\CmnCtrl1.exe"


CLEAN :
	-@erase "$(INTDIR)\animctrl.obj"
	-@erase "$(INTDIR)\CmnCtrl1.obj"
	-@erase "$(INTDIR)\CmnCtrl1.pch"
	-@erase "$(INTDIR)\CmnCtrl1.res"
	-@erase "$(INTDIR)\DateTime.obj"
	-@erase "$(INTDIR)\MonthCal.obj"
	-@erase "$(INTDIR)\mtreectl.obj"
	-@erase "$(INTDIR)\notifwdw.obj"
	-@erase "$(INTDIR)\propsht.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\toolbar1.obj"
	-@erase "$(INTDIR)\toolbar2.obj"
	-@erase "$(INTDIR)\toolpage.obj"
	-@erase "$(INTDIR)\treecpg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\CmnCtrl1.exe"
	-@erase "$(OUTDIR)\CmnCtrl1.ilk"
	-@erase "$(OUTDIR)\CmnCtrl1.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\CmnCtrl1.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CmnCtrl1.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CmnCtrl1.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\CmnCtrl1.pdb" /debug /machine:I386 /out:"$(OUTDIR)\CmnCtrl1.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\animctrl.obj" \
	"$(INTDIR)\CmnCtrl1.obj" \
	"$(INTDIR)\DateTime.obj" \
	"$(INTDIR)\MonthCal.obj" \
	"$(INTDIR)\mtreectl.obj" \
	"$(INTDIR)\notifwdw.obj" \
	"$(INTDIR)\propsht.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\toolbar1.obj" \
	"$(INTDIR)\toolbar2.obj" \
	"$(INTDIR)\toolpage.obj" \
	"$(INTDIR)\treecpg.obj" \
	"$(INTDIR)\CmnCtrl1.res"

"$(OUTDIR)\CmnCtrl1.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CmnCtrl1 - Win32 Release static"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\CmnCtrl1.exe"


CLEAN :
	-@erase "$(INTDIR)\animctrl.obj"
	-@erase "$(INTDIR)\CmnCtrl1.obj"
	-@erase "$(INTDIR)\CmnCtrl1.pch"
	-@erase "$(INTDIR)\CmnCtrl1.res"
	-@erase "$(INTDIR)\DateTime.obj"
	-@erase "$(INTDIR)\MonthCal.obj"
	-@erase "$(INTDIR)\mtreectl.obj"
	-@erase "$(INTDIR)\notifwdw.obj"
	-@erase "$(INTDIR)\propsht.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\toolbar1.obj"
	-@erase "$(INTDIR)\toolbar2.obj"
	-@erase "$(INTDIR)\toolpage.obj"
	-@erase "$(INTDIR)\treecpg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\CmnCtrl1.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\CmnCtrl1.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CmnCtrl1.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CmnCtrl1.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\CmnCtrl1.pdb" /machine:I386 /out:"$(OUTDIR)\CmnCtrl1.exe" 
LINK32_OBJS= \
	"$(INTDIR)\animctrl.obj" \
	"$(INTDIR)\CmnCtrl1.obj" \
	"$(INTDIR)\DateTime.obj" \
	"$(INTDIR)\MonthCal.obj" \
	"$(INTDIR)\mtreectl.obj" \
	"$(INTDIR)\notifwdw.obj" \
	"$(INTDIR)\propsht.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\toolbar1.obj" \
	"$(INTDIR)\toolbar2.obj" \
	"$(INTDIR)\toolpage.obj" \
	"$(INTDIR)\treecpg.obj" \
	"$(INTDIR)\CmnCtrl1.res"

"$(OUTDIR)\CmnCtrl1.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CmnCtrl1 - Win32 Release Unicode"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\CmnCtrl1.exe"


CLEAN :
	-@erase "$(INTDIR)\animctrl.obj"
	-@erase "$(INTDIR)\CmnCtrl1.obj"
	-@erase "$(INTDIR)\CmnCtrl1.pch"
	-@erase "$(INTDIR)\CmnCtrl1.res"
	-@erase "$(INTDIR)\DateTime.obj"
	-@erase "$(INTDIR)\MonthCal.obj"
	-@erase "$(INTDIR)\mtreectl.obj"
	-@erase "$(INTDIR)\notifwdw.obj"
	-@erase "$(INTDIR)\propsht.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\toolbar1.obj"
	-@erase "$(INTDIR)\toolbar2.obj"
	-@erase "$(INTDIR)\toolpage.obj"
	-@erase "$(INTDIR)\treecpg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\CmnCtrl1.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /Fp"$(INTDIR)\CmnCtrl1.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CmnCtrl1.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CmnCtrl1.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\CmnCtrl1.pdb" /machine:I386 /out:"$(OUTDIR)\CmnCtrl1.exe" 
LINK32_OBJS= \
	"$(INTDIR)\animctrl.obj" \
	"$(INTDIR)\CmnCtrl1.obj" \
	"$(INTDIR)\DateTime.obj" \
	"$(INTDIR)\MonthCal.obj" \
	"$(INTDIR)\mtreectl.obj" \
	"$(INTDIR)\notifwdw.obj" \
	"$(INTDIR)\propsht.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\toolbar1.obj" \
	"$(INTDIR)\toolbar2.obj" \
	"$(INTDIR)\toolpage.obj" \
	"$(INTDIR)\treecpg.obj" \
	"$(INTDIR)\CmnCtrl1.res"

"$(OUTDIR)\CmnCtrl1.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CmnCtrl1 - Win32 Debug Unicode"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\CmnCtrl1.exe"


CLEAN :
	-@erase "$(INTDIR)\animctrl.obj"
	-@erase "$(INTDIR)\CmnCtrl1.obj"
	-@erase "$(INTDIR)\CmnCtrl1.pch"
	-@erase "$(INTDIR)\CmnCtrl1.res"
	-@erase "$(INTDIR)\DateTime.obj"
	-@erase "$(INTDIR)\MonthCal.obj"
	-@erase "$(INTDIR)\mtreectl.obj"
	-@erase "$(INTDIR)\notifwdw.obj"
	-@erase "$(INTDIR)\propsht.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\toolbar1.obj"
	-@erase "$(INTDIR)\toolbar2.obj"
	-@erase "$(INTDIR)\toolpage.obj"
	-@erase "$(INTDIR)\treecpg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\CmnCtrl1.exe"
	-@erase "$(OUTDIR)\CmnCtrl1.ilk"
	-@erase "$(OUTDIR)\CmnCtrl1.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /Fp"$(INTDIR)\CmnCtrl1.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CmnCtrl1.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CmnCtrl1.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\CmnCtrl1.pdb" /debug /machine:I386 /out:"$(OUTDIR)\CmnCtrl1.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\animctrl.obj" \
	"$(INTDIR)\CmnCtrl1.obj" \
	"$(INTDIR)\DateTime.obj" \
	"$(INTDIR)\MonthCal.obj" \
	"$(INTDIR)\mtreectl.obj" \
	"$(INTDIR)\notifwdw.obj" \
	"$(INTDIR)\propsht.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\toolbar1.obj" \
	"$(INTDIR)\toolbar2.obj" \
	"$(INTDIR)\toolpage.obj" \
	"$(INTDIR)\treecpg.obj" \
	"$(INTDIR)\CmnCtrl1.res"

"$(OUTDIR)\CmnCtrl1.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("CmnCtrl1.dep")
!INCLUDE "CmnCtrl1.dep"
!ELSE 
!MESSAGE Warning: cannot find "CmnCtrl1.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "CmnCtrl1 - Win32 Release" || "$(CFG)" == "CmnCtrl1 - Win32 Debug" || "$(CFG)" == "CmnCtrl1 - Win32 Debug static" || "$(CFG)" == "CmnCtrl1 - Win32 Release static" || "$(CFG)" == "CmnCtrl1 - Win32 Release Unicode" || "$(CFG)" == "CmnCtrl1 - Win32 Debug Unicode"
SOURCE=.\animctrl.cpp

"$(INTDIR)\animctrl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CmnCtrl1.pch"


SOURCE=.\CmnCtrl1.cpp

"$(INTDIR)\CmnCtrl1.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CmnCtrl1.pch"


SOURCE=.\CmnCtrl1.rc

"$(INTDIR)\CmnCtrl1.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\DateTime.cpp

"$(INTDIR)\DateTime.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CmnCtrl1.pch"


SOURCE=.\MonthCal.cpp

"$(INTDIR)\MonthCal.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CmnCtrl1.pch"


SOURCE=.\mtreectl.cpp

"$(INTDIR)\mtreectl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CmnCtrl1.pch"


SOURCE=.\notifwdw.cpp

"$(INTDIR)\notifwdw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CmnCtrl1.pch"


SOURCE=.\propsht.cpp

"$(INTDIR)\propsht.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CmnCtrl1.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "CmnCtrl1 - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\CmnCtrl1.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CmnCtrl1.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CmnCtrl1 - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\CmnCtrl1.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CmnCtrl1.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CmnCtrl1 - Win32 Debug static"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\CmnCtrl1.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CmnCtrl1.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CmnCtrl1 - Win32 Release static"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\CmnCtrl1.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CmnCtrl1.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CmnCtrl1 - Win32 Release Unicode"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /Fp"$(INTDIR)\CmnCtrl1.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CmnCtrl1.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CmnCtrl1 - Win32 Debug Unicode"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /Fp"$(INTDIR)\CmnCtrl1.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CmnCtrl1.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\toolbar1.cpp

"$(INTDIR)\toolbar1.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CmnCtrl1.pch"


SOURCE=.\toolbar2.cpp

"$(INTDIR)\toolbar2.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CmnCtrl1.pch"


SOURCE=.\toolpage.cpp

"$(INTDIR)\toolpage.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CmnCtrl1.pch"


SOURCE=.\treecpg.cpp

"$(INTDIR)\treecpg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CmnCtrl1.pch"



!ENDIF 

