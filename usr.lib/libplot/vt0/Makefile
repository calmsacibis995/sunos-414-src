#
# @(#)Makefile 1.1 94/10/31 SMI; from UCB 4.3 83/07/09
#
CFLAGS=	-O
OBJS=	arc.o box.o circle.o close.o dot.o erase.o label.o \
	line.o linmod.o move.o open.o point.o space.o subr.o

../libvt0:	${OBJS}
	ar cu ../libvt0 ${OBJS}

clean:
	rm -f ${OBJS} errs a.out core
