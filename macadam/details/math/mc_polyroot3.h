//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_polyroot3.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_zpolyroot3.h>

#ifndef MC_POLYROOT3_H
#define MC_POLYROOT3_H

#pragma mark - mc_polyroot3 -

MC_TARGET_PROC int mc_polyroot3f(float a, float b, float c, float d
	, float * r1
	, float * r2
	, float * r3
) {
	int r;
	float i1, i2, i3;
	r = mc_zpolyroot3f(a, b, c, d, r1, &i1, r2, &i2, r3, &i3);
	if (!(r == 2 || r == 3)) {
		*r1 = -1.0f;
		*r2 = -1.0f;
		*r3 = -1.0f;
		r   = -1;
	}
	return r;
}

MC_TARGET_PROC int mc_polyroot3(double a, double b, double c, double d
	, double * r1
	, double * r2
	, double * r3
) {
	int r;
	double i1, i2, i3;
	r = mc_zpolyroot3(a, b, c, d, r1, &i1, r2, &i2, r3, &i3);
	if (!(r == 2 || r == 3)) {
		*r1 = -1.0;
		*r2 = -1.0;
		*r3 = -1.0;
		r   = -1;
	}
	return r;
}

MC_TARGET_PROC int mc_polyroot3l(long double a, long double b, long double c, long double d
	, long double * r1
	, long double * r2
	, long double * r3
) {
	int r;
	long double i1, i2, i3;
	r = mc_zpolyroot3l(a, b, c, d, r1, &i1, r2, &i2, r3, &i3);
	if (!(r == 2 || r == 3)) {
		*r1 = -1.0L;
		*r2 = -1.0L;
		*r3 = -1.0L;
		r   = -1;
	}
	return r;
}

#endif /* !MC_POLYROOT3_H */

/* EOF */