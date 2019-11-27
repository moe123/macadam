//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_qr3x3.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_fmax.h>
#include <macadam/details/math/mc_raise2.h>
#include <macadam/details/math/mc_sqrt.h>

#ifndef MC_QR3X3_H
#define MC_QR3X3_H

#pragma mark - mc_gvrot -

MC_TARGET_PROC void mc_gvrotf(float a1, float a2, float tol, float * ch, float * sh)
{
//!# Givens rotation.
	float w;

//!# Sanity check.
	 w  = mc_sqrtf(mc_raise2f(a1) + mc_raise2f(a2));
	*sh = w > tol ? a2 : 0.0f;
	*ch = mc_fabsf(a1) + mc_fmaxf(w, tol);

//!# Sign check; -0 not handled.
	 w  = *sh;
	*sh =  a1 < 0.0f ? *ch : *sh;
	*ch =  a1 < 0.0f ?  w  : *ch;

//!# Normalizing ch and sh by r.
	 w  =  1.0f / mc_sqrtf(mc_raise2f(*ch) + mc_raise2f(*sh));
	*ch = *ch * w;
	*sh = *sh * w;
}

MC_TARGET_PROC void mc_gvrotff(float a1, float a2, float tol, double * ch, double * sh)
{
//!# Givens rotation.
	double w, a1d, a2d, told;

	a1d  = mc_cast(double, a1);
	a2d  = mc_cast(double, a2);
	told = mc_cast(double, tol);

//!# Sanity check.
	 w  = mc_sqrt(mc_raise2(a1d) + mc_raise2(a2d));
	*sh = w > told ? a2d : 0.0;
	*ch = mc_fabs(a1d) + mc_fmax(w, told);

//!# Sign check; -0 not handled.
	 w  = *sh;
	*sh =  a1d < 0.0 ? *ch : *sh;
	*ch =  a1d < 0.0 ?  w  : *ch;

//!# Normalizing ch and sh by r.
	 w  =  1.0 / mc_sqrt(mc_raise2(*ch) + mc_raise2(*sh));
	*ch = *ch * w;
	*sh = *sh * w;
}

MC_TARGET_PROC void mc_gvrot(double a1, double a2, double tol, double * ch, double * sh)
{
//!# Givens rotation.
	double w;

//!# Sanity check.
	 w  = mc_sqrt(mc_raise2(a1) + mc_raise2(a2));
	*sh = w > tol ? a2 : 0.0;
	*ch = mc_fabs(a1) + mc_fmax(w, tol);

//!# Sign check; -0 not handled.
	 w  = *sh;
	*sh =  a1 < 0.0 ? *ch : *sh;
	*ch =  a1 < 0.0 ?  w  : *ch;

//!# Normalizing ch and sh by r.
	 w  =  1.0 / mc_sqrt(mc_raise2(*ch) + mc_raise2(*sh));
	*ch = *ch * w;
	*sh = *sh * w;
}

MC_TARGET_PROC void mc_gvrotl(long double a1, long double a2, long double tol, long double * ch, long double * sh)
{
//!# Givens rotation.
	long double w;

//!# Sanity check.
	 w  = mc_sqrtl(mc_raise2l(a1) + mc_raise2l(a2));
	*sh = w > tol ? a2 : 0.0L;
	*ch = mc_fabsl(a1) + mc_fmaxl(w, tol);

//!# Sign check; -0 not handled.
	 w  = *sh;
	*sh =  a1 < 0.0L ? *ch : *sh;
	*ch =  a1 < 0.0L ?  w  : *ch;

//!# Normalizing ch and sh by r.
	 w  =  1.0L / mc_sqrtl(mc_raise2l(*ch) + mc_raise2l(*sh));
	*ch = *ch * w;
	*sh = *sh * w;
}

#pragma mark - mc_qrgv3x3 -

