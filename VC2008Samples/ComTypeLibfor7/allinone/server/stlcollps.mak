# Microsoft Developer Studio Generated NMAKE File, Based on stlcollps.dsp
!IF "$(CFG)" == ""
CFG=stlcollps - Win32 Unicode Debug
!MESSAGE No configuration specified.  Defaulting to stlcollps - Win32 Unicode\
 Debug.
!ENDIF 

!IF "$(CFG)" != "stlcollps - Win32 Release" && "$(CFG)" !=\
 "stlcollps - Win32 Debug" && "$(CFG)" != "stlcollps - Win32 Unicode Debug" &&\
 "$(CFG)" != "stlcollps - Win32 Unicode Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "stlcollps.mak" CFG="stlcollps - Win32 Unicode Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "stlcollps - Win32 Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "stlcollps - Win32 Debug" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "stlcollps - Win32 Unicode Debug" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "stlcollps - Win32 Unicode Release" (based on\
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

!IF  "$(CFG)" == "stlcollps - Win32 Release"

OUTDIR=.
INTDIR=.
# Begin Custom Macros
OutDir=.
# End Custom Macros

ALL : "$(OUTDIR)\stlcollps.dll" "$(OutDir)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\dlldata.obj"
	-@erase "$(INTDIR)\stlcoll_i.obj"
	-@erase "$(INTDIR)\stlcoll_p.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\stlcollps.dll"
	-@erase "$(OUTDIR)\stlcollps.exp"
	-@erase "$(OUTDIR)\stlcollps.lib"
	-@erase "$(OutDir)\regsvr32.trg"

CPP_PROJ=/nologo /MT /W3 /Ox /D "NDEBUG" /D "_WINDOWS" /D "WIN32" /D\
 "REGISTER_PROXY_DLL" /D _WIN32_WINNT=0x400 /Fp"$(INTDIR)\stlcollps.pch" /YX /FD\
 /c 
CPP_OBJS=.
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\stlcollps.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib rpcndr.lib rpcns4.lib rpcrt4.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\stlcollps.pdb" /machine:I386\
 /def:".\stlcollps.def" /out:"$(OUTDIR)\stlcollps.dll"\
 /implib:"$(OUTDIR)\stlcollps.lib" 
DEF_FILE= \
	".\stlcollps.def"
LINK32_OBJS= \
	"$(INTDIR)\dlldata.obj" \
	"$(INTDIR)\stlcoll_i.obj" \
	"$(INTDIR)\stlcoll_p.obj"

"$(OUTDIR)\stlcollps.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.
TargetPath=.\stlcollps.dll
InputPath=.\stlcollps.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "stlcollps - Win32 Debug"

OUTDIR=.
INTDIR=.
# Begin Custom Macros
OutDir=.
# End Custom Macros

ALL : "$(OUTDIR)\stlcollps.dll" "$(OutDir)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\dlldata.obj"
	-@erase "$(INTDIR)\stlcoll_i.obj"
	-@erase "$(INTDIR)\stlcoll_p.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\stlcollps.dll"
	-@erase "$(OUTDIR)\stlcollps.exp"
	-@erase "$(OUTDIR)\stlcollps.ilk"
	-@erase "$(OUTDIR)\stlcollps.lib"
	-@erase "$(OUTDIR)\stlcollps.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "_WINDOWS" /D "WIN32"\
 /D "REGISTER_PROXY_DLL" /D _WIN32_WINNT=0x400 /Fp"$(INTDIR)\stlcollps.pch" /YX\
 /FD /c 
CPP_OBJS=.
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\stlcollps.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib rpcndr.lib rpcns4.lib rpcrt4.lib /nologo /subsystem:windows /dll\
 /incremental:yes /pdb:"$(OUTDIR)\stlcollps.pdb" /debug /machine:I386\
 /def:".\stlcollps.def" /out:"$(OUTDIR)\stlcollps.dll"\
 /implib:"$(OUTDIR)\stlcollps.lib" /pdbtype:sept 
DEF_FILE= \
	".\stlcollps.def"
LINK32_OBJS= \
	"$(INTDIR)\dlldata.obj" \
	"$(INTDIR)\stlcoll_i.obj" \
	"$(INTDIR)\stlcoll_p.obj"

"$(OUTDIR)\stlcollps.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.
TargetPath=.\stlcollps.dll
InputPath=.\stlcollps.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "stlcollps - Win32 Unicode Debug"

OUTDIR=.\stlcollp
INTDIR=.\stlcollp
# Begin Custom Macros
OutDir=.\stlcollp
# End Custom Macros

