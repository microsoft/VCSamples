# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=CatDB - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to CatDB - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "CatDB - Win32 Release" && "$(CFG)" !=\
 "CatDB - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "CatDB.mak" CFG="CatDB - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CatDB - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "CatDB - Win32 Debug" (based on "Win32 (x86) Application")
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
# PROP Target_Last_Scanned "CatDB - Win32 Debug"
MTL=mktyplib.exe
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "CatDB - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\CatDB.exe"

CLEAN : 
	-@erase "$(INTDIR)\Cat3Doc.obj"
	-@erase "$(INTDIR)\Cat3View.obj"
	-@erase "$(INTDIR)\CatDB.obj"
	-@erase "$(INTDIR)\CatDB.pch"
	-@erase "$(INTDIR)\CatDB.res"
	-@erase "$(INTDIR)\colpage.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\tablepag.obj"
	-@erase "$(OUTDIR)\CatDB.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/CatDB.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/CatDB.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/CatDB.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/CatDB.pdb" /machine:I386 /out:"$(OUTDIR)/CatDB.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Cat3Doc.obj" \
	"$(INTDIR)\Cat3View.obj" \
	"$(INTDIR)\CatDB.obj" \
	"$(INTDIR)\CatDB.res" \
	"$(INTDIR)\colpage.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\tablepag.obj"

"$(OUTDIR)\CatDB.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CatDB - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "$(OUTDIR)\CatDB.exe"

CLEAN : 
	-@erase "$(INTDIR)\Cat3Doc.obj"
	-@erase "$(INTDIR)\Cat3View.obj"
	-@erase "$(INTDIR)\CatDB.obj"
	-@erase "$(INTDIR)\CatDB.pch"
	-@erase "$(INTDIR)\CatDB.res"
	-@erase "$(INTDIR)\colpage.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\tablepag.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\CatDB.exe"
	-@erase "$(OUTDIR)\CatDB.ilk"
	-@erase "$(OUTDIR)\CatDB.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /Fp"$(INTDIR)/CatDB.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/CatDB.res" /d "_DEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/CatDB.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/CatDB.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/CatDB.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Cat3Doc.obj" \
	"$(INTDIR)\Cat3View.obj" \
	"$(INTDIR)\CatDB.obj" \
	"$(INTDIR)\CatDB.res" \
	"$(INTDIR)\colpage.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\tablepag.obj"

"$(OUTDIR)\CatDB.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

# Name "CatDB - Win32 Release"
# Name "CatDB - Win32 Debug"

!IF  "$(CFG)" == "CatDB - Win32 Release"

!ELSEIF  "$(CFG)" == "CatDB - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\ReadMe.txt

!IF  "$(CFG)" == "CatDB - Win32 Release"

!ELSEIF  "$(CFG)" == "CatDB - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CatDB.cpp
DEP_CPP_CATAL=\
	".\Cat3Doc.h"\
	".\Cat3View.h"\
	".\CatDB.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\mecbase.h"\
	

"$(INTDIR)\CatDB.obj" : $(SOURCE) $(DEP_CPP_CATAL) "$(INTDIR)"\
 "$(INTDIR)\CatDB.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	"..\..\..\mec10\include\mecodbc.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\mecbase.h"\
	{$(INCLUDE)}"\mecdb.h"\
	{$(INCLUDE)}"\mecdb.inl"\
	{$(INCLUDE)}"\mecodbc.inl"\
	

!IF  "$(CFG)" == "CatDB - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS"\
 /Fp"$(INTDIR)/CatDB.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\CatDB.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "CatDB - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /Fp"$(INTDIR)/CatDB.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\CatDB.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	"..\..\..\mec10\include\mecodbc.h"\
	".\CatDB.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\mecbase.h"\
	{$(INCLUDE)}"\mecdb.h"\
	{$(INCLUDE)}"\mecdb.inl"\
	{$(INCLUDE)}"\mecodbc.inl"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\CatDB.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Cat3Doc.cpp
DEP_CPP_CAT3D=\
	".\Cat3Doc.h"\
	".\CatDB.h"\
	".\colpage.h"\
	".\StdAfx.h"\
	".\tablepag.h"\
	{$(INCLUDE)}"\mecbase.h"\
	

"$(INTDIR)\Cat3Doc.obj" : $(SOURCE) $(DEP_CPP_CAT3D) "$(INTDIR)"\
 "$(INTDIR)\CatDB.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Cat3View.cpp
DEP_CPP_CAT3V=\
	"..\..\..\mec10\include\mecodbc.h"\
	".\Cat3Doc.h"\
	".\Cat3View.h"\
	".\CatDB.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\mecbase.h"\
	{$(INCLUDE)}"\mecdb.h"\
	{$(INCLUDE)}"\mecdb.inl"\
	{$(INCLUDE)}"\mecodbc.inl"\
	

"$(INTDIR)\Cat3View.obj" : $(SOURCE) $(DEP_CPP_CAT3V) "$(INTDIR)"\
 "$(INTDIR)\CatDB.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\CatDB.rc
DEP_RSC_CATALO=\
	".\res\Cat3Doc.ico"\
	".\res\CatDB.ico"\
	".\res\CatDB.rc2"\
	".\res\toolbar1.bmp"\
	

"$(INTDIR)\CatDB.res" : $(SOURCE) $(DEP_RSC_CATALO) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\colpage.cpp
DEP_CPP_COLPA=\
	"..\..\..\mec10\include\mecodbc.h"\
	".\CatDB.h"\
	".\colpage.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\mecbase.h"\
	{$(INCLUDE)}"\mecdb.h"\
	{$(INCLUDE)}"\mecdb.inl"\
	{$(INCLUDE)}"\mecodbc.inl"\
	

"$(INTDIR)\colpage.obj" : $(SOURCE) $(DEP_CPP_COLPA) "$(INTDIR)"\
 "$(INTDIR)\CatDB.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\tablepag.cpp
DEP_CPP_TABLE=\
	"..\..\..\mec10\include\mecodbc.h"\
	".\CatDB.h"\
	".\StdAfx.h"\
	".\tablepag.h"\
	{$(INCLUDE)}"\mecbase.h"\
	{$(INCLUDE)}"\mecdb.h"\
	{$(INCLUDE)}"\mecdb.inl"\
	{$(INCLUDE)}"\mecodbc.inl"\
	

"$(INTDIR)\tablepag.obj" : $(SOURCE) $(DEP_CPP_TABLE) "$(INTDIR)"\
 "$(INTDIR)\CatDB.pch"


# End Source File
# End Target
# End Project
################################################################################
