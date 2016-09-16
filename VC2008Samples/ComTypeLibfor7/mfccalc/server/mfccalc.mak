# Microsoft Developer Studio Generated NMAKE File, Based on mfccalc.dsp
!IF "$(CFG)" == ""
CFG=MfcCalc - Win32 Release
!MESSAGE No configuration specified.  Defaulting to MfcCalc - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "MfcCalc - Win32 Release" && "$(CFG)" !=\
 "MfcCalc - Win32 Debug" && "$(CFG)" != "MfcCalc - Win32 Unicode Release" &&\
 "$(CFG)" != "MfcCalc - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "mfccalc.mak" CFG="MfcCalc - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MfcCalc - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "MfcCalc - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "MfcCalc - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "MfcCalc - Win32 Unicode Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "MfcCalc - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\mfccalc.exe" "$(OUTDIR)\mfccalc.tlb"

CLEAN : 
	-@erase "$(INTDIR)\calcdlg.obj"
	-@erase "$(INTDIR)\mfccalc.obj"
	-@erase "$(INTDIR)\mfccalc.pch"
	-@erase "$(INTDIR)\mfccalc.res"
	-@erase "$(INTDIR)\mfccalc.tlb"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\mfccalc.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfccalc.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\mfccalc.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mfccalc.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\mfccalc.pdb" /machine:I386 /out:"$(OUTDIR)\mfccalc.exe" 
LINK32_OBJS= \
	"$(INTDIR)\calcdlg.obj" \
	"$(INTDIR)\mfccalc.obj" \
	"$(INTDIR)\mfccalc.res" \
	"$(INTDIR)\stdafx.obj"

"$(OUTDIR)\mfccalc.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MfcCalc - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\mfccalc.exe" "$(OUTDIR)\mfccalc.tlb"

CLEAN : 
	-@erase "$(INTDIR)\calcdlg.obj"
	-@erase "$(INTDIR)\mfccalc.obj"
	-@erase "$(INTDIR)\mfccalc.pch"
	-@erase "$(INTDIR)\mfccalc.res"
	-@erase "$(INTDIR)\mfccalc.tlb"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\mfccalc.exe"
	-@erase "$(OUTDIR)\mfccalc.ilk"
	-@erase "$(OUTDIR)\mfccalc.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfccalc.pch" /Yu"Stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\mfccalc.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mfccalc.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\mfccalc.pdb" /debug /machine:I386 /out:"$(OUTDIR)\mfccalc.exe" 
LINK32_OBJS= \
	"$(INTDIR)\calcdlg.obj" \
	"$(INTDIR)\mfccalc.obj" \
	"$(INTDIR)\mfccalc.res" \
	"$(INTDIR)\stdafx.obj"

"$(OUTDIR)\mfccalc.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MfcCalc - Win32 Unicode Release"

OUTDIR=.\UniRelease
INTDIR=.\UniRelease
# Begin Custom Macros
OutDir=.\.\UniRelease
# End Custom Macros

ALL : "$(OUTDIR)\mfccalc.exe" "$(OUTDIR)\mfccalc.tlb"

CLEAN : 
	-@erase "$(INTDIR)\calcdlg.obj"
	-@erase "$(INTDIR)\mfccalc.obj"
	-@erase "$(INTDIR)\mfccalc.pch"
	-@erase "$(INTDIR)\mfccalc.res"
	-@erase "$(INTDIR)\mfccalc.tlb"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\mfccalc.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfccalc.pch" /Yu"Stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\UniRelease/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\mfccalc.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mfccalc.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows\
 /incremental:no /pdb:"$(OUTDIR)\mfccalc.pdb" /machine:I386\
 /out:"$(OUTDIR)\mfccalc.exe" 
LINK32_OBJS= \
	"$(INTDIR)\calcdlg.obj" \
	"$(INTDIR)\mfccalc.obj" \
	"$(INTDIR)\mfccalc.res" \
	"$(INTDIR)\stdafx.obj"

"$(OUTDIR)\mfccalc.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MfcCalc - Win32 Unicode Debug"

OUTDIR=.\UniDebug
INTDIR=.\UniDebug
# Begin Custom Macros
OutDir=.\.\UniDebug
# End Custom Macros

