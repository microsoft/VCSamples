!MESSAGE --- GameHistory Native COM Server ---
!MESSAGE

!IF "$(CFG)" == ""
CFG=Debug
!MESSAGE No configuration specified. Defaulting to Debug.
!ENDIF

!IF "$(CFG)" != "Debug" && "$(CFG)" != "Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF

!IF "$(TARGET_NATIVE_ARCHITECTURE)" == "x86"
ARCH=IX86
!ELSE
!IF "$(TARGET_NATIVE_ARCHITECTURE)" == "ia64"
ARCH=IA64
!ELSE
!IF "$(TARGET_NATIVE_ARCHITECTURE)" == "amd64"
ARCH=AMD64
!ELSE
!ERROR Unknown target architecture!
!ENDIF
!ENDIF
!ENDIF


# --- Debug configuration ---

!IF  "$(CFG)" == "Debug"

!MESSAGE Building "$(CFG)" Configuration

BINDIR=..\bin
OUTDIR=..\bin\Debug
TARGETDIR=.\Debug

ALL : "$(TARGETDIR)\GameHistory.dll" "$(OUTDIR)\GameHistory.dll"

CLEAN :
	if exist "$(TARGETDIR)\GameHistory.dll" $(ADMIN_PIPE) regsvr32 /u /s "$(TARGETDIR)\GameHistory.dll"
	-@erase "$(OUTDIR)\GameHistory.dll"
	-@erase "$(TARGETDIR)\GameHistory.dll"
	-@erase "$(TARGETDIR)\GameHistory.exp"
	-@erase "$(TARGETDIR)\GameHistory.ilk"
	-@erase "$(TARGETDIR)\GameHistory.lib"
	-@erase "$(TARGETDIR)\GameHistory.obj"
	-@erase "$(TARGETDIR)\GameHistory.pdb"
	-@erase "$(TARGETDIR)\GameHistory.res"
	-@erase "$(TARGETDIR)\stack.obj"
	-@erase "$(TARGETDIR)\stdafx.obj"
	-@erase "$(TARGETDIR)\vc70.idb"
	-@erase "$(TARGETDIR)\vc70.pdb"
	-@erase ".\dlldata.c"
	-@erase ".\_GameHistory.h"
	-@erase ".\_GameHistory.idl"
	-@erase ".\_GameHistory.tlb"
	-@erase ".\_GameHistory_i.c"
	-@erase ".\_GameHistory_p.c"

"$(BINDIR)" :
	if not exist "$(BINDIR)/$(NULL)" mkdir "$(BINDIR)"

"$(OUTDIR)" : "$(BINDIR)"
	if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(TARGETDIR)" :
	if not exist "$(TARGETDIR)/$(NULL)" mkdir "$(TARGETDIR)"

"$(TARGETDIR)\GameHistory.dll" : "$(TARGETDIR)"
	rc /d "_DEBUG" /l 0x409 /I "$(TARGETDIR)" /fo"$(TARGETDIR)/GameHistory.res" GameHistory.rc
	cl /Od /D "WIN32" /D "_WINDOWS" /D "_DEBUG" /D "_USRDLL" /D "_ATL_ATTRIBUTES" /D "_MBCS" /D "_WINDLL" /Gm /EHsc /RTC1 /MDd /Yc"stdafx.h" /Fp"$(TARGETDIR)/GameHistory.pch" /Fo"$(TARGETDIR)/" /Fd"$(TARGETDIR)/vc70.pdb" /FR"$(TARGETDIR)/" /W3 /c /Wp64 /ZI /TP stdafx.cpp
	cl /Od /D "WIN32" /D "_WINDOWS" /D "_DEBUG" /D "_USRDLL" /D "_ATL_ATTRIBUTES" /D "_MBCS" /D "_WINDLL" /Gm /EHsc /RTC1 /MDd /Yu"stdafx.h" /Fp"$(TARGETDIR)/GameHistory.pch" /Fo"$(TARGETDIR)/" /Fd"$(TARGETDIR)/vc70.pdb" /FR"$(TARGETDIR)/" /W3 /c /Wp64 /ZI /TP stack.cpp GameHistory.cpp
	link /OUT:"$(TARGETDIR)/GameHistory.dll" /INCREMENTAL /NOLOGO /DLL /IDLOUT:"_GameHistory.idl" /DEBUG /PDB:"$(TARGETDIR)/GameHistory.pdb" /SUBSYSTEM:WINDOWS /IMPLIB:"$(TARGETDIR)/GameHistory.lib" /MACHINE:$(ARCH)  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib "$(TARGETDIR)\GameHistory.obj" "$(TARGETDIR)\stack.obj" "$(TARGETDIR)\stdafx.obj" "$(TARGETDIR)\GameHistory.res"
	bscmake /o "$(TARGETDIR)/GameHistory.bsc" "$(TARGETDIR)\GameHistory.sbr" "$(TARGETDIR)\stack.sbr" "$(TARGETDIR)\stdafx.sbr"
	@if exist "$(TARGETDIR)\GameHistory.dll.manifest"  mt /outputresource:"$(TARGETDIR)\GameHistory.dll";2 /manifest "$(TARGETDIR)\GameHistory.dll.manifest"

