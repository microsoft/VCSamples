# Microsoft Developer Studio Generated NMAKE File, Based on ATLDraw.dsp
!IF "$(CFG)" == ""
CFG=ATLDraw - Win32 Release
!MESSAGE No configuration specified. Defaulting to ATLDraw - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "ATLDraw - Win32 Release" && "$(CFG)" !=\
 "ATLDraw - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ATLDraw.mak" CFG="ATLDraw - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ATLDraw - Win32 Release" (based on "Win32 (x86) Win32 Application")
!MESSAGE "ATLDraw - Win32 Debug" (based on "Win32 (x86) Win32 Application")
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

!IF  "$(CFG)" == "ATLDraw - Win32 Release"

OUTDIR=.
INTDIR=.\Release
# Begin Custom Macros
OutDir=.
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\ATLDraw.exe" "$(OUTDIR)\ATLDraw.bsc"

!ELSE 

ALL : "$(OUTDIR)\ATLDraw.exe" "$(OUTDIR)\ATLDraw.bsc"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ATLDDoc.obj"
	-@erase "$(INTDIR)\ATLDDoc.sbr"
	-@erase "$(INTDIR)\ATLDraw.obj"
	-@erase "$(INTDIR)\ATLDraw.res"
	-@erase "$(INTDIR)\ATLDraw.sbr"
	-@erase "$(INTDIR)\ATLDView.obj"
	-@erase "$(INTDIR)\ATLDView.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\preatldr.obj"
	-@erase "$(INTDIR)\preatldr.sbr"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\ATLDraw.bsc"
	-@erase "$(OUTDIR)\ATLDraw.exe"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_MBCS" /D "_WIN32_DCOM" /D "_AFXDLL" /FR"$(INTDIR)\\"\
 /Fp"$(INTDIR)\ATLDraw.pch" /YX"preatldr.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"\
 /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\Release/
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ATLDraw.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ATLDraw.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\ATLDDoc.sbr" \
	"$(INTDIR)\ATLDraw.sbr" \
	"$(INTDIR)\ATLDView.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\preatldr.sbr"

"$(OUTDIR)\ATLDraw.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\ATLDraw.pdb" /machine:I386 /out:"$(OUTDIR)\ATLDraw.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ATLDDoc.obj" \
	"$(INTDIR)\ATLDraw.obj" \
	"$(INTDIR)\ATLDraw.res" \
	"$(INTDIR)\ATLDView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\preatldr.obj"

"$(OUTDIR)\ATLDraw.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ATLDraw - Win32 Debug"

OUTDIR=.
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\ATLDraw.exe" "$(OUTDIR)\ATLDraw.bsc"

!ELSE 

ALL : "$(OUTDIR)\ATLDraw.exe" "$(OUTDIR)\ATLDraw.bsc"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ATLDDoc.obj"
	-@erase "$(INTDIR)\ATLDDoc.sbr"
	-@erase "$(INTDIR)\ATLDraw.obj"
	-@erase "$(INTDIR)\ATLDraw.pch"
	-@erase "$(INTDIR)\ATLDraw.res"
	-@erase "$(INTDIR)\ATLDraw.sbr"
	-@erase "$(INTDIR)\ATLDView.obj"
	-@erase "$(INTDIR)\ATLDView.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\preatldr.obj"
	-@erase "$(INTDIR)\preatldr.sbr"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\ATLDraw.bsc"
	-@erase "$(OUTDIR)\ATLDraw.exe"
	-@erase "$(OUTDIR)\ATLDraw.ilk"
	-@erase "$(OUTDIR)\ATLDraw.pdb"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /D "_MBCS" /D "_WIN32_DCOM" /D "_AFXDLL" /FR"$(INTDIR)\\"\
 /Fp"$(INTDIR)\ATLDraw.pch" /Yu"preatldr.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"\
 /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\Debug/
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ATLDraw.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ATLDraw.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\ATLDDoc.sbr" \
	"$(INTDIR)\ATLDraw.sbr" \
	"$(INTDIR)\ATLDView.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\preatldr.sbr"

"$(OUTDIR)\ATLDraw.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\ATLDraw.pdb" /debug /machine:I386 /out:"$(OUTDIR)\ATLDraw.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ATLDDoc.obj" \
	"$(INTDIR)\ATLDraw.obj" \
	"$(INTDIR)\ATLDraw.res" \
	"$(INTDIR)\ATLDView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\preatldr.obj"

"$(OUTDIR)\ATLDraw.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

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


!IF "$(CFG)" == "ATLDraw - Win32 Release" || "$(CFG)" ==\
 "ATLDraw - Win32 Debug"
SOURCE=.\ATLDDoc.cpp

!IF  "$(CFG)" == "ATLDraw - Win32 Release"

DEP_CPP_ATLDD=\
	"..\drawserv\drawserv.tlb"\
	".\ATLDDoc.h"\
	".\ATLDraw.h"\
	".\preatldr.h"\
	

"$(INTDIR)\ATLDDoc.obj"	"$(INTDIR)\ATLDDoc.sbr" : $(SOURCE) $(DEP_CPP_ATLDD)\
 "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ATLDraw - Win32 Debug"

