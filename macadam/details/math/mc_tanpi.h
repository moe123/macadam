//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_tanpi.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_TANPI_H
#define MC_TANPI_H

#pragma mark - mc_tanpi -

static MC_TARGET_INLINE float mc_tanpif(float x)
{
#	if MC_TARGET_APPLEXM
#	if MC_TARGET_CPP98
	return ::__tanpif(x);
#	else
	return __tanpif(x);
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
	return ::tanf(pix);
#	else
	return tanf(pix);
#	endif
#	endif
}

static MC_TARGET_INLINE double mc_tanpi(double x)
{
#	if MC_TARGET_APPLEXM
#	if MC_TARGET_CPP98
	return ::__tanpi(x);
#	else
	return __tanpi(x);
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
	return ::tan(pix);
#	else
	return tan(pix);
#	endif
#	endif
}

static MC_TARGET_INLINE long double mc_tanpil(long double x)
{
#	if MC_TARGET_APPLEXM
	const double xx = mc_cast(double, x);
#	if MC_TARGET_CPP98
	return mc_cast(long double, ::__tanpi(xx));
#	else
	return mc_cast(long double, __tanpi(xx));
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
	return ::tanl(pix);
#	else
	return tanl(pix);
#	endif
#	endif
}

#endif /* !MC_TANPI_H */

/* EOF */