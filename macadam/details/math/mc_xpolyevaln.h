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

static MC_TARGET_INLINE float mc_xpolyevalnef(float x, const float * a, unsigned int n, float * err)
{
//!# Evaluating the polynomial a (in ascending powers order) at
//!# the specified value of x + computes absolute error estimate.
	int i, m ;
	float z, s = 0.0f, e;
	if (n > 0 && n < 128) {
		m = mc_cast(int, n); 
		s = a[m - 1];
		if (err != NULL) {
#	if MC_TARGET_CPP98
			z = ::fabsf(x);
			e = 0.5f * ::fabsf(s);
			for (i = m - 2; i >= 0; i--) {
				s = s * x + a[i];
				e = e * z + ::fabsf(s);
			}
			e    = MCLIMITS_EPSILONF * ::fabsf(2.0f * e - ::fabsf(s));
			*err = e;
#	else
			z = fabsf(x);
			e = 0.5f * fabsf(s);
			for (i = m - 2; i >= 0; i--) {
				s = s * x + a[i];
				e = e * z + fabsf(s);
			}
			e    = MCLIMITS_EPSILONF * fabsf(2.0f * e - fabsf(s));
			*err = e;
#	endif
		} else {
			for (i = m - 2; i >= 0; i--) {
				s = s * x + a[i];
			}
		}
	}
	return s;
}

