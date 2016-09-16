# Microsoft Developer Studio Generated NMAKE File, Based on collect.dsp
!IF "$(CFG)" == ""
CFG=Collect - Win32 Release
!MESSAGE No configuration specified. Defaulting to Collect - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Collect - Win32 Release" && "$(CFG)" !=\
 "Collect - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "collect.mak" CFG="Collect - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Collect - Win32 Release" (based on "Win32 (x86) Win32 Application")
!MESSAGE "Collect - Win32 Debug" (based on "Win32 (x86) Win32 Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "Collect - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\collect.exe"

!ELSE 

ALL : "$(OUTDIR)\collect.exe"

!ENDIF 

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
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\collect.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\collect.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\collect.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\collect.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\collect.pdb" /machine:I386 /out:"$(OUTDIR)\collect.exe" 
LINK32_OBJS= \
	"$(INTDIR)\collect.obj" \
	"$(INTDIR)\collect.res" \
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
	"$(INTDIR)\typtrmap.obj"

"$(OUTDIR)\collect.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Collect - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\collect.exe"

!ELSE 

ALL : "$(OUTDIR)\collect.exe"

!ENDIF 

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
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\collect.exe"
	-@erase "$(OUTDIR)\collect.ilk"
	-@erase "$(OUTDIR)\collect.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)\collect.pch" /Yu"Stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\collect.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\collect.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\collect.pdb" /debug /machine:I386 /out:"$(OUTDIR)\collect.exe" 
LINK32_OBJS= \
	"$(INTDIR)\collect.obj" \
	"$(INTDIR)\collect.res" \
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
	"$(INTDIR)\typtrmap.obj"

"$(OUTDIR)\collect.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(CFG)" == "Collect - Win32 Release" || "$(CFG)" ==\
 "Collect - Win32 Debug"
SOURCE=.\collect.cpp

!IF  "$(CFG)" == "Collect - Win32 Release"

DEP_CPP_COLLE=\
	".\collect.h"\
	".\colledoc.h"\
	".\mainfrm.h"\
	".\strlstvw.h"\
	

"$(INTDIR)\collect.obj" : $(SOURCE) $(DEP_CPP_COLLE) "$(INTDIR)"\
 "$(INTDIR)\collect.pch"


!ELSEIF  "$(CFG)" == "Collect - Win32 Debug"

DEP_CPP_COLLE=\
	".\collect.h"\
	".\colledoc.h"\
	".\mainfrm.h"\
	".\strlstvw.h"\
	

"$(INTDIR)\collect.obj" : $(SOURCE) $(DEP_CPP_COLLE) "$(INTDIR)"\
 "$(INTDIR)\collect.pch"


!ENDIF 

SOURCE=.\collect.rc
DEP_RSC_COLLEC=\
	".\res\collect.ico"\
	".\res\collect.rc2"\
	".\res\toolbar.bmp"\
	

"$(INTDIR)\collect.res" : $(SOURCE) $(DEP_RSC_COLLEC) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\colledoc.cpp

!IF  "$(CFG)" == "Collect - Win32 Release"

DEP_CPP_COLLED=\
	".\collect.h"\
	".\colledoc.h"\
	

"$(INTDIR)\colledoc.obj" : $(SOURCE) $(DEP_CPP_COLLED) "$(INTDIR)"\
 "$(INTDIR)\collect.pch"


!ELSEIF  "$(CFG)" == "Collect - Win32 Debug"

DEP_CPP_COLLED=\
	".\collect.h"\
	".\colledoc.h"\
	

"$(INTDIR)\colledoc.obj" : $(SOURCE) $(DEP_CPP_COLLED) "$(INTDIR)"\
 "$(INTDIR)\collect.pch"


!ENDIF 

SOURCE=.\collevw.cpp

!IF  "$(CFG)" == "Collect - Win32 Release"

DEP_CPP_COLLEV=\
	".\collect.h"\
	".\colledoc.h"\
	".\collevw.h"\
	

"$(INTDIR)\collevw.obj" : $(SOURCE) $(DEP_CPP_COLLEV) "$(INTDIR)"\
 "$(INTDIR)\collect.pch"


!ELSEIF  "$(CFG)" == "Collect - Win32 Debug"

DEP_CPP_COLLEV=\
	".\collect.h"\
	".\colledoc.h"\
	".\collevw.h"\
	

"$(INTDIR)\collevw.obj" : $(SOURCE) $(DEP_CPP_COLLEV) "$(INTDIR)"\
 "$(INTDIR)\collect.pch"


!ENDIF 

SOURCE=.\dwarryvw.cpp

!IF  "$(CFG)" == "Collect - Win32 Release"

DEP_CPP_DWARR=\
	".\collect.h"\
	".\colledoc.h"\
	".\dwarryvw.h"\
	

"$(INTDIR)\dwarryvw.obj" : $(SOURCE) $(DEP_CPP_DWARR) "$(INTDIR)"\
 "$(INTDIR)\collect.pch"


!ELSEIF  "$(CFG)" == "Collect - Win32 Debug"

DEP_CPP_DWARR=\
	".\collect.h"\
	".\colledoc.h"\
	".\dwarryvw.h"\
	

"$(INTDIR)\dwarryvw.obj" : $(SOURCE) $(DEP_CPP_DWARR) "$(INTDIR)"\
 "$(INTDIR)\collect.pch"


!ENDIF 

SOURCE=.\intlstvw.cpp

!IF  "$(CFG)" == "Collect - Win32 Release"

DEP_CPP_INTLS=\
	".\collect.h"\
	".\colledoc.h"\
	".\intlstvw.h"\
	

"$(INTDIR)\intlstvw.obj" : $(SOURCE) $(DEP_CPP_INTLS) "$(INTDIR)"\
 "$(INTDIR)\collect.pch"


!ELSEIF  "$(CFG)" == "Collect - Win32 Debug"

DEP_CPP_INTLS=\
	".\collect.h"\
	".\colledoc.h"\
	".\intlstvw.h"\
	

"$(INTDIR)\intlstvw.obj" : $(SOURCE) $(DEP_CPP_INTLS) "$(INTDIR)"\
 "$(INTDIR)\collect.pch"


!ENDIF 

SOURCE=.\mainfrm.cpp

!IF  "$(CFG)" == "Collect - Win32 Release"

DEP_CPP_MAINF=\
	".\collect.h"\
	".\colledoc.h"\
	".\dwarryvw.h"\
	".\intlstvw.h"\
	".\mainfrm.h"\
	".\mapdwvw.h"\
	".\mapssvw.h"\
	".\ptarryvw.h"\
	".\strlstvw.h"\
	".\typaryvw.h"\
	".\typlstvw.h"\
	".\typtrmap.h"\
	

"$(INTDIR)\mainfrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\collect.pch"


!ELSEIF  "$(CFG)" == "Collect - Win32 Debug"

DEP_CPP_MAINF=\
	".\collect.h"\
	".\colledoc.h"\
	".\dwarryvw.h"\
	".\intlstvw.h"\
	".\mainfrm.h"\
	".\mapdwvw.h"\
	".\mapssvw.h"\
	".\ptarryvw.h"\
	".\strlstvw.h"\
	".\typaryvw.h"\
	".\typlstvw.h"\
	".\typtrmap.h"\
	

"$(INTDIR)\mainfrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\collect.pch"


!ENDIF 

SOURCE=.\mapdwvw.cpp

!IF  "$(CFG)" == "Collect - Win32 Release"

DEP_CPP_MAPDW=\
	".\collect.h"\
	".\colledoc.h"\
	".\mapdwvw.h"\
	

"$(INTDIR)\mapdwvw.obj" : $(SOURCE) $(DEP_CPP_MAPDW) "$(INTDIR)"\
 "$(INTDIR)\collect.pch"


!ELSEIF  "$(CFG)" == "Collect - Win32 Debug"

DEP_CPP_MAPDW=\
	".\collect.h"\
	".\colledoc.h"\
	".\mapdwvw.h"\
	

"$(INTDIR)\mapdwvw.obj" : $(SOURCE) $(DEP_CPP_MAPDW) "$(INTDIR)"\
 "$(INTDIR)\collect.pch"


!ENDIF 

SOURCE=.\mapssvw.cpp

!IF  "$(CFG)" == "Collect - Win32 Release"

DEP_CPP_MAPSS=\
	".\collect.h"\
	".\colledoc.h"\
	".\mapssvw.h"\
	

"$(INTDIR)\mapssvw.obj" : $(SOURCE) $(DEP_CPP_MAPSS) "$(INTDIR)"\
 "$(INTDIR)\collect.pch"


!ELSEIF  "$(CFG)" == "Collect - Win32 Debug"

DEP_CPP_MAPSS=\
	".\collect.h"\
	".\colledoc.h"\
	".\mapssvw.h"\
	

"$(INTDIR)\mapssvw.obj" : $(SOURCE) $(DEP_CPP_MAPSS) "$(INTDIR)"\
 "$(INTDIR)\collect.pch"


!ENDIF 

SOURCE=.\ptarryvw.cpp

!IF  "$(CFG)" == "Collect - Win32 Release"

DEP_CPP_PTARR=\
	".\collect.h"\
	".\colledoc.h"\
	".\ptarryvw.h"\
	

"$(INTDIR)\ptarryvw.obj" : $(SOURCE) $(DEP_CPP_PTARR) "$(INTDIR)"\
 "$(INTDIR)\collect.pch"


!ELSEIF  "$(CFG)" == "Collect - Win32 Debug"

DEP_CPP_PTARR=\
	".\collect.h"\
	".\colledoc.h"\
	".\ptarryvw.h"\
	

"$(INTDIR)\ptarryvw.obj" : $(SOURCE) $(DEP_CPP_PTARR) "$(INTDIR)"\
 "$(INTDIR)\collect.pch"


!ENDIF 

SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "Collect - Win32 Release"

DEP_CPP_STDAF=\
	"..\server\cdata.h"\
	"..\server\idata.h"\
	"..\server\stlcoll.tlb"\
	".\stdafx.h"\
	
CPP_SWITCHES=/nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\collect.pch" /Yc"Stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\collect.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Collect - Win32 Debug"

DEP_CPP_STDAF=\
	"..\server\cdata.h"\
	"..\server\idata.h"\
	"..\server\stlcoll.tlb"\
	".\stdafx.h"\
	
CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)\collect.pch" /Yc"Stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\collect.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\strlstvw.cpp

