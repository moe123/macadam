//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_mulabtmxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/lapack/blas/mc_blas_gemm.h>

#ifndef MC_MULABTMXN_H
#define MC_MULABTMXN_H

#pragma mark - mc_mulabtmxn -

MC_TARGET_FUNC void mc_mulabtmxnf(int m, int n, int p, float * restrict c, const float * a, const float * b)
{
//!# c=a*b'. Asumming m=ma, n=na, mb=na and nb=p, produces c[m x p]=a[m x n] * b[n x p].
#	if MCTARGET_BLAS_USE_CLAYOUT

	const int mm      = m;
	const int nn      = m;
	const int kk      = n = p;
	const int lda     = m;
	const int ldb     = m;
	const int ldc     = m;
	const float alpha = 1.0f;
	const float beta  = 0.0f;

	mc_blas_sgemm('N', 'T', mm, nn, kk, alpha, a, lda, b, ldb, beta, c, ldc);
#	else

#	endif
}

MC_TARGET_FUNC void mc_mulabtmxn(int m, int n, int p, double * restrict c, const double * a, const double * b)
{
//!# c=a*b'. Asumming m=ma, n=na, mb=na and nb=p, produces c[m x p]=a[m x n] * b[n x p].
#	if MCTARGET_BLAS_USE_CLAYOUT

	const int mm       = m;
	const int nn       = m;
	const int kk       = n = p;
	const int lda      = m;
	const int ldb      = m;
	const int ldc      = m;
	const double alpha = 1.0;
	const double beta  = 0.0;

	mc_blas_dgemm('N', 'T', mm, nn, kk, alpha, a, lda, b, ldb, beta, c, ldc);
#	else

#	endif
}

MC_TARGET_FUNC void mc_mulabtmxnl(int m, int n, int p, long double * restrict c, const long double * a, const long double * b)
{
//!# c=a*b'. Asumming m=ma, n=na, mb=na and nb=p, produces c[m x p]=a[m x n] * b[n x p].
#	if MCTARGET_BLAS_USE_CLAYOUT

	const int mm            = m;
	const int nn            = m;
	const int kk            = n = p;
	const int lda           = m;
	const int ldb           = m;
	const int ldc           = m;
	const long double alpha = 1.0L;
	const long double beta  = 0.0L;

	mc_blas_lgemm('N', 'T', mm, nn, kk, alpha, a, lda, b, ldb, beta, c, ldc);
#	else

#	endif
}

#endif /* !MC_MULABTMXN_H */

/* EOF */