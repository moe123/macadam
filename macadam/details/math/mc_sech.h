//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_sech.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_cosh.h>

#ifndef MC_SECH_H
#define MC_SECH_H

#pragma mark - mc_sech -

static MC_TARGET_INLINE float mc_sechf(float x)
{
	return 1.0f / mc_coshf(x);
}

static MC_TARGET_INLINE double mc_sech(double x)
{
	return 1.0 / mc_cosh(x);
}

static MC_TARGET_INLINE long double mc_sechl(long double x)
{
	return 1.0L / mc_coshl(x);
}

#endif /* !MC_SECH_H */

/* EOF */