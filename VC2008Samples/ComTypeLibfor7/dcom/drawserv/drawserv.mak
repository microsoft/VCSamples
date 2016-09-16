# Microsoft Developer Studio Generated NMAKE File, Based on DrawServ.dsp
!IF "$(CFG)" == ""
CFG=DrawServ - Win32 Release
!MESSAGE No configuration specified. Defaulting to DrawServ - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "DrawServ - Win32 Release" && "$(CFG)" !=\
 "DrawServ - Win32 Debug" && "$(CFG)" != "DrawServ - Win32 Unicode Release" &&\
 "$(CFG)" != "DrawServ - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "DrawServ.mak" CFG="DrawServ - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DrawServ - Win32 Release" (based on "Win32 (x86) Win32 Application")
!MESSAGE "DrawServ - Win32 Debug" (based on "Win32 (x86) Win32 Application")
!MESSAGE "DrawServ - Win32 Unicode Release" (based on\
 "Win32 (x86) Win32 Application")
!MESSAGE "DrawServ - Win32 Unicode Debug" (based on\
 "Win32 (x86) Win32 Application")
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

!IF  "$(CFG)" == "DrawServ - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\DrawServ.exe" "$(OutDir)\reg_exe.trg"

!ELSE 

ALL : "$(OUTDIR)\DrawServ.exe" "$(OutDir)\reg_exe.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\DrawObj.obj"
	-@erase "$(INTDIR)\DrawServ.obj"
	-@erase "$(INTDIR)\DrawServ.res"
	-@erase "$(INTDIR)\predraw.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\DrawServ.exe"
	-@erase "$(OutDir)\reg_exe.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W4 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_MBCS" /D "_WIN32_DCOM" /Fp"$(INTDIR)\predraw.pch" /YX"predraw.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\DrawServ.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\DrawServ.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\DrawServ.pdb" /machine:I386 /out:"$(OUTDIR)\DrawServ.exe" 
LINK32_OBJS= \
	"$(INTDIR)\DrawObj.obj" \
	"$(INTDIR)\DrawServ.obj" \
	"$(INTDIR)\DrawServ.res" \
	"$(INTDIR)\predraw.obj"

"$(OUTDIR)\DrawServ.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\DrawServ.exe
InputPath=.\Release\DrawServ.exe
SOURCE=$(InputPath)

"$(OutDir)\reg_exe.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(TargetPath) /RegServer 
	echo reg_exe exec. time > "$(OutDir)\reg_exe.trg" 
	echo Server registration done! 
	

!ELSEIF  "$(CFG)" == "DrawServ - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\DrawServ.exe" "$(OUTDIR)\predraw.pch" "$(OUTDIR)\DrawServ.bsc"\
 "$(OutDir)\reg_exe.trg"

!ELSE 

ALL : "$(OUTDIR)\DrawServ.exe" "$(OUTDIR)\predraw.pch" "$(OUTDIR)\DrawServ.bsc"\
 "$(OutDir)\reg_exe.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\DrawObj.obj"
	-@erase "$(INTDIR)\DrawObj.sbr"
	-@erase "$(INTDIR)\DrawServ.obj"
	-@erase "$(INTDIR)\DrawServ.res"
	-@erase "$(INTDIR)\DrawServ.sbr"
	-@erase "$(INTDIR)\predraw.obj"
	-@erase "$(INTDIR)\predraw.pch"
	-@erase "$(INTDIR)\predraw.sbr"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\DrawServ.bsc"
	-@erase "$(OUTDIR)\DrawServ.exe"
	-@erase "$(OUTDIR)\DrawServ.ilk"
	-@erase "$(OUTDIR)\DrawServ.pdb"
	-@erase "$(OutDir)\reg_exe.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W4 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_MBCS" /D "_WIN32_DCOM" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\predraw.pch"\
 /YX"predraw.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\Debug/
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\DrawServ.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\DrawServ.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\DrawObj.sbr" \
	"$(INTDIR)\DrawServ.sbr" \
	"$(INTDIR)\predraw.sbr"

"$(OUTDIR)\DrawServ.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\DrawServ.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)\DrawServ.exe" 
LINK32_OBJS= \
	"$(INTDIR)\DrawObj.obj" \
	"$(INTDIR)\DrawServ.obj" \
	"$(INTDIR)\DrawServ.res" \
	"$(INTDIR)\predraw.obj"

"$(OUTDIR)\DrawServ.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\DrawServ.exe
InputPath=.\Debug\DrawServ.exe
SOURCE=$(InputPath)

"$(OutDir)\reg_exe.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(TargetPath) /RegServer 
	echo reg_exe exec. time > "$(OutDir)\reg_exe.trg" 
	echo Server registration done! 
	

!ELSEIF  "$(CFG)" == "DrawServ - Win32 Unicode Release"

OUTDIR=.\ReleaseU
INTDIR=.\ReleaseU
# Begin Custom Macros
OutDir=.\.\ReleaseU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\DrawServ.exe" "$(OutDir)\reg_exe.trg"

!ELSE 

ALL : "$(OUTDIR)\DrawServ.exe" "$(OutDir)\reg_exe.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\DrawObj.obj"
	-@erase "$(INTDIR)\DrawServ.obj"
	-@erase "$(INTDIR)\DrawServ.res"
	-@erase "$(INTDIR)\predraw.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\DrawServ.exe"
	-@erase "$(OutDir)\reg_exe.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W4 /GX /O2 /D "NDEBUG" /D "_UNICODE" /D "WIN32" /D\
 "_WINDOWS" /D "_MBCS" /D "_WIN32_DCOM" /Fp"$(INTDIR)\predraw.pch"\
 /YX"predraw.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\DrawServ.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\DrawServ.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows\
 /incremental:no /pdb:"$(OUTDIR)\DrawServ.pdb" /machine:I386\
 /out:"$(OUTDIR)\DrawServ.exe" 
LINK32_OBJS= \
	"$(INTDIR)\DrawObj.obj" \
	"$(INTDIR)\DrawServ.obj" \
	"$(INTDIR)\DrawServ.res" \
	"$(INTDIR)\predraw.obj"

"$(OUTDIR)\DrawServ.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\ReleaseU
TargetPath=.\ReleaseU\DrawServ.exe
InputPath=.\ReleaseU\DrawServ.exe
SOURCE=$(InputPath)

"$(OutDir)\reg_exe.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(TargetPath) /RegServer 
	echo reg_exe exec. time > "$(OutDir)\reg_exe.trg" 
	echo Server registration done! 
	

!ELSEIF  "$(CFG)" == "DrawServ - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\.\DebugU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\DrawServ.exe" "$(OutDir)\reg_exe.trg"

!ELSE 

ALL : "$(OUTDIR)\DrawServ.exe" "$(OutDir)\reg_exe.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\DrawObj.obj"
	-@erase "$(INTDIR)\DrawServ.obj"
	-@erase "$(INTDIR)\DrawServ.res"
	-@erase "$(INTDIR)\predraw.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\DrawServ.exe"
	-@erase "$(OUTDIR)\DrawServ.ilk"
	-@erase "$(OUTDIR)\DrawServ.pdb"
	-@erase "$(OutDir)\reg_exe.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W4 /Gm /GX /Zi /Od /D "_DEBUG" /D "_UNICODE" /D "WIN32"\
 /D "_WINDOWS" /D "_MBCS" /D "_WIN32_DCOM" /Fp"$(INTDIR)\predraw.pch"\
 /YX"predraw.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\DebugU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\DrawServ.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\DrawServ.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows\
 /incremental:yes /pdb:"$(OUTDIR)\DrawServ.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)\DrawServ.exe" 
LINK32_OBJS= \
	"$(INTDIR)\DrawObj.obj" \
	"$(INTDIR)\DrawServ.obj" \
	"$(INTDIR)\DrawServ.res" \
	"$(INTDIR)\predraw.obj"

"$(OUTDIR)\DrawServ.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\DebugU
TargetPath=.\DebugU\DrawServ.exe
InputPath=.\DebugU\DrawServ.exe
SOURCE=$(InputPath)

"$(OutDir)\reg_exe.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(TargetPath) /RegServer 
	echo reg_exe exec. time > "$(OutDir)\reg_exe.trg" 
	echo Server registration done! 
	

!ENDIF 

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