ALL : "$(OUTDIR)\stlcollps.dll" "$(OutDir)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\dlldata.obj"
	-@erase "$(INTDIR)\stlcoll_i.obj"
	-@erase "$(INTDIR)\stlcoll_p.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\stlcollps.dll"
	-@erase "$(OUTDIR)\stlcollps.exp"
	-@erase "$(OUTDIR)\stlcollps.ilk"
	-@erase "$(OUTDIR)\stlcollps.lib"
	-@erase "$(OUTDIR)\stlcollps.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "_WINDOWS" /D "WIN32"\
 /D "REGISTER_PROXY_DLL" /D _WIN32_WINNT=0x400 /D "_UNICODE" /D "UNICODE"\
 /Fp"$(INTDIR)\stlcollps.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\stlcollp/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\stlcollps.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib rpcndr.lib rpcns4.lib rpcrt4.lib /nologo /subsystem:windows /dll\
 /incremental:yes /pdb:"$(OUTDIR)\stlcollps.pdb" /debug /machine:I386\
 /def:".\stlcollps.def" /out:"$(OUTDIR)\stlcollps.dll"\
 /implib:"$(OUTDIR)\stlcollps.lib" /pdbtype:sept 
DEF_FILE= \
	".\stlcollps.def"
LINK32_OBJS= \
	"$(INTDIR)\dlldata.obj" \
	"$(INTDIR)\stlcoll_i.obj" \
	"$(INTDIR)\stlcoll_p.obj"

"$(OUTDIR)\stlcollps.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\stlcollp
TargetPath=.\stlcollp\stlcollps.dll
InputPath=.\stlcollp\stlcollps.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "stlcollps - Win32 Unicode Release"

OUTDIR=.\stlcoll0
INTDIR=.\stlcoll0
# Begin Custom Macros
OutDir=.\stlcoll0
# End Custom Macros

ALL : "$(OUTDIR)\stlcollps.dll" "$(OutDir)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\dlldata.obj"
	-@erase "$(INTDIR)\stlcoll_i.obj"
	-@erase "$(INTDIR)\stlcoll_p.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\stlcollps.dll"
	-@erase "$(OUTDIR)\stlcollps.exp"
	-@erase "$(OUTDIR)\stlcollps.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /Ox /D "NDEBUG" /D "_WINDOWS" /D "WIN32" /D\
 "REGISTER_PROXY_DLL" /D _WIN32_WINNT=0x400 /D "_UNICODE" /D "UNICODE"\
 /Fp"$(INTDIR)\stlcollps.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\stlcoll0/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\stlcollps.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib rpcndr.lib rpcns4.lib rpcrt4.lib /nologo /subsystem:windows /dll\
 /incremental:no /pdb:"$(OUTDIR)\stlcollps.pdb" /machine:I386\
 /def:".\stlcollps.def" /out:"$(OUTDIR)\stlcollps.dll"\
 /implib:"$(OUTDIR)\stlcollps.lib" 
DEF_FILE= \
	".\stlcollps.def"
LINK32_OBJS= \
	"$(INTDIR)\dlldata.obj" \
	"$(INTDIR)\stlcoll_i.obj" \
	"$(INTDIR)\stlcoll_p.obj"

"$(OUTDIR)\stlcollps.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\stlcoll0
TargetPath=.\stlcoll0\stlcollps.dll
InputPath=.\stlcoll0\stlcollps.dll
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


!IF "$(CFG)" == "stlcollps - Win32 Release" || "$(CFG)" ==\
 "stlcollps - Win32 Debug" || "$(CFG)" == "stlcollps - Win32 Unicode Debug" ||\
 "$(CFG)" == "stlcollps - Win32 Unicode Release"
SOURCE=.\dlldata.c

!IF  "$(CFG)" == "stlcollps - Win32 Release"


"$(INTDIR)\dlldata.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "stlcollps - Win32 Debug"


"$(INTDIR)\dlldata.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "stlcollps - Win32 Unicode Debug"


"$(INTDIR)\dlldata.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "stlcollps - Win32 Unicode Release"


"$(INTDIR)\dlldata.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\stlcoll_i.c

!IF  "$(CFG)" == "stlcollps - Win32 Release"


"$(INTDIR)\stlcoll_i.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "stlcollps - Win32 Debug"


"$(INTDIR)\stlcoll_i.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "stlcollps - Win32 Unicode Debug"


"$(INTDIR)\stlcoll_i.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "stlcollps - Win32 Unicode Release"


"$(INTDIR)\stlcoll_i.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\stlcoll_p.c
DEP_CPP_STLCO=\
	".\idata.h"\
	".\stlcoll.h"\
	

!IF  "$(CFG)" == "stlcollps - Win32 Release"


"$(INTDIR)\stlcoll_p.obj" : $(SOURCE) $(DEP_CPP_STLCO) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "stlcollps - Win32 Debug"


"$(INTDIR)\stlcoll_p.obj" : $(SOURCE) $(DEP_CPP_STLCO) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "stlcollps - Win32 Unicode Debug"


"$(INTDIR)\stlcoll_p.obj" : $(SOURCE) $(DEP_CPP_STLCO) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "stlcollps - Win32 Unicode Release"


"$(INTDIR)\stlcoll_p.obj" : $(SOURCE) $(DEP_CPP_STLCO) "$(INTDIR)"


!ENDIF 

SOURCE=.\stlcollps.def

!ENDIF 