MC_TARGET_FUNC int mc_qrgv3x3f(const float a[9], float q[9], float r[9])
{
//!# A and Q may be the same. Using Givens rotations method.
	const float tol = 1E-06f;

	float a0, b0, ch1, sh1, ch2, sh2, ch3, sh3, sh12, sh22, sh32;

	float a11 = a[0], a12 = a[1], a13 = a[2];
	float a21 = a[3], a22 = a[4], a23 = a[5];
	float a31 = a[6], a32 = a[7], a33 = a[8];

//!# First givens rotation (ch, 0, 0, sh)
	mc_gvrotf(a11, a21, tol, &ch1, &sh1);
	a0 = 1.0f - 2.0f * sh1 * sh1;
	b0 = 2.0f        * ch1 * sh1;

//!# Computiting B=Q'*B
	r[0] =  a0 * a11 + b0 * a21; r[1] =  a0 * a12 + b0 * a22; r[2] =  a0 * a13 + b0 * a23;
	r[3] = -b0 * a11 + a0 * a21; r[4] = -b0 * a12 + a0 * a22; r[5] = -b0 * a13 + a0 * a23;
	r[6] =  a31;                 r[7] =  a32;                 r[8] =  a33;

//!# Second givens rotation (ch, 0, -sh, 0)
	mc_gvrotf(r[0], r[6], tol, &ch2, &sh2);
	a0 = 1.0f - 2.0f * sh2 * sh2;
	b0 = 2.0f        * ch2 * sh2;

//!# Computiting B=Q'*B
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
	const double tol = 1E-15;

	double a0, b0, ch1, sh1, ch2, sh2, ch3, sh3, sh12, sh22, sh32;

	double a11 = mc_cast(double, a[0]), a12 = mc_cast(double, a[1]), a13 = mc_cast(double, a[2]);
	double a21 = mc_cast(double, a[3]), a22 = mc_cast(double, a[4]), a23 = mc_cast(double, a[5]);
	double a31 = mc_cast(double, a[6]), a32 = mc_cast(double, a[7]), a33 = mc_cast(double, a[8]);

//!# First givens rotation (ch, 0, 0, sh)
	mc_gvrot(a11, a21, tol, &ch1, &sh1);
	a0 = 1.0 - 2.0 * sh1 * sh1;
	b0 = 2.0       * ch1 * sh1;

//!# Computiting B=Q'*B
	r[0] =  a0 * a11 + b0 * a21; r[1] =  a0 * a12 + b0 * a22; r[2] =  a0 * a13 + b0 * a23;
	r[3] = -b0 * a11 + a0 * a21; r[4] = -b0 * a12 + a0 * a22; r[5] = -b0 * a13 + a0 * a23;
	r[6] =  a31;                 r[7] =  a32;                 r[8] =  a33;

//!# Second givens rotation (ch, 0, -sh, 0)
	mc_gvrot(r[0], r[6], tol, &ch2, &sh2);
	a0 = 1.0 - 2.0 * sh2 * sh2;
	b0 = 2.0       * ch2 * sh2;

//!# Computiting B=Q'*B
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
	const double tol = 1E-15;

	double a0, b0, ch1, sh1, ch2, sh2, ch3, sh3, sh12, sh22, sh32;

	double a11 = a[0], a12 = a[1], a13 = a[2];
	double a21 = a[3], a22 = a[4], a23 = a[5];
	double a31 = a[6], a32 = a[7], a33 = a[8];

//!# First givens rotation (ch, 0, 0, sh)
	mc_gvrot(a11, a21, tol, &ch1, &sh1);
	a0 = 1.0 - 2.0 * sh1 * sh1;
	b0 = 2.0       * ch1 * sh1;

//!# Computiting B=Q'*B
	r[0] =  a0 * a11 + b0 * a21; r[1] =  a0 * a12 + b0 * a22; r[2] =  a0 * a13 + b0 * a23;
	r[3] = -b0 * a11 + a0 * a21; r[4] = -b0 * a12 + a0 * a22; r[5] = -b0 * a13 + a0 * a23;
	r[6] =  a31;                 r[7] =  a32;                 r[8] =  a33;

//!# Second givens rotation (ch, 0, -sh, 0)
	mc_gvrot(r[0], r[6], tol, &ch2, &sh2);
	a0 = 1.0 - 2.0 * sh2 * sh2;
	b0 = 2.0       * ch2 * sh2;

//!# Computiting B=Q'*B
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
	const long double tol = 1E-30L;

	long double a0, b0, ch1, sh1, ch2, sh2, ch3, sh3, sh12, sh22, sh32;

	long double a11 = a[0], a12 = a[1], a13 = a[2];
	long double a21 = a[3], a22 = a[4], a23 = a[5];
	long double a31 = a[6], a32 = a[7], a33 = a[8];

//!# First givens rotation (ch, 0, 0, sh)
	mc_gvrotl(a11, a21, tol, &ch1, &sh1);
	a0 = 1.0L - 2.0L * sh1 * sh1;
	b0 = 2.0L        * ch1 * sh1;

//!# Computiting B=Q'*B
	r[0] =  a0 * a11 + b0 * a21; r[1] =  a0 * a12 + b0 * a22; r[2] =  a0 * a13 + b0 * a23;
	r[3] = -b0 * a11 + a0 * a21; r[4] = -b0 * a12 + a0 * a22; r[5] = -b0 * a13 + a0 * a23;
	r[6] =  a31;                 r[7] =  a32;                 r[8] =  a33;

//!# Second givens rotation (ch, 0, -sh, 0)
	mc_gvrotl(r[0], r[6], tol, &ch2, &sh2);
	a0 = 1.0L - 2.0L * sh2 * sh2;
	b0 = 2.0L        * ch2 * sh2;

//!# Computiting B=Q'*B
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

#pragma mark - mc_qrhh3x3 -

MC_TARGET_FUNC int mc_qrhh3x3f(const float a[9], float q[9], float r[9])
{
//!# A and Q may be the same. Using Householder reflections method.
	float a11 = a[0], a12 = a[1], a13 = a[2];
	float a21 = a[3], a22 = a[4], a23 = a[5];
	float a31 = a[6], a32 = a[7], a33 = a[8];

	float e111, e112, e113;
	float e121, e122, e123;
	float e131, e132, e133;

	float e211, e212, e213;
	float e221, e222, e223;
	float e231, e232, e233;

	float e1a11, e1a12, e1a13;
	float e1a21, e1a22, e1a23;
	float e1a31, e1a32, e1a33;

	float x0, x1, x2;
	float u0, u1, u2;
	float v0, v1, v2;

	float magx, magu, alpha;

//!# HH Step 1: computing Q1=I-2vvT.
	x0    = a11;
	x1    = a21;
	x2    = a31;
	magx  = mc_raise2f(x0) + mc_raise2f(x1) + mc_raise2f(x2);
	if (magx > 0.0f) {
		magx = mc_sqrtf(magx);
	}
	alpha = magx * -1.0f * ((x0 > 0.0f) ? -1.0f : (x0 < 0.0f) ? 1.0f : 0.0f);
	u0    = x0 + alpha;
	u1    = x1;
	u2    = x2;

	magu  = mc_raise2f(u0) + mc_raise2f(u1) + mc_raise2f(u2);
	if (magu > 0.0f) {
		magu = 1.0f / mc_sqrtf(magu);
	}
	v0    = u0 * magu;
	v1    = u1 * magu;
	v2    = u2 * magu;

	e111  =  1.0f - 2.0f * v0 * v0; e112 = -2.0f * v0 * v1;        e113 = -2.0f * v0 * v2;
	e121  = -2.0f * v0 * v1;        e122 =  1.0f - 2.0f * v1 * v1; e123 = -2.0f * v1 * v2;
	e131  = -2.0f * v0 * v2;        e132 = -2.0f * v1 * v2;        e133 =  1.0f - 2.0f * v2 * v2;

//!# Computing e1a=e1*a.
	e1a11 = e111 * a11 + e112 * a21 + e113 * a31;
	e1a12 = e111 * a12 + e112 * a22 + e113 * a32;
	e1a13 = e111 * a13 + e112 * a23 + e113 * a33;

	e1a21 = e121 * a11 + e122 * a21 + e123 * a31;
	e1a22 = e121 * a12 + e122 * a22 + e123 * a32;
	e1a23 = e121 * a13 + e122 * a23 + e123 * a33;

	e1a31 = e131 * a11 + e132 * a21 + e133 * a31;
	e1a32 = e131 * a12 + e132 * a22 + e133 * a32;
	e1a33 = e131 * a13 + e132 * a23 + e133 * a33;

//!# HH Step 2: computing Q2=I-2vvT.
	x0    = a22;
	x1    = a32;
	magx  = mc_raise2f(x0) + mc_raise2f(x1);
	if (magx > 0.0f) {
		magx = mc_sqrtf(magx);
	}
	alpha = magx * -1.0f * ((x0 > 0.0f) ? -1.0f : (x0 < 0.0f) ? 1.0f : 0.0f);
	u0    = x0 + alpha;
	u1    = x1;

	magu  = mc_raise2f(u0) + mc_raise2f(u1);
	if (magu > 0.0f) {
		magu = 1.0f / mc_sqrtf(magu);
	}
	v0    = u0 * magu;
	v1    = u1 * magu;

//!# Computing e2.
	e211  = 1.0f; e212 =  0.0f;                  e213 =  0.0f;
	e221  = 0.0f; e222 =  1.0f - 2.0f * v0 * v0; e223 = -2.0f * v0 * v1;
	e231  = 0.0f; e232 = -2.0f * v0 * v1;        e233 =  1.0f - 2.0f * v1 * v1;

//!# HH Step 3: computing Q and R.

//!# Computing R such as R=e2*e1a.
	r[0]  = e211 * e1a11 + e212 * e1a21 + e213 * e1a31;
	r[1]  = e211 * e1a12 + e212 * e1a22 + e213 * e1a32;
	r[2]  = e211 * e1a13 + e212 * e1a23 + e213 * e1a33;

	r[3]  = e221 * e1a11 + e222 * e1a21 + e223 * e1a31;
	r[4]  = e221 * e1a12 + e222 * e1a22 + e223 * e1a32;
	r[5]  = e221 * e1a13 + e222 * e1a23 + e223 * e1a33;

	r[6]  = e231 * e1a11 + e232 * e1a21 + e233 * e1a31;
	r[7]  = e231 * e1a12 + e232 * e1a22 + e233 * e1a32;
	r[8]  = e231 * e1a13 + e232 * e1a23 + e233 * e1a33;

//!# Computing Q such as Q=e1'*e2'=(e1*e2)'.
	q[0]  = e111 * e211 + e121 * e212 + e131 * e213;
	q[1]  = e111 * e221 + e121 * e222 + e131 * e223;
	q[2]  = e111 * e231 + e121 * e232 + e131 * e233;

	q[3]  = e112 * e211 + e122 * e212 + e132 * e213;
	q[4]  = e112 * e221 + e122 * e222 + e132 * e223;
	q[5]  = e112 * e231 + e122 * e232 + e132 * e233;

	q[6]  = e113 * e211 + e123 * e212 + e133 * e213;
	q[7]  = e113 * e221 + e123 * e222 + e133 * e223;
	q[8]  = e113 * e231 + e123 * e232 + e133 * e233;

	return 0;
}

MC_TARGET_FUNC int mc_qrhh3x3ff(const float a[9], double q[9], double r[9])
{
//!# Using Householder reflections method.
	double a11 = mc_cast(double, a[0]), a12 = mc_cast(double, a[1]), a13 = mc_cast(double, a[2]);
	double a21 = mc_cast(double, a[3]), a22 = mc_cast(double, a[4]), a23 = mc_cast(double, a[5]);
	double a31 = mc_cast(double, a[6]), a32 = mc_cast(double, a[7]), a33 = mc_cast(double, a[8]);

	double e111, e112, e113;
	double e121, e122, e123;
	double e131, e132, e133;

	double e211, e212, e213;
	double e221, e222, e223;
	double e231, e232, e233;

	double e1a11, e1a12, e1a13;
	double e1a21, e1a22, e1a23;
	double e1a31, e1a32, e1a33;

	double x0, x1, x2;
	double u0, u1, u2;
	double v0, v1, v2;

	double magx, magu, alpha;

//!# HH Step 1: computing Q1=I-2vvT.
	x0    = a11;
	x1    = a21;
	x2    = a31;
	magx  = mc_raise2(x0) + mc_raise2(x1) + mc_raise2(x2);
	if (magx > 0.0) {
		magx = mc_sqrt(magx);
	}
	alpha = magx * -1.0 * ((x0 > 0.0) ? -1.0 : (x0 < 0.0) ? 1.0 : 0.0);
	u0    = x0 + alpha;
	u1    = x1;
	u2    = x2;

	magu  = mc_raise2(u0) + mc_raise2(u1) + mc_raise2(u2);
	if (magu > 0.0) {
		magu = 1.0 / mc_sqrt(magu);
	}
	v0    = u0 * magu;
	v1    = u1 * magu;
	v2    = u2 * magu;

	e111  =  1.0 - 2.0 * v0 * v0; e112 = -2.0 * v0 * v1;       e113 = -2.0 * v0 * v2;
	e121  = -2.0 * v0 * v1;       e122 =  1.0 - 2.0 * v1 * v1; e123 = -2.0 * v1 * v2;
	e131  = -2.0 * v0 * v2;       e132 = -2.0 * v1 * v2;       e133 =  1.0 - 2.0 * v2 * v2;

//!# Computing e1a=e1*a.
	e1a11 = e111 * a11 + e112 * a21 + e113 * a31;
	e1a12 = e111 * a12 + e112 * a22 + e113 * a32;
	e1a13 = e111 * a13 + e112 * a23 + e113 * a33;

	e1a21 = e121 * a11 + e122 * a21 + e123 * a31;
	e1a22 = e121 * a12 + e122 * a22 + e123 * a32;
	e1a23 = e121 * a13 + e122 * a23 + e123 * a33;

	e1a31 = e131 * a11 + e132 * a21 + e133 * a31;
	e1a32 = e131 * a12 + e132 * a22 + e133 * a32;
	e1a33 = e131 * a13 + e132 * a23 + e133 * a33;

//!# HH Step 2: computing Q2=I-2vvT.
	x0    = a22;
	x1    = a32;
	magx  = mc_raise2(x0) + mc_raise2(x1);
	if (magx > 0.0) {
		magx = mc_sqrt(magx);
	}
	alpha = magx * -1.0 * ((x0 > 0.0) ? -1.0 : (x0 < 0.0) ? 1.0 : 0.0);
	u0    = x0 + alpha;
	u1    = x1;

	magu  = mc_raise2(u0) + mc_raise2(u1);
	if (magu > 0.0) {
		magu = 1.0 / mc_sqrt(magu);
	}
	v0    = u0 * magu;
	v1    = u1 * magu;

//!# Computing e2.
	e211  = 1.0; e212 =  0.0;                 e213 =  0.0;
	e221  = 0.0; e222 =  1.0 - 2.0 * v0 * v0; e223 = -2.0 * v0 * v1;
	e231  = 0.0; e232 = -2.0 * v0 * v1;       e233 =  1.0 - 2.0 * v1 * v1;

//!# HH Step 3: computing Q and R.

//!# Computing R such as R=e2*e1a.
	r[0]  = e211 * e1a11 + e212 * e1a21 + e213 * e1a31;
	r[1]  = e211 * e1a12 + e212 * e1a22 + e213 * e1a32;
	r[2]  = e211 * e1a13 + e212 * e1a23 + e213 * e1a33;

	r[3]  = e221 * e1a11 + e222 * e1a21 + e223 * e1a31;
	r[4]  = e221 * e1a12 + e222 * e1a22 + e223 * e1a32;
	r[5]  = e221 * e1a13 + e222 * e1a23 + e223 * e1a33;

	r[6]  = e231 * e1a11 + e232 * e1a21 + e233 * e1a31;
	r[7]  = e231 * e1a12 + e232 * e1a22 + e233 * e1a32;
	r[8]  = e231 * e1a13 + e232 * e1a23 + e233 * e1a33;

//!# Computing Q such as Q=e1'*e2'=(e1*e2)'.
	q[0]  = e111 * e211 + e121 * e212 + e131 * e213;
	q[1]  = e111 * e221 + e121 * e222 + e131 * e223;
	q[2]  = e111 * e231 + e121 * e232 + e131 * e233;

	q[3]  = e112 * e211 + e122 * e212 + e132 * e213;
	q[4]  = e112 * e221 + e122 * e222 + e132 * e223;
	q[5]  = e112 * e231 + e122 * e232 + e132 * e233;

	q[6]  = e113 * e211 + e123 * e212 + e133 * e213;
	q[7]  = e113 * e221 + e123 * e222 + e133 * e223;
	q[8]  = e113 * e231 + e123 * e232 + e133 * e233;

	return 0;
}

MC_TARGET_FUNC int mc_qrhh3x3(const double a[9], double q[9], double r[9])
{
//!# A and Q may be the same. Using Householder reflections method.
	double a11 = a[0], a12 = a[1], a13 = a[2];
	double a21 = a[3], a22 = a[4], a23 = a[5];
	double a31 = a[6], a32 = a[7], a33 = a[8];

	double e111, e112, e113;
	double e121, e122, e123;
	double e131, e132, e133;

	double e211, e212, e213;
	double e221, e222, e223;
	double e231, e232, e233;

	double e1a11, e1a12, e1a13;
	double e1a21, e1a22, e1a23;
	double e1a31, e1a32, e1a33;

	double x0, x1, x2;
	double u0, u1, u2;
	double v0, v1, v2;

	double magx, magu, alpha;

//!# HH Step 1: computing Q1=I-2vvT.
	x0    = a11;
	x1    = a21;
	x2    = a31;
	magx  = mc_raise2(x0) + mc_raise2(x1) + mc_raise2(x2);
	if (magx > 0.0) {
		magx = mc_sqrt(magx);
	}
	alpha = magx * -1.0 * ((x0 > 0.0) ? -1.0 : (x0 < 0.0) ? 1.0 : 0.0);
	u0    = x0 + alpha;
	u1    = x1;
	u2    = x2;

	magu  = mc_raise2(u0) + mc_raise2(u1) + mc_raise2(u2);
	if (magu > 0.0) {
		magu = 1.0 / mc_sqrt(magu);
	}
	v0    = u0 * magu;
	v1    = u1 * magu;
	v2    = u2 * magu;

	e111  =  1.0 - 2.0 * v0 * v0; e112 = -2.0 * v0 * v1;       e113 = -2.0 * v0 * v2;
	e121  = -2.0 * v0 * v1;       e122 =  1.0 - 2.0 * v1 * v1; e123 = -2.0 * v1 * v2;
	e131  = -2.0 * v0 * v2;       e132 = -2.0 * v1 * v2;       e133 =  1.0 - 2.0 * v2 * v2;

//!# Computing e1a=e1*a.
	e1a11 = e111 * a11 + e112 * a21 + e113 * a31;
	e1a12 = e111 * a12 + e112 * a22 + e113 * a32;
	e1a13 = e111 * a13 + e112 * a23 + e113 * a33;

	e1a21 = e121 * a11 + e122 * a21 + e123 * a31;
	e1a22 = e121 * a12 + e122 * a22 + e123 * a32;
	e1a23 = e121 * a13 + e122 * a23 + e123 * a33;

	e1a31 = e131 * a11 + e132 * a21 + e133 * a31;
	e1a32 = e131 * a12 + e132 * a22 + e133 * a32;
	e1a33 = e131 * a13 + e132 * a23 + e133 * a33;

//!# HH Step 2: computing Q2=I-2vvT.
	x0    = a22;
	x1    = a32;
	magx  = mc_raise2(x0) + mc_raise2(x1);
	if (magx > 0.0) {
		magx = mc_sqrt(magx);
	}
	alpha = magx * -1.0 * ((x0 > 0.0) ? -1.0 : (x0 < 0.0) ? 1.0 : 0.0);
	u0    = x0 + alpha;
	u1    = x1;

	magu  = mc_raise2(u0) + mc_raise2(u1);
	if (magu > 0.0) {
		magu = 1.0 / mc_sqrt(magu);
	}
	v0    = u0 * magu;
	v1    = u1 * magu;

//!# Computing e2.
	e211  = 1.0; e212 =  0.0;                 e213 =  0.0;
	e221  = 0.0; e222 =  1.0 - 2.0 * v0 * v0; e223 = -2.0 * v0 * v1;
	e231  = 0.0; e232 = -2.0 * v0 * v1;       e233 =  1.0 - 2.0 * v1 * v1;

//!# HH Step 3: computing Q and R.

//!# Computing R such as R=e2*e1a.
	r[0]  = e211 * e1a11 + e212 * e1a21 + e213 * e1a31;
	r[1]  = e211 * e1a12 + e212 * e1a22 + e213 * e1a32;
	r[2]  = e211 * e1a13 + e212 * e1a23 + e213 * e1a33;

	r[3]  = e221 * e1a11 + e222 * e1a21 + e223 * e1a31;
	r[4]  = e221 * e1a12 + e222 * e1a22 + e223 * e1a32;
	r[5]  = e221 * e1a13 + e222 * e1a23 + e223 * e1a33;

	r[6]  = e231 * e1a11 + e232 * e1a21 + e233 * e1a31;
	r[7]  = e231 * e1a12 + e232 * e1a22 + e233 * e1a32;
	r[8]  = e231 * e1a13 + e232 * e1a23 + e233 * e1a33;

//!# Computing Q such as Q=e1'*e2'=(e1*e2)'.
	q[0]  = e111 * e211 + e121 * e212 + e131 * e213;
	q[1]  = e111 * e221 + e121 * e222 + e131 * e223;
	q[2]  = e111 * e231 + e121 * e232 + e131 * e233;

	q[3]  = e112 * e211 + e122 * e212 + e132 * e213;
	q[4]  = e112 * e221 + e122 * e222 + e132 * e223;
	q[5]  = e112 * e231 + e122 * e232 + e132 * e233;

	q[6]  = e113 * e211 + e123 * e212 + e133 * e213;
	q[7]  = e113 * e221 + e123 * e222 + e133 * e223;
	q[8]  = e113 * e231 + e123 * e232 + e133 * e233;

	return 0;
}

MC_TARGET_FUNC int mc_qrhh3x3l(const long double a[9], long double q[9], long double r[9])
{
//!# A and Q may be the same. Using Householder reflections method.
	long double a11 = a[0], a12 = a[1], a13 = a[2];
	long double a21 = a[3], a22 = a[4], a23 = a[5];
	long double a31 = a[6], a32 = a[7], a33 = a[8];

	long double e111, e112, e113;
	long double e121, e122, e123;
	long double e131, e132, e133;

	long double e211, e212, e213;
	long double e221, e222, e223;
	long double e231, e232, e233;

	long double e1a11, e1a12, e1a13;
	long double e1a21, e1a22, e1a23;
	long double e1a31, e1a32, e1a33;

	long double x0, x1, x2;
	long double u0, u1, u2;
	long double v0, v1, v2;

	long double magx, magu, alpha;

//!# HH Step 1: computing Q1=I-2vvT.
	x0    = a11;
	x1    = a21;
	x2    = a31;
	magx  = mc_raise2l(x0) + mc_raise2l(x1) + mc_raise2l(x2);
	if (magx > 0.0L) {
		magx = mc_sqrtl(magx);
	}
	alpha = magx * -1.0L * ((x0 > 0.0L) ? -1.0L : (x0 < 0.0L) ? 1.0L : 0.0L);
	u0    = x0 + alpha;
	u1    = x1;
	u2    = x2;

	magu  = mc_raise2l(u0) + mc_raise2l(u1) + mc_raise2l(u2);
	if (magu > 0.0L) {
		magu = 1.0L / mc_sqrtl(magu);
	}
	v0    = u0 * magu;
	v1    = u1 * magu;
	v2    = u2 * magu;

	e111  =  1.0L - 2.0L * v0 * v0; e112 = -2.0L * v0 * v1;        e113 = -2.0L * v0 * v2;
	e121  = -2.0L * v0 * v1;        e122 =  1.0L - 2.0L * v1 * v1; e123 = -2.0L * v1 * v2;
	e131  = -2.0L * v0 * v2;        e132 = -2.0L * v1 * v2;        e133 =  1.0L - 2.0L * v2 * v2;

//!# Computing e1a=e1*a.
	e1a11 = e111 * a11 + e112 * a21 + e113 * a31;
	e1a12 = e111 * a12 + e112 * a22 + e113 * a32;
	e1a13 = e111 * a13 + e112 * a23 + e113 * a33;

	e1a21 = e121 * a11 + e122 * a21 + e123 * a31;
	e1a22 = e121 * a12 + e122 * a22 + e123 * a32;
	e1a23 = e121 * a13 + e122 * a23 + e123 * a33;

	e1a31 = e131 * a11 + e132 * a21 + e133 * a31;
	e1a32 = e131 * a12 + e132 * a22 + e133 * a32;
	e1a33 = e131 * a13 + e132 * a23 + e133 * a33;

//!# HH Step 2: computing Q2=I-2vvT.
	x0    = a22;
	x1    = a32;
	magx  = mc_raise2l(x0) + mc_raise2l(x1);
	if (magx > 0.0L) {
		magx = mc_sqrtl(magx);
	}
	alpha = magx * -1.0L * ((x0 > 0.0L) ? -1.0L : (x0 < 0.0L) ? 1.0L : 0.0L);
	u0    = x0 + alpha;
	u1    = x1;

	magu  = mc_raise2l(u0) + mc_raise2l(u1);
	if (magu > 0.0L) {
		magu = 1.0L / mc_sqrtl(magu);
	}
	v0    = u0 * magu;
	v1    = u1 * magu;

//!# Computing e2.
	e211  = 1.0L; e212 =  0.0L;                  e213 =  0.0L;
	e221  = 0.0L; e222 =  1.0L - 2.0L * v0 * v0; e223 = -2.0L * v0 * v1;
	e231  = 0.0L; e232 = -2.0L * v0 * v1;        e233 =  1.0L - 2.0L * v1 * v1;

//!# HH Step 3: computing Q and R.

//!# Computing R such as R=e2*e1a.
	r[0]  = e211 * e1a11 + e212 * e1a21 + e213 * e1a31;
	r[1]  = e211 * e1a12 + e212 * e1a22 + e213 * e1a32;
	r[2]  = e211 * e1a13 + e212 * e1a23 + e213 * e1a33;

	r[3]  = e221 * e1a11 + e222 * e1a21 + e223 * e1a31;
	r[4]  = e221 * e1a12 + e222 * e1a22 + e223 * e1a32;
	r[5]  = e221 * e1a13 + e222 * e1a23 + e223 * e1a33;

	r[6]  = e231 * e1a11 + e232 * e1a21 + e233 * e1a31;
	r[7]  = e231 * e1a12 + e232 * e1a22 + e233 * e1a32;
	r[8]  = e231 * e1a13 + e232 * e1a23 + e233 * e1a33;

//!# Computing Q such as Q=e1'*e2'=(e1*e2)'.
	q[0]  = e111 * e211 + e121 * e212 + e131 * e213;
	q[1]  = e111 * e221 + e121 * e222 + e131 * e223;
	q[2]  = e111 * e231 + e121 * e232 + e131 * e233;

	q[3]  = e112 * e211 + e122 * e212 + e132 * e213;
	q[4]  = e112 * e221 + e122 * e222 + e132 * e223;
	q[5]  = e112 * e231 + e122 * e232 + e132 * e233;

	q[6]  = e113 * e211 + e123 * e212 + e133 * e213;
	q[7]  = e113 * e221 + e123 * e222 + e133 * e223;
	q[8]  = e113 * e231 + e123 * e232 + e133 * e233;

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