!IF  "$(CFG)" == "Collect - Win32 Release"

DEP_CPP_STRLS=\
	".\collect.h"\
	".\colledoc.h"\
	".\strlstvw.h"\
	

"$(INTDIR)\strlstvw.obj" : $(SOURCE) $(DEP_CPP_STRLS) "$(INTDIR)"\
 "$(INTDIR)\collect.pch"


!ELSEIF  "$(CFG)" == "Collect - Win32 Debug"

DEP_CPP_STRLS=\
	".\collect.h"\
	".\colledoc.h"\
	".\strlstvw.h"\
	

"$(INTDIR)\strlstvw.obj" : $(SOURCE) $(DEP_CPP_STRLS) "$(INTDIR)"\
 "$(INTDIR)\collect.pch"


!ENDIF 

SOURCE=.\typaryvw.cpp

!IF  "$(CFG)" == "Collect - Win32 Release"

DEP_CPP_TYPAR=\
	".\collect.h"\
	".\colledoc.h"\
	".\typaryvw.h"\
	

"$(INTDIR)\typaryvw.obj" : $(SOURCE) $(DEP_CPP_TYPAR) "$(INTDIR)"\
 "$(INTDIR)\collect.pch"


!ELSEIF  "$(CFG)" == "Collect - Win32 Debug"

