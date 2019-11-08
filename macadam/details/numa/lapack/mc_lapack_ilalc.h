//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_lapack_ilalc.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/lapack/blas/mc_blas_access.h>

#ifndef MC_LAPACKE_ILALC_H
#define MC_LAPACKE_ILALC_H

#pragma mark - mc_lapack_ilaslc -

MC_TARGET_FUNC int mc_lapack_ilaslc(int m, int n, const float * a, int lda)
{
	const float zero = 0.0f;

	int i, ilalc;

	if (n == 0) {
		mc_cast(void, lda);
		ilalc = n;
	} else if (mc_blas_matrix_at(a, lda, n, 1, n) != zero || mc_blas_matrix_at(a, lda, n, m, n) != zero) {
		ilalc = n;
	} else {
		for (ilalc = n; ilalc >= 1; --ilalc) {
			for (i = 1; i <= m; ++i) {
				if (mc_blas_matrix_at(a, lda, n, i, ilalc) != zero) {
					break;
				}
			}
		}
	}
	return ilalc;
}

#pragma mark - mc_lapack_iladlc -

MC_TARGET_FUNC int mc_lapack_iladlc(int m, int n, const double * a, int lda)
{
	const double zero = 0.0;

	int i, ilalc;

	if (n == 0) {
		mc_cast(void, lda);
		ilalc = n;
	} else if (mc_blas_matrix_at(a, lda, n, 1, n) != zero || mc_blas_matrix_at(a, lda, n, m, n) != zero) {
		ilalc = n;
	} else {
		for (ilalc = n; ilalc >= 1; --ilalc) {
			for (i = 1; i <= m; ++i) {
				if (mc_blas_matrix_at(a, lda, n, i, ilalc) != zero) {
					break;
				}
			}
		}
	}
	return ilalc;
}

#pragma mark - mc_lapack_ilallc -

MC_TARGET_FUNC int mc_lapack_ilallc(int m, int n, const long double * a, int lda)
{
	const long double zero = 0.0L;

	int i, ilalc;

	if (n == 0) {
		mc_cast(void, lda);
		ilalc = n;
	} else if (mc_blas_matrix_at(a, lda, n, 1, n) != zero || mc_blas_matrix_at(a, lda, n, m, n) != zero) {
		ilalc = n;
	} else {
		for (ilalc = n; ilalc >= 1; --ilalc) {
			for (i = 1; i <= m; ++i) {
				if (mc_blas_matrix_at(a, lda, n, i, ilalc) != zero) {
					break;
				}
			}
		}
	}
	return ilalc;
}

#endif /* !MC_LAPACKE_ILALC_H */

/* EOF */