//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_ibeta.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_lgamma.h>

#ifndef MC_BETAINC_H
#define MC_BETAINC_H

#pragma mark - mc_ibeta -

static MC_TARGET_INLINE float mc_ibetaf(float a, float b, float x)
{
	unsigned int i = 0, j;
	float g, k, w, f = 1.0f, c = 1.0f, d = 0;
	//#! NAN input results in NAN output.
#	if MC_TARGET_CPP98
	if (::isnan(a) || ::isnan(b) || ::isnan(x)) {
		return MCK_NAN;
	}
#	else
	if (isnan(a) || isnan(b) || isnan(x)) {
		return MCK_NAN;
	}
#	endif
	//#! x is out of bounds hence infinity is returned.
	if (x < 0 || x > 1) {
		return x < 0 ? -MCK_INF : MCK_INF;
	}
	if (x > (a + 1.0f) / (a + b + 2.0f)) {
		//#! The beta inverse is symetric.
		return (1.0f - mc_ibetaf(b, a, 1.0f - x));
	}
	//#! Computing delta-gamma + front integral.
#	if MC_TARGET_CPP98
	g = mc_lgammaf(a) + mc_lgammaf(b) - mc_lgammaf(a + b);
	k = ::expf(::logf(x) * a + ::logf(1.0f - x) * b - g) / a;
#	else
	g = mc_lgammaf(a) + mc_lgammaf(b) - mc_lgammaf(a + b);
	k = expf(logf(x) * a + logf(1.0f - x) * b - g) / a;
#	endif
	//#! Reducing, converging.
	for (; i < 256; ++i) {
		j = i / 2;
		if (i == 0) {
			//#! First iteration.
			w = 1.0f;
		} else if ((i % 2) == 0) {
			w = (j * (b - j) * x) / ((a + 2.0f * j - 1.0f) * (a + 2.0f * j));
		} else {
			w = -((a + j) * (a + b + j) * x) / ((a + 2.0f * j) * (a + 2.0f * j + 1));
		}
		d = 1.0f + w * d;
#	if MC_TARGET_CPP98
		if (::fabsf(d) < 1.0E-15f) {
			//#! Clipping to absolute min.
			d = 1.0E-15f;
		}
#	else
		if (fabsf(d) < 1.0E-15f) {
			//#! Clipping to absolute min.
			d = 1.0E-15f;
		}
#	endif
		d = 1.0f / d;
		c = 1.0f + w / c;
#	if MC_TARGET_CPP98
		if (::fabsf(c) < 1.0E-15f) {
			//#! Clipping to absolute min.
			c = 1.0E-15f;
		}
#	else
		if (fabsf(c) < 1.0E-15f) {
			//#! Clipping to absolute min.
			c = 1.0E-15f;
		}
#	endif
		f *= (c * d);
#	if MC_TARGET_CPP98
		if (::fabsf(1.0f - (c * d)) < 1.0E-5f) {
			return k * (f - 1.0f);
		}
#	else
		if (fabsf(1.0f - (c * d)) < 1.0E-5f) {
			return k * (f - 1.0f);
		}
#	endif
	}
	//#! Unable to reduce, returning towards infinity.
	return MCK_INF;
}

