#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

PROJ = ComSpy
all:    $(OUTDIR) $(OUTDIR)\$(PROJ).exe

$(OUTDIR):
     if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

EXTRA_LIBS = svcguid.lib odbccp32.lib odbc32.lib shell32.lib advapi32.lib

!IF "$(CPU)" == "IA64"
EXTRA_LIBS = $(EXTRA_LIBS) atl21asm.lib
!ENDIF

!IF  "$(PREFAST_ENABLED)" == "1"
$(cflags) = $(cflags) /analyze
!ENDIF


LINK32_OBJS = $(OUTDIR)\stdafx.obj \
              $(OUTDIR)\spycon.obj \
              $(OUTDIR)\comspy.obj \
              $(OUTDIR)\comspy.res

$(OUTDIR)\comspy.h : comspy.idl
     $(midl) $(MIDL_OPTIMIZATION) /h comspy.h /tlb comspy.tlb /iid comspy_i.c /out $(OUTDIR) comspy.idl


$(OUTDIR)\stdafx.obj:     stdafx.cpp
     $(cc) $(cflags) $(cdebug) $(cvarsdll) /D_ATL_STATIC_REGISTRY /D_UNICODE /I"..\comspyface\$(OUTDIR)" /Yc"stdafx.h" /Fp"$(OUTDIR)\\" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I$(OUTDIR) stdafx.cpp

.cpp{$(OUTDIR)}.obj:
     $(cc) $(cflags) $(cdebug) $(cvarsdll) /D_ATL_STATIC_REGISTRY /D_UNICODE /I"..\comspyface\$(OUTDIR)" /Yu"stdafx.h" /Fp"$(OUTDIR)\\" /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" /I$(OUTDIR) $**

$(OUTDIR)\comspy.res:
     $(rc) $(rcflags) $(rcvars) /Fo$(OUTDIR)\comspy.res /I"..\comspyface\$(OUTDIR)" /I$(OUTDIR) comspy.rc

$(OUTDIR)\$(PROJ).exe:   $(OUTDIR)\comspy.h $(LINK32_OBJS)
     $(link) $(ldebug) $(guilflags) $(olelibsdll) /NODEFAULTLIB:libc.lib /MACHINE:$(CPU) /PDB:$(OUTDIR)\$(PROJ).pdb -out:$(OUTDIR)\$(PROJ).exe $(LINK32_OBJS) $(EXTRA_LIBS) 

clean:
     $(CLEANUP)
