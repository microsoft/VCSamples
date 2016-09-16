# Microsoft Developer Studio Generated NMAKE File, Based on ipdrive.dsp
!IF "$(CFG)" == ""
CFG=IpDrive - Win32 Release
!MESSAGE No configuration specified.  Defaulting to IpDrive - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "IpDrive - Win32 Release" && "$(CFG)" !=\
 "IpDrive - Win32 Debug" && "$(CFG)" != "IpDrive - Win32 Unicode Release" &&\
 "$(CFG)" != "IpDrive - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "ipdrive.mak" CFG="IpDrive - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "IpDrive - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "IpDrive - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "IpDrive - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "IpDrive - Win32 Unicode Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "IpDrive - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

ALL : "$(OUTDIR)\ipdrive.exe"

CLEAN : 
	-@erase "$(INTDIR)\Ipdridoc.obj"
	-@erase "$(INTDIR)\Ipdrive.obj"
	-@erase "$(INTDIR)\ipdrive.pch"
	-@erase "$(INTDIR)\Ipdrive.res"
	-@erase "$(INTDIR)\Ipdrivw.obj"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\ipdrive.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\ipdrive.pch" /Yu"Stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Ipdrive.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ipdrive.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\ipdrive.pdb" /machine:I386 /out:"$(OUTDIR)\ipdrive.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Ipdridoc.obj" \
	"$(INTDIR)\Ipdrive.obj" \
	"$(INTDIR)\Ipdrive.res" \
	"$(INTDIR)\Ipdrivw.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Stdafx.obj"

"$(OUTDIR)\ipdrive.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "IpDrive - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\ipdrive.exe"

CLEAN : 
	-@erase "$(INTDIR)\Ipdridoc.obj"
	-@erase "$(INTDIR)\Ipdrive.obj"
	-@erase "$(INTDIR)\ipdrive.pch"
	-@erase "$(INTDIR)\Ipdrive.res"
	-@erase "$(INTDIR)\Ipdrivw.obj"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\ipdrive.exe"
	-@erase "$(OUTDIR)\ipdrive.ilk"
	-@erase "$(OUTDIR)\ipdrive.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\ipdrive.pch" /Yu"Stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Ipdrive.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ipdrive.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\ipdrive.pdb" /debug /machine:I386 /out:"$(OUTDIR)\ipdrive.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Ipdridoc.obj" \
	"$(INTDIR)\Ipdrive.obj" \
	"$(INTDIR)\Ipdrive.res" \
	"$(INTDIR)\Ipdrivw.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Stdafx.obj"

"$(OUTDIR)\ipdrive.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "IpDrive - Win32 Unicode Release"

OUTDIR=.\UniRelease
INTDIR=.\UniRelease
# Begin Custom Macros
OutDir=.\.\UniRelease
# End Custom Macros

ALL : "$(OUTDIR)\ipdrive.exe"

CLEAN : 
	-@erase "$(INTDIR)\Ipdridoc.obj"
	-@erase "$(INTDIR)\Ipdrive.obj"
	-@erase "$(INTDIR)\ipdrive.pch"
	-@erase "$(INTDIR)\Ipdrive.res"
	-@erase "$(INTDIR)\Ipdrivw.obj"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\ipdrive.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\ipdrive.pch" /Yu"Stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\UniRelease/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Ipdrive.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ipdrive.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows\
 /incremental:no /pdb:"$(OUTDIR)\ipdrive.pdb" /machine:I386\
 /out:"$(OUTDIR)\ipdrive.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Ipdridoc.obj" \
	"$(INTDIR)\Ipdrive.obj" \
	"$(INTDIR)\Ipdrive.res" \
	"$(INTDIR)\Ipdrivw.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Stdafx.obj"

"$(OUTDIR)\ipdrive.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "IpDrive - Win32 Unicode Debug"

OUTDIR=.\UniDebug
INTDIR=.\UniDebug
# Begin Custom Macros
OutDir=.\.\UniDebug
# End Custom Macros

ALL : "$(OUTDIR)\ipdrive.exe"

CLEAN : 
	-@erase "$(INTDIR)\Ipdridoc.obj"
	-@erase "$(INTDIR)\Ipdrive.obj"
	-@erase "$(INTDIR)\ipdrive.pch"
	-@erase "$(INTDIR)\Ipdrive.res"
	-@erase "$(INTDIR)\Ipdrivw.obj"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\ipdrive.exe"
	-@erase "$(OUTDIR)\ipdrive.ilk"
	-@erase "$(OUTDIR)\ipdrive.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\ipdrive.pch" /Yu"Stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\UniDebug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Ipdrive.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ipdrive.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows\
 /incremental:yes /pdb:"$(OUTDIR)\ipdrive.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)\ipdrive.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Ipdridoc.obj" \
	"$(INTDIR)\Ipdrive.obj" \
	"$(INTDIR)\Ipdrive.res" \
	"$(INTDIR)\Ipdrivw.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Stdafx.obj"

