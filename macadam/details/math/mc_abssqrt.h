//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_abssqrt.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_sqrt.h>

#ifndef MC_ABSSQRT_H
#define MC_ABSSQRT_H

#pragma mark - mc_abssqrt -

MC_TARGET_FUNC float mc_abssqrtf(float x)
{
	return mc_sqrtf(mc_fabsf(x));
}

MC_TARGET_FUNC double mc_abssqrt(double x)
{
	return mc_sqrt(mc_fabs(x));
}

MC_TARGET_FUNC long double mc_abssqrtl(long double x)
{
	return mc_sqrtl(mc_fabsl(x));
}

#endif /* !MC_ABSRSQRT_H */

/* EOF */