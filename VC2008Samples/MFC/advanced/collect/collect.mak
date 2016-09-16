# Microsoft Developer Studio Generated NMAKE File, Based on collect.dsp
!IF "$(CFG)" == ""
CFG=Collect - Win32 Release
!MESSAGE No configuration specified. Defaulting to Collect - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Collect - Win32 Release" && "$(CFG)" != "Collect - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "collect.mak" CFG="Collect - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Collect - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Collect - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "Collect - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\collect.exe"


CLEAN :
	-@erase "$(INTDIR)\collect.obj"
	-@erase "$(INTDIR)\collect.pch"
	-@erase "$(INTDIR)\collect.res"
	-@erase "$(INTDIR)\colledoc.obj"
	-@erase "$(INTDIR)\collevw.obj"
	-@erase "$(INTDIR)\dwarryvw.obj"
	-@erase "$(INTDIR)\intlstvw.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\mapdwvw.obj"
	-@erase "$(INTDIR)\mapssvw.obj"
	-@erase "$(INTDIR)\ptarryvw.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\strlstvw.obj"
	-@erase "$(INTDIR)\typaryvw.obj"
	-@erase "$(INTDIR)\typlstvw.obj"
	-@erase "$(INTDIR)\typtrmap.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\collect.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\collect.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\collect.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\collect.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\collect.pdb" /machine:I386 /out:"$(OUTDIR)\collect.exe" 
LINK32_OBJS= \
	"$(INTDIR)\collect.obj" \
	"$(INTDIR)\colledoc.obj" \
	"$(INTDIR)\collevw.obj" \
	"$(INTDIR)\dwarryvw.obj" \
	"$(INTDIR)\intlstvw.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\mapdwvw.obj" \
	"$(INTDIR)\mapssvw.obj" \
	"$(INTDIR)\ptarryvw.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\strlstvw.obj" \
	"$(INTDIR)\typaryvw.obj" \
	"$(INTDIR)\typlstvw.obj" \
	"$(INTDIR)\typtrmap.obj" \
	"$(INTDIR)\collect.res"

"$(OUTDIR)\collect.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Collect - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\collect.exe"


CLEAN :
	-@erase "$(INTDIR)\collect.obj"
	-@erase "$(INTDIR)\collect.pch"
	-@erase "$(INTDIR)\collect.res"
	-@erase "$(INTDIR)\colledoc.obj"
	-@erase "$(INTDIR)\collevw.obj"
	-@erase "$(INTDIR)\dwarryvw.obj"
	-@erase "$(INTDIR)\intlstvw.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\mapdwvw.obj"
	-@erase "$(INTDIR)\mapssvw.obj"
	-@erase "$(INTDIR)\ptarryvw.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\strlstvw.obj"
	-@erase "$(INTDIR)\typaryvw.obj"
	-@erase "$(INTDIR)\typlstvw.obj"
	-@erase "$(INTDIR)\typtrmap.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\collect.exe"
	-@erase "$(OUTDIR)\collect.ilk"
	-@erase "$(OUTDIR)\collect.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\collect.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\collect.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\collect.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\collect.pdb" /debug /machine:I386 /out:"$(OUTDIR)\collect.exe" 
LINK32_OBJS= \
	"$(INTDIR)\collect.obj" \
	"$(INTDIR)\colledoc.obj" \
	"$(INTDIR)\collevw.obj" \
	"$(INTDIR)\dwarryvw.obj" \
	"$(INTDIR)\intlstvw.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\mapdwvw.obj" \
	"$(INTDIR)\mapssvw.obj" \
	"$(INTDIR)\ptarryvw.obj" \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\strlstvw.obj" \
	"$(INTDIR)\typaryvw.obj" \
	"$(INTDIR)\typlstvw.obj" \
	"$(INTDIR)\typtrmap.obj" \
	"$(INTDIR)\collect.res"

"$(OUTDIR)\collect.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("collect.dep")
!INCLUDE "collect.dep"
!ELSE 
!MESSAGE Warning: cannot find "collect.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Collect - Win32 Release" || "$(CFG)" == "Collect - Win32 Debug"
SOURCE=.\collect.cpp

"$(INTDIR)\collect.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\collect.pch"


SOURCE=.\collect.rc

"$(INTDIR)\collect.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\colledoc.cpp

"$(INTDIR)\colledoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\collect.pch"


SOURCE=.\collevw.cpp

"$(INTDIR)\collevw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\collect.pch"


SOURCE=.\dwarryvw.cpp

"$(INTDIR)\dwarryvw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\collect.pch"


SOURCE=.\intlstvw.cpp

"$(INTDIR)\intlstvw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\collect.pch"


SOURCE=.\mainfrm.cpp

"$(INTDIR)\mainfrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\collect.pch"


SOURCE=.\mapdwvw.cpp

"$(INTDIR)\mapdwvw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\collect.pch"


SOURCE=.\mapssvw.cpp

"$(INTDIR)\mapssvw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\collect.pch"


SOURCE=.\ptarryvw.cpp

"$(INTDIR)\ptarryvw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\collect.pch"


SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "Collect - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\collect.pch" /Yc"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\collect.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Collect - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\collect.pch" /Yc"Stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\collect.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\strlstvw.cpp

"$(INTDIR)\strlstvw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\collect.pch"


SOURCE=.\typaryvw.cpp

"$(INTDIR)\typaryvw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\collect.pch"


SOURCE=.\typlstvw.cpp

"$(INTDIR)\typlstvw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\collect.pch"


SOURCE=.\typtrmap.cpp

"$(INTDIR)\typtrmap.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\collect.pch"



!ENDIF 

