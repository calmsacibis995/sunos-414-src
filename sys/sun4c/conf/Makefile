#
# @(#)Makefile 1.1 94/10/31 SMI
#
# This makefile creates the distributed kernel objects and
# configuration files.

ARCH=	sun4c
MACH=	sparc

CONFDIR= ../../conf.common
MACHINES= DL60 NFS60 SDST60 DLS60 GENERIC_SMALL
FILES=	scsi/conf/scsi_confdata.c scsi/targets/sd_conf.c \
	scsi/targets/st_conf.c $(ARCH)/openprom_xxx.c
HDIRS=	sbusdev scsi scsi/adapters scsi/conf scsi/generic scsi/impl scsi/targets

include ../../conf.common/Makefile.install
