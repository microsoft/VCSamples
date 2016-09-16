!MESSAGE --- TilePuzzle CLR Assembly ---
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

# --- Debug configuration ---

!IF  "$(CFG)" == "Debug"

!MESSAGE Building "$(CFG)" Configuration

BINDIR=..\bin
OUTDIR=..\bin\Debug
TARGETDIR=.\Debug

ALL : "$(OUTDIR)" "$(TARGETDIR)" "$(OUTDIR)\TilePuzzle.dll"

CLEAN :
	-@erase "$(OUTDIR)\TilePuzzle.dll"
	-@erase "$(OUTDIR)\TilePuzzle.dll.manifest"
	-@erase "$(OUTDIR)\TilePuzzle.ilk"
	-@erase "$(TARGETDIR)\Engine.obj"
	-@erase "$(TARGETDIR)\GameTree.obj"
	-@erase "$(TARGETDIR)\TilePuzzle.pdb"
	-@erase "$(TARGETDIR)\vc70.idb"
	-@erase "$(TARGETDIR)\vc70.pdb"

"$(BINDIR)" :
	if not exist "$(BINDIR)/$(NULL)" mkdir "$(BINDIR)"

"$(OUTDIR)" : "$(BINDIR)"
	if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(TARGETDIR)" :
	if not exist "$(TARGETDIR)/$(NULL)" mkdir "$(TARGETDIR)"

"$(OUTDIR)\TilePuzzle.dll" :
	cl /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_WINDLL"  /MDd /Yc"stdafx.h" /Fp"$(TARGETDIR)/TilePuzzle.pch" /Fo"$(TARGETDIR)/" /Fd"$(TARGETDIR)/vc70.pdb" /FR"$(TARGETDIR)/" /W3 /c /Zi /clr /TP Stdafx.cpp
	cl /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_WINDLL"  /MDd /Yu"stdafx.h" /Fp"$(TARGETDIR)/TilePuzzle.pch" /Fo"$(TARGETDIR)/" /Fd"$(TARGETDIR)/vc70.pdb" /FR"$(TARGETDIR)/" /W3 /c /Zi /clr /TP GameTree.cpp Engine.cpp AssemblyInfo.cpp
	link /OUT:"$(OUTDIR)/TilePuzzle.dll" /INCREMENTAL /NOLOGO /DLL /DEBUG /PDB:"$(OUTDIR)/TilePuzzle.pdb"  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib "$(TARGETDIR)\AssemblyInfo.obj" "$(TARGETDIR)\Engine.obj" "$(TARGETDIR)\GameTree.obj" "$(TARGETDIR)\Stdafx.obj"
	bscmake /o "$(TARGETDIR)/TilePuzzle.bsc" "$(TARGETDIR)\AssemblyInfo.sbr" "$(TARGETDIR)\Engine.sbr" "$(TARGETDIR)\GameTree.sbr" "$(TARGETDIR)\Stdafx.sbr"
	@if exist "$(OUTDIR)\TilePuzzle.dll.manifest"  mt /outputresource:"$(OUTDIR)\TilePuzzle.dll";2 /manifest "$(OUTDIR)\TilePuzzle.dll.manifest"

# --- Release configuration ---

!ELSEIF  "$(CFG)" == "Release"

!MESSAGE Building "$(CFG)" Configuration

BINDIR=..\bin
OUTDIR=..\bin\Release
TARGETDIR=.\Release

ALL : "$(OUTDIR)" "$(TARGETDIR)" "$(OUTDIR)\TilePuzzle.dll"

CLEAN :
	-@erase "$(OUTDIR)\TilePuzzle.dll"
	-@erase "$(OUTDIR)\TilePuzzle.dll.manifest"
	-@erase "$(TARGETDIR)\Engine.obj"
	-@erase "$(TARGETDIR)\GameTree.obj"
	-@erase "$(TARGETDIR)\vc70.idb"

"$(BINDIR)" :
	if not exist "$(BINDIR)/$(NULL)" mkdir "$(BINDIR)"

"$(OUTDIR)" : "$(BINDIR)"
	if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(TARGETDIR)" :
	if not exist "$(TARGETDIR)/$(NULL)" mkdir "$(TARGETDIR)"

"$(OUTDIR)\TilePuzzle.dll" :
	cl /O2 /Ob1 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_WINDLL" /FD /MD /Yc"stdafx.h" /Fp"$(TARGETDIR)/TilePuzzle.pch" /Fo"$(TARGETDIR)/" /Fd"$(TARGETDIR)/vc70.pdb" /W3 /c /Zi /clr /TP Stdafx.cpp
	cl /O2 /Ob1 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_WINDLL" /FD /MD /Yu"stdafx.h" /Fp"$(TARGETDIR)/TilePuzzle.pch" /Fo"$(TARGETDIR)/" /Fd"$(TARGETDIR)/vc70.pdb" /W3 /c /Zi /clr /TP GameTree.cpp Engine.cpp AssemblyInfo.cpp
	link /OUT:"$(OUTDIR)/TilePuzzle.dll" /INCREMENTAL:NO /NOLOGO /DLL /DEBUG /PDB:"$(OUTDIR)/TilePuzzle.pdb"  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib "$(TARGETDIR)\AssemblyInfo.obj" "$(TARGETDIR)\Engine.obj" "$(TARGETDIR)\GameTree.obj" "$(TARGETDIR)\Stdafx.obj"
	mt /outputresource:"$(OUTDIR)\TilePuzzle.dll";2 /manifest "$(OUTDIR)\TilePuzzle.dll.manifest"

!ENDIF