"$(OUTDIR)\ipdrive.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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


!IF "$(CFG)" == "IpDrive - Win32 Release" || "$(CFG)" ==\
 "IpDrive - Win32 Debug" || "$(CFG)" == "IpDrive - Win32 Unicode Release" ||\
 "$(CFG)" == "IpDrive - Win32 Unicode Debug"
SOURCE=.\Ipdridoc.cpp

!IF  "$(CFG)" == "IpDrive - Win32 Release"

DEP_CPP_IPDRI=\
	".\Ipdridoc.h"\
	".\Ipdrive.h"\
	

"$(INTDIR)\Ipdridoc.obj" : $(SOURCE) $(DEP_CPP_IPDRI) "$(INTDIR)"\
 "$(INTDIR)\ipdrive.pch"


!ELSEIF  "$(CFG)" == "IpDrive - Win32 Debug"

DEP_CPP_IPDRI=\
	".\Ipdridoc.h"\
	".\Ipdrive.h"\
	

"$(INTDIR)\Ipdridoc.obj" : $(SOURCE) $(DEP_CPP_IPDRI) "$(INTDIR)"\
 "$(INTDIR)\ipdrive.pch"


!ELSEIF  "$(CFG)" == "IpDrive - Win32 Unicode Release"

DEP_CPP_IPDRI=\
	".\Ipdridoc.h"\
	".\Ipdrive.h"\
	

"$(INTDIR)\Ipdridoc.obj" : $(SOURCE) $(DEP_CPP_IPDRI) "$(INTDIR)"\
 "$(INTDIR)\ipdrive.pch"


!ELSEIF  "$(CFG)" == "IpDrive - Win32 Unicode Debug"

DEP_CPP_IPDRI=\
	".\Ipdridoc.h"\
	".\Ipdrive.h"\
	

"$(INTDIR)\Ipdridoc.obj" : $(SOURCE) $(DEP_CPP_IPDRI) "$(INTDIR)"\
 "$(INTDIR)\ipdrive.pch"


!ENDIF 

SOURCE=.\Ipdrive.cpp

!IF  "$(CFG)" == "IpDrive - Win32 Release"

DEP_CPP_IPDRIV=\
	".\Ipdridoc.h"\
	".\Ipdrive.h"\
	".\Ipdrivw.h"\
	".\Mainfrm.h"\
	

"$(INTDIR)\Ipdrive.obj" : $(SOURCE) $(DEP_CPP_IPDRIV) "$(INTDIR)"\
 "$(INTDIR)\ipdrive.pch"


!ELSEIF  "$(CFG)" == "IpDrive - Win32 Debug"

DEP_CPP_IPDRIV=\
	".\Ipdridoc.h"\
	".\Ipdrive.h"\
	".\Ipdrivw.h"\
	".\Mainfrm.h"\
	

"$(INTDIR)\Ipdrive.obj" : $(SOURCE) $(DEP_CPP_IPDRIV) "$(INTDIR)"\
 "$(INTDIR)\ipdrive.pch"


!ELSEIF  "$(CFG)" == "IpDrive - Win32 Unicode Release"

DEP_CPP_IPDRIV=\
	".\Ipdridoc.h"\
	".\Ipdrive.h"\
	".\Ipdrivw.h"\
	".\Mainfrm.h"\
	

"$(INTDIR)\Ipdrive.obj" : $(SOURCE) $(DEP_CPP_IPDRIV) "$(INTDIR)"\
 "$(INTDIR)\ipdrive.pch"


!ELSEIF  "$(CFG)" == "IpDrive - Win32 Unicode Debug"

DEP_CPP_IPDRIV=\
	".\Ipdridoc.h"\
	".\Ipdrive.h"\
	".\Ipdrivw.h"\
	".\Mainfrm.h"\
	

"$(INTDIR)\Ipdrive.obj" : $(SOURCE) $(DEP_CPP_IPDRIV) "$(INTDIR)"\
 "$(INTDIR)\ipdrive.pch"


!ENDIF 

SOURCE=.\Ipdrive.rc
DEP_RSC_IPDRIVE=\
	".\Res\Ipdrive.ico"\
	".\Res\Ipdrive.rc2"\
	".\Res\Toolbar.bmp"\
	

!IF  "$(CFG)" == "IpDrive - Win32 Release"


