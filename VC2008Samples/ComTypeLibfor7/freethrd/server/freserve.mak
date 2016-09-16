# Microsoft Developer Studio Generated NMAKE File, Based on freserve.dsp
!IF "$(CFG)" == ""
CFG=freserve - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to freserve - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "freserve - Win32 Release" && "$(CFG)" !=\
 "freserve - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "freserve.mak" CFG="freserve - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "freserve - Win32 Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "freserve - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "freserve - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\freserve.dll" "$(OutDir)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\Apputil.obj"
	-@erase "$(INTDIR)\Ball.obj"
	-@erase "$(INTDIR)\Factory.obj"
	-@erase "$(INTDIR)\Freserve.obj"
	-@erase "$(INTDIR)\freserve.pch"
	-@erase "$(INTDIR)\Freserve.res"
	-@erase "$(INTDIR)\iball_i.obj"
	-@erase "$(INTDIR)\Preserve.obj"
	-@erase "$(INTDIR)\Server.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\freserve.dll"
	-@erase "$(OUTDIR)\freserve.exp"
	-@erase "$(OUTDIR)\freserve.lib"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WIN32"\
 /Fp"$(INTDIR)\freserve.pch" /Yu"preserve.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"\
 /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Freserve.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\freserve.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)\freserve.pdb" /machine:I386 /nodefaultlib:"libc.lib"\
 /def:".\Freserve.def" /out:"$(OUTDIR)\freserve.dll"\
 /implib:"$(OUTDIR)\freserve.lib" 
DEF_FILE= \
	".\Freserve.def"
LINK32_OBJS= \
	"$(INTDIR)\Apputil.obj" \
	"$(INTDIR)\Ball.obj" \
	"$(INTDIR)\Factory.obj" \
	"$(INTDIR)\Freserve.obj" \
	"$(INTDIR)\Freserve.res" \
	"$(INTDIR)\iball_i.obj" \
	"$(INTDIR)\Preserve.obj" \
	"$(INTDIR)\Server.obj"

"$(OUTDIR)\freserve.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Release
TargetPath=.\Release\freserve.dll
InputPath=.\Release\freserve.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "freserve - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\freserve.dll" "$(OutDir)\regsvr32.trg"

CLEAN : 
	-@erase "$(INTDIR)\Apputil.obj"
	-@erase "$(INTDIR)\Ball.obj"
	-@erase "$(INTDIR)\Factory.obj"
	-@erase "$(INTDIR)\Freserve.obj"
	-@erase "$(INTDIR)\freserve.pch"
	-@erase "$(INTDIR)\Freserve.res"
	-@erase "$(INTDIR)\iball_i.obj"
	-@erase "$(INTDIR)\Preserve.obj"
	-@erase "$(INTDIR)\Server.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\freserve.dll"
	-@erase "$(OUTDIR)\freserve.exp"
	-@erase "$(OUTDIR)\freserve.ilk"
	-@erase "$(OUTDIR)\freserve.lib"
	-@erase "$(OUTDIR)\freserve.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WIN32"\
 /Fp"$(INTDIR)\freserve.pch" /Yu"preserve.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"\
 /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Freserve.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\freserve.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)\freserve.pdb" /debug /machine:I386 /nodefaultlib:"libc.lib"\
 /def:".\Freserve.def" /out:"$(OUTDIR)\freserve.dll"\
 /implib:"$(OUTDIR)\freserve.lib" 
DEF_FILE= \
	".\Freserve.def"
LINK32_OBJS= \
	"$(INTDIR)\Apputil.obj" \
	"$(INTDIR)\Ball.obj" \
	"$(INTDIR)\Factory.obj" \
	"$(INTDIR)\Freserve.obj" \
	"$(INTDIR)\Freserve.res" \
	"$(INTDIR)\iball_i.obj" \
	"$(INTDIR)\Preserve.obj" \
	"$(INTDIR)\Server.obj"

"$(OUTDIR)\freserve.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Debug
TargetPath=.\Debug\freserve.dll
InputPath=.\Debug\freserve.dll
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

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


