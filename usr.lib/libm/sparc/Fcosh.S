
	.seg	"data"
	.asciz	"@(#)Fcosh.S 1.1 94/10/31 SMI"

#define LOCORE
#include <machine/asm_linkage.h>

!	Copyright (c) 1988 by Sun Microsystems, Inc.

	.global	_r_cosh_
	.seg	"text"
	ENTRY(Fcosh)
	save	%sp,-SA(MINFRAME+8),%sp
	st	%i0,[%fp-8]
	call	_r_cosh_
	sub	%fp,8,%o0
	ret
	restore
