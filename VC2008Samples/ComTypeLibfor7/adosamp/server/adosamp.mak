# Microsoft Developer Studio Generated NMAKE File, Based on ADOSamp.dsp
!IF "$(CFG)" == ""
CFG=ADOSamp - Win32 Unicode Exe Debug
!MESSAGE No configuration specified. Defaulting to ADOSamp - Win32 Unicode Exe\
 Debug.
!ENDIF 

!IF "$(CFG)" != "ADOSamp - Win32 Release" && "$(CFG)" !=\
 "ADOSamp - Win32 Debug" && "$(CFG)" != "ADOSamp - Win32 Unicode Debug" &&\
 "$(CFG)" != "ADOSamp - Win32 Unicode Release" && "$(CFG)" !=\
 "ADOSamp - Win32 Exe Release" && "$(CFG)" != "ADOSamp - Win32 Exe Debug" &&\
 "$(CFG)" != "ADOSamp - Win32 Unicode Exe Debug" && "$(CFG)" !=\
 "ADOSamp - Win32 Unicode Exe Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ADOSamp.mak" CFG="ADOSamp - Win32 Unicode Exe Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ADOSamp - Win32 Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ADOSamp - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ADOSamp - Win32 Unicode Debug" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ADOSamp - Win32 Unicode Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ADOSamp - Win32 Exe Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ADOSamp - Win32 Exe Debug" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ADOSamp - Win32 Unicode Exe Debug" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ADOSamp - Win32 Unicode Exe Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "ADOSamp - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : adosamp.tlb "$(OUTDIR)\ADOSamp.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : adosamp.tlb "$(OUTDIR)\ADOSamp.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ADOSamp.obj"
	-@erase "$(INTDIR)\ADOSamp.pch"
	-@erase "$(INTDIR)\ADOSamp.res"
	-@erase "$(INTDIR)\ADOTier.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\ADOSamp.dll"
	-@erase "$(OUTDIR)\ADOSamp.exp"
	-@erase "$(OUTDIR)\ADOSamp.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /Fp"$(INTDIR)\ADOSamp.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
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
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ADOSamp.res" /d "NDEBUG" /d "_USRDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ADOSamp.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)\ADOSamp.pdb" /machine:I386 /def:".\ADOSamp.def"\
 /out:"$(OUTDIR)\ADOSamp.dll" /implib:"$(OUTDIR)\ADOSamp.lib" 
LINK32_OBJS= \
	"$(INTDIR)\ADOSamp.obj" \
	"$(INTDIR)\ADOSamp.res" \
	"$(INTDIR)\ADOTier.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\ADOSamp.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Release
TargetPath=.\Release\ADOSamp.dll
InputPath=.\Release\ADOSamp.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : adosamp.tlb "$(OUTDIR)\ADOSamp.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : adosamp.tlb "$(OUTDIR)\ADOSamp.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ADOSamp.obj"
	-@erase "$(INTDIR)\ADOSamp.pch"
	-@erase "$(INTDIR)\ADOSamp.res"
	-@erase "$(INTDIR)\ADOTier.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\ADOSamp.dll"
	-@erase "$(OUTDIR)\ADOSamp.exp"
	-@erase "$(OUTDIR)\ADOSamp.ilk"
	-@erase "$(OUTDIR)\ADOSamp.lib"
	-@erase "$(OUTDIR)\ADOSamp.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_USRDLL" /Fp"$(INTDIR)\ADOSamp.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
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
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ADOSamp.res" /d "_DEBUG" /d "_USRDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ADOSamp.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)\ADOSamp.pdb" /debug /machine:I386 /def:".\ADOSamp.def"\
 /out:"$(OUTDIR)\ADOSamp.dll" /implib:"$(OUTDIR)\ADOSamp.lib" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\ADOSamp.obj" \
	"$(INTDIR)\ADOSamp.res" \
	"$(INTDIR)\ADOTier.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\ADOSamp.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Debug
