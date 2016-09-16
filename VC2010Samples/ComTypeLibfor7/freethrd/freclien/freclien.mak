# Microsoft Developer Studio Generated NMAKE File, Based on freclien.dsp
!IF "$(CFG)" == ""
CFG=freclien - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to freclien - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "freclien - Win32 Release" && "$(CFG)" !=\
 "freclien - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "freclien.mak" CFG="freclien - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "freclien - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "freclien - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "freclien - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\freclien.exe"

CLEAN : 
	-@erase "$(INTDIR)\Apputil.obj"
	-@erase "$(INTDIR)\Freclien.obj"
	-@erase "$(INTDIR)\freclien.pch"
	-@erase "$(INTDIR)\Freclien.res"
	-@erase "$(INTDIR)\Guiball.obj"
	-@erase "$(INTDIR)\preclien.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\freclien.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WIN32" /D\
 _WIN32_WINNT=0x0400 /Fp"$(INTDIR)\freclien.pch" /Yu"preclien.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Freclien.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\freclien.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\freclien.pdb" /machine:I386 /nodefaultlib:"libc.lib"\
 /out:"$(OUTDIR)\freclien.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Apputil.obj" \
	"$(INTDIR)\Freclien.obj" \
	"$(INTDIR)\Freclien.res" \
	"$(INTDIR)\Guiball.obj" \
	"$(INTDIR)\preclien.obj"

"$(OUTDIR)\freclien.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "freclien - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\freclien.exe"

CLEAN : 
	-@erase "$(INTDIR)\Apputil.obj"
	-@erase "$(INTDIR)\Freclien.obj"
	-@erase "$(INTDIR)\freclien.pch"
	-@erase "$(INTDIR)\Freclien.res"
	-@erase "$(INTDIR)\Guiball.obj"
	-@erase "$(INTDIR)\preclien.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\freclien.exe"
	-@erase "$(OUTDIR)\freclien.ilk"
	-@erase "$(OUTDIR)\freclien.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WIN32" /D\
 _WIN32_WINNT=0x0400 /Fp"$(INTDIR)\freclien.pch" /Yu"preclien.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Freclien.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\freclien.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\freclien.pdb" /debug /machine:I386 /nodefaultlib:"libc.lib"\
 /out:"$(OUTDIR)\freclien.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Apputil.obj" \
	"$(INTDIR)\Freclien.obj" \
	"$(INTDIR)\Freclien.res" \
	"$(INTDIR)\Guiball.obj" \
	"$(INTDIR)\preclien.obj"

"$(OUTDIR)\freclien.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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


!IF "$(CFG)" == "freclien - Win32 Release" || "$(CFG)" ==\
 "freclien - Win32 Debug"
SOURCE=.\Apputil.cpp
DEP_CPP_APPUT=\
	"..\server\apputil.h"\
	

!IF  "$(CFG)" == "freclien - Win32 Release"


"$(INTDIR)\Apputil.obj" : $(SOURCE) $(DEP_CPP_APPUT) "$(INTDIR)"
	$(CPP) /nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WIN32" /D\
 _WIN32_WINNT=0x0400 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ELSEIF  "$(CFG)" == "freclien - Win32 Debug"


"$(INTDIR)\Apputil.obj" : $(SOURCE) $(DEP_CPP_APPUT) "$(INTDIR)"
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WIN32" /D\
 _WIN32_WINNT=0x0400 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ENDIF 

SOURCE=.\Freclien.cpp

"$(INTDIR)\Freclien.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\freclien.pch"


SOURCE=.\Freclien.rc
DEP_RSC_FRECL=\
	".\freclien.h"\
	".\freclien.ico"\
	

"$(INTDIR)\Freclien.res" : $(SOURCE) $(DEP_RSC_FRECL) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\Guiball.cpp

"$(INTDIR)\Guiball.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\freclien.pch"


SOURCE=.\preclien.cpp

!IF  "$(CFG)" == "freclien - Win32 Release"

DEP_CPP_PRECL=\
	"..\server\apputil.h"\
	"..\server\iball.tlb"\
	".\freclien.h"\
	".\guiball.h"\
	".\preclien.h"\
	

"$(INTDIR)\preclien.obj"	"$(INTDIR)\freclien.pch" : $(SOURCE) $(DEP_CPP_PRECL)\
 "$(INTDIR)"
	$(CPP) /nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WIN32" /D\
 _WIN32_WINNT=0x0400 /Fp"$(INTDIR)\freclien.pch" /Yc"preclien.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ELSEIF  "$(CFG)" == "freclien - Win32 Debug"

DEP_CPP_PRECL=\
	"..\server\apputil.h"\
	"..\server\iball.tlb"\
	".\freclien.h"\
	".\guiball.h"\
	".\preclien.h"\
	

"$(INTDIR)\preclien.obj"	"$(INTDIR)\freclien.pch" : $(SOURCE) $(DEP_CPP_PRECL)\
 "$(INTDIR)"
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WIN32" /D\
 _WIN32_WINNT=0x0400 /Fp"$(INTDIR)\freclien.pch" /Yc"preclien.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c $(SOURCE)


!ENDIF 


!ENDIF 

