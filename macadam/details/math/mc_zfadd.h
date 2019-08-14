//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zfadd.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_ZFADD_H
#define MC_ZFADD_H

#pragma mark - mc_zfadd -

MC_TARGET_PROC void mc_zfaddf(float * c_r, float * c_i
	, float a_r, float a_i
	, float b
) {
	*c_r = a_r + b;
	*c_i = a_i;
}

MC_TARGET_PROC void mc_zfadd(double * c_r, double * c_i
	, double a_r, double a_i
	, double b
) {
	*c_r = a_r + b;
	*c_i = a_i;
}

MC_TARGET_PROC void mc_zfaddl(long double * c_r, long double * c_i
	, long double a_r, long double a_i
	, long double b
) {
	*c_r = a_r + b;
	*c_i = a_i;
}

#endif /* !MC_ZFADD_H */

/* EOF */