TargetPath=.\Debug\ADOSamp.dll
InputPath=.\Debug\ADOSamp.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\DebugU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : adosamp.tlb "$(OUTDIR)\ADOSamp.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : adosamp.tlb "$(OUTDIR)\ADOSamp.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ADOSamp.obj"
	-@erase "$(INTDIR)\ADOSamp.pch"
	-@erase "$(INTDIR)\ADOSamp.res"
	-@erase "$(INTDIR)\ADOTier.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\ADOSamp.dll"
	-@erase "$(OUTDIR)\ADOSamp.exp"
	-@erase "$(OUTDIR)\ADOSamp.ilk"
	-@erase "$(OUTDIR)\ADOSamp.lib"
	-@erase "$(OUTDIR)\ADOSamp.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\ADOSamp.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\DebugU/
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
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ADOSamp.res" /d "_DEBUG" /d "_USRDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ADOSamp.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)\ADOSamp.pdb" /debug /machine:I386 /def:".\ADOSamp.def"\
 /out:"$(OUTDIR)\ADOSamp.dll" /implib:"$(OUTDIR)\ADOSamp.lib" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\ADOSamp.obj" \
	"$(INTDIR)\ADOSamp.res" \
	"$(INTDIR)\ADOTier.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\ADOSamp.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\DebugU
TargetPath=.\DebugU\ADOSamp.dll
InputPath=.\DebugU\ADOSamp.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Unicode Release"

OUTDIR=.\ReleaseU
INTDIR=.\ReleaseU
# Begin Custom Macros
OutDir=.\ReleaseU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : adosamp.tlb "$(OUTDIR)\ADOSamp.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : adosamp.tlb "$(OUTDIR)\ADOSamp.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ADOSamp.obj"
	-@erase "$(INTDIR)\ADOSamp.pch"
	-@erase "$(INTDIR)\ADOSamp.res"
	-@erase "$(INTDIR)\ADOTier.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\ADOSamp.dll"
	-@erase "$(OUTDIR)\ADOSamp.exp"
	-@erase "$(OUTDIR)\ADOSamp.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\ADOSamp.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseU/
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
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ADOSamp.res" /d "NDEBUG" /d "_USRDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ADOSamp.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)\ADOSamp.pdb" /machine:I386 /def:".\ADOSamp.def"\
 /out:"$(OUTDIR)\ADOSamp.dll" /implib:"$(OUTDIR)\ADOSamp.lib" 
LINK32_OBJS= \
	"$(INTDIR)\ADOSamp.obj" \
	"$(INTDIR)\ADOSamp.res" \
	"$(INTDIR)\ADOTier.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\ADOSamp.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseU
TargetPath=.\ReleaseU\ADOSamp.dll
InputPath=.\ReleaseU\ADOSamp.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Exe Release"

OUTDIR=.\ExeRelease
INTDIR=.\ExeRelease
# Begin Custom Macros
OutDir=.\ExeRelease
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : adosamp.tlb "$(OUTDIR)\ADOSamp.exe" "$(OUTDIR)\ADOSamp.pch" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : adosamp.tlb "$(OUTDIR)\ADOSamp.exe" "$(OUTDIR)\ADOSamp.pch" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ADOSamp.obj"
	-@erase "$(INTDIR)\ADOSamp.pch"
	-@erase "$(INTDIR)\ADOSamp.res"
	-@erase "$(INTDIR)\ADOTier.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\ADOSamp.exe"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ExeRelease/
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
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ADOSamp.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ADOSamp.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\ADOSamp.pdb" /machine:I386 /out:"$(OUTDIR)\ADOSamp.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ADOSamp.obj" \
	"$(INTDIR)\ADOSamp.res" \
	"$(INTDIR)\ADOTier.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\ADOSamp.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ExeRelease
TargetName=ADOSamp
InputPath=.\ExeRelease\ADOSamp.exe
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(OutDir)\$(TargetName) /RegServer 
	echo $(TargetName) exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Exe Debug"

OUTDIR=.\ExeDebug
INTDIR=.\ExeDebug
# Begin Custom Macros
OutDir=.\ExeDebug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : adosamp.tlb "$(OUTDIR)\ADOSamp.exe" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : adosamp.tlb "$(OUTDIR)\ADOSamp.exe" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ADOSamp.obj"
	-@erase "$(INTDIR)\ADOSamp.pch"
	-@erase "$(INTDIR)\ADOSamp.res"
	-@erase "$(INTDIR)\ADOTier.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\ADOSamp.exe"
	-@erase "$(OUTDIR)\ADOSamp.ilk"
	-@erase "$(OUTDIR)\ADOSamp.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /Fp"$(INTDIR)\ADOSamp.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 
