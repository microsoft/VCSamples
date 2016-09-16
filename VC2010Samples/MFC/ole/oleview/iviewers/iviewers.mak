# Microsoft Developer Studio Generated NMAKE File, Based on iviewers.dsp
!IF "$(CFG)" == ""
CFG=iviewers - Win32 DLL Release
!MESSAGE No configuration specified. Defaulting to iviewers - Win32 DLL Release.
!ENDIF 

!IF "$(CFG)" != "iviewers - Win32 DLL Release" && "$(CFG)" != "iviewers - Win32 DLL Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "iviewers.mak" CFG="iviewers - Win32 DLL Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "iviewers - Win32 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "iviewers - Win32 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "iviewers - Win32 DLL Release"

OUTDIR=.\..\release
INTDIR=.\dllrel
# Begin Custom Macros
OutDir=.\..\release
# End Custom Macros

ALL : "$(OUTDIR)\iviewers.dll" "$(OUTDIR)\iviewers.bsc"


CLEAN :
	-@erase "$(INTDIR)\dataobj.obj"
	-@erase "$(INTDIR)\dataobj.sbr"
	-@erase "$(INTDIR)\dispatch.obj"
	-@erase "$(INTDIR)\dispatch.sbr"
	-@erase "$(INTDIR)\guid.obj"
	-@erase "$(INTDIR)\guid.sbr"
	-@erase "$(INTDIR)\iadvsink.obj"
	-@erase "$(INTDIR)\iadvsink.sbr"
	-@erase "$(INTDIR)\idataobj.obj"
	-@erase "$(INTDIR)\idataobj.sbr"
	-@erase "$(INTDIR)\iviewer.obj"
	-@erase "$(INTDIR)\iviewer.sbr"
	-@erase "$(INTDIR)\iviewers.obj"
	-@erase "$(INTDIR)\iviewers.pch"
	-@erase "$(INTDIR)\iviewers.res"
	-@erase "$(INTDIR)\iviewers.sbr"
	-@erase "$(INTDIR)\shadow.obj"
	-@erase "$(INTDIR)\shadow.sbr"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\stdafx.sbr"
	-@erase "$(INTDIR)\tlblist.obj"
	-@erase "$(INTDIR)\tlblist.sbr"
	-@erase "$(INTDIR)\tlbodl.obj"
	-@erase "$(INTDIR)\tlbodl.sbr"
	-@erase "$(INTDIR)\tlbtree.obj"
	-@erase "$(INTDIR)\tlbtree.sbr"
	-@erase "$(INTDIR)\tree.obj"
	-@erase "$(INTDIR)\tree.sbr"
	-@erase "$(INTDIR)\typelib.obj"
	-@erase "$(INTDIR)\typelib.sbr"
	-@erase "$(INTDIR)\util.obj"
	-@erase "$(INTDIR)\util.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\iviewers.bsc"
	-@erase "$(OUTDIR)\iviewers.dll"
	-@erase "$(OUTDIR)\iviewers.exp"
	-@erase "$(OUTDIR)\iviewers.ilk"
	-@erase "$(OUTDIR)\iviewers.lib"
	-@erase "$(OUTDIR)\iviewers.pdb"
	-@erase ".\dllrel\iviewers.map"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W4 /WX /GX /O2 /D "NDEBUG" /D "_USRDLL" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_WINDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\iviewers.pch" /Yu"STDAFX.H" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\iviewers.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\iviewers.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\dataobj.sbr" \
	"$(INTDIR)\dispatch.sbr" \
	"$(INTDIR)\guid.sbr" \
	"$(INTDIR)\iadvsink.sbr" \
	"$(INTDIR)\idataobj.sbr" \
	"$(INTDIR)\iviewer.sbr" \
	"$(INTDIR)\iviewers.sbr" \
	"$(INTDIR)\shadow.sbr" \
	"$(INTDIR)\stdafx.sbr" \
	"$(INTDIR)\tlblist.sbr" \
	"$(INTDIR)\tlbodl.sbr" \
	"$(INTDIR)\tlbtree.sbr" \
	"$(INTDIR)\tree.sbr" \
	"$(INTDIR)\typelib.sbr" \
	"$(INTDIR)\util.sbr"

"$(OUTDIR)\iviewers.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\iviewers.pdb" /map:"$(INTDIR)\iviewers.map" /debug /machine:I386 /def:".\iviewers.def" /out:"$(OUTDIR)\iviewers.dll" /implib:"$(OUTDIR)\iviewers.lib" 
DEF_FILE= \
	".\iviewers.def"
