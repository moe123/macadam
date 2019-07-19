//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_legendre_qn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_acoth.h>
#include <macadam/details/math/mc_atanh.h>
#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_isinf.h>
#include <macadam/details/math/mc_isnan.h>
#include <macadam/details/math/mc_legendre_pn.h>
#include <macadam/details/math/mc_log1p.h>
#include <macadam/details/math/mc_raise2.h>
#include <macadam/details/math/mc_raise3.h>
#include <macadam/details/math/mc_raise4.h>
#include <macadam/details/math/mc_rsqr.h>

#ifndef MC_LEGENDRE_QN_H
#define MC_LEGENDRE_QN_H

#pragma mark - mc_legendre_q0 -

MC_TARGET_PROC float mc_legendre_q0f(float x)
{
//!# Legendre functions of the second kind, degree 0.
	if (mc_fabsf(x) < 1.0f) {
		return mc_atanhf(x);
	}
	return mc_acothf(x);
}

MC_TARGET_PROC double mc_legendre_q0(double x)
{
//!# Legendre functions of the second kind, degree 0.
	if (mc_fabs(x) < 1.0) {
		return mc_atanh(x);
	}
	return mc_acoth(x);
}

MC_TARGET_PROC long double mc_legendre_q0l(long double x)
{
//!# Legendre functions of the second kind, degree 0.
	if (mc_fabsl(x) < 1.0L) {
		return mc_atanhl(x);
	}
	return mc_acothl(x);
}

#pragma mark - mc_legendre_q1 -

MC_TARGET_PROC float mc_legendre_q1f(float x)
{
//!# Legendre functions of the second kind, degree 1.
	float q1 = 0.0f;
	float w, y, f, s, k;

	if (mc_isnan(x) || mc_isinf(x)) {
		return MCK_NAN;
	}
	w = mc_fabsf(x);
	if (w < 1.0f) {
		q1 = mc_atanhf(x) * x - 1.0f;
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

MC_TARGET_PROC double mc_legendre_q1(double x)
{
//!# Legendre functions of the second kind, degree 1.
	double q1 = 0.0;
	double w, y, f, s, k;

	if (mc_isnan(x) || mc_isinf(x)) {
		return MCK_NAN;
	}
	w = mc_fabs(x);
	if (w < 1.0) {
		q1 = mc_atanh(x) * x - 1.0;
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

MC_TARGET_PROC long double mc_legendre_q1l(long double x)
{
//!# Legendre functions of the second kind, degree 1.
	long double q1 = 0.0L;
	long double w, y, f, s, k;

	if (mc_isnan(x) || mc_isinf(x)) {
		return MCK_NAN;
	}
	w = mc_fabsl(x);
	if (w < 1.0L) {
		q1 = mc_atanhl(x) * x - 1.0L;
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

MC_TARGET_PROC float mc_legendre_q2f(float x)
{
//!# Legendre functions of the second kind, degree 2.
	const float p2 = mc_legendre_p2f(x);
	const float q0 = mc_legendre_q0f(x);
	return p2 * q0 - (MCK_KF(MCK_3_2) * x);
}

MC_TARGET_PROC double mc_legendre_q2(double x)
{
//!# Legendre functions of the second kind, degree 2.
	const double p2 = mc_legendre_p2(x);
	const double q0 = mc_legendre_q0(x);
	return p2 * q0 - (MCK_K(MCK_3_2) * x);
}

MC_TARGET_PROC long double mc_legendre_q2l(long double x)
{
//!# Legendre functions of the second kind, degree 2.
	const long double p2 = mc_legendre_p2l(x);
	const long double q0 = mc_legendre_q0l(x);
	return p2 * q0 - (MCK_KL(MCK_3_2) * x);
}

#pragma mark - mc_legendre_q3 -

MC_TARGET_PROC float mc_legendre_q3f(float x)
{
//!# Legendre functions of the second kind, degree 3.
	const float p3 = mc_legendre_p3f(x);
	const float q0 = mc_legendre_q0f(x);
	return p3 * q0 - (MCK_KF(MCK_5_2) * mc_raise2f(x)) + MCK_KF(MCK_2_3);
}

MC_TARGET_PROC double mc_legendre_q3(double x)
{
//!# Legendre functions of the second kind, degree 3.
	const double p3 = mc_legendre_p3(x);
	const double q0 = mc_legendre_q0(x);
	return p3 * q0 - (MCK_K(MCK_5_2) * mc_raise2(x)) + MCK_K(MCK_2_3);
}

MC_TARGET_PROC long double mc_legendre_q3l(long double x)
{
//!# Legendre functions of the second kind, degree 3.
	const long double p3 = mc_legendre_p3l(x);
	const long double q0 = mc_legendre_q0l(x);
	return p3 * q0 - (MCK_KL(MCK_5_2) * mc_raise2l(x)) + MCK_KL(MCK_2_3);
}

#pragma mark - mc_legendre_q4 -

MC_TARGET_PROC float mc_legendre_q4f(float x)
{
//!# Legendre functions of the second kind, degree 4.
	const float p4 = mc_legendre_p4f(x);
	const float q0 = mc_legendre_q0f(x);
	return p4 * q0 - (MCK_KF(MCK_35_8) * mc_raise3f(x)) + (MCK_KF(MCK_55_24) * x);
}

MC_TARGET_PROC double mc_legendre_q4(double x)
{
//!# Legendre functions of the second kind, degree 4.
	const double p4 = mc_legendre_p4(x);
	const double q0 = mc_legendre_q0(x);
	return p4 * q0 - (MCK_K(MCK_35_8) * mc_raise3(x)) + (MCK_K(MCK_55_24) * x);
}

MC_TARGET_PROC long double mc_legendre_q4l(long double x)
{
//!# Legendre functions of the second kind, degree 4.
	const long double p4 = mc_legendre_p4l(x);
	const long double q0 = mc_legendre_q0l(x);
	return p4 * q0 - (MCK_KL(MCK_35_8) * mc_raise3l(x)) + (MCK_KL(MCK_55_24) * x);
}

#pragma mark - mc_legendre_q5 -

MC_TARGET_PROC float mc_legendre_q5f(float x)
{
//!# Legendre functions of the second kind, degree 5.
	const float p5 = mc_legendre_p5f(x);
	const float q0 = mc_legendre_q0f(x);
	return p5 * q0 - (MCK_KF(MCK_63_8) * mc_raise4f(x)) + (MCK_KF(MCK_49_8) * mc_raise2f(x)) - MCK_KF(MCK_8_15);
}

MC_TARGET_PROC double mc_legendre_q5(double x)
{
//!# Legendre functions of the second kind, degree 5.
	const double p5 = mc_legendre_p5(x);
	const double q0 = mc_legendre_q0(x);
	return p5 * q0 - (MCK_K(MCK_63_8) * mc_raise4(x)) + (MCK_K(MCK_49_8) * mc_raise2(x)) - MCK_K(MCK_8_15);
}

MC_TARGET_PROC long double mc_legendre_q5l(long double x)
{
//!# Legendre functions of the second kind, degree 5.
	const long double p5 = mc_legendre_p5l(x);
	const long double q0 = mc_legendre_q0l(x);
	return p5 * q0 - (MCK_KL(MCK_63_8) * mc_raise4l(x)) + (MCK_KL(MCK_49_8) * mc_raise2l(x)) - MCK_KL(MCK_8_15);
}

#endif /* !MC_LEGENDRE_QN_H */

/* EOF */