!MESSAGE --- TileDriver CLR Assembly : Depends on TilePuzzle CLR Assembly and GameHistory Native COM Server ---
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

OUTDIR=..\bin\Debug
TARGETDIR=.\Debug

ALL : "$(OUTDIR)\TilePuzzle.dll" "$(OUTDIR)\GameHistory.dll" "$(OUTDIR)\TileDriver.dll"

CLEAN :
	-@erase "$(OUTDIR)\TileDriver.dll"
	-@erase "$(OUTDIR)\TileDriver.manifest"
	-@erase "$(OUTDIR)\TileDriver.ilk"
	-@erase "$(TARGETDIR)\Board.obj"
	-@erase "$(TARGETDIR)\SolverThreads.obj"
	-@erase "$(TARGETDIR)\TileDriver.obj"
	-@erase "$(TARGETDIR)\TileDriver.pdb"
	-@erase "$(TARGETDIR)\vc70.idb"
	-@erase "$(TARGETDIR)\vc70.pdb"
	cd "..\GameHistory"
	nmake /F makefile.mak CFG="$(CFG)" CLEAN
	cd "..\TileDriver"
	cd "..\TilePuzzle"
	nmake /F makefile.mak CFG="$(CFG)" CLEAN
	cd "..\TileDriver"

"$(TARGETDIR)" :
	if not exist "$(TARGETDIR)/$(NULL)" mkdir "$(TARGETDIR)"

"$(OUTDIR)\TileDriver.dll" : "$(TARGETDIR)"
	cl /Od /AI "$(OUTDIR)" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_WINDLL"  /MDd /Yc"stdafx.h" /Fp"$(TARGETDIR)/TileDriver.pch" /Fo"$(TARGETDIR)/" /Fd"$(TARGETDIR)/vc70.pdb" /FR"$(TARGETDIR)/" /W3 /c /Zi /clr /TP Stdafx.cpp
	cl /Od /AI "$(OUTDIR)" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_WINDLL"  /MDd /Yu"stdafx.h" /Fp"$(TARGETDIR)/TileDriver.pch" /Fo"$(TARGETDIR)/" /Fd"$(TARGETDIR)/vc70.pdb" /FR"$(TARGETDIR)/" /W3 /c /Zi /clr /TP TileDriver.cpp SolverThreads.cpp Board.cpp AssemblyInfo.cpp
	link /OUT:"$(OUTDIR)/TileDriver.dll" /INCREMENTAL /NOLOGO /DLL /DEBUG /PDB:"$(OUTDIR)/TileDriver.pdb"  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib "$(TARGETDIR)\AssemblyInfo.obj" "$(TARGETDIR)\Board.obj" "$(TARGETDIR)\SolverThreads.obj" "$(TARGETDIR)\Stdafx.obj" "$(TARGETDIR)\TileDriver.obj"
	bscmake /o "$(TARGETDIR)/TileDriver.bsc" "$(TARGETDIR)\AssemblyInfo.sbr" "$(TARGETDIR)\Board.sbr" "$(TARGETDIR)\SolverThreads.sbr" "$(TARGETDIR)\Stdafx.sbr" "$(TARGETDIR)\TileDriver.sbr"
	@if exist "$(OUTDIR)\TileDriver.dll.manifest"  mt /outputresource:"$(OUTDIR)\TileDriver.dll";2 /manifest "$(OUTDIR)\TileDriver.dll.manifest"
	

"$(OUTDIR)\GameHistory.dll" :
	cd "..\GameHistory"
	nmake /F makefile.mak CFG="$(CFG)"
	cd "..\TileDriver"

"$(OUTDIR)\TilePuzzle.dll" :
	cd "..\TilePuzzle"
	nmake /F makefile.mak CFG="$(CFG)"
	cd "..\TileDriver"

# --- Release configuration ---

!ELSEIF  "$(CFG)" == "Release"

!MESSAGE Building "$(CFG)" Configuration

OUTDIR=..\bin\Release
TARGETDIR=.\Release

ALL : "$(OUTDIR)\TilePuzzle.dll" "$(OUTDIR)\GameHistory.dll" "$(OUTDIR)\TileDriver.dll"

CLEAN :
	-@erase "$(OUTDIR)\TileDriver.dll"
	-@erase "$(OUTDIR)\TileDriver.dll.manifest"
	-@erase "$(TARGETDIR)\Board.obj"
	-@erase "$(TARGETDIR)\SolverThreads.obj"
	-@erase "$(TARGETDIR)\TileDriver.obj"
	-@erase "$(TARGETDIR)\vc70.idb"
	cd "..\GameHistory"
	nmake /F makefile.mak CFG="$(CFG)" CLEAN
	cd "..\TileDriver"
	cd "..\TilePuzzle"
	nmake /F makefile.mak CFG="$(CFG)" CLEAN
	cd "..\TileDriver"

"$(TARGETDIR)" :
	if not exist "$(TARGETDIR)/$(NULL)" mkdir "$(TARGETDIR)"

"$(OUTDIR)\TileDriver.dll" : "$(TARGETDIR)"
	cl /O2 /Ob1 /AI "$(OUTDIR)" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_WINDLL" /FD  /MD /Yc"stdafx.h" /Fp"$(TARGETDIR)/TileDriver.pch" /Fo"$(TARGETDIR)/" /Fd"$(TARGETDIR)/vc70.pdb" /W3 /c /Zi /clr /TP Stdafx.cpp
	cl /O2 /Ob1 /AI "$(OUTDIR)" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_WINDLL" /FD  /MD /Yu"stdafx.h" /Fp"$(TARGETDIR)/TileDriver.pch" /Fo"$(TARGETDIR)/" /Fd"$(TARGETDIR)/vc70.pdb" /W3 /c /Zi /clr /TP TileDriver.cpp SolverThreads.cpp Board.cpp AssemblyInfo.cpp
	link /OUT:"$(OUTDIR)/TileDriver.dll" /INCREMENTAL:NO /NOLOGO /DLL /DEBUG /PDB:"$(OUTDIR)/TileDriver.pdb"  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib "$(TARGETDIR)\AssemblyInfo.obj" "$(TARGETDIR)\Board.obj" "$(TARGETDIR)\SolverThreads.obj" "$(TARGETDIR)\Stdafx.obj" "$(TARGETDIR)\TileDriver.obj"
	@if exist "$(OUTDIR)\TileDriver.dll.manifest"  mt /outputresource:"$(OUTDIR)\TileDriver.dll";2 /manifest "$(OUTDIR)\TileDriver.dll.manifest"

"$(OUTDIR)\GameHistory.dll" :
	cd "..\GameHistory"
	nmake /F makefile.mak CFG="$(CFG)"
	cd "..\TileDriver"

"$(OUTDIR)\TilePuzzle.dll" :
	cd "..\TilePuzzle"
	nmake /F makefile.mak CFG="$(CFG)"
	cd "..\TileDriver"

!ENDIF