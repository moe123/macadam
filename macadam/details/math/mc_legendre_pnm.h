//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_legendre_pnm.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_isinf.h>
#include <macadam/details/math/mc_isnan.h>
#include <macadam/details/math/mc_legendre_pn.h>
#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_factorial.h>
#include <macadam/details/math/mc_gamma.h>
#include <macadam/details/math/mc_sqrt.h>

#ifndef MC_LEGENDRE_PNM_H
#define MC_LEGENDRE_PNM_H

#pragma mark - mc_legendre_pnm -

MC_TARGET_FUNC float mc_legendre_pnmf(int n, int m, float x)
{
//!# Associated Legendre polynomials or functions of degree n and order m.
	float p0                = 1.0f;
	float p1                = 0.0f;
	float pn                = 0.0f;
	float z                 = 0.0f;
	float w                 = 1.0f;
	int i                   = 1;
	int k                   = 0;
	const int max_factorial = 35;
	if (mc_isnan(x) || mc_isinf(x)) {
		return MCK_NAN;
	}
	if (mc_fabsf(x) > 1.0f) {
		return MCK_NAN;
	}
	if (n < 0) {
		n = -n - 1;
	}
	if (m < 0) {
		k = n + m;
		if (!(k < 0)) { 
			p1 = mc_legendre_pnmf(n, -m, x);
			n  = n - m;
			p0 = (n < max_factorial
				? (mc_factorialf(mc_cast(unsigned int, k)) / mc_factorialf(mc_cast(unsigned int, n)))
				: (mc_gammaf(mc_cast(float, (k + 1))) / mc_gammaf(mc_cast(float, (n + 1))))
			);
			p1 = ((!((m & 1) == 0) && mc_fabsf(x) <= 1.0f)
				? (-p1 * p0)
				: (+p1 * p0)
			);
		}
		return p1;
	} else if (m > n) { 
		return p1;
	} else if (m == 0) {
		return mc_legendre_pnf(mc_cast(unsigned int, n), x);
	}
	if (m > 0) {
		z = mc_sqrtf(1.0f - x * x);
		w = 1.0f;
		for (; i <= m; i++) {
			p0 = p0 * -1.0f * w * z;
			w  = w + 2.0f;
		}
	}
	if (n == m) {
		return p0;
	}
	p1 = x * (2.0f * m + 1.0f) * p0;
	if (n == m + 1) {
		return p1;
	}
	for (i = m + 2; i <= n; i++) {
		pn = (x * (2.0f * mc_cast(float, i) - 1.0f) * p1 - (mc_cast(float, i) + mc_cast(float, m) - 1.0f) * p0) / mc_cast(float, (i - m));
		p0 = p1;
		p1 = pn;
	}
	return p1;
}

MC_TARGET_FUNC double mc_legendre_pnm(int n, int m, double x)
{
//!# Associated Legendre polynomials or functions of degree n and order m.
	double p0               = 1.0;
	double p1               = 0.0;
	double pn               = 0.0;
	double z                = 0.0;
	double w                = 1.0;
	int i                   = 1;
	int k                   = 0;
	const int max_factorial = 171;
	if (mc_isnan(x) || mc_isinf(x)) {
		return MCK_NAN;
	}
	if (mc_fabs(x) > 1.0) {
		return MCK_NAN;
	}
	if (n < 0) {
		n = -n - 1;
	}
	if (m < 0) {
		k = n + m;
		if (!(k < 0)) { 
			p1 = mc_legendre_pnm(n, -m, x);
			n  = n - m;
			p0 = (n < max_factorial
				? (mc_factorial(mc_cast(unsigned int, k)) / mc_factorial(mc_cast(unsigned int, n)))
				: (mc_gamma(mc_cast(double, (k + 1))) / mc_gamma(mc_cast(double, (n + 1))))
			);
			p1 = ((!((m & 1) == 0) && mc_fabs(x) <= 1.0)
				? (-p1 * p0)
				: (+p1 * p0)
			);
		}
		return p1;
	} else if (m > n) { 
		return p1;
	} else if (m == 0) {
		return mc_legendre_pn(mc_cast(unsigned int, n), x);
	}
	if (m > 0) {
		z = mc_sqrt(1.0 - x * x);
		w = 1.0;
		for (; i <= m; i++) {
			p0 = p0 * -1.0 * w * z;
			w  = w + 2.0;
		}
	}
	if (n == m) {
		return p0;
	}
	p1 = x * (2.0 * m + 1.0) * p0;
	if (n == m + 1) {
		return p1;
	}
	for (i = m + 2; i <= n; i++) {
		pn = (x * (2.0 * mc_cast(double, i) - 1.0) * p1 - (mc_cast(double, i) + mc_cast(double, m) - 1.0) * p0) / mc_cast(double, (i - m));
		p0 = p1;
		p1 = pn;
	}
	return p1;
}

MC_TARGET_FUNC long double mc_legendre_pnml(int n, int m, long double x)
{
//!# Associated Legendre polynomials or functions of degree n and order m.
	long double p0          = 1.0L;
	long double p1          = 0.0L;
	long double pn          = 0.0L;
	long double z           = 0.0L;
	long double w           = 1.0L;
	int i                   = 1;
	int k                   = 0;
#	if MC_TARGET_MSVC_CPP
	const int max_factorial = 171;
#	else
	const int max_factorial = 1755;
#	endif
	if (mc_isnan(x) || mc_isinf(x)) {
		return MCK_NAN;
	}
	if (mc_fabsl(x) > 1.0L) {
		return MCK_NAN;
	}
	if (n < 0) {
		n = -n - 1;
	}
	if (m < 0) {
		k = n + m;
		if (!(k < 0)) { 
			p1 = mc_legendre_pnml(n, -m, x);
			n  = n - m;
			p0 = (n < max_factorial
				? (mc_factoriall(mc_cast(unsigned int, k)) / mc_factoriall(mc_cast(unsigned int, n)))
				: (mc_gammal(mc_cast(long double, (k + 1))) / mc_gammal(mc_cast(long double, (n + 1))))
			);
			p1 = ((!((m & 1) == 0) && mc_fabsl(x) <= 1.0L)
				? (-p1 * p0)
				: (+p1 * p0)
			);
		}
		return p1;
	} else if (m > n) { 
		return p1;
	} else if (m == 0) {
		return mc_legendre_pnl(mc_cast(unsigned int, n), x);
	}
	if (m > 0) {
		z = mc_sqrtl(1.0L - x * x);
		w = 1.0L;
		for (; i <= m; i++) {
			p0 = p0 * -1.0L * w * z;
			w  = w + 2.0L;
		}
	}
	if (n == m) {
		return p0;
	}
	p1 = x * (2.0L * m + 1.0L) * p0;
	if (n == m + 1) {
		return p1;
	}
	for (i = m + 2; i <= n; i++) {
		pn = (x * (2.0L * mc_cast(long double, i) - 1.0L) * p1 - (mc_cast(long double, i) + mc_cast(long double, m) - 1.0L) * p0) / mc_cast(long double, (i - m));
		p0 = p1;
		p1 = pn;
	}
	return p1;
}

#endif /* !MC_LEGENDRE_PNM_H */

/* EOF */