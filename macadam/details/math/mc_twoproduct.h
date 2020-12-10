//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_twoproduct.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_TWOPRODUCT_H
#define MC_TWOPRODUCT_H

#pragma mark - mc_twoproduct -

MC_TARGET_FUNC void mc_twoproductf(float a, float b, float * x, float * y)
{
//!#
//!# @note: Dekker's twoProduct is not a robust fma implementation.
//!#

//!# 2^12 + 1.
	const float cs = mc_cast_expr(float, 4096 + 1);

	float a1, a2, b1, b2, c;

	*x = a * b;
//!# split a -> a1,a2
	c  = cs * a;
	a1 = c - (c - a);
	a2 = a - a1;

//!# split b -> b1,b2
	c  = cs * b;
	b1 = c - (c - b);
	b2 = b - b1;

	*y = a2 * b2 - (*x - a1 * b1 - a2 * b1 - a1 * b2);
}

MC_TARGET_FUNC void mc_twoproduct(double a, double b, double * x, double * y)
{
//!#
//!# @note: Dekker's twoProduct is not a robust fma implementation.
//!#

//!# 2^27 + 1.
	const double cs = mc_cast_expr(double, 134217728 + 1);

	double a1, a2, b1, b2, c;

	*x = a * b;
//!# split a -> a1,a2
	c  = cs * a;
	a1 = c - (c - a);
	a2 = a - a1;

//!# split b -> b1,b2
	c  = cs * b;
	b1 = c - (c - b);
	b2 = b - b1;

	*y = a2 * b2 - (*x - a1 * b1 - a2 * b1 - a1 * b2);
}

MC_TARGET_FUNC void mc_twoproductl(long double a, long double b, long double * x, long double * y)
{
//!#
//!# @note: Dekker's twoProduct is not a robust fma implementation.
//!#
#	if !MC_TARGET_LONG_DOUBLE_UNAVAILABLE
//!# 2^32 + 1.
	const long double cs = mc_cast_expr(long double, 4294967296 + 1);
#	else
//!# 2^27 + 1.
	const long double cs = mc_cast_expr(long double, 134217728 + 1);
#	endif
	long double a1, a2, b1, b2, c;

	*x = a * b;
//!# split a -> a1,a2
	c  = cs * a;
	a1 = c - (c - a);
	a2 = a - a1;

//!# split b -> b1,b2
	c  = cs * b;
	b1 = c - (c - b);
	b2 = b - b1;

	*y = a2 * b2 - (*x - a1 * b1 - a2 * b1 - a1 * b2);
}

#endif /* !MC_TWOPRODUCT_H */

/* EOF */