CPP_OBJS=.\ExeDebug/
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
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ADOSamp.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ADOSamp.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\ADOSamp.pdb" /debug /machine:IX86 /out:"$(OUTDIR)\ADOSamp.exe"\
 /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\ADOSamp.obj" \
	"$(INTDIR)\ADOSamp.res" \
	"$(INTDIR)\ADOTier.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\ADOSamp.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ExeDebug
TargetName=ADOSamp
InputPath=.\ExeDebug\ADOSamp.exe
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(OutDir)\$(TargetName) /RegServer 
	echo $(TargetName) exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Unicode Exe Debug"

OUTDIR=.\ExeDebugU
INTDIR=.\ExeDebugU
# Begin Custom Macros
OutDir=.\ExeDebugU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : adosamp.tlb "$(OUTDIR)\ADOSamp.exe" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : adosamp.tlb "$(OUTDIR)\ADOSamp.exe" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ADOSamp.obj"
	-@erase "$(INTDIR)\ADOSamp.pch"
	-@erase "$(INTDIR)\ADOSamp.res"
	-@erase "$(INTDIR)\ADOTier.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\ADOSamp.exe"
	-@erase "$(OUTDIR)\ADOSamp.ilk"
	-@erase "$(OUTDIR)\ADOSamp.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "UNICODE" /D "_UNICODE" /Fp"$(INTDIR)\ADOSamp.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ExeDebugU/
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
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ADOSamp.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ADOSamp.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\ADOSamp.pdb" /debug /machine:IX86 /out:"$(OUTDIR)\ADOSamp.exe"\
 /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\ADOSamp.obj" \
	"$(INTDIR)\ADOSamp.res" \
	"$(INTDIR)\ADOTier.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\ADOSamp.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ExeDebugU
TargetName=ADOSamp
InputPath=.\ExeDebugU\ADOSamp.exe
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(OutDir)\$(TargetName) /RegServer 
	echo $(TargetName) exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Unicode Exe Release"

OUTDIR=.\ExeReleaseU
INTDIR=.\ExeReleaseU
# Begin Custom Macros
OutDir=.\ExeReleaseU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : adosamp.tlb "$(OUTDIR)\ADOSamp.exe" "$(OUTDIR)\ADOSamp.pch" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : adosamp.tlb "$(OUTDIR)\ADOSamp.exe" "$(OUTDIR)\ADOSamp.pch" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ADOSamp.obj"
	-@erase "$(INTDIR)\ADOSamp.pch"
	-@erase "$(INTDIR)\ADOSamp.res"
	-@erase "$(INTDIR)\ADOTier.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\ADOSamp.exe"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "UNICODE" /D "_UNICODE" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ExeReleaseU/
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
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ADOSamp.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ADOSamp.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\ADOSamp.pdb" /machine:I386 /out:"$(OUTDIR)\ADOSamp.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ADOSamp.obj" \
	"$(INTDIR)\ADOSamp.res" \
	"$(INTDIR)\ADOTier.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\ADOSamp.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ExeReleaseU
TargetName=ADOSamp
InputPath=.\ExeReleaseU\ADOSamp.exe
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(OutDir)\$(TargetName) /RegServer 
	echo $(TargetName) exec. time > "$(OutDir)\regsvr32.trg" 
	

!ENDIF 


!IF "$(CFG)" == "ADOSamp - Win32 Release" || "$(CFG)" ==\
 "ADOSamp - Win32 Debug" || "$(CFG)" == "ADOSamp - Win32 Unicode Debug" ||\
 "$(CFG)" == "ADOSamp - Win32 Unicode Release" || "$(CFG)" ==\
 "ADOSamp - Win32 Exe Release" || "$(CFG)" == "ADOSamp - Win32 Exe Debug" ||\
 "$(CFG)" == "ADOSamp - Win32 Unicode Exe Debug" || "$(CFG)" ==\
 "ADOSamp - Win32 Unicode Exe Release"
