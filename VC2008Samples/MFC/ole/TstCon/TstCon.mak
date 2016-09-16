# Microsoft Developer Studio Generated NMAKE File, Based on TstCon.dsp
!IF "$(CFG)" == ""
CFG=TstCon - Win32 Debug
!MESSAGE No configuration specified. Defaulting to TstCon - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "TstCon - Win32 Release" && "$(CFG)" != "TstCon - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TstCon.mak" CFG="TstCon - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TstCon - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "TstCon - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "TstCon - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\TstCon32.exe" ".\TstCon_i.c"

!ELSE 

ALL : "TCProps - Win32 Release" "$(OUTDIR)\TstCon32.exe" ".\TstCon_i.c"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"TCProps - Win32 ReleaseCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\AProp.obj"
	-@erase "$(INTDIR)\APropDg.obj"
	-@erase "$(INTDIR)\BindHost.obj"
	-@erase "$(INTDIR)\ComCatDg.obj"
	-@erase "$(INTDIR)\ConInfDg.obj"
	-@erase "$(INTDIR)\EvLogPg.obj"
	-@erase "$(INTDIR)\ExcepInf.obj"
	-@erase "$(INTDIR)\ExtCtl.obj"
	-@erase "$(INTDIR)\FeatPg.obj"
	-@erase "$(INTDIR)\IFacesPg.obj"
	-@erase "$(INTDIR)\InsCtlDg.obj"
	-@erase "$(INTDIR)\Log.obj"
	-@erase "$(INTDIR)\LogDg.obj"
	-@erase "$(INTDIR)\MacroCB.obj"
	-@erase "$(INTDIR)\MacroDB.obj"
	-@erase "$(INTDIR)\MacroDg.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MethInfo.obj"
	-@erase "$(INTDIR)\MethodDg.obj"
	-@erase "$(INTDIR)\MFileWnd.obj"
	-@erase "$(INTDIR)\NewAPDg.obj"
	-@erase "$(INTDIR)\OutWndVw.obj"
	-@erase "$(INTDIR)\PBagDg.obj"
	-@erase "$(INTDIR)\PChngPg.obj"
	-@erase "$(INTDIR)\PEdReqPg.obj"
	-@erase "$(INTDIR)\PropBag.obj"
	-@erase "$(INTDIR)\RegCtlDg.obj"
	-@erase "$(INTDIR)\Script.obj"
	-@erase "$(INTDIR)\ScrMngr.obj"
	-@erase "$(INTDIR)\ServPg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TabOrdDg.obj"
	-@erase "$(INTDIR)\TCDoc.obj"
	-@erase "$(INTDIR)\TCItem.obj"
	-@erase "$(INTDIR)\TCSplit.obj"
	-@erase "$(INTDIR)\TCTrace.obj"
	-@erase "$(INTDIR)\TCView.obj"
	-@erase "$(INTDIR)\TstCon.obj"
	-@erase "$(INTDIR)\TstCon.pch"
	-@erase "$(INTDIR)\TstCon.res"
	-@erase "$(INTDIR)\TstCon.tlb"
	-@erase "$(INTDIR)\TypeAttr.obj"
	-@erase "$(INTDIR)\VarUtils.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\TstCon32.exe"
	-@erase "$(OUTDIR)\TstCon32.pdb"
	-@erase ".\TstCon_i.c"
	-@erase ".\TstConIF.h"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W4 /GX /O2 /I "TCProps\Release" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\TstCon.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=/nologo /D "NDEBUG" /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\TstCon.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\TstCon.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=shlwapi.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\TstCon32.pdb" /debug /machine:I386 /out:"$(OUTDIR)\TstCon32.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AProp.obj" \
	"$(INTDIR)\APropDg.obj" \
	"$(INTDIR)\BindHost.obj" \
	"$(INTDIR)\ComCatDg.obj" \
	"$(INTDIR)\ConInfDg.obj" \
	"$(INTDIR)\EvLogPg.obj" \
	"$(INTDIR)\ExcepInf.obj" \
	"$(INTDIR)\ExtCtl.obj" \
	"$(INTDIR)\FeatPg.obj" \
	"$(INTDIR)\IFacesPg.obj" \
	"$(INTDIR)\InsCtlDg.obj" \
	"$(INTDIR)\Log.obj" \
	"$(INTDIR)\LogDg.obj" \
	"$(INTDIR)\MacroCB.obj" \
	"$(INTDIR)\MacroDB.obj" \
	"$(INTDIR)\MacroDg.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MethInfo.obj" \
	"$(INTDIR)\MethodDg.obj" \
	"$(INTDIR)\MFileWnd.obj" \
	"$(INTDIR)\NewAPDg.obj" \
	"$(INTDIR)\OutWndVw.obj" \
	"$(INTDIR)\PBagDg.obj" \
	"$(INTDIR)\PChngPg.obj" \
	"$(INTDIR)\PEdReqPg.obj" \
	"$(INTDIR)\PropBag.obj" \
	"$(INTDIR)\RegCtlDg.obj" \
	"$(INTDIR)\Script.obj" \
	"$(INTDIR)\ScrMngr.obj" \
	"$(INTDIR)\ServPg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TabOrdDg.obj" \
	"$(INTDIR)\TCDoc.obj" \
	"$(INTDIR)\TCItem.obj" \
	"$(INTDIR)\TCSplit.obj" \
	"$(INTDIR)\TCTrace.obj" \
	"$(INTDIR)\TCView.obj" \
	"$(INTDIR)\TstCon.obj" \
	"$(INTDIR)\TypeAttr.obj" \
	"$(INTDIR)\VarUtils.obj" \
	"$(INTDIR)\TstCon.res" \
	".\TCProps\Release\TCProps.lib"

