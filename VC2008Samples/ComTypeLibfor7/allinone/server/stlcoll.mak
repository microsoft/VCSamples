# Microsoft Developer Studio Generated NMAKE File, Based on stlcoll.dsp
!IF "$(CFG)" == ""
CFG=stlcoll - Win32 DLL Unicode Debug
!MESSAGE No configuration specified. Defaulting to stlcoll - Win32 DLL Unicode\
 Debug.
!ENDIF 

!IF "$(CFG)" != "stlcoll - Win32 DLL Debug" && "$(CFG)" !=\
 "stlcoll - Win32 DLL Release" && "$(CFG)" !=\
 "stlcoll - Win32 DLL Unicode Release" && "$(CFG)" !=\
 "stlcoll - Win32 DLL Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "stlcoll.mak" CFG="stlcoll - Win32 DLL Unicode Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "stlcoll - Win32 DLL Debug" (based on "Win32 (x86) Win32 Application")
!MESSAGE "stlcoll - Win32 DLL Release" (based on\
 "Win32 (x86) Win32 Application")
!MESSAGE "stlcoll - Win32 DLL Unicode Release" (based on\
 "Win32 (x86) Win32 Application")
!MESSAGE "stlcoll - Win32 DLL Unicode Debug" (based on\
 "Win32 (x86) Win32 Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "stlcoll - Win32 DLL Debug"

OUTDIR=.\debug
INTDIR=.\debug
# Begin Custom Macros
OutDir=.\debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\stlcoll.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\stlcoll.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\stlcoll.obj"
	-@erase "$(INTDIR)\stlcoll.pch"
	-@erase "$(INTDIR)\stlcoll.res"
	-@erase "$(INTDIR)\Stlcoll_.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\stlcoll.dll"
	-@erase "$(OUTDIR)\stlcoll.exp"
	-@erase "$(OUTDIR)\stlcoll.ilk"
	-@erase "$(OUTDIR)\stlcoll.lib"
	-@erase "$(OUTDIR)\stlcoll.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_USRDLL" /D "_AFXDLL" /Fp"$(INTDIR)\stlcoll.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\debug/
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\stlcoll.res" /d "_DEBUG" /d "_USRDLL" /d\
 "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\stlcoll.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)\stlcoll.pdb" /debug /machine:I386 /def:"stlcoll.def"\
 /out:"$(OUTDIR)\stlcoll.dll" /implib:"$(OUTDIR)\stlcoll.lib" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\stlcoll.obj" \
	"$(INTDIR)\stlcoll.res" \
	"$(INTDIR)\Stlcoll_.obj"

"$(OUTDIR)\stlcoll.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\debug
TargetPath=.\debug\stlcoll.dll
InputPath=.\debug\stlcoll.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "stlcoll - Win32 DLL Release"

OUTDIR=.\release
INTDIR=.\release
# Begin Custom Macros
OutDir=.\release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\stlcoll.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\stlcoll.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\stlcoll.obj"
	-@erase "$(INTDIR)\stlcoll.pch"
	-@erase "$(INTDIR)\stlcoll.res"
	-@erase "$(INTDIR)\Stlcoll_.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\stlcoll.dll"
	-@erase "$(OUTDIR)\stlcoll.exp"
	-@erase "$(OUTDIR)\stlcoll.ilk"
	-@erase "$(OUTDIR)\stlcoll.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_AFXDLL" /Fp"$(INTDIR)\stlcoll.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\release/
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\stlcoll.res" /d "_DEBUG" /d "_USRDLL" /d\
 "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\stlcoll.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)\stlcoll.pdb" /machine:I386 /def:"stlcoll.def"\
 /out:"$(OUTDIR)\stlcoll.dll" /implib:"$(OUTDIR)\stlcoll.lib" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\stlcoll.obj" \
	"$(INTDIR)\stlcoll.res" \
	"$(INTDIR)\Stlcoll_.obj"

"$(OUTDIR)\stlcoll.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\release
TargetPath=.\release\stlcoll.dll
InputPath=.\release\stlcoll.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "stlcoll - Win32 DLL Unicode Release"

