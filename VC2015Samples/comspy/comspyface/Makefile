#----- Include the PSDK's WIN32.MAK to pick up defines-------------------
!include <win32.mak>

all:    $(OUTDIR) $(OUTDIR)\comspyaudit.h $(OUTDIR)\comspyctl.h


$(OUTDIR):
     if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

$(OUTDIR)\comspyaudit.h : comspyaudit.idl
     $(midl) $(MIDL_OPTIMIZATION) /h comspyaudit.h /tlb comspyaudit.tlb /iid comspyaudit_i.c /out $(OUTDIR) comspyaudit.idl

$(OUTDIR)\comspyctl.h : comspyctl.idl
     $(midl) $(MIDL_OPTIMIZATION) /h comspyctl.h /tlb comspyctl.tlb /iid comspyctl_i.c /out $(OUTDIR) comspyctl.idl


clean:
     $(CLEANUP)
