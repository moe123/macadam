//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_addmulax2x2.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_ADDMULAX2X2_H
#define MC_ADDMULAX2X2_H

#pragma mark - mc_addmulax2x2 -

MC_TARGET_FUNC void mc_addmulax2x2f(float * b, const float a[4], const float x[2])
{
//!# b=b + a*b
	b[0] = b[0] + (a[0] * x[0]);
	b[0] = b[0] + (a[1] * x[1]);

	b[1] = b[1] + (a[2] * x[0]);
	b[1] = b[1] + (a[3] * x[1]);
}

MC_TARGET_FUNC void mc_addmulax2x2(double * b, double a[4], double x[2])
{
//!# b=b + a*b
	b[0] = b[0] + (a[0] * x[0]);
	b[0] = b[0] + (a[1] * x[1]);

	b[1] = b[1] + (a[2] * x[0]);
	b[1] = b[1] + (a[3] * x[1]);
}

MC_TARGET_FUNC void mc_addmulax2x2l(long double * b, long double a[4], long double x[2])
{
//!# b=b + a*b
	b[0] = b[0] + (a[0] * x[0]);
	b[0] = b[0] + (a[1] * x[1]);

	b[1] = b[1] + (a[2] * x[0]);
	b[1] = b[1] + (a[3] * x[1]);
}

#endif /* !MC_ADDMULAX2X2_H */

/* EOF */