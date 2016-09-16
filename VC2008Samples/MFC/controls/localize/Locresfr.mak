# Microsoft Developer Studio Generated NMAKE File, Based on Locresfr.dsp
!IF "$(CFG)" == ""
CFG=Locresfr - Win32 Release
!MESSAGE No configuration specified. Defaulting to Locresfr - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Locresfr - Win32 Release" && "$(CFG)" != "Locresfr - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Locresfr.mak" CFG="Locresfr - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Locresfr - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Locresfr - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "Locresfr - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\Locresfr.dll"


CLEAN :
	-@erase "$(INTDIR)\locresfr.obj"
	-@erase "$(INTDIR)\locresfr.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\Locresfr.dll"
	-@erase "$(OUTDIR)\Locresfr.exp"
	-@erase "$(OUTDIR)\Locresfr.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Locresfr.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\locresfr.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Locresfr.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\Locresfr.pdb" /machine:I386 /out:"$(OUTDIR)\Locresfr.dll" /implib:"$(OUTDIR)\Locresfr.lib" 
LINK32_OBJS= \
	"$(INTDIR)\locresfr.obj" \
	"$(INTDIR)\locresfr.res"

"$(OUTDIR)\Locresfr.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Locresfr - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Locresfr.dll"


CLEAN :
	-@erase "$(INTDIR)\locresfr.obj"
	-@erase "$(INTDIR)\locresfr.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Locresfr.dll"
	-@erase "$(OUTDIR)\Locresfr.exp"
	-@erase "$(OUTDIR)\Locresfr.ilk"
	-@erase "$(OUTDIR)\Locresfr.lib"
	-@erase "$(OUTDIR)\Locresfr.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Locresfr.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\locresfr.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Locresfr.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\Locresfr.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Locresfr.dll" /implib:"$(OUTDIR)\Locresfr.lib" 
LINK32_OBJS= \
	"$(INTDIR)\locresfr.obj" \
	"$(INTDIR)\locresfr.res"

"$(OUTDIR)\Locresfr.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("Locresfr.dep")
!INCLUDE "Locresfr.dep"
!ELSE 
!MESSAGE Warning: cannot find "Locresfr.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Locresfr - Win32 Release" || "$(CFG)" == "Locresfr - Win32 Debug"
SOURCE=.\locresfr.cpp

"$(INTDIR)\locresfr.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\locresfr.rc

"$(INTDIR)\locresfr.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)



!ENDIF 

