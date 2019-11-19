//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_mulax3x3.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_addmulax3x3.h>

#ifndef MC_MULAX3X3_H
#define MC_MULAX3X3_H

#pragma mark - mc_mulax3x3 -

MC_TARGET_FUNC void mc_mulax3x3f(float * b, const float a[9], const float x[3])
{
//!# b=a*x
	b[0] = 0.0f; b[1] = 0.0f; b[2] = 0.0f;
	mc_addmulax3x3f(b, a, x);
}

MC_TARGET_FUNC void mc_mulax3x3(double * b, const double a[9], const double x[3])
{
//!# b=a*x
	b[0] = 0.0; b[1] = 0.0; b[2] = 0.0;
	mc_addmulax3x3(b, a, x);
}

MC_TARGET_FUNC void mc_mulax3x3l(long double * b, const long double a[9], const long double x[3])
{
//!# b=a*x
	b[0] = 0.0L; b[1] = 0.0L; b[2] = 0.0L;
	mc_addmulax3x3l(b, a, x);
}

#endif /* !MC_MULAX3X3_H */

/* EOF */