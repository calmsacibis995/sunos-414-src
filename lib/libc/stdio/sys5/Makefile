#
# @(#)Makefile 1.1 94/10/31 SMI
#
# Copyright (c) 1987 by Sun Microsystems, Inc.
#

all: xall

include ../../Makefile.arch
include $(ARCH)/Makefile
include ../../Makefile.master

SRC = filbuf.c fopen.c fprintf.c flsbuf.c \
	printf.c \
	setbuf.c sprintf.c \
	vfprintf.c vprintf.c vsprintf.c
OBJS = $(SRC:%.c=$(VARIANT)/%.o) $(MD_CSRC:$(ARCH)/%.c=$(VARIANT)/%.o)
.KEEP_STATE:

xall: $$(LIBS)
$(LIBS): $$(VARIANT) $$(OBJS)

clean: master.clean
