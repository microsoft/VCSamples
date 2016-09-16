# Microsoft Developer Studio Generated NMAKE File, Based on TestDll1.dsp
!IF "$(CFG)" == ""
CFG=TestDll1 - Win32 Release
!MESSAGE No configuration specified. Defaulting to TestDll1 - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "TestDll1 - Win32 Release" && "$(CFG)" != "TestDll1 - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TestDll1.mak" CFG="TestDll1 - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TestDll1 - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "TestDll1 - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "TestDll1 - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\TestDll1.dll"


CLEAN :
	-@erase "$(INTDIR)\testdll1.obj"
	-@erase "$(INTDIR)\testdll1.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\TestDll1.dll"
	-@erase "$(OUTDIR)\TestDll1.exp"
	-@erase "$(OUTDIR)\TestDll1.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXEXT" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\testdll1.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\TestDll1.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\TestDll1.pdb" /machine:I386 /out:"$(OUTDIR)\TestDll1.dll" /implib:"$(OUTDIR)\TestDll1.lib" 
LINK32_OBJS= \
	"$(INTDIR)\testdll1.obj" \
	"$(INTDIR)\testdll1.res"

"$(OUTDIR)\TestDll1.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "TestDll1 - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\TestDll1.dll"


CLEAN :
	-@erase "$(INTDIR)\testdll1.obj"
	-@erase "$(INTDIR)\testdll1.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\TestDll1.dll"
	-@erase "$(OUTDIR)\TestDll1.exp"
	-@erase "$(OUTDIR)\TestDll1.ilk"
	-@erase "$(OUTDIR)\TestDll1.lib"
	-@erase "$(OUTDIR)\TestDll1.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXEXT" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\testdll1.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\TestDll1.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\TestDll1.pdb" /debug /machine:I386 /out:"$(OUTDIR)\TestDll1.dll" /implib:"$(OUTDIR)\TestDll1.lib" 
LINK32_OBJS= \
	"$(INTDIR)\testdll1.obj" \
	"$(INTDIR)\testdll1.res"

"$(OUTDIR)\TestDll1.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("TestDll1.dep")
!INCLUDE "TestDll1.dep"
!ELSE 
!MESSAGE Warning: cannot find "TestDll1.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "TestDll1 - Win32 Release" || "$(CFG)" == "TestDll1 - Win32 Debug"
SOURCE=.\testdll1.cpp

!IF  "$(CFG)" == "TestDll1 - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXEXT" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\testdll1.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "TestDll1 - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXEXT" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\testdll1.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\testdll1.rc

"$(INTDIR)\testdll1.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)



!ENDIF 

