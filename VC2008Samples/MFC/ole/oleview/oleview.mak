# Microsoft Developer Studio Generated NMAKE File, Based on oleview.dsp
!IF "$(CFG)" == ""
CFG=oleview - Win32 Debug
!MESSAGE No configuration specified. Defaulting to oleview - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "oleview - Win32 Debug" && "$(CFG)" != "oleview - Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "oleview.mak" CFG="oleview - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "oleview - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "oleview - Win32 Release" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "oleview - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\oleview.exe" "$(OUTDIR)\oleview.bsc"


CLEAN :
	-@erase "$(INTDIR)\doc.obj"
	-@erase "$(INTDIR)\doc.sbr"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\mainfrm.sbr"
	-@erase "$(INTDIR)\obj_vw.obj"
	-@erase "$(INTDIR)\obj_vw.sbr"
	-@erase "$(INTDIR)\oleview.obj"
	-@erase "$(INTDIR)\oleview.pch"
	-@erase "$(INTDIR)\oleview.res"
	-@erase "$(INTDIR)\oleview.sbr"
	-@erase "$(INTDIR)\regview.obj"
	-@erase "$(INTDIR)\regview.sbr"
	-@erase "$(INTDIR)\shadow.obj"
	-@erase "$(INTDIR)\shadow.sbr"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\stdafx.sbr"
	-@erase "$(INTDIR)\util.obj"
	-@erase "$(INTDIR)\util.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\view.obj"
	-@erase "$(INTDIR)\view.sbr"
	-@erase "$(OUTDIR)\oleview.bsc"
	-@erase "$(OUTDIR)\oleview.exe"
	-@erase "$(OUTDIR)\oleview.ilk"
	-@erase "$(OUTDIR)\oleview.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\oleview.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\oleview.res" /d "_DEBUG" /d "_AFXDLL" /d "WIN32" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\oleview.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\doc.sbr" \
	"$(INTDIR)\mainfrm.sbr" \
	"$(INTDIR)\obj_vw.sbr" \
	"$(INTDIR)\oleview.sbr" \
	"$(INTDIR)\regview.sbr" \
	"$(INTDIR)\shadow.sbr" \
	"$(INTDIR)\stdafx.sbr" \
	"$(INTDIR)\util.sbr" \
	"$(INTDIR)\view.sbr"

"$(OUTDIR)\oleview.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=version.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\oleview.pdb" /debug /machine:I386 /out:"$(OUTDIR)\oleview.exe" 
LINK32_OBJS= \
	"$(INTDIR)\doc.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\obj_vw.obj" \
	"$(INTDIR)\oleview.obj" \
	"$(INTDIR)\regview.obj" \
	"$(INTDIR)\shadow.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\util.obj" \
	"$(INTDIR)\view.obj" \
	"$(INTDIR)\oleview.res"

"$(OUTDIR)\oleview.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

SOURCE=$(InputPath)
PostBuild_Desc=Note:
DS_POSTBUILD_DEP=$(INTDIR)\postbld.dep

ALL : $(DS_POSTBUILD_DEP)

# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

$(DS_POSTBUILD_DEP) : "$(OUTDIR)\oleview.exe" "$(OUTDIR)\oleview.bsc"
   echo Make sure you build the IViewers.dll project that ships  with this sample
	echo  to allow you to view interfaces using the Oleview  sample.
	echo Helper for Post-build step > "$(DS_POSTBUILD_DEP)"

!ELSEIF  "$(CFG)" == "oleview - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\oleview.exe"


CLEAN :
	-@erase "$(INTDIR)\doc.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\obj_vw.obj"
	-@erase "$(INTDIR)\oleview.obj"
	-@erase "$(INTDIR)\oleview.pch"
	-@erase "$(INTDIR)\oleview.res"
	-@erase "$(INTDIR)\regview.obj"
	-@erase "$(INTDIR)\shadow.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\util.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\view.obj"
	-@erase "$(OUTDIR)\oleview.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)\oleview.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\oleview.res" /d "NDEBUG" /d "_AFXDLL" /d "WIN32" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\oleview.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=version.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\oleview.pdb" /machine:I386 /out:"$(OUTDIR)\oleview.exe" 