SOURCE=.\ADOSamp.cpp

!IF  "$(CFG)" == "ADOSamp - Win32 Release"

DEP_CPP_ADOSA=\
	".\ADOSamp.h"\
	".\ADOSamp_i.c"\
	".\ADOTier.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ADOSamp.obj" : $(SOURCE) $(DEP_CPP_ADOSA) "$(INTDIR)"\
 "$(INTDIR)\ADOSamp.pch" ".\ADOSamp_i.c" ".\ADOSamp.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Debug"

DEP_CPP_ADOSA=\
	".\ADOSamp_i.c"\
	".\ADOTier.h"\
	

"$(INTDIR)\ADOSamp.obj" : $(SOURCE) $(DEP_CPP_ADOSA) "$(INTDIR)"\
 "$(INTDIR)\ADOSamp.pch" ".\ADOSamp_i.c"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Unicode Debug"

DEP_CPP_ADOSA=\
	".\ADOSamp.h"\
	".\ADOSamp_i.c"\
	".\ADOTier.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ADOSamp.obj" : $(SOURCE) $(DEP_CPP_ADOSA) "$(INTDIR)"\
 "$(INTDIR)\ADOSamp.pch" ".\ADOSamp_i.c" ".\ADOSamp.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Unicode Release"

DEP_CPP_ADOSA=\
	".\ADOSamp.h"\
	".\ADOSamp_i.c"\
	".\ADOTier.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ADOSamp.obj" : $(SOURCE) $(DEP_CPP_ADOSA) "$(INTDIR)"\
 "$(INTDIR)\ADOSamp.pch" ".\ADOSamp_i.c" ".\ADOSamp.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Exe Release"

DEP_CPP_ADOSA=\
	".\ADOSamp.h"\
	".\ADOSamp_i.c"\
	".\ADOTier.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ADOSamp.obj" : $(SOURCE) $(DEP_CPP_ADOSA) "$(INTDIR)"\
 ".\ADOSamp_i.c" ".\ADOSamp.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Exe Debug"

DEP_CPP_ADOSA=\
	".\ADOSamp.h"\
	".\ADOSamp_i.c"\
	".\ADOTier.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ADOSamp.obj" : $(SOURCE) $(DEP_CPP_ADOSA) "$(INTDIR)"\
 "$(INTDIR)\ADOSamp.pch" ".\ADOSamp_i.c" ".\ADOSamp.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Unicode Exe Debug"

DEP_CPP_ADOSA=\
	".\ADOSamp.h"\
	".\ADOSamp_i.c"\
	".\ADOTier.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ADOSamp.obj" : $(SOURCE) $(DEP_CPP_ADOSA) "$(INTDIR)"\
 "$(INTDIR)\ADOSamp.pch" ".\ADOSamp_i.c" ".\ADOSamp.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Unicode Exe Release"

DEP_CPP_ADOSA=\
	".\ADOSamp.h"\
	".\ADOSamp_i.c"\
	".\ADOTier.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ADOSamp.obj" : $(SOURCE) $(DEP_CPP_ADOSA) "$(INTDIR)" ".\ADOSamp.h"\
 ".\ADOSamp_i.c"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\ADOSamp.idl

!IF  "$(CFG)" == "ADOSamp - Win32 Release"

InputPath=.\ADOSamp.idl
InputName=ADOSamp

"$(InputName).tlb"	"$(InputName).h"	"$(InputName)_i.c"	 : $(SOURCE) "$(INTDIR)"\
 "$(OUTDIR)"
	midl /h $(InputName).h /iid $(InputName)_i.c $(InputPath)

!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Debug"

InputPath=.\ADOSamp.idl
InputName=ADOSamp

"$(InputName).tlb"	"$(InputName).h"	"$(InputName)_i.c"	 : $(SOURCE) "$(INTDIR)"\
 "$(OUTDIR)"
	midl /h $(InputName).h /iid $(InputName)_i.c $(InputPath)

!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Unicode Debug"

InputPath=.\ADOSamp.idl
InputName=ADOSamp