"$(INTDIR)\Ipdrive.res" : $(SOURCE) $(DEP_RSC_IPDRIVE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "IpDrive - Win32 Debug"


"$(INTDIR)\Ipdrive.res" : $(SOURCE) $(DEP_RSC_IPDRIVE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "IpDrive - Win32 Unicode Release"


"$(INTDIR)\Ipdrive.res" : $(SOURCE) $(DEP_RSC_IPDRIVE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "IpDrive - Win32 Unicode Debug"


"$(INTDIR)\Ipdrive.res" : $(SOURCE) $(DEP_RSC_IPDRIVE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Ipdrivw.cpp

!IF  "$(CFG)" == "IpDrive - Win32 Release"

DEP_CPP_IPDRIVW=\
	".\Ipdridoc.h"\
	".\Ipdrive.h"\
	".\Ipdrivw.h"\
	

"$(INTDIR)\Ipdrivw.obj" : $(SOURCE) $(DEP_CPP_IPDRIVW) "$(INTDIR)"\
 "$(INTDIR)\ipdrive.pch"


!ELSEIF  "$(CFG)" == "IpDrive - Win32 Debug"

DEP_CPP_IPDRIVW=\
	".\Ipdridoc.h"\
	".\Ipdrive.h"\
	".\Ipdrivw.h"\
	

"$(INTDIR)\Ipdrivw.obj" : $(SOURCE) $(DEP_CPP_IPDRIVW) "$(INTDIR)"\
 "$(INTDIR)\ipdrive.pch"


!ELSEIF  "$(CFG)" == "IpDrive - Win32 Unicode Release"

DEP_CPP_IPDRIVW=\
	".\Ipdridoc.h"\
	".\Ipdrive.h"\
	".\Ipdrivw.h"\
	

"$(INTDIR)\Ipdrivw.obj" : $(SOURCE) $(DEP_CPP_IPDRIVW) "$(INTDIR)"\
 "$(INTDIR)\ipdrive.pch"


!ELSEIF  "$(CFG)" == "IpDrive - Win32 Unicode Debug"

DEP_CPP_IPDRIVW=\
	".\Ipdridoc.h"\
	".\Ipdrive.h"\
	".\Ipdrivw.h"\
	

"$(INTDIR)\Ipdrivw.obj" : $(SOURCE) $(DEP_CPP_IPDRIVW) "$(INTDIR)"\
 "$(INTDIR)\ipdrive.pch"


!ENDIF 

SOURCE=.\Mainfrm.cpp

!IF  "$(CFG)" == "IpDrive - Win32 Release"

DEP_CPP_MAINF=\
	".\Ipdrive.h"\
	".\Mainfrm.h"\
	

"$(INTDIR)\Mainfrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\ipdrive.pch"


!ELSEIF  "$(CFG)" == "IpDrive - Win32 Debug"

DEP_CPP_MAINF=\
	".\Ipdrive.h"\
	".\Mainfrm.h"\
	

"$(INTDIR)\Mainfrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\ipdrive.pch"


!ELSEIF  "$(CFG)" == "IpDrive - Win32 Unicode Release"

DEP_CPP_MAINF=\
	".\Ipdrive.h"\
	".\Mainfrm.h"\
	

"$(INTDIR)\Mainfrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\ipdrive.pch"


!ELSEIF  "$(CFG)" == "IpDrive - Win32 Unicode Debug"

DEP_CPP_MAINF=\
	".\Ipdrive.h"\
	".\Mainfrm.h"\
	

"$(INTDIR)\Mainfrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\ipdrive.pch"


!ENDIF 

SOURCE=.\Stdafx.cpp

!IF  "$(CFG)" == "IpDrive - Win32 Release"

DEP_CPP_STDAF=\
	"..\server\inproc.tlb"\
	".\Stdafx.h"\
	"d:\msdev\include\zmouse.h"\
	

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\ipdrive.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\ipdrive.pch" /Yc /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ELSEIF  "$(CFG)" == "IpDrive - Win32 Debug"

DEP_CPP_STDAF=\
	"..\server\inproc.tlb"\
	".\Stdafx.h"\
	"d:\msdev\include\zmouse.h"\
	

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\ipdrive.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\ipdrive.pch" /Yc /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ELSEIF  "$(CFG)" == "IpDrive - Win32 Unicode Release"

DEP_CPP_STDAF=\
	"..\server\inproc.tlb"\
	".\Stdafx.h"\
	"d:\msdev\include\zmouse.h"\
	

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\ipdrive.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\ipdrive.pch" /Yc"Stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ELSEIF  "$(CFG)" == "IpDrive - Win32 Unicode Debug"

DEP_CPP_STDAF=\
	"..\server\inproc.tlb"\
	".\Stdafx.h"\
	"d:\msdev\include\zmouse.h"\
	

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\ipdrive.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_UNICODE" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\ipdrive.pch" /Yc\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ENDIF 

SOURCE=.\Ipdridoc.h
SOURCE=.\Ipdrive.h
SOURCE=.\Ipdrivw.h
SOURCE=.\Mainfrm.h
SOURCE=.\Resource.h
SOURCE=.\Stdafx.h
SOURCE=.\Res\Ipdrive.ico
SOURCE=.\Res\Ipdrive.rc2
SOURCE=.\Res\Toolbar.bmp

!ENDIF 

