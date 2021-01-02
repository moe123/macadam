//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_lbeta.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_isinf.h>
#include <macadam/details/math/mc_isnan.h>
#include <macadam/details/math/mc_gamma.h>
#include <macadam/details/math/mc_lgamma.h>
#include <macadam/details/math/mc_log.h>

#ifndef MC_LBETA_H
#define MC_LBETA_H

#pragma mark - mc_lbeta -

MC_TARGET_FUNC float mc_lbetaf(float x, float y)
{
	float a, b, c, d;
	if (mc_isnan(x) || mc_isnan(y)) {
		return MCK_NAN;
	}
	if (mc_isinf(x) || mc_isinf(y)) {
		return MCK_INFP;
	}
	if (x <= 0.0f && y <= 0.0f) {
		return MCK_NAN;
	}
	if (x < 0.0f && y < 0.0f) {
		return MCK_NAN;
	}
	if (x == 0.0f || y == 0.0f) {
		return MCK_INFP;
	}
	if (x < y) {
		d = x;
		x = y;
		y = d;
	}
	d = x + y;
	c = mc_gammaf(d);
	if (!mc_isinf(c) && c < MCLIMITS_MAXF) {
		a = mc_gammaf(x);
		b = mc_gammaf(y);
		return mc_logf(a / (c / b));
	}
	a = mc_lgammaf(x);
	b = mc_lgammaf(y);
	c = mc_lgammaf(d);
	return a + b - c;
}

MC_TARGET_FUNC double mc_lbeta(double x, double y)
{
	double a, b, c, d;
	if (mc_isnan(x) || mc_isnan(y)) {
		return MCK_NAN;
	}
	if (mc_isinf(x) || mc_isinf(y)) {
		return MCK_INFP;
	}
	if (x <= 0.0 && y <= 0.0) {
		return MCK_NAN;
	}
	if (x < 0.0 && y < 0.0) {
		return MCK_NAN;
	}
	if (x == 0.0 || y == 0.0) {
		return MCK_INFP;
	}
	if (x < y) {
		d = x;
		x = y;
		y = d;
	}
	d = x + y;
	c = mc_gamma(d);
	if (!mc_isinf(c) && c < MCLIMITS_MAX) {
		a = mc_gamma(x);
		b = mc_gamma(y);
		return mc_log(a / (c / b));
	}
	a = mc_lgamma(x);
	b = mc_lgamma(y);
	c = mc_lgamma(d);
	return a + b - c;
}

MC_TARGET_FUNC long double mc_lbetal(long double x, long double y)
{
	long double a, b, c, d;
	if (mc_isnan(x) || mc_isnan(y)) {
		return MCK_NAN;
	}
	if (mc_isinf(x) || mc_isinf(y)) {
		return MCK_INFP;
	}
	if (x <= 0.0L && y <= 0.0L) {
		return MCK_NAN;
	}
	if (x < 0.0L && y < 0.0L) {
		return MCK_NAN;
	}
	if (x == 0.0L || y == 0.0L) {
		return MCK_INFP;
	}
	if (x < y) {
		d = x;
		x = y;
		y = d;
	}
	d = x + y;
	c = mc_gammal(d);
	if (!mc_isinf(c) && c < MCLIMITS_MAXL) {
		a = mc_gammal(x);
		b = mc_gammal(y);
		return mc_logl(a / (c / b));
	}
	a = mc_lgammal(x);
	b = mc_lgammal(y);
	c = mc_lgammal(d);
	return a + b - c;
}

#endif /* !MC_LBETA_H */

/* EOF */