#
# Copyright (c) 1983 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
# @(#)Makefile 1.1 94/10/31 SMI; from UCB 5.5 1/18/86
#
OBJS=	inet.o if.o main.o mbuf.o route.o unix.o ns.o ipintrq.o
CFLAGS=-O
DESTDIR=

netstat: ${OBJS}
	${CC} ${OBJS} -o netstat -lkvm

install: netstat
	install -s -m 2755 -g kmem netstat ${DESTDIR}/usr/ucb/netstat

clean:
	rm -f *.o core a.out errs netstat
