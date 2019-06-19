//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_exp10.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_EXP10_H
#define MC_EXP10_H

#pragma mark - mc_exp10 -

static MC_TARGET_INLINE float mc_exp10f(float x)
{
#	if MC_TARGET_CPP98
#	if MC_TARGET_APPLEXM
	return ::__exp10f(x);
#	elif defined(__linux__) && (defined(__GLIBC__) || defined(_GNU_SOURCE))
	return ::exp10f(x);
#	else
	return ::expf((MCK_KF(MCK_LOG10) * x));
#	endif
#	else
#	if MC_TARGET_APPLEXM
	return __exp10f(x);
#	elif defined(__linux__) && (defined(__GLIBC__) || defined(_GNU_SOURCE))
	return exp10f(x);
#	else
	return expf((MCK_KF(MCK_LOG10) * x));
#	endif
#	endif
}

static MC_TARGET_INLINE double mc_exp10(double x)
{
#	if MC_TARGET_CPP98
#	if MC_TARGET_APPLEXM
	return ::__exp10(x);
#	elif defined(__linux__) && (defined(__GLIBC__) || defined(_GNU_SOURCE))
	return ::exp10(x);
#	else
	return ::exp((MCK_K(MCK_LOG10) * x));
#	endif
#	else
#	if MC_TARGET_APPLEXM
	return __exp10(x);
#	elif defined(__linux__) && (defined(__GLIBC__) || defined(_GNU_SOURCE))
	return exp10(x);
#	else
	return exp((MCK_K(MCK_LOG10) * x));
#	endif
#	endif
}

static MC_TARGET_INLINE long double mc_exp10l(long double x)
{
#	if MC_TARGET_CPP98
#	if MC_TARGET_APPLEXM
	const double xx = mc_cast(double, x);
	return mc_cast(long double, ::__exp10(xx));
#	elif defined(__linux__) && (defined(__GLIBC__) || defined(_GNU_SOURCE))
	return ::exp10l(x);
#	else
	return ::expl((MCK_KL(MCK_LOG10) * x));
#	endif
#	else
#	if MC_TARGET_APPLEXM
	const double xx = mc_cast(double, x);
	return mc_cast(long double, __exp10(xx));
#	elif defined(__linux__) && (defined(__GLIBC__) || defined(_GNU_SOURCE))
	return exp10l(x);
#	else
#	if MC_TARGET_C99 && defined(M_LN10l)
	return expl((M_LN10l * x));
#	else
	return expl((MCK_KL(MCK_LOG10) * x));
#	endif
#	endif
#	endif
}

#endif /* !MC_EXP10_H */

/* EOF */