//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_cdiv.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_zdiv.h>

#ifndef MC_CDIV_H
#define MC_CDIV_H

#pragma mark - mc_cdiv -

MC_TARGET_PROC mc_complex_float_t mc_cdivf(mc_complex_float_t a, mc_complex_float_t b)
{
#	if MC_TARGET_C99_COMPLEX
		return a / b;
#	else
	mc_complex_float_t c;
	mc_zdivf(&c.u_re, &c.u_im, a.u_re, a.u_im, b.u_re, b.u_im);
	return c;
#	endif
}

MC_TARGET_PROC mc_complex_double_t mc_cdiv(mc_complex_double_t a, mc_complex_double_t b)
{
#	if MC_TARGET_C99_COMPLEX
		return a / b;
#	else
	mc_complex_double_t c;
	mc_zdiv(&c.u_re, &c.u_im, a.u_re, a.u_im, b.u_re, b.u_im);
	return c;
#	endif
}

MC_TARGET_PROC mc_complex_long_double_t mc_cdivl(mc_complex_long_double_t a, mc_complex_long_double_t b)
{
#	if MC_TARGET_C99_COMPLEX
		return a / b;
#	else
	mc_complex_long_double_t c;
	mc_zdivl(&c.u_re, &c.u_im, a.u_re, a.u_im, b.u_re, b.u_im);
	return c;
#	endif
}

#endif /* !MC_CDIV_H */

/* EOF */