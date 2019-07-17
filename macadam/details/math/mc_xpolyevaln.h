//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_xpolyevaln.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_XPOLYEVALN_H
#define MC_XPOLYEVALN_H

#pragma mark - mc_xpolyevalne -

static MC_TARGET_INLINE float mc_xpolyevalnef(float x, const float * p, unsigned int n, float * err)
{
//!# Evaluating the polynomial p (in ascending powers order) at
//!# the specified value of x + computes absolute error estimate.
	int i, m;
	float z, s = 0.0f, e;
	if (n > 0 && n < 256) {
		m = mc_cast(int, n);
		s = p[m - 1];
		if (err != NULL) {
#	if MC_TARGET_CPP98
			z = ::fabsf(x);
			e = 0.5f * ::fabsf(s);
			for (i = m - 2; i >= 0; i--) {
				s = s * x + p[i];
				e = e * z + ::fabsf(s);
			}
			e    = MCLIMITS_EPSILONF * ::fabsf(2.0f * e - ::fabsf(s));
			*err = e;
#	else
			z = fabsf(x);
			e = 0.5f * fabsf(s);
			for (i = m - 2; i >= 0; i--) {
				s = s * x + p[i];
				e = e * z + fabsf(s);
			}
			e    = MCLIMITS_EPSILONF * fabsf(2.0f * e - fabsf(s));
			*err = e;
#	endif
		} else {
			for (i = m - 2; i >= 0; i--) {
				s = s * x + p[i];
			}
		}
	}
	return s;
}