"$(OUTDIR)\GameHistory.dll" : "$(OUTDIR)"
	$(SIMULATOR_PIPE) $(ADMIN_PIPE) regsvr32 /s /c "$(TARGETDIR)\GameHistory.dll"
	tlbimp "$(TARGETDIR)\GameHistory.dll" /Out:"$(OUTDIR)\GameHistory.dll"

# --- Release configuration ---

!ELSEIF  "$(CFG)" == "Release"

!MESSAGE Building "$(CFG)" Configuration

BINDIR=..\bin
OUTDIR=..\bin\Release
TARGETDIR=.\Release

ALL : "$(TARGETDIR)\GameHistory.dll" "$(OUTDIR)\GameHistory.dll"

CLEAN :
	if exist "$(TARGETDIR)\GameHistory.dll" $(ADMIN_PIPE) regsvr32 /u /s "$(TARGETDIR)\GameHistory.dll"
	-@erase "$(OUTDIR)\GameHistory.dll"
	-@erase "$(TARGETDIR)\GameHistory.dll"
	-@erase "$(TARGETDIR)\GameHistory.exp"
	-@erase "$(TARGETDIR)\GameHistory.lib"
	-@erase "$(TARGETDIR)\GameHistory.obj"
	-@erase "$(TARGETDIR)\GameHistory.res"
	-@erase "$(TARGETDIR)\stack.obj"
	-@erase "$(TARGETDIR)\stdafx.obj"
	-@erase "$(TARGETDIR)\vc70.idb"
	-@erase ".\dlldata.c"
	-@erase ".\_GameHistory.h"
	-@erase ".\_GameHistory.idl"
	-@erase ".\_GameHistory.tlb"
	-@erase ".\_GameHistory_i.c"
	-@erase ".\_GameHistory_p.c"

"$(BINDIR)" :
	if not exist "$(BINDIR)/$(NULL)" mkdir "$(BINDIR)"

"$(OUTDIR)" : "$(BINDIR)"
	if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(TARGETDIR)" :
	if not exist "$(TARGETDIR)/$(NULL)" mkdir "$(TARGETDIR)"

"$(TARGETDIR)\GameHistory.dll" : "$(TARGETDIR)"
	rc /d "NDEBUG" /l 0x409 /I "$(TARGETDIR)" /fo"$(TARGETDIR)/GameHistory.res" "GameHistory.rc"
	cl /O2 /Ob1 /D "WIN32" /D "_WINDOWS" /D "NDEBUG" /D "_USRDLL" /D "_ATL_ATTRIBUTES" /D "_MBCS" /D "_ATL_STATIC_REGISTRY" /D "_WINDLL" /GF /FD /EHsc /MD /Gy /Yc"stdafx.h" /Fp"$(TARGETDIR)/GameHistory.pch" /Fo"$(TARGETDIR)/" /Fd"$(TARGETDIR)/vc70.pdb" /W3 /c /Wp64 /Zi /TP stdafx.cpp
	cl /O2 /Ob1 /D "WIN32" /D "_WINDOWS" /D "NDEBUG" /D "_USRDLL" /D "_ATL_ATTRIBUTES" /D "_MBCS" /D "_ATL_STATIC_REGISTRY" /D "_WINDLL" /GF /FD /EHsc /MD /Gy /Yu"stdafx.h" /Fp"$(TARGETDIR)/GameHistory.pch" /Fo"$(TARGETDIR)/" /Fd"$(TARGETDIR)/vc70.pdb" /W3 /c /Wp64 /Zi /TP stack.cpp GameHistory.cpp
	link /OUT:"$(TARGETDIR)/GameHistory.dll" /INCREMENTAL:NO /NOLOGO /DLL /IDLOUT:"_GameHistory.idl" /DEBUG /PDB:"$(TARGETDIR)/GameHistory.pdb" /SUBSYSTEM:WINDOWS /IMPLIB:"$(TARGETDIR)/GameHistory.lib" /MACHINE:$(ARCH)  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib "$(TARGETDIR)\GameHistory.obj" "$(TARGETDIR)\stack.obj" "$(TARGETDIR)\stdafx.obj" "$(TARGETDIR)\GameHistory.res"
	@if exist "$(TARGETDIR)\GameHistory.dll.manifest"  mt /outputresource:"$(TARGETDIR)\GameHistory.dll";2 /manifest "$(TARGETDIR)\GameHistory.dll.manifest"

"$(OUTDIR)\GameHistory.dll" : "$(OUTDIR)"
	$(SIMULATOR_PIPE) $(ADMIN_PIPE) regsvr32 /s /c "$(TARGETDIR)\GameHistory.dll"
	tlbimp "$(TARGETDIR)\GameHistory.dll" /Out:"$(OUTDIR)\GameHistory.dll"

!ENDIF