ALL : "$(OUTDIR)\mfccalc.exe" "$(OUTDIR)\mfccalc.tlb"

CLEAN : 
	-@erase "$(INTDIR)\calcdlg.obj"
	-@erase "$(INTDIR)\mfccalc.obj"
	-@erase "$(INTDIR)\mfccalc.pch"
	-@erase "$(INTDIR)\mfccalc.res"
	-@erase "$(INTDIR)\mfccalc.tlb"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\mfccalc.exe"
	-@erase "$(OUTDIR)\mfccalc.ilk"
	-@erase "$(OUTDIR)\mfccalc.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfccalc.pch" /Yu"Stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\UniDebug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\mfccalc.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mfccalc.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows\
 /incremental:yes /pdb:"$(OUTDIR)\mfccalc.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)\mfccalc.exe" 
LINK32_OBJS= \
	"$(INTDIR)\calcdlg.obj" \
	"$(INTDIR)\mfccalc.obj" \
	"$(INTDIR)\mfccalc.res" \
	"$(INTDIR)\stdafx.obj"

"$(OUTDIR)\mfccalc.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj::
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr::
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) $(CPP_PROJ) $<  


!IF "$(CFG)" == "MfcCalc - Win32 Release" || "$(CFG)" ==\
 "MfcCalc - Win32 Debug" || "$(CFG)" == "MfcCalc - Win32 Unicode Release" ||\
 "$(CFG)" == "MfcCalc - Win32 Unicode Debug"
SOURCE=.\calcdlg.cpp

!IF  "$(CFG)" == "MfcCalc - Win32 Release"

DEP_CPP_CALCD=\
	".\calcdlg.h"\
	".\mfccalc.h"\
	

"$(INTDIR)\calcdlg.obj" : $(SOURCE) $(DEP_CPP_CALCD) "$(INTDIR)"\
 "$(INTDIR)\mfccalc.pch"


!ELSEIF  "$(CFG)" == "MfcCalc - Win32 Debug"

DEP_CPP_CALCD=\
	".\calcdlg.h"\
	".\mfccalc.h"\
	

"$(INTDIR)\calcdlg.obj" : $(SOURCE) $(DEP_CPP_CALCD) "$(INTDIR)"\
 "$(INTDIR)\mfccalc.pch"


!ELSEIF  "$(CFG)" == "MfcCalc - Win32 Unicode Release"

DEP_CPP_CALCD=\
	".\calcdlg.h"\
	".\mfccalc.h"\
	

"$(INTDIR)\calcdlg.obj" : $(SOURCE) $(DEP_CPP_CALCD) "$(INTDIR)"\
 "$(INTDIR)\mfccalc.pch"


!ELSEIF  "$(CFG)" == "MfcCalc - Win32 Unicode Debug"

DEP_CPP_CALCD=\
	".\calcdlg.h"\
	".\mfccalc.h"\
	

"$(INTDIR)\calcdlg.obj" : $(SOURCE) $(DEP_CPP_CALCD) "$(INTDIR)"\
 "$(INTDIR)\mfccalc.pch"


!ENDIF 

SOURCE=.\mfccalc.cpp

!IF  "$(CFG)" == "MfcCalc - Win32 Release"

DEP_CPP_MFCCA=\
	".\calcdlg.h"\
	".\mfccalc.h"\
	

"$(INTDIR)\mfccalc.obj" : $(SOURCE) $(DEP_CPP_MFCCA) "$(INTDIR)"\
 "$(INTDIR)\mfccalc.pch"


!ELSEIF  "$(CFG)" == "MfcCalc - Win32 Debug"

DEP_CPP_MFCCA=\
	".\calcdlg.h"\
	".\mfccalc.h"\
	

"$(INTDIR)\mfccalc.obj" : $(SOURCE) $(DEP_CPP_MFCCA) "$(INTDIR)"\
 "$(INTDIR)\mfccalc.pch"


!ELSEIF  "$(CFG)" == "MfcCalc - Win32 Unicode Release"

DEP_CPP_MFCCA=\
	".\calcdlg.h"\
	".\mfccalc.h"\
	

"$(INTDIR)\mfccalc.obj" : $(SOURCE) $(DEP_CPP_MFCCA) "$(INTDIR)"\
 "$(INTDIR)\mfccalc.pch"


