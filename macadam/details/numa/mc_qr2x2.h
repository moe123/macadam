//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_qr2x2.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_raise2.h>
#include <macadam/details/math/mc_sqrt.h>

#ifndef MC_QR2X2_H
#define MC_QR2X2_H

#pragma mark - mc_qr2x2 -

MC_TARGET_FUNC int mc_qr2x2f(const float a[4], float q[4], float r[4])
{
//!# A and Q may be the same. Using Gram-Schmidt method.
	float w;

	if (a != q) {
		q[0] = a[0]; q[1] = a[1];
		q[2] = a[2]; q[3] = a[3];
	}

	r[0] = 0.0f; r[1] = 0.0f;
	r[2] = 0.0f; r[3] = 0.0f;

	w = mc_raise2f(q[0]) + mc_raise2f(q[2]);
	if (w != 0.0f) {
		w    = mc_sqrtf(w);
		r[0] = w;
		w    = 1.0f /w;
	}

	q[0] = q[0] * w;
	q[2] = q[2] * w;

	w    = q[0] * q[1] + q[2] * q[3];
	r[1] = w;

	q[1] = q[1] - w * q[0];
	q[3] = q[3] - w * q[2];

	w = mc_raise2f(q[1]) + mc_raise2f(q[3]);
	if (w != 0.0f) {
		w    = mc_sqrtf(w);
		r[3] = w;
		w    = 1.0f / w;
	}

	q[1] = q[1] * w;
	q[3] = q[3] * w;

	return 0;
}

MC_TARGET_FUNC int mc_qr2x2ff(const float a[4], double q[4], double r[4])
{
//!# Using Gram-Schmidt method.
	double w;

	q[0] = mc_cast(double, a[0]); q[1] =  mc_cast(double, a[1]);
	q[2] = mc_cast(double, a[2]); q[3] =  mc_cast(double, a[3]);

	r[0] = 0.0; r[1] = 0.0;
	r[2] = 0.0; r[3] = 0.0;

	w = mc_raise2(q[0]) + mc_raise2(q[2]);
	if (w != 0.0) {
		w    = mc_sqrt(w);
		r[0] = w;
		w    = 1.0 /w;
	}

	q[0] = q[0] * w;
	q[2] = q[2] * w;

	w    = q[0] * q[1] + q[2] * q[3];
	r[1] = w;

	q[1] = q[1] - w * q[0];
	q[3] = q[3] - w * q[2];

	w = mc_raise2(q[1]) + mc_raise2(q[3]);
	if (w != 0.0) {
		w    = mc_sqrt(w);
		r[3] = w;
		w    = 1.0 / w;
	}

	q[1] = q[1] * w;
	q[3] = q[3] * w;

	return 0;
}

MC_TARGET_FUNC int mc_qr2x2(const double a[4], double q[4], double r[4])
{
//!# A and Q may be the same. Using Gram-Schmidt method.
	double w;

	if (a != q) {
		q[0] = a[0]; q[1] = a[1];
		q[2] = a[2]; q[3] = a[3];
	}

	r[0] = 0.0; r[1] = 0.0;
	r[2] = 0.0; r[3] = 0.0;

	w = mc_raise2(q[0]) + mc_raise2(q[2]);
	if (w != 0.0) {
		w    = mc_sqrt(w);
		r[0] = w;
		w    = 1.0 /w;
	}

	q[0] = q[0] * w;
	q[2] = q[2] * w;

	w    = q[0] * q[1] + q[2] * q[3];
	r[1] = w;

	q[1] = q[1] - w * q[0];
	q[3] = q[3] - w * q[2];

	w = mc_raise2(q[1]) + mc_raise2(q[3]);
	if (w != 0.0) {
		w    = mc_sqrt(w);
		r[3] = w;
		w    = 1.0 / w;
	}

	q[1] = q[1] * w;
	q[3] = q[3] * w;

	return 0;
}

MC_TARGET_FUNC int mc_qr2x2l(const long double a[4], long double q[4], long double r[4])
{
//!# A and Q may be the same. Using Gram-Schmidt method.
	long double w;

	if (a != q) {
		q[0] = a[0]; q[1] = a[1];
		q[2] = a[2]; q[3] = a[3];
	}

	r[0] = 0.0L; r[1] = 0.0L;
	r[2] = 0.0L; r[3] = 0.0L;

	w = mc_raise2l(q[0]) + mc_raise2l(q[2]);
	if (w != 0.0L) {
		w    = mc_sqrtl(w);
		r[0] = w;
		w    = 1.0L /w;
	}

	q[0] = q[0] * w;
	q[2] = q[2] * w;

	w    = q[0] * q[1] + q[2] * q[3];
	r[1] = w;

	q[1] = q[1] - w * q[0];
	q[3] = q[3] - w * q[2];

	w = mc_raise2l(q[1]) + mc_raise2l(q[3]);
	if (w != 0.0L) {
		w    = mc_sqrtl(w);
		r[3] = w;
		w    = 1.0L / w;
	}

	q[1] = q[1] * w;
	q[3] = q[3] * w;

	return 0;
}

#endif /* !MC_QR2X2_H */

/* EOF */