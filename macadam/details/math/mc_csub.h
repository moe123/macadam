//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_csub.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_zsub.h>

#ifndef MC_CSUB_H
#define MC_CSUB_H

#pragma mark - mc_csub -

MC_TARGET_FUNC mc_complex_float_t mc_csubf(mc_complex_float_t a, mc_complex_float_t b)
{
#	if MC_TARGET_C99_COMPLEX
		return a - b;
#	else
	mc_complex_float_t c;
	mc_zsubf(&c.u_re, &c.u_im, a.u_re, a.u_im, b.u_re, b.u_im);
	return c;
#	endif
}

MC_TARGET_FUNC mc_complex_double_t mc_csub(mc_complex_double_t a, mc_complex_double_t b)
{
#	if MC_TARGET_C99_COMPLEX
		return a - b;
#	else
	mc_complex_double_t c;
	mc_zsub(&c.u_re, &c.u_im, a.u_re, a.u_im, b.u_re, b.u_im);
	return c;
#	endif
}

MC_TARGET_FUNC mc_complex_long_double_t mc_csubl(mc_complex_long_double_t a, mc_complex_long_double_t b)
{
#	if MC_TARGET_C99_COMPLEX
		return a - b;
#	else
	mc_complex_long_double_t c;
	mc_zsubl(&c.u_re, &c.u_im, a.u_re, a.u_im, b.u_re, b.u_im);
	return c;
#	endif
}

#endif /* !MC_CSUB_H */

/* EOF */