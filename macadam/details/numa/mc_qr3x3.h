//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_qr3x3.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_raise2.h>
#include <macadam/details/math/mc_sqrt.h>

#ifndef MC_QR3X3_H
#define MC_QR3X3_H

#pragma mark - mc_qr3x3 -

MC_TARGET_FUNC int mc_qr3x3f(const float a[9], float q[9], float r[9])
{
//!# A and Q may be the same. Using Gram-Schmidt method.
	float w;

	if (a != q) {
		q[0] = a[0]; q[1] = a[1]; q[2] = a[2];
		q[3] = a[3]; q[4] = a[4]; q[5] = a[5];
		q[6] = a[6]; q[7] = a[7]; q[8] = a[8];
	}

	r[0] = 0.0f; r[1] = 0.0f; r[2] = 0.0f;
	r[3] = 0.0f; r[4] = 0.0f; r[5] = 0.0f;
	r[6] = 0.0f; r[7] = 0.0f; r[8] = 0.0f;

	w = mc_raise2f(q[0]) + mc_raise2f(q[3]) + mc_raise2f(q[6]);
	if (w != 0.0f) {
		w    = mc_sqrtf(w);
		r[0] = w;
		w    = 1.0f / w;
	}
	q[0] = q[0] * w;
	q[3] = q[3] * w;
	q[6] = q[6] * w;

	w    = q[0] * q[1] + q[3] * q[4] + q[6] * q[7];
	r[1] = w;

	q[1] = q[1] - w * q[0];
	q[4] = q[4] - w * q[3];
	q[7] = q[7] - w * q[6];

	w = mc_raise2f(q[1]) + mc_raise2f(q[4]) + mc_raise2f(q[7]);
	if (w != 0.0f) {
		w    = mc_sqrtf(w);
		r[4] = w;
		w    = 1.0f / w;
	}
	q[1] = q[1] * w;
	q[4] = q[4] * w;
	q[7] = q[7] * w;

	w    = q[0] * q[2] + q[3] * q[5] + q[6] * q[8];
	r[2] = w;

	q[2] = q[2] - w * q[0];
	q[5] = q[5] - w * q[3];
	q[8] = q[8] - w * q[6];

	w    = q[1] * q[2] + q[4] * q[5] + q[7] * q[8];
	r[5] = w;

	q[2] = q[2] - w * q[1];
	q[5] = q[5] - w * q[4];
	q[8] = q[8] - w * q[7];

	w = mc_raise2f(q[2]) + mc_raise2f(q[5]) + mc_raise2f(q[8]);
	if (w != 0.0f) {
		w    = mc_sqrtf(w);
		r[8] = w;
		w    = 1.0f / w;
	}
	q[2] = q[2] * w;
	q[5] = q[5] * w;
	q[8] = q[8] * w;

	return 0;
}

MC_TARGET_FUNC int mc_qr3x3ff(const float a[9], double q[9], double r[9])
{
//!# Using Gram-Schmidt method.
	double w;

	q[0] = mc_cast(double, a[0]); q[1] = mc_cast(double, a[1]); q[2] = mc_cast(double, a[2]);
	q[3] = mc_cast(double, a[3]); q[4] = mc_cast(double, a[4]); q[5] = mc_cast(double, a[5]);
	q[6] = mc_cast(double, a[6]); q[7] = mc_cast(double, a[7]); q[8] = mc_cast(double, a[8]);

	r[0] = 0.0; r[1] = 0.0; r[2] = 0.0;
	r[3] = 0.0; r[4] = 0.0; r[5] = 0.0;
	r[6] = 0.0; r[7] = 0.0; r[8] = 0.0;

	w = mc_raise2(q[0]) + mc_raise2(q[3]) + mc_raise2(q[6]);
	if (w != 0.0) {
		w    = mc_sqrt(w);
		r[0] = w;
		w    = 1.0 / w;
	}
	q[0] = q[0] * w;
	q[3] = q[3] * w;
	q[6] = q[6] * w;

	w    = q[0] * q[1] + q[3] * q[4] + q[6] * q[7];
	r[1] = w;

	q[1] = q[1] - w * q[0];
	q[4] = q[4] - w * q[3];
	q[7] = q[7] - w * q[6];

	w = mc_raise2(q[1]) + mc_raise2(q[4]) + mc_raise2(q[7]);
	if (w != 0.0) {
		w    = mc_sqrt(w);
		r[4] = w;
		w    = 1.0 / w;
	}
	q[1] = q[1] * w;
	q[4] = q[4] * w;
	q[7] = q[7] * w;

	w    = q[0] * q[2] + q[3] * q[5] + q[6] * q[8];
	r[2] = w;

	q[2] = q[2] - w * q[0];
	q[5] = q[5] - w * q[3];
	q[8] = q[8] - w * q[6];

	w    = q[1] * q[2] + q[4] * q[5] + q[7] * q[8];
	r[5] = w;

	q[2] = q[2] - w * q[1];
	q[5] = q[5] - w * q[4];
	q[8] = q[8] - w * q[7];

	w = mc_raise2(q[2]) + mc_raise2(q[5]) + mc_raise2(q[8]);
	if (w != 0.0) {
		w    = mc_sqrt(w);
		r[8] = w;
		w    = 1.0 / w;
	}
	q[2] = q[2] * w;
	q[5] = q[5] * w;
	q[8] = q[8] * w;

	return 0;
}

