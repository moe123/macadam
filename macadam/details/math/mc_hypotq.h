//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_hypotq.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_HYPOTQ_H
#define MC_HYPOTQ_H

#pragma mark - mc_hypotq -

static MC_TARGET_INLINE float mc_hypotqf(float x, float y)
{
#	if MC_TARGET_CPP98
	float a = ::fabsf(x);
	float b = ::fabsf(y);
#	else
	float a = fabsf(x);
	float b = fabsf(y);
#	endif
	float c = 0.0f;
	if (a > b) {
		c = b / a;
#	if MC_TARGET_CPP98
		c = a * ::sqrtf(1.0f + c * c);
#	else
		c = a * sqrtf(1.0f + c * c);
#	endif
	} else if (b > 0.0f) {
		c = a / b;
#	if MC_TARGET_CPP98
		c = b * ::sqrtf(1.0f + c * c);
#	else
		c = b * sqrtf(1.0f + c * c);
#	endif
	}
	return c;
}

static MC_TARGET_INLINE double mc_hypotq(double x, double y)
{
#	if MC_TARGET_CPP98
	double a = ::fabs(x);
	double b = ::fabs(y);
#	else
	double a = fabs(x);
	double b = fabs(y);
#	endif
	double c = 0.0;
	if (a > b) {
		c = b / a;
#	if MC_TARGET_CPP98
		c = a * ::sqrt(1.0 + c * c);
#	else
		c = a * sqrt(1.0 + c * c);
#	endif
	} else if (b > 0.0) {
		c = a / b;
#	if MC_TARGET_CPP98
		c = b * ::sqrt(1.0 + c * c);
#	else
		c = b * sqrt(1.0 + c * c);
#	endif
	}
	return c;
}

static MC_TARGET_INLINE double mc_hypotql(long double x, long double y)
{
#	if MC_TARGET_CPP98
	long double a = ::fabsl(x);
	long double b = ::fabsl(y);
#	else
	long double a = fabsl(x);
	long double b = fabsl(y);
#	endif
	long double c = 0.0;
	if (a > b) {
		c = b / a;
#	if MC_TARGET_CPP98
		c = a * ::sqrtl(1.0L + c * c);
#	else
		c = a * sqrtl(1.0L + c * c);
#	endif
	} else if (b > 0.0L) {
		c = a / b;
#	if MC_TARGET_CPP98
		c = b * ::sqrtl(1.0L + c * c);
#	else
		c = b * sqrtl(1.0L + c * c);
#	endif
	}
	return c;
}

#endif /* !MC_HYPOTQ_H */

/* EOF */