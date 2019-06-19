//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_acospi.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_ACOSPI_H
#define MC_ACOSPI_H

#pragma mark - mc_acospi -

static MC_TARGET_INLINE float mc_acospif(float x)
{
#	if MC_TARGET_CPP98
	const float y = ::acosf(x);
#	else
	const float y = acosf(x);
#	endif
	return y * MCK_KF(MCK_1_PI);
}

static MC_TARGET_INLINE double mc_acospi(double x)
{
#	if MC_TARGET_CPP98
	const double y = ::acos(x);
#	else
	const double y = acos(x);
#	endif
	return y * MCK_K(MCK_1_PI);
}

static MC_TARGET_INLINE long double mc_acospil(long double x)
{
#	if MC_TARGET_CPP98
	const long double y = ::acosl(x);
#	else
	const long double y = acosl(x);
#	endif
	return y * MCK_KL(MCK_1_PI);
}

#endif /* !MC_ACOSPI_H */

/* EOF */