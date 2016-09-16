#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>


PROJ = ComSpyCtl
all:    $(OUTDIR) $(OUTDIR)\$(PROJ).dll

$(OUTDIR):
     if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"


#EXTRA_LIBS = odbccp32.lib odbc32.lib advapi32.lib svcguid.lib 
EXTRA_LIBS=rpcrt4.lib shell32.lib

!IF ("$(CPU)" == "i386")
EXTRA_LIBS = $(EXTRA_LIBS) comsuppw.lib
!ENDIF

PREFAST_ENABLED = 1
!IFDEF  $(PREFAST_ENABLED)
$(cflags) = $(cflags) /analyze
!ENDIF

LINK32_OBJS = $(OUTDIR)\stdafx.obj \
              $(OUTDIR)\txsub.obj \
              $(OUTDIR)\syslcesub.obj \
              $(OUTDIR)\selecteventsdlg.obj \
              $(OUTDIR)\resourcesub.obj \
              $(OUTDIR)\methodsub.obj \
              $(OUTDIR)\evtstoresub.obj \
              $(OUTDIR)\crmsub.obj \
              $(OUTDIR)\comspyproppage.obj \
              $(OUTDIR)\comspyctl.obj \
              $(OUTDIR)\comspy.obj \
              $(OUTDIR)\appinfo.obj \
              $(OUTDIR)\adminwrap.obj \
              $(OUTDIR)\comspyctl.res

$(OUTDIR)\stdafx.obj:     stdafx.cpp
     $(cc) $(cflags) $(cdebug) $(cvarsdll) /EHsc /D_UNICODE /DUNICODE  /I"..\comspyface\$(OUTDIR)" /I"..\inc" /Yc"stdafx.h" /Fp"$(OUTDIR)\\" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" stdafx.cpp

.cpp{$(OUTDIR)}.obj:
     $(cc) $(cflags) $(cdebug) $(cvarsdll) /EHsc /D_UNICODE /DUNICODE  /I"..\comspyface\$(OUTDIR)" /I"..\inc" /Yu"stdafx.h" /Fp"$(OUTDIR)\\" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $**

$(OUTDIR)\comspyctl.res:
     $(rc) $(rcflags) $(rcvars) /Fo$(OUTDIR)\comspyctl.res /I"..\comspyface\$(OUTDIR)" comspyctl.rc

$(OUTDIR)\$(PROJ).dll:   $(LINK32_OBJS)
     $(link) $(ldebug) $(dlllflags) /MACHINE:$(CPU) /PDB:$(OUTDIR)\$(PROJ).pdb -out:$(OUTDIR)\$(PROJ).dll /DEF:comspyctl.def  /NODEFAULTLIB:libc.lib $(LINK32_OBJS) $(EXTRA_LIBS) $(baselibs) $(olelibs) 

clean:
     $(CLEANUP)
