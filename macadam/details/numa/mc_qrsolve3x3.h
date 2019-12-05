//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_qrsolve3x3.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_mulatx3x3.h>
#include <macadam/details/numa/mc_triusolve3x3.h>

#ifndef MC_QRSOLVE3X3_H
#define MC_QRSOLVE3X3_H

#pragma mark - mc_qrsolve3x3 -

MC_TARGET_FUNC int mc_qrsolve3x3f(const float q[9], const float r[9], const float d[9], const float p[9], const int pvi[3], const float b[3], float x[3]) 
{
//!# Solving linear system Ax=b for QR family factorization.
//!# lu[m x n], d[m x n], p[m x n], pvi[m x 1] x[m x 1] and b[m x 1] where m=n=3.
//!# d and p can be null; for now d should always be, obviously null.
//!# Accepting a permutation matrix or a pivot indeces vector. Pass null accordingly.

	mc_cast(void, pvi);
	mc_cast(void, p);
	mc_cast(void, d);

	mc_mulatx3x3f(x, q, b);
	return mc_triusolve3x3f(r, x, x);
}

MC_TARGET_FUNC int mc_qrsolve3x3ff(const float q[9], const float r[9], const float d[9], const float p[9], const int pvi[3], const float b[3], double x[3]) 
{
//!# Solving linear system Ax=b for QR family factorization.
//!# lu[m x n], d[m x n], p[m x n], pvi[m x 1] x[m x 1] and b[m x 1] where m=n=3.
//!# d and p can be null; for now d should always be, obviously null.
//!# Accepting a permutation matrix or a pivot indeces vector. Pass null accordingly.
	double w;

	mc_cast(void, pvi);
	mc_cast(void, p);
	mc_cast(void, d);

//!# Computing d=Q'*b, storing d into x vector.
	x[0] = mc_cast(double, q[0]) * mc_cast(double, b[0]);
	x[0] = x[0] + (mc_cast(double, q[3]) * mc_cast(double, b[1]));
	x[0] = x[0] + (mc_cast(double, q[6]) * mc_cast(double, b[2]));

	x[1] = mc_cast(double, q[1]) * mc_cast(double, b[0]);
	x[1] = x[1] + (mc_cast(double, q[4]) * mc_cast(double, b[1]));
	x[1] = x[1] + (mc_cast(double, q[7]) * mc_cast(double, b[2]));

	x[2] = mc_cast(double, q[2]) * mc_cast(double, b[0]);
	x[2] = x[2] + (mc_cast(double, q[5]) * mc_cast(double, b[1]));
	x[2] = x[2] + (mc_cast(double, q[8]) * mc_cast(double, b[2]));

//!# Solving Rx=d.
	w = mc_cast(double, r[8]);
	if (w == 0.0) {
		mc_zeros1x3(x);
		return -1;
	}
	x[2] = x[2] / w;
	x[0] = x[0] - x[2] * mc_cast(double, r[2]);
	x[1] = x[1] - x[2] * mc_cast(double, r[5]);

	w    = mc_cast(double, r[4]);
	x[1] = x[1] / w;
	x[0] = x[0] - x[1] * mc_cast(double, r[1]);

	w = mc_cast(double, r[0]);
	if (w == 0.0) {
		mc_zeros1x3(x);
		return -1;
	}
	x[0] = x[0] / w;

	return 0;
}

MC_TARGET_FUNC int mc_qrsolve3x3(const double q[9], const double r[9], const double d[9], const double p[9], const int pvi[3], const double b[3], double x[3]) 
{
//!# Solving linear system Ax=b for LU family factorization.
//!# lu[m x n], d[m x n], p[m x n], pvi[m x 1] x[m x 1] and b[m x 1] where m=n=3.
//!# d and p can be null; for now d should always be, obviously null.
//!# Accepting a permutation matrix or a pivot indeces vector. Pass null accordingly.

	mc_cast(void, pvi);
	mc_cast(void, p);
	mc_cast(void, d);

	mc_mulatx3x3(x, q, b);
	return mc_triusolve3x3(r, x, x);
}

MC_TARGET_FUNC int mc_qrsolve3x3l(const long double q[9], const long double r[9], const long double d[9], const long double p[9], const int pvi[3], const long double b[3], long double x[3]) 
{
//!# Solving linear system Ax=b for LU family factorization.
//!# lu[m x n], d[m x n], p[m x n], pvi[m x 1] x[m x 1] and b[m x 1] where m=n=3.
//!# d and p can be null; for now d should always be, obviously null.
//!# Accepting a permutation matrix or a pivot indeces vector. Pass null accordingly.

	mc_cast(void, pvi);
	mc_cast(void, p);
	mc_cast(void, d);

	mc_mulatx3x3l(x, q, b);
	return mc_triusolve3x3l(r, x, x);
}

#endif /* !MC_QRSOLVE3X3_H */

/* EOF */