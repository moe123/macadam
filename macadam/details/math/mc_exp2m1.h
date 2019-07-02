//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_exp2m1.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_EXP2M1_H
#define MC_EXP2M1_H

#pragma mark - mc_exp2m1 -

static MC_TARGET_INLINE float mc_exp2m1f(float x)
{
	const float y = x * MCK_KF(MCK_LOG2);
#	if MC_TARGET_CPP98
	return ::expm1f(y);
#	else
	return expm1f(y);
#	endif
}

static MC_TARGET_INLINE double mc_exp2m1(double x)
{
	const double y = x * MCK_K(MCK_LOG2);
#	if MC_TARGET_CPP98
	return ::expm1(y);
#	else
	return expm1(y);
#	endif
}

static MC_TARGET_INLINE long double mc_exp2m1l(long double x)
{
#	if MC_TARGET_C99 && defined(M_LN2l)
	const long double y = x * M_LN2l;
#	else
	const long double y = x * MCK_KL(MCK_LOG2);
#	endif
#	if MC_TARGET_CPP98
	return ::expm1l(y);
#	else
	return expm1l(y);
#	endif
}

#pragma mark - mc_uexp2m1 -

static MC_TARGET_INLINE unsigned int mc_uexp2m1(unsigned int x)
{
	return (1 << x) - 1;
}

#pragma mark - mc_ulexp2m1 -

static MC_TARGET_INLINE unsigned long mc_ulexp2m1(unsigned long x)
{
	return (1 << x) - 1;
}

#pragma mark - mc_ullexp2m1 -

#	if MC_TARGET_C99 || MC_TARGET_CPP11
static MC_TARGET_INLINE unsigned long long mc_ullexp2m1(unsigned long long x)
{
	return (1 << x) - 1;
}
#	else
#	define mc_ullexp2m1 mc_ulexp2m1
#	endif

#endif /* !MC_EXP2M1_H */

/* EOF */