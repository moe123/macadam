//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_log2.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_LOG2_H
#define MC_LOG2_H

#pragma mark - mc_log2 -

static MC_TARGET_INLINE float mc_log2f(float x)
{
	const float y = x * MCK_KF(MCK_1_LOG2);
#	if MC_TARGET_CPP98
	return ::logf(y);
#	else
	return logf(y);
#	endif
}

static MC_TARGET_INLINE double mc_log2(double x)
{
	const double y = x * MCK_K(MCK_1_LOG2);
#	if MC_TARGET_CPP98
	return ::logf(y);
#	else
	return logf(y);
#	endif
}

static MC_TARGET_INLINE long double mc_log2l(long double x)
{
#	if MC_TARGET_C99 && defined(M_LN2l)
	const long double y = x / M_LN2l;
#	else
	const long double y = x * MCK_KL(MCK_1_LOG2);
#	endif
#	if MC_TARGET_CPP98
	return ::logl(y);
#	else
	return logl(y);
#	endif
}

static MC_TARGET_INLINE int mc_ulog2(unsigned int x)
{
	return x != 0 ? (sizeof(x) * MCLIMITS_CBITS - 1) - MC_TARGET_CLZ(x) : 0;
}

static MC_TARGET_INLINE long mc_ullog2(unsigned long x)
{
	return x != 0 ? (sizeof(x) * MCLIMITS_CBITS - 1) - MC_TARGET_CLZL(x) : 0;
}

#	if MC_TARGET_C99 || MC_TARGET_CPP11
static MC_TARGET_INLINE long long mc_ulllog2(unsigned long x)
{
	return x != 0 ? (sizeof(x) * MCLIMITS_CBITS - 1) - MC_TARGET_CLZLL(x) : 0;
}
#	else
#	define mc_ulllog2 mc_ullog2
#	endif

#endif /* !MC_LOG1M_H */

/* EOF */