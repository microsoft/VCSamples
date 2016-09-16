# Microsoft Developer Studio Generated NMAKE File, Based on DBVList.dsp
!IF "$(CFG)" == ""
CFG=DBVList - Win32 Debug Unicode
!MESSAGE No configuration specified. Defaulting to DBVList - Win32 Debug Unicode.
!ENDIF 

!IF "$(CFG)" != "DBVList - Win32 Release" && "$(CFG)" != "DBVList - Win32 Debug" && "$(CFG)" != "DBVList - Win32 Debug Static" && "$(CFG)" != "DBVList - Win32 Release Static" && "$(CFG)" != "DBVList - Win32 Debug Unicode" && "$(CFG)" != "DBVList - Win32 Release Unicode"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "DBVList.mak" CFG="DBVList - Win32 Debug Unicode"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DBVList - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "DBVList - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "DBVList - Win32 Debug Static" (based on "Win32 (x86) Application")
!MESSAGE "DBVList - Win32 Release Static" (based on "Win32 (x86) Application")
!MESSAGE "DBVList - Win32 Debug Unicode" (based on "Win32 (x86) Application")
!MESSAGE "DBVList - Win32 Release Unicode" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "DBVList - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\DBVList.exe"


CLEAN :
	-@erase "$(INTDIR)\DBVList.obj"
	-@erase "$(INTDIR)\DBVList.pch"
	-@erase "$(INTDIR)\DBVList.res"
	-@erase "$(INTDIR)\DBVListDoc.obj"
	-@erase "$(INTDIR)\DBVListSet.obj"
	-@erase "$(INTDIR)\DBVListView.obj"
	-@erase "$(INTDIR)\EmpView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\DBVList.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\DBVList.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\DBVList.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\DBVList.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\DBVList.pdb" /machine:I386 /out:"$(OUTDIR)\DBVList.exe" 
LINK32_OBJS= \
	"$(INTDIR)\DBVList.obj" \
	"$(INTDIR)\DBVListDoc.obj" \
	"$(INTDIR)\DBVListSet.obj" \
	"$(INTDIR)\DBVListView.obj" \
	"$(INTDIR)\EmpView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\DBVList.res"

"$(OUTDIR)\DBVList.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "DBVList - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\DBVList.exe"


CLEAN :
	-@erase "$(INTDIR)\DBVList.obj"
	-@erase "$(INTDIR)\DBVList.pch"
	-@erase "$(INTDIR)\DBVList.res"
	-@erase "$(INTDIR)\DBVListDoc.obj"
	-@erase "$(INTDIR)\DBVListSet.obj"
	-@erase "$(INTDIR)\DBVListView.obj"
	-@erase "$(INTDIR)\EmpView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\DBVList.exe"
	-@erase "$(OUTDIR)\DBVList.ilk"
	-@erase "$(OUTDIR)\DBVList.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\DBVList.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\DBVList.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\DBVList.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\DBVList.pdb" /debug /machine:I386 /out:"$(OUTDIR)\DBVList.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\DBVList.obj" \
	"$(INTDIR)\DBVListDoc.obj" \
	"$(INTDIR)\DBVListSet.obj" \
	"$(INTDIR)\DBVListView.obj" \
	"$(INTDIR)\EmpView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\DBVList.res"

"$(OUTDIR)\DBVList.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "DBVList - Win32 Debug Static"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\DBVList.exe"


CLEAN :
	-@erase "$(INTDIR)\DBVList.obj"
	-@erase "$(INTDIR)\DBVList.pch"
	-@erase "$(INTDIR)\DBVList.res"
	-@erase "$(INTDIR)\DBVListDoc.obj"
	-@erase "$(INTDIR)\DBVListSet.obj"
	-@erase "$(INTDIR)\DBVListView.obj"
	-@erase "$(INTDIR)\EmpView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\DBVList.exe"
	-@erase "$(OUTDIR)\DBVList.ilk"
	-@erase "$(OUTDIR)\DBVList.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\DBVList.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\DBVList.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\DBVList.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\DBVList.pdb" /debug /machine:I386 /out:"$(OUTDIR)\DBVList.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\DBVList.obj" \
	"$(INTDIR)\DBVListDoc.obj" \
	"$(INTDIR)\DBVListSet.obj" \
	"$(INTDIR)\DBVListView.obj" \
	"$(INTDIR)\EmpView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\DBVList.res"

"$(OUTDIR)\DBVList.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "DBVList - Win32 Release Static"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\DBVList.exe"


