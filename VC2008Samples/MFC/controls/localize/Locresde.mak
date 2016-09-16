# Microsoft Developer Studio Generated NMAKE File, Based on Locresde.dsp
!IF "$(CFG)" == ""
CFG=Locresde - Win32 Release
!MESSAGE No configuration specified. Defaulting to Locresde - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Locresde - Win32 Release" && "$(CFG)" != "Locresde - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Locresde.mak" CFG="Locresde - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Locresde - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Locresde - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "Locresde - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\Locresde.dll"


CLEAN :
	-@erase "$(INTDIR)\locresde.obj"
	-@erase "$(INTDIR)\locresde.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\Locresde.dll"
	-@erase "$(OUTDIR)\Locresde.exp"
	-@erase "$(OUTDIR)\Locresde.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Locresde.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\locresde.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Locresde.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\Locresde.pdb" /machine:I386 /out:"$(OUTDIR)\Locresde.dll" /implib:"$(OUTDIR)\Locresde.lib" 
LINK32_OBJS= \
	"$(INTDIR)\locresde.obj" \
	"$(INTDIR)\locresde.res"

"$(OUTDIR)\Locresde.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Locresde - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Locresde.dll"


CLEAN :
	-@erase "$(INTDIR)\locresde.obj"
	-@erase "$(INTDIR)\locresde.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Locresde.dll"
	-@erase "$(OUTDIR)\Locresde.exp"
	-@erase "$(OUTDIR)\Locresde.ilk"
	-@erase "$(OUTDIR)\Locresde.lib"
	-@erase "$(OUTDIR)\Locresde.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Locresde.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\locresde.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Locresde.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\Locresde.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Locresde.dll" /implib:"$(OUTDIR)\Locresde.lib" 
LINK32_OBJS= \
	"$(INTDIR)\locresde.obj" \
	"$(INTDIR)\locresde.res"

"$(OUTDIR)\Locresde.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("Locresde.dep")
!INCLUDE "Locresde.dep"
!ELSE 
!MESSAGE Warning: cannot find "Locresde.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Locresde - Win32 Release" || "$(CFG)" == "Locresde - Win32 Debug"
SOURCE=.\locresde.cpp

"$(INTDIR)\locresde.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\locresde.rc

"$(INTDIR)\locresde.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)



!ENDIF 

