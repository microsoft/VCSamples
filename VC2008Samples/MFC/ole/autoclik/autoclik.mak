# Microsoft Visual C++ Generated NMAKE File, Format Version 40000
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=AutoClik - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to AutoClik - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "AutoClik - Win32 Release" && "$(CFG)" !=\
 "AutoClik - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "autoclik.mak" CFG="AutoClik - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "AutoClik - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "AutoClik - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "AutoClik - Win32 Debug"
RSC=rc.exe
MTL=mktyplib.exe
CPP=cl.exe

!IF  "$(CFG)" == "AutoClik - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir Release
# PROP BASE Intermediate_Dir Release
# PROP BASE Target_Dir
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir Release
# PROP Intermediate_Dir Release
# PROP Target_Dir
OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\autoclik.exe" "$(OUTDIR)\autoclik.tlb"

CLEAN : 
	-@erase ".\Release\autoclik.tlb"
	-@erase ".\Release\autoclik.exe"
	-@erase ".\Release\stdafx.obj"
	-@erase ".\Release\mainfrm.obj"
	-@erase ".\Release\autoclik.pch"
	-@erase ".\Release\childfrm.obj"
	-@erase ".\Release\autoclik.obj"
	-@erase ".\Release\dialogs.obj"
	-@erase ".\Release\aclikvw.obj"
	-@erase ".\Release\aclikdoc.obj"
	-@erase ".\Release\autoclik.res"
	-@erase ".\Release\clikpnt.obj"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/autoclik.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/"\
 /c 
CPP_OBJS=.\Release/
CPP_SBRS=
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/autoclik.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/autoclik.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/autoclik.pdb" /machine:I386 /out:"$(OUTDIR)/autoclik.exe" 
LINK32_OBJS= \
	"$(INTDIR)/stdafx.obj" \
	"$(INTDIR)/mainfrm.obj" \
	"$(INTDIR)/childfrm.obj" \
	"$(INTDIR)/autoclik.obj" \
	"$(INTDIR)/dialogs.obj" \
	"$(INTDIR)/aclikvw.obj" \
	"$(INTDIR)/aclikdoc.obj" \
	"$(INTDIR)/clikpnt.obj" \
	"$(INTDIR)/autoclik.res"

"$(OUTDIR)\autoclik.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "AutoClik - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir Debug
# PROP BASE Intermediate_Dir Debug
# PROP BASE Target_Dir
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir Debug
# PROP Intermediate_Dir Debug
# PROP Target_Dir
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "$(OUTDIR)\autoclik.exe" "$(OUTDIR)\autoclik.tlb"

CLEAN : 
	-@erase ".\Debug\vc40.pdb"
	-@erase ".\Debug\autoclik.pch"
	-@erase ".\Debug\autoclik.tlb"
	-@erase ".\Debug\autoclik.exe"
	-@erase ".\Debug\dialogs.obj"
	-@erase ".\Debug\aclikvw.obj"
	-@erase ".\Debug\aclikdoc.obj"
	-@erase ".\Debug\mainfrm.obj"
	-@erase ".\Debug\childfrm.obj"
	-@erase ".\Debug\stdafx.obj"
	-@erase ".\Debug\autoclik.obj"
	-@erase ".\Debug\autoclik.res"
	-@erase ".\Debug\clikpnt.obj"
	-@erase ".\Debug\autoclik.ilk"
	-@erase ".\Debug\autoclik.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/autoclik.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/autoclik.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/autoclik.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/autoclik.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/autoclik.exe" 
LINK32_OBJS= \
	"$(INTDIR)/dialogs.obj" \
	"$(INTDIR)/aclikvw.obj" \
	"$(INTDIR)/aclikdoc.obj" \
	"$(INTDIR)/mainfrm.obj" \
	"$(INTDIR)/childfrm.obj" \
	"$(INTDIR)/stdafx.obj" \
	"$(INTDIR)/autoclik.obj" \
	"$(INTDIR)/clikpnt.obj" \
	"$(INTDIR)/autoclik.res"

"$(OUTDIR)\autoclik.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "AutoClik - Win32 Release"
# Name "AutoClik - Win32 Debug"

!IF  "$(CFG)" == "AutoClik - Win32 Release"

!ELSEIF  "$(CFG)" == "AutoClik - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\readme.txt

!IF  "$(CFG)" == "AutoClik - Win32 Release"

!ELSEIF  "$(CFG)" == "AutoClik - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\autoclik.cpp
DEP_CPP_AUTOC=\
	".\aclikdoc.h"\
	".\aclikvw.h"\
	".\autoclik.h"\
	".\childfrm.h"\
	".\mainfrm.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "AutoClik - Win32 Release"


"$(INTDIR)\autoclik.obj" : $(SOURCE) $(DEP_CPP_AUTOC) "$(INTDIR)"\
 "$(INTDIR)\autoclik.pch"


!ELSEIF  "$(CFG)" == "AutoClik - Win32 Debug"


"$(INTDIR)\autoclik.obj" : $(SOURCE) $(DEP_CPP_AUTOC) "$(INTDIR)"\
 "$(INTDIR)\autoclik.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_AUTOC) "$(INTDIR)"\
 "$(INTDIR)\autoclik.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\autoclik.odl

!IF  "$(CFG)" == "AutoClik - Win32 Release"


"$(OUTDIR)\autoclik.tlb" : $(SOURCE) "$(OUTDIR)"
   $(MTL) /nologo /D "NDEBUG" /tlb "$(OUTDIR)/autoclik.tlb" /win32 $(SOURCE)


!ELSEIF  "$(CFG)" == "AutoClik - Win32 Debug"


"$(OUTDIR)\autoclik.tlb" : $(SOURCE) "$(OUTDIR)"
   $(MTL) /nologo /D "_DEBUG" /tlb "$(OUTDIR)/autoclik.tlb" /win32 $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\stdafx.cpp
DEP_CPP_STDAF=\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "AutoClik - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/autoclik.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/"\
 /c $(SOURCE) \
	

"$(INTDIR)\stdafx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\autoclik.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "AutoClik - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/autoclik.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\stdafx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\autoclik.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\mainfrm.cpp
DEP_CPP_MAINF=\
	".\autoclik.h"\
	".\mainfrm.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "AutoClik - Win32 Release"


"$(INTDIR)\mainfrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\autoclik.pch"


!ELSEIF  "$(CFG)" == "AutoClik - Win32 Debug"


"$(INTDIR)\mainfrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\autoclik.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\autoclik.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\childfrm.cpp
DEP_CPP_CHILD=\
	".\autoclik.h"\
	".\childfrm.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "AutoClik - Win32 Release"


"$(INTDIR)\childfrm.obj" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\autoclik.pch"


!ELSEIF  "$(CFG)" == "AutoClik - Win32 Debug"


"$(INTDIR)\childfrm.obj" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\autoclik.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\autoclik.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\aclikdoc.cpp
DEP_CPP_ACLIK=\
	".\aclikdoc.h"\
	".\autoclik.h"\
	".\ClikPnt.h"\
	".\dialogs.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "AutoClik - Win32 Release"


"$(INTDIR)\aclikdoc.obj" : $(SOURCE) $(DEP_CPP_ACLIK) "$(INTDIR)"\
 "$(INTDIR)\autoclik.pch"


!ELSEIF  "$(CFG)" == "AutoClik - Win32 Debug"


"$(INTDIR)\aclikdoc.obj" : $(SOURCE) $(DEP_CPP_ACLIK) "$(INTDIR)"\
 "$(INTDIR)\autoclik.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_ACLIK) "$(INTDIR)"\
 "$(INTDIR)\autoclik.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\aclikvw.cpp
DEP_CPP_ACLIKV=\
	".\aclikdoc.h"\
	".\aclikvw.h"\
	".\autoclik.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "AutoClik - Win32 Release"


"$(INTDIR)\aclikvw.obj" : $(SOURCE) $(DEP_CPP_ACLIKV) "$(INTDIR)"\
 "$(INTDIR)\autoclik.pch"


!ELSEIF  "$(CFG)" == "AutoClik - Win32 Debug"


"$(INTDIR)\aclikvw.obj" : $(SOURCE) $(DEP_CPP_ACLIKV) "$(INTDIR)"\
 "$(INTDIR)\autoclik.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_ACLIKV) "$(INTDIR)"\
 "$(INTDIR)\autoclik.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\autoclik.rc
DEP_RSC_AUTOCL=\
	".\res\AUTOCLIK.ICO"\
	".\res\aclikdoc.ico"\
	".\res\TOOLBAR.BMP"\
	".\res\AUTOCLIK.RC2"\
	

!IF  "$(CFG)" == "AutoClik - Win32 Release"


"$(INTDIR)\autoclik.res" : $(SOURCE) $(DEP_RSC_AUTOCL) "$(INTDIR)"
   $(RSC) /l 0x409 /fo"$(INTDIR)/autoclik.res" /i "Release" /d "NDEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "AutoClik - Win32 Debug"


"$(INTDIR)\autoclik.res" : $(SOURCE) $(DEP_RSC_AUTOCL) "$(INTDIR)"
   $(RSC) /l 0x409 /fo"$(INTDIR)/autoclik.res" /i "Debug" /d "_DEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\dialogs.cpp
DEP_CPP_DIALO=\
	".\autoclik.h"\
	".\dialogs.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "AutoClik - Win32 Release"


"$(INTDIR)\dialogs.obj" : $(SOURCE) $(DEP_CPP_DIALO) "$(INTDIR)"\
 "$(INTDIR)\autoclik.pch"


!ELSEIF  "$(CFG)" == "AutoClik - Win32 Debug"


"$(INTDIR)\dialogs.obj" : $(SOURCE) $(DEP_CPP_DIALO) "$(INTDIR)"\
 "$(INTDIR)\autoclik.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_DIALO) "$(INTDIR)"\
 "$(INTDIR)\autoclik.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\clikpnt.cpp
DEP_CPP_CLIKP=\
	".\autoclik.h"\
	".\ClikPnt.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "AutoClik - Win32 Release"


"$(INTDIR)\clikpnt.obj" : $(SOURCE) $(DEP_CPP_CLIKP) "$(INTDIR)"\
 "$(INTDIR)\autoclik.pch"


!ELSEIF  "$(CFG)" == "AutoClik - Win32 Debug"


"$(INTDIR)\clikpnt.obj" : $(SOURCE) $(DEP_CPP_CLIKP) "$(INTDIR)"\
 "$(INTDIR)\autoclik.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_CLIKP) "$(INTDIR)"\
 "$(INTDIR)\autoclik.pch"


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
