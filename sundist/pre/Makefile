#
#        @(#)Makefile 1.1 94/10/31 SMI 
#
#
SUBDIR=local crc
DOCS=README_pre

.KEEP_STATE:

all: $(SUBDIR) $(DOCS)

$(SUBDIR): FRC
	cd $@; $(MAKE)

clean:
	-rm -f core README_pre
	-for i in $(SUBDIR); do (cd $$i; $(MAKE) clean); done

FRC:

