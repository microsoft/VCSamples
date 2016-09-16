!MESSAGE --- PUZZLE main CLR Assembly : Depends on TileDriver CLR Assembly ---
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

OUTDIR=.\bin\Debug
OBJDIR=.\obj
RESDIR=.\obj\Debug

ALL : "$(OUTDIR)\TileDriver.dll" "$(OUTDIR)\puzzle.exe"

CLEAN :
	-@erase "$(OUTDIR)\puzzle.exe"
	-@erase "$(OUTDIR)\puzzle.pdb"
	-@erase "$(RESDIR)\PUZZLE.AboutForm.resources"
	-@erase "$(RESDIR)\PUZZLE.MainForm.resources"
	-@erase "$(RESDIR)\PUZZLE.BoardSizeForm.resources"
	cd "TileDriver"
	nmake /F makefile.mak CFG="$(CFG)" CLEAN
	cd ..

"$(OBJDIR)" :
	if not exist "$(OBJDIR)/$(NULL)" mkdir "$(OBJDIR)"

"$(RESDIR)" : "$(OBJDIR)"
	if not exist "$(RESDIR)/$(NULL)" mkdir "$(RESDIR)"

"$(OUTDIR)\puzzle.exe" : "$(RESDIR)"
	resgen aboutform.resx "$(RESDIR)\PUZZLE.AboutForm.resources"
	resgen mainform.resx "$(RESDIR)\PUZZLE.MainForm.resources"
	resgen BoardSizeForm.resx "$(RESDIR)\PUZZLE.BoardSizeForm.resources"
	csc /out:"$(OUTDIR)\puzzle.exe" /debug+ /optimize- /target:exe /define:_DEBUG /r:System.dll /r:System.Data.dll /r:System.Drawing.dll /r:System.Windows.Forms.dll /r:System.XML.dll /r:Accessibility.dll /r:System.Runtime.Serialization.Formatters.Soap.dll /r:"$(OUTDIR)\TileDriver.dll" /res:"$(RESDIR)\PUZZLE.BoardSizeForm.resources",PUZZLE.BoardSizeForm.resources /res:"$(RESDIR)\PUZZLE.AboutForm.resources",PUZZLE.AboutForm.resources /res:"$(RESDIR)\PUZZLE.MainForm.resources",PUZZLE.MainForm.resources aboutform.cs boardsizeform.cs board.cs mainform.cs

"$(OUTDIR)\TileDriver.dll" :
	cd "TileDriver"
	nmake /F makefile.mak CFG="$(CFG)"
	cd ..

# --- Release configuration ---

!ELSEIF  "$(CFG)" == "Release"

!MESSAGE Building "$(CFG)" Configuration

OUTDIR=.\bin\Release
OBJDIR=.\obj
RESDIR=.\obj\Release

ALL : "$(OUTDIR)\TileDriver.dll" "$(OUTDIR)\puzzle.exe"

CLEAN :
	-@erase "$(OUTDIR)\puzzle.exe"
	-@erase "$(RESDIR)\PUZZLE.AboutForm.resources"
	-@erase "$(RESDIR)\PUZZLE.MainForm.resources"
	-@erase "$(RESDIR)\PUZZLE.BoardSizeForm.resources"
	cd "TileDriver"
	nmake /F makefile.mak CFG="$(CFG)" CLEAN
	cd ..

"$(OBJDIR)" :
	if not exist "$(OBJDIR)/$(NULL)" mkdir "$(OBJDIR)"

"$(RESDIR)" : "$(OBJDIR)"
	if not exist "$(RESDIR)/$(NULL)" mkdir "$(RESDIR)"

"$(OUTDIR)\puzzle.exe" : "$(RESDIR)"
	resgen aboutform.resx "$(RESDIR)\PUZZLE.AboutForm.resources"
	resgen mainform.resx "$(RESDIR)\PUZZLE.MainForm.resources"
	resgen BoardSizeForm.resx "$(RESDIR)\PUZZLE.BoardSizeForm.resources"
	csc /out:"$(OUTDIR)\puzzle.exe" /optimize+ /target:winexe /r:System.dll /r:System.Data.dll /r:System.Drawing.dll /r:System.Windows.Forms.dll /r:System.XML.dll /r:Accessibility.dll /r:System.Runtime.Serialization.Formatters.Soap.dll /r:"$(OUTDIR)\TileDriver.dll" /res:"$(RESDIR)\PUZZLE.BoardSizeForm.resources",PUZZLE.BoardSizeForm.resources /res:"$(RESDIR)\PUZZLE.AboutForm.resources",PUZZLE.AboutForm.resources /res:"$(RESDIR)\PUZZLE.MainForm.resources",PUZZLE.MainForm.resources aboutform.cs boardsizeform.cs board.cs mainform.cs

"$(OUTDIR)\TileDriver.dll" :
	cd "TileDriver"
	nmake /F makefile.mak CFG="$(CFG)"
	cd ..

!ENDIF