//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zlog.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_log.h>
#include <macadam/details/math/mc_zabs.h>
#include <macadam/details/math/mc_zarg.h>

#ifndef MC_ZLOG_H
#define MC_ZLOG_H

#pragma mark - mc_zlog -

MC_TARGET_PROC void mc_zlogf(float * c_r, float * c_i
	, float a_r, float a_i
) {
	*c_r = mc_logf(mc_zabsf(a_r, a_i));
	*c_i = mc_zargf(a_r, a_i);
}

MC_TARGET_PROC void mc_zlog(double * c_r, double * c_i
	, double a_r, double a_i
) {
	*c_r = mc_log(mc_zabs(a_r, a_i));
	*c_i = mc_zarg(a_r, a_i);
}

MC_TARGET_PROC void mc_zlogl(long double * c_r, long double * c_i
	, long double a_r, long double a_i
) {
	*c_r = mc_logl(mc_zabsl(a_r, a_i));
	*c_i = mc_zargl(a_r, a_i);
}

#endif /* !MC_ZLOG_H */

/* EOF */