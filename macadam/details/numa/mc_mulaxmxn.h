//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_mulaxmxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/lapack/blas/mc_blas_gemv.h>

#ifndef MC_MULAXMXN_H
#define MC_MULAXMXN_H

#pragma mark - mc_mulaxmxn -

MC_TARGET_FUNC void mc_mulaxmxnf(int m, int n, float * restrict b, const float * a, const float * x)
{
//!# Requires b[m x 1], a[m * n] and x[n x 1].
//!# b=a*x
#	if MCTARGET_BLAS_USE_CLAYOUT

	const int mm      = m;
	const int nn      = n;
	const int lda     = m;
	const int incx    = 1;
	const int incy    = 1;
	const float alpha = 1.0f;
	const float beta  = 0.0f;

	mc_blas_sgemv('N', mm, nn, alpha, a, lda, x, incx, beta, b, incy);
#	else
	int i, j = 0;
	mc_zeros1xnf(m, b);
	for (j = 0; j < n; j++) {
		const float w = x[j];
		for (i = 0; i < m; i++) {
			b[i] = b[i] + (w * a[(n * i) + j]);
		}
	}
#	endif
}

MC_TARGET_FUNC void mc_mulaxmxnff(int m, int n, double * restrict b, const float * a, const float * x)
{
//!# Requires b[m x 1], a[m * n] and x[n x 1].
//!# b=a*x
	int i, j = 0;
	mc_zeros1xn(m, b);
	for (j = 0; j < n; j++) {
		const double w = mc_cast(double, x[j]);
		for (i = 0; i < m; i++) {
			b[i] = b[i] + (w * mc_cast(double, a[(n * i) + j]));
		}
	}
}

MC_TARGET_FUNC void mc_mulaxmxnfd(int m, int n, double * restrict b, const float * a, const double * x)
{
//!# Requires b[m x 1], a[m * n] and x[n x 1].
//!# b=a*x
	int i, j = 0;
	mc_zeros1xn(m, b);
	for (j = 0; j < n; j++) {
		const double w = x[j];
		for (i = 0; i < m; i++) {
			b[i] = b[i] + (w * mc_cast(double, a[(n * i) + j]));
		}
	}
}

MC_TARGET_FUNC void mc_mulaxmxndf(int m, int n, double * restrict b, const double * a, const float * x)
{
//!# Requires b[m x 1], a[m * n] and x[n x 1].
//!# b=a*x
	int i, j = 0;
	mc_zeros1xn(m, b);
	for (j = 0; j < n; j++) {
		const double w = mc_cast(double, x[j]);
		for (i = 0; i < m; i++) {
			b[i] = b[i] + (w * a[(n * i) + j]);
		}
	}
}

MC_TARGET_FUNC void mc_mulaxmxn(int m, int n, double * restrict b, const double * a, const double * x)
{
//!# Requires b[m x 1], a[m * n] and x[n x 1].
//!# b=a*x
#	if MCTARGET_BLAS_USE_CLAYOUT

	const int mm      = m;
	const int nn      = n;
	const int lda     = m;
	const int incx    = 1;
	const int incy    = 1;
	const float alpha = 1.0f;
	const float beta  = 0.0f;

	mc_blas_dgemv('N', mm, nn, alpha, a, lda, x, incx, beta, b, incy);
#	else
	int i, j = 0;
	mc_zeros1xn(m, b);
	for (j = 0; j < n; j++) {
		const double w = x[j];
		for (i = 0; i < m; i++) {
			b[i] = b[i] + (w * a[(n * i) + j]);
		}
	}
#	endif
}

MC_TARGET_FUNC void mc_mulaxmxnl(int m, int n, long double * restrict b, const long double * a, const long double * x)
{
//!# Requires b[m x 1], a[m * n] and x[n x 1].
//!# b=a*x
#	if MCTARGET_BLAS_USE_CLAYOUT

	const int mm      = m;
	const int nn      = n;
	const int lda     = m;
	const int incx    = 1;
	const int incy    = 1;
	const float alpha = 1.0f;
	const float beta  = 0.0f;

	mc_blas_lgemv('N', mm, nn, alpha, a, lda, x, incx, beta, b, incy);
#	else
	int i, j = 0;
	mc_zeros1xnl(m, b);
	for (j = 0; j < n; j++) {
		const long double w = x[j];
		for (i = 0; i < m; i++) {
			b[i] = b[i] + (w * a[(n * i) + j]);
		}
	}
#	endif
}

#endif /* !MC_MULAXMXN_H */

/* EOF */