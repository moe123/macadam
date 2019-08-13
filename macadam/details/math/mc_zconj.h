// mc_zconj.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_ZCONJ_H
#define MC_ZCONJ_H

#pragma mark - mc_zconj -

MC_TARGET_PROC void mc_zconjf(float * c_r, float * c_i
	, float a_r, float a_i
) {
	*c_r =  a_r;
	*c_i = -a_i;
}

MC_TARGET_PROC void mc_zconj(double * c_r, double * c_i
	, double a_r, double a_i
) {
	*c_r =  a_r;
	*c_i = -a_i;
}

MC_TARGET_PROC void mc_zconjl(long double * c_r, long double * c_i
	, long double a_r, long double a_i
) {
	*c_r =  a_r;
	*c_i = -a_i;
}

#endif /* !MC_ZCONJ_H */

/* EOF */