"$(OUTDIR)\TstCon32.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

SOURCE="$(InputPath)"
PostBuild_Desc=Building help file...
DS_POSTBUILD_DEP=$(INTDIR)\postbld.dep

ALL : $(DS_POSTBUILD_DEP)

# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

$(DS_POSTBUILD_DEP) : "TCProps - Win32 Release" "$(OUTDIR)\TstCon32.exe" ".\TstCon_i.c"
   makehelp.bat
	echo Helper for Post-build step > "$(DS_POSTBUILD_DEP)"

!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\TstCon32.exe" ".\TstCon_i.c" "$(OUTDIR)\TstCon.bsc"

!ELSE 

ALL : "TCProps - Win32 Debug" "$(OUTDIR)\TstCon32.exe" ".\TstCon_i.c" "$(OUTDIR)\TstCon.bsc"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"TCProps - Win32 DebugCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\AProp.obj"
	-@erase "$(INTDIR)\AProp.sbr"
	-@erase "$(INTDIR)\APropDg.obj"
	-@erase "$(INTDIR)\APropDg.sbr"
	-@erase "$(INTDIR)\BindHost.obj"
	-@erase "$(INTDIR)\BindHost.sbr"
	-@erase "$(INTDIR)\ComCatDg.obj"
	-@erase "$(INTDIR)\ComCatDg.sbr"
	-@erase "$(INTDIR)\ConInfDg.obj"
	-@erase "$(INTDIR)\ConInfDg.sbr"
	-@erase "$(INTDIR)\EvLogPg.obj"
	-@erase "$(INTDIR)\EvLogPg.sbr"
	-@erase "$(INTDIR)\ExcepInf.obj"
	-@erase "$(INTDIR)\ExcepInf.sbr"
	-@erase "$(INTDIR)\ExtCtl.obj"
	-@erase "$(INTDIR)\ExtCtl.sbr"
	-@erase "$(INTDIR)\FeatPg.obj"
	-@erase "$(INTDIR)\FeatPg.sbr"
	-@erase "$(INTDIR)\IFacesPg.obj"
	-@erase "$(INTDIR)\IFacesPg.sbr"
	-@erase "$(INTDIR)\InsCtlDg.obj"
	-@erase "$(INTDIR)\InsCtlDg.sbr"
	-@erase "$(INTDIR)\Log.obj"
	-@erase "$(INTDIR)\Log.sbr"
	-@erase "$(INTDIR)\LogDg.obj"
	-@erase "$(INTDIR)\LogDg.sbr"
	-@erase "$(INTDIR)\MacroCB.obj"
	-@erase "$(INTDIR)\MacroCB.sbr"
	-@erase "$(INTDIR)\MacroDB.obj"
	-@erase "$(INTDIR)\MacroDB.sbr"
	-@erase "$(INTDIR)\MacroDg.obj"
	-@erase "$(INTDIR)\MacroDg.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\MethInfo.obj"
	-@erase "$(INTDIR)\MethInfo.sbr"
	-@erase "$(INTDIR)\MethodDg.obj"
	-@erase "$(INTDIR)\MethodDg.sbr"
	-@erase "$(INTDIR)\MFileWnd.obj"
	-@erase "$(INTDIR)\MFileWnd.sbr"
	-@erase "$(INTDIR)\NewAPDg.obj"
	-@erase "$(INTDIR)\NewAPDg.sbr"
	-@erase "$(INTDIR)\OutWndVw.obj"
	-@erase "$(INTDIR)\OutWndVw.sbr"
	-@erase "$(INTDIR)\PBagDg.obj"
	-@erase "$(INTDIR)\PBagDg.sbr"
	-@erase "$(INTDIR)\PChngPg.obj"
	-@erase "$(INTDIR)\PChngPg.sbr"
	-@erase "$(INTDIR)\PEdReqPg.obj"
	-@erase "$(INTDIR)\PEdReqPg.sbr"
	-@erase "$(INTDIR)\PropBag.obj"
	-@erase "$(INTDIR)\PropBag.sbr"
	-@erase "$(INTDIR)\RegCtlDg.obj"
	-@erase "$(INTDIR)\RegCtlDg.sbr"
	-@erase "$(INTDIR)\Script.obj"
	-@erase "$(INTDIR)\Script.sbr"
	-@erase "$(INTDIR)\ScrMngr.obj"
	-@erase "$(INTDIR)\ScrMngr.sbr"
	-@erase "$(INTDIR)\ServPg.obj"
	-@erase "$(INTDIR)\ServPg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\TabOrdDg.obj"
	-@erase "$(INTDIR)\TabOrdDg.sbr"
	-@erase "$(INTDIR)\TCDoc.obj"
	-@erase "$(INTDIR)\TCDoc.sbr"
	-@erase "$(INTDIR)\TCItem.obj"
	-@erase "$(INTDIR)\TCItem.sbr"
	-@erase "$(INTDIR)\TCSplit.obj"
	-@erase "$(INTDIR)\TCSplit.sbr"
	-@erase "$(INTDIR)\TCTrace.obj"
	-@erase "$(INTDIR)\TCTrace.sbr"
	-@erase "$(INTDIR)\TCView.obj"
	-@erase "$(INTDIR)\TCView.sbr"
	-@erase "$(INTDIR)\TstCon.obj"
	-@erase "$(INTDIR)\TstCon.pch"
	-@erase "$(INTDIR)\TstCon.res"
	-@erase "$(INTDIR)\TstCon.sbr"
	-@erase "$(INTDIR)\TstCon.tlb"
	-@erase "$(INTDIR)\TypeAttr.obj"
	-@erase "$(INTDIR)\TypeAttr.sbr"
	-@erase "$(INTDIR)\VarUtils.obj"
	-@erase "$(INTDIR)\VarUtils.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\TstCon.bsc"
	-@erase "$(OUTDIR)\TstCon32.exe"
	-@erase "$(OUTDIR)\TstCon32.ilk"
	-@erase "$(OUTDIR)\TstCon32.pdb"
	-@erase ".\TstCon_i.c"
	-@erase ".\TstConIF.h"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W4 /Gm /GX /ZI /Od /I "TCProps\Debug" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\TstCon.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=/nologo /D "_DEBUG" /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\TstCon.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\TstCon.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\AProp.sbr" \
	"$(INTDIR)\APropDg.sbr" \
	"$(INTDIR)\BindHost.sbr" \
	"$(INTDIR)\ComCatDg.sbr" \
	"$(INTDIR)\ConInfDg.sbr" \
	"$(INTDIR)\EvLogPg.sbr" \
	"$(INTDIR)\ExcepInf.sbr" \
	"$(INTDIR)\ExtCtl.sbr" \
	"$(INTDIR)\FeatPg.sbr" \
	"$(INTDIR)\IFacesPg.sbr" \
	"$(INTDIR)\InsCtlDg.sbr" \
	"$(INTDIR)\Log.sbr" \
	"$(INTDIR)\LogDg.sbr" \
	"$(INTDIR)\MacroCB.sbr" \
	"$(INTDIR)\MacroDB.sbr" \
	"$(INTDIR)\MacroDg.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\MethInfo.sbr" \
	"$(INTDIR)\MethodDg.sbr" \
	"$(INTDIR)\MFileWnd.sbr" \
	"$(INTDIR)\NewAPDg.sbr" \
	"$(INTDIR)\OutWndVw.sbr" \
	"$(INTDIR)\PBagDg.sbr" \
	"$(INTDIR)\PChngPg.sbr" \
	"$(INTDIR)\PEdReqPg.sbr" \
	"$(INTDIR)\PropBag.sbr" \
	"$(INTDIR)\RegCtlDg.sbr" \
	"$(INTDIR)\Script.sbr" \
	"$(INTDIR)\ScrMngr.sbr" \
	"$(INTDIR)\ServPg.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\TabOrdDg.sbr" \
	"$(INTDIR)\TCDoc.sbr" \
	"$(INTDIR)\TCItem.sbr" \
	"$(INTDIR)\TCSplit.sbr" \
	"$(INTDIR)\TCTrace.sbr" \
	"$(INTDIR)\TCView.sbr" \
	"$(INTDIR)\TstCon.sbr" \
	"$(INTDIR)\TypeAttr.sbr" \
	"$(INTDIR)\VarUtils.sbr"

