//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zpow.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_zexp.h>
#include <macadam/details/math/mc_zlog.h>
#include <macadam/details/math/mc_zmul.h>

#ifndef MC_ZPOW_H
#define MC_ZPOW_H

#pragma mark - mc_zpow -

MC_TARGET_PROC void mc_zpowf(float * c_r, float * c_i
	, const float a_r, const float a_i
	, const float b_r, const float b_i
) {
	mc_zlogf(c_r, c_i, a_r, a_i);
	mc_zmulf(c_r, c_i, b_r, b_i, *c_r, *c_i);
	mc_zexpf(c_r, c_i, *c_r, *c_i);
}

MC_TARGET_PROC void mc_zpow(double * c_r, double * c_i
	, const double a_r, const double a_i
	, const double b_r, const double b_i
) {
	mc_zlog(c_r, c_i, a_r, a_i);
	mc_zmul(c_r, c_i, b_r, b_i, *c_r, *c_i);
	mc_zexp(c_r, c_i, *c_r, *c_i);
}

MC_TARGET_PROC void mc_zpowl(long double * c_r, long double * c_i
	, const long double a_r, const long double a_i
	, const long double b_r, const long double b_i
) {
	mc_zlogl(c_r, c_i, a_r, a_i);
	mc_zmull(c_r, c_i, b_r, b_i, *c_r, *c_i);
	mc_zexpl(c_r, c_i, *c_r, *c_i);
}

#endif /* !MC_ZPOW_H */

/* EOF */