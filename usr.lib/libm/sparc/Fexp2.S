
	.seg	"data"
	.asciz	"@(#)Fexp2.S 1.1 94/10/31 SMI"

#define LOCORE
#include <machine/asm_linkage.h>

!	Copyright (c) 1988 by Sun Microsystems, Inc.

	.global	_r_exp2_
	.seg	"text"
	ENTRY(Fexp2)
	save	%sp,-SA(MINFRAME+8),%sp
	st	%i0,[%fp-8]
	call	_r_exp2_
	sub	%fp,8,%o0
	ret
	restore
