//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_asinpi.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_ASINPI_H
#define MC_ASINPI_H

#pragma mark - mc_asinpi -

static MC_TARGET_INLINE float mc_asinpif(float x)
{
#	if MC_TARGET_CPP98
	const float y = ::asinf(x);
#	else
	const float y = asinf(x);
#	endif
	return y * MCK_KF(MCK_1_PI);
}

static MC_TARGET_INLINE double mc_asinpi(double x)
{
#	if MC_TARGET_CPP98
	const double y = ::asin(x);
#	else
	const double y = asin(x);
#	endif
	return y * MCK_K(MCK_1_PI);
}

static MC_TARGET_INLINE long double mc_asinpil(long double x)
{
#	if MC_TARGET_CPP98
	const long double y = ::asinl(x);
#	else
	const long double y = asinl(x);
#	endif
	return y * MCK_KL(MCK_1_PI);
}

#endif /* !MC_ASINPI_H */

/* EOF */