//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_asinpi.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_asin.h>

#ifndef MC_ASINPI_H
#define MC_ASINPI_H

#pragma mark - mc_asinpi -

static MC_TARGET_INLINE float mc_asinpif(float x)
{
	const float y = mc_asinf(x);
	return y * MCK_KF(MCK_1_PI);
}

static MC_TARGET_INLINE double mc_asinpi(double x)
{
	const double y = mc_asin(x);
	return y * MCK_K(MCK_1_PI);
}

static MC_TARGET_INLINE long double mc_asinpil(long double x)
{
	const long double y = mc_asinl(x);
	return y * MCK_KL(MCK_1_PI);
}

#endif /* !MC_ASINPI_H */

/* EOF */