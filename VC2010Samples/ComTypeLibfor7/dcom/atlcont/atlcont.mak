# Microsoft Developer Studio Generated NMAKE File, Based on atlcont.dsp
!IF "$(CFG)" == ""
CFG=AtlCont - Win32 Release
!MESSAGE No configuration specified. Defaulting to AtlCont - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "AtlCont - Win32 Release" && "$(CFG)" !=\
 "AtlCont - Win32 MinCRT" && "$(CFG)" != "AtlCont - Win32 Debug" && "$(CFG)" !=\
 "AtlCont - Win32 Unicode Release" && "$(CFG)" !=\
 "AtlCont - Win32 Unicode MinCRT" && "$(CFG)" != "AtlCont - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "atlcont.mak" CFG="AtlCont - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "AtlCont - Win32 Release" (based on "Win32 (x86) Win32 Application")
!MESSAGE "AtlCont - Win32 MinCRT" (based on "Win32 (x86) Win32 Application")
!MESSAGE "AtlCont - Win32 Debug" (based on "Win32 (x86) Win32 Application")
!MESSAGE "AtlCont - Win32 Unicode Release" (based on\
 "Win32 (x86) Win32 Application")
!MESSAGE "AtlCont - Win32 Unicode MinCRT" (based on\
 "Win32 (x86) Win32 Application")