OUTDIR=.\releaseu
INTDIR=.\releaseu
# Begin Custom Macros
OutDir=.\releaseu
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\stlcoll.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\stlcoll.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\stlcoll.obj"
	-@erase "$(INTDIR)\stlcoll.pch"
	-@erase "$(INTDIR)\stlcoll.res"
	-@erase "$(INTDIR)\Stlcoll_.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\stlcoll.dll"
	-@erase "$(OUTDIR)\stlcoll.exp"
	-@erase "$(OUTDIR)\stlcoll.ilk"
	-@erase "$(OUTDIR)\stlcoll.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O1 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_USRDLL" /D "_AFXDLL" /D "UNICODE" /D "_UNICODE" /Fp"$(INTDIR)\stlcoll.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\releaseu/
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\stlcoll.res" /d "_DEBUG" /d "_USRDLL" /d\
 "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\stlcoll.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)\stlcoll.pdb" /machine:I386 /def:"stlcoll.def"\
 /out:"$(OUTDIR)\stlcoll.dll" /implib:"$(OUTDIR)\stlcoll.lib" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\stlcoll.obj" \
	"$(INTDIR)\stlcoll.res" \
	"$(INTDIR)\Stlcoll_.obj"

"$(OUTDIR)\stlcoll.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\releaseu
TargetPath=.\releaseu\stlcoll.dll
InputPath=.\releaseu\stlcoll.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "stlcoll - Win32 DLL Unicode Debug"

OUTDIR=.\debugu
INTDIR=.\debugu
# Begin Custom Macros
OutDir=.\debugu
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\stlcoll.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\stlcoll.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\stlcoll.obj"
	-@erase "$(INTDIR)\stlcoll.pch"
	-@erase "$(INTDIR)\stlcoll.res"
	-@erase "$(INTDIR)\Stlcoll_.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\stlcoll.dll"
	-@erase "$(OUTDIR)\stlcoll.exp"
	-@erase "$(OUTDIR)\stlcoll.ilk"
	-@erase "$(OUTDIR)\stlcoll.lib"
	-@erase "$(OUTDIR)\stlcoll.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_USRDLL" /D "_AFXDLL" /D "UNICODE" /D "_UNICODE" /Fp"$(INTDIR)\stlcoll.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\debugu/
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\stlcoll.res" /d "_DEBUG" /d "_USRDLL" /d\
 "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\stlcoll.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)\stlcoll.pdb" /debug /machine:I386 /def:"stlcoll.def"\
 /out:"$(OUTDIR)\stlcoll.dll" /implib:"$(OUTDIR)\stlcoll.lib" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\stlcoll.obj" \
	"$(INTDIR)\stlcoll.res" \
	"$(INTDIR)\Stlcoll_.obj"

"$(OUTDIR)\stlcoll.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\debugu
TargetPath=.\debugu\stlcoll.dll
InputPath=.\debugu\stlcoll.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ENDIF 


!IF "$(CFG)" == "stlcoll - Win32 DLL Debug" || "$(CFG)" ==\
 "stlcoll - Win32 DLL Release" || "$(CFG)" ==\
 "stlcoll - Win32 DLL Unicode Release" || "$(CFG)" ==\
 "stlcoll - Win32 DLL Unicode Debug"
SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "stlcoll - Win32 DLL Debug"

DEP_CPP_STDAF=\
	".\cdata.h"\
	".\idata.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"statreg.cpp"\
	{$(INCLUDE)}"statreg.h"\
	
CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_USRDLL" /D "_AFXDLL" /Fp"$(INTDIR)\stlcoll.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\stlcoll.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "stlcoll - Win32 DLL Release"

DEP_CPP_STDAF=\
	".\cdata.h"\
	".\idata.h"\
	".\StdAfx.h"\
	"d:\msdev\atl\include\atliface.h"\
	
CPP_SWITCHES=/nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_USRDLL" /D "_AFXDLL" /Fp"$(INTDIR)\stlcoll.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\stlcoll.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "stlcoll - Win32 DLL Unicode Release"

DEP_CPP_STDAF=\
	".\cdata.h"\
	".\idata.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"statreg.cpp"\
	{$(INCLUDE)}"statreg.h"\
	
CPP_SWITCHES=/nologo /MD /W3 /GX /O1 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_USRDLL" /D "_AFXDLL" /D "UNICODE" /D "_UNICODE" /Fp"$(INTDIR)\stlcoll.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\stlcoll.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "stlcoll - Win32 DLL Unicode Debug"

