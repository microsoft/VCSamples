# Microsoft Developer Studio Generated NMAKE File, Based on MFCBind.dsp
!IF "$(CFG)" == ""
CFG=MFCBind - Win32 Debug static
!MESSAGE No configuration specified. Defaulting to MFCBind - Win32 Debug static.
!ENDIF 

!IF "$(CFG)" != "MFCBind - Win32 Release" && "$(CFG)" != "MFCBind - Win32 Debug" && "$(CFG)" != "MFCBind - Win32 Unicode Debug" && "$(CFG)" != "MFCBind - Win32 Unicode Release" && "$(CFG)" != "MFCBind - Win32 Debug static" && "$(CFG)" != "MFCBind - Win32 Release static"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MFCBind.mak" CFG="MFCBind - Win32 Debug static"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MFCBind - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "MFCBind - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "MFCBind - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE "MFCBind - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "MFCBind - Win32 Debug static" (based on "Win32 (x86) Application")
!MESSAGE "MFCBind - Win32 Release static" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "MFCBind - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\MFCBind.exe"


CLEAN :
	-@erase "$(INTDIR)\BindDoc.obj"
	-@erase "$(INTDIR)\BindView.obj"
	-@erase "$(INTDIR)\CntrItem.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MFCBind.obj"
	-@erase "$(INTDIR)\MFCBind.pch"
	-@erase "$(INTDIR)\MFCBind.res"
	-@erase "$(INTDIR)\ObjView.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\MFCBind.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\MFCBind.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o /win32 "NUL" 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\MFCBind.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\MFCBind.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\MFCBind.pdb" /machine:I386 /out:"$(OUTDIR)\MFCBind.exe" 
LINK32_OBJS= \
	"$(INTDIR)\BindDoc.obj" \
	"$(INTDIR)\BindView.obj" \
	"$(INTDIR)\CntrItem.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MFCBind.obj" \
	"$(INTDIR)\ObjView.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\MFCBind.res"

"$(OUTDIR)\MFCBind.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MFCBind - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\MFCBind.exe"


CLEAN :
	-@erase "$(INTDIR)\BindDoc.obj"
	-@erase "$(INTDIR)\BindView.obj"
	-@erase "$(INTDIR)\CntrItem.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MFCBind.obj"
	-@erase "$(INTDIR)\MFCBind.pch"
	-@erase "$(INTDIR)\MFCBind.res"
	-@erase "$(INTDIR)\ObjView.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\MFCBind.exe"
	-@erase "$(OUTDIR)\MFCBind.ilk"
	-@erase "$(OUTDIR)\MFCBind.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\MFCBind.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o /win32 "NUL" 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\MFCBind.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\MFCBind.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\MFCBind.pdb" /debug /machine:I386 /out:"$(OUTDIR)\MFCBind.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\BindDoc.obj" \
	"$(INTDIR)\BindView.obj" \
	"$(INTDIR)\CntrItem.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MFCBind.obj" \
	"$(INTDIR)\ObjView.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\MFCBind.res"

"$(OUTDIR)\MFCBind.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MFCBind - Win32 Unicode Debug"

OUTDIR=.\UnicodeDebug
INTDIR=.\UnicodeDebug
# Begin Custom Macros
OutDir=.\UnicodeDebug
# End Custom Macros

ALL : "$(OUTDIR)\MFCBind.exe"


CLEAN :
	-@erase "$(INTDIR)\BindDoc.obj"
	-@erase "$(INTDIR)\BindView.obj"
	-@erase "$(INTDIR)\CntrItem.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MFCBind.obj"
	-@erase "$(INTDIR)\MFCBind.pch"
	-@erase "$(INTDIR)\MFCBind.res"
	-@erase "$(INTDIR)\ObjView.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\MFCBind.exe"
	-@erase "$(OUTDIR)\MFCBind.ilk"
	-@erase "$(OUTDIR)\MFCBind.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /Fp"$(INTDIR)\MFCBind.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o /win32 "NUL" 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\MFCBind.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\MFCBind.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\MFCBind.pdb" /debug /machine:I386 /out:"$(OUTDIR)\MFCBind.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\BindDoc.obj" \
	"$(INTDIR)\BindView.obj" \
	"$(INTDIR)\CntrItem.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MFCBind.obj" \
	"$(INTDIR)\ObjView.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\MFCBind.res"

"$(OUTDIR)\MFCBind.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MFCBind - Win32 Unicode Release"

OUTDIR=.\UnicodeRelease
INTDIR=.\UnicodeRelease
# Begin Custom Macros
OutDir=.\UnicodeRelease
# End Custom Macros

ALL : "$(OUTDIR)\MFCBind.exe"