!MESSAGE "AtlCont - Win32 Unicode Debug" (based on\
 "Win32 (x86) Win32 Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "AtlCont - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\atlcont.exe" "$(OutDir)\reg_exe.trg"

!ELSE 

ALL : "$(OUTDIR)\atlcont.exe" "$(OutDir)\reg_exe.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\AtlCont.obj"
	-@erase "$(INTDIR)\atlcont.pch"
	-@erase "$(INTDIR)\AtlCont.res"
	-@erase "$(INTDIR)\AtlCont1.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\atlcont.exe"
	-@erase "$(OutDir)\reg_exe.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)\atlcont.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\AtlCont.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\atlcont.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=oledlg.lib /nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\atlcont.pdb" /machine:I386 /out:"$(OUTDIR)\atlcont.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AtlCont.obj" \
	"$(INTDIR)\AtlCont.res" \
	"$(INTDIR)\AtlCont1.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\atlcont.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\atlcont.exe
InputPath=.\Release\atlcont.exe
SOURCE=$(InputPath)

"$(OutDir)\reg_exe.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(TargetPath) /RegServer 
	echo reg_exe exec. time > "$(OutDir)\reg_exe.trg" 
	echo Server registration done! 
	

!ELSEIF  "$(CFG)" == "AtlCont - Win32 MinCRT"

OUTDIR=.\MinRel
INTDIR=.\MinRel
# Begin Custom Macros
OutDir=.\.\MinRel
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\atlcont.exe" "$(OutDir)\reg_exe.trg"

!ELSE 

ALL : "$(OUTDIR)\atlcont.exe" "$(OutDir)\reg_exe.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\AtlCont.obj"
	-@erase "$(INTDIR)\AtlCont.res"
	-@erase "$(INTDIR)\AtlCont1.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\atlcont.exe"
	-@erase ".\Release\atlcont.pch"
	-@erase "$(OutDir)\reg_exe.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" \
 /Fp".\Release\AtlCont.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\MinRel/
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\AtlCont.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\atlcont.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=oledlg.lib /nologo /entry:"WinMain" /subsystem:windows\
 /incremental:no /pdb:"$(OUTDIR)\atlcont.pdb" /machine:I386\
 /out:"$(OUTDIR)\atlcont.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AtlCont.obj" \
	"$(INTDIR)\AtlCont.res" \
	"$(INTDIR)\AtlCont1.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\atlcont.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\MinRel
TargetPath=.\MinRel\atlcont.exe
InputPath=.\MinRel\atlcont.exe
SOURCE=$(InputPath)

"$(OutDir)\reg_exe.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(TargetPath) /RegServer 
	echo reg_exe exec. time > "$(OutDir)\reg_exe.trg" 
	echo Server registration done! 
	

!ELSEIF  "$(CFG)" == "AtlCont - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\atlcont.exe" "$(OutDir)\reg_exe.trg"

!ELSE 

ALL : "$(OUTDIR)\atlcont.exe" "$(OutDir)\reg_exe.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\AtlCont.obj"
	-@erase "$(INTDIR)\atlcont.pch"
	-@erase "$(INTDIR)\AtlCont.res"
	-@erase "$(INTDIR)\AtlCont1.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\atlcont.exe"
	-@erase "$(OUTDIR)\atlcont.ilk"
	-@erase "$(OUTDIR)\atlcont.pdb"
	-@erase "$(OutDir)\reg_exe.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /Fp"$(INTDIR)\atlcont.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\AtlCont.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\atlcont.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=oledlg.lib /nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\atlcont.pdb" /debug /machine:I386 /out:"$(OUTDIR)\atlcont.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AtlCont.obj" \
	"$(INTDIR)\AtlCont.res" \
	"$(INTDIR)\AtlCont1.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\atlcont.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\atlcont.exe
InputPath=.\Debug\atlcont.exe
SOURCE=$(InputPath)

"$(OutDir)\reg_exe.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(TargetPath) /RegServer 
	echo reg_exe exec. time > "$(OutDir)\reg_exe.trg" 
	echo Server registration done! 
	

!ELSEIF  "$(CFG)" == "AtlCont - Win32 Unicode Release"

OUTDIR=.\ReleaseU
INTDIR=.\ReleaseU
# Begin Custom Macros
OutDir=.\.\ReleaseU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\atlcont.exe" "$(OutDir)\reg_exe.trg"

!ELSE 

ALL : "$(OUTDIR)\atlcont.exe" "$(OutDir)\reg_exe.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\AtlCont.obj"
	-@erase "$(INTDIR)\atlcont.pch"
	-@erase "$(INTDIR)\AtlCont.res"
	-@erase "$(INTDIR)\AtlCont1.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\atlcont.exe"
	-@erase "$(OutDir)\reg_exe.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O1 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_MBCS" /D "_UNICODE" /Fp"$(INTDIR)\atlcont.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\AtlCont.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\atlcont.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=oledlg.lib /nologo /entry:"wWinMainCRTStartup" /subsystem:windows\
 /incremental:no /pdb:"$(OUTDIR)\atlcont.pdb" /machine:I386\
 /out:"$(OUTDIR)\atlcont.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AtlCont.obj" \
	"$(INTDIR)\AtlCont.res" \
	"$(INTDIR)\AtlCont1.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\atlcont.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\ReleaseU
TargetPath=.\ReleaseU\atlcont.exe
InputPath=.\ReleaseU\atlcont.exe
SOURCE=$(InputPath)

"$(OutDir)\reg_exe.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(TargetPath) /RegServer 
	echo reg_exe exec. time > "$(OutDir)\reg_exe.trg" 
	echo Server registration done! 
	

!ELSEIF  "$(CFG)" == "AtlCont - Win32 Unicode MinCRT"

OUTDIR=.\MinRelU
INTDIR=.\MinRelU
# Begin Custom Macros
OutDir=.\.\MinRelU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\atlcont.exe" "$(OutDir)\reg_exe.trg"

!ELSE 

ALL : "$(OUTDIR)\atlcont.exe" "$(OutDir)\reg_exe.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\AtlCont.obj"
	-@erase "$(INTDIR)\AtlCont.res"
	-@erase "$(INTDIR)\AtlCont1.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\atlcont.exe"
	-@erase ".\ReleaseU\atlcont.pch"
	-@erase "$(OutDir)\reg_exe.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /O1 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D\
 "_UNICODE" /Fp".\ReleaseU\AtlCont.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\MinRelU/
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\AtlCont.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\atlcont.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=oledlg.lib /nologo /entry:"wWinMain" /subsystem:windows\
 /incremental:no /pdb:"$(OUTDIR)\atlcont.pdb" /machine:I386\
 /out:"$(OUTDIR)\atlcont.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AtlCont.obj" \
	"$(INTDIR)\AtlCont.res" \
	"$(INTDIR)\AtlCont1.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\atlcont.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\MinRelU
TargetPath=.\MinRelU\atlcont.exe
InputPath=.\MinRelU\atlcont.exe
SOURCE=$(InputPath)

"$(OutDir)\reg_exe.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(TargetPath) /RegServer 
	echo reg_exe exec. time > "$(OutDir)\reg_exe.trg" 
	echo Server registration done! 
	

!ELSEIF  "$(CFG)" == "AtlCont - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\.\DebugU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\atlcont.exe" "$(OutDir)\reg_exe.trg"

!ELSE 

ALL : "$(OUTDIR)\atlcont.exe" "$(OutDir)\reg_exe.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\AtlCont.obj"
	-@erase "$(INTDIR)\atlcont.pch"
	-@erase "$(INTDIR)\AtlCont.res"
	-@erase "$(INTDIR)\AtlCont1.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\atlcont.exe"
	-@erase "$(OUTDIR)\atlcont.ilk"
	-@erase "$(OUTDIR)\atlcont.pdb"
	-@erase "$(OutDir)\reg_exe.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_MBCS" /D "_UNICODE" /Fp"$(INTDIR)\atlcont.pch" /Yu"stdafx.h"\
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\AtlCont.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\atlcont.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=oledlg.lib /nologo /entry:"wWinMainCRTStartup" /subsystem:windows\
 /incremental:yes /pdb:"$(OUTDIR)\atlcont.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)\atlcont.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AtlCont.obj" \
	"$(INTDIR)\AtlCont.res" \
	"$(INTDIR)\AtlCont1.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\atlcont.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\DebugU
TargetPath=.\DebugU\atlcont.exe
InputPath=.\DebugU\atlcont.exe
SOURCE=$(InputPath)

"$(OutDir)\reg_exe.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(TargetPath) /RegServer 
	echo reg_exe exec. time > "$(OutDir)\reg_exe.trg" 
	echo Server registration done! 
	

!ENDIF 


!IF "$(CFG)" == "AtlCont - Win32 Release" || "$(CFG)" ==\
 "AtlCont - Win32 MinCRT" || "$(CFG)" == "AtlCont - Win32 Debug" || "$(CFG)" ==\
 "AtlCont - Win32 Unicode Release" || "$(CFG)" ==\
 "AtlCont - Win32 Unicode MinCRT" || "$(CFG)" == "AtlCont - Win32 Unicode Debug"
SOURCE=.\AtlCont.cpp

!IF  "$(CFG)" == "AtlCont - Win32 Release"

DEP_CPP_ATLCO=\
	".\AtlCont.h"\
	".\AtlCont1.h"\
	".\AtlCont_i.c"\
	

"$(INTDIR)\AtlCont.obj" : $(SOURCE) $(DEP_CPP_ATLCO) "$(INTDIR)"\
 "$(INTDIR)\atlcont.pch" ".\AtlCont.h" ".\AtlCont_i.c"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AtlCont - Win32 MinCRT"

DEP_CPP_ATLCO=\
	".\AtlCont.h"\
	".\AtlCont1.h"\
	".\AtlCont_i.c"\
	

"$(INTDIR)\AtlCont.obj" : $(SOURCE) $(DEP_CPP_ATLCO) "$(INTDIR)"\
 ".\Release\atlcont.pch" ".\AtlCont.h" ".\AtlCont_i.c"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AtlCont - Win32 Debug"

DEP_CPP_ATLCO=\
	".\AtlCont.h"\
	".\AtlCont1.h"\
	".\AtlCont_i.c"\
	

"$(INTDIR)\AtlCont.obj" : $(SOURCE) $(DEP_CPP_ATLCO) "$(INTDIR)"\
 "$(INTDIR)\atlcont.pch" ".\AtlCont.h" ".\AtlCont_i.c"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AtlCont - Win32 Unicode Release"

DEP_CPP_ATLCO=\
	".\AtlCont.h"\
	".\AtlCont1.h"\
	".\AtlCont_i.c"\
	".\StdAfx.h"\
	

"$(INTDIR)\AtlCont.obj" : $(SOURCE) $(DEP_CPP_ATLCO) "$(INTDIR)"\
 "$(INTDIR)\atlcont.pch" ".\AtlCont.h" ".\AtlCont_i.c"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AtlCont - Win32 Unicode MinCRT"

DEP_CPP_ATLCO=\
	".\AtlCont.h"\
	".\AtlCont1.h"\
	".\AtlCont_i.c"\
	".\StdAfx.h"\
	

"$(INTDIR)\AtlCont.obj" : $(SOURCE) $(DEP_CPP_ATLCO) "$(INTDIR)"\
 ".\ReleaseU\atlcont.pch" ".\AtlCont.h" ".\AtlCont_i.c"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AtlCont - Win32 Unicode Debug"

DEP_CPP_ATLCO=\
	".\AtlCont.h"\
	".\AtlCont1.h"\
	".\AtlCont_i.c"\
	

"$(INTDIR)\AtlCont.obj" : $(SOURCE) $(DEP_CPP_ATLCO) "$(INTDIR)"\
 "$(INTDIR)\atlcont.pch" ".\AtlCont_i.c" ".\AtlCont.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\AtlCont.idl

!IF  "$(CFG)" == "AtlCont - Win32 Release"

InputPath=.\AtlCont.idl

"AtlCont.tlb"	"AtlCont.h"	"AtlCont_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oic /h AtlCont.h /iid AtlCont_i.c AtlCont.idl

!ELSEIF  "$(CFG)" == "AtlCont - Win32 MinCRT"

InputPath=.\AtlCont.idl

"AtlCont.tlb"	"AtlCont.h"	"AtlCont_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oic /h AtlCont.h /iid AtlCont_i.c AtlCont.idl

!ELSEIF  "$(CFG)" == "AtlCont - Win32 Debug"

InputPath=.\AtlCont.idl

"AtlCont.tlb"	"AtlCont.h"	"AtlCont_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oic /h AtlCont.h /iid AtlCont_i.c AtlCont.idl

!ELSEIF  "$(CFG)" == "AtlCont - Win32 Unicode Release"

InputPath=.\AtlCont.idl

"AtlCont.tlb"	"AtlCont.h"	"AtlCont_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oic /h AtlCont.h /iid AtlCont_i.c AtlCont.idl

!ELSEIF  "$(CFG)" == "AtlCont - Win32 Unicode MinCRT"

InputPath=.\AtlCont.idl

"AtlCont.tlb"	"AtlCont.h"	"AtlCont_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oic /h AtlCont.h /iid AtlCont_i.c AtlCont.idl

!ELSEIF  "$(CFG)" == "AtlCont - Win32 Unicode Debug"

InputPath=.\AtlCont.idl

"AtlCont.tlb"	"AtlCont.h"	"AtlCont_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl /Oic /h AtlCont.h /iid AtlCont_i.c AtlCont.idl

!ENDIF 

SOURCE=.\AtlCont.rc
DEP_RSC_ATLCON=\
	".\AtlCont.rgs"\
	".\AtlCont.tlb"\
	

!IF  "$(CFG)" == "AtlCont - Win32 Release"


"$(INTDIR)\AtlCont.res" : $(SOURCE) $(DEP_RSC_ATLCON) "$(INTDIR)"\
 ".\AtlCont.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AtlCont - Win32 MinCRT"


"$(INTDIR)\AtlCont.res" : $(SOURCE) $(DEP_RSC_ATLCON) "$(INTDIR)"\
 ".\AtlCont.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AtlCont - Win32 Debug"


"$(INTDIR)\AtlCont.res" : $(SOURCE) $(DEP_RSC_ATLCON) "$(INTDIR)"\
 ".\AtlCont.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AtlCont - Win32 Unicode Release"


"$(INTDIR)\AtlCont.res" : $(SOURCE) $(DEP_RSC_ATLCON) "$(INTDIR)"\
 ".\AtlCont.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AtlCont - Win32 Unicode MinCRT"


"$(INTDIR)\AtlCont.res" : $(SOURCE) $(DEP_RSC_ATLCON) "$(INTDIR)"\
 ".\AtlCont.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AtlCont - Win32 Unicode Debug"


"$(INTDIR)\AtlCont.res" : $(SOURCE) $(DEP_RSC_ATLCON) "$(INTDIR)"\
 ".\AtlCont.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\AtlCont1.cpp

!IF  "$(CFG)" == "AtlCont - Win32 Release"

DEP_CPP_ATLCONT=\
	".\AtlCont.h"\
	".\AtlCont1.h"\
	

"$(INTDIR)\AtlCont1.obj" : $(SOURCE) $(DEP_CPP_ATLCONT) "$(INTDIR)"\
 "$(INTDIR)\atlcont.pch" ".\AtlCont.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AtlCont - Win32 MinCRT"

DEP_CPP_ATLCONT=\
	".\AtlCont.h"\
	".\AtlCont1.h"\
	

"$(INTDIR)\AtlCont1.obj" : $(SOURCE) $(DEP_CPP_ATLCONT) "$(INTDIR)"\
 ".\Release\atlcont.pch" ".\AtlCont.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AtlCont - Win32 Debug"

DEP_CPP_ATLCONT=\
	".\AtlCont.h"\
	".\AtlCont1.h"\
	

"$(INTDIR)\AtlCont1.obj" : $(SOURCE) $(DEP_CPP_ATLCONT) "$(INTDIR)"\
 "$(INTDIR)\atlcont.pch" ".\AtlCont.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AtlCont - Win32 Unicode Release"

DEP_CPP_ATLCONT=\
	".\AtlCont.h"\
	".\AtlCont1.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\AtlCont1.obj" : $(SOURCE) $(DEP_CPP_ATLCONT) "$(INTDIR)"\
 "$(INTDIR)\atlcont.pch" ".\AtlCont.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AtlCont - Win32 Unicode MinCRT"

DEP_CPP_ATLCONT=\
	".\AtlCont.h"\
	".\AtlCont1.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\AtlCont1.obj" : $(SOURCE) $(DEP_CPP_ATLCONT) "$(INTDIR)"\
 ".\ReleaseU\atlcont.pch" ".\AtlCont.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "AtlCont - Win32 Unicode Debug"

DEP_CPP_ATLCONT=\
	".\AtlCont.h"\
	".\AtlCont1.h"\
	

"$(INTDIR)\AtlCont1.obj" : $(SOURCE) $(DEP_CPP_ATLCONT) "$(INTDIR)"\
 "$(INTDIR)\atlcont.pch" ".\AtlCont.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "AtlCont - Win32 Release"

DEP_CPP_STDAF=\
	"..\drawctl\drawctl.tlb"\
	".\StdAfx.h"\
	"d:\msdev\mcl\atl\include\atliface.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)\atlcont.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\atlcont.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "AtlCont - Win32 MinCRT"

DEP_CPP_STDAF=\
	"..\drawctl\drawctl.tlb"\
	".\StdAfx.h"\
	"d:\msdev\mcl\atl\include\atliface.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp".\Release\AtlCont.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	".\Release\atlcont.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "AtlCont - Win32 Debug"

DEP_CPP_STDAF=\
	"..\drawctl\drawctl.tlb"\
	".\StdAfx.h"\
	"d:\msdev\mcl\atl\include\atliface.h"\
	
CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\atlcont.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\atlcont.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "AtlCont - Win32 Unicode Release"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /GX /O1 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_MBCS" /D "_UNICODE" /Fp"$(INTDIR)\atlcont.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\atlcont.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "AtlCont - Win32 Unicode MinCRT"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /O1 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_MBCS" /D "_UNICODE" /Fp".\ReleaseU\AtlCont.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	".\ReleaseU\atlcont.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "AtlCont - Win32 Unicode Debug"

DEP_CPP_STDAF=\
	"..\drawctl\drawctl.tlb"\
	".\StdAfx.h"\
	"d:\msdev\mcl\atl\include\atliface.h"\
	
CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_MBCS" /D "_UNICODE" /Fp"$(INTDIR)\atlcont.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\atlcont.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\AtlCont1.h
SOURCE=.\StdAfx.h
SOURCE=.\AtlCont.rgs

!ENDIF 

