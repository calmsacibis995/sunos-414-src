#ifndef lint
static	char sccsid[] = "@(#)dbx_machdep.c 1.1 94/10/31 Copyr 1985 Sun Micro";
#endif

/*
 * This file is optionally brought in by including a
 * "psuedo-device dbx" line in the config file.  It is
 * compiled using the "-g" flag to generate structure
 * information which is used by dbx with the -k flag.
 */

#include <sys/param.h>

#include <machine/buserr.h>
#include <machine/clock.h>
#include <machine/mmu.h>
#include <machine/cpu.h>
#include <machine/memerr.h>
#include <machine/pte.h>
