//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_hypotq.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_sqrt.h>

#ifndef MC_HYPOTQ_H
#define MC_HYPOTQ_H

#pragma mark - mc_hypotq -

static MC_TARGET_INLINE float mc_hypotqf(float x, float y)
{
	float a = mc_fabsf(x);
	float b = mc_fabsf(y);
	float c = 0.0f;
	if (a > b) {
		c = b / a;
		c = a * mc_sqrtf(1.0f + c * c);
	} else if (b > 0.0f) {
		c = a / b;
		c = b * mc_sqrtf(1.0f + c * c);
	}
	return c;
}

static MC_TARGET_INLINE double mc_hypotq(double x, double y)
{
	double a = mc_fabs(x);
	double b = mc_fabs(y);
	double c = 0.0;
	if (a > b) {
		c = b / a;
		c = a * mc_sqrt(1.0 + c * c);
	} else if (b > 0.0) {
		c = a / b;
		c = b * mc_sqrt(1.0 + c * c);
	}
	return c;
}

static MC_TARGET_INLINE double mc_hypotql(long double x, long double y)
{
	long double a = mc_fabsl(x);
	long double b = mc_fabsl(y);
	long double c = 0.0;
	if (a > b) {
		c = b / a;
		c = a * mc_sqrtl(1.0L + c * c);
	} else if (b > 0.0L) {
		c = a / b;
		c = b * mc_sqrtl(1.0L + c * c);
	}
	return c;
}

#endif /* !MC_HYPOTQ_H */

/* EOF */