static MC_TARGET_INLINE double mc_xpolyevalne(double x, const double * p, unsigned int n, double * err)
{
//!# Evaluating the polynomial p (in ascending powers order) at
//!# the specified value of x + computes absolute error estimate.
	int i, m;
	double z, s = 0.0, e;
	if (n > 0 && n < 256) {
		m = mc_cast(int, n);
		s = p[m - 1];
		if (err != NULL) {
#	if MC_TARGET_CPP98
			z = fabs(x);
			e = 0.5 * ::fabs(s);
			for (i = m - 2; i >= 0; i--) {
				s = s * x + p[i];
				e = e * z + ::fabs(s);
			}
			e    = MCLIMITS_EPSILON * ::fabs(2.0 * e - ::fabs(s));
			*err = e;
#	else
			z = fabs(x);
			e = 0.5 * fabs(s);
			for (i = m - 2; i >= 0; i--) {
				s = s * x + p[i];
				e = e * z + fabs(s);
			}
			e    = MCLIMITS_EPSILON * fabs(2.0 * e - fabs(s));
			*err = e;
#	endif
		} else {
			for (i = m - 2; i >= 0; i--) {
				s = s * x + p[i];
			}
		}
	}
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyevalnel(long double x, const long double * p, unsigned int n, long double * err)
{
//!# Evaluating the polynomial p (in ascending powers order) at
//!# the specified value of x + computes absolute error estimate.
	int i, m;
	long double z, s = 0.0L, e;
	if (n > 0 && n < 256) {
		m = mc_cast(int, n);
		s = p[m - 1];
		if (err != NULL) {
#	if MC_TARGET_CPP98
			z = fabsl(x);
			e = 0.5L * ::fabsl(s);
			for (i = m - 2; i >= 0; i--) {
				s = s * x + p[i];
				e = e * z + ::fabsl(s);
			}
			e    = MCLIMITS_EPSILONL * ::fabsl(2.0L * e - ::fabsl(s));
			*err = e;
#	else
			z = fabsl(x);
			e = 0.5L * fabsl(s);
			for (i = m - 2; i >= 0; i--) {
				s = s * x + p[i];
				e = e * z + fabsl(s);
			}
			e    = MCLIMITS_EPSILONL * fabsl(2.0L * e - fabsl(s));
			*err = e;
#	endif
		} else {
			for (i = m - 2; i >= 0; i--) {
				s = s * x + p[i];
			}
		}
	}
	return s;
}

#pragma mark - mc_xpolyeval2 -

static MC_TARGET_INLINE float mc_xpolyeval2f(float x
	, float p1
	, float p2
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	float s;
	s = p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE double mc_xpolyeval2(double x
	, double p1
	, double p2
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	double s;
	s = p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyeval2l(long double x
	, long double p1
	, long double p2
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	long double s;
	s = p2;
	s = s * x + p1;
	return s;
}

#pragma mark - mc_xpolyeval3 -

static MC_TARGET_INLINE float mc_xpolyeval3f(float x
	, float p1
	, float p2
	, float p3
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	float s;
	s = p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE double mc_xpolyeval3(double x
	, double p1
	, double p2
	, double p3
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	double s;
	s = p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyeval3l(long double x
	, long double p1
	, long double p2
	, long double p3
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	long double s;
	s = p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

#pragma mark - mc_xpolyeval4 -

static MC_TARGET_INLINE float mc_xpolyeval4f(float x
	, float p1
	, float p2
	, float p3
	, float p4
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	float s;
	s = p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE double mc_xpolyeval4(double x
	, double p1
	, double p2
	, double p3
	, double p4
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	double s;
	s = p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyeval4l(long double x
	, long double p1
	, long double p2
	, long double p3
	, long double p4
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	long double s;
	s = p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

#pragma mark - mc_xpolyeval5 -

static MC_TARGET_INLINE float mc_xpolyeval5f(float x
	, float p1
	, float p2
	, float p3
	, float p4
	, float p5
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	float s;
	s = p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE double mc_xpolyeval5(double x
	, double p1
	, double p2
	, double p3
	, double p4
	, double p5
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	double s;
	s = p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyeval5l(long double x
	, long double p1
	, long double p2
	, long double p3
	, long double p4
	, long double p5
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	long double s;
	s = p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

#pragma mark - mc_xpolyeval6 -

static MC_TARGET_INLINE float mc_xpolyeval6f(float x
	, float p1
	, float p2
	, float p3
	, float p4
	, float p5
	, float p6
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	float s;
	s = p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE double mc_xpolyeval6(double x
	, double p1
	, double p2
	, double p3
	, double p4
	, double p5
	, double p6
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	double s;
	s = p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyeval6l(long double x
	, long double p1
	, long double p2
	, long double p3
	, long double p4
	, long double p5
	, long double p6
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	long double s;
	s = p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

#pragma mark - mc_xpolyeval7 -

static MC_TARGET_INLINE float mc_xpolyeval7f(float x
	, float p1
	, float p2
	, float p3
	, float p4
	, float p5
	, float p6
	, float p7
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	float s;
	s = p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE double mc_xpolyeval7(double x
	, double p1
	, double p2
	, double p3
	, double p4
	, double p5
	, double p6
	, double p7
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	double s;
	s = p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyeval7l(long double x
	, long double p1
	, long double p2
	, long double p3
	, long double p4
	, long double p5
	, long double p6
	, long double p7
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	long double s;
	s = p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

#pragma mark - mc_xpolyeval8 -

static MC_TARGET_INLINE float mc_xpolyeval8f(float x
	, float p1
	, float p2
	, float p3
	, float p4
	, float p5
	, float p6
	, float p7
	, float p8
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	float s;
	s = p8;
	s = s * x + p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE double mc_xpolyeval8(double x
	, double p1
	, double p2
	, double p3
	, double p4
	, double p5
	, double p6
	, double p7
	, double p8
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	double s;
	s = p8;
	s = s * x + p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyeval8l(long double x
	, long double p1
	, long double p2
	, long double p3
	, long double p4
	, long double p5
	, long double p6
	, long double p7
	, long double p8
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	long double s;
	s = p8;
	s = s * x + p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

#pragma mark - mc_xpolyeval9 -

static MC_TARGET_INLINE float mc_xpolyeval9f(float x
	, float p1
	, float p2
	, float p3
	, float p4
	, float p5
	, float p6
	, float p7
	, float p8
	, float p9
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	float s;
	s = p9;
	s = s * x + p8;
	s = s * x + p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE double mc_xpolyeval9(double x
	, double p1
	, double p2
	, double p3
	, double p4
	, double p5
	, double p6
	, double p7
	, double p8
	, double p9
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	double s;
	s = p9;
	s = s * x + p8;
	s = s * x + p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyeval9l(long double x
	, long double p1
	, long double p2
	, long double p3
	, long double p4
	, long double p5
	, long double p6
	, long double p7
	, long double p8
	, long double p9
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	long double s;
	s = p9;
	s = s * x + p8;
	s = s * x + p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

#pragma mark - mc_xpolyeval10 -

static MC_TARGET_INLINE float mc_xpolyeval10f(float x
	, float p1
	, float p2
	, float p3
	, float p4
	, float p5
	, float p6
	, float p7
	, float p8
	, float p9
	, float p10
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	float s;
	s = p10;
	s = s * x + p9;
	s = s * x + p8;
	s = s * x + p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE double mc_xpolyeval10(double x
	, double p1
	, double p2
	, double p3
	, double p4
	, double p5
	, double p6
	, double p7
	, double p8
	, double p9
	, double p10
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	double s;
	s = p10;
	s = s * x + p9;
	s = s * x + p8;
	s = s * x + p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyeval10l(long double x
	, long double p1
	, long double p2
	, long double p3
	, long double p4
	, long double p5
	, long double p6
	, long double p7
	, long double p8
	, long double p9
	, long double p10
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	long double s;
	s = p10;
	s = s * x + p9;
	s = s * x + p8;
	s = s * x + p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

#pragma mark - mc_xpolyeval11 -

static MC_TARGET_INLINE float mc_xpolyeval11f(float x
	, float p1
	, float p2
	, float p3
	, float p4
	, float p5
	, float p6
	, float p7
	, float p8
	, float p9
	, float p10
	, float p11
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	float s;
	s = p11;
	s = s * x + p10;
	s = s * x + p9;
	s = s * x + p8;
	s = s * x + p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE double mc_xpolyeval11(double x
	, double p1
	, double p2
	, double p3
	, double p4
	, double p5
	, double p6
	, double p7
	, double p8
	, double p9
	, double p10
	, double p11
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	double s;
	s = p11;
	s = s * x + p10;
	s = s * x + p9;
	s = s * x + p8;
	s = s * x + p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyeval11l(long double x
	, long double p1
	, long double p2
	, long double p3
	, long double p4
	, long double p5
	, long double p6
	, long double p7
	, long double p8
	, long double p9
	, long double p10
	, long double p11
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	long double s;
	s = p11;
	s = s * x + p10;
	s = s * x + p9;
	s = s * x + p8;
	s = s * x + p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

#pragma mark - mc_xpolyeval12 -

static MC_TARGET_INLINE float mc_xpolyeval12f(float x
	, float p1
	, float p2
	, float p3
	, float p4
	, float p5
	, float p6
	, float p7
	, float p8
	, float p9
	, float p10
	, float p11
	, float p12
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	float s;
	s = p12;
	s = s * x + p11;
	s = s * x + p10;
	s = s * x + p9;
	s = s * x + p8;
	s = s * x + p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE double mc_xpolyeval12(double x
	, double p1
	, double p2
	, double p3
	, double p4
	, double p5
	, double p6
	, double p7
	, double p8
	, double p9
	, double p10
	, double p11
	, double p12
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	double s;
	s = p12;
	s = s * x + p11;
	s = s * x + p10;
	s = s * x + p9;
	s = s * x + p8;
	s = s * x + p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyeval12l(long double x
	, long double p1
	, long double p2
	, long double p3
	, long double p4
	, long double p5
	, long double p6
	, long double p7
	, long double p8
	, long double p9
	, long double p10
	, long double p11
	, long double p12
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	long double s;
	s = p12;
	s = s * x + p11;
	s = s * x + p10;
	s = s * x + p9;
	s = s * x + p8;
	s = s * x + p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

#pragma mark - mc_xpolyeval13 -

static MC_TARGET_INLINE float mc_xpolyeval13f(float x
	, float p1
	, float p2
	, float p3
	, float p4
	, float p5
	, float p6
	, float p7
	, float p8
	, float p9
	, float p10
	, float p11
	, float p12
	, float p13
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	float s;
	s = p13;
	s = s * x + p12;
	s = s * x + p11;
	s = s * x + p10;
	s = s * x + p9;
	s = s * x + p8;
	s = s * x + p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE double mc_xpolyeval13(double x
	, double p1
	, double p2
	, double p3
	, double p4
	, double p5
	, double p6
	, double p7
	, double p8
	, double p9
	, double p10
	, double p11
	, double p12
	, double p13
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	double s;
	s = p13;
	s = s * x + p12;
	s = s * x + p11;
	s = s * x + p10;
	s = s * x + p9;
	s = s * x + p8;
	s = s * x + p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyeval13l(long double x
	, long double p1
	, long double p2
	, long double p3
	, long double p4
	, long double p5
	, long double p6
	, long double p7
	, long double p8
	, long double p9
	, long double p10
	, long double p11
	, long double p12
	, long double p13
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	long double s;
	s = p13;
	s = s * x + p12;
	s = s * x + p11;
	s = s * x + p10;
	s = s * x + p9;
	s = s * x + p8;
	s = s * x + p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

#pragma mark - mc_xpolyeval14 -

static MC_TARGET_INLINE float mc_xpolyeval14f(float x
	, float p1
	, float p2
	, float p3
	, float p4
	, float p5
	, float p6
	, float p7
	, float p8
	, float p9
	, float p10
	, float p11
	, float p12
	, float p13
	, float p14
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	float s;
	s = p14;
	s = s * x + p13;
	s = s * x + p12;
	s = s * x + p11;
	s = s * x + p10;
	s = s * x + p9;
	s = s * x + p8;
	s = s * x + p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE double mc_xpolyeval14(double x
	, double p1
	, double p2
	, double p3
	, double p4
	, double p5
	, double p6
	, double p7
	, double p8
	, double p9
	, double p10
	, double p11
	, double p12
	, double p13
	, double p14
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	double s;
	s = p14;
	s = s * x + p13;
	s = s * x + p12;
	s = s * x + p11;
	s = s * x + p10;
	s = s * x + p9;
	s = s * x + p8;
	s = s * x + p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyeval14l(long double x
	, long double p1
	, long double p2
	, long double p3
	, long double p4
	, long double p5
	, long double p6
	, long double p7
	, long double p8
	, long double p9
	, long double p10
	, long double p11
	, long double p12
	, long double p13
	, long double p14
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	long double s;
	s = p14;
	s = s * x + p13;
	s = s * x + p12;
	s = s * x + p11;
	s = s * x + p10;
	s = s * x + p9;
	s = s * x + p8;
	s = s * x + p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

#pragma mark - mc_xpolyeval15 -

static MC_TARGET_INLINE float mc_xpolyeval15f(float x
	, float p1
	, float p2
	, float p3
	, float p4
	, float p5
	, float p6
	, float p7
	, float p8
	, float p9
	, float p10
	, float p11
	, float p12
	, float p13
	, float p14
	, float p15
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	float s;
	s = p15;
	s = s * x + p14;
	s = s * x + p13;
	s = s * x + p12;
	s = s * x + p11;
	s = s * x + p10;
	s = s * x + p9;
	s = s * x + p8;
	s = s * x + p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE double mc_xpolyeval15(double x
	, double p1
	, double p2
	, double p3
	, double p4
	, double p5
	, double p6
	, double p7
	, double p8
	, double p9
	, double p10
	, double p11
	, double p12
	, double p13
	, double p14
	, double p15
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	double s;
	s = p15;
	s = s * x + p14;
	s = s * x + p13;
	s = s * x + p12;
	s = s * x + p11;
	s = s * x + p10;
	s = s * x + p9;
	s = s * x + p8;
	s = s * x + p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyeval15l(long double x
	, long double p1
	, long double p2
	, long double p3
	, long double p4
	, long double p5
	, long double p6
	, long double p7
	, long double p8
	, long double p9
	, long double p10
	, long double p11
	, long double p12
	, long double p13
	, long double p14
	, long double p15
) {
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	long double s;
	s = p15;
	s = s * x + p14;
	s = s * x + p13;
	s = s * x + p12;
	s = s * x + p11;
	s = s * x + p10;
	s = s * x + p9;
	s = s * x + p8;
	s = s * x + p7;
	s = s * x + p6;
	s = s * x + p5;
	s = s * x + p4;
	s = s * x + p3;
	s = s * x + p2;
	s = s * x + p1;
	return s;
}

#pragma mark - mc_xpolyevaln -

static MC_TARGET_INLINE float mc_xpolyevalnf(float x, const float * p, unsigned int n)
{
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	float s;
	switch (n)
	{
	case 2:
		s = mc_xpolyeval2f(x, p[0], p[1]);
	break;
	case 3:
		s = mc_xpolyeval3f(x, p[0], p[1], p[2]);
	break;
	case 4:
		s = mc_xpolyeval4f(x, p[0], p[1], p[2], p[3]);
	break;
	case 5:
		s = mc_xpolyeval5f(x, p[0], p[1], p[2], p[3], p[4]);
	break;
	case 6:
		s = mc_xpolyeval6f(x, p[0], p[1], p[2], p[3], p[4], p[5]);
	break;
	case 7:
		s = mc_xpolyeval7f(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6]);
	break;
	case 8:
		s = mc_xpolyeval8f(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7]);
	break;
	case 9:
		s = mc_xpolyeval9f(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8]);
	break;
	case 10:
		s = mc_xpolyeval10f(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9]);
	break;
	case 11:
		s = mc_xpolyeval11f(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9], p[10]);
	break;
	case 12:
		s = mc_xpolyeval12f(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9], p[10], p[11]);
	break;
	case 13:
		s = mc_xpolyeval13f(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9], p[10], p[11], p[12]);
	break;
	case 14:
		s = mc_xpolyeval14f(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9], p[10], p[11], p[12], p[13]);
	break;
	case 15:
		s = mc_xpolyeval15f(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9], p[10], p[11], p[12], p[13], p[14]);
	break;
	default:
		s = mc_xpolyevalnef(x, p, n, NULL);
	}
	return s;
}

static MC_TARGET_INLINE double mc_xpolyevaln(double x, const double * p, unsigned int n)
{
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	double s;
	switch (n)
	{
	case 2:
		s = mc_xpolyeval2(x, p[0], p[1]);
	break;
	case 3:
		s = mc_xpolyeval3(x, p[0], p[1], p[2]);
	break;
	case 4:
		s = mc_xpolyeval4(x, p[0], p[1], p[2], p[3]);
	break;
	case 5:
		s = mc_xpolyeval5(x, p[0], p[1], p[2], p[3], p[4]);
	break;
	case 6:
		s = mc_xpolyeval6(x, p[0], p[1], p[2], p[3], p[4], p[5]);
	break;
	case 7:
		s = mc_xpolyeval7(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6]);
	break;
	case 8:
		s = mc_xpolyeval8(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7]);
	break;
	case 9:
		s = mc_xpolyeval9(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8]);
	break;
	case 10:
		s = mc_xpolyeval10(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9]);
	break;
	case 11:
		s = mc_xpolyeval11(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9], p[10]);
	break;
	case 12:
		s = mc_xpolyeval12(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9], p[10], p[11]);
	break;
	case 13:
		s = mc_xpolyeval13(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9], p[10], p[11], p[12]);
	break;
	case 14:
		s = mc_xpolyeval14(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9], p[10], p[11], p[12], p[13]);
	break;
	case 15:
		s = mc_xpolyeval15(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9], p[10], p[11], p[12], p[13], p[14]);
	break;
	default:
		s = mc_xpolyevalne(x, p, n, NULL);
	}
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyevalnl(long double x, const long double * p, unsigned int n)
{
//!# Evaluating the polynomial p (in ascending powers order) at the specified value of x.
	long double s;
	switch (n)
	{
	case 2:
		s = mc_xpolyeval2l(x, p[0], p[1]);
	break;
	case 3:
		s = mc_xpolyeval3l(x, p[0], p[1], p[2]);
	break;
	case 4:
		s = mc_xpolyeval4l(x, p[0], p[1], p[2], p[3]);
	break;
	case 5:
		s = mc_xpolyeval5l(x, p[0], p[1], p[2], p[3], p[4]);
	break;
	case 6:
		s = mc_xpolyeval6l(x, p[0], p[1], p[2], p[3], p[4], p[5]);
	break;
	case 7:
		s = mc_xpolyeval7l(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6]);
	break;
	case 8:
		s = mc_xpolyeval8l(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7]);
	break;
	case 9:
		s = mc_xpolyeval9l(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8]);
	break;
	case 10:
		s = mc_xpolyeval10l(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9]);
	break;
	case 11:
		s = mc_xpolyeval11l(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9], p[10]);
	break;
	case 12:
		s = mc_xpolyeval12l(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9], p[10], p[11]);
	break;
	case 13:
		s = mc_xpolyeval13l(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9], p[10], p[11], p[12]);
	break;
	case 14:
		s = mc_xpolyeval14l(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9], p[10], p[11], p[12], p[13]);
	break;
	case 15:
		s = mc_xpolyeval15l(x, p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9], p[10], p[11], p[12], p[13], p[14]);
	break;
	default:
		s = mc_xpolyevalnel(x, p, n, NULL);
	}
	return s;
}

#endif /* !MC_XPOLYEVALN_H */

/* EOF */