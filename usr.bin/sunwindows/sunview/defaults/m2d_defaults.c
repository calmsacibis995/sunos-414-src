#ifndef lint
#ifdef sccs
static  char sccsid[] = "@(#)m2d_defaults.c 1.1 94/10/31 Copyr 1985 Sun Micro";
#endif
#endif

/*
 * Copyright (c) 1985 by Sun Microsystems, Inc.
 */

/*
 * mailrc_to_deafults -- convert mailrc to defaults
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <strings.h>
#include <ctype.h>
/* #include <sunwindow/rect.h> */
#include <sunwindow/defaults.h>

static char    *delimited_prefix = "/Mail/";
static char    fullpath[128+2048];
/* Note: 2048 is the longest string generated by m2d_get_aliases()
 * (see m2d_vars.c)
 */


m2d_flush_defaults()
{
	defaults_write_changed((char *)NULL, (int *)NULL);
}

m2d_set_string(type, name, value)
char		*type;
char		*name;
char		*value;
{
	(void)sprintf(fullpath, "%s%s/%s", delimited_prefix, type, name);
	defaults_set_string(fullpath, value, (int *)NULL);
}

m2d_set_boolean(name, value)
char		*name;
int		value;
{
	(void)sprintf(fullpath, "%sSet/%s", delimited_prefix, name);
	defaults_set_enumeration(fullpath, value?"Yes":"No", (int *)NULL);
}

m2d_set_integer(name, value)
char		*name;
int		value;
{
	(void)sprintf(fullpath, "%sSet/%s", delimited_prefix, name);
	defaults_set_integer(fullpath, value, (int *)NULL);
}