"$(OUTDIR)\TstCon.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=shlwapi.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\TstCon32.pdb" /debug /machine:I386 /out:"$(OUTDIR)\TstCon32.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\AProp.obj" \
	"$(INTDIR)\APropDg.obj" \
	"$(INTDIR)\BindHost.obj" \
	"$(INTDIR)\ComCatDg.obj" \
	"$(INTDIR)\ConInfDg.obj" \
	"$(INTDIR)\EvLogPg.obj" \
	"$(INTDIR)\ExcepInf.obj" \
	"$(INTDIR)\ExtCtl.obj" \
	"$(INTDIR)\FeatPg.obj" \
	"$(INTDIR)\IFacesPg.obj" \
	"$(INTDIR)\InsCtlDg.obj" \
	"$(INTDIR)\Log.obj" \
	"$(INTDIR)\LogDg.obj" \
	"$(INTDIR)\MacroCB.obj" \
	"$(INTDIR)\MacroDB.obj" \
	"$(INTDIR)\MacroDg.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MethInfo.obj" \
	"$(INTDIR)\MethodDg.obj" \
	"$(INTDIR)\MFileWnd.obj" \
	"$(INTDIR)\NewAPDg.obj" \
	"$(INTDIR)\OutWndVw.obj" \
	"$(INTDIR)\PBagDg.obj" \
	"$(INTDIR)\PChngPg.obj" \
	"$(INTDIR)\PEdReqPg.obj" \
	"$(INTDIR)\PropBag.obj" \
	"$(INTDIR)\RegCtlDg.obj" \
	"$(INTDIR)\Script.obj" \
	"$(INTDIR)\ScrMngr.obj" \
	"$(INTDIR)\ServPg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TabOrdDg.obj" \
	"$(INTDIR)\TCDoc.obj" \
	"$(INTDIR)\TCItem.obj" \
	"$(INTDIR)\TCSplit.obj" \
	"$(INTDIR)\TCTrace.obj" \
	"$(INTDIR)\TCView.obj" \
	"$(INTDIR)\TstCon.obj" \
	"$(INTDIR)\TypeAttr.obj" \
	"$(INTDIR)\VarUtils.obj" \
	"$(INTDIR)\TstCon.res" \
	".\TCProps\Debug\TCProps.lib"

"$(OUTDIR)\TstCon32.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

SOURCE="$(InputPath)"
PostBuild_Desc=Building help file...
DS_POSTBUILD_DEP=$(INTDIR)\postbld.dep

ALL : $(DS_POSTBUILD_DEP)

# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

$(DS_POSTBUILD_DEP) : "TCProps - Win32 Debug" "$(OUTDIR)\TstCon32.exe" ".\TstCon_i.c" "$(OUTDIR)\TstCon.bsc"
   makehelp.bat
	echo Helper for Post-build step > "$(DS_POSTBUILD_DEP)"

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("TstCon.dep")
!INCLUDE "TstCon.dep"
!ELSE 
!MESSAGE Warning: cannot find "TstCon.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "TstCon - Win32 Release" || "$(CFG)" == "TstCon - Win32 Debug"
SOURCE=.\AProp.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\AProp.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\AProp.obj"	"$(INTDIR)\AProp.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\APropDg.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\APropDg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\APropDg.obj"	"$(INTDIR)\APropDg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\BindHost.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\BindHost.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\BindHost.obj"	"$(INTDIR)\BindHost.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\ComCatDg.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\ComCatDg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\ComCatDg.obj"	"$(INTDIR)\ComCatDg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\ConInfDg.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\ConInfDg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\ConInfDg.obj"	"$(INTDIR)\ConInfDg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\EvLogPg.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\EvLogPg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\EvLogPg.obj"	"$(INTDIR)\EvLogPg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\ExcepInf.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\ExcepInf.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\ExcepInf.obj"	"$(INTDIR)\ExcepInf.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\ExtCtl.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\ExtCtl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\ExtCtl.obj"	"$(INTDIR)\ExtCtl.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\FeatPg.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\FeatPg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\FeatPg.obj"	"$(INTDIR)\FeatPg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\IFacesPg.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\IFacesPg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\IFacesPg.obj"	"$(INTDIR)\IFacesPg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\InsCtlDg.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\InsCtlDg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\InsCtlDg.obj"	"$(INTDIR)\InsCtlDg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\Log.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\Log.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\Log.obj"	"$(INTDIR)\Log.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\LogDg.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\LogDg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\LogDg.obj"	"$(INTDIR)\LogDg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\MacroCB.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\MacroCB.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\MacroCB.obj"	"$(INTDIR)\MacroCB.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\MacroDB.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\MacroDB.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\MacroDB.obj"	"$(INTDIR)\MacroDB.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\MacroDg.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\MacroDg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\MacroDg.obj"	"$(INTDIR)\MacroDg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\MainFrm.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\MainFrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\MainFrm.obj"	"$(INTDIR)\MainFrm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\MethInfo.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\MethInfo.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\MethInfo.obj"	"$(INTDIR)\MethInfo.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\MethodDg.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\MethodDg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\MethodDg.obj"	"$(INTDIR)\MethodDg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\MFileWnd.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\MFileWnd.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\MFileWnd.obj"	"$(INTDIR)\MFileWnd.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\NewAPDg.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\NewAPDg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\NewAPDg.obj"	"$(INTDIR)\NewAPDg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\OutWndVw.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\OutWndVw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\OutWndVw.obj"	"$(INTDIR)\OutWndVw.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\PBagDg.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\PBagDg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\PBagDg.obj"	"$(INTDIR)\PBagDg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\PChngPg.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\PChngPg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\PChngPg.obj"	"$(INTDIR)\PChngPg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\PEdReqPg.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\PEdReqPg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\PEdReqPg.obj"	"$(INTDIR)\PEdReqPg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\PropBag.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\PropBag.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\PropBag.obj"	"$(INTDIR)\PropBag.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\RegCtlDg.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\RegCtlDg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\RegCtlDg.obj"	"$(INTDIR)\RegCtlDg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\Script.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\Script.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\Script.obj"	"$(INTDIR)\Script.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\ScrMngr.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\ScrMngr.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\ScrMngr.obj"	"$(INTDIR)\ScrMngr.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\ServPg.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\ServPg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\ServPg.obj"	"$(INTDIR)\ServPg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"

