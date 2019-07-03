//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_hermite_hn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_isinf.h>
#include <macadam/details/math/mc_isnan.h>
#include <macadam/details/math/mc_raise2.h>
#include <macadam/details/math/mc_raise3.h>
#include <macadam/details/math/mc_raise4.h>
#include <macadam/details/math/mc_raise5.h>
#include <macadam/details/math/mc_raise6.h>

#ifndef MC_HERMITE_HN_H
#define MC_HERMITE_HN_H

#pragma mark - mc_hermite_h1 -

static MC_TARGET_INLINE float mc_hermite_h1f(float x)
{
//!# Physicists' Hermite polynomial, degree 1.
	return 2.0f * x;
}

static MC_TARGET_INLINE double mc_hermite_h1(double x)
{
//!# Physicists' Hermite polynomial, degree 1.
	return 2.0 * x;
}

static MC_TARGET_INLINE long  double mc_hermite_h1l(long double x)
{
//!# Physicists' Hermite polynomial, degree 1.
	return 2.0L * x;
}

#pragma mark - mc_hermite_h2 -

static MC_TARGET_INLINE float mc_hermite_h2f(float x)
{
//!# Physicists' Hermite polynomial, degree 2.
	return (4.0f * mc_raise2f(x)) - 2.0f;
}

static MC_TARGET_INLINE double mc_hermite_h2(double x)
{
//!# Physicists' Hermite polynomial, degree 2.
	return (4.0 * mc_raise2(x)) - 2.0;
}

static MC_TARGET_INLINE long double mc_hermite_h2l(long double x)
{
//!# Physicists' Hermite polynomial, degree 2.
	return (4.0L * mc_raise2l(x)) - 2.0L;
}

#pragma mark - mc_hermite_h3 -

static MC_TARGET_INLINE float mc_hermite_h3f(float x)
{
//!# Physicists' Hermite polynomial, degree 3.
	return (8.0f * mc_raise3f(x)) - (12.0f * x);
}

static MC_TARGET_INLINE double mc_hermite_h3(double x)
{
//!# Physicists' Hermite polynomial, degree 3.
	return (8.0 * mc_raise3(x)) - (12.0 * x);
}

static MC_TARGET_INLINE long double mc_hermite_h3l(long double x)
{
//!# Physicists' Hermite polynomial, degree 3.
	return (8.0L * mc_raise3l(x)) - (12.0L * x);
}

#pragma mark - mc_hermite_h4 -

static MC_TARGET_INLINE float mc_hermite_h4f(float x)
{
//!# Physicists' Hermite polynomial, degree 4.
	return (16.0f * mc_raise4f(x)) - (48.0f * mc_raise2f(x)) + 12.0f;
}

static MC_TARGET_INLINE double mc_hermite_h4(double x)
{
//!# Physicists' Hermite polynomial, degree 4.
	return (16.0 * mc_raise4(x)) - (48.0 * mc_raise2(x)) + 12.0;
}

static MC_TARGET_INLINE long double mc_hermite_h4l(long double x)
{
//!# Physicists' Hermite polynomial, degree 4.
	return (16.0L * mc_raise4l(x)) - (48.0L * mc_raise2l(x)) + 12.0L;
}

#pragma mark - mc_hermite_h5 -

static MC_TARGET_INLINE float mc_hermite_h5f(float x)
{
//!# Physicists' Hermite polynomial, degree 5.
	return (120.0f * x) - (160.0f * mc_raise3f(x)) + (32.0f * mc_raise5f(x));
}

static MC_TARGET_INLINE double mc_hermite_h5(double x)
{
//!# Physicists' Hermite polynomial, degree 5.
	return (120.0 * x) - (160.0 * mc_raise3(x)) + (32.0 * mc_raise5(x));
}

static MC_TARGET_INLINE long double mc_hermite_h5l(long double x)
{
//!# Physicists' Hermite polynomial, degree 5.
	return (120.0L * x) - (160.0L * mc_raise3l(x)) + (32.0L * mc_raise5l(x));
}

#pragma mark - mc_hermite_h6 -

static MC_TARGET_INLINE float mc_hermite_h6f(float x)
{
//!# Physicists' Hermite polynomial, degree 6.
	return (64.0f * mc_raise6f(x)) - (480.0f * mc_raise4f(x)) + (720.0f * mc_raise2f(x)) - 120.0f;
}

static MC_TARGET_INLINE double mc_hermite_h6(double x)
{
//!# Physicists' Hermite polynomial, degree 6.
	return (64.0 * mc_raise6(x)) - (480.0 * mc_raise4(x)) + (720.0 * mc_raise2(x)) - 120.0;
}

static MC_TARGET_INLINE long double mc_hermite_h6l(long double x)
{
//!# Physicists' Hermite polynomial, degree 6.
	return (64.0L * mc_raise6l(x)) - (480.0L * mc_raise4l(x)) + (720.0L * mc_raise2l(x)) - 120.0L;
}

#pragma mark - mc_hermite_hn -

static MC_TARGET_INLINE float mc_hermite_hnf(unsigned int n, float x)
{
//!# NTH physicists' Hermite polynomial.
	float hi       = 0.0f;
	float h0       = 0.0f;
	float h1       = 0.0f;
	unsigned int i = 2;
	if (mc_isnan(x) || mc_isinf(x)) {
		return MCK_NAN;
	}
	if (n >= 1 && n < MCLIMITS_IMAX) {
		h0 = 1.0f;
		h1 = 2.0f * x;
		for (; i <= n; ++i) {
			hi = x * h1 - mc_cast(float, (i - 1)) * h0;
			h0 = h1;
			h1 = 2.0f * hi;
		}
	}
	return h1;
}

static MC_TARGET_INLINE double mc_hermite_hn(unsigned int n, double x)
{
//!# NTH physicists' Hermite polynomial.
	double hi      = 0.0;
	double h0      = 0.0;
	double h1      = 0.0;
	unsigned int i = 2;
	if (mc_isnan(x) || mc_isinf(x)) {
		return MCK_NAN;
	}
	if (n >= 1 && n < MCLIMITS_IMAX) {
		h0 = 1.0;
		h1 = 2.0 * x;
		for (; i <= n; ++i) {
			hi = x * h1 - mc_cast(double, (i - 1)) * h0;
			h0 = h1;
			h1 = 2.0 * hi;
		}
	}
	return h1;
}

static MC_TARGET_INLINE long double mc_hermite_hnl(unsigned int n, long double x)
{
//!# NTH physicists' Hermite polynomial.
	long double hi = 0.0L;
	long double h0 = 0.0L;
	long double h1 = 0.0L;
	unsigned int i = 2;
	if (mc_isnan(x) || mc_isinf(x)) {
		return MCK_NAN;
	}
	if (n >= 1 && n < MCLIMITS_IMAX) {
		h0 = 1.0L;
		h1 = 2.0L * x;
		for (; i <= n; ++i) {
			hi = x * h1 - mc_cast(long double, (i - 1)) * h0;
			h0 = h1;
			h1 = 2.0L * hi;
		}
	}
	return h1;
}

#endif /* !MC_HERMITE_HN_H */

/* EOF */