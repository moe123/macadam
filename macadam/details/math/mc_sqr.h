//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_sqr.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_raise2.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_SQR_H
#define MC_SQR_H

#pragma mark - mc_sqr -

static MC_TARGET_INLINE float mc_sqrf(float x)
{
	return mc_raise2f(x);
}

static MC_TARGET_INLINE double mc_sqr(double x)
{
	return mc_raise2(x);
}

static MC_TARGET_INLINE long double mc_sqrl(long double x)
{
	return mc_raise2l(x);
}

#endif /* !MC_SQR_H */

/* EOF */