CPP_SWITCHES=/nologo /MD /W4 /GX /O2 /I "TCProps\Release" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\TstCon.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\TstCon.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W4 /Gm /GX /ZI /Od /I "TCProps\Debug" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\TstCon.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\TstCon.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\TabOrdDg.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\TabOrdDg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\TabOrdDg.obj"	"$(INTDIR)\TabOrdDg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\TCDoc.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\TCDoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\TCDoc.obj"	"$(INTDIR)\TCDoc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\TCItem.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\TCItem.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\TCItem.obj"	"$(INTDIR)\TCItem.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\TCSplit.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\TCSplit.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\TCSplit.obj"	"$(INTDIR)\TCSplit.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\TCTrace.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\TCTrace.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\TCTrace.obj"	"$(INTDIR)\TCTrace.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\TCView.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\TCView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\TCView.obj"	"$(INTDIR)\TCView.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\TstCon.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\TstCon.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\TstCon.obj"	"$(INTDIR)\TstCon.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\TstCon.odl

!IF  "$(CFG)" == "TstCon - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\TstCon.tlb" /h "TstConIF.H" /iid "TstCon_i.C" /win32 

"$(OUTDIR)\TstCon.tlb"	".\TstConIF.h"	".\TstCon_i.c" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\TstCon.tlb" /h "TstConIF.H" /iid "TstCon_i.C" /win32 

