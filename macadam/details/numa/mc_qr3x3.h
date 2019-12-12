//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_qr3x3.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_hypot2.h>
#include <macadam/details/math/mc_hypot3.h>
#include <macadam/details/numa/mc_eye3x3.h>
#include <macadam/details/numa/mc_gvrot.h>
#include <macadam/details/numa/mc_zeros3x3.h>

#ifndef MC_QR3X3_H
#define MC_QR3X3_H

#pragma mark - mc_qrgv3x3 -

MC_TARGET_FUNC int mc_qrgv3x3f(const float a[9], float q[9], float r[9])
{
//!# A and Q may be the same. Using Givens rotations method.
	const float tol = 2.0f * MCLIMITS_EPSILONF;

	float a0, b0, ch1, sh1, ch2, sh2, ch3, sh3, sh12, sh22, sh32;

	float a11 = a[0], a12 = a[1], a13 = a[2];
	float a21 = a[3], a22 = a[4], a23 = a[5];
	float a31 = a[6], a32 = a[7], a33 = a[8];

//!# First givens rotation (ch, 0, 0, sh)
	mc_gvrotf(a11, a21, tol, &ch1, &sh1);
	a0 = 1.0f - 2.0f * sh1 * sh1;
	b0 = 2.0f        * ch1 * sh1;

//!# Computing B=Q'*B
	r[0] =  a0 * a11 + b0 * a21; r[1] =  a0 * a12 + b0 * a22; r[2] =  a0 * a13 + b0 * a23;
	r[3] = -b0 * a11 + a0 * a21; r[4] = -b0 * a12 + a0 * a22; r[5] = -b0 * a13 + a0 * a23;
	r[6] =  a31;                 r[7] =  a32;                 r[8] =  a33;

//!# Second givens rotation (ch, 0, -sh, 0)
	mc_gvrotf(r[0], r[6], tol, &ch2, &sh2);
	a0 = 1.0f - 2.0f * sh2 * sh2;
	b0 = 2.0f        * ch2 * sh2;

//!# Computing B=Q'*B
	a11 =  a0 * r[0] + b0 * r[6]; a12 =  a0 * r[1] + b0 * r[7]; a13 =  a0 * r[2] + b0 * r[8];
	a21 =  r[3];                  a22 =  r[4];                  a23 =  r[5];
	a31 = -b0 * r[0] + a0 * r[6]; a32 = -b0 * r[1] + a0 * r[7]; a33 = -b0 * r[2] + a0 * r[8];

//!# Third givens rotation (ch, sh, 0, 0)
	mc_gvrotf(a22, a32, tol, &ch3, &sh3);
	a0 = 1.0f - 2.0f * sh3 * sh3;
	b0 = 2.0f        * ch3 * sh3;

//!# Computing and finalizing R.
	r[0] =  a11;                 r[1] =  a12;                 r[2] =  a13;
	r[3] =  a0 * a21 + b0 * a31; r[4] =  a0 * a22 + b0 * a32; r[5] =  a0 * a23 + b0 * a33;
	r[6] = -b0 * a21 + a0 * a31; r[7] = -b0 * a22 + a0 * a32; r[8] = -b0 * a23 + a0 * a33;

	sh12 = sh1 * sh1;
	sh22 = sh2 * sh2;
	sh32 = sh3 * sh3;

//!# Computing Q such as Q=Q1*Q2*Q3
	q[0] =  (-1.0f + 2.0f * sh12) * (-1.0f + 2.0f * sh22); 
	q[1] =  4.0f * ch2 * ch3 * (-1.0f + 2.0f * sh12) * sh2 * sh3 + 2.0f * ch1 * sh1 * (-1.0f + 2.0f * sh32); 
	q[2] =  4.0f * ch1 * ch3 * sh1 * sh3 - 2.0f * ch2 * (-1.0f + 2.0f * sh12) * sh2 * (-1.0f + 2.0f * sh32);

	q[3] =  2.0f * ch1 * sh1 * (1.0f - 2.0f * sh22); 
	q[4] = -8.0f * ch1 * ch2 * ch3 * sh1 * sh2 * sh3 + (-1.0f + 2.0f * sh12) * (-1.0f + 2.0f * sh32); 
	q[5] = -2.0f * ch3 * sh3 + 4.0f * sh1 * (ch3 * sh1 * sh3+ch1 * ch2 * sh2 * (-1.0f + 2.0f * sh32));

	q[6] =  2.0f * ch2 * sh2; 
	q[7] =  2.0f * ch3 * (1.0f - 2.0f * sh22) * sh3; 
	q[8] =  (-1.0f + 2.0f * sh22) * (-1.0f + 2.0f * sh32);

	return 0;
}

