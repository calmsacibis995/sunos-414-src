#
# @(#)Makefile 1.1 94/10/31 SMI
#
HDIR	=	$(DESTDIR)/usr/include/scsi/generic
CSRC	=	
HFILES	=	commands.h dad_mode.h inquiry.h message.h mode.h sense.h status.h
SUBDIR	=

all:	$(HFILES)

install:

install_h: all
	rm -rf $(HDIR)
	install -d -m 755 $(HDIR)
	install -m 444 $(HFILES) $(HDIR)

FRC:
