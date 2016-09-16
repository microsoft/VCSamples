# Microsoft Developer Studio Generated NMAKE File, Based on xlist.dsp
!IF "$(CFG)" == ""
CFG=XList - Win32 Release
!MESSAGE No configuration specified. Defaulting to XList - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "XList - Win32 Release" && "$(CFG)" != "XList - Win32 Debug" && "$(CFG)" != "XList - Win32 Unicode Debug" && "$(CFG)" != "XList - Win32 Unicode Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "xlist.mak" CFG="XList - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "XList - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "XList - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "XList - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "XList - Win32 Unicode Release" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "XList - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\xlist.ocx" ".\.\Release\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\xlist.obj"
	-@erase "$(INTDIR)\xlist.pch"
	-@erase "$(INTDIR)\xlist.res"
	-@erase "$(INTDIR)\xlist.tlb"
	-@erase "$(INTDIR)\xlistctl.obj"
	-@erase "$(INTDIR)\xlistppg.obj"
	-@erase "$(OUTDIR)\xlist.exp"
	-@erase "$(OUTDIR)\xlist.lib"
	-@erase "$(OUTDIR)\xlist.ocx"
	-@erase ".\.\Release\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\xlist.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\xlist.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\xlist.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\xlist.pdb" /machine:I386 /def:".\xlist.def" /out:"$(OUTDIR)\xlist.ocx" /implib:"$(OUTDIR)\xlist.lib" 
DEF_FILE= \
	".\xlist.def"
LINK32_OBJS= \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\xlist.obj" \
	"$(INTDIR)\xlistctl.obj" \
	"$(INTDIR)\xlistppg.obj" \
	"$(INTDIR)\xlist.res"

"$(OUTDIR)\xlist.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\xlist.ocx
InputPath=.\Release\xlist.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "XList - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\xlist.ocx" ".\.\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\xlist.obj"
	-@erase "$(INTDIR)\xlist.pch"
	-@erase "$(INTDIR)\xlist.res"
	-@erase "$(INTDIR)\xlist.tlb"
	-@erase "$(INTDIR)\xlistctl.obj"
	-@erase "$(INTDIR)\xlistppg.obj"
	-@erase "$(OUTDIR)\xlist.exp"
	-@erase "$(OUTDIR)\xlist.ilk"
	-@erase "$(OUTDIR)\xlist.lib"
	-@erase "$(OUTDIR)\xlist.ocx"
	-@erase "$(OUTDIR)\xlist.pdb"
	-@erase ".\.\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\xlist.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\xlist.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\xlist.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\xlist.pdb" /debug /machine:I386 /def:".\xlist.def" /out:"$(OUTDIR)\xlist.ocx" /implib:"$(OUTDIR)\xlist.lib" 
DEF_FILE= \
	".\xlist.def"
LINK32_OBJS= \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\xlist.obj" \
	"$(INTDIR)\xlistctl.obj" \
	"$(INTDIR)\xlistppg.obj" \
	"$(INTDIR)\xlist.res"

"$(OUTDIR)\xlist.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\xlist.ocx
InputPath=.\Debug\xlist.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "XList - Win32 Unicode Debug"

OUTDIR=.\UniDebug
INTDIR=.\UniDebug
# Begin Custom Macros
OutDir=.\.\UniDebug
# End Custom Macros

ALL : "$(OUTDIR)\xlist.ocx" ".\.\UniDebug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\xlist.obj"
	-@erase "$(INTDIR)\xlist.pch"
	-@erase "$(INTDIR)\xlist.res"
	-@erase "$(INTDIR)\xlist.tlb"
	-@erase "$(INTDIR)\xlistctl.obj"
	-@erase "$(INTDIR)\xlistppg.obj"
	-@erase "$(OUTDIR)\xlist.exp"
	-@erase "$(OUTDIR)\xlist.ilk"
	-@erase "$(OUTDIR)\xlist.lib"
	-@erase "$(OUTDIR)\xlist.ocx"
	-@erase "$(OUTDIR)\xlist.pdb"
	-@erase ".\.\UniDebug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\xlist.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\xlist.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\xlist.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\xlist.pdb" /debug /machine:I386 /def:".\xlist.def" /out:"$(OUTDIR)\xlist.ocx" /implib:"$(OUTDIR)\xlist.lib" 