LINK32_OBJS= \
	"$(INTDIR)\doc.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\obj_vw.obj" \
	"$(INTDIR)\oleview.obj" \
	"$(INTDIR)\regview.obj" \
	"$(INTDIR)\shadow.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\util.obj" \
	"$(INTDIR)\view.obj" \
	"$(INTDIR)\oleview.res"

"$(OUTDIR)\oleview.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

SOURCE=$(InputPath)
PostBuild_Desc=Note:
DS_POSTBUILD_DEP=$(INTDIR)\postbld.dep

ALL : $(DS_POSTBUILD_DEP)

# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

$(DS_POSTBUILD_DEP) : "$(OUTDIR)\oleview.exe"
   echo Make sure you build the IViewers.dll project that ships  with this sample
	echo  to allow you to view interfaces using the Oleview  sample.
	echo Helper for Post-build step > "$(DS_POSTBUILD_DEP)"

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

MTL_PROJ=/mktyplib203 

!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("oleview.dep")
!INCLUDE "oleview.dep"
!ELSE 
!MESSAGE Warning: cannot find "oleview.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "oleview - Win32 Debug" || "$(CFG)" == "oleview - Win32 Release"
SOURCE=.\doc.cpp

!IF  "$(CFG)" == "oleview - Win32 Debug"


"$(INTDIR)\doc.obj"	"$(INTDIR)\doc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\oleview.pch"


!ELSEIF  "$(CFG)" == "oleview - Win32 Release"


"$(INTDIR)\doc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\oleview.pch"


!ENDIF 

SOURCE=.\mainfrm.cpp

!IF  "$(CFG)" == "oleview - Win32 Debug"


"$(INTDIR)\mainfrm.obj"	"$(INTDIR)\mainfrm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\oleview.pch"


!ELSEIF  "$(CFG)" == "oleview - Win32 Release"


"$(INTDIR)\mainfrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\oleview.pch"


!ENDIF 

SOURCE=.\obj_vw.cpp

!IF  "$(CFG)" == "oleview - Win32 Debug"


"$(INTDIR)\obj_vw.obj"	"$(INTDIR)\obj_vw.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\oleview.pch"


!ELSEIF  "$(CFG)" == "oleview - Win32 Release"


"$(INTDIR)\obj_vw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\oleview.pch"


!ENDIF 

SOURCE=.\oleview.cpp

!IF  "$(CFG)" == "oleview - Win32 Debug"


"$(INTDIR)\oleview.obj"	"$(INTDIR)\oleview.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\oleview.pch"


!ELSEIF  "$(CFG)" == "oleview - Win32 Release"


"$(INTDIR)\oleview.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\oleview.pch"


!ENDIF 

SOURCE=.\oleview.rc

"$(INTDIR)\oleview.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\regview.cpp

!IF  "$(CFG)" == "oleview - Win32 Debug"


"$(INTDIR)\regview.obj"	"$(INTDIR)\regview.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\oleview.pch"


!ELSEIF  "$(CFG)" == "oleview - Win32 Release"


"$(INTDIR)\regview.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\oleview.pch"


!ENDIF 

SOURCE=.\shadow.cpp

!IF  "$(CFG)" == "oleview - Win32 Debug"


"$(INTDIR)\shadow.obj"	"$(INTDIR)\shadow.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\oleview.pch"


!ELSEIF  "$(CFG)" == "oleview - Win32 Release"


"$(INTDIR)\shadow.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\oleview.pch"


!ENDIF 

SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "oleview - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\oleview.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\stdafx.sbr"	"$(INTDIR)\oleview.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "oleview - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)\oleview.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\oleview.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\util.cpp

!IF  "$(CFG)" == "oleview - Win32 Debug"


"$(INTDIR)\util.obj"	"$(INTDIR)\util.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\oleview.pch"


!ELSEIF  "$(CFG)" == "oleview - Win32 Release"


"$(INTDIR)\util.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\oleview.pch"


!ENDIF 

SOURCE=.\view.cpp

!IF  "$(CFG)" == "oleview - Win32 Debug"


"$(INTDIR)\view.obj"	"$(INTDIR)\view.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\oleview.pch"


!ELSEIF  "$(CFG)" == "oleview - Win32 Release"


"$(INTDIR)\view.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\oleview.pch"


!ENDIF 


!ENDIF 

