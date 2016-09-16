# Microsoft Developer Studio Generated NMAKE File, Based on TestDll2.dsp
!IF "$(CFG)" == ""
CFG=TestDll2 - Win32 Release
!MESSAGE No configuration specified. Defaulting to TestDll2 - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "TestDll2 - Win32 Release" && "$(CFG)" != "TestDll2 - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TestDll2.mak" CFG="TestDll2 - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TestDll2 - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "TestDll2 - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "TestDll2 - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\TestDll2.dll"


CLEAN :
	-@erase "$(INTDIR)\testdll2.obj"
	-@erase "$(INTDIR)\testdll2.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\TestDll2.dll"
	-@erase "$(OUTDIR)\TestDll2.exp"
	-@erase "$(OUTDIR)\TestDll2.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXEXT" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\testdll2.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\TestDll2.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\TestDll2.pdb" /machine:I386 /out:"$(OUTDIR)\TestDll2.dll" /implib:"$(OUTDIR)\TestDll2.lib" 
LINK32_OBJS= \
	"$(INTDIR)\testdll2.obj" \
	"$(INTDIR)\testdll2.res"

"$(OUTDIR)\TestDll2.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "TestDll2 - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\TestDll2.dll"


CLEAN :
	-@erase "$(INTDIR)\testdll2.obj"
	-@erase "$(INTDIR)\testdll2.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\TestDll2.dll"
	-@erase "$(OUTDIR)\TestDll2.exp"
	-@erase "$(OUTDIR)\TestDll2.ilk"
	-@erase "$(OUTDIR)\TestDll2.lib"
	-@erase "$(OUTDIR)\TestDll2.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXEXT" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\testdll2.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\TestDll2.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\TestDll2.pdb" /debug /machine:I386 /out:"$(OUTDIR)\TestDll2.dll" /implib:"$(OUTDIR)\TestDll2.lib" 
LINK32_OBJS= \
	"$(INTDIR)\testdll2.obj" \
	"$(INTDIR)\testdll2.res"

"$(OUTDIR)\TestDll2.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("TestDll2.dep")
!INCLUDE "TestDll2.dep"
!ELSE 
!MESSAGE Warning: cannot find "TestDll2.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "TestDll2 - Win32 Release" || "$(CFG)" == "TestDll2 - Win32 Debug"
SOURCE=.\testdll2.cpp

"$(INTDIR)\testdll2.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\testdll2.rc

"$(INTDIR)\testdll2.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)



!ENDIF 