static MC_TARGET_INLINE double mc_xpolyevalne(double x, const double * a, unsigned int n, double * err)
{
//!# Evaluating the polynomial a (in ascending powers order) at
//!# the specified value of x + computes absolute error estimate.
	int i, m ;
	double z, s = 0.0, e;
	if (n > 0 && n < 128) {
		m = mc_cast(int, n); 
		s = a[m - 1];
		if (err != NULL) {
#	if MC_TARGET_CPP98
			z = fabs(x);
			e = 0.5 * ::fabs(s);
			for (i = m - 2; i >= 0; i--) {
				s = s * x + a[i];
				e = e * z + ::fabs(s);
			}
			e    = MCLIMITS_EPSILON * ::fabs(2.0 * e - ::fabs(s));
			*err = e;
#	else
			z = fabs(x);
			e = 0.5 * fabs(s);
			for (i = m - 2; i >= 0; i--) {
				s = s * x + a[i];
				e = e * z + fabs(s);
			}
			e    = MCLIMITS_EPSILON * fabs(2.0 * e - fabs(s));
			*err = e;
#	endif
		} else {
			for (i = m - 2; i >= 0; i--) {
				s = s * x + a[i];
			}
		}
	}
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyevalnel(long double x, const long double * a, unsigned int n, long double * err)
{
//!# Evaluating the polynomial a (in ascending powers order) at
//!# the specified value of x + computes absolute error estimate.
	int i, m ;
	long double z, s = 0.0L, e;
	if (n > 0 && n < 128) {
		m = mc_cast(int, n); 
		s = a[m - 1];
		if (err != NULL) {
#	if MC_TARGET_CPP98
			z = fabsl(x);
			e = 0.5L * ::fabsl(s);
			for (i = m - 2; i >= 0; i--) {
				s = s * x + a[i];
				e = e * z + ::fabsl(s);
			}
			e    = MCLIMITS_EPSILONL * ::fabsl(2.0L * e - ::fabsl(s));
			*err = e;
#	else
			z = fabsl(x);
			e = 0.5L * fabsl(s);
			for (i = m - 2; i >= 0; i--) {
				s = s * x + a[i];
				e = e * z + fabsl(s);
			}
			e    = MCLIMITS_EPSILONL * fabsl(2.0L * e - fabsl(s));
			*err = e;
#	endif
		} else {
			for (i = m - 2; i >= 0; i--) {
				s = s * x + a[i];
			}
		}
	}
	return s;
}

#pragma mark - mc_xpolyeval2 -

static MC_TARGET_INLINE float mc_xpolyeval2f(float x
	, float a1
	, float a2
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	float s;
	s = a2;
	s = s * x + a1;
	return s;
}

static MC_TARGET_INLINE double mc_xpolyeval2(double x
	, double a1
	, double a2
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	double s;
	s = a2;
	s = s * x + a1;
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyeval2l(long double x
	, long double a1
	, long double a2
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	long double s;
	s = a2;
	s = s * x + a1;
	return s;
}

#pragma mark - mc_xpolyeval3 -

static MC_TARGET_INLINE float mc_xpolyeval3f(float x
	, float a1
	, float a2
	, float a3
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	float s;
	s = a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

static MC_TARGET_INLINE double mc_xpolyeval3(double x
	, double a1
	, double a2
	, double a3
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	double s;
	s = a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyeval3l(long double x
	, long double a1
	, long double a2
	, long double a3
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	long double s;
	s = a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

#pragma mark - mc_xpolyeval4 -

static MC_TARGET_INLINE float mc_xpolyeval4f(float x
	, float a1
	, float a2
	, float a3
	, float a4
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	float s;
	s = a4;
	s = s * x + a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

static MC_TARGET_INLINE double mc_xpolyeval4(double x
	, double a1
	, double a2
	, double a3
	, double a4
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	double s;
	s = a4;
	s = s * x + a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyeval4l(long double x
	, long double a1
	, long double a2
	, long double a3
	, long double a4
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	long double s;
	s = a4;
	s = s * x + a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

#pragma mark - mc_xpolyeval5 -

static MC_TARGET_INLINE float mc_xpolyeval5f(float x
	, float a1
	, float a2
	, float a3
	, float a4
	, float a5
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	float s;
	s = a5;
	s = s * x + a4;
	s = s * x + a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

static MC_TARGET_INLINE double mc_xpolyeval5(double x
	, double a1
	, double a2
	, double a3
	, double a4
	, double a5
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	double s;
	s = a5;
	s = s * x + a4;
	s = s * x + a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyeval5l(long double x
	, long double a1
	, long double a2
	, long double a3
	, long double a4
	, long double a5
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	long double s;
	s = a5;
	s = s * x + a4;
	s = s * x + a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

#pragma mark - mc_xpolyeval6 -

static MC_TARGET_INLINE float mc_xpolyeval6f(float x
	, float a1
	, float a2
	, float a3
	, float a4
	, float a5
	, float a6
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	float s;
	s = a6;
	s = s * x + a5;
	s = s * x + a4;
	s = s * x + a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

static MC_TARGET_INLINE double mc_xpolyeval6(double x
	, double a1
	, double a2
	, double a3
	, double a4
	, double a5
	, double a6
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	double s;
	s = a6;
	s = s * x + a5;
	s = s * x + a4;
	s = s * x + a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyeval6l(long double x
	, long double a1
	, long double a2
	, long double a3
	, long double a4
	, long double a5
	, long double a6
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	long double s;
	s = a6;
	s = s * x + a5;
	s = s * x + a4;
	s = s * x + a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

#pragma mark - mc_xpolyeval7 -

static MC_TARGET_INLINE float mc_xpolyeval7f(float x
	, float a1
	, float a2
	, float a3
	, float a4
	, float a5
	, float a6
	, float a7
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	float s;
	s = a7;
	s = s * x + a6;
	s = s * x + a5;
	s = s * x + a4;
	s = s * x + a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

static MC_TARGET_INLINE double mc_xpolyeval7(double x
	, double a1
	, double a2
	, double a3
	, double a4
	, double a5
	, double a6
	, double a7
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	double s;
	s = a7;
	s = s * x + a6;
	s = s * x + a5;
	s = s * x + a4;
	s = s * x + a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyeval7l(long double x
	, long double a1
	, long double a2
	, long double a3
	, long double a4
	, long double a5
	, long double a6
	, long double a7
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	long double s;
	s = a7;
	s = s * x + a6;
	s = s * x + a5;
	s = s * x + a4;
	s = s * x + a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

#pragma mark - mc_xpolyeval8 -

static MC_TARGET_INLINE float mc_xpolyeval8f(float x
	, float a1
	, float a2
	, float a3
	, float a4
	, float a5
	, float a6
	, float a7
	, float a8
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	float s;
	s = a8;
	s = s * x + a7;
	s = s * x + a6;
	s = s * x + a5;
	s = s * x + a4;
	s = s * x + a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

static MC_TARGET_INLINE double mc_xpolyeval8(double x
	, double a1
	, double a2
	, double a3
	, double a4
	, double a5
	, double a6
	, double a7
	, double a8
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	double s;
	s = a8;
	s = s * x + a7;
	s = s * x + a6;
	s = s * x + a5;
	s = s * x + a4;
	s = s * x + a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyeval8l(long double x
	, long double a1
	, long double a2
	, long double a3
	, long double a4
	, long double a5
	, long double a6
	, long double a7
	, long double a8
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	long double s;
	s = a8;
	s = s * x + a7;
	s = s * x + a6;
	s = s * x + a5;
	s = s * x + a4;
	s = s * x + a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

#pragma mark - mc_xpolyeval9 -

static MC_TARGET_INLINE float mc_xpolyeval9f(float x
	, float a1
	, float a2
	, float a3
	, float a4
	, float a5
	, float a6
	, float a7
	, float a8
	, float a9
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	float s;
	s = a9;
	s = s * x + a8;
	s = s * x + a7;
	s = s * x + a6;
	s = s * x + a5;
	s = s * x + a4;
	s = s * x + a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

static MC_TARGET_INLINE double mc_xpolyeval9(double x
	, double a1
	, double a2
	, double a3
	, double a4
	, double a5
	, double a6
	, double a7
	, double a8
	, double a9
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	double s;
	s = a9;
	s = s * x + a8;
	s = s * x + a7;
	s = s * x + a6;
	s = s * x + a5;
	s = s * x + a4;
	s = s * x + a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyeval9l(long double x
	, long double a1
	, long double a2
	, long double a3
	, long double a4
	, long double a5
	, long double a6
	, long double a7
	, long double a8
	, long double a9
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	long double s;
	s = a9;
	s = s * x + a8;
	s = s * x + a7;
	s = s * x + a6;
	s = s * x + a5;
	s = s * x + a4;
	s = s * x + a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

#pragma mark - mc_xpolyeval10 -

static MC_TARGET_INLINE float mc_xpolyeval10f(float x
	, float a1
	, float a2
	, float a3
	, float a4
	, float a5
	, float a6
	, float a7
	, float a8
	, float a9
	, float a10
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	float s;
	s = a10;
	s = s * x + a9;
	s = s * x + a8;
	s = s * x + a7;
	s = s * x + a6;
	s = s * x + a5;
	s = s * x + a4;
	s = s * x + a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

static MC_TARGET_INLINE double mc_xpolyeval10(double x
	, double a1
	, double a2
	, double a3
	, double a4
	, double a5
	, double a6
	, double a7
	, double a8
	, double a9
	, double a10
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	double s;
	s = a10;
	s = s * x + a9;
	s = s * x + a8;
	s = s * x + a7;
	s = s * x + a6;
	s = s * x + a5;
	s = s * x + a4;
	s = s * x + a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyeval10l(long double x
	, long double a1
	, long double a2
	, long double a3
	, long double a4
	, long double a5
	, long double a6
	, long double a7
	, long double a8
	, long double a9
	, long double a10
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	long double s;
	s = a10;
	s = s * x + a9;
	s = s * x + a8;
	s = s * x + a7;
	s = s * x + a6;
	s = s * x + a5;
	s = s * x + a4;
	s = s * x + a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

#pragma mark - mc_xpolyeval11 -

static MC_TARGET_INLINE float mc_xpolyeval11f(float x
	, float a1
	, float a2
	, float a3
	, float a4
	, float a5
	, float a6
	, float a7
	, float a8
	, float a9
	, float a10
	, float a11
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	float s;
	s = a11;
	s = s * x + a10;
	s = s * x + a9;
	s = s * x + a8;
	s = s * x + a7;
	s = s * x + a6;
	s = s * x + a5;
	s = s * x + a4;
	s = s * x + a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

static MC_TARGET_INLINE double mc_xpolyeval11(double x
	, double a1
	, double a2
	, double a3
	, double a4
	, double a5
	, double a6
	, double a7
	, double a8
	, double a9
	, double a10
	, double a11
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	double s;
	s = a11;
	s = s * x + a10;
	s = s * x + a9;
	s = s * x + a8;
	s = s * x + a7;
	s = s * x + a6;
	s = s * x + a5;
	s = s * x + a4;
	s = s * x + a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyeval11l(long double x
	, long double a1
	, long double a2
	, long double a3
	, long double a4
	, long double a5
	, long double a6
	, long double a7
	, long double a8
	, long double a9
	, long double a10
	, long double a11
) {
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	long double s;
	s = a11;
	s = s * x + a10;
	s = s * x + a9;
	s = s * x + a8;
	s = s * x + a7;
	s = s * x + a6;
	s = s * x + a5;
	s = s * x + a4;
	s = s * x + a3;
	s = s * x + a2;
	s = s * x + a1;
	return s;
}

#pragma mark - mc_xpolyevaln -

static MC_TARGET_INLINE float mc_xpolyevalnf(float x, const float * a, unsigned int n)
{
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	float s;
	switch (n)
	{
	case 2:
		s = mc_xpolyeval2f(x, a[0], a[1]);
	break;
	case 3:
		s = mc_xpolyeval3f(x, a[0], a[1], a[2]);
	break;
	case 4:
		s = mc_xpolyeval4f(x, a[0], a[1], a[2], a[3]);
	break;
	case 5:
		s = mc_xpolyeval5f(x, a[0], a[1], a[2], a[3], a[4]);
	break;
	case 6:
		s = mc_xpolyeval6f(x, a[0], a[1], a[2], a[3], a[4], a[5]);
	break;
	case 7:
		s = mc_xpolyeval7f(x, a[0], a[1], a[2], a[3], a[4], a[5], a[6]);
	break;
	case 8:
		s = mc_xpolyeval8f(x, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
	break;
	case 9:
		s = mc_xpolyeval9f(x, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
	break;
	case 10:
		s = mc_xpolyeval10f(x, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
	break;
	case 11:
		s = mc_xpolyeval11f(x, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9], a[10]);
	break;
	default:
		s = mc_xpolyevalnef(x, a, n, NULL);
	}
	return s;
}

static MC_TARGET_INLINE double mc_xpolyevaln(double x, const double * a, unsigned int n)
{
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	double s;
	switch (n)
	{
	case 2:
		s = mc_xpolyeval2(x, a[0], a[1]);
	break;
	case 3:
		s = mc_xpolyeval3(x, a[0], a[1], a[2]);
	break;
	case 4:
		s = mc_xpolyeval4(x, a[0], a[1], a[2], a[3]);
	break;
	case 5:
		s = mc_xpolyeval5(x, a[0], a[1], a[2], a[3], a[4]);
	break;
	case 6:
		s = mc_xpolyeval6(x, a[0], a[1], a[2], a[3], a[4], a[5]);
	break;
	case 7:
		s = mc_xpolyeval7(x, a[0], a[1], a[2], a[3], a[4], a[5], a[6]);
	break;
	case 8:
		s = mc_xpolyeval8(x, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
	break;
	case 9:
		s = mc_xpolyeval9(x, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
	break;
	case 10:
		s = mc_xpolyeval10(x, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
	break;
	case 11:
		s = mc_xpolyeval11(x, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9], a[10]);
	break;
	default:
		s = mc_xpolyevalne(x, a, n, NULL);
	}
	return s;
}

static MC_TARGET_INLINE long double mc_xpolyevalnl(long double x, const long double * a, unsigned int n)
{
//!# Evaluating the polynomial a (in ascending powers order) at the specified value of x.
	long double s;
	switch (n)
	{
	case 2:
		s = mc_xpolyeval2l(x, a[0], a[1]);
	break;
	case 3:
		s = mc_xpolyeval3l(x, a[0], a[1], a[2]);
	break;
	case 4:
		s = mc_xpolyeval4l(x, a[0], a[1], a[2], a[3]);
	break;
	case 5:
		s = mc_xpolyeval5l(x, a[0], a[1], a[2], a[3], a[4]);
	break;
	case 6:
		s = mc_xpolyeval6l(x, a[0], a[1], a[2], a[3], a[4], a[5]);
	break;
	case 7:
		s = mc_xpolyeval7l(x, a[0], a[1], a[2], a[3], a[4], a[5], a[6]);
	break;
	case 8:
		s = mc_xpolyeval8l(x, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
	break;
	case 9:
		s = mc_xpolyeval9l(x, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
	break;
	case 10:
		s = mc_xpolyeval10l(x, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
	break;
	case 11:
		s = mc_xpolyeval11l(x, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9], a[10]);
	break;
	default:
		s = mc_xpolyevalnel(x, a, n, NULL);
	}
	return s;
}

#endif /* !MC_XPOLYEVALN_H */

/* EOF */