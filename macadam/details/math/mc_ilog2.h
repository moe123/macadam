//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_ilog2.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_ILOG2_H
#define MC_ILOG2_H

static MC_TARGET_INLINE int mc_ilog2(int x)
{
	if (x > 0 && x < MCLIMITS_IMAX) {
		const int l = mc_cast(int, (sizeof(unsigned int) * MCLIMITS_CBITS - 1));
		const int r = mc_cast(int, MC_TARGET_CLZ(mc_cast(unsigned int, x)));
		return (l - r);
	}
	return MCK_NAN;
}

static MC_TARGET_INLINE long mc_llog2(long x)
{
	if (x > 0 && x < MCLIMITS_LMAX) {
		const long l = mc_cast(long, (sizeof(unsigned long) * MCLIMITS_CBITS - 1));
		const long r = mc_cast(long, MC_TARGET_CLZL(mc_cast(unsigned long, x)));
		return (l - r);
	}
	return MCK_NAN;
}

#	if MC_TARGET_C99 || MC_TARGET_CPP11
static MC_TARGET_INLINE long long mc_lllog2(long long x)
{
	if (x > 0 && x < MCLIMITS_LLMAX) {
		const long long l = mc_cast(long long, (sizeof(unsigned long long) * MCLIMITS_CBITS - 1));
		const long long r = mc_cast(long long, MC_TARGET_CLZLL(mc_cast(unsigned long long, x)));
		return (l - r);
	}
	return MCK_NAN;
}
#	else
#	define mc_lllog2 mc_llog2
#	endif

#endif /* !MC_ILOG2_H */

/* EOF */