//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zpow.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_zexp.h>
#include <macadam/details/math/mc_zlog.h>
#include <macadam/details/math/mc_zmul.h>

#ifndef MC_ZPOW_H
#define MC_ZPOW_H

#pragma mark - mc_zpow -

MC_TARGET_PROC void mc_zpowf(float * c_r, float * c_i
	, float a_r, float a_i
	, float b_r, float b_i
) {
	mc_zlogf(c_r, c_i, a_r, a_i);
	mc_zmulf(c_r, c_i, b_r, b_i, *c_r, *c_i);
	mc_zexpf(c_r, c_i, *c_r, *c_i);
}

MC_TARGET_PROC void mc_zpow(double * c_r, double * c_i
	, double a_r, double a_i
	, double b_r, double b_i
) {
	mc_zlog(c_r, c_i, a_r, a_i);
	mc_zmul(c_r, c_i, b_r, b_i, *c_r, *c_i);
	mc_zexp(c_r, c_i, *c_r, *c_i);
}

MC_TARGET_PROC void mc_zpowl(long double * c_r, long double * c_i
	, long double a_r, long double a_i
	, long double b_r, long double b_i
) {
	mc_zlogl(c_r, c_i, a_r, a_i);
	mc_zmull(c_r, c_i, b_r, b_i, *c_r, *c_i);
	mc_zexpl(c_r, c_i, *c_r, *c_i);
}

#endif /* !MC_ZPOW_H */

/* EOF */