//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_hypotc.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_HYPOTC_H
#define MC_HYPOTC_H

#pragma mark - mc_hypotc -

static MC_TARGET_INLINE float mc_hypotcf(float x, float y, float z)
{
#	if MC_TARGET_CPP98
	return ::sqrtf((x * x) + (y * y) + (z * z));
# else
	return sqrtf((x * x) + (y * y) + (z * z));
#	endif
}

static MC_TARGET_INLINE double mc_hypotc(double x, double y, double z)
{
#	if MC_TARGET_CPP98
	return ::sqrt((x * x) + (y * y) + (z * z));
# else
	return sqrt((x * x) + (y * y) + (z * z));
#	endif
}

static MC_TARGET_INLINE double mc_hypotcl(long double x, long double y, long double z)
{
#	if MC_TARGET_CPP98
	return ::sqrtl((x * x) + (y * y) + (z * z));
# else
	return sqrtl((x * x) + (y * y) + (z * z));
#	endif
}

#endif /* !MC_HYPOTC_H */

/* EOF */