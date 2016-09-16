# Microsoft Developer Studio Generated NMAKE File, Based on rowlist.dsp
!IF "$(CFG)" == ""
CFG=RowList - Win32 Static Debug
!MESSAGE No configuration specified. Defaulting to RowList - Win32 Static Debug.
!ENDIF 

!IF "$(CFG)" != "RowList - Win32 Release" && "$(CFG)" != "RowList - Win32 Debug" && "$(CFG)" != "RowList - Win32 Static Debug" && "$(CFG)" != "RowList - Win32 Static Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "rowlist.mak" CFG="RowList - Win32 Static Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "RowList - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "RowList - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "RowList - Win32 Static Debug" (based on "Win32 (x86) Application")
!MESSAGE "RowList - Win32 Static Release" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "RowList - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\rowlist.exe"


CLEAN :
	-@erase "$(INTDIR)\Listvwex.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\RListDoc.obj"
	-@erase "$(INTDIR)\RListVw.obj"
	-@erase "$(INTDIR)\RowList.obj"
	-@erase "$(INTDIR)\rowlist.pch"
	-@erase "$(INTDIR)\RowList.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\rowlist.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\rowlist.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\RowList.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\rowlist.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\rowlist.pdb" /machine:I386 /out:"$(OUTDIR)\rowlist.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Listvwex.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\RListDoc.obj" \
	"$(INTDIR)\RListVw.obj" \
	"$(INTDIR)\RowList.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\RowList.res"

"$(OUTDIR)\rowlist.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "RowList - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\rowlist.exe"


CLEAN :
	-@erase "$(INTDIR)\Listvwex.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\RListDoc.obj"
	-@erase "$(INTDIR)\RListVw.obj"
	-@erase "$(INTDIR)\RowList.obj"
	-@erase "$(INTDIR)\rowlist.pch"
	-@erase "$(INTDIR)\RowList.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\rowlist.exe"
	-@erase "$(OUTDIR)\rowlist.ilk"
	-@erase "$(OUTDIR)\rowlist.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\rowlist.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\RowList.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\rowlist.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\rowlist.pdb" /debug /machine:I386 /out:"$(OUTDIR)\rowlist.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Listvwex.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\RListDoc.obj" \
	"$(INTDIR)\RListVw.obj" \
	"$(INTDIR)\RowList.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\RowList.res"

"$(OUTDIR)\rowlist.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "RowList - Win32 Static Debug"

OUTDIR=.\StaticDebug
INTDIR=.\StaticDebug
# Begin Custom Macros
OutDir=.\StaticDebug
# End Custom Macros

ALL : "$(OUTDIR)\rowlist.exe"


CLEAN :
	-@erase "$(INTDIR)\Listvwex.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\RListDoc.obj"
	-@erase "$(INTDIR)\RListVw.obj"
	-@erase "$(INTDIR)\RowList.obj"
	-@erase "$(INTDIR)\rowlist.pch"
	-@erase "$(INTDIR)\RowList.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\rowlist.exe"
	-@erase "$(OUTDIR)\rowlist.ilk"
	-@erase "$(OUTDIR)\rowlist.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\rowlist.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\RowList.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\rowlist.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\rowlist.pdb" /debug /machine:I386 /out:"$(OUTDIR)\rowlist.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Listvwex.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\RListDoc.obj" \
	"$(INTDIR)\RListVw.obj" \
	"$(INTDIR)\RowList.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\RowList.res"

"$(OUTDIR)\rowlist.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "RowList - Win32 Static Release"

OUTDIR=.\StaticRelease
INTDIR=.\StaticRelease
# Begin Custom Macros
OutDir=.\StaticRelease
# End Custom Macros

ALL : "$(OUTDIR)\rowlist.exe"


CLEAN :
	-@erase "$(INTDIR)\Listvwex.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\RListDoc.obj"
	-@erase "$(INTDIR)\RListVw.obj"
	-@erase "$(INTDIR)\RowList.obj"
	-@erase "$(INTDIR)\rowlist.pch"
	-@erase "$(INTDIR)\RowList.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\rowlist.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\rowlist.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\RowList.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\rowlist.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\rowlist.pdb" /machine:I386 /out:"$(OUTDIR)\rowlist.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Listvwex.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\RListDoc.obj" \
	"$(INTDIR)\RListVw.obj" \
	"$(INTDIR)\RowList.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\RowList.res"

"$(OUTDIR)\rowlist.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("rowlist.dep")
!INCLUDE "rowlist.dep"
!ELSE 
!MESSAGE Warning: cannot find "rowlist.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "RowList - Win32 Release" || "$(CFG)" == "RowList - Win32 Debug" || "$(CFG)" == "RowList - Win32 Static Debug" || "$(CFG)" == "RowList - Win32 Static Release"
SOURCE=.\Listvwex.cpp

"$(INTDIR)\Listvwex.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\rowlist.pch"


SOURCE=.\MainFrm.cpp

"$(INTDIR)\MainFrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\rowlist.pch"


SOURCE=.\RListDoc.cpp

"$(INTDIR)\RListDoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\rowlist.pch"


SOURCE=.\RListVw.cpp

"$(INTDIR)\RListVw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\rowlist.pch"


SOURCE=.\RowList.cpp

"$(INTDIR)\RowList.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\rowlist.pch"


SOURCE=.\RowList.rc

"$(INTDIR)\RowList.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "RowList - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\rowlist.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\rowlist.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "RowList - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\rowlist.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\rowlist.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "RowList - Win32 Static Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\rowlist.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\rowlist.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "RowList - Win32 Static Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\rowlist.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\rowlist.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

