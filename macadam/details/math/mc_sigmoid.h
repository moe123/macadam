//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_sigmoid.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_sqr.h>

#ifndef MC_SIGMOID_H
#define MC_SIGMOID_H

#pragma mark - mc_sigmoid -

static MC_TARGET_INLINE float mc_sigmoidf(float x)
{
	const float x0 = +46.0f;
	const float x1 = -23.0f;
#	if MC_TARGET_CPP98
	if (::fabsf(x) > x0) {
		if (x > 0.0f) {
			return 1.0f;
		}
		return ::expf(x);
	}
	if (x < x1) {
		x = ::expf(x);
		return x  - mc_sqrf(x);
	}
	return 1.0f / (::expf(-x) + 1.0f);
#	else
	if (fabsf(x) > x0) {
		if (x > 0.0f) {
			return 1.0f;
		}
		return expf(x);
	}
	if (x < x1) {
		x = expf(x);
		return x  - mc_sqrf(x);
	}
	return 1.0f / (expf(-x) + 1.0f);
#	endif
}

static MC_TARGET_INLINE double mc_sigmoid(double x)
{
	const double x0 = +46.0;
	const double x1 = -23.0;
#	if MC_TARGET_CPP98
	if (::fabs(x) > x0) {
		if (x > 0.0) {
			return 1.0;
		}
		return ::exp(x);
	}
	if (x < x1) {
		x = ::exp(x);
		return x  - mc_sqr(x);
	}
	return 1.0 / (::exp(-x) + 1.0);
#	else
	if (fabs(x) > x0) {
		if (x > 0.0) {
			return 1.0;
		}
		return exp(x);
	}
	if (x < x1) {
		x = exp(x);
		return x  - mc_sqr(x);
	}
	return 1.0 / (exp(-x) + 1.0);
#	endif
}

static MC_TARGET_INLINE long double mc_sigmoidl(long double x)
{
	const long double x0 = +46.0;
	const long double x1 = -23.0;
#	if MC_TARGET_CPP98
	if (::fabsl(x) > x0) {
		if (x > 0.0L) {
			return 1.0L;
		}
		return ::expl(x);
	}
	if (x < x1) {
		x = ::expl(x);
		return x  - mc_sqrl(x);
	}
	return 1.0L / (::expl(-x) + 1.0L);
#	else
	if (fabsl(x) > x0) {
		if (x > 0.0) {
			return 1.0;
		}
		return expl(x);
	}
	if (x < x1) {
		x = expl(x);
		return x  - mc_sqrl(x);
	}
	return 1.0L / (expl(-x) + 1.0L);
#	endif
}

#endif /* !MC_SIGMOID_H */

/* EOF */