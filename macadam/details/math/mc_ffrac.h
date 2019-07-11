//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_ffrac.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_modf.h>

#ifndef MC_FFRAC_H
#define MC_FFRAC_H

#pragma mark - mc_ffrac -

static MC_TARGET_INLINE float mc_ffracf(float x)
{
	float y = 0.0f;
	return mc_modff(x, &y);
}

static MC_TARGET_INLINE double mc_ffrac(double x)
{
	double y = 0.0;
	return mc_modf(x, &y);
}

static MC_TARGET_INLINE long double mc_ffracl(long double x)
{
	long double y = 0.0L;
	return mc_modfl(x, &y);
}

#endif /* !MC_FFRAC_H */

/* EOF */