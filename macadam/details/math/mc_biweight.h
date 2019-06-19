//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_biweight.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_bisquare.h>

#ifndef MC_BIWEIGHT_H
#define MC_BIWEIGHT_H

#pragma mark - mc_biweight -

static MC_TARGET_INLINE float mc_biweightf(float x)
{
	const float k = 4.685f;
	return  mc_bisquaref(x, k);
}

static MC_TARGET_INLINE double mc_biweight(double x)
{
	const double k = 4.685;
	return  mc_bisquare(x, k);
}

static MC_TARGET_INLINE long double mc_biweightl(long double x)
{
	const long double k = 4.685L;
	return  mc_bisquarel(x, k);
}

#endif /* !MC_BIWEIGHT_H */

/* EOF */