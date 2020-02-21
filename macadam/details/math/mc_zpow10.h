//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zpow10.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_zexp.h>
#include <macadam/details/math/mc_zmul.h>

#ifndef MC_ZPOW10_H
#define MC_ZPOW10_H

#pragma mark - mc_zpow10 -

MC_TARGET_PROC void mc_zpow10f(float * c_r, float * c_i
	, float a_r, float a_i
) {
	*c_r = MCK_KF(MCK_LOG10);
	*c_i = 0.0f;
	mc_zmulf(c_r, c_i, a_r, a_i, *c_r, *c_i);
	mc_zexpf(c_r, c_i, *c_r, *c_i);
}

MC_TARGET_PROC void mc_zpow10(double * c_r, double * c_i
	, double a_r, double a_i
) {
	*c_r = MCK_K(MCK_LOG10);
	*c_i = 0.0;
	mc_zmul(c_r, c_i, a_r, a_i, *c_r, *c_i);
	mc_zexp(c_r, c_i, *c_r, *c_i);
}

MC_TARGET_PROC void mc_zpow10l(long double * c_r, long double * c_i
	, long double a_r, long double a_i
) {
	*c_r = MCK_KL(MCK_LOG10);
	*c_i = 0.0L;
	mc_zmull(c_r, c_i, a_r, a_i, *c_r, *c_i);
	mc_zexpl(c_r, c_i, *c_r, *c_i);
}

#endif /* !MC_ZPOW10_H */

/* EOF */