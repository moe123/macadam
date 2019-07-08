//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_cot.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_tan.h>

#ifndef MC_COT_H
#define MC_COT_H

#pragma mark - mc_cot -

static MC_TARGET_INLINE float mc_cotf(float x)
{
	return 1.0f / mc_tanf(x);
}

static MC_TARGET_INLINE double mc_cot(double x)
{
	return 1.0 / mc_tan(x);
}

static MC_TARGET_INLINE long double mc_cotl(long double x)
{
	return 1.0L / mc_tanl(x);
}

#endif /* !MC_COT_H */

/* EOF */