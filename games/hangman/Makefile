#
# @(#)Makefile 1.1 94/10/31 SMI; from UCB
#
OBJS=		endgame.o extern.o getguess.o getword.o main.o playgame.o \
		prdata.o prman.o prword.o setup.o
CFILES=		endgame.c extern.c getguess.c getword.c main.c playgame.c \
		prdata.c prman.c prword.c setup.c
HDRS=		hangman.h
CFLAGS=		-O
LDFLAGS=	-g

all: hangman

tags: $(HDRS) $(CFILES)
	ctags $(HDRS) $(CFILES)

install: hangman
	install -s hangman $(DESTDIR)/usr/games/hangman
	
hangman: $(OBJS)
	$(CC) $(LDFLAGS) -o hangman $(OBJS) -lcurses -ltermlib

$(OBJS): $(HDRS)

clean:
	rm -f $(OBJS) hangman ? core