!IF "$(CFG)" == "DrawServ - Win32 Release" || "$(CFG)" ==\
 "DrawServ - Win32 Debug" || "$(CFG)" == "DrawServ - Win32 Unicode Release" ||\
 "$(CFG)" == "DrawServ - Win32 Unicode Debug"
SOURCE=.\DrawObj.cpp

!IF  "$(CFG)" == "DrawServ - Win32 Release"

DEP_CPP_DRAWO=\
	".\CPIDServ.h"\
	".\DrawObj.h"\
	".\DrawServ.h"\
	".\predraw.h"\
	"d:\msdev\mcl\atl\include\atliface.h"\
	

"$(INTDIR)\DrawObj.obj" : $(SOURCE) $(DEP_CPP_DRAWO) "$(INTDIR)" ".\DrawServ.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DrawServ - Win32 Debug"

DEP_CPP_DRAWO=\
	".\CPIDServ.h"\
	".\DrawObj.h"\
	".\DrawServ.h"\
	".\predraw.h"\
	"d:\msdev\mcl\atl\include\atliface.h"\
	

"$(INTDIR)\DrawObj.obj"	"$(INTDIR)\DrawObj.sbr" : $(SOURCE) $(DEP_CPP_DRAWO)\
 "$(INTDIR)" ".\DrawServ.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DrawServ - Win32 Unicode Release"

DEP_CPP_DRAWO=\
	".\CPIDServ.h"\
	".\DrawObj.h"\
	".\DrawServ.h"\
	".\predraw.h"\
	

"$(INTDIR)\DrawObj.obj" : $(SOURCE) $(DEP_CPP_DRAWO) "$(INTDIR)" ".\DrawServ.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DrawServ - Win32 Unicode Debug"

DEP_CPP_DRAWO=\
	".\CPIDServ.h"\
	".\DrawObj.h"\
	".\DrawServ.h"\
	".\predraw.h"\
	"d:\msdev\mcl\atl\include\atliface.h"\
	

"$(INTDIR)\DrawObj.obj" : $(SOURCE) $(DEP_CPP_DRAWO) "$(INTDIR)" ".\DrawServ.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\DrawObj.rgs
SOURCE=.\DrawServ.cpp

!IF  "$(CFG)" == "DrawServ - Win32 Release"

DEP_CPP_DRAWS=\
	".\CPIDServ.h"\
	".\DrawObj.h"\
	".\DrawServ.h"\
	".\DrawServ_i.c"\
	".\predraw.h"\
	"d:\msdev\mcl\atl\include\atliface.h"\
	

"$(INTDIR)\DrawServ.obj" : $(SOURCE) $(DEP_CPP_DRAWS) "$(INTDIR)"\
 ".\DrawServ.h" ".\DrawServ_i.c"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DrawServ - Win32 Debug"

DEP_CPP_DRAWS=\
	".\CPIDServ.h"\
	".\DrawObj.h"\
	".\DrawServ.h"\
	".\DrawServ_i.c"\
	".\predraw.h"\
	"d:\msdev\mcl\atl\include\atliface.h"\
	

"$(INTDIR)\DrawServ.obj"	"$(INTDIR)\DrawServ.sbr" : $(SOURCE) $(DEP_CPP_DRAWS)\
 "$(INTDIR)" ".\DrawServ_i.c" ".\DrawServ.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DrawServ - Win32 Unicode Release"

DEP_CPP_DRAWS=\
	".\CPIDServ.h"\
	".\DrawObj.h"\
	".\DrawServ.h"\
	".\DrawServ_i.c"\
	".\predraw.h"\
	

"$(INTDIR)\DrawServ.obj" : $(SOURCE) $(DEP_CPP_DRAWS) "$(INTDIR)"\
 ".\DrawServ.h" ".\DrawServ_i.c"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DrawServ - Win32 Unicode Debug"

DEP_CPP_DRAWS=\
	".\CPIDServ.h"\
	".\DrawObj.h"\
	".\DrawServ.h"\
	".\DrawServ_i.c"\
	".\predraw.h"\
	"d:\msdev\mcl\atl\include\atliface.h"\
	

"$(INTDIR)\DrawServ.obj" : $(SOURCE) $(DEP_CPP_DRAWS) "$(INTDIR)"\
 ".\DrawServ.h" ".\DrawServ_i.c"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\DrawServ.idl

!IF  "$(CFG)" == "DrawServ - Win32 Release"

