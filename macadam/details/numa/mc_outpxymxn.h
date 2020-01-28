//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_outpxymxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_zerosmxn.h>

#ifndef MC_OUTPXYMXN_H
#define MC_OUTPXYMXN_H

#pragma mark - mc_outpxymxn -

MC_TARGET_FUNC void mc_outpxymxnf(int m, int n, float * a, const float * x, const float * y)
{
//!# Requires a[m x n], x[m x 1] and y[n x 1].
//!# c=x*y' i.e outer product of two vectors.
#	if !MC_TARGET_EMBEDDED && MCTARGET_BLAS_USE_CLAYOUT

	const int mm      = m;
	const int nn      = n;
	const int lda     = m;
	const int incx    = 1;
	const int incy    = 1;
	const float alpha = 1.0f;

	mc_zerosmxnf(m, n, a);
	mc_blas_sger(mm, nn, alpha, x, incx, y, incy, a, lda);
#	else
	int j = 0, i;
	float v, e, w;
	for (; j < n; j++) {
		w = y[j];
		for (i = 0; i < m; i++) {
			mc_twoproductf(x[i], w, &v, &e);
			a[(n * i) + j] = v + e;
		}
	}
#	endif
}

MC_TARGET_FUNC void mc_outpxymxnff(int m, int n, double * a, const float * x, const float * y)
{
//!# Requires a[m x n], x[m x 1] and y[n x 1].
//!# c=x*y' i.e outer product of two vectors.
	int j = 0, i;
	double v, e, w;
	for (; j < n; j++) {
		w = mc_cast(double, y[j]);
		for (i = 0; i < m; i++) {
			mc_twoproduct(mc_cast(double, x[i]), w, &v, &e);
			a[(n * i) + j] = v + e;
		}
	}
}

MC_TARGET_FUNC void mc_outpxymxnfd(int m, int n, double * a, const float * x, const double * y)
{
//!# Requires a[m x n], x[m x 1] and y[n x 1].
//!# c=x*y' i.e outer product of two vectors.
	int j = 0, i;
	double v, e, w;
	for (; j < n; j++) {
		w = y[j];
		for (i = 0; i < m; i++) {
			mc_twoproduct(mc_cast(double, x[i]), w, &v, &e);
			a[(n * i) + j] = v + e;
		}
	}
}

MC_TARGET_FUNC void mc_outpxymxndf(int m, int n, double * a, const double * x, const float * y)
{
//!# Requires a[m x n], x[m x 1] and y[n x 1].
//!# c=x*y' i.e outer product of two vectors.
	int j = 0, i;
	double v, e, w;
	for (; j < n; j++) {
		w = mc_cast(double, y[j]);
		for (i = 0; i < m; i++) {
			mc_twoproduct(x[i], w, &v, &e);
			a[(n * i) + j] = v + e;
		}
	}
}

MC_TARGET_FUNC void mc_outpxymxn(int m, int n, double * a, const double * x, const double * y)
{
//!# Requires a[m x n], x[m x 1] and y[n x 1].
//!# c=x*y' i.e outer product of two vectors.
#	if !MC_TARGET_EMBEDDED && MCTARGET_BLAS_USE_CLAYOUT

	const int mm       = m;
	const int nn       = n;
	const int lda      = m;
	const int incx     = 1;
	const int incy     = 1;
	const double alpha = 1.0;

	mc_zerosmxn(m, n, a);
	mc_blas_dger(mm, nn, alpha, x, incx, y, incy, a, lda);
#	else
	int j = 0, i;
	double v, e, w;
	for (; j < n; j++) {
		w = y[j];
		for (i = 0; i < m; i++) {
			mc_twoproduct(x[i], w, &v, &e);
			a[(n * i) + j] = v + e;
		}
	}
#	endif
}

MC_TARGET_FUNC void mc_outpxymxnl(int m, int n, long double * a, const long double * x, const long double * y)
{
//!# Requires a[m x n], x[m x 1] and y[n x 1].
//!# c=x*y' i.e outer product of two vectors.
#	if !MC_TARGET_EMBEDDED && MCTARGET_BLAS_USE_CLAYOUT

	const int mm            = m;
	const int nn            = n;
	const int lda           = m;
	const int incx          = 1;
	const int incy          = 1;
	const long double alpha = 1.0L;

	mc_zerosmxnl(m, n, a);
	mc_blas_lger(mm, nn, alpha, x, incx, y, incy, a, lda);
#	else
	int j = 0, i;
	long double v, e, w;
	for (; j < n; j++) {
		w = y[j];
		for (i = 0; i < m; i++) {
			mc_twoproductl(x[i], w, &v, &e);
			a[(n * i) + j] = v + e;
		}
	}
#	endif
}

#endif /* !MC_OUTPXYMXN_H */

/* EOF */