LINK32_OBJS= \
	"$(INTDIR)\dataobj.obj" \
	"$(INTDIR)\dispatch.obj" \
	"$(INTDIR)\guid.obj" \
	"$(INTDIR)\iadvsink.obj" \
	"$(INTDIR)\idataobj.obj" \
	"$(INTDIR)\iviewer.obj" \
	"$(INTDIR)\iviewers.obj" \
	"$(INTDIR)\shadow.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\tlblist.obj" \
	"$(INTDIR)\tlbodl.obj" \
	"$(INTDIR)\tlbtree.obj" \
	"$(INTDIR)\tree.obj" \
	"$(INTDIR)\typelib.obj" \
	"$(INTDIR)\util.obj" \
	"$(INTDIR)\iviewers.res"

"$(OUTDIR)\iviewers.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "iviewers - Win32 DLL Debug"

OUTDIR=.\..\debug
INTDIR=.\dlldebug
# Begin Custom Macros
OutDir=.\..\debug
# End Custom Macros

ALL : "$(OUTDIR)\iviewers.dll"


CLEAN :
	-@erase "$(INTDIR)\dataobj.obj"
	-@erase "$(INTDIR)\dispatch.obj"
	-@erase "$(INTDIR)\guid.obj"
	-@erase "$(INTDIR)\iadvsink.obj"
	-@erase "$(INTDIR)\idataobj.obj"
	-@erase "$(INTDIR)\iviewer.obj"
	-@erase "$(INTDIR)\iviewers.obj"
	-@erase "$(INTDIR)\iviewers.pch"
	-@erase "$(INTDIR)\iviewers.res"
	-@erase "$(INTDIR)\shadow.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\tlblist.obj"
	-@erase "$(INTDIR)\tlbodl.obj"
	-@erase "$(INTDIR)\tlbtree.obj"
	-@erase "$(INTDIR)\tree.obj"
	-@erase "$(INTDIR)\typelib.obj"
	-@erase "$(INTDIR)\util.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\iviewers.dll"
	-@erase "$(OUTDIR)\iviewers.exp"
	-@erase "$(OUTDIR)\iviewers.lib"
	-@erase "$(OUTDIR)\iviewers.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W4 /WX /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_USRDLL" /D "_MBCS" /Fp"$(INTDIR)\iviewers.pch" /Yu"STDAFX.H" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\iviewers.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\iviewers.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\iviewers.pdb" /debug /machine:I386 /def:".\iviewers.def" /out:"$(OUTDIR)\iviewers.dll" /implib:"$(OUTDIR)\iviewers.lib" 
DEF_FILE= \
	".\iviewers.def"
LINK32_OBJS= \
	"$(INTDIR)\dataobj.obj" \
	"$(INTDIR)\dispatch.obj" \
	"$(INTDIR)\guid.obj" \
	"$(INTDIR)\iadvsink.obj" \
	"$(INTDIR)\idataobj.obj" \
	"$(INTDIR)\iviewer.obj" \
	"$(INTDIR)\iviewers.obj" \
	"$(INTDIR)\shadow.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\tlblist.obj" \
	"$(INTDIR)\tlbodl.obj" \
	"$(INTDIR)\tlbtree.obj" \
	"$(INTDIR)\tree.obj" \
	"$(INTDIR)\typelib.obj" \
	"$(INTDIR)\util.obj" \
	"$(INTDIR)\iviewers.res"

"$(OUTDIR)\iviewers.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

TargetDir=\Rtl\MfcT\Vc98\Samples\MFC\ole\oleview\debug
SOURCE="$(InputPath)"
PostBuild_Desc=copying iviewers.dll to system directory
DS_POSTBUILD_DEP=$(INTDIR)\postbld.dep

ALL : $(DS_POSTBUILD_DEP)

# Begin Custom Macros
OutDir=.\..\debug
# End Custom Macros

$(DS_POSTBUILD_DEP) : "$(OUTDIR)\iviewers.dll"
   copy \Rtl\MfcT\Vc98\Samples\MFC\ole\oleview\debug\iviewers.dll %windir%\iviewers.dll
	echo Helper for Post-build step > "$(DS_POSTBUILD_DEP)"

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("iviewers.dep")
!INCLUDE "iviewers.dep"
!ELSE 
!MESSAGE Warning: cannot find "iviewers.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "iviewers - Win32 DLL Release" || "$(CFG)" == "iviewers - Win32 DLL Debug"
SOURCE=.\dataobj.cpp

!IF  "$(CFG)" == "iviewers - Win32 DLL Release"


"$(INTDIR)\dataobj.obj"	"$(INTDIR)\dataobj.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ELSEIF  "$(CFG)" == "iviewers - Win32 DLL Debug"


"$(INTDIR)\dataobj.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ENDIF 

SOURCE=.\dispatch.cpp

!IF  "$(CFG)" == "iviewers - Win32 DLL Release"


"$(INTDIR)\dispatch.obj"	"$(INTDIR)\dispatch.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ELSEIF  "$(CFG)" == "iviewers - Win32 DLL Debug"