DEP_CPP_STDAF=\
	".\cdata.h"\
	".\idata.h"\
	".\StdAfx.h"\
	"d:\msdev\atl\include\atliface.h"\
	
CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_USRDLL" /D "_AFXDLL" /D "UNICODE" /D "_UNICODE"\
 /Fp"$(INTDIR)\stlcoll.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\stlcoll.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\stlcoll.cpp

!IF  "$(CFG)" == "stlcoll - Win32 DLL Debug"

DEP_CPP_STLCO=\
	".\cdata.h"\
	".\idata.h"\
	".\StdAfx.h"\
	".\stlcoll.h"\
	".\Stlcoll_.h"\
	".\stlcoll_i.c"\
	

"$(INTDIR)\stlcoll.obj" : $(SOURCE) $(DEP_CPP_STLCO) "$(INTDIR)"\
 "$(INTDIR)\stlcoll.pch" ".\stlcoll_i.c" ".\stlcoll.h"


!ELSEIF  "$(CFG)" == "stlcoll - Win32 DLL Release"

DEP_CPP_STLCO=\
	".\stlcoll.h"\
	".\Stlcoll_.h"\
	".\stlcoll_i.c"\
	

"$(INTDIR)\stlcoll.obj" : $(SOURCE) $(DEP_CPP_STLCO) "$(INTDIR)"\
 "$(INTDIR)\stlcoll.pch" ".\stlcoll.h" ".\stlcoll_i.c"


!ELSEIF  "$(CFG)" == "stlcoll - Win32 DLL Unicode Release"

DEP_CPP_STLCO=\
	".\cdata.h"\
	".\idata.h"\
	".\StdAfx.h"\
	".\stlcoll.h"\
	".\Stlcoll_.h"\
	".\stlcoll_i.c"\
	

"$(INTDIR)\stlcoll.obj" : $(SOURCE) $(DEP_CPP_STLCO) "$(INTDIR)"\
 "$(INTDIR)\stlcoll.pch" ".\stlcoll_i.c" ".\stlcoll.h"


!ELSEIF  "$(CFG)" == "stlcoll - Win32 DLL Unicode Debug"

DEP_CPP_STLCO=\
	".\stlcoll.h"\
	".\Stlcoll_.h"\
	".\stlcoll_i.c"\
	

"$(INTDIR)\stlcoll.obj" : $(SOURCE) $(DEP_CPP_STLCO) "$(INTDIR)"\
 "$(INTDIR)\stlcoll.pch" ".\stlcoll.h" ".\stlcoll_i.c"


!ENDIF 

SOURCE=.\stlcoll.idl

!IF  "$(CFG)" == "stlcoll - Win32 DLL Debug"

InputPath=.\stlcoll.idl
InputName=stlcoll

"$(InputName).tlb"	"$(InputName).h"	"$(InputName)_i.c"	 : $(SOURCE) "$(INTDIR)"\
 "$(OUTDIR)"
	midl /h $(InputName).h /iid $(InputName)_i.c $(InputPath)

!ELSEIF  "$(CFG)" == "stlcoll - Win32 DLL Release"

InputPath=.\stlcoll.idl
InputName=stlcoll

"$(InputName).tlb"	"$(InputName).h"	"$(InputName)_i.c"	 : $(SOURCE) "$(INTDIR)"\
 "$(OUTDIR)"
	midl /h $(InputName).h /iid $(InputName)_i.c $(InputPath)

!ELSEIF  "$(CFG)" == "stlcoll - Win32 DLL Unicode Release"

InputPath=.\stlcoll.idl
InputName=stlcoll

"$(InputName).tlb"	"$(InputName).h"	"$(InputName)_i.c"	 : $(SOURCE) "$(INTDIR)"\
 "$(OUTDIR)"
	midl /h $(InputName).h /iid $(InputName)_i.c $(InputPath)

!ELSEIF  "$(CFG)" == "stlcoll - Win32 DLL Unicode Debug"

InputPath=.\stlcoll.idl
InputName=stlcoll