!ELSEIF  "$(CFG)" == "MfcCalc - Win32 Unicode Debug"

DEP_CPP_MFCCA=\
	".\calcdlg.h"\
	".\mfccalc.h"\
	

"$(INTDIR)\mfccalc.obj" : $(SOURCE) $(DEP_CPP_MFCCA) "$(INTDIR)"\
 "$(INTDIR)\mfccalc.pch"


!ENDIF 

SOURCE=.\mfccalc.odl

!IF  "$(CFG)" == "MfcCalc - Win32 Release"


"$(OUTDIR)\mfccalc.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) /nologo /D "NDEBUG" /tlb "$(OUTDIR)\mfccalc.tlb" /mktyplib203 /win32\
 $(SOURCE)


!ELSEIF  "$(CFG)" == "MfcCalc - Win32 Debug"


"$(OUTDIR)\mfccalc.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) /nologo /D "_DEBUG" /tlb "$(OUTDIR)\mfccalc.tlb" /mktyplib203 /win32\
 $(SOURCE)


!ELSEIF  "$(CFG)" == "MfcCalc - Win32 Unicode Release"


"$(OUTDIR)\mfccalc.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) /nologo /D "NDEBUG" /tlb "$(OUTDIR)\mfccalc.tlb" /mktyplib203 /win32\
 $(SOURCE)


!ELSEIF  "$(CFG)" == "MfcCalc - Win32 Unicode Debug"


"$(OUTDIR)\mfccalc.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) /nologo /D "_DEBUG" /tlb "$(OUTDIR)\mfccalc.tlb" /mktyplib203 /win32\
 $(SOURCE)


!ENDIF 

SOURCE=.\mfccalc.rc
DEP_RSC_MFCCAL=\
	".\res\mfccalc.ico"\
	".\res\mfccalc.rc2"\
	

!IF  "$(CFG)" == "MfcCalc - Win32 Release"


"$(INTDIR)\mfccalc.res" : $(SOURCE) $(DEP_RSC_MFCCAL) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\mfccalc.res" /i ".\Release" /d "NDEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "MfcCalc - Win32 Debug"


"$(INTDIR)\mfccalc.res" : $(SOURCE) $(DEP_RSC_MFCCAL) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\mfccalc.res" /i ".\Debug" /d "_DEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "MfcCalc - Win32 Unicode Release"


"$(INTDIR)\mfccalc.res" : $(SOURCE) $(DEP_RSC_MFCCAL) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\mfccalc.res" /i ".\UniRelease" /d "NDEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "MfcCalc - Win32 Unicode Debug"


"$(INTDIR)\mfccalc.res" : $(SOURCE) $(DEP_RSC_MFCCAL) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\mfccalc.res" /i ".\UniDebug" /d "_DEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ENDIF 

SOURCE=.\stdafx.cpp

!IF  "$(CFG)" == "MfcCalc - Win32 Release"


"$(INTDIR)\stdafx.obj"	"$(INTDIR)\mfccalc.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfccalc.pch" /Yc /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ELSEIF  "$(CFG)" == "MfcCalc - Win32 Debug"

DEP_CPP_STDAF=\
	".\stdafx.h"\
	"d:\msdev\include\zmouse.h"\
	

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\mfccalc.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfccalc.pch" /Yc /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ELSEIF  "$(CFG)" == "MfcCalc - Win32 Unicode Release"

DEP_CPP_STDAF=\
	".\stdafx.h"\
	"d:\msdev\include\zmouse.h"\
	

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\mfccalc.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfccalc.pch" /Yc\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ELSEIF  "$(CFG)" == "MfcCalc - Win32 Unicode Debug"

DEP_CPP_STDAF=\
	".\stdafx.h"\
	"d:\msdev\include\zmouse.h"\
	

"$(INTDIR)\stdafx.obj"	"$(INTDIR)\mfccalc.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\mfccalc.pch" /Yc\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ENDIF 

SOURCE=.\calcdlg.h
SOURCE=.\mfccalc.h
SOURCE=.\stdafx.h
SOURCE=.\res\mfccalc.ico
SOURCE=.\res\mfccalc.rc2

!ENDIF 