MC_TARGET_FUNC int mc_qr3x3(const double a[9], double q[9], double r[9])
{
//!# A and Q may be the same. Using Gram-Schmidt method.
	double w;

	if (a != q) {
		q[0] = a[0]; q[1] = a[1]; q[2] = a[2];
		q[3] = a[3]; q[4] = a[4]; q[5] = a[5];
		q[6] = a[6]; q[7] = a[7]; q[8] = a[8];
	}

	r[0] = 0.0; r[1] = 0.0; r[2] = 0.0;
	r[3] = 0.0; r[4] = 0.0; r[5] = 0.0;
	r[6] = 0.0; r[7] = 0.0; r[8] = 0.0;

	w = mc_raise2(q[0]) + mc_raise2(q[3]) + mc_raise2(q[6]);
	if (w != 0.0) {
		w    = mc_sqrt(w);
		r[0] = w;
		w    = 1.0 / w;
	}
	q[0] = q[0] * w;
	q[3] = q[3] * w;
	q[6] = q[6] * w;

	w    = q[0] * q[1] + q[3] * q[4] + q[6] * q[7];
	r[1] = w;

	q[1] = q[1] - w * q[0];
	q[4] = q[4] - w * q[3];
	q[7] = q[7] - w * q[6];

	w = mc_raise2(q[1]) + mc_raise2(q[4]) + mc_raise2(q[7]);
	if (w != 0.0) {
		w    = mc_sqrt(w);
		r[4] = w;
		w    = 1.0 / w;
	}
	q[1] = q[1] * w;
	q[4] = q[4] * w;
	q[7] = q[7] * w;

	w    = q[0] * q[2] + q[3] * q[5] + q[6] * q[8];
	r[2] = w;

	q[2] = q[2] - w * q[0];
	q[5] = q[5] - w * q[3];
	q[8] = q[8] - w * q[6];

	w    = q[1] * q[2] + q[4] * q[5] + q[7] * q[8];
	r[5] = w;

	q[2] = q[2] - w * q[1];
	q[5] = q[5] - w * q[4];
	q[8] = q[8] - w * q[7];

	w = mc_raise2(q[2]) + mc_raise2(q[5]) + mc_raise2(q[8]);
	if (w != 0.0) {
		w    = mc_sqrt(w);
		r[8] = w;
		w    = 1.0 / w;
	}
	q[2] = q[2] * w;
	q[5] = q[5] * w;
	q[8] = q[8] * w;

	return 0;
}

MC_TARGET_FUNC int mc_qr3x3l(const long double a[9], long double q[9], long double r[9])
{
//!# A and Q may be the same. Using Gram-Schmidt method.
	long double w;

	if (a != q) {
		q[0] = a[0]; q[1] = a[1]; q[2] = a[2];
		q[3] = a[3]; q[4] = a[4]; q[5] = a[5];
		q[6] = a[6]; q[7] = a[7]; q[8] = a[8];
	}

	r[0] = 0.0L; r[1] = 0.0L; r[2] = 0.0L;
	r[3] = 0.0L; r[4] = 0.0L; r[5] = 0.0L;
	r[6] = 0.0L; r[7] = 0.0L; r[8] = 0.0L;

	w = mc_raise2l(q[0]) + mc_raise2l(q[3]) + mc_raise2l(q[6]);
	if (w != 0.0L) {
		w    = mc_sqrtl(w);
		r[0] = w;
		w    = 1.0L / w;
	}
	q[0] = q[0] * w;
	q[3] = q[3] * w;
	q[6] = q[6] * w;

	w    = q[0] * q[1] + q[3] * q[4] + q[6] * q[7];
	r[1] = w;

	q[1] = q[1] - w * q[0];
	q[4] = q[4] - w * q[3];
	q[7] = q[7] - w * q[6];

	w = mc_raise2l(q[1]) + mc_raise2l(q[4]) + mc_raise2l(q[7]);
	if (w != 0.0L) {
		w    = mc_sqrtl(w);
		r[4] = w;
		w    = 1.0L / w;
	}
	q[1] = q[1] * w;
	q[4] = q[4] * w;
	q[7] = q[7] * w;

	w    = q[0] * q[2] + q[3] * q[5] + q[6] * q[8];
	r[2] = w;

	q[2] = q[2] - w * q[0];
	q[5] = q[5] - w * q[3];
	q[8] = q[8] - w * q[6];

	w    = q[1] * q[2] + q[4] * q[5] + q[7] * q[8];
	r[5] = w;

	q[2] = q[2] - w * q[1];
	q[5] = q[5] - w * q[4];
	q[8] = q[8] - w * q[7];

	w = mc_raise2l(q[2]) + mc_raise2l(q[5]) + mc_raise2l(q[8]);
	if (w != 0.0L) {
		w    = mc_sqrtl(w);
		r[8] = w;
		w    = 1.0L / w;
	}
	q[2] = q[2] * w;
	q[5] = q[5] * w;
	q[8] = q[8] * w;

	return 0;
}

#endif /* !MC_QR3X3_H */

/* EOF */