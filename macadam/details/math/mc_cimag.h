//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_cimag.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_zmul.h>

#ifndef MC_CIMAG_H
#define MC_CIMAG_H

#pragma mark - mc_cimag -

MC_TARGET_FUNC float mc_cimagf(mc_complex_float_t c)
{
#	if MC_TARGET_C99_COMPLEX
		return cimagf(c);
#	else
	return c.u_im;
#	endif
}

MC_TARGET_FUNC double mc_cimag(mc_complex_double_t c)
{
#	if MC_TARGET_C99_COMPLEX
		return cimag(c);
#	else
	return c.u_im;
#	endif
}

MC_TARGET_FUNC long double mc_cimagl(mc_complex_long_double_t c)
{
#	if MC_TARGET_C99_COMPLEX
		return cimagl(c);
#	else
	return c.u_im;
#	endif
}

#endif /* !MC_CIMAG_H */

/* EOF */