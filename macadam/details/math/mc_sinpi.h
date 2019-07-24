//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_sinpi.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_fmod.h>
#include <macadam/details/math/mc_isinf.h>
#include <macadam/details/math/mc_isnan.h>
#include <macadam/details/math/mc_sin.h>


#ifndef MC_SINPI_H
#define MC_SINPI_H

#pragma mark - mc_sinpi -

MC_TARGET_FUNC float mc_sinpif (float x)
{
#	if MC_TARGET_APPLEXM
#	if MC_TARGET_CPP98
	return ::__sinpif (x);
#	else
	return __sinpif (x);
#	endif
#	else
	if (mc_isnan(x)) {
		return NAN;
	}
	if (mc_isinf(x)) {
		return NAN;
	}
	x = mc_fmodf(mc_fabsf(x), 2.0f);
	if (mc_fmodf(x, 1.0f) == 0.5f) {
		return 0.0f;
	}
	if (x == 1.0f) {
		return -1.0f;
	}
	if (x == 0.0f) {
		return 1.0f;
	}
	const float pix = MCK_KF(MCK_PI) * x;
	return mc_sinf(pix);
#	endif
}

MC_TARGET_FUNC double mc_sinpi(double x)
{
#	if MC_TARGET_APPLEXM
#	if MC_TARGET_CPP98
	return ::__sinpi(x);
#	else
	return __sinpi(x);
#	endif
#	else
	if (mc_isnan(x)) {
		return NAN;
	}
	if (mc_isinf(x)) {
		return NAN;
	}
	x = mc_fmod(mc_fabs(x), 2.0);
	if (mc_fmod(x, 1.0) == 0.5) {
		return 0.0;
	}
	if (x == 1.0) {
		return -1.0;
	}
	if (x == 0.0) {
		return 1.0;
	}
	const double pix = MCK_K(MCK_PI) * x;
	return mc_sin(pix);
#	endif
}

MC_TARGET_FUNC long double mc_sinpil(long double x)
{
#	if MC_TARGET_APPLEXM
	const double xx = mc_cast(double, x);
#	if MC_TARGET_CPP98
	return mc_cast(long double, ::__sinpi(xx));
#	else
	return mc_cast(long double, __sinpi(xx));
#	endif
#	else
	if (mc_isnan(x)) {
		return NAN;
	}
	if (mc_isinf(x)) {
		return NAN;
	}
	x = mc_fmodl(mc_fabsl(x), 2.0L);
	if (mc_fmodl(x, 1.0L) == 0.5L) {
		return 0.0L;
	}
	if (x == 1.0L) {
		return -1.0L;
	}
	if (x == 0.0L) {
		return 1.0L;
	}
#	if (MC_TARGET_C99 || MC_TARGET_CPP17) && defined(M_PIl)
	const long double pix = M_PIl * x;
#	else
	const long double pix = MCK_KL(MCK_PI) * x;
#	endif
	return mc_sinl(pix);
#	endif
}

#endif /* !MC_SINPI_H */

/* EOF */