static MC_TARGET_INLINE double mc_ibeta(double a, double b, double x)
{
	unsigned int i = 0, j;
	double g, k, w, f = 1.0, c = 1.0, d = 0;
	//#! NAN input results in NAN output.
#	if MC_TARGET_CPP98
	if (::isnan(a) || ::isnan(b) || ::isnan(x)) {
		return MCK_NAN;
	}
#	else
	if (isnan(a) || isnan(b) || isnan(x)) {
		return MCK_NAN;
	}
#	endif
	//#! x is out of bounds hence infinity is returned.
	if (x < 0 || x > 1) {
		return x < 0 ? -MCK_INF : MCK_INF;
	}
	if (x > (a + 1.0) / (a + b + 2.0)) {
		//#! The beta inverse is symetric.
		return (1.0 - mc_ibeta(b, a, 1.0 - x));
	}
	//#! Computing delta-gamma + front integral.
#	if MC_TARGET_CPP98
	g = mc_lgamma(a) + mc_lgamma(b) - mc_lgamma(a + b);
	k = ::exp(::log(x) * a + ::log(1.0 - x) * b - g) / a;
#	else
	g = mc_lgamma(a) + mc_lgamma(b) - mc_lgamma(a + b);
	k = exp(log(x) * a + log(1.0 - x) * b - g) / a;
#	endif
	//#! Reducing, converging.
	for (; i < 256; ++i) {
		j = i / 2;
		if (i == 0) {
			//#! First iteration.
			w = 1.0;
		} else if ((i % 2) == 0) {
			w = (j * (b - j) * x) / ((a + 2.0 * j - 1.0) * (a + 2.0 * j));
		} else {
			w = -((a + j) * (a + b + j) * x) / ((a + 2.0 * j) * (a + 2.0 * j + 1));
		}
		d = 1.0 + w * d;
#	if MC_TARGET_CPP98
		if (::fabs(d) < 1.0E-30) {
			//#! Clipping to absolute min.
			d = 1.0E-30;
		}
#	else
		if (fabs(d) < 1.0E-30) {
			//#! Clipping to absolute min.
			d = 1.0E-30;
		}
#	endif
		d = 1.0 / d;
		c = 1.0 + w / c;
#	if MC_TARGET_CPP98
		if (::fabs(c) < 1.0E-30) {
			//#! Clipping to absolute min.
			c = 1.0E-30;
		}
#	else
		if (fabs(c) < 1.0E-30) {
			//#! Clipping to absolute min.
			c = 1.0E-30;
		}
#	endif
		f *= (c * d);
#	if MC_TARGET_CPP98
		if (::fabs(1.0 - (c * d)) < 1.0E-8) {
			return k * (f - 1.0);
		}
#	else
		if (fabs(1.0 - (c * d)) < 1.0E-8) {
			return k * (f - 1.0);
		}
#	endif
	}
	//#! Unable to reduce, returning towards infinity.
	return MCK_INF;
}

static MC_TARGET_INLINE long double mc_ibetal(long double a, long double b, long double x)
{
	unsigned int i = 0, j;
	long double g, k, w, f = 1.0L, c = 1.0L, d = 0;
	//#! NAN input results in NAN output.
#	if MC_TARGET_CPP98
	if (::isnan(a) || ::isnan(b) || ::isnan(x)) {
		return MCK_NAN;
	}
#	else
	if (isnan(a) || isnan(b) || isnan(x)) {
		return MCK_NAN;
	}
#	endif
	//#! x is out of bounds hence infinity is returned.
	if (x < 0 || x > 1) {
		return x < 0 ? -MCK_INF : MCK_INF;
	}
	if (x > (a + 1.0L) / (a + b + 2.0L)) {
		//#! The beta inverse is symetric.
		return (1.0L - mc_ibetal(b, a, 1.0L - x));
	}
	//#! Computing delta-gamma + front integral.
#	if MC_TARGET_CPP98
	g = mc_lgammal(a) + mc_lgammal(b) - mc_lgammal(a + b);
	k = ::expl(::logl(x) * a + ::logl(1.0L - x) * b - g) / a;
#	else
	g = mc_lgammal(a) + mc_lgammal(b) - mc_lgammal(a + b);
	k = expl(logl(x) * a + logl(1.0L - x) * b - g) / a;
#	endif
	//#! Reducing, converging.
	for (; i < 256; ++i) {
		j = i / 2;
		if (i == 0) {
			//#! First iteration.
			w = 1.0L;
		} else if ((i % 2) == 0) {
			w = (j * (b - j) * x) / ((a + 2.0L * j - 1.0L) * (a + 2.0L * j));
		} else {
			w = -((a + j) * (a + b + j) * x) / ((a + 2.0L * j) * (a + 2.0L * j + 1));
		}
		d = 1.0L + w * d;
#	if MC_TARGET_CPP98
		if (::fabsl(d) < 1.0E-30L) {
			//#! Clipping to absolute min.
			d = 1.0E-30L;
		}
#	else
		if (fabsl(d) < 1.0E-30L) {
			//#! Clipping to absolute min.
			d = 1.0E-30L;
		}
#	endif
		d = 1.0L / d;
		c = 1.0L + w / c;
#	if MC_TARGET_CPP98
		if (::fabsl(c) < 1.0E-30L) {
			//#! Clipping to absolute min.
			c = 1.0E-30L;
		}
#	else
		if (fabsl(c) < 1.0E-30L) {
			//#! Clipping to absolute min.
			c = 1.0E-30L;
		}
#	endif
		f *= (c * d);
#	if MC_TARGET_CPP98
		if (::fabsl(1.0L - (c * d)) < 1.0E-8L) {
			return k * (f - 1.0L);
		}
#	else
		if (fabsl(1.0L - (c * d)) < 1.0E-8L) {
			return k * (f - 1.0L);
		}
#	endif
	}
	//#! Unable to reduce, returning towards infinity.
	return MCK_INF;
}

#endif /* !MC_BETAINC_H */

/* EOF */