/*
 * Copyright (c) 1986 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 */

#ifndef lint
static char sccsid[] = "@(#)db_save.c 1.1 94/10/31 SMI"; /* from UCB 4.13 2/17/88 */
#endif /* not lint */

/*
 * Buffer allocation and deallocation routines.
 */

#include <sys/types.h>
#include <stdio.h>
#include <syslog.h>
#include <arpa/nameser.h>
#include "db.h"

#ifdef DEBUG
extern int debug;
extern FILE *ddt;
#endif

extern char *strcpy();

/*
 * Allocate a name buffer & save name.
 */
struct namebuf *
savename(name)
	char *name;
{
	register struct namebuf *np;

	np = (struct namebuf *) malloc(sizeof(struct namebuf));
	if (np == NULL) {
		syslog(LOG_ERR, "savename: %m");
		exit(1);
	}
	np->n_dname = savestr(name);
	np->n_next = NULL;
	np->n_data = NULL;
	np->n_hash = NULL;
	return (np);
}

/*
 * Allocate a data buffer & save data.
 */
struct databuf *
savedata(class, type, ttl, data, size)
	int class, type;
	u_long ttl;
	char *data;
	int size;
{
	register struct databuf *dp;

	if (type == T_NS)
		dp = (struct databuf *) 
		    malloc((unsigned)DATASIZE(size)+sizeof(u_long));
	else
		dp = (struct databuf *) malloc((unsigned)DATASIZE(size));
	if (dp == NULL) {
		syslog(LOG_ERR, "savedata: %m");
		exit(1);
	}
	dp->d_next = NULL;
	dp->d_type = type;
	dp->d_class = class;
	dp->d_ttl = ttl;
	dp->d_size = size;
	dp->d_mark = 0;
	dp->d_flags = 0;
	dp->d_nstime = 0;
	bcopy(data, dp->d_data, dp->d_size);
	return (dp);
}

int hashsizes[] = {	/* hashtable sizes */
	2,
	11,
	113,
	337,
	977,
	2053,
	4073,
	8011,
	16001,
	0
};

/*
 * Allocate a data buffer & save data.
 */
struct hashbuf *
savehash(oldhtp)
	register struct hashbuf *oldhtp;
{
	register struct hashbuf *htp;
	register struct namebuf *np, *nnp, **hp;
	register int n;
	int newsize;

	if (oldhtp == NULL)
		newsize = hashsizes[0];
	else {
		for (n = 0; newsize = hashsizes[n++]; )
			if (oldhtp->h_size == newsize) {
				newsize = hashsizes[n];
				break;
			}
		if (newsize == 0)
			newsize = oldhtp->h_size * 2 + 1;
	}
#ifdef DEBUG
	if(debug > 3)
		fprintf(ddt, "savehash GROWING to %d\n", newsize);
#endif
	htp = (struct hashbuf *) malloc((unsigned)HASHSIZE(newsize));
	if (htp == NULL) {
		syslog(LOG_ERR, "savehash: %m");
		exit(1);
	}
	htp->h_size = newsize;
	bzero((char *) htp->h_tab, newsize * sizeof(struct hashbuf *));
	if (oldhtp == NULL) {
		htp->h_cnt = 0;
		return (htp);
	}
#ifdef DEBUG
	if (debug > 3)
		fprintf(ddt,"savehash(%#x) cnt=%d, sz=%d, newsz=%d\n",
			oldhtp, oldhtp->h_cnt, oldhtp->h_size, newsize);
#endif
	htp->h_cnt = oldhtp->h_cnt;
	for (n = 0; n < oldhtp->h_size; n++) {
		for (np = oldhtp->h_tab[n]; np != NULL; np = nnp) {
			nnp = np->n_next;
			hp = &htp->h_tab[np->n_hashval % htp->h_size];
			np->n_next = *hp;
			*hp = np;
		}
	}
	free((char *) oldhtp);
	return (htp);
}

/*
 * Allocate an inverse query buffer.
 */
struct invbuf *
saveinv()
{
	register struct invbuf *ip;

	ip = (struct invbuf *) malloc(sizeof(struct invbuf));
	if (ip == NULL) {
		syslog(LOG_ERR, "saveinv: %m");
		exit(1);
	}
	ip->i_next = NULL;
	bzero((char *)ip->i_dname, sizeof(ip->i_dname));
	return (ip);
}

/*
 * Make a copy of a string and return a pointer to it.
 */
char *
savestr(str)
	char *str;
{
	char *cp;

	cp = malloc((unsigned)strlen(str) + 1);
	if (cp == NULL) {
		syslog(LOG_ERR, "savestr: %m");
		exit(1);
	}
	(void) strcpy(cp, str);
	return (cp);
}
