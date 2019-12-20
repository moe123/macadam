//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_mulabmxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_mulab2x2.h>
#include <macadam/details/numa/mc_mulab3x3.h>

#ifndef MC_MULABMXN_H
#define MC_MULABMXN_H

#pragma mark - mc_mulabmxn -

#	define MCTARGET_USE_BLAS 1

MC_TARGET_FUNC void mc_mulabmxnf(int m, int n, int p, float * restrict c, const float * restrict a, const float * restrict b)
{
//!# c=a*b. Asumming m=ma, n=na, mb=na and nb=p, produces c[m x p]=a[m x n] * b[n x p].
#	if MCTARGET_USE_BLAS

	int mm            = m;
	int nn            = p;
	int kk            = n;
	int lda           = m;
	int ldb           = n;
	int ldc           = m;
	const float alpha = 1.0f;
	const float beta  = 0.0f;

	mc_blas_sgemm('N', 'N', mm, nn, kk, alpha, a, lda, b, ldb, beta, c, ldc);
#	else
	int i = 0, j, k;
	for (; i < m; i++) {
		for (j = 0; j < p; j++) {
			c[(p * i) + j] = 0.0f;
			for (k = 0; k < n; k++) {
				c[(p * i) + j] = c[(p * i) + j] + (a[(n * i) + k] * b[(p * k) + j]);
			}
		}
	}
#	endif
}

MC_TARGET_FUNC void mc_mulabmxn(int m, int n, int p, double * restrict c, const double * restrict a, const double * restrict b)
{
//!# c=a*b. Asumming m=ma, n=na, mb=na and nb=p, produces c[m x p]=a[m x n] * b[n x p].
#	if MCTARGET_USE_BLAS

	int mm             = m;
	int nn             = p;
	int kk             = n;
	int lda            = m;
	int ldb            = n;
	int ldc            = m;
	const double alpha = 1.0;
	const double beta  = 0.0;

	mc_blas_dgemm('N', 'N', mm, nn, kk, alpha, a, lda, b, ldb, beta, c, ldc);
#	else
	int i = 0, j, k;
	for (; i < m; i++) {
		for (j = 0; j < p; j++) {
			c[(p * i) + j] = 0.0;
			for (k = 0; k < n; k++) {
				c[(p * i) + j] = c[(p * i) + j] + (a[(n * i) + k] * b[(p * k) + j]);
			}
		}
	}
#	endif
}

MC_TARGET_FUNC void mc_mulabmxnl(int m, int n, int p, long double * restrict c, const long double * restrict a, const long double * restrict b)
{
//!# c=a*b. Asumming m=ma, n=na, mb=na and nb=p, produces c[m x p]=a[m x n] * b[n x p].
#	if MCTARGET_USE_BLAS

	int mm                  = m;
	int nn                  = p;
	int kk                  = n;
	int lda                 = m;
	int ldb                 = n;
	int ldc                 = m;
	const long double alpha = 1.0L;
	const long double beta  = 0.0L;

	mc_blas_lgemm('N', 'N', mm, nn, kk, alpha, a, lda, b, ldb, beta, c, ldc);
#	else
	int i = 0, j, k;
	for (; i < m; i++) {
		for (j = 0; j < p; j++) {
			c[(p * i) + j] = 0.0L;
			for (k = 0; k < n; k++) {
				c[(p * i) + j] = c[(p * i) + j] + (a[(n * i) + k] * b[(p * k) + j]);
			}
		}
	}
#	endif
}

#endif /* !MC_MULABMXN_H */

/* EOF */