DEP_CPP_TYPAR=\
	".\collect.h"\
	".\colledoc.h"\
	".\typaryvw.h"\
	

"$(INTDIR)\typaryvw.obj" : $(SOURCE) $(DEP_CPP_TYPAR) "$(INTDIR)"\
 "$(INTDIR)\collect.pch"


!ENDIF 

SOURCE=.\typlstvw.cpp

!IF  "$(CFG)" == "Collect - Win32 Release"

DEP_CPP_TYPLS=\
	".\collect.h"\
	".\colledoc.h"\
	".\typlstvw.h"\
	

"$(INTDIR)\typlstvw.obj" : $(SOURCE) $(DEP_CPP_TYPLS) "$(INTDIR)"\
 "$(INTDIR)\collect.pch"


!ELSEIF  "$(CFG)" == "Collect - Win32 Debug"

DEP_CPP_TYPLS=\
	".\collect.h"\
	".\colledoc.h"\
	".\typlstvw.h"\
	

"$(INTDIR)\typlstvw.obj" : $(SOURCE) $(DEP_CPP_TYPLS) "$(INTDIR)"\
 "$(INTDIR)\collect.pch"


!ENDIF 

SOURCE=.\typtrmap.cpp

!IF  "$(CFG)" == "Collect - Win32 Release"

DEP_CPP_TYPTR=\
	".\collect.h"\
	".\colledoc.h"\
	".\typtrmap.h"\
	

"$(INTDIR)\typtrmap.obj" : $(SOURCE) $(DEP_CPP_TYPTR) "$(INTDIR)"\
 "$(INTDIR)\collect.pch"


!ELSEIF  "$(CFG)" == "Collect - Win32 Debug"

DEP_CPP_TYPTR=\
	".\collect.h"\
	".\colledoc.h"\
	".\typtrmap.h"\
	

"$(INTDIR)\typtrmap.obj" : $(SOURCE) $(DEP_CPP_TYPTR) "$(INTDIR)"\
 "$(INTDIR)\collect.pch"


!ENDIF 

SOURCE=.\server\cdata.h
SOURCE=.\collect.h
SOURCE=.\colledoc.h
SOURCE=.\collevw.h
SOURCE=.\dwarryvw.h
SOURCE=.\server\idata.h
SOURCE=.\intlstvw.h
SOURCE=.\mainfrm.h
SOURCE=.\mapdwvw.h
SOURCE=.\mapssvw.h
SOURCE=.\ptarryvw.h
SOURCE=.\stdafx.h
SOURCE=.\server\stlcoll.tlb
SOURCE=.\strlstvw.h
SOURCE=.\typaryvw.h
SOURCE=.\typlstvw.h
SOURCE=.\typtrmap.h
SOURCE=.\res\collect.ico
SOURCE=.\res\collect.rc2
SOURCE=.\res\toolbar.bmp

!ENDIF 