DEF_FILE= \
	".\xlist.def"
LINK32_OBJS= \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\xlist.obj" \
	"$(INTDIR)\xlistctl.obj" \
	"$(INTDIR)\xlistppg.obj" \
	"$(INTDIR)\xlist.res"

"$(OUTDIR)\xlist.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\UniDebug
TargetPath=.\UniDebug\xlist.ocx
InputPath=.\UniDebug\xlist.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "XList - Win32 Unicode Release"

OUTDIR=.\UniRelease
INTDIR=.\UniRelease
# Begin Custom Macros
OutDir=.\.\UniRelease
# End Custom Macros

ALL : "$(OUTDIR)\xlist.ocx" ".\.\UniRelease\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\xlist.obj"
	-@erase "$(INTDIR)\xlist.pch"
	-@erase "$(INTDIR)\xlist.res"
	-@erase "$(INTDIR)\xlist.tlb"
	-@erase "$(INTDIR)\xlistctl.obj"
	-@erase "$(INTDIR)\xlistppg.obj"
	-@erase "$(OUTDIR)\xlist.exp"
	-@erase "$(OUTDIR)\xlist.lib"
	-@erase "$(OUTDIR)\xlist.ocx"
	-@erase ".\.\UniRelease\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\xlist.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\xlist.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\xlist.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\xlist.pdb" /machine:I386 /def:".\xlist.def" /out:"$(OUTDIR)\xlist.ocx" /implib:"$(OUTDIR)\xlist.lib" 
DEF_FILE= \
	".\xlist.def"
LINK32_OBJS= \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\xlist.obj" \
	"$(INTDIR)\xlistctl.obj" \
	"$(INTDIR)\xlistppg.obj" \
	"$(INTDIR)\xlist.res"

"$(OUTDIR)\xlist.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\UniRelease
TargetPath=.\UniRelease\xlist.ocx
InputPath=.\UniRelease\xlist.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
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
!IF EXISTS("xlist.dep")
!INCLUDE "xlist.dep"
!ELSE 
!MESSAGE Warning: cannot find "xlist.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "XList - Win32 Release" || "$(CFG)" == "XList - Win32 Debug" || "$(CFG)" == "XList - Win32 Unicode Debug" || "$(CFG)" == "XList - Win32 Unicode Release"
SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "XList - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\xlist.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\xlist.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "XList - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\xlist.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\xlist.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "XList - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\xlist.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\xlist.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "XList - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /Fp"$(INTDIR)\xlist.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\xlist.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\xlist.cpp

"$(INTDIR)\xlist.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\xlist.pch"


SOURCE=.\xlist.odl

!IF  "$(CFG)" == "XList - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\xlist.tlb" /mktyplib203 /win32 

"$(OUTDIR)\xlist.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "XList - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\xlist.tlb" /mktyplib203 /win32 

"$(OUTDIR)\xlist.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "XList - Win32 Unicode Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\xlist.tlb" /mktyplib203 /win32 

"$(OUTDIR)\xlist.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "XList - Win32 Unicode Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\xlist.tlb" /mktyplib203 /win32 

"$(OUTDIR)\xlist.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\xlist.rc

!IF  "$(CFG)" == "XList - Win32 Release"


"$(INTDIR)\xlist.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\xlist.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\xlist.res" /i ".\Release" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "XList - Win32 Debug"


"$(INTDIR)\xlist.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\xlist.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\xlist.res" /i ".\Debug" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "XList - Win32 Unicode Debug"


"$(INTDIR)\xlist.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\xlist.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\xlist.res" /i ".\UniDebug" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "XList - Win32 Unicode Release"


"$(INTDIR)\xlist.res" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\xlist.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\xlist.res" /i ".\UniRelease" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ENDIF 

SOURCE=.\xlistctl.cpp

"$(INTDIR)\xlistctl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\xlist.pch"


SOURCE=.\xlistppg.cpp

"$(INTDIR)\xlistppg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\xlist.pch"



!ENDIF 

