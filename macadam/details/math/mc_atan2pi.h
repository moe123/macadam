//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_atan2pi.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_ATAN2PI_H
#define MC_ATAN2PI_H

#pragma mark - mc_atan2pi -

static MC_TARGET_INLINE float mc_atan2pif(float x, float y)
{
#	if MC_TARGET_CPP98
	const float z = ::atan2f(x, y);
#	else
	const float z = atan2f(x, y);
#	endif
	return z * MCK_KF(MCK_1_PI);
}

static MC_TARGET_INLINE double mc_atan2pi(double x, double y)
{
#	if MC_TARGET_CPP98
	const double z = ::atan2(x, y);
#	else
	const double z = atan2(x, y);
#	endif
	return z * MCK_K(MCK_1_PI);
}

static MC_TARGET_INLINE long double mc_atan2pil(long double x, long double y)
{
#	if MC_TARGET_CPP98
	const long double z = ::atan2l(x, y);
#	else
	const long double z = atan2l(x, y);
#	endif
	return z * MCK_KL(MCK_1_PI);
}

#endif /* !MC_ATAN2PI_H */

/* EOF */