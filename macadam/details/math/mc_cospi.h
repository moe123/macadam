//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_cospi.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_COSPI_H
#define MC_COSPI_H

#pragma mark - mc_cospi -

static MC_TARGET_INLINE float mc_cospif(float x)
{
#	if MC_TARGET_APPLEXM
#	if MC_TARGET_CPP98
	return ::__cospif(x);
#	else
	return __cospif(x);
#	endif
#	else
#	if MC_TARGET_CPP98
	if (::isnan(x)) {
		return NAN;
	}
	if (::isinf(x)) {
		return NAN;
	}
	x = ::fmodf(::fabsf(x), 2.0f);
	if(::fmodf(x, 1.0f) == 0.5f) {
		return 0.0f;
	}
#	else
	if (isnan(x)) {
		return NAN;
	}
	if (isinf(x)) {
		return NAN;
	}
	x = fmodf(fabsf(x), 2.0f);
	if(fmodf(x, 1.0f) == 0.5f) {
		return 0.0f;
	}
#	endif
	if(x == 1.0f) {
		return -1.0f;
	}
	if(x == 0.0f) {
		return 1.0f;
	}
	const float pix = MCK_KF(MCK_PI) * x;
#	if MC_TARGET_CPP98
	return ::cosf(pix);
#	else
	return cosf(pix);
#	endif
#	endif
}

static MC_TARGET_INLINE double mc_cospi(double x)
{
#	if MC_TARGET_APPLEXM
#	if MC_TARGET_CPP98
	return ::__cospi(x);
#	else
	return __cospi(x);
#	endif
#	else
#	if MC_TARGET_CPP98
	if (::isnan(x)) {
		return NAN;
	}
	if (::isinf(x)) {
		return NAN;
	}
	x = ::fmod(::fabs(x), 2.0);
	if(::fmod(x, 1.0) == 0.5) {
		return 0.0;
	}
#	else
	if (isnan(x)) {
		return NAN;
	}
	if (isinf(x)) {
		return NAN;
	}
	x = fmod(fabs(x), 2.0);
	if(fmod(x, 1.0) == 0.5) {
		return 0.0;
	}
#	endif
	if(x == 1.0) {
		return -1.0;
	}
	if(x == 0.0) {
		return 1.0;
	}
	const double pix = MCK_K(MCK_PI) * x;
#	if MC_TARGET_CPP98
	return ::cos(pix);
#	else
	return cos(pix);
#	endif
#	endif
}

static MC_TARGET_INLINE long double mc_cospil(long double x)
{
#	if MC_TARGET_APPLEXM
	const double xx = mc_cast(double, x);
#	if MC_TARGET_CPP98
	return mc_cast(long double, ::__cospi(xx));
#	else
	return mc_cast(long double, __cospi(xx));
#	endif
#	else
#	if MC_TARGET_CPP98
	if (::isnan(x)) {
		return NAN;
	}
	if (::isinf(x)) {
		return NAN;
	}
	x = ::fmodl(::fabsl(x), 2.0L);
	if(::fmodl(x, 1.0L) == 0.5L) {
		return 0.0L;
	}
#	else
	if (isnan(x)) {
		return NAN;
	}
	if (isinf(x)) {
		return NAN;
	}
	x = fmodl(fabsl(x), 2.0L);
	if(fmodl(x, 1.0L) == 0.5L) {
		return 0.0L;
	}
#	endif
	if(x == 1.0L) {
		return -1.0L;
	}
	if(x == 0.0L) {
		return 1.0L;
	}
#	if MC_TARGET_C99 && defined(M_PIl)
	const long double pix = M_PIl * x;
#	else
	const long double pix = MCK_KL(MCK_PI) * x;
#	endif
#	if MC_TARGET_CPP98
	return ::cosl(pix);
#	else
	return cosl(pix);
#	endif
#	endif
}

#endif /* !MC_COSPI_H */

/* EOF */