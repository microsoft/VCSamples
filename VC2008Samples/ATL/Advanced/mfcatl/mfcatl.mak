# Microsoft Developer Studio Generated NMAKE File, Based on mfcatl.dsp
!IF "$(CFG)" == ""
CFG=MfcAtl - Win32 Release
!MESSAGE No configuration specified. Defaulting to MfcAtl - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "MfcAtl - Win32 Release" && "$(CFG)" != "MfcAtl - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mfcatl.mak" CFG="MfcAtl - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MfcAtl - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "MfcAtl - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "MfcAtl - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\mfcatl.exe" "$(OUTDIR)\MfcAtl.tlb"


CLEAN :
	-@erase "$(INTDIR)\MfcAtl.obj"
	-@erase "$(INTDIR)\mfcatl.pch"
	-@erase "$(INTDIR)\MfcAtl.res"
	-@erase "$(INTDIR)\MfcAtl.tlb"
	-@erase "$(INTDIR)\MfcAtlDl.obj"
	-@erase "$(INTDIR)\ObjOne.obj"
	-@erase "$(INTDIR)\ObjTwo.obj"
	-@erase "$(INTDIR)\premfcat.obj"
	-@erase "$(OUTDIR)\mfcatl.exe"
	-@erase ".\interf.h"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfcatl.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\MfcAtl.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mfcatl.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\mfcatl.pdb" /machine:I386 /out:"$(OUTDIR)\mfcatl.exe" 
LINK32_OBJS= \
	"$(INTDIR)\MfcAtl.obj" \
	"$(INTDIR)\MfcAtlDl.obj" \
	"$(INTDIR)\ObjOne.obj" \
	"$(INTDIR)\ObjTwo.obj" \
	"$(INTDIR)\premfcat.obj" \
	"$(INTDIR)\MfcAtl.res"

"$(OUTDIR)\mfcatl.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MfcAtl - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\mfcatl.exe"


CLEAN :
	-@erase "$(INTDIR)\MfcAtl.obj"
	-@erase "$(INTDIR)\mfcatl.pch"
	-@erase "$(INTDIR)\MfcAtl.res"
	-@erase "$(INTDIR)\MfcAtl.tlb"
	-@erase "$(INTDIR)\MfcAtlDl.obj"
	-@erase "$(INTDIR)\ObjOne.obj"
	-@erase "$(INTDIR)\ObjTwo.obj"
	-@erase "$(INTDIR)\premfcat.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\mfcatl.exe"
	-@erase "$(OUTDIR)\mfcatl.ilk"
	-@erase "$(OUTDIR)\mfcatl.pdb"
	-@erase ".\interf.h"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfcatl.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\MfcAtl.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mfcatl.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\mfcatl.pdb" /debug /machine:I386 /out:"$(OUTDIR)\mfcatl.exe" 
LINK32_OBJS= \
	"$(INTDIR)\MfcAtl.obj" \
	"$(INTDIR)\MfcAtlDl.obj" \
	"$(INTDIR)\ObjOne.obj" \
	"$(INTDIR)\ObjTwo.obj" \
	"$(INTDIR)\premfcat.obj" \
	"$(INTDIR)\MfcAtl.res"

"$(OUTDIR)\mfcatl.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("mfcatl.dep")
!INCLUDE "mfcatl.dep"
!ELSE 
!MESSAGE Warning: cannot find "mfcatl.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "MfcAtl - Win32 Release" || "$(CFG)" == "MfcAtl - Win32 Debug"
SOURCE=.\MfcAtl.cpp

!IF  "$(CFG)" == "MfcAtl - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfcatl.pch" /Yu"premfcat.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\MfcAtl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mfcatl.pch" ".\interf.h"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MfcAtl - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfcatl.pch" /Yu"premfcat.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\MfcAtl.obj" : $(SOURCE) "$(INTDIR)" ".\interf.h" "$(INTDIR)\mfcatl.pch"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\MfcAtl.odl

!IF  "$(CFG)" == "MfcAtl - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\MfcAtl.tlb" /h "interf.h" /mktyplib203 /win32 

"$(OUTDIR)\MfcAtl.tlb"	".\interf.h" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MfcAtl - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\MfcAtl.tlb" /h "interf.h" /mktyplib203 /win32 

"$(OUTDIR)\MfcAtl.tlb"	".\interf.h" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\MfcAtl.rc

!IF  "$(CFG)" == "MfcAtl - Win32 Release"


"$(INTDIR)\MfcAtl.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\MfcAtl.res" /i ".\Release" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "MfcAtl - Win32 Debug"


"$(INTDIR)\MfcAtl.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MfcAtl.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\MfcAtl.res" /i ".\Debug" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ENDIF 

SOURCE=.\MfcAtlDl.cpp

!IF  "$(CFG)" == "MfcAtl - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfcatl.pch" /Yu"premfcat.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\MfcAtlDl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mfcatl.pch"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MfcAtl - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfcatl.pch" /Yu"premfcat.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\MfcAtlDl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mfcatl.pch"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\ObjOne.cpp

!IF  "$(CFG)" == "MfcAtl - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfcatl.pch" /Yu"premfcat.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\ObjOne.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mfcatl.pch"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MfcAtl - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfcatl.pch" /Yu"premfcat.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\ObjOne.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mfcatl.pch"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\ObjTwo.cpp

!IF  "$(CFG)" == "MfcAtl - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfcatl.pch" /Yu"premfcat.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\ObjTwo.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\mfcatl.pch" ".\interf.h"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MfcAtl - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfcatl.pch" /Yu"premfcat.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\ObjTwo.obj" : $(SOURCE) "$(INTDIR)" ".\interf.h" "$(INTDIR)\mfcatl.pch"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\premfcat.cpp

!IF  "$(CFG)" == "MfcAtl - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfcatl.pch" /Yc"premfcat.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\premfcat.obj"	"$(INTDIR)\mfcatl.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MfcAtl - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfcatl.pch" /Yc"premfcat.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\premfcat.obj"	"$(INTDIR)\mfcatl.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

