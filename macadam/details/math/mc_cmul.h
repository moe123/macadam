//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_cmul.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_zmul.h>

#ifndef MC_CMUL_H
#define MC_CMUL_H

#pragma mark - mc_cmul -

MC_TARGET_PROC mc_complex_float_t mc_cmulf(mc_complex_float_t a, mc_complex_float_t b)
{
#	if MC_TARGET_C99_COMPLEX
		return a * b;
#	else
	mc_complex_float_t c;
	mc_zmulf(&c.u_re, &c.u_im, a.u_re, a.u_im, b.u_re, b.u_im);
	return c;
#	endif
}

MC_TARGET_PROC mc_complex_double_t mc_cmul(mc_complex_double_t a, mc_complex_double_t b)
{
#	if MC_TARGET_C99_COMPLEX
		return a * b;
#	else
	mc_complex_double_t c;
	mc_zmul(&c.u_re, &c.u_im, a.u_re, a.u_im, b.u_re, b.u_im);
	return c;
#	endif
}

MC_TARGET_PROC mc_complex_long_double_t mc_cmull(mc_complex_long_double_t a, mc_complex_long_double_t b)
{
#	if MC_TARGET_C99_COMPLEX
		return a * b;
#	else
	mc_complex_long_double_t c;
	mc_zmull(&c.u_re, &c.u_im, a.u_re, a.u_im, b.u_re, b.u_im);
	return c;
#	endif
}

#endif /* !MC_CMUL_H */

/* EOF */