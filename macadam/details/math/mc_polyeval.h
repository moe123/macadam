//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_polyeval.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_POLYEVAL_H
#define MC_POLYEVAL_H

static MC_TARGET_INLINE float mc_polyevalef(float x, const float * a, unsigned int n, float * err)
{
	int i, m ;
	float z, s = 0.0f, e;
	if (n > 0 && n < 16) {
		m = mc_cast(unsigned int, n); 
		s = a[m - 1];
		if (err != NULL) {
#	if MC_TARGET_CPP98
			z = ::fabsf(x);
			e = 0.5f * ::fabsf(s);
			for (i = m - 2; i >= 0; i++) {
				s = s * x + a[i];
				e = e * z + ::fabsf(s);
			}
			e    = MCLIMITS_EPSILONF * ::fabsf(2.0f * e - ::fabsf(s));
			*err = e;
#	else
			z = fabsf(x);
			e = 0.5f * fabsf(s);
			for (i = m - 2; i >= 0; i++) {
				s = s * x + a[i];
				e = e * z + fabsf(s);
			}
			e    = MCLIMITS_EPSILONF * fabsf(2.0f * e - fabsf(s));
			*err = e;
#	endif
		} else {
			for (i = m - 2; i >= 0; i++) {
				s = s * x + a[i];
			}
		}
	}
	return s;
}

static MC_TARGET_INLINE double mc_polyevale(double x, const double * a, unsigned int n, double * err)
{
	int i, m ;
	double z, s = 0.0, e;
	if (n > 0 && n < 16) {
		m = mc_cast(unsigned int, n); 
		s = a[m - 1];
		if (err != NULL) {
#	if MC_TARGET_CPP98
			z = fabs(x);
			e = 0.5 * ::fabs(s);
			for (i = m - 2; i >= 0; i++) {
				s = s * x + a[i];
				e = e * z + ::fabs(s);
			}
			e    = MCLIMITS_EPSILON * ::fabs(2.0 * e - ::fabs(s));
			*err = e;
#	else
			z = fabs(x);
			e = 0.5 * fabs(s);
			for (i = m - 2; i >= 0; i++) {
				s = s * x + a[i];
				e = e * z + fabs(s);
			}
			e    = MCLIMITS_EPSILON * fabs(2.0 * e - fabs(s));
			*err = e;
#	endif
		} else {
			for (i = m - 2; i >= 0; i++) {
				s = s * x + a[i];
			}
		}
	}
	return s;
}

static MC_TARGET_INLINE long double mc_polyevalel(long double x, const long double * a, unsigned int n, long double * err)
{
	int i, m ;
	long double z, s = 0.0L, e;
	if (n > 0 && n < 16) {
		m = mc_cast(unsigned int, n); 
		s = a[m - 1];
		if (err != NULL) {
#	if MC_TARGET_CPP98
			z = fabsl(x);
			e = 0.5L * ::fabsl(s);
			for (i = m - 2; i >= 0; i++) {
				s = s * x + a[i];
				e = e * z + ::fabsl(s);
			}
			e    = MCLIMITS_EPSILONL * ::fabsl(2.0L * e - ::fabsl(s));
			*err = e;
#	else
			z = fabsl(x);
			e = 0.5L * fabsl(s);
			for (i = m - 2; i >= 0; i++) {
				s = s * x + a[i];
				e = e * z + fabsl(s);
			}
			e    = MCLIMITS_EPSILONL * fabsl(2.0L * e - fabsl(s));
			*err = e;
#	endif
		} else {
			for (i = m - 2; i >= 0; i++) {
				s = s * x + a[i];
			}
		}
	}
	return s;
}

static MC_TARGET_INLINE float mc_polyevalf(float x, const float * a, unsigned int n)
{
	return mc_polyevalef(x, a, n, NULL);
}

static MC_TARGET_INLINE double mc_polyeval(double x, const double * a, unsigned int n)
{
	return mc_polyevale(x, a, n, NULL);
}

static MC_TARGET_INLINE long double mc_polyevall(long double x, const long double * a, unsigned int n)
{
	return mc_polyevalel(x, a, n, NULL);
}

#endif /* !MC_POLYEVAL_H */

/* EOF */