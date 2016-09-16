# Microsoft Developer Studio Generated NMAKE File, Based on MFCCont.dsp
!IF "$(CFG)" == ""
CFG=MFCCont - Win32 Debug
!MESSAGE No configuration specified. Defaulting to MFCCont - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "MFCCont - Win32 Release" && "$(CFG)" !=\
 "MFCCont - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MFCCont.mak" CFG="MFCCont - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MFCCont - Win32 Release" (based on "Win32 (x86) Win32 Application")
!MESSAGE "MFCCont - Win32 Debug" (based on "Win32 (x86) Win32 Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "MFCCont - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\MFCCont.exe"

!ELSE 

ALL : "$(OUTDIR)\MFCCont.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\drawctl.obj"
	-@erase "$(INTDIR)\MFCCont.obj"
	-@erase "$(INTDIR)\MFCCont.pch"
	-@erase "$(INTDIR)\MFCCont.res"
	-@erase "$(INTDIR)\MFCContDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\MFCCont.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /Fp"$(INTDIR)\MFCCont.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
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
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\MFCCont.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\MFCCont.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\MFCCont.pdb" /machine:I386 /out:"$(OUTDIR)\MFCCont.exe" 
LINK32_OBJS= \
	"$(INTDIR)\drawctl.obj" \
	"$(INTDIR)\MFCCont.obj" \
	"$(INTDIR)\MFCCont.res" \
	"$(INTDIR)\MFCContDlg.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\MFCCont.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MFCCont - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\MFCCont.exe"

!ELSE 

ALL : "$(OUTDIR)\MFCCont.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\drawctl.obj"
	-@erase "$(INTDIR)\MFCCont.obj"
	-@erase "$(INTDIR)\MFCCont.pch"
	-@erase "$(INTDIR)\MFCCont.res"
	-@erase "$(INTDIR)\MFCContDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\MFCCont.exe"
	-@erase "$(OUTDIR)\MFCCont.ilk"
	-@erase "$(OUTDIR)\MFCCont.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /Fp"$(INTDIR)\MFCCont.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
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
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o NUL /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\MFCCont.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\MFCCont.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\MFCCont.pdb" /debug /machine:I386 /out:"$(OUTDIR)\MFCCont.exe"\
 /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\drawctl.obj" \
	"$(INTDIR)\MFCCont.obj" \
	"$(INTDIR)\MFCCont.res" \
	"$(INTDIR)\MFCContDlg.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\MFCCont.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(CFG)" == "MFCCont - Win32 Release" || "$(CFG)" ==\
 "MFCCont - Win32 Debug"
SOURCE=.\drawctl.cpp
DEP_CPP_DRAWC=\
	".\drawctl.h"\
	

"$(INTDIR)\drawctl.obj" : $(SOURCE) $(DEP_CPP_DRAWC) "$(INTDIR)"\
 "$(INTDIR)\MFCCont.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\MFCCont.cpp
DEP_CPP_MFCCO=\
	".\drawctl.h"\
	".\MFCCont.h"\
	".\MFCContDlg.h"\
	

"$(INTDIR)\MFCCont.obj" : $(SOURCE) $(DEP_CPP_MFCCO) "$(INTDIR)"\
 "$(INTDIR)\MFCCont.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\MFCCont.rc
DEP_RSC_MFCCON=\
	".\res\MFCCont.ico"\
	".\res\MFCCont.rc2"\
	

"$(INTDIR)\MFCCont.res" : $(SOURCE) $(DEP_RSC_MFCCON) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\MFCContDlg.cpp
DEP_CPP_MFCCONT=\
	".\drawctl.h"\
	".\MFCCont.h"\
	".\MFCContDlg.h"\
	

"$(INTDIR)\MFCContDlg.obj" : $(SOURCE) $(DEP_CPP_MFCCONT) "$(INTDIR)"\
 "$(INTDIR)\MFCCont.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "MFCCont - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /Fp"$(INTDIR)\MFCCont.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\MFCCont.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MFCCont - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\MFCCont.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\MFCCont.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\drawctl.h
SOURCE=.\MFCCont.h
SOURCE=.\MFCContDlg.h
SOURCE=.\Resource.h
SOURCE=.\StdAfx.h
SOURCE=.\res\MFCCont.ico
SOURCE=.\res\MFCCont.rc2
SOURCE=.\ReadMe.txt

!ENDIF 