"$(InputName).tlb"	"$(InputName).h"	"$(InputName)_i.c"	 : $(SOURCE) "$(INTDIR)"\
 "$(OUTDIR)"
	midl /h $(InputName).h /iid $(InputName)_i.c $(InputPath)

!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Unicode Release"

InputPath=.\ADOSamp.idl
InputName=ADOSamp

"$(InputName).tlb"	"$(InputName).h"	"$(InputName)_i.c"	 : $(SOURCE) "$(INTDIR)"\
 "$(OUTDIR)"
	midl /h $(InputName).h /iid $(InputName)_i.c $(InputPath)

!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Exe Release"

InputPath=.\ADOSamp.idl
InputName=ADOSamp

"$(InputName).tlb"	"$(InputName).h"	"$(InputName)_i.c"	 : $(SOURCE) "$(INTDIR)"\
 "$(OUTDIR)"
	midl /h $(InputName).h /iid $(InputName)_i.c $(InputPath)

!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Exe Debug"

InputPath=.\ADOSamp.idl
InputName=ADOSamp

"$(InputName).tlb"	"$(InputName).h"	"$(InputName)_i.c"	 : $(SOURCE) "$(INTDIR)"\
 "$(OUTDIR)"
	midl /h $(InputName).h /iid $(InputName)_i.c $(InputPath)

!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Unicode Exe Debug"

InputPath=.\ADOSamp.idl
InputName=ADOSamp

"$(InputName).tlb"	"$(InputName).h"	"$(InputName)_i.c"	 : $(SOURCE) "$(INTDIR)"\
 "$(OUTDIR)"
	midl /h $(InputName).h /iid $(InputName)_i.c $(InputPath)

!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Unicode Exe Release"

InputPath=.\ADOSamp.idl
InputName=ADOSamp

"$(InputName).tlb"	"$(InputName).h"	"$(InputName)_i.c"	 : $(SOURCE) "$(INTDIR)"\
 "$(OUTDIR)"
	midl /h $(InputName).h /iid $(InputName)_i.c $(InputPath)

!ENDIF 

SOURCE=.\ADOSamp.rc
DEP_RSC_ADOSAM=\
	".\ADOSamp.rgs"\
	".\ADOSamp.tlb"\
	".\ADOTier.rgs"\
	

!IF  "$(CFG)" == "ADOSamp - Win32 Release"


"$(INTDIR)\ADOSamp.res" : $(SOURCE) $(DEP_RSC_ADOSAM) "$(INTDIR)"\
 ".\ADOSamp.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Debug"


"$(INTDIR)\ADOSamp.res" : $(SOURCE) $(DEP_RSC_ADOSAM) "$(INTDIR)"\
 ".\ADOSamp.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Unicode Debug"


"$(INTDIR)\ADOSamp.res" : $(SOURCE) $(DEP_RSC_ADOSAM) "$(INTDIR)"\
 ".\ADOSamp.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Unicode Release"


"$(INTDIR)\ADOSamp.res" : $(SOURCE) $(DEP_RSC_ADOSAM) "$(INTDIR)"\
 ".\ADOSamp.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Exe Release"


"$(INTDIR)\ADOSamp.res" : $(SOURCE) $(DEP_RSC_ADOSAM) "$(INTDIR)"\
 ".\ADOSamp.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Exe Debug"


"$(INTDIR)\ADOSamp.res" : $(SOURCE) $(DEP_RSC_ADOSAM) "$(INTDIR)"\
 ".\ADOSamp.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Unicode Exe Debug"


"$(INTDIR)\ADOSamp.res" : $(SOURCE) $(DEP_RSC_ADOSAM) "$(INTDIR)"\
 ".\ADOSamp.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Unicode Exe Release"


"$(INTDIR)\ADOSamp.res" : $(SOURCE) $(DEP_RSC_ADOSAM) "$(INTDIR)"\
 ".\ADOSamp.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\ADOTier.cpp

!IF  "$(CFG)" == "ADOSamp - Win32 Release"

DEP_CPP_ADOTI=\
	".\ADOSamp.h"\
	".\ADOTier.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ADOTier.obj" : $(SOURCE) $(DEP_CPP_ADOTI) "$(INTDIR)"\
 "$(INTDIR)\ADOSamp.pch" ".\ADOSamp.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Debug"

