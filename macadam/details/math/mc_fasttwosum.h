//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_fasttwosum.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_FASTTWOSUM_H
#define MC_FASTTWOSUM_H

#pragma mark - mc_fasttwosum -

MC_TARGET_FUNC void mc_fasttwosumf(float a, float b, float * x, float * y)
{
//!# Dekker algorithm, 3 floating point operations. FastTwoSum computes an
//!# error-free sum of two float64s, with conditions on the relative magnitudes.
//!# Error-free means the result x is floating-point sum a+b, and y is the
//!# floating-point error such that x+y exactly equals a+b. Results are accurate
//!# when |b| <= |a|, but are also still accurate as long as no trailing nonzero
//!# bit of a is smaller than the least significant.
	*x = a + b;
	*y = a - *x + b;
}

MC_TARGET_FUNC void mc_fasttwosum(double a, double b, double * x, double * y)
{
//!# Dekker algorithm, 3 floating point operations. FastTwoSum computes an
//!# error-free sum of two float64s, with conditions on the relative magnitudes.
//!# Error-free means the result x is floating-point sum a+b, and y is the
//!# floating-point error such that x+y exactly equals a+b. Results are accurate
//!# when |b| <= |a|, but are also still accurate as long as no trailing nonzero
//!# bit of a is smaller than the least significant.
	*x = a + b;
	*y = a - *x + b;
}

MC_TARGET_FUNC void mc_fasttwosuml(long double a, long double b, long double * x, long double * y)
{
//!# Dekker algorithm, 3 floating point operations. FastTwoSum computes an
//!# error-free sum of two float64s, with conditions on the relative magnitudes.
//!# Error-free means the result x is floating-point sum a+b, and y is the
//!# floating-point error such that x+y exactly equals a+b. Results are accurate
//!# when |b| <= |a|, but are also still accurate as long as no trailing nonzero
//!# bit of a is smaller than the least significant.
	*x = a + b;
	*y = a - *x + b;
}

#endif /* !MC_FASTTWOSUM_H */

/* EOF */