MC_TARGET_PROC int mc_qrgv3x3ff(const float a[9], double q[9], double r[9])
{
//!# Using Givens rotations method.
	const double tol = 2.0 * MCLIMITS_EPSILON;

	double a0, b0, ch1, sh1, ch2, sh2, ch3, sh3, sh12, sh22, sh32;

	double a11 = mc_cast(double, a[0]), a12 = mc_cast(double, a[1]), a13 = mc_cast(double, a[2]);
	double a21 = mc_cast(double, a[3]), a22 = mc_cast(double, a[4]), a23 = mc_cast(double, a[5]);
	double a31 = mc_cast(double, a[6]), a32 = mc_cast(double, a[7]), a33 = mc_cast(double, a[8]);

//!# First givens rotation (ch, 0, 0, sh)
	mc_gvrot(a11, a21, tol, &ch1, &sh1);
	a0 = 1.0 - 2.0 * sh1 * sh1;
	b0 = 2.0       * ch1 * sh1;

//!# Computing B=Q'*B
	r[0] =  a0 * a11 + b0 * a21; r[1] =  a0 * a12 + b0 * a22; r[2] =  a0 * a13 + b0 * a23;
	r[3] = -b0 * a11 + a0 * a21; r[4] = -b0 * a12 + a0 * a22; r[5] = -b0 * a13 + a0 * a23;
	r[6] =  a31;                 r[7] =  a32;                 r[8] =  a33;

//!# Second givens rotation (ch, 0, -sh, 0)
	mc_gvrot(r[0], r[6], tol, &ch2, &sh2);
	a0 = 1.0 - 2.0 * sh2 * sh2;
	b0 = 2.0       * ch2 * sh2;

//!# Computing B=Q'*B
	a11 =  a0 * r[0] + b0 * r[6]; a12 =  a0 * r[1] + b0 * r[7]; a13 =  a0 * r[2] + b0 * r[8];
	a21 =  r[3];                  a22 =  r[4];                  a23 =  r[5];
	a31 = -b0 * r[0] + a0 * r[6]; a32 = -b0 * r[1] + a0 * r[7]; a33 = -b0 * r[2] + a0 * r[8];

//!# Third givens rotation (ch, sh, 0, 0)
	mc_gvrot(a22, a32, tol, &ch3, &sh3);
	a0 = 1.0 - 2.0 * sh3 * sh3;
	b0 = 2.0       * ch3 * sh3;

//!# Computing and finalizing R.
	r[0] =  a11;                 r[1] =  a12;                 r[2] =  a13;
	r[3] =  a0 * a21 + b0 * a31; r[4] =  a0 * a22 + b0 * a32; r[5] =  a0 * a23 + b0 * a33;
	r[6] = -b0 * a21 + a0 * a31; r[7] = -b0 * a22 + a0 * a32; r[8] = -b0 * a23 + a0 * a33;

	sh12 = sh1 * sh1;
	sh22 = sh2 * sh2;
	sh32 = sh3 * sh3;

//!# Computing Q such as Q=Q1*Q2*Q3
	q[0] =  (-1.0 + 2.0 * sh12) * (-1.0 + 2.0 * sh22); 
	q[1] =  4.0 * ch2 * ch3 * (-1.0 + 2.0 * sh12) * sh2 * sh3 + 2.0 * ch1 * sh1 * (-1.0 + 2.0 * sh32); 
	q[2] =  4.0 * ch1 * ch3 * sh1 * sh3 - 2.0 * ch2 * (-1.0 + 2.0 * sh12) * sh2 * (-1.0 + 2.0 * sh32);

	q[3] =  2.0 * ch1 * sh1 * (1.0 - 2.0 * sh22); 
	q[4] = -8.0 * ch1 * ch2 * ch3 * sh1 * sh2 * sh3 + (-1.0 + 2.0 * sh12) * (-1.0 + 2.0 * sh32); 
	q[5] = -2.0 * ch3 * sh3 + 4.0 * sh1 * (ch3 * sh1 * sh3+ch1 * ch2 * sh2 * (-1.0 + 2.0 * sh32));

	q[6] =  2.0 * ch2 * sh2; 
	q[7] =  2.0 * ch3 * (1.0 - 2.0 * sh22) * sh3; 
	q[8] =  (-1.0 + 2.0 * sh22) * (-1.0 + 2.0 * sh32);

	return 0;
}