InputPath=.\DrawServ.idl

"DrawServ.tlb"	"DrawServ.h"	"DrawServ_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl DrawServ.idl

!ELSEIF  "$(CFG)" == "DrawServ - Win32 Debug"

InputPath=.\DrawServ.idl

"DrawServ.tlb"	"DrawServ.h"	"DrawServ_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl DrawServ.idl

!ELSEIF  "$(CFG)" == "DrawServ - Win32 Unicode Release"

InputPath=.\DrawServ.idl

"DrawServ.tlb"	"DrawServ.h"	"DrawServ_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl DrawServ.idl

!ELSEIF  "$(CFG)" == "DrawServ - Win32 Unicode Debug"

InputPath=.\DrawServ.idl

"DrawServ.tlb"	"DrawServ.h"	"DrawServ_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl DrawServ.idl

!ENDIF 

SOURCE=.\DrawServ.rc
DEP_RSC_DRAWSE=\
	".\DrawObj.rgs"\
	".\DrawServ.rgs"\
	".\DrawServ.tlb"\
	

!IF  "$(CFG)" == "DrawServ - Win32 Release"


"$(INTDIR)\DrawServ.res" : $(SOURCE) $(DEP_RSC_DRAWSE) "$(INTDIR)"\
 ".\DrawServ.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DrawServ - Win32 Debug"


"$(INTDIR)\DrawServ.res" : $(SOURCE) $(DEP_RSC_DRAWSE) "$(INTDIR)"\
 ".\DrawServ.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DrawServ - Win32 Unicode Release"


"$(INTDIR)\DrawServ.res" : $(SOURCE) $(DEP_RSC_DRAWSE) "$(INTDIR)"\
 ".\DrawServ.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "DrawServ - Win32 Unicode Debug"


"$(INTDIR)\DrawServ.res" : $(SOURCE) $(DEP_RSC_DRAWSE) "$(INTDIR)"\
 ".\DrawServ.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\DrawServ.rgs
SOURCE=.\predraw.cpp

!IF  "$(CFG)" == "DrawServ - Win32 Release"

DEP_CPP_PREDR=\
	".\predraw.h"\
	"d:\msdev\mcl\atl\include\atliface.h"\
	
CPP_SWITCHES=/nologo /MT /W4 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_MBCS" /D "_WIN32_DCOM" /Fp"$(INTDIR)\predraw.pch" /YX"predraw.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\predraw.obj" : $(SOURCE) $(DEP_CPP_PREDR) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DrawServ - Win32 Debug"

DEP_CPP_PREDR=\
	".\predraw.h"\
	"d:\msdev\mcl\atl\include\atliface.h"\
	
CPP_SWITCHES=/nologo /MTd /W4 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_MBCS" /D "_WIN32_DCOM" /FR"$(INTDIR)\\"\
 /Fp"$(INTDIR)\predraw.pch" /Yc /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\predraw.obj"	"$(INTDIR)\predraw.sbr"	"$(INTDIR)\predraw.pch" : \
$(SOURCE) $(DEP_CPP_PREDR) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DrawServ - Win32 Unicode Release"

DEP_CPP_PREDR=\
	".\predraw.h"\
	
CPP_SWITCHES=/nologo /MT /W4 /GX /O2 /D "NDEBUG" /D "_UNICODE" /D "WIN32" /D\
 "_WINDOWS" /D "_MBCS" /D "_WIN32_DCOM" /Fp"$(INTDIR)\predraw.pch"\
 /YX"predraw.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\predraw.obj" : $(SOURCE) $(DEP_CPP_PREDR) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DrawServ - Win32 Unicode Debug"

DEP_CPP_PREDR=\
	".\predraw.h"\
	"d:\msdev\mcl\atl\include\atliface.h"\
	
CPP_SWITCHES=/nologo /MTd /W4 /Gm /GX /Zi /Od /D "_DEBUG" /D "_UNICODE" /D\
 "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_WIN32_DCOM" /Fp"$(INTDIR)\predraw.pch"\
 /YX"predraw.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\predraw.obj" : $(SOURCE) $(DEP_CPP_PREDR) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\CPIDServ.h
SOURCE=.\DrawObj.h
SOURCE=.\predraw.h

!ENDIF 

