#
#	@(#)Makefile 1.1 94/10/31 Copyright(c) Sun Microsystems, Inc.
#
.DEFAULT:
	sccs get -G$@ $@

include ../../include/Makefile.macros
DBX=-O
# specify DBX=-g for dbx version

DESTDIR =
PROGRAM = sunbuttons
INCDIR	= ../../include
INCLUDES= buttons.h button_icon.h off_off_icon.h off_on_icon.h \
	  on_off_icon.h on_on_icon.h $(INCDIR)/sdrtns.h\
	  $(ONLINEINC)/libonline.h
LIBS	= -lsuntool -lsunwindow -lpixrect

SOURCES	= sunbuttons.c
OBJECTS	= $(SOURCES:.c=.o)
LINTFILES = $(SOURCES:.c=.ln)

CFLAGS	= $(DBX) -D`arch` -I$(INCDIR)
LDFLAGS	= $(DBX)
LINTFLAGS= -D`arch` -I$(INCDIR)

.KEEP_STATE:

##### beginning of dependency lines #####

all:	$(INCLUDES) $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	cc $(LDFLAGS) -o $@ $(OBJECTS) $(SDLIBS) $(LIBS)

install: all FRC
	@if [ $(DESTDIR) ]; then \
	  set -x; \
	  install -s $(PROGRAM) $(DESTDIR); \
	else \
	  set -x; \
	  install $(PROGRAM) ../../bin; \
	fi
		
clean: FRC
	rm -f $(PROGRAM) $(OBJECTS) $(LINTFILES) core

lint: $(LINTFILES)
	lint $(LINTFLAGS) $(LINTFILES) $(LIBS)

info: FRC
	sccs info

include ../../include/Makefile.end