MC_TARGET_PROC int mc_qrgv3x3(const double a[9], double q[9], double r[9])
{
//!# A and Q may be the same. Using Givens rotations method.
	const double tol = 2.0 * MCLIMITS_EPSILON;

	double a0, b0, ch1, sh1, ch2, sh2, ch3, sh3, sh12, sh22, sh32;

	double a11 = a[0], a12 = a[1], a13 = a[2];
	double a21 = a[3], a22 = a[4], a23 = a[5];
	double a31 = a[6], a32 = a[7], a33 = a[8];

//!# First givens rotation (ch, 0, 0, sh)
	mc_gvrot(a11, a21, tol, &ch1, &sh1);
	a0 = 1.0 - 2.0 * sh1 * sh1;
	b0 = 2.0       * ch1 * sh1;

//!# Computing B=Q'*B
	r[0] =  a0 * a11 + b0 * a21; r[1] =  a0 * a12 + b0 * a22; r[2] =  a0 * a13 + b0 * a23;
	r[3] = -b0 * a11 + a0 * a21; r[4] = -b0 * a12 + a0 * a22; r[5] = -b0 * a13 + a0 * a23;
	r[6] =  a31;                 r[7] =  a32;                 r[8] =  a33;

//!# Second givens rotation (ch, 0, -sh, 0)
	mc_gvrot(r[0], r[6], tol, &ch2, &sh2);
	a0 = 1.0 - 2.0 * sh2 * sh2;
	b0 = 2.0       * ch2 * sh2;

//!# Computing B=Q'*B
	a11 =  a0 * r[0] + b0 * r[6]; a12 =  a0 * r[1] + b0 * r[7]; a13 =  a0 * r[2] + b0 * r[8];
	a21 =  r[3];                  a22 =  r[4];                  a23 =  r[5];
	a31 = -b0 * r[0] + a0 * r[6]; a32 = -b0 * r[1] + a0 * r[7]; a33 = -b0 * r[2] + a0 * r[8];

//!# Third givens rotation (ch, sh, 0, 0)
	mc_gvrot(a22, a32, tol, &ch3, &sh3);
	a0 = 1.0 - 2.0 * sh3 * sh3;
	b0 = 2.0       * ch3 * sh3;

//!# Computing and finalizing R.
	r[0] =  a11;                 r[1] =  a12;                 r[2] =  a13;
	r[3] =  a0 * a21 + b0 * a31; r[4] =  a0 * a22 + b0 * a32; r[5] =  a0 * a23 + b0 * a33;
	r[6] = -b0 * a21 + a0 * a31; r[7] = -b0 * a22 + a0 * a32; r[8] = -b0 * a23 + a0 * a33;

	sh12 = sh1 * sh1;
	sh22 = sh2 * sh2;
	sh32 = sh3 * sh3;

//!# Computing Q such as Q=Q1*Q2*Q3
	q[0] =  (-1.0 + 2.0 * sh12) * (-1.0 + 2.0 * sh22); 
	q[1] =  4.0 * ch2 * ch3 * (-1.0 + 2.0 * sh12) * sh2 * sh3 + 2.0 * ch1 * sh1 * (-1.0 + 2.0 * sh32); 
	q[2] =  4.0 * ch1 * ch3 * sh1 * sh3 - 2.0 * ch2 * (-1.0 + 2.0 * sh12) * sh2 * (-1.0 + 2.0 * sh32);

	q[3] =  2.0 * ch1 * sh1 * (1.0 - 2.0 * sh22); 
	q[4] = -8.0 * ch1 * ch2 * ch3 * sh1 * sh2 * sh3 + (-1.0 + 2.0 * sh12) * (-1.0 + 2.0 * sh32); 
	q[5] = -2.0 * ch3 * sh3 + 4.0 * sh1 * (ch3 * sh1 * sh3+ch1 * ch2 * sh2 * (-1.0 + 2.0 * sh32));

	q[6] =  2.0 * ch2 * sh2; 
	q[7] =  2.0 * ch3 * (1.0 - 2.0 * sh22) * sh3; 
	q[8] =  (-1.0 + 2.0 * sh22) * (-1.0 + 2.0 * sh32);

	return 0;
}

