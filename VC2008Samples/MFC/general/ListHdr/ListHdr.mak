# Microsoft Developer Studio Generated NMAKE File, Based on ListHdr.dsp
!IF "$(CFG)" == ""
CFG=ListHdr - Win32 Debug Unicode
!MESSAGE No configuration specified. Defaulting to ListHdr - Win32 Debug Unicode.
!ENDIF 

!IF "$(CFG)" != "ListHdr - Win32 Release" && "$(CFG)" != "ListHdr - Win32 Debug" && "$(CFG)" != "ListHdr - Win32 Debug static" && "$(CFG)" != "ListHdr - Win32 Release static" && "$(CFG)" != "ListHdr - Win32 Debug Unicode" && "$(CFG)" != "ListHdr - Win32 Release Unicode"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ListHdr.mak" CFG="ListHdr - Win32 Debug Unicode"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ListHdr - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "ListHdr - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "ListHdr - Win32 Debug static" (based on "Win32 (x86) Application")
!MESSAGE "ListHdr - Win32 Release static" (based on "Win32 (x86) Application")
!MESSAGE "ListHdr - Win32 Debug Unicode" (based on "Win32 (x86) Application")
!MESSAGE "ListHdr - Win32 Release Unicode" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "ListHdr - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\ListHdr.exe"


CLEAN :
	-@erase "$(INTDIR)\LHdrDlg.obj"
	-@erase "$(INTDIR)\ListHdr.obj"
	-@erase "$(INTDIR)\ListHdr.pch"
	-@erase "$(INTDIR)\ListHdr.res"
	-@erase "$(INTDIR)\mlistctl.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\ListHdr.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\ListHdr.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o /win32 NUL 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ListHdr.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ListHdr.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\ListHdr.pdb" /machine:I386 /out:"$(OUTDIR)\ListHdr.exe" 
LINK32_OBJS= \
	"$(INTDIR)\LHdrDlg.obj" \
	"$(INTDIR)\ListHdr.obj" \
	"$(INTDIR)\mlistctl.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ListHdr.res"

"$(OUTDIR)\ListHdr.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ListHdr - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\ListHdr.exe"


CLEAN :
	-@erase "$(INTDIR)\LHdrDlg.obj"
	-@erase "$(INTDIR)\ListHdr.obj"
	-@erase "$(INTDIR)\ListHdr.pch"
	-@erase "$(INTDIR)\ListHdr.res"
	-@erase "$(INTDIR)\mlistctl.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\ListHdr.exe"
	-@erase "$(OUTDIR)\ListHdr.ilk"
	-@erase "$(OUTDIR)\ListHdr.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\ListHdr.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o /win32 NUL 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ListHdr.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ListHdr.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\ListHdr.pdb" /debug /machine:I386 /out:"$(OUTDIR)\ListHdr.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\LHdrDlg.obj" \
	"$(INTDIR)\ListHdr.obj" \
	"$(INTDIR)\mlistctl.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ListHdr.res"

"$(OUTDIR)\ListHdr.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ListHdr - Win32 Debug static"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\ListHdr.exe"


CLEAN :
	-@erase "$(INTDIR)\LHdrDlg.obj"
	-@erase "$(INTDIR)\ListHdr.obj"
	-@erase "$(INTDIR)\ListHdr.pch"
	-@erase "$(INTDIR)\ListHdr.res"
	-@erase "$(INTDIR)\mlistctl.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\ListHdr.exe"
	-@erase "$(OUTDIR)\ListHdr.ilk"
	-@erase "$(OUTDIR)\ListHdr.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\ListHdr.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o /win32 NUL 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ListHdr.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ListHdr.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\ListHdr.pdb" /debug /machine:I386 /out:"$(OUTDIR)\ListHdr.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\LHdrDlg.obj" \
	"$(INTDIR)\ListHdr.obj" \
	"$(INTDIR)\mlistctl.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ListHdr.res"

"$(OUTDIR)\ListHdr.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ListHdr - Win32 Release static"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\ListHdr.exe"


CLEAN :
	-@erase "$(INTDIR)\LHdrDlg.obj"
	-@erase "$(INTDIR)\ListHdr.obj"
	-@erase "$(INTDIR)\ListHdr.pch"
	-@erase "$(INTDIR)\ListHdr.res"
	-@erase "$(INTDIR)\mlistctl.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\ListHdr.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\ListHdr.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o /win32 NUL 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ListHdr.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ListHdr.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\ListHdr.pdb" /machine:I386 /out:"$(OUTDIR)\ListHdr.exe" 
LINK32_OBJS= \
	"$(INTDIR)\LHdrDlg.obj" \
	"$(INTDIR)\ListHdr.obj" \
	"$(INTDIR)\mlistctl.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ListHdr.res"

"$(OUTDIR)\ListHdr.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ListHdr - Win32 Debug Unicode"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\ListHdr.exe"


CLEAN :
	-@erase "$(INTDIR)\LHdrDlg.obj"
	-@erase "$(INTDIR)\ListHdr.obj"
	-@erase "$(INTDIR)\ListHdr.pch"
	-@erase "$(INTDIR)\ListHdr.res"
	-@erase "$(INTDIR)\mlistctl.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\ListHdr.exe"
	-@erase "$(OUTDIR)\ListHdr.ilk"
	-@erase "$(OUTDIR)\ListHdr.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /Fp"$(INTDIR)\ListHdr.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o /win32 NUL 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ListHdr.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ListHdr.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\ListHdr.pdb" /debug /machine:I386 /out:"$(OUTDIR)\ListHdr.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\LHdrDlg.obj" \
	"$(INTDIR)\ListHdr.obj" \
	"$(INTDIR)\mlistctl.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ListHdr.res"

"$(OUTDIR)\ListHdr.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ListHdr - Win32 Release Unicode"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\ListHdr.exe"


CLEAN :
	-@erase "$(INTDIR)\LHdrDlg.obj"
	-@erase "$(INTDIR)\ListHdr.obj"
	-@erase "$(INTDIR)\ListHdr.pch"
	-@erase "$(INTDIR)\ListHdr.res"
	-@erase "$(INTDIR)\mlistctl.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\ListHdr.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /Fp"$(INTDIR)\ListHdr.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o /win32 NUL 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ListHdr.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ListHdr.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\ListHdr.pdb" /machine:I386 /out:"$(OUTDIR)\ListHdr.exe" 
LINK32_OBJS= \
	"$(INTDIR)\LHdrDlg.obj" \
	"$(INTDIR)\ListHdr.obj" \
	"$(INTDIR)\mlistctl.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ListHdr.res"

"$(OUTDIR)\ListHdr.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("ListHdr.dep")
!INCLUDE "ListHdr.dep"
!ELSE 
!MESSAGE Warning: cannot find "ListHdr.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "ListHdr - Win32 Release" || "$(CFG)" == "ListHdr - Win32 Debug" || "$(CFG)" == "ListHdr - Win32 Debug static" || "$(CFG)" == "ListHdr - Win32 Release static" || "$(CFG)" == "ListHdr - Win32 Debug Unicode" || "$(CFG)" == "ListHdr - Win32 Release Unicode"
SOURCE=.\LHdrDlg.cpp

"$(INTDIR)\LHdrDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ListHdr.pch"


SOURCE=.\ListHdr.cpp

"$(INTDIR)\ListHdr.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ListHdr.pch"


SOURCE=.\ListHdr.rc

"$(INTDIR)\ListHdr.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\mlistctl.cpp

"$(INTDIR)\mlistctl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ListHdr.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "ListHdr - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\ListHdr.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ListHdr.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ListHdr - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\ListHdr.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ListHdr.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ListHdr - Win32 Debug static"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\ListHdr.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ListHdr.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ListHdr - Win32 Release static"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\ListHdr.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ListHdr.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ListHdr - Win32 Debug Unicode"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /Fp"$(INTDIR)\ListHdr.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ListHdr.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ListHdr - Win32 Release Unicode"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /Fp"$(INTDIR)\ListHdr.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ListHdr.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