CLEAN :
	-@erase "$(INTDIR)\BindDoc.obj"
	-@erase "$(INTDIR)\BindView.obj"
	-@erase "$(INTDIR)\CntrItem.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MFCBind.obj"
	-@erase "$(INTDIR)\MFCBind.pch"
	-@erase "$(INTDIR)\MFCBind.res"
	-@erase "$(INTDIR)\ObjView.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\MFCBind.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /Fp"$(INTDIR)\MFCBind.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o /win32 "NUL" 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\MFCBind.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\MFCBind.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\MFCBind.pdb" /machine:I386 /out:"$(OUTDIR)\MFCBind.exe" 
LINK32_OBJS= \
	"$(INTDIR)\BindDoc.obj" \
	"$(INTDIR)\BindView.obj" \
	"$(INTDIR)\CntrItem.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MFCBind.obj" \
	"$(INTDIR)\ObjView.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\MFCBind.res"

"$(OUTDIR)\MFCBind.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MFCBind - Win32 Debug static"

OUTDIR=.\DebugStatic
INTDIR=.\DebugStatic
# Begin Custom Macros
OutDir=.\DebugStatic
# End Custom Macros

ALL : "$(OUTDIR)\MFCBind.exe"


CLEAN :
	-@erase "$(INTDIR)\BindDoc.obj"
	-@erase "$(INTDIR)\BindView.obj"
	-@erase "$(INTDIR)\CntrItem.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MFCBind.obj"
	-@erase "$(INTDIR)\MFCBind.pch"
	-@erase "$(INTDIR)\MFCBind.res"
	-@erase "$(INTDIR)\ObjView.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\MFCBind.exe"
	-@erase "$(OUTDIR)\MFCBind.ilk"
	-@erase "$(OUTDIR)\MFCBind.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\MFCBind.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o /win32 "NUL" 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\MFCBind.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\MFCBind.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\MFCBind.pdb" /debug /machine:I386 /out:"$(OUTDIR)\MFCBind.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\BindDoc.obj" \
	"$(INTDIR)\BindView.obj" \
	"$(INTDIR)\CntrItem.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MFCBind.obj" \
	"$(INTDIR)\ObjView.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\MFCBind.res"

"$(OUTDIR)\MFCBind.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MFCBind - Win32 Release static"

OUTDIR=.\ReleaseStatic
INTDIR=.\ReleaseStatic
# Begin Custom Macros
OutDir=.\ReleaseStatic
# End Custom Macros

ALL : "$(OUTDIR)\MFCBind.exe"


CLEAN :
	-@erase "$(INTDIR)\BindDoc.obj"
	-@erase "$(INTDIR)\BindView.obj"
	-@erase "$(INTDIR)\CntrItem.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MFCBind.obj"
	-@erase "$(INTDIR)\MFCBind.pch"
	-@erase "$(INTDIR)\MFCBind.res"
	-@erase "$(INTDIR)\ObjView.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\MFCBind.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\MFCBind.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o /win32 "NUL" 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\MFCBind.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\MFCBind.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\MFCBind.pdb" /machine:I386 /out:"$(OUTDIR)\MFCBind.exe" 
LINK32_OBJS= \
	"$(INTDIR)\BindDoc.obj" \
	"$(INTDIR)\BindView.obj" \
	"$(INTDIR)\CntrItem.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MFCBind.obj" \
	"$(INTDIR)\ObjView.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\MFCBind.res"

"$(OUTDIR)\MFCBind.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("MFCBind.dep")
!INCLUDE "MFCBind.dep"
!ELSE 
!MESSAGE Warning: cannot find "MFCBind.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "MFCBind - Win32 Release" || "$(CFG)" == "MFCBind - Win32 Debug" || "$(CFG)" == "MFCBind - Win32 Unicode Debug" || "$(CFG)" == "MFCBind - Win32 Unicode Release" || "$(CFG)" == "MFCBind - Win32 Debug static" || "$(CFG)" == "MFCBind - Win32 Release static"
SOURCE=.\BindDoc.cpp

"$(INTDIR)\BindDoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MFCBind.pch"


SOURCE=.\BindView.cpp

"$(INTDIR)\BindView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MFCBind.pch"


SOURCE=.\CntrItem.cpp

"$(INTDIR)\CntrItem.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MFCBind.pch"


SOURCE=.\MainFrm.cpp

"$(INTDIR)\MainFrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MFCBind.pch"


SOURCE=.\MFCBind.cpp

"$(INTDIR)\MFCBind.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MFCBind.pch"


SOURCE=.\MFCBind.rc

"$(INTDIR)\MFCBind.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\ObjView.cpp

"$(INTDIR)\ObjView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MFCBind.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "MFCBind - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\MFCBind.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\MFCBind.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MFCBind - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\MFCBind.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\MFCBind.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MFCBind - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /Fp"$(INTDIR)\MFCBind.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\MFCBind.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MFCBind - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /D "_AFXDLL" /Fp"$(INTDIR)\MFCBind.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\MFCBind.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MFCBind - Win32 Debug static"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\MFCBind.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\MFCBind.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MFCBind - Win32 Release static"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\MFCBind.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\MFCBind.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