"$(INTDIR)\dispatch.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ENDIF 

SOURCE=.\guid.cpp

!IF  "$(CFG)" == "iviewers - Win32 DLL Release"


"$(INTDIR)\guid.obj"	"$(INTDIR)\guid.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ELSEIF  "$(CFG)" == "iviewers - Win32 DLL Debug"


"$(INTDIR)\guid.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ENDIF 

SOURCE=.\iadvsink.cpp

!IF  "$(CFG)" == "iviewers - Win32 DLL Release"


"$(INTDIR)\iadvsink.obj"	"$(INTDIR)\iadvsink.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ELSEIF  "$(CFG)" == "iviewers - Win32 DLL Debug"


"$(INTDIR)\iadvsink.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ENDIF 

SOURCE=.\idataobj.cpp

!IF  "$(CFG)" == "iviewers - Win32 DLL Release"


"$(INTDIR)\idataobj.obj"	"$(INTDIR)\idataobj.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ELSEIF  "$(CFG)" == "iviewers - Win32 DLL Debug"


"$(INTDIR)\idataobj.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ENDIF 

SOURCE=.\iviewer.cpp

!IF  "$(CFG)" == "iviewers - Win32 DLL Release"


"$(INTDIR)\iviewer.obj"	"$(INTDIR)\iviewer.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ELSEIF  "$(CFG)" == "iviewers - Win32 DLL Debug"


"$(INTDIR)\iviewer.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ENDIF 

SOURCE=.\iviewers.cpp

!IF  "$(CFG)" == "iviewers - Win32 DLL Release"


"$(INTDIR)\iviewers.obj"	"$(INTDIR)\iviewers.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ELSEIF  "$(CFG)" == "iviewers - Win32 DLL Debug"


"$(INTDIR)\iviewers.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ENDIF 

SOURCE=.\iviewers.rc

"$(INTDIR)\iviewers.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\shadow.cpp

!IF  "$(CFG)" == "iviewers - Win32 DLL Release"


"$(INTDIR)\shadow.obj"	"$(INTDIR)\shadow.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ELSEIF  "$(CFG)" == "iviewers - Win32 DLL Debug"


"$(INTDIR)\shadow.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ENDIF 

SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "iviewers - Win32 DLL Release"

CPP_SWITCHES=/nologo /MT /W4 /WX /GX /O2 /D "NDEBUG" /D "_USRDLL" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_WINDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\iviewers.pch" /Yc"STDAFX.H" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\iviewers.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "iviewers - Win32 DLL Debug"

CPP_SWITCHES=/nologo /MTd /W4 /WX /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_USRDLL" /D "_MBCS" /Fp"$(INTDIR)\iviewers.pch" /Yc"STDAFX.H" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\iviewers.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\tlblist.cpp

!IF  "$(CFG)" == "iviewers - Win32 DLL Release"


"$(INTDIR)\tlblist.obj"	"$(INTDIR)\tlblist.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ELSEIF  "$(CFG)" == "iviewers - Win32 DLL Debug"


"$(INTDIR)\tlblist.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ENDIF 

SOURCE=.\tlbodl.cpp

!IF  "$(CFG)" == "iviewers - Win32 DLL Release"


"$(INTDIR)\tlbodl.obj"	"$(INTDIR)\tlbodl.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ELSEIF  "$(CFG)" == "iviewers - Win32 DLL Debug"


"$(INTDIR)\tlbodl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ENDIF 

SOURCE=.\tlbtree.cpp

!IF  "$(CFG)" == "iviewers - Win32 DLL Release"


"$(INTDIR)\tlbtree.obj"	"$(INTDIR)\tlbtree.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ELSEIF  "$(CFG)" == "iviewers - Win32 DLL Debug"


"$(INTDIR)\tlbtree.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ENDIF 

SOURCE=.\tree.cpp

!IF  "$(CFG)" == "iviewers - Win32 DLL Release"


"$(INTDIR)\tree.obj"	"$(INTDIR)\tree.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ELSEIF  "$(CFG)" == "iviewers - Win32 DLL Debug"


"$(INTDIR)\tree.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ENDIF 

SOURCE=.\typelib.cpp

!IF  "$(CFG)" == "iviewers - Win32 DLL Release"


"$(INTDIR)\typelib.obj"	"$(INTDIR)\typelib.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ELSEIF  "$(CFG)" == "iviewers - Win32 DLL Debug"


"$(INTDIR)\typelib.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ENDIF 

SOURCE=.\util.cpp

!IF  "$(CFG)" == "iviewers - Win32 DLL Release"


"$(INTDIR)\util.obj"	"$(INTDIR)\util.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ELSEIF  "$(CFG)" == "iviewers - Win32 DLL Debug"


"$(INTDIR)\util.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\iviewers.pch"


!ENDIF 


!ENDIF 

