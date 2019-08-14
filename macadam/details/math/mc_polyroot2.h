//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_polyroot2.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_zpolyroot2.h>

#ifndef MC_POLYROOT2_H
#define MC_POLYROOT2_H

#pragma mark - mc_polyroot2 -

int mc_polyroot2f(float a, float b, float c
	, float * r1
	, float * r2
) {
	int r;
	float i1, i2;
	r = mc_zpolyroot2f(a, b, c, r1, &i1, r2, &i2);
	if (!(r == 1 || r == 2)) {
		*r1 = -1.0f;
		*r2 = -1.0f;
		r   = -1;
	}
	return r;
}

int mc_polyroot2(double a, double b, double c
	, double * r1
	, double * r2
) {
	int r;
	double i1, i2;
	r = mc_zpolyroot2(a, b, c, r1, &i1, r2, &i2);
	if (!(r == 1 || r == 2)) {
		*r1 = -1.0;
		*r2 = -1.0;
		r   = -1;
	}
	return r;
}

int mc_polyroot2l(long double a, long double b, long double c
	, long double * r1
	, long double * r2
) {
	int r;
	long double i1, i2;
	r = mc_zpolyroot2l(a, b, c, r1, &i1, r2, &i2);
	if (!(r == 1 || r == 2)) {
		*r1 = -1.0L;
		*r2 = -1.0L;
		r   = -1;
	}
	return r;
}

#endif /* !MC_POLYROOT2_H */

/* EOF */