CLEAN :
	-@erase "$(INTDIR)\DBVList.obj"
	-@erase "$(INTDIR)\DBVList.pch"
	-@erase "$(INTDIR)\DBVList.res"
	-@erase "$(INTDIR)\DBVListDoc.obj"
	-@erase "$(INTDIR)\DBVListSet.obj"
	-@erase "$(INTDIR)\DBVListView.obj"
	-@erase "$(INTDIR)\EmpView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\DBVList.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\DBVList.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\DBVList.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\DBVList.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\DBVList.pdb" /machine:I386 /out:"$(OUTDIR)\DBVList.exe" 
LINK32_OBJS= \
	"$(INTDIR)\DBVList.obj" \
	"$(INTDIR)\DBVListDoc.obj" \
	"$(INTDIR)\DBVListSet.obj" \
	"$(INTDIR)\DBVListView.obj" \
	"$(INTDIR)\EmpView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\DBVList.res"

"$(OUTDIR)\DBVList.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "DBVList - Win32 Debug Unicode"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\DBVList.exe"


CLEAN :
	-@erase "$(INTDIR)\DBVList.obj"
	-@erase "$(INTDIR)\DBVList.pch"
	-@erase "$(INTDIR)\DBVList.res"
	-@erase "$(INTDIR)\DBVListDoc.obj"
	-@erase "$(INTDIR)\DBVListSet.obj"
	-@erase "$(INTDIR)\DBVListView.obj"
	-@erase "$(INTDIR)\EmpView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\DBVList.exe"
	-@erase "$(OUTDIR)\DBVList.ilk"
	-@erase "$(OUTDIR)\DBVList.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /Fp"$(INTDIR)\DBVList.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\DBVList.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\DBVList.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\DBVList.pdb" /debug /machine:I386 /out:"$(OUTDIR)\DBVList.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\DBVList.obj" \
	"$(INTDIR)\DBVListDoc.obj" \
	"$(INTDIR)\DBVListSet.obj" \
	"$(INTDIR)\DBVListView.obj" \
	"$(INTDIR)\EmpView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\DBVList.res"

"$(OUTDIR)\DBVList.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "DBVList - Win32 Release Unicode"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\DBVList.exe"


CLEAN :
	-@erase "$(INTDIR)\DBVList.obj"
	-@erase "$(INTDIR)\DBVList.pch"
	-@erase "$(INTDIR)\DBVList.res"
	-@erase "$(INTDIR)\DBVListDoc.obj"
	-@erase "$(INTDIR)\DBVListSet.obj"
	-@erase "$(INTDIR)\DBVListView.obj"
	-@erase "$(INTDIR)\EmpView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\DBVList.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /Fp"$(INTDIR)\DBVList.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\DBVList.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\DBVList.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\DBVList.pdb" /machine:I386 /out:"$(OUTDIR)\DBVList.exe" 
LINK32_OBJS= \
	"$(INTDIR)\DBVList.obj" \
	"$(INTDIR)\DBVListDoc.obj" \
	"$(INTDIR)\DBVListSet.obj" \
	"$(INTDIR)\DBVListView.obj" \
	"$(INTDIR)\EmpView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\DBVList.res"

"$(OUTDIR)\DBVList.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("DBVList.dep")
!INCLUDE "DBVList.dep"
!ELSE 
!MESSAGE Warning: cannot find "DBVList.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "DBVList - Win32 Release" || "$(CFG)" == "DBVList - Win32 Debug" || "$(CFG)" == "DBVList - Win32 Debug Static" || "$(CFG)" == "DBVList - Win32 Release Static" || "$(CFG)" == "DBVList - Win32 Debug Unicode" || "$(CFG)" == "DBVList - Win32 Release Unicode"
SOURCE=.\DBVList.cpp

"$(INTDIR)\DBVList.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\DBVList.pch"


SOURCE=.\DBVList.rc

"$(INTDIR)\DBVList.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\DBVListDoc.cpp

"$(INTDIR)\DBVListDoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\DBVList.pch"


SOURCE=.\DBVListSet.cpp

"$(INTDIR)\DBVListSet.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\DBVList.pch"


SOURCE=.\DBVListView.cpp

"$(INTDIR)\DBVListView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\DBVList.pch"


SOURCE=.\EmpView.cpp

"$(INTDIR)\EmpView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\DBVList.pch"


SOURCE=.\MainFrm.cpp

"$(INTDIR)\MainFrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\DBVList.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "DBVList - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\DBVList.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\DBVList.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DBVList - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\DBVList.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\DBVList.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DBVList - Win32 Debug Static"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\DBVList.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\DBVList.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DBVList - Win32 Release Static"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\DBVList.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\DBVList.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DBVList - Win32 Debug Unicode"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /Fp"$(INTDIR)\DBVList.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\DBVList.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DBVList - Win32 Release Unicode"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /Fp"$(INTDIR)\DBVList.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\DBVList.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

