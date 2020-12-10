//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_cadd.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_zadd.h>

#ifndef MC_CADD_H
#define MC_CADD_H

#pragma mark - mc_cadd -

MC_TARGET_PROC mc_complex_float_t mc_caddf(mc_complex_float_t a, mc_complex_float_t b)
{
#	if MC_TARGET_C99_COMPLEX
		return a + b;
#	else
	mc_complex_float_t c;
	mc_zaddf(&c.u_re, &c.u_im, a.u_re, a.u_im, b.u_re, b.u_im);
	return c;
#	endif
}

MC_TARGET_PROC mc_complex_double_t mc_cadd(mc_complex_double_t a, mc_complex_double_t b)
{
#	if MC_TARGET_C99_COMPLEX
		return a + b;
#	else
	mc_complex_double_t c;
	mc_zadd(&c.u_re, &c.u_im, a.u_re, a.u_im, b.u_re, b.u_im);
	return c;
#	endif
}

MC_TARGET_PROC mc_complex_long_double_t mc_caddl(mc_complex_long_double_t a, mc_complex_long_double_t b)
{
#	if MC_TARGET_C99_COMPLEX
		return a + b;
#	else
	mc_complex_long_double_t c;
	mc_zaddl(&c.u_re, &c.u_im, a.u_re, a.u_im, b.u_re, b.u_im);
	return c;
#	endif
}

#endif /* !MC_CADD_H */

/* EOF */