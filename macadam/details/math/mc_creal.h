//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_creal.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_zmul.h>

#ifndef MC_CREAL_H
#define MC_CREAL_H

#pragma mark - mc_creal -

MC_TARGET_PROC float mc_crealf(mc_complex_float_t c)
{
#	if MC_TARGET_C99_COMPLEX
		return crealf(c);
#	else
	return c.u_re;
#	endif
}

MC_TARGET_PROC double mc_creal(mc_complex_double_t c)
{
#	if MC_TARGET_C99_COMPLEX
		return creal(c);
#	else
	return c.u_re;
#	endif
}

MC_TARGET_PROC long double mc_creall(mc_complex_long_double_t c)
{
#	if MC_TARGET_C99_COMPLEX
		return creall(c);
#	else
	return c.u_re;
#	endif
}

#endif /* !MC_CREAL_H */

/* EOF */