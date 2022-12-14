/*	Copyright (c) 1984 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

#ifndef lint
static	char sccsid[] = "@(#)set_TERM.c 1.1 94/10/31 SMI"; /* from S5R3 1.3 */
#endif

#include "curses.ext"

/*
 * Establish the terminal that the #defines in term.h refer to.
 */
TERMINAL *set_curterm(newterminal)
register TERMINAL *newterminal;
{
	register TERMINAL *oldterminal = cur_term;
	if (newterminal) {
		cur_bools = newterminal->_bools;
		cur_nums = newterminal->_nums;
		cur_strs = newterminal->_strs;
		cur_term = newterminal;
	}
	return oldterminal;
}
