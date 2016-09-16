# Microsoft Visual C++ Generated NMAKE File, Format Version 40000
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=Container - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Container - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Container - Win32 Release" && "$(CFG)" !=\
 "Container - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "Contain.mak" CFG="Container - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Container - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Container - Win32 Debug" (based on "Win32 (x86) Application")
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
CPP=cl.exe
RSC=rc.exe
MTL=mktyplib.exe

!IF  "$(CFG)" == "Container - Win32 Release"

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

ALL : "$(OUTDIR)\Contain.exe"

CLEAN : 
	-@erase ".\Release\Contain.exe"
	-@erase ".\Release\Contain.obj"
	-@erase ".\Release\Contain.pch"
	-@erase ".\Release\StdAfx.obj"
	-@erase ".\Release\MainFrm.obj"
	-@erase ".\Release\ChildFrm.obj"
	-@erase ".\Release\ContrDoc.obj"
	-@erase ".\Release\ContrVw.obj"
	-@erase ".\Release\CntrItem.obj"
	-@erase ".\Release\Contain.res"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Contain.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/"\
 /c 
CPP_OBJS=.\Release/
CPP_SBRS=
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Contain.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Contain.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/Contain.pdb" /machine:I386 /out:"$(OUTDIR)/Contain.exe" 
LINK32_OBJS= \
	"$(INTDIR)/Contain.obj" \
	"$(INTDIR)/StdAfx.obj" \
	"$(INTDIR)/MainFrm.obj" \
	"$(INTDIR)/ChildFrm.obj" \
	"$(INTDIR)/ContrDoc.obj" \
	"$(INTDIR)/ContrVw.obj" \
	"$(INTDIR)/CntrItem.obj" \
	"$(INTDIR)/Contain.res"

"$(OUTDIR)\Contain.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Container - Win32 Debug"

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

ALL : "$(OUTDIR)\Contain.exe"

CLEAN : 
	-@erase ".\Debug\Contain.exe"
	-@erase ".\Debug\Contain.obj"
	-@erase ".\Debug\Contain.pch"
	-@erase ".\Debug\StdAfx.obj"
	-@erase ".\Debug\MainFrm.obj"
	-@erase ".\Debug\ChildFrm.obj"
	-@erase ".\Debug\ContrDoc.obj"
	-@erase ".\Debug\ContrVw.obj"
	-@erase ".\Debug\CntrItem.obj"
	-@erase ".\Debug\Contain.res"
	-@erase ".\Debug\Contain.ilk"
	-@erase ".\Debug\Contain.pdb"
	-@erase ".\Debug\vc40.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Contain.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Contain.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Contain.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/Contain.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/Contain.exe" 
LINK32_OBJS= \
	"$(INTDIR)/Contain.obj" \
	"$(INTDIR)/StdAfx.obj" \
	"$(INTDIR)/MainFrm.obj" \
	"$(INTDIR)/ChildFrm.obj" \
	"$(INTDIR)/ContrDoc.obj" \
	"$(INTDIR)/ContrVw.obj" \
	"$(INTDIR)/CntrItem.obj" \
	"$(INTDIR)/Contain.res"

"$(OUTDIR)\Contain.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

# Name "Container - Win32 Release"
# Name "Container - Win32 Debug"

!IF  "$(CFG)" == "Container - Win32 Release"

!ELSEIF  "$(CFG)" == "Container - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\ReadMe.txt

!IF  "$(CFG)" == "Container - Win32 Release"

!ELSEIF  "$(CFG)" == "Container - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Contain.cpp
DEP_CPP_CONTA=\
	".\ChildFrm.h"\
	".\Contain.h"\
	".\ContrDoc.h"\
	".\ContrVw.h"\
	".\MainFrm.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Container - Win32 Release"


"$(INTDIR)\Contain.obj" : $(SOURCE) $(DEP_CPP_CONTA) "$(INTDIR)"\
 "$(INTDIR)\Contain.pch"


!ELSEIF  "$(CFG)" == "Container - Win32 Debug"


"$(INTDIR)\Contain.obj" : $(SOURCE) $(DEP_CPP_CONTA) "$(INTDIR)"\
 "$(INTDIR)\Contain.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_CONTA) "$(INTDIR)"\
 "$(INTDIR)\Contain.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Container - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Contain.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/"\
 /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Contain.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Container - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Contain.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Contain.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\Contain.h"\
	".\MainFrm.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Container - Win32 Release"


"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\Contain.pch"


!ELSEIF  "$(CFG)" == "Container - Win32 Debug"


"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\Contain.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\Contain.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChildFrm.cpp
DEP_CPP_CHILD=\
	".\ChildFrm.h"\
	".\Contain.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Container - Win32 Release"


"$(INTDIR)\ChildFrm.obj" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\Contain.pch"


!ELSEIF  "$(CFG)" == "Container - Win32 Debug"


"$(INTDIR)\ChildFrm.obj" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\Contain.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\Contain.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ContrDoc.cpp
DEP_CPP_CONTR=\
	".\CntrItem.h"\
	".\Contain.h"\
	".\ContrDoc.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Container - Win32 Release"


"$(INTDIR)\ContrDoc.obj" : $(SOURCE) $(DEP_CPP_CONTR) "$(INTDIR)"\
 "$(INTDIR)\Contain.pch"


!ELSEIF  "$(CFG)" == "Container - Win32 Debug"


"$(INTDIR)\ContrDoc.obj" : $(SOURCE) $(DEP_CPP_CONTR) "$(INTDIR)"\
 "$(INTDIR)\Contain.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_CONTR) "$(INTDIR)"\
 "$(INTDIR)\Contain.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ContrVw.cpp
DEP_CPP_CONTRV=\
	".\CntrItem.h"\
	".\Contain.h"\
	".\ContrDoc.h"\
	".\ContrVw.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Container - Win32 Release"


"$(INTDIR)\ContrVw.obj" : $(SOURCE) $(DEP_CPP_CONTRV) "$(INTDIR)"\
 "$(INTDIR)\Contain.pch"


!ELSEIF  "$(CFG)" == "Container - Win32 Debug"


"$(INTDIR)\ContrVw.obj" : $(SOURCE) $(DEP_CPP_CONTRV) "$(INTDIR)"\
 "$(INTDIR)\Contain.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_CONTRV) "$(INTDIR)"\
 "$(INTDIR)\Contain.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CntrItem.cpp
DEP_CPP_CNTRI=\
	".\CntrItem.h"\
	".\Contain.h"\
	".\ContrDoc.h"\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "Container - Win32 Release"


"$(INTDIR)\CntrItem.obj" : $(SOURCE) $(DEP_CPP_CNTRI) "$(INTDIR)"\
 "$(INTDIR)\Contain.pch"


!ELSEIF  "$(CFG)" == "Container - Win32 Debug"


"$(INTDIR)\CntrItem.obj" : $(SOURCE) $(DEP_CPP_CNTRI) "$(INTDIR)"\
 "$(INTDIR)\Contain.pch"

"$(INTDIR)\vc40.pdb" : $(SOURCE) $(DEP_CPP_CNTRI) "$(INTDIR)"\
 "$(INTDIR)\Contain.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Contain.rc
DEP_RSC_CONTAI=\
	".\res\Contain.ico"\
	".\res\ContrDoc.ico"\
	".\res\Toolbar.bmp"\
	".\res\Contain.rc2"\
	

"$(INTDIR)\Contain.res" : $(SOURCE) $(DEP_RSC_CONTAI) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
# End Target
# End Project
################################################################################
