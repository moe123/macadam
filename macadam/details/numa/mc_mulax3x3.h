//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_mulax3x3.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_MULAX3X3_H
#define MC_MULAX3X3_H

#pragma mark - mc_mulax3x3 -

MC_TARGET_FUNC void mc_mulax3x3f(float * b, const float a[9], const float x[3])
{
//!# b=a*x
	b[0] = 0.0f; b[1] = 0.0f; b[2] = 0.0f;

	b[0] = b[0] + (a[0] * x[0]);
	b[0] = b[0] + (a[1] * x[1]);
	b[0] = b[0] + (a[2] * x[2]);

	b[1] = b[1] + (a[3] * x[0]);
	b[1] = b[1] + (a[4] * x[1]);
	b[1] = b[1] + (a[5] * x[2]);

	b[2] = b[2] + (a[6] * x[0]);
	b[2] = b[2] + (a[7] * x[1]);
	b[2] = b[2] + (a[8] * x[2]);
}

MC_TARGET_FUNC void mc_mulax3x3(double * b, double a[9], double x[3])
{
//!# b=a*x
	b[0] = 0.0; b[1] = 0.0; b[2] = 0.0;

	b[0] = b[0] + (a[0] * x[0]);
	b[0] = b[0] + (a[1] * x[1]);
	b[0] = b[0] + (a[2] * x[2]);

	b[1] = b[1] + (a[3] * x[0]);
	b[1] = b[1] + (a[4] * x[1]);
	b[1] = b[1] + (a[5] * x[2]);

	b[2] = b[2] + (a[6] * x[0]);
	b[2] = b[2] + (a[7] * x[1]);
	b[2] = b[2] + (a[8] * x[2]);
}

MC_TARGET_FUNC void mc_mulax3x3l(long double * b, long double a[9], long double x[3])
{
//!# b=a*x
	b[0] = 0.0L; b[1] = 0.0L; b[2] = 0.0L;

	b[0] = b[0] + (a[0] * x[0]);
	b[0] = b[0] + (a[1] * x[1]);
	b[0] = b[0] + (a[2] * x[2]);

	b[1] = b[1] + (a[3] * x[0]);
	b[1] = b[1] + (a[4] * x[1]);
	b[1] = b[1] + (a[5] * x[2]);

	b[2] = b[2] + (a[6] * x[0]);
	b[2] = b[2] + (a[7] * x[1]);
	b[2] = b[2] + (a[8] * x[2]);
}

#endif /* !MC_MULAX3X3_H */

/* EOF */