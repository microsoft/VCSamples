#/*+=========================================================================
#  File:       MAKEFILE
#
#  Summary:    Makefile for building the FRECLIEN.EXE binary.  FRECLIEN
#              is a simple Win32 EXE that acts as a client of the FRESERVE
#              DLL server to create and manipulate a free threaded COM
#              object from a multi-threaded client.
#
#              FRECLIEN specifically works with the FRESERVE.DLL produced
#              in the FRESERVE lesson (in sibling directory FRESERVE).
#              This Makefile therefore depends on a prior build (and the
#              resultant registration) of the FRESERVE.DLL server.
#
#              This Makefile creates a subdirectory (TEMP) for the
#              .OBJ and .RES files used during the build process.
#
#              For a comprehensive tutorial code tour of FRECLIEN's
#              contents and offerings see the accompanying FRECLIEN.TXT
#              file.  For more specific technical details see the comments
#              dispersed throughout the FRECLIEN source code.
#
#              See also FRESERVE.TXT (in the sibling FRESERVE directory)
#              more details on the FRESERVE server and how it works with
#              for FRECLIEN.EXE itself.
#
#              In general, to set up your system to build and test the
#              Win32 code samples in this OLE Tutorial series, see the
#              global TUTORIAL.TXT file for details.  This MAKEFILE is
#              Microsoft NMAKE compatible and the 'debug' build can be
#              achieved by simply issuing the NMAKE command in the
#              command prompt window.
#
#  Builds:     FRECLIEN.EXE
#
#  Origin:     4-6-96: atrent - Editor-inheritance from DLLCLIEN makefile.
#
#--Usage:-------------------------------------------------------------------
#  NMAKE Options
#
#  Use the table below to determine the additional options for NMAKE to
#  generate various application debugging, profiling and performance tuning
#  information.
#
#  Application Information Type         Invoke NMAKE
#  ----------------------------         ------------
#  For No Debugging Info                nmake nodebug=1
#  For Working Set Tuner Info           nmake tune=1
#  For Call Attributed Profiling Info   nmake profile=1
#
#  Note: The three options above are mutually exclusive (you may use only
#        one to compile/link the application).
#
#  Note: creating the environment variables NODEBUG, TUNE, and PROFILE
#        is an alternate method to setting these options via the nmake
#        command line.
#
#  Additional NMAKE Options             Invoke NMAKE
#  ----------------------------         ------------
#  For No ANSI NULL Compliance          nmake no_ansi=1
#    (ANSI NULL is defined as PVOID 0)
#  To compile for Unicode               nmake unicode=1
#    (Default is ANSI)
#  To clean up temporary binaries       nmake clean
#  To clean up all generated files      nmake cleanall
#
#---------------------------------------------------------------------------
#  This file is part of the Microsoft OLE Tutorial Code Samples.
#
#  Copyright (c) Microsoft Corporation, 1996.  All rights reserved.
#
#  This source code is intended only as a supplement to Microsoft
#  Development Tools and/or on-line documentation.  See these other
#  materials for detailed information regarding Microsoft code samples.
#
#  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
#  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
#  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
#  PARTICULAR PURPOSE.
#=========================================================================+*/

#  WIN32.MAK should be included at the front of every Win32 makefile.
#
#  Define APPVER = [ 3.50 | 3.51 | 4.0 ] prior to including win32.mak to get
#  build time checking for version dependencies and to mark the executable
#  with version information.
#
#  Define TARGETOS = [ WIN95 | WINNT | BOTH ] prior to including win32.mak
#  to get some build time checking for platform dependencies.
#
APPVER=4.0
TARGETOS=WINNT
!include <win32.mak>

# Assign the main program name macro.
PGM=freclien

# Use a temporary sub-directory to store intermediate
# binary files like *.obj, *.res, *.map, etc.
TDIR = TEMP

# The sibling ..\INC and ..\LIB directories are added to the front of
# the INCLUDE and LIB macros to inform the compiler and linker of
# these application-specific locations for include and lib files.
INCLUDE=..\inc;$(INCLUDE)
LIB=..\lib;$(LIB)

LINK = $(link)

# If UNICODE=1 is defined then define UNICODE during Compiles.
# The default is to compile with ANSI for running under both
# Win95 and WinNT.
!IFDEF UNICODE
LINKFLAGS = $(ldebug) /NOD:libc.lib /NOD:msvcrt.lib /NOD:libcd.lib \
  /NOD:libcmtd.lib /NOD:msvcrtd.lib
CDBG=$(cdebug) -DUNICODE -D_UNICODE
RCFLAGS = -DWIN32 -DRC_INCLUDE -DUNICODE
!ELSE
LINKFLAGS = $(ldebug) /NOD:libc.lib /NOD:msvcrt.lib /NOD:libcd.lib \
  /NOD:libcmtd.lib /NOD:msvcrtd.lib
CDBG=$(cdebug)
RCFLAGS = -DWIN32 -DRC_INCLUDE
!ENDIF

# If NODEBUG is not defined then define DEBUG during Compiles.
# The default is to compile with debug symbols in the binaries.
!IFNDEF NODEBUG
CDBG = $(CDBG) -DDEBUG
RCFLAGS = $(RCFLAGS) -DDEBUG
!ENDIF

# APPLIBS are libraries used by this application that are outside
#   of its indigenous file set and are needed during the final link.
APPLIBS = apputil.lib

# PGMOBJS is a macro that defines the object files for this application.
PGMOBJS = $(TDIR)\$(PGM).obj $(TDIR)\guiball.obj

# The final target.
all: tempdir output

# Make the temporary work sub-directory.
tempdir:
  -mkdir $(TDIR)

# The actual output products.
output: $(PGM).exe

# Compilation/Dependency rules for the main source files.
$(TDIR)\$(PGM).obj: $(PGM).cpp $(PGM).h
  $(cc) $(cvarsmt) $(cflags) $(CDBG) -Fo$@ $(PGM).cpp

$(TDIR)\guiball.obj: guiball.cpp guiball.h
  $(cc) $(cvarsmt) $(cflags) $(CDBG) -Fo$@ guiball.cpp

# Compile the resources.
$(TDIR)\$(PGM).res: $(PGM).rc $(PGM).ico $(PGM).h
  rc $(RCFLAGS) -r -fo$@ $(PGM).rc

# Link the object and resource binaries into the final target binary.
$(PGM).exe: $(PGMOBJS) $(TDIR)\$(PGM).res
  $(LINK) @<<
    $(LINKFLAGS)
    -out:$@
    -map:$(TDIR)\$*.map
    $(PGMOBJS)
    $(TDIR)\$*.res
    $(olelibsmt) $(APPLIBS)
<<

# Target to clean up temporary binaries.
clean:
  -del $(PGM).pdb
  -deltree /y $(TDIR)
  -rmdir /s /q $(TDIR)

# Target to clean up all generated files.
cleanall:
  -del *.exe
  -del *.dll
  -del *.lib
  -del *.exp
  -del *.obj
  -del *.res
  -del *.map
  -del *.pdb
  -del *.vcp
  -del *.aps
  -del *.pch
  -del *.sbr
  -del *.bsc
  -del *.mdp
  -del *.ncb
  -del *.mak
  -del makefile.exe
  -del resource.h
  -deltree /y windebug
  -rmdir /s /q windebug
  -deltree /y winrel
  -rmdir /s /q winrel
  -deltree /y $(TDIR)
  -rmdir /s /q $(TDIR)
