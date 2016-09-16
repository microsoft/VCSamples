# Microsoft Developer Studio Generated NMAKE File, Based on dllhusk.dsp
!IF "$(CFG)" == ""
CFG=DLLHusk - Win32 Release
!MESSAGE No configuration specified. Defaulting to DLLHusk - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "DLLHusk - Win32 Release" && "$(CFG)" != "DLLHusk - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "dllhusk.mak" CFG="DLLHusk - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DLLHusk - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "DLLHusk - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "DLLHusk - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\dllhusk.exe"

!ELSE 

ALL : "TestDll2 - Win32 Release" "TestDll1 - Win32 Release" "$(OUTDIR)\dllhusk.exe"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"TestDll1 - Win32 ReleaseCLEAN" "TestDll2 - Win32 ReleaseCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\dllhusk.obj"
	-@erase "$(INTDIR)\dllhusk.res"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\dllhusk.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\dllhusk.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\dllhusk.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=Release\TestDll1.lib Release\TestDll2.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\dllhusk.pdb" /machine:I386 /out:"$(OUTDIR)\dllhusk.exe" 
LINK32_OBJS= \
	"$(INTDIR)\dllhusk.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\dllhusk.res" \
	"$(OUTDIR)\TestDll1.lib" \
	"$(OUTDIR)\TestDll2.lib"

"$(OUTDIR)\dllhusk.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "DLLHusk - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\dllhusk.exe"

!ELSE 

ALL : "TestDll2 - Win32 Debug" "TestDll1 - Win32 Debug" "$(OUTDIR)\dllhusk.exe"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"TestDll1 - Win32 DebugCLEAN" "TestDll2 - Win32 DebugCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\dllhusk.obj"
	-@erase "$(INTDIR)\dllhusk.res"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\dllhusk.exe"
	-@erase "$(OUTDIR)\dllhusk.ilk"
	-@erase "$(OUTDIR)\dllhusk.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\dllhusk.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\dllhusk.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=Debug\TestDll1.lib Debug\TestDll2.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\dllhusk.pdb" /debug /machine:I386 /out:"$(OUTDIR)\dllhusk.exe" 
LINK32_OBJS= \
	"$(INTDIR)\dllhusk.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\dllhusk.res" \
	"$(OUTDIR)\TestDll1.lib" \
	"$(OUTDIR)\TestDll2.lib"

"$(OUTDIR)\dllhusk.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("dllhusk.dep")
!INCLUDE "dllhusk.dep"
!ELSE 
!MESSAGE Warning: cannot find "dllhusk.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "DLLHusk - Win32 Release" || "$(CFG)" == "DLLHusk - Win32 Debug"
SOURCE=.\dllhusk.cpp

!IF  "$(CFG)" == "DLLHusk - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\dllhusk.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DLLHusk - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\dllhusk.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\dllhusk.rc

"$(INTDIR)\dllhusk.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\mainfrm.cpp

!IF  "$(CFG)" == "DLLHusk - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\mainfrm.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DLLHusk - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\mainfrm.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

!IF  "$(CFG)" == "DLLHusk - Win32 Release"

"TestDll1 - Win32 Release" : 
   cd "."
   $(MAKE) /$(MAKEFLAGS) /F .\TestDll1.mak CFG="TestDll1 - Win32 Release" 
   cd "."

"TestDll1 - Win32 ReleaseCLEAN" : 
   cd "."
   $(MAKE) /$(MAKEFLAGS) /F .\TestDll1.mak CFG="TestDll1 - Win32 Release" RECURSE=1 CLEAN 
   cd "."

!ELSEIF  "$(CFG)" == "DLLHusk - Win32 Debug"

"TestDll1 - Win32 Debug" : 
   cd "."
   $(MAKE) /$(MAKEFLAGS) /F .\TestDll1.mak CFG="TestDll1 - Win32 Debug" 
   cd "."

"TestDll1 - Win32 DebugCLEAN" : 
   cd "."
   $(MAKE) /$(MAKEFLAGS) /F .\TestDll1.mak CFG="TestDll1 - Win32 Debug" RECURSE=1 CLEAN 
   cd "."

!ENDIF 

!IF  "$(CFG)" == "DLLHusk - Win32 Release"

"TestDll2 - Win32 Release" : 
   cd "."
   $(MAKE) /$(MAKEFLAGS) /F .\TestDll2.mak CFG="TestDll2 - Win32 Release" 
   cd "."

"TestDll2 - Win32 ReleaseCLEAN" : 
   cd "."
   $(MAKE) /$(MAKEFLAGS) /F .\TestDll2.mak CFG="TestDll2 - Win32 Release" RECURSE=1 CLEAN 
   cd "."

!ELSEIF  "$(CFG)" == "DLLHusk - Win32 Debug"

"TestDll2 - Win32 Debug" : 
   cd "."
   $(MAKE) /$(MAKEFLAGS) /F .\TestDll2.mak CFG="TestDll2 - Win32 Debug" 
   cd "."

"TestDll2 - Win32 DebugCLEAN" : 
   cd "."
   $(MAKE) /$(MAKEFLAGS) /F .\TestDll2.mak CFG="TestDll2 - Win32 Debug" RECURSE=1 CLEAN 
   cd "."

!ENDIF 


!ENDIF 

