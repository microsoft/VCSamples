#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

PROJ = ComSpyAudit
all:    $(OUTDIR) $(OUTDIR)\$(PROJ).dll

$(OUTDIR):
     if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

!IF  "$(PREFAST_ENABLED)" == "1"
$(cflags) = $(cflags) /analyze
!ENDIF

EXTRA_LIBS = odbccp32.lib odbc32.lib 

LINK32_OBJS = $(OUTDIR)\stdafx.obj \
              $(OUTDIR)\events.obj \
              $(OUTDIR)\comspysqlaudit.obj \
              $(OUTDIR)\comspyaudit.obj \
              $(OUTDIR)\comspyaudit.res

$(OUTDIR)\stdafx.obj:     stdafx.cpp
     $(cc) $(cflags) $(cdebug) $(cvarsdll) /D_ATL_MIN_CRT /D_ATL_STATIC_REGISTRY /D_UNICODE /D_USRDLL /I"..\comspyface\$(OUTDIR)" /Yc"stdafx.h" /Fp"$(OUTDIR)\\" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" stdafx.cpp

.cpp{$(OUTDIR)}.obj:
     $(cc) $(cflags) $(cdebug) $(cvarsdll) /D_ATL_MIN_CRT /D_ATL_STATIC_REGISTRY /D_UNICODE /D_USRDLL /I"..\comspyface\$(OUTDIR)" /Yu"stdafx.h" /Fp"$(OUTDIR)\\" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $**

$(OUTDIR)\comspyaudit.res:
     $(rc) $(rcflags) $(rcvars) /Fo$(OUTDIR)\comspyaudit.res /I"..\comspyface\$(OUTDIR)" comspyaudit.rc

$(OUTDIR)\$(PROJ).dll:   $(LINK32_OBJS)
     $(link) $(ldebug) $(dlllflags) $(olelibsdll) /MACHINE:$(CPU) /NODEFAULTLIB:atlmincrt.lib /PDB:$(OUTDIR)\$(PROJ).pdb -out:$(OUTDIR)\$(PROJ).dll /DEF:$(PROJ).def  $(LINK32_OBJS) $(EXTRA_LIBS)

clean:
     $(CLEANUP)
