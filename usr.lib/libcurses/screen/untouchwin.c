/*	Copyright (c) 1984 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

#ifndef lint
static	char sccsid[] = "@(#)untouchwin.c 1.1 94/10/31 SMI"; /* from S5R3.1 1.3 */
#endif

#include	"curses_inc.h"

untouchwin(win)
WINDOW	*win;
{
    return (wtouchln(win,0,win->_maxy,FALSE));
}