MC_TARGET_PROC int mc_qrgv3x3l(const long double a[9], long double q[9], long double r[9])
{
//!# A and Q may be the same. Using Givens rotations method.
	const long double tol = 2.0L * MCLIMITS_EPSILONL;

	long double a0, b0, ch1, sh1, ch2, sh2, ch3, sh3, sh12, sh22, sh32;

	long double a11 = a[0], a12 = a[1], a13 = a[2];
	long double a21 = a[3], a22 = a[4], a23 = a[5];
	long double a31 = a[6], a32 = a[7], a33 = a[8];

//!# First givens rotation (ch, 0, 0, sh)
	mc_gvrotl(a11, a21, tol, &ch1, &sh1);
	a0 = 1.0L - 2.0L * sh1 * sh1;
	b0 = 2.0L        * ch1 * sh1;

//!# Computing B=Q'*B
	r[0] =  a0 * a11 + b0 * a21; r[1] =  a0 * a12 + b0 * a22; r[2] =  a0 * a13 + b0 * a23;
	r[3] = -b0 * a11 + a0 * a21; r[4] = -b0 * a12 + a0 * a22; r[5] = -b0 * a13 + a0 * a23;
	r[6] =  a31;                 r[7] =  a32;                 r[8] =  a33;

//!# Second givens rotation (ch, 0, -sh, 0)
	mc_gvrotl(r[0], r[6], tol, &ch2, &sh2);
	a0 = 1.0L - 2.0L * sh2 * sh2;
	b0 = 2.0L        * ch2 * sh2;

//!# Computing B=Q'*B
	a11 =  a0 * r[0] + b0 * r[6]; a12 =  a0 * r[1] + b0 * r[7]; a13 =  a0 * r[2] + b0 * r[8];
	a21 =  r[3];                  a22 =  r[4];                  a23 =  r[5];
	a31 = -b0 * r[0] + a0 * r[6]; a32 = -b0 * r[1] + a0 * r[7]; a33 = -b0 * r[2] + a0 * r[8];

//!# Third givens rotation (ch, sh, 0, 0)
	mc_gvrotl(a22, a32, tol, &ch3, &sh3);
	a0 = 1.0L - 2.0L * sh3 * sh3;
	b0 = 2.0L        * ch3 * sh3;

//!# Computing and finalizing R.
	r[0] =  a11;                 r[1] =  a12;                 r[2] =  a13;
	r[3] =  a0 * a21 + b0 * a31; r[4] =  a0 * a22 + b0 * a32; r[5] =  a0 * a23 + b0 * a33;
	r[6] = -b0 * a21 + a0 * a31; r[7] = -b0 * a22 + a0 * a32; r[8] = -b0 * a23 + a0 * a33;

	sh12 = sh1 * sh1;
	sh22 = sh2 * sh2;
	sh32 = sh3 * sh3;

//!# Computing Q such as Q=Q1*Q2*Q3
	q[0] =  (-1.0L + 2.0L * sh12) * (-1.0L + 2.0L * sh22); 
	q[1] =  4.0L * ch2 * ch3 * (-1.0L + 2.0L * sh12) * sh2 * sh3 + 2.0L * ch1 * sh1 * (-1.0L + 2.0L * sh32); 
	q[2] =  4.0L * ch1 * ch3 * sh1 * sh3 - 2.0L * ch2 * (-1.0L + 2.0L * sh12) * sh2 * (-1.0L + 2.0L * sh32);

	q[3] =  2.0L * ch1 * sh1 * (1.0L - 2.0L * sh22); 
	q[4] = -8.0L * ch1 * ch2 * ch3 * sh1 * sh2 * sh3 + (-1.0L + 2.0L * sh12) * (-1.0L + 2.0L * sh32); 
	q[5] = -2.0L * ch3 * sh3 + 4.0L * sh1 * (ch3 * sh1 * sh3+ch1 * ch2 * sh2 * (-1.0L + 2.0L * sh32));

	q[6] =  2.0L * ch2 * sh2; 
	q[7] =  2.0L * ch3 * (1.0L - 2.0L * sh22) * sh3; 
	q[8] =  (-1.0L + 2.0L * sh22) * (-1.0L + 2.0L * sh32);

	return 0;
}

#pragma mark - mc_qr3x3 -

