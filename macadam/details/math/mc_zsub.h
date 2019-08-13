// mc_zsub.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_ZSUB_H
#define MC_ZSUB_H

#pragma mark - mc_zsub -

MC_TARGET_PROC void mc_zsubf(float * c_r, float * c_i
	, float a_r, float a_i
	, float b_r, float b_i
) {
	*c_r = a_r - b_r;
	*c_i = a_i - b_i;
}

MC_TARGET_PROC void mc_zsub(double * c_r, double * c_i
	, double a_r, double a_i
	, double b_r, double b_i
) {
	*c_r = a_r - b_r;
	*c_i = a_i - b_i;
}

MC_TARGET_PROC void mc_zsubl(long double * c_r, long double * c_i
	, long double a_r, long double a_i
	, long double b_r, long double b_i
) {
	*c_r = a_r - b_r;
	*c_i = a_i - b_i;
}

#endif /* !MC_ZSUB_H */

/* EOF */