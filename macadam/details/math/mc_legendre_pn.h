//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_legendre_pn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_isinf.h>
#include <macadam/details/math/mc_isnan.h>
#include <macadam/details/math/mc_raise2.h>
#include <macadam/details/math/mc_raise3.h>
#include <macadam/details/math/mc_raise4.h>
#include <macadam/details/math/mc_raise5.h>

#ifndef MC_LEGENDRE_PN_H
#define MC_LEGENDRE_PN_H

#pragma mark - mc_legendre_p0 -

MC_TARGET_PROC float mc_legendre_p0f(float x)
{
	x = 1.0f;
	return x;
}

MC_TARGET_PROC double mc_legendre_p0(double x)
{
	x = 1.0;
	return x;
}

MC_TARGET_PROC long double mc_legendre_p0l(long double x)
{
	x = 1.0L;
	return x;
}

#pragma mark - mc_legendre_p1 -

MC_TARGET_PROC float mc_legendre_p1f(float x)
{
	return x;
}

MC_TARGET_PROC double mc_legendre_p1(double x)
{
	return x;
}

MC_TARGET_PROC long double mc_legendre_p1l(long double x)
{
	return x;
}

#pragma mark - mc_legendre_p2 -

MC_TARGET_PROC float mc_legendre_p2f(float x)
{
	return 1.5f * mc_raise2f(x) - 0.5f;
}

MC_TARGET_PROC double mc_legendre_p2(double x)
{
	return 1.5 * mc_raise2(x) - 0.5;
}

MC_TARGET_PROC long double mc_legendre_p2l(long double x)
{
	return 1.5L * mc_raise2l(x) - 0.5L;
}

#pragma mark - mc_legendre_p3 -

MC_TARGET_PROC float mc_legendre_p3f(float x)
{
	return 0.5f * ((5.0f * mc_raise3f(x)) - (3.0f * x));
}

MC_TARGET_PROC double mc_legendre_p3(double x)
{
	return 0.5 * ((5.0 * mc_raise3(x)) - (3.0 * x));
}

MC_TARGET_PROC long double mc_legendre_p3l(long double x)
{
	return 0.5L * ((5.0L * mc_raise3l(x)) - (3.0L * x));
}

#pragma mark - mc_legendre_p4 -

MC_TARGET_PROC float mc_legendre_p4f(float x)
{
	return 0.125f * (((35.0f * mc_raise4f(x)) - (30.0f * mc_raise2f(x))) + 3.0f);
}

MC_TARGET_PROC double mc_legendre_p4(double x)
{
	return 0.125 * (((35.0 * mc_raise4(x)) - (30.0 * mc_raise2(x))) + 3.0);
}

MC_TARGET_PROC long double mc_legendre_p4l(long double x)
{
	return 0.125L * (((35.0L * mc_raise4l(x)) - (30.0L * mc_raise2l(x))) + 3.0L);
}

#pragma mark - mc_legendre_p5 -

MC_TARGET_PROC float mc_legendre_p5f(float x)
{
	return 0.125f * (((63.0f * mc_raise5f(x)) - (70.0f * mc_raise3f(x))) + (15.0f * x));
}

MC_TARGET_PROC double mc_legendre_p5(double x)
{
	return 0.125 * (((63.0 * mc_raise5(x)) - (70.0 * mc_raise3(x))) + (15.0 * x));
}

MC_TARGET_PROC long double mc_legendre_p5l(long double x)
{
	return 0.125L * (((63.0L * mc_raise5l(x)) - (70.0L * mc_raise3l(x))) + (15.0L * x));
}

#pragma mark - mc_legendre_p6 -

MC_TARGET_PROC float mc_legendre_p6f(float x)
{
	return 0.0625f * (((231.0f * mc_raise6f(x)) - (315.0f * mc_raise4f(x)) + (105.0f * mc_raise2f(x))) - 5.0f);
}

MC_TARGET_PROC double mc_legendre_p6(double x)
{
	return 0.0625 * (((231.0 * mc_raise6(x)) - (315.0 * mc_raise4(x)) + (105.0 * mc_raise2(x))) - 5.0);
}

