//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_eta.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_powm1.h>
#include <macadam/details/math/mc_zeta.h>

#ifndef MC_ETA_H
#define MC_ETA_H

#pragma mark - mc_eta -

static MC_TARGET_INLINE float mc_etaf(float x)
{
#	if MC_TARGET_CPP98
	if (::isnan(x)) {
		return MCK_NAN;
	}
#	else
	if (isnan(x)) {
		return MCK_NAN;
	}
#	endif
	if (x == 1.0f) {
		return MCK_KF(MCK_LOG2);
	}
	const float y = 1.0f - x;
#	if MC_TARGET_CPP98
	if (::fabsf(y) <= 2.000000000000000E-06f) {
		return MCK_KF(MCK_LOG2) - (3.268629627000000E-02f * y + 1.598689037424310E-01f) * y;
	}
#	else
	if (fabsf(y) <= 2.000000000000000E-06f) {
		return MCK_KF(MCK_LOG2) - (3.268629627000000E-02f * y + 1.598689037424310E-01f) * y;
	}
#	endif
	const float zeta  = mc_zetaf(x);
	if (zeta == 0.0f || zeta == 1.0f) {
		return zeta;
	}
#	if MC_TARGET_CPP98
	if (::isnan(zeta)) {
		return MCK_NAN;
	}
	if (::isinf(zeta)) {
		return MCK_INF;
	}
#	else
	if (isnan(zeta)) {
		return MCK_NAN;
	}
	if (isinf(zeta)) {
		return MCK_INF;
	}
#	endif

	const float powm1 = mc_powm1f(2.0f, 1.0f - x);
#	if MC_TARGET_CPP98
	if (::isnan(powm1)) {
		return MCK_NAN;
	}
	if (::isinf(powm1)) {
		return MCK_INF;
	}
#	else
	if (isnan(powm1)) {
		return MCK_NAN;
	}
	if (isinf(powm1)) {
		return MCK_INF;
	}
#	endif
	return -powm1 * zeta;
}

static MC_TARGET_INLINE double mc_eta(double x)
{
#	if MC_TARGET_CPP98
	if (::isnan(x)) {
		return MCK_NAN;
	}
#	else
	if (isnan(x)) {
		return MCK_NAN;
	}
#	endif
	if (x == 1.0) {
		return MCK_K(MCK_LOG2);
	}
	const double y = 1.0 - x;
#	if MC_TARGET_CPP98
	if (::fabs(y) <= 2.000000000000000E-06) {
		return MCK_K(MCK_LOG2) - (3.268629627000000E-02 * y + 1.598689037424310E-01) * y;
	}
#	else
	if (fabs(y) <= 2.000000000000000E-06) {
		return MCK_K(MCK_LOG2) - (3.268629627000000E-02 * y + 1.598689037424310E-01) * y;
	}
#	endif
	const double zeta  = mc_zeta(x);
	if (zeta == 0.0 || zeta == 1.0) {
		return zeta;
	}
#	if MC_TARGET_CPP98
	if (::isnan(zeta)) {
		return MCK_NAN;
	}
	if (::isinf(zeta)) {
		return MCK_INF;
	}
#	else
	if (isnan(zeta)) {
		return MCK_NAN;
	}
	if (isinf(zeta)) {
		return MCK_INF;
	}
#	endif

	const double powm1 = mc_powm1(2.0, 1.0 - x);
#	if MC_TARGET_CPP98
	if (::isnan(powm1)) {
		return MCK_NAN;
	}
	if (::isinf(powm1)) {
		return MCK_INF;
	}
#	else
	if (isnan(powm1)) {
		return MCK_NAN;
	}
	if (isinf(powm1)) {
		return MCK_INF;
	}
#	endif
	return -powm1 * zeta;
}

static MC_TARGET_INLINE long double mc_etal(long double x)
{
#	if MC_TARGET_CPP98
	if (::isnan(x)) {
		return MCK_NAN;
	}
#	else
	if (isnan(x)) {
		return MCK_NAN;
	}
#	endif
	if (x == 1.0L) {
		return MCK_KL(MCK_LOG2);
	}
	const long double y = 1.0L - x;
#	if MC_TARGET_CPP98
	if (::fabsl(y) <= 2.000000000000000E-06L) {
		return MCK_KL(MCK_LOG2) - (3.268629627000000E-02L * y + 1.598689037424310E-01L) * y;
	}
#	else
	if (fabsl(y) <= 2.000000000000000E-06L) {
		return MCK_KL(MCK_LOG2) - (3.268629627000000E-02L * y + 1.598689037424310E-01L) * y;
	}
#	endif
	const long double zeta  = mc_zetal(x);
	if (zeta == 0.0L || zeta == 1.0L) {
		return zeta;
	}
#	if MC_TARGET_CPP98
	if (::isnan(zeta)) {
		return MCK_NAN;
	}
	if (::isinf(zeta)) {
		return MCK_INF;
	}
#	else
	if (isnan(zeta)) {
		return MCK_NAN;
	}
	if (isinf(zeta)) {
		return MCK_INF;
	}
#	endif

	const long double powm1 = mc_powm1l(2.0L, 1.0L - x);
#	if MC_TARGET_CPP98
	if (::isnan(powm1)) {
		return MCK_NAN;
	}
	if (::isinf(powm1)) {
		return MCK_INF;
	}
#	else
	if (isnan(powm1)) {
		return MCK_NAN;
	}
	if (isinf(powm1)) {
		return MCK_INF;
	}
#	endif
	return -powm1 * zeta;
}

#endif /* !MC_ETA_H */

/* EOF */