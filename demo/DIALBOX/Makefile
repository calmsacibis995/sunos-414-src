#
# @(#)Makefile 1.1 94/10/31 SMI
#

HDR= dial_icon.h dial_mask_icon.h
SRC= dialtest.c pw_circle.c diag.c dump.c
OPENWINHOME= /usr/openwin
OBJ= $(SRC:.c=.o)
LIB= -lsuntool -lsunwindow -lpixrect -lm
CFLAGS=	-O -I$(OPENWINHOME)/share/include

XSRC= x_diag.c x_dialtest.c x_dump.c x_pw_circle.c
XOBJ= $(XSRC:.c=.o)
EXECS= dialtest x_dialtest
XLIB=  -L$(OPENWINHOME)/lib -lxview -lpixrect -lm -lolgx -lX

INSFILES= Makefile $(SRC) $(XSRC)
INSDIR= $(DESTDIR)/usr/demo/DIALBOX
OWNER= bin

.KEEP_STATE:

all: dialtest x_dialtest

dialtest: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIB)

x_dialtest: $(XOBJ)
	$(CC) $(CFLAGS) -o $@ $(XOBJ) $(XLIB)

dialtest.o: dial_icon.h

x_dialtest.o: dial_icon.h

clean: FRC
	$(RM) *.o a.out core dialtest x_dialtest

install: $(INSFILES) $(HDR) FRC
	install -d -m 755 -o $(OWNER) $(INSDIR)
	install -m 555 -o $(OWNER) $(EXECS) $(INSDIR)
	install -m 644 -o $(OWNER) $(INSFILES) $(INSDIR)
	install -m 444 -o $(OWNER) $(HDR) $(INSDIR)

FRC:

#
#	dependencies as generated by cc -M and filtered by grep -v include
#
#
#

diag.o: diag.c
dialtest.o: dialtest.c
dialtest.o: ./dial_icon.h
dump.o: dump.c
pw_circle.o: pw_circle.c
x_diag.o: x_diag.c
x_dialtest.o: x_dialtest.c
x_dialtest.o: ./dial_icon.h
x_dialtest.o: ./dial_mask_icon.h
x_dump.o: x_dump.c
x_pw_circle.o: x_pw_circle.c