MC_TARGET_FUNC int mc_qr3x3f(const float a[9], float q[9], float r[9])
{
//!# A and Q may be the same. Using Gram-Schmidt method. QT*Q=I for eps 1E-06
//!# which is better than HH approach for singles. We might use in the future
//!# a variant to do error correction for the sum^2.
	float w;

	if (a != q) {
		q[0] = a[0]; q[1] = a[1]; q[2] = a[2];
		q[3] = a[3]; q[4] = a[4]; q[5] = a[5];
		q[6] = a[6]; q[7] = a[7]; q[8] = a[8];
	}

	mc_zeros3x3f(r);

	w = mc_hypot3f(q[0], q[3], q[6]);
	if (w != 0.0f) {
		r[0] = w;
		w    = 1.0f / w;
	} else {
		mc_eye3x3f(q);
		mc_eye3x3f(r);
		return -1;
	}
	q[0] = q[0] * w;
	q[3] = q[3] * w;
	q[6] = q[6] * w;

	w    = q[0] * q[1] + q[3] * q[4] + q[6] * q[7];
	r[1] = w;

	q[1] = q[1] - w * q[0];
	q[4] = q[4] - w * q[3];
	q[7] = q[7] - w * q[6];

	w = mc_hypot3f(q[1], q[4], q[7]);
	if (w != 0.0f) {
		r[4] = w;
		w    = 1.0f / w;
	} else {
		mc_eye3x3f(q);
		mc_eye3x3f(r);
		return -1;
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

	w = mc_hypot3f(q[2], q[5], q[8]);
	if (w != 0.0f) {
		r[8] = w;
		w    = 1.0f / w;
	} else {
		mc_eye3x3f(q);
		mc_eye3x3f(r);
		return -1;
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

	mc_zeros3x3(r);

	w = mc_hypot3(q[0], q[3], q[6]);
	if (w != 0.0) {
		r[0] = w;
		w    = 1.0 / w;
	} else {
		mc_eye3x3(q);
		mc_eye3x3(r);
		return -1;
	}
	q[0] = q[0] * w;
	q[3] = q[3] * w;
	q[6] = q[6] * w;

	w    = q[0] * q[1] + q[3] * q[4] + q[6] * q[7];
	r[1] = w;

	q[1] = q[1] - w * q[0];
	q[4] = q[4] - w * q[3];
	q[7] = q[7] - w * q[6];

	w = mc_hypot3(q[1], q[4], q[7]);
	if (w != 0.0) {
		r[4] = w;
		w    = 1.0 / w;
	} else {
		mc_eye3x3(q);
		mc_eye3x3(r);
		return -1;
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

	w = mc_hypot3(q[2], q[5], q[8]);
	if (w != 0.0) {
		r[8] = w;
		w    = 1.0 / w;
	} else {
		mc_eye3x3(q);
		mc_eye3x3(r);
		return -1;
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

	mc_zeros3x3(r);

	w = mc_hypot3(q[0], q[3], q[6]);
	if (w != 0.0) {
		r[0] = w;
		w    = 1.0 / w;
	} else {
		mc_eye3x3(q);
		mc_eye3x3(r);
		return -1;
	}
	q[0] = q[0] * w;
	q[3] = q[3] * w;
	q[6] = q[6] * w;

	w    = q[0] * q[1] + q[3] * q[4] + q[6] * q[7];
	r[1] = w;

	q[1] = q[1] - w * q[0];
	q[4] = q[4] - w * q[3];
	q[7] = q[7] - w * q[6];

	w = mc_hypot3(q[1], q[4], q[7]);
	if (w != 0.0) {
		r[4] = w;
		w    = 1.0 / w;
	} else {
		mc_eye3x3(q);
		mc_eye3x3(r);
		return -1;
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

	w = mc_hypot3(q[2], q[5], q[8]);
	if (w != 0.0) {
		r[8] = w;
		w    = 1.0 / w;
	} else {
		mc_eye3x3(q);
		mc_eye3x3(r);
		return -1;
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

	mc_zeros3x3l(r);

	w = mc_hypot3l(q[0], q[3], q[6]);
	if (w != 0.0L) {
		r[0] = w;
		w    = 1.0L / w;
	} else {
		mc_eye3x3l(q);
		mc_eye3x3l(r);
		return -1;
	}
	q[0] = q[0] * w;
	q[3] = q[3] * w;
	q[6] = q[6] * w;

	w    = q[0] * q[1] + q[3] * q[4] + q[6] * q[7];
	r[1] = w;

	q[1] = q[1] - w * q[0];
	q[4] = q[4] - w * q[3];
	q[7] = q[7] - w * q[6];

	w = mc_hypot3l(q[1], q[4], q[7]);
	if (w != 0.0L) {
		r[4] = w;
		w    = 1.0L / w;
	} else {
		mc_eye3x3l(q);
		mc_eye3x3l(r);
		return -1;
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

	w = mc_hypot3l(q[2], q[5], q[8]);
	if (w != 0.0L) {
		r[8] = w;
		w    = 1.0L / w;
	} else {
		mc_eye3x3l(q);
		mc_eye3x3l(r);
		return -1;
	}
	q[2] = q[2] * w;
	q[5] = q[5] * w;
	q[8] = q[8] * w;

	return 0;
}

#endif /* !MC_QR3X3_H */

/* EOF */