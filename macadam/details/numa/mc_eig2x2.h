//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_eig2x2.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_eye2x2.h>
#include <macadam/details/numa/mc_zeye2x2.h>
#include <macadam/details/numa/mc_zreig2x2.h>

#ifndef MC_EIG2X2_H
#define MC_EIG2X2_H

#pragma mark - mc_eig2x2 -

MC_TARGET_FUNC int mc_eig2x2f(const float a[4], float e[2], float * v)
{
	int r, wantv = mc_nonnull(v);
	float e0_r, e0_i;
	float e1_r, e1_i;

	float v0_r, v0_i, v1_r, v1_i;
	float v2_r, v2_i, v3_r, v3_i;

	mc_zeye2x2f(
		  &v0_r, &v0_i, &v1_r, &v1_i
		, &v2_r, &v2_i, &v3_r, &v3_i
	);
	if (wantv) {
		mc_eye2x2f(v);
	}
	r = mc_zreig2x2f(a, &e0_r, &e0_i, &e1_r, &e1_i
		, wantv
		, &v0_r, &v0_i, &v1_r, &v1_i
		, &v2_r, &v2_i, &v3_r, &v3_i
	);
	e[0] = e0_r;
	e[1] = e1_r;

	if (wantv) {
		v[0] = v0_r; v[1] = v1_r;
		v[2] = v2_r; v[3] = v3_r;
	}
	return r > 0 ? 0 : r - 1;
}

MC_TARGET_FUNC int mc_eig2x2(const double a[4], double e[2], double * v)
{
	int r, wantv = mc_nonnull(v);
	double e0_r, e0_i;
	double e1_r, e1_i;

	double v0_r, v0_i, v1_r, v1_i;
	double v2_r, v2_i, v3_r, v3_i;

	mc_zeye2x2(
		  &v0_r, &v0_i, &v1_r, &v1_i
		, &v2_r, &v2_i, &v3_r, &v3_i
	);
	if (wantv) {
		mc_eye2x2(v);
	}
	r = mc_zreig2x2(a, &e0_r, &e0_i, &e1_r, &e1_i
		, wantv
		, &v0_r, &v0_i, &v1_r, &v1_i
		, &v2_r, &v2_i, &v3_r, &v3_i
	);
	e[0] = e0_r;
	e[1] = e1_r;

	if (wantv) {
		v[0] = v0_r; v[1] = v1_r;
		v[2] = v2_r; v[3] = v3_r;
	}
	return r > 0 ? 0 : r - 1;
}

MC_TARGET_FUNC int mc_eig2x2l(const long double a[4], long double e[2], long double * v)
{
	int r, wantv = mc_nonnull(v);
	long double e0_r, e0_i;
	long double e1_r, e1_i;

	long double v0_r, v0_i, v1_r, v1_i;
	long double v2_r, v2_i, v3_r, v3_i;

	mc_zeye2x2l(
		  &v0_r, &v0_i, &v1_r, &v1_i
		, &v2_r, &v2_i, &v3_r, &v3_i
	);
	if (wantv) {
		mc_eye2x2l(v);
	}
	r = mc_zreig2x2l(a, &e0_r, &e0_i, &e1_r, &e1_i
		, wantv
		, &v0_r, &v0_i, &v1_r, &v1_i
		, &v2_r, &v2_i, &v3_r, &v3_i
	);
	e[0] = e0_r;
	e[1] = e1_r;

	if (wantv) {
		v[0] = v0_r; v[1] = v1_r;
		v[2] = v2_r; v[3] = v3_r;
	}
	return r > 0 ? 0 : r - 1;
}

#endif /* !MC_EIG2X2_H */

/* EOF */