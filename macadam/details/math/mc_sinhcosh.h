//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_sinhcosh.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_cosh.h>
#include <macadam/details/math/mc_sinh.h>

#ifndef MC_SINHCOSH_H
#define MC_SINHCOSH_H

#pragma mark - mc_sinhcosh -

static MC_TARGET_INLINE void mc_sinhcoshf(float x, float * mc_sinhp, float * mc_coshp)
{
	*mc_sinhp = mc_sinhf(x);
	*mc_coshp = mc_coshf(x);
}

static MC_TARGET_INLINE void mc_sinhcosh(double x, double * mc_sinhp, double * mc_coshp)
{
	*mc_sinhp = mc_sinh(x);
	*mc_coshp = mc_cosh(x);
}

static MC_TARGET_INLINE void mc_sinhcoshl(long double x, long double * mc_sinhp, long double * mc_coshp)
{
	*mc_sinhp = mc_sinhl(x);
	*mc_coshp = mc_coshl(x);
}

#endif /* !MC_SINHCOSH_H */

/* EOF */