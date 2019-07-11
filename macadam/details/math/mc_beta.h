//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_beta.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_exp.h>
#include <macadam/details/math/mc_isinf.h>
#include <macadam/details/math/mc_isnan.h>
#include <macadam/details/math/mc_lbeta.h>

#ifndef MC_BETA_H
#define MC_BETA_H

#pragma mark - mc_beta -

static MC_TARGET_INLINE
float mc_betaf(float x, float y)
{
	if (mc_isnan(x) || mc_isnan(y)) {
		return MCK_NAN;
	}
	if (mc_isinf(x) || mc_isinf(y)) {
		return MCK_NAN;
	}
	if (x == 0.0f && y == 0.0f) {
		return MCK_NAN;
	}
	if (x == 0.0f || y == 0.0f) {
		return MCK_INFP;
	}
	if (x == 1.0f) {
		return 1.0f / y;
	}
	if (y == 1.0f) {
		return 1.0f / x;
	}
	if (x < y) {
		const float w = x;
		x             = y;
		y             = w;
	}
	const float r = mc_lbetaf(x, y);
	if (mc_isnan(r)) {
		return MCK_NAN;
	}
	if (mc_isinf(r)) {
		return r;
	}
	return mc_expf(r);
}

static MC_TARGET_INLINE
double mc_beta(double x, double y)
{
	if (mc_isnan(x) || mc_isnan(y)) {
		return MCK_NAN;
	}
	if (mc_isinf(x) || mc_isinf(y)) {
		return MCK_NAN;
	}
	if (x == 0.0 && y == 0.0) {
		return MCK_NAN;
	}
	if (x == 0.0 || y == 0.0) {
		return MCK_INFP;
	}
	if (x == 1.0) {
		return 1.0 / y;
	}
	if (y == 1.0) {
		return 1.0 / x;
	}
	if (x < y) {
		const double w = x;
		x              = y;
		y              = w;
	}
	const double r = mc_lbeta(x, y);
	if (mc_isnan(r)) {
		return MCK_NAN;
	}
	if (mc_isinf(r)) {
		return r;
	}
	return mc_exp(r);
}

static MC_TARGET_INLINE
long double mc_betal(long double x, long double y)
{
	if (mc_isnan(x) || mc_isnan(y)) {
		return MCK_NAN;
	}
	if (mc_isinf(x) || mc_isinf(y)) {
		return MCK_NAN;
	}
	if (x == 0.0L && y == 0.0L) {
		return MCK_NAN;
	}
	if (x == 0.0L || y == 0.0L) {
		return MCK_INFP;
	}
	if (x == 1.0L) {
		return 1.0L / y;
	}
	if (y == 1.0L) {
		return 1.0L / x;
	}
	if (x < y) {
		const double w = x;
		x              = y;
		y              = w;
	}
	const long double r = mc_lbetal(x, y);
	if (mc_isnan(r)) {
		return MCK_NAN;
	}
	if (mc_isinf(r)) {
		return r;
	}
	return mc_expl(r);
}

#endif /* !MC_BETA_H */

/* EOF */