DEP_CPP_ATLDD=\
	".\ATLDDoc.h"\
	".\ATLDraw.h"\
	

"$(INTDIR)\ATLDDoc.obj"	"$(INTDIR)\ATLDDoc.sbr" : $(SOURCE) $(DEP_CPP_ATLDD)\
 "$(INTDIR)" "$(INTDIR)\ATLDraw.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\ATLDraw.cpp

!IF  "$(CFG)" == "ATLDraw - Win32 Release"

DEP_CPP_ATLDR=\
	"..\drawserv\drawserv.tlb"\
	".\ATLDDoc.h"\
	".\ATLDraw.h"\
	".\ATLDView.h"\
	".\MainFrm.h"\
	".\preatldr.h"\
	

"$(INTDIR)\ATLDraw.obj"	"$(INTDIR)\ATLDraw.sbr" : $(SOURCE) $(DEP_CPP_ATLDR)\
 "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ATLDraw - Win32 Debug"

DEP_CPP_ATLDR=\
	".\ATLDDoc.h"\
	".\ATLDraw.h"\
	".\ATLDView.h"\
	".\MainFrm.h"\
	

"$(INTDIR)\ATLDraw.obj"	"$(INTDIR)\ATLDraw.sbr" : $(SOURCE) $(DEP_CPP_ATLDR)\
 "$(INTDIR)" "$(INTDIR)\ATLDraw.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\ATLDraw.rc
DEP_RSC_ATLDRA=\
	".\res\ATLDDoc.ico"\
	".\res\ATLDraw.ico"\
	".\res\ATLDraw.rc2"\
	".\res\Toolbar.bmp"\
	

"$(INTDIR)\ATLDraw.res" : $(SOURCE) $(DEP_RSC_ATLDRA) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\ATLDView.cpp

!IF  "$(CFG)" == "ATLDraw - Win32 Release"

DEP_CPP_ATLDV=\
	"..\drawserv\drawserv.tlb"\
	".\ATLDDoc.h"\
	".\ATLDraw.h"\
	".\ATLDView.h"\
	".\preatldr.h"\
	

"$(INTDIR)\ATLDView.obj"	"$(INTDIR)\ATLDView.sbr" : $(SOURCE) $(DEP_CPP_ATLDV)\
 "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ATLDraw - Win32 Debug"

DEP_CPP_ATLDV=\
	".\ATLDDoc.h"\
	".\ATLDraw.h"\
	".\ATLDView.h"\
	

"$(INTDIR)\ATLDView.obj"	"$(INTDIR)\ATLDView.sbr" : $(SOURCE) $(DEP_CPP_ATLDV)\
 "$(INTDIR)" "$(INTDIR)\ATLDraw.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "ATLDraw - Win32 Release"

DEP_CPP_MAINF=\
	"..\drawserv\drawserv.tlb"\
	".\ATLDraw.h"\
	".\MainFrm.h"\
	".\preatldr.h"\
	

"$(INTDIR)\MainFrm.obj"	"$(INTDIR)\MainFrm.sbr" : $(SOURCE) $(DEP_CPP_MAINF)\
 "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "ATLDraw - Win32 Debug"

DEP_CPP_MAINF=\
	".\ATLDraw.h"\
	".\MainFrm.h"\
	

"$(INTDIR)\MainFrm.obj"	"$(INTDIR)\MainFrm.sbr" : $(SOURCE) $(DEP_CPP_MAINF)\
 "$(INTDIR)" "$(INTDIR)\ATLDraw.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\preatldr.cpp

!IF  "$(CFG)" == "ATLDraw - Win32 Release"

DEP_CPP_PREAT=\
	"..\drawserv\drawserv.tlb"\
	".\preatldr.h"\
	
CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_MBCS" /D "_WIN32_DCOM" /D "_AFXDLL" /FR"$(INTDIR)\\"\
 /Fp"$(INTDIR)\ATLDraw.pch" /YX"preatldr.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"\
 /FD /c 

"$(INTDIR)\preatldr.obj"	"$(INTDIR)\preatldr.sbr" : $(SOURCE) $(DEP_CPP_PREAT)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ATLDraw - Win32 Debug"

DEP_CPP_PREAT=\
	"..\drawserv\drawserv.tlb"\
	".\preatldr.h"\
	
CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_MBCS" /D "_WIN32_DCOM" /D "_AFXDLL" /FR"$(INTDIR)\\"\
 /Fp"$(INTDIR)\ATLDraw.pch" /Yc"preatldr.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\"\
 /FD /c 

"$(INTDIR)\preatldr.obj"	"$(INTDIR)\preatldr.sbr"	"$(INTDIR)\ATLDraw.pch" : \
$(SOURCE) $(DEP_CPP_PREAT) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\ReadMe.txt
SOURCE=.\ATLDDoc.h
SOURCE=.\ATLDraw.h
SOURCE=.\ATLDView.h
SOURCE=.\MainFrm.h
SOURCE=.\preatldr.h
SOURCE=.\res\ATLDDoc.ico
SOURCE=.\res\ATLDraw.ico
SOURCE=.\res\ATLDraw.rc2
SOURCE=.\res\Toolbar.bmp

!ENDIF 

