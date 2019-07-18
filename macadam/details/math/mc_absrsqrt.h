//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_absrsqrt.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_rsqrt.h>

#ifndef MC_ABSRSQRT_H
#define MC_ABSRSQRT_H

#pragma mark - mc_absrsqrt -

MC_TARGET_FUNCTION float mc_absrsqrtf(float x)
{
	return mc_rsqrtf(mc_fabsf(x));
}

MC_TARGET_FUNCTION double mc_absrsqrt(double x)
{
	return mc_rsqrt(mc_fabs(x));
}

MC_TARGET_FUNCTION long double mc_absrsqrtl(long double x)
{
	return mc_rsqrtl(mc_fabsl(x));
}

#endif /* !MC_ABSRSQRT_H */

/* EOF */