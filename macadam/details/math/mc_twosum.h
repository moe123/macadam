//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_twosum.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_TWOSUM_H
#define MC_TWOSUM_H

#pragma mark - mc_twosum -

MC_TARGET_FUNC void mc_twosumf(float a, float b, float * x, float * y)
{
//!# Knuth algorithm, 6 floating point operations. Result x is a+b, y is the error
//!# such that x+y exactly equals a+b.
	*x            =  a + b;
	const float z = *x - a;
	*y            =  a - (*x - z) + (b - z);
}

MC_TARGET_FUNC void mc_twosum(double a, double b, double * x, double * y)
{
//!# Knuth algorithm, 6 floating point operations. Result x is a+b, y is the error
//!# such that x+y exactly equals a+b.
	*x             =  a + b;
	const double z = *x - a;
	*y             =  a - (*x - z) + (b - z);
}

MC_TARGET_FUNC void mc_twosuml(long double a, long double b, long double * x, long double * y)
{
//!# Knuth algorithm, 6 floating point operations. Result x is a+b, y is the error
//!# such that x+y exactly equals a+b.
	*x                  =  a + b;
	const long double z = *x - a;
	*y                  =  a - (*x - z) + (b - z);
}

#endif /* !MC_TWOSUM_H */

/* EOF */