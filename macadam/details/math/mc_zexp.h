//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zexp.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_exp.h>

#ifndef MC_ZEXP_H
#define MC_ZEXP_H

#pragma mark - mc_zexp -

MC_TARGET_PROC void mc_zexpf(float * c_r, float * c_i
	, float a_r, float a_i
) {
	const float x = mc_expf(a_r);
	*c_r          = x * mc_cosf(a_i);
	*c_i          = x * mc_sinf(a_i);
}

MC_TARGET_PROC void mc_zexp(double * c_r, double * c_i
	, double a_r, double a_i
) {
	const double x = mc_exp(a_r);
	*c_r           = x * mc_cos(a_i);
	*c_i           = x * mc_sin(a_i);
}

MC_TARGET_PROC void mc_zexpl(long double * c_r, long double * c_i
	, long double a_r, long double a_i
) {
	const long double x = mc_expl(a_r);
	*c_r                = x * mc_cosl(a_i);
	*c_i                = x * mc_sinl(a_i);
}

#endif /* !MC_ZEXP_H */

/* EOF */