"$(InputName).tlb"	"$(InputName).h"	"$(InputName)_i.c"	 : $(SOURCE) "$(INTDIR)"\
 "$(OUTDIR)"
	midl /h $(InputName).h /iid $(InputName)_i.c $(InputPath)

!ENDIF 

SOURCE=.\stlcoll.rc
DEP_RSC_STLCOL=\
	".\iStlArrays.rgs"\
	".\iStlDWordArray.rgs"\
	".\iStlLists.rgs"\
	".\iStlMapDWordToMyStruct.rgs"\
	".\iStlMaps.rgs"\
	".\iStlMapStringToMyObject.rgs"\
	".\iStlMapStringToString.rgs"\
	".\stlcoll.tlb"\
	

!IF  "$(CFG)" == "stlcoll - Win32 DLL Debug"


"$(INTDIR)\stlcoll.res" : $(SOURCE) $(DEP_RSC_STLCOL) "$(INTDIR)"\
 ".\stlcoll.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "stlcoll - Win32 DLL Release"


"$(INTDIR)\stlcoll.res" : $(SOURCE) $(DEP_RSC_STLCOL) "$(INTDIR)"\
 ".\stlcoll.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "stlcoll - Win32 DLL Unicode Release"


"$(INTDIR)\stlcoll.res" : $(SOURCE) $(DEP_RSC_STLCOL) "$(INTDIR)"\
 ".\stlcoll.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "stlcoll - Win32 DLL Unicode Debug"


"$(INTDIR)\stlcoll.res" : $(SOURCE) $(DEP_RSC_STLCOL) "$(INTDIR)"\
 ".\stlcoll.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Stlcoll_.cpp

!IF  "$(CFG)" == "stlcoll - Win32 DLL Debug"

DEP_CPP_STLCOLL=\
	".\cdata.h"\
	".\idata.h"\
	".\StdAfx.h"\
	".\stlcoll.h"\
	".\Stlcoll_.h"\
	

"$(INTDIR)\Stlcoll_.obj" : $(SOURCE) $(DEP_CPP_STLCOLL) "$(INTDIR)"\
 "$(INTDIR)\stlcoll.pch" ".\stlcoll.h"


!ELSEIF  "$(CFG)" == "stlcoll - Win32 DLL Release"

DEP_CPP_STLCOLL=\
	".\stlcoll.h"\
	".\Stlcoll_.h"\
	

"$(INTDIR)\Stlcoll_.obj" : $(SOURCE) $(DEP_CPP_STLCOLL) "$(INTDIR)"\
 "$(INTDIR)\stlcoll.pch" ".\stlcoll.h"


!ELSEIF  "$(CFG)" == "stlcoll - Win32 DLL Unicode Release"

DEP_CPP_STLCOLL=\
	".\cdata.h"\
	".\idata.h"\
	".\StdAfx.h"\
	".\stlcoll.h"\
	".\Stlcoll_.h"\
	

"$(INTDIR)\Stlcoll_.obj" : $(SOURCE) $(DEP_CPP_STLCOLL) "$(INTDIR)"\
 "$(INTDIR)\stlcoll.pch" ".\stlcoll.h"


!ELSEIF  "$(CFG)" == "stlcoll - Win32 DLL Unicode Debug"

DEP_CPP_STLCOLL=\
	".\stlcoll.h"\
	".\Stlcoll_.h"\
	

"$(INTDIR)\Stlcoll_.obj" : $(SOURCE) $(DEP_CPP_STLCOLL) "$(INTDIR)"\
 "$(INTDIR)\stlcoll.pch" ".\stlcoll.h"


!ENDIF 

SOURCE=.\cdata.h
SOURCE=.\idata.h
SOURCE=.\Resource.h
SOURCE=.\StdAfx.h
SOURCE=.\stlcoll.h
SOURCE=.\stlcoll.tlb
SOURCE=.\Stlcoll_.h
SOURCE=.\StlArrays.rgs
SOURCE=.\StlColl.rgs
SOURCE=.\StlDWordArray.rgs
SOURCE=.\StlLists.rgs
SOURCE=.\StlMapDWordToMyStruct.rgs
SOURCE=.\StlMaps.rgs
SOURCE=.\StlMapStringToMyObject.rgs
SOURCE=.\StlMapStringToString.rgs

!ENDIF 

