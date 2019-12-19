//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_mulatbmxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/lapack/blas/mc_blas_gemm.h>

#ifndef MC_MULATBMXN_H
#define MC_MULATBMXN_H

#pragma mark - mc_mulatbmxn -

MC_TARGET_FUNC void mc_mulatbmxnf(int m, int n, int p, float * restrict c, const float * restrict a, const float * restrict b)
{
//!# c=a'*b. Asumming m=ma, n=na, mb=na and nb=p, produces c[m x p]=a[m x n] * b[n x p].
#	if MCTARGET_BLAS_USE_CLONE
	if (p == n) {
		mc_blas_sgemm('T', 'N', n, m, m, 1.0f, a, m, b, m, 0.0f, c, n);
	}
#	else
	mc_blas_sgemm('T', 'N', m, p, n, 1.0f, a, m, b, m, 0.0f, c, m);
#	endif
}

MC_TARGET_FUNC void mc_mulatbmxn(int m, int n, int p, double * restrict c, const double * restrict a, const double * restrict b)
{
//!# c=a'*b. Asumming m=ma, n=na, mb=na and nb=p, produces c[m x p]=a[m x n] * b[n x p].
#	if MCTARGET_BLAS_USE_CLONE
	if (p == n) {
		mc_blas_dgemm('T', 'N', n, m, m, 1.0, a, m, b, m, 0.0, c, n);
	}
#	else
	mc_blas_dgemm('T', 'N', m, p, n, 1.0, a, m, b, m, 0.0, c, n);
#	endif
}

MC_TARGET_FUNC void mc_mulatbmxnl(int m, int n, int p, long double * restrict c, const long double * restrict a, const long double * restrict b)
{
//!# c=a'*b. Asumming m=ma, n=na, mb=na and nb=p, produces c[m x p]=a[m x n] * b[n x p].
#	if MCTARGET_BLAS_USE_CLONE
	if (p == n) {
		mc_blas_lgemm('T', 'N', n, m, m, 1.0L, a, m, b, m, 0.0L, c, n);
	}
#	else
	mc_blas_lgemm('T', 'N', m, p, n, 1.0L, a, m, b, m, 0.0L, c, n);
#	endif
}

#endif /* !MC_MULATBMXN_H */

/* EOF */