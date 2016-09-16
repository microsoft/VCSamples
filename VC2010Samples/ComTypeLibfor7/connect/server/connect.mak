# Microsoft Developer Studio Generated NMAKE File, Based on connect.dsp
!IF "$(CFG)" == ""
CFG=Connect - Win32 Release
!MESSAGE No configuration specified. Defaulting to Connect - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Connect - Win32 Release" && "$(CFG)" !=\
 "Connect - Win32 Debug" && "$(CFG)" != "Connect - Win32 Unicode Release" &&\
 "$(CFG)" != "Connect - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "connect.mak" CFG="Connect - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Connect - Win32 Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Connect - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Connect - Win32 Unicode Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Connect - Win32 Unicode Debug" (based on\
 "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "Connect - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\connect.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\connect.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Connect.obj"
	-@erase "$(INTDIR)\connect.pch"
	-@erase "$(INTDIR)\Connect.res"
	-@erase "$(INTDIR)\preconn.obj"
	-@erase "$(INTDIR)\Random.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\connect.dll"
	-@erase "$(OUTDIR)\connect.exp"
	-@erase "$(OUTDIR)\connect.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\connect.pch" /Yu"preconn.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Connect.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\connect.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)\connect.pdb" /machine:I386 /def:".\Connect.def"\
 /out:"$(OUTDIR)\connect.dll" /implib:"$(OUTDIR)\connect.lib" 
DEF_FILE= \
	".\Connect.def"
LINK32_OBJS= \
	"$(INTDIR)\Connect.obj" \
	"$(INTDIR)\Connect.res" \
	"$(INTDIR)\preconn.obj" \
	"$(INTDIR)\Random.obj"

"$(OUTDIR)\connect.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\connect.dll
InputPath=.\Release\connect.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "Connect - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\connect.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\connect.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Connect.obj"
	-@erase "$(INTDIR)\connect.pch"
	-@erase "$(INTDIR)\Connect.res"
	-@erase "$(INTDIR)\preconn.obj"
	-@erase "$(INTDIR)\Random.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\connect.dll"
	-@erase "$(OUTDIR)\connect.exp"
	-@erase "$(OUTDIR)\connect.ilk"
	-@erase "$(OUTDIR)\connect.lib"
	-@erase "$(OUTDIR)\connect.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\connect.pch" /Yu"preconn.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Connect.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\connect.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)\connect.pdb" /debug /machine:I386 /def:".\Connect.def"\
 /out:"$(OUTDIR)\connect.dll" /implib:"$(OUTDIR)\connect.lib" 
DEF_FILE= \
	".\Connect.def"
LINK32_OBJS= \
	"$(INTDIR)\Connect.obj" \
	"$(INTDIR)\Connect.res" \
	"$(INTDIR)\preconn.obj" \
	"$(INTDIR)\Random.obj"

"$(OUTDIR)\connect.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\connect.dll
InputPath=.\Debug\connect.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "Connect - Win32 Unicode Release"

OUTDIR=.\ReleaseU
INTDIR=.\ReleaseU
# Begin Custom Macros
OutDir=.\.\ReleaseU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\connect.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\connect.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Connect.obj"
	-@erase "$(INTDIR)\connect.pch"
	-@erase "$(INTDIR)\Connect.res"
	-@erase "$(INTDIR)\preconn.obj"
	-@erase "$(INTDIR)\Random.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\connect.dll"
	-@erase "$(OUTDIR)\connect.exp"
	-@erase "$(OUTDIR)\connect.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\connect.pch"\
 /Yu"preconn.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Connect.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\connect.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)\connect.pdb" /machine:I386 /def:".\Connect.def"\
 /out:"$(OUTDIR)\connect.dll" /implib:"$(OUTDIR)\connect.lib" 
DEF_FILE= \
	".\Connect.def"
LINK32_OBJS= \
	"$(INTDIR)\Connect.obj" \
	"$(INTDIR)\Connect.res" \
	"$(INTDIR)\preconn.obj" \
	"$(INTDIR)\Random.obj"

"$(OUTDIR)\connect.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\ReleaseU
TargetPath=.\ReleaseU\connect.dll
InputPath=.\ReleaseU\connect.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "Connect - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\.\DebugU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\connect.dll" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\connect.dll" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Connect.obj"
	-@erase "$(INTDIR)\connect.pch"
	-@erase "$(INTDIR)\Connect.res"
	-@erase "$(INTDIR)\preconn.obj"
	-@erase "$(INTDIR)\Random.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\connect.dll"
	-@erase "$(OUTDIR)\connect.exp"
	-@erase "$(OUTDIR)\connect.ilk"
	-@erase "$(OUTDIR)\connect.lib"
	-@erase "$(OUTDIR)\connect.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\connect.pch"\
 /Yu"preconn.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\DebugU/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Connect.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\connect.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)\connect.pdb" /debug /machine:I386 /def:".\Connect.def"\
 /out:"$(OUTDIR)\connect.dll" /implib:"$(OUTDIR)\connect.lib" 
DEF_FILE= \
	".\Connect.def"
LINK32_OBJS= \
	"$(INTDIR)\Connect.obj" \
	"$(INTDIR)\Connect.res" \
	"$(INTDIR)\preconn.obj" \
	"$(INTDIR)\Random.obj"

"$(OUTDIR)\connect.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\DebugU
TargetPath=.\DebugU\connect.dll
InputPath=.\DebugU\connect.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

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


!IF "$(CFG)" == "Connect - Win32 Release" || "$(CFG)" ==\
 "Connect - Win32 Debug" || "$(CFG)" == "Connect - Win32 Unicode Release" ||\
 "$(CFG)" == "Connect - Win32 Unicode Debug"
SOURCE=.\Connect.cpp

!IF  "$(CFG)" == "Connect - Win32 Release"

DEP_CPP_CONNE=\
	".\Connect.h"\
	".\Connect_i.c"\
	".\Random.h"\
	

"$(INTDIR)\Connect.obj" : $(SOURCE) $(DEP_CPP_CONNE) "$(INTDIR)"\
 "$(INTDIR)\connect.pch" ".\Connect.h" ".\Connect_i.c"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Connect - Win32 Debug"

DEP_CPP_CONNE=\
	".\Connect.h"\
	".\Connect_i.c"\
	".\Random.h"\
	

"$(INTDIR)\Connect.obj" : $(SOURCE) $(DEP_CPP_CONNE) "$(INTDIR)"\
 "$(INTDIR)\connect.pch" ".\Connect_i.c" ".\Connect.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Connect - Win32 Unicode Release"

DEP_CPP_CONNE=\
	".\Connect.h"\
	".\Connect_i.c"\
	".\preconn.h"\
	".\Random.h"\
	

"$(INTDIR)\Connect.obj" : $(SOURCE) $(DEP_CPP_CONNE) "$(INTDIR)"\
 "$(INTDIR)\connect.pch" ".\Connect.h" ".\Connect_i.c"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Connect - Win32 Unicode Debug"

DEP_CPP_CONNE=\
	".\Connect.h"\
	".\Connect_i.c"\
	".\Random.h"\
	

"$(INTDIR)\Connect.obj" : $(SOURCE) $(DEP_CPP_CONNE) "$(INTDIR)"\
 "$(INTDIR)\connect.pch" ".\Connect.h" ".\Connect_i.c"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Connect.def
SOURCE=.\Connect.idl

!IF  "$(CFG)" == "Connect - Win32 Release"

InputPath=.\Connect.idl

"Connect.tlb"	"Connect.h"	"Connect_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl Connect.idl

!ELSEIF  "$(CFG)" == "Connect - Win32 Debug"

InputPath=.\Connect.idl

"Connect.tlb"	"Connect.h"	"Connect_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl Connect.idl

!ELSEIF  "$(CFG)" == "Connect - Win32 Unicode Release"

InputPath=.\Connect.idl

"Connect.tlb"	"Connect.h"	"Connect_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl Connect.idl

!ELSEIF  "$(CFG)" == "Connect - Win32 Unicode Debug"

InputPath=.\Connect.idl

"Connect.tlb"	"Connect.h"	"Connect_i.c"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	midl Connect.idl

!ENDIF 

SOURCE=.\Connect.rc
DEP_RSC_CONNEC=\
	".\Connect.tlb"\
	".\Random.rgs"\
	

!IF  "$(CFG)" == "Connect - Win32 Release"


"$(INTDIR)\Connect.res" : $(SOURCE) $(DEP_RSC_CONNEC) "$(INTDIR)"\
 ".\Connect.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Connect - Win32 Debug"


"$(INTDIR)\Connect.res" : $(SOURCE) $(DEP_RSC_CONNEC) "$(INTDIR)"\
 ".\Connect.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Connect - Win32 Unicode Release"


"$(INTDIR)\Connect.res" : $(SOURCE) $(DEP_RSC_CONNEC) "$(INTDIR)"\
 ".\Connect.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Connect - Win32 Unicode Debug"


"$(INTDIR)\Connect.res" : $(SOURCE) $(DEP_RSC_CONNEC) "$(INTDIR)"\
 ".\Connect.tlb"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\connect.txt
SOURCE=.\preconn.cpp

!IF  "$(CFG)" == "Connect - Win32 Release"

DEP_CPP_PRECO=\
	".\preconn.h"\
	"d:\msdev\mcl\atl\include\atliface.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\connect.pch" /Yc"preconn.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\preconn.obj"	"$(INTDIR)\connect.pch" : $(SOURCE) $(DEP_CPP_PRECO)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Connect - Win32 Debug"

DEP_CPP_PRECO=\
	".\preconn.h"\
	"d:\msdev\mcl\atl\include\atliface.h"\
	
CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\connect.pch"\
 /Yc"preconn.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\preconn.obj"	"$(INTDIR)\connect.pch" : $(SOURCE) $(DEP_CPP_PRECO)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Connect - Win32 Unicode Release"

DEP_CPP_PRECO=\
	".\preconn.h"\
	
CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\connect.pch"\
 /Yc"preconn.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\preconn.obj"	"$(INTDIR)\connect.pch" : $(SOURCE) $(DEP_CPP_PRECO)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Connect - Win32 Unicode Debug"

DEP_CPP_PRECO=\
	".\preconn.h"\
	"d:\msdev\mcl\atl\include\atliface.h"\
	
CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /D "_UNICODE"\
 /Fp"$(INTDIR)\connect.pch" /Yc"preconn.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 

"$(INTDIR)\preconn.obj"	"$(INTDIR)\connect.pch" : $(SOURCE) $(DEP_CPP_PRECO)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Random.cpp

!IF  "$(CFG)" == "Connect - Win32 Release"

DEP_CPP_RANDO=\
	".\Connect.h"\
	".\Random.h"\
	

"$(INTDIR)\Random.obj" : $(SOURCE) $(DEP_CPP_RANDO) "$(INTDIR)"\
 "$(INTDIR)\connect.pch" ".\Connect.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Connect - Win32 Debug"

DEP_CPP_RANDO=\
	".\Connect.h"\
	".\Random.h"\
	

"$(INTDIR)\Random.obj" : $(SOURCE) $(DEP_CPP_RANDO) "$(INTDIR)"\
 "$(INTDIR)\connect.pch" ".\Connect.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Connect - Win32 Unicode Release"

DEP_CPP_RANDO=\
	".\Connect.h"\
	".\preconn.h"\
	".\Random.h"\
	

"$(INTDIR)\Random.obj" : $(SOURCE) $(DEP_CPP_RANDO) "$(INTDIR)"\
 "$(INTDIR)\connect.pch" ".\Connect.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Connect - Win32 Unicode Debug"

DEP_CPP_RANDO=\
	".\Connect.h"\
	".\Random.h"\
	

"$(INTDIR)\Random.obj" : $(SOURCE) $(DEP_CPP_RANDO) "$(INTDIR)"\
 "$(INTDIR)\connect.pch" ".\Connect.h"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\Random.rgs
SOURCE=.\preconn.h
SOURCE=.\Random.h

!ENDIF 

