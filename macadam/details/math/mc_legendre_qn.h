//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_legendre_qn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_trigonometry.h>
#include <macadam/details/math/mc_legendre_pn.h>
#include <macadam/details/math/mc_rsqr.h>
#include <macadam/details/math/mc_log1p.h>
#include <macadam/details/math/mc_log1m.h>

#ifndef MC_LEGENDRE_QN_H
#define MC_LEGENDRE_QN_H

#pragma mark - mc_legendre_q0 -

static MC_TARGET_INLINE float mc_legendre_q0f(float x)
{
//!# Legendre functions of the second kind, degree 0.
#	if MC_TARGET_CPP98
	 if (::fabsf(x) < 1.0f) {
		return ::atanhf(x);
	 }
#	else
	 if (fabsf(x) < 1.0f) {
		return atanhf(x);
	 }
#	endif
	return mc_acothf(x);
}

static MC_TARGET_INLINE double mc_legendre_q0(double x)
{
//!# Legendre functions of the second kind, degree 0.
#	if MC_TARGET_CPP98
	 if (::fabs(x) < 1.0) {
		return ::atanh(x);
	 }
#	else
	 if (fabs(x) < 1.0) {
		return atanh(x);
	 }
#	endif
	return mc_acoth(x);
}

static MC_TARGET_INLINE long double mc_legendre_q0l(long double x)
{
//!# Legendre functions of the second kind, degree 0.
#	if MC_TARGET_CPP98
	 if (::fabsl(x) < 1.0L) {
		return ::atanhl(x);
	 }
#	else
	 if (fabsl(x) < 1.0L) {
		return atanhl(x);
	 }
#	endif
	return mc_acothl(x);
}

#pragma mark - mc_legendre_q1 -

static MC_TARGET_INLINE float mc_legendre_q1f(float x)
{
//!# Legendre functions of the second kind, degree 1.
	float q1 = 0.0f;
	float w, y, f, s, k;
#	if MC_TARGET_CPP98
	if (::isnan(x) || ::isinf(x)) {
		return MCK_NAN;
	}
#	else
	if (isnan(x) || isinf(x)) {
		return MCK_NAN;
	}
#	endif
#	if MC_TARGET_CPP98
	w  = ::fabsf(x);
#	else
	w  = fabsf(x);
#	endif
	if (w < 1.0f) {
#	if MC_TARGET_CPP98
		q1 = ::atanhf(x) * x - 1.0f;
#	else
		q1 = atanhf(x) * x - 1.0f;
#	endif
	} else if (w < 2.0f) {
		q1 = 0.5f * mc_log1pf(2.0f / (w - 1.0f)) * w - 1.0f;
	} else {
		y = mc_rsqrf(x); w = 1.0f; f = 3.0f; s = 1.0f; k = 5.0f;
		do {
			f *= y;
			w  = f / k;
			s  = s + w;
			k += 2.0f;
		} while (w <= s * MCLIMITS_EPSILONF);
		q1 = (s * y) * MCK_KF(MCK_1_3);
	}
	return q1;
}

static MC_TARGET_INLINE double mc_legendre_q1(double x)
{
//!# Legendre functions of the second kind, degree 1.
	double q1 = 0.0;
	double w, y, f, s, k;
#	if MC_TARGET_CPP98
	if (::isnan(x) || ::isinf(x)) {
		return MCK_NAN;
	}
#	else
	if (isnan(x) || isinf(x)) {
		return MCK_NAN;
	}
#	endif
#	if MC_TARGET_CPP98
	w  = ::fabs(x);
#	else
	w  = fabs(x);
#	endif
	if (w < 1.0) {
#	if MC_TARGET_CPP98
		q1 = ::atanh(x) * x - 1.0;
#	else
		q1 = atanh(x) * x - 1.0;
#	endif
	} else if (w < 2.0) {
		q1 = 0.5f * mc_log1p(2.0 / (w - 1.0)) * w - 1.0;
	} else {
		y = mc_rsqr(x); w = 1.0; f = 3.0; s = 1.0; k = 5.0;
		do {
			f *= y;
			w  = f / k;
			s  = s + w;
			k += 2.0;
		} while (w <= s * MCLIMITS_EPSILON);
		q1 = (s * y) * MCK_K(MCK_1_3);
	}
	return q1;
}

static MC_TARGET_INLINE long double mc_legendre_q1l(long double x)
{
//!# Legendre functions of the second kind, degree 1.
	long double q1 = 0.0L;
	long double w, y, f, s, k;
#	if MC_TARGET_CPP98
	if (::isnan(x) || ::isinf(x)) {
		return MCK_NAN;
	}
#	else
	if (isnan(x) || isinf(x)) {
		return MCK_NAN;
	}
#	endif
#	if MC_TARGET_CPP98
	w  = ::fabsl(x);
#	else
	w  = fabsl(x);
#	endif
	if (w < 1.0L) {
#	if MC_TARGET_CPP98
		q1 = ::atanhl(x) * x - 1.0L;
#	else
		q1 = atanhl(x) * x - 1.0L;
#	endif
	} else if (w < 2.0L) {
		q1 = 0.5f * mc_log1pl(2.0L / (w - 1.0L)) * w - 1.0L;
	} else {
		y = mc_rsqrl(x); w = 1.0L; f = 3.0L; s = 1.0L; k = 5.0L;
		do {
			f *= y;
			w  = f / k;
			s  = s + w;
			k += 2.0L;
		} while (w <= s * MCLIMITS_EPSILONL);
		q1 = (s * y) * MCK_KL(MCK_1_3);
	}
	return q1;
}

#pragma mark - mc_legendre_q2 -

static MC_TARGET_INLINE float mc_legendre_q2f(float x)
{
//!# Legendre functions of the second kind, degree 2.
	const float p2 = mc_legendre_pnf(x, 2);
	const float q0 = mc_legendre_q0f(x);
	return p2 * q0 - (MCK_KF(MCK_3_2) * x);
}

static MC_TARGET_INLINE double mc_legendre_q2(double x)
{
//!# Legendre functions of the second kind, degree 2.
	const double p2 = mc_legendre_pn(x, 2);
	const double q0 = mc_legendre_q0(x);
	return p2 * q0 - (MCK_K(MCK_3_2) * x);
}

static MC_TARGET_INLINE long double mc_legendre_q2l(long double x)
{
//!# Legendre functions of the second kind, degree 2.
	const long double p2 = mc_legendre_pnl(x, 2);
	const long double q0 = mc_legendre_q0l(x);
	return p2 * q0 - (MCK_KL(MCK_3_2) * x);
}

#pragma mark - mc_legendre_q3 -

static MC_TARGET_INLINE float mc_legendre_q3f(float x)
{
//!# Legendre functions of the second kind, degree 3.
	const float p3 = mc_legendre_pnf(x, 3);
	const float q0 = mc_legendre_q0f(x);
	return p3 * q0 - (MCK_KF(MCK_5_2) * mc_sqrf(x)) + MCK_KF(MCK_2_3);
}

static MC_TARGET_INLINE double mc_legendre_q3(double x)
{
//!# Legendre functions of the second kind, degree 3.
	const double p3 = mc_legendre_pn(x, 3);
	const double q0 = mc_legendre_q0(x);
	return p3 * q0 - (MCK_K(MCK_5_2) * mc_sqr(x)) + MCK_K(MCK_2_3);
}

static MC_TARGET_INLINE long double mc_legendre_q3l(long double x)
{
//!# Legendre functions of the second kind, degree 3.
	const long double p3 = mc_legendre_pnl(x, 3);
	const long double q0 = mc_legendre_q0l(x);
	return p3 * q0 - (MCK_KL(MCK_5_2) * mc_sqrl(x)) + MCK_KL(MCK_2_3);
}

#endif /* !MC_LEGENDRE_QN_H */

/* EOF */