DEP_CPP_ADOTI=\
	".\ADOTier.h"\
	

"$(INTDIR)\ADOTier.obj" : $(SOURCE) $(DEP_CPP_ADOTI) "$(INTDIR)"\
 "$(INTDIR)\ADOSamp.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Unicode Debug"

DEP_CPP_ADOTI=\
	".\ADOSamp.h"\
	".\ADOTier.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ADOTier.obj" : $(SOURCE) $(DEP_CPP_ADOTI) "$(INTDIR)"\
 "$(INTDIR)\ADOSamp.pch" ".\ADOSamp.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Unicode Release"

DEP_CPP_ADOTI=\
	".\ADOSamp.h"\
	".\ADOTier.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ADOTier.obj" : $(SOURCE) $(DEP_CPP_ADOTI) "$(INTDIR)"\
 "$(INTDIR)\ADOSamp.pch" ".\ADOSamp.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Exe Release"

DEP_CPP_ADOTI=\
	".\ADOSamp.h"\
	".\ADOTier.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ADOTier.obj" : $(SOURCE) $(DEP_CPP_ADOTI) "$(INTDIR)" ".\ADOSamp.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Exe Debug"

DEP_CPP_ADOTI=\
	".\ADOSamp.h"\
	".\ADOTier.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ADOTier.obj" : $(SOURCE) $(DEP_CPP_ADOTI) "$(INTDIR)"\
 "$(INTDIR)\ADOSamp.pch" ".\ADOSamp.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Unicode Exe Debug"

DEP_CPP_ADOTI=\
	".\ADOSamp.h"\
	".\ADOTier.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ADOTier.obj" : $(SOURCE) $(DEP_CPP_ADOTI) "$(INTDIR)"\
 "$(INTDIR)\ADOSamp.pch" ".\ADOSamp.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Unicode Exe Release"

DEP_CPP_ADOTI=\
	".\ADOSamp.h"\
	".\ADOTier.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ADOTier.obj" : $(SOURCE) $(DEP_CPP_ADOTI) "$(INTDIR)" ".\ADOSamp.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "ADOSamp - Win32 Release"

DEP_CPP_STDAF=\
	".\ADOSamp.h"\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /Fp"$(INTDIR)\ADOSamp.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ADOSamp.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)" ".\ADOSamp.h"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Debug"

DEP_CPP_STDAF=\
	".\ADOSamp.h"\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_USRDLL" /Fp"$(INTDIR)\ADOSamp.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ADOSamp.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)" ".\ADOSamp.h"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Unicode Debug"

DEP_CPP_STDAF=\
	".\ADOSamp.h"\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\ADOSamp.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ADOSamp.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)" ".\ADOSamp.h"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Unicode Release"

DEP_CPP_STDAF=\
	".\ADOSamp.h"\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\ADOSamp.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ADOSamp.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)" ".\ADOSamp.h"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Exe Release"

DEP_CPP_STDAF=\
	".\ADOSamp.h"\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS"\
 /Fp"$(INTDIR)\ADOSamp.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ADOSamp.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)" ".\ADOSamp.h"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Exe Debug"

DEP_CPP_STDAF=\
	".\ADOSamp.h"\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /Fp"$(INTDIR)\ADOSamp.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ADOSamp.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)" ".\ADOSamp.h"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Unicode Exe Debug"

DEP_CPP_STDAF=\
	".\ADOSamp.h"\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "UNICODE" /D "_UNICODE" /Fp"$(INTDIR)\ADOSamp.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ADOSamp.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)" ".\ADOSamp.h"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ADOSamp - Win32 Unicode Exe Release"

DEP_CPP_STDAF=\
	".\ADOSamp.h"\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "UNICODE" /D "_UNICODE" /Fp"$(INTDIR)\ADOSamp.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ADOSamp.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)" ".\ADOSamp.h"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\ADOSamp.h
SOURCE=.\ADOTier.h
SOURCE=.\Resource.h
SOURCE=.\StdAfx.h
SOURCE=.\ADOTier.rgs

!ENDIF 