MC_TARGET_PROC long double mc_legendre_p6l(long double x)
{
	return 0.0625L * (((231.0L * mc_raise6l(x)) - (315.0L * mc_raise4l(x)) + (105.0L * mc_raise2l(x))) - 5.0L);
}

#pragma mark - mc_legendre_pn -

MC_TARGET_FUNC float mc_legendre_pnf(unsigned int n, float x)
{
//!# Legendre polynomials or functions.
	float pi       = 0.0f;
	float p0       = 0.0f;
	float p1       = 0.0f;
	unsigned int i = 2;
	if (mc_isnan(x) || mc_isinf(x)) {
		return MCK_NAN;
	}
	if (x == 1.0f || x == -1.0f) {
		p1 = 1.0f;
		if ((x < 0.0f) && ((n % 2) != 0)) {
			p1 = -(p1);
		}
	} else if (n >= 1 && n < MCLIMITS_IMAX) {
		if (n == 1) {
			p1 = x;
		} else if (n == 2) {
			p1 = mc_legendre_p2f(x);
		} else if ((x == 0.0f) && ((n % 2) != 0)) {
			p1 = 0.0f;
		} else {
			p0 = 1.0f;
			p1 = x;
			for (; i <= n; i++) {
				pi = ((2.0f * mc_cast(float, i) - 1.0f) * x * p1 - mc_cast(float, (i - 1)) * p0) / mc_cast(float, i);
				p0 = p1;
				p1 = pi;
			}
		}
	}
	return p1;
}

MC_TARGET_FUNC double mc_legendre_pn(unsigned int n, double x)
{
//!# Legendre polynomials or functions.
	double pi      = 0.0;
	double p0      = 0.0;
	double p1      = 0.0;
	unsigned int i = 2;
	if (mc_isnan(x) || mc_isinf(x)) {
		return MCK_NAN;
	}
	if (x == 1.0 || x == -1.0) {
		p1 = 1.0;
		if ((x < 0.0) && ((n % 2) != 0)) {
			p1 = -(p1);
		}
	} else if (n >= 1 && n < MCLIMITS_IMAX) {
		if (n == 1) {
			p1 = x;
		} else if (n == 2) {
			p1 = mc_legendre_p2(x);
		} else if ((x == 0.0) && ((n % 2) != 0)) {
			p1 = 0.0;
		} else {
			p0 = 1.0;
			p1 = x;
			for (; i <= n; i++) {
				pi = ((2.0 * mc_cast(double, i) - 1.0) * x * p1 - mc_cast(double, (i - 1)) * p0) / mc_cast(double, i);
				p0 = p1;
				p1 = pi;
			}
		}
	}
	return p1;
}

MC_TARGET_FUNC long double mc_legendre_pnl(unsigned int n, long double x)
{
//!# Legendre polynomials or functions.
	long double pi = 0.0L;
	long double p0 = 0.0L;
	long double p1 = 0.0L;
	unsigned int i = 2;
	if (mc_isnan(x) || mc_isinf(x)) {
		return MCK_NAN;
	}
	if (x == 1.0L || x == -1.0L) {
		p1 = 1.0L;
		if ((x < 0.0L) && ((n % 2) != 0)) {
			p1 = -(p1);
		}
	} else if (n >= 1 && n < MCLIMITS_IMAX) {
		if (n == 1) {
			p1 = x;
		} else if (n == 2) {
			p1 = mc_legendre_p2l(x);
		} else if ((x == 0.0L) && ((n % 2) != 0)) {
			p1 = 0.0L;
		} else {
			p0 = 1.0L;
			p1 = x;
			for (; i <= n; i++) {
				pi = ((2.0L * mc_cast(long double, i) - 1.0L) * x * p1 - mc_cast(long double, (i - 1)) * p0) / mc_cast(long double, i);
				p0 = p1;
				p1 = pi;
			}
		}
	}
	return p1;
}

#endif /* !MC_LEGENDRE_PN_H */

/* EOF */