!IF "$(CFG)" == "freserve - Win32 Release" || "$(CFG)" ==\
 "freserve - Win32 Debug"
SOURCE=.\Apputil.cpp
DEP_CPP_APPUT=\
	".\apputil.h"\
	

!IF  "$(CFG)" == "freserve - Win32 Release"


"$(INTDIR)\Apputil.obj" : $(SOURCE) $(DEP_CPP_APPUT) "$(INTDIR)"
	$(CPP) /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WIN32"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ELSEIF  "$(CFG)" == "freserve - Win32 Debug"


"$(INTDIR)\Apputil.obj" : $(SOURCE) $(DEP_CPP_APPUT) "$(INTDIR)"
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WIN32"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ENDIF 

SOURCE=.\Ball.cpp
DEP_CPP_BALL_=\
	".\ball.h"\
	

"$(INTDIR)\Ball.obj" : $(SOURCE) $(DEP_CPP_BALL_) "$(INTDIR)"\
 "$(INTDIR)\freserve.pch"


SOURCE=.\Factory.cpp
DEP_CPP_FACTO=\
	".\ball.h"\
	".\factory.h"\
	

"$(INTDIR)\Factory.obj" : $(SOURCE) $(DEP_CPP_FACTO) "$(INTDIR)"\
 "$(INTDIR)\freserve.pch"


SOURCE=.\Freserve.cpp
DEP_CPP_FRESE=\
	".\factory.h"\
	

!IF  "$(CFG)" == "freserve - Win32 Release"


"$(INTDIR)\Freserve.obj" : $(SOURCE) $(DEP_CPP_FRESE) "$(INTDIR)"\
 "$(INTDIR)\freserve.pch"
	$(CPP) /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WIN32"\
 /Fp"$(INTDIR)\freserve.pch" /Yu"preserve.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"\
 /FD /c $(SOURCE)


!ELSEIF  "$(CFG)" == "freserve - Win32 Debug"


"$(INTDIR)\Freserve.obj" : $(SOURCE) $(DEP_CPP_FRESE) "$(INTDIR)"\
 "$(INTDIR)\freserve.pch"
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WIN32"\
 /Fp"$(INTDIR)\freserve.pch" /Yu"preserve.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"\
 /FD /c $(SOURCE)


!ENDIF 

SOURCE=.\Freserve.def
SOURCE=.\Freserve.rc
DEP_RSC_FRESER=\
	".\apputil.h"\
	".\freserve.ico"\
	".\server.h"\
	

"$(INTDIR)\Freserve.res" : $(SOURCE) $(DEP_RSC_FRESER) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\iball_i.c

!IF  "$(CFG)" == "freserve - Win32 Release"


"$(INTDIR)\iball_i.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WIN32"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ELSEIF  "$(CFG)" == "freserve - Win32 Debug"


"$(INTDIR)\iball_i.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WIN32"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ENDIF 

SOURCE=.\Preserve.cpp

!IF  "$(CFG)" == "freserve - Win32 Release"

DEP_CPP_PRESE=\
	".\apputil.h"\
	".\iball.h"\
	".\preserve.h"\
	".\server.h"\
	

"$(INTDIR)\Preserve.obj"	"$(INTDIR)\freserve.pch" : $(SOURCE) $(DEP_CPP_PRESE)\
 "$(INTDIR)"
	$(CPP) /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WIN32"\
 /Fp"$(INTDIR)\freserve.pch" /Yc"preserve.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"\
 /FD /c $(SOURCE)


!ELSEIF  "$(CFG)" == "freserve - Win32 Debug"

DEP_CPP_PRESE=\
	".\apputil.h"\
	".\iball.h"\
	".\preserve.h"\
	".\server.h"\
	

"$(INTDIR)\Preserve.obj"	"$(INTDIR)\freserve.pch" : $(SOURCE) $(DEP_CPP_PRESE)\
 "$(INTDIR)"
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WIN32"\
 /Fp"$(INTDIR)\freserve.pch" /Yc"preserve.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"\
 /FD /c $(SOURCE)


!ENDIF 

SOURCE=.\Server.cpp

"$(INTDIR)\Server.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\freserve.pch"



!ENDIF 

