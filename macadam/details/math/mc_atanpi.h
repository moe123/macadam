//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_atanpi.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_ATANPI_H
#define MC_ATANPI_H

#pragma mark - mc_atanpi -

static MC_TARGET_INLINE float mc_atanpif(float x)
{
#	if MC_TARGET_CPP98
	const float y = ::atanf(x);
#	else
	const float y = atanf(x);
#	endif
	return y * MCK_KF(MCK_1_PI);
}

static MC_TARGET_INLINE double mc_atanpi(double x)
{
#	if MC_TARGET_CPP98
	const double y = ::atan(x);
#	else
	const double y = atan(x);
#	endif
	return y * MCK_K(MCK_1_PI);
}

static MC_TARGET_INLINE long double mc_atanpil(long double x)
{
#	if MC_TARGET_CPP98
	const long double y = ::atanl(x);
#	else
	const long double y = atanl(x);
#	endif
	return y * MCK_KL(MCK_1_PI);
}

#endif /* !MC_ATANPI_H */

/* EOF */