//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_scal.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/lapack/blas/mc_blas_access.h>

#ifndef MC_BLAS_SCAL_H
#define MC_BLAS_SCAL_H

#pragma mark - mc_blas_sscal -

MC_TARGET_FUNC void mc_blas_sscal(int n, float a, float * x, int incx)
{
	int i, m, mp1, nincx;

	if (n <= 0 || incx <= 0) {
		return;
	}
	if (incx == 1) {
		m = n % 5;
		if (m != 0) {
			for (i = 1; i <= m; ++i) {
				mc_blas_vector_at(x, i) = a * mc_blas_vector_at(x, i);
			}
			if (n < 5) {
				return;
			}
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 5) {
			mc_blas_vector_at(x, i    ) = a * mc_blas_vector_at(x, i    );
			mc_blas_vector_at(x, i + 1) = a * mc_blas_vector_at(x, i + 1);
			mc_blas_vector_at(x, i + 2) = a * mc_blas_vector_at(x, i + 2);
			mc_blas_vector_at(x, i + 3) = a * mc_blas_vector_at(x, i + 3);
			mc_blas_vector_at(x, i + 4) = a * mc_blas_vector_at(x, i + 4);
		}
	} else {
		nincx = n * incx;
		for (i = 1; incx < 0 ? i >= nincx : i <= nincx; i += incx) {
			mc_blas_vector_at(x, i) = a * mc_blas_vector_at(x, i);
		}
	}
}

#pragma mark - mc_blas_dscal -

MC_TARGET_FUNC void mc_blas_dscal(int n, double a, double * x, int incx)
{
	int i, m, mp1, nincx;

	if (n <= 0 || incx <= 0) {
		return;
	}
	if (incx == 1) {
		m = n % 5;
		if (m != 0) {
			for (i = 1; i <= m; ++i) {
				mc_blas_vector_at(x, i) = a * mc_blas_vector_at(x, i);
			}
			if (n < 5) {
				return;
			}
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 5) {
			mc_blas_vector_at(x, i    ) = a * mc_blas_vector_at(x, i    );
			mc_blas_vector_at(x, i + 1) = a * mc_blas_vector_at(x, i + 1);
			mc_blas_vector_at(x, i + 2) = a * mc_blas_vector_at(x, i + 2);
			mc_blas_vector_at(x, i + 3) = a * mc_blas_vector_at(x, i + 3);
			mc_blas_vector_at(x, i + 4) = a * mc_blas_vector_at(x, i + 4);
		}
	} else {
		nincx = n * incx;
		for (i = 1; incx < 0 ? i >= nincx : i <= nincx; i += incx) {
			mc_blas_vector_at(x, i) = a * mc_blas_vector_at(x, i);
		}
	}
}

#pragma mark - mc_blas_lscal -

MC_TARGET_FUNC void mc_blas_lscal(int n, long double a, long double * x, int incx)
{
	int i, m, mp1, nincx;

	if (n <= 0 || incx <= 0) {
		return;
	}
	if (incx == 1) {
		m = n % 5;
		if (m != 0) {
			for (i = 1; i <= m; ++i) {
				mc_blas_vector_at(x, i) = a * mc_blas_vector_at(x, i);
			}
			if (n < 5) {
				return;
			}
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 5) {
			mc_blas_vector_at(x, i    ) = a * mc_blas_vector_at(x, i    );
			mc_blas_vector_at(x, i + 1) = a * mc_blas_vector_at(x, i + 1);
			mc_blas_vector_at(x, i + 2) = a * mc_blas_vector_at(x, i + 2);
			mc_blas_vector_at(x, i + 3) = a * mc_blas_vector_at(x, i + 3);
			mc_blas_vector_at(x, i + 4) = a * mc_blas_vector_at(x, i + 4);
		}
	} else {
		nincx = n * incx;
		for (i = 1; incx < 0 ? i >= nincx : i <= nincx; i += incx) {
			mc_blas_vector_at(x, i) = a * mc_blas_vector_at(x, i);
		}
	}
}

#endif /* !MC_BLAS_SCAL_H */

/* EOF */