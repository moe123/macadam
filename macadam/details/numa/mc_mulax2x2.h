//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_mulax2x2.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_addmulax2x2.h>

#ifndef MC_MULAX2X2_H
#define MC_MULAX2X2_H

#pragma mark - mc_mulax2x2 -

MC_TARGET_FUNC void mc_mulax2x2f(float * b, const float a[4], const float x[2])
{
//!# b=a*b
	b[0] = 0.0f; b[1] = 0.0f;
	mc_addmulax2x2f(b, a, x);
}

MC_TARGET_FUNC void mc_mulax2x2(double * b, double a[4], double x[2])
{
//!# b=a*b
	mc_addmulax2x2(b, a, x);
}

MC_TARGET_FUNC void mc_mulax2x2l(long double * b, long double a[4], long double x[2])
{
//!# b=a*b
	mc_addmulax2x2l(b, a, x);
}

#endif /* !MC_MULAX2X2_H */

/* EOF */