"$(OUTDIR)\TstCon.tlb"	".\TstConIF.h"	".\TstCon_i.c" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\TstCon.rc

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\TstCon.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\TstCon.res" /i "Release" /i "TCProps\Release" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\TstCon.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\TstCon.res" /i "Debug" /i "TCProps\Debug" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ENDIF 

SOURCE=.\TypeAttr.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\TypeAttr.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\TypeAttr.obj"	"$(INTDIR)\TypeAttr.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

SOURCE=.\VarUtils.Cpp

!IF  "$(CFG)" == "TstCon - Win32 Release"


"$(INTDIR)\VarUtils.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"


"$(INTDIR)\VarUtils.obj"	"$(INTDIR)\VarUtils.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TstCon.pch" ".\TstConIF.h"


!ENDIF 

!IF  "$(CFG)" == "TstCon - Win32 Release"

"TCProps - Win32 Release" : 
   cd ".\TCProps"
   $(MAKE) /$(MAKEFLAGS) /F .\TCProps.mak CFG="TCProps - Win32 Release" 
   cd ".."

"TCProps - Win32 ReleaseCLEAN" : 
   cd ".\TCProps"
   $(MAKE) /$(MAKEFLAGS) /F .\TCProps.mak CFG="TCProps - Win32 Release" RECURSE=1 CLEAN 
   cd ".."

!ELSEIF  "$(CFG)" == "TstCon - Win32 Debug"

"TCProps - Win32 Debug" : 
   cd ".\TCProps"
   $(MAKE) /$(MAKEFLAGS) /F .\TCProps.mak CFG="TCProps - Win32 Debug" 
   cd ".."

"TCProps - Win32 DebugCLEAN" : 
   cd ".\TCProps"
   $(MAKE) /$(MAKEFLAGS) /F .\TCProps.mak CFG="TCProps - Win32 Debug" RECURSE=1 CLEAN 
   cd ".."

!ENDIF 


!ENDIF 

