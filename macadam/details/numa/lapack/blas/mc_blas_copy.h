//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_copy.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#ifndef MC_BLAS_COPY_H
#define MC_BLAS_COPY_H

#pragma mark - mc_blas_scopy -

MC_TARGET_FUNC void mc_blas_scopy(int n, const float * x, int incx, float * y, int incy)
{
	int i, m, ix, iy, mp1;

	if (n <= 0) {
		return;
	}
	if (incx == 1 && incy == 1) {
		m = n % 7;
		if (m != 0) {
			for (i = 1; i <= m; ++i) {
				mc_blas_vector_at(y, i) = mc_blas_vector_at(x, i);
			}
			if (n < 7) {
				return;
			}
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 7) {
			mc_blas_vector_at(y, i    ) = mc_blas_vector_at(x, i    );
			mc_blas_vector_at(y, i + 1) = mc_blas_vector_at(x, i + 1);
			mc_blas_vector_at(y, i + 2) = mc_blas_vector_at(x, i + 2);
			mc_blas_vector_at(y, i + 3) = mc_blas_vector_at(x, i + 3);
			mc_blas_vector_at(y, i + 4) = mc_blas_vector_at(x, i + 4);
			mc_blas_vector_at(y, i + 5) = mc_blas_vector_at(x, i + 5);
			mc_blas_vector_at(y, i + 6) = mc_blas_vector_at(x, i + 6);
		}
	} else {
		ix = 1;
		iy = 1;
		if (incx < 0) {
			ix = (-(n) + 1) * incx + 1;
		}
		if (incy < 0) {
			iy = (-(n) + 1) * incy + 1;
		}
		for (i = 1; i <= n; ++i) {
			mc_blas_vector_at(y, iy) = mc_blas_vector_at(x, ix);
			ix                       = ix + incx;
			iy                       = iy + incy;
		}
	}
}

#pragma mark - mc_blas_dcopy -

MC_TARGET_FUNC void mc_blas_dcopy(int n, const double * x, int incx, double * y, int incy)
{
	int i, m, ix, iy, mp1;

	if (n <= 0) {
		return;
	}
	if (incx == 1 && incy == 1) {
		m = n % 7;
		if (m != 0) {
			for (i = 1; i <= m; ++i) {
				mc_blas_vector_at(y, i) = mc_blas_vector_at(x, i);
			}
			if (n < 7) {
				return;
			}
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 7) {
			mc_blas_vector_at(y, i)     = mc_blas_vector_at(x, i    );
			mc_blas_vector_at(y, i + 1) = mc_blas_vector_at(x, i + 1);
			mc_blas_vector_at(y, i + 2) = mc_blas_vector_at(x, i + 2);
			mc_blas_vector_at(y, i + 3) = mc_blas_vector_at(x, i + 3);
			mc_blas_vector_at(y, i + 4) = mc_blas_vector_at(x, i + 4);
			mc_blas_vector_at(y, i + 5) = mc_blas_vector_at(x, i + 5);
			mc_blas_vector_at(y, i + 6) = mc_blas_vector_at(x, i + 6);
		}
	} else {
		ix = 1;
		iy = 1;
		if (incx < 0) {
			ix = (-(n) + 1) * incx + 1;
		}
		if (incy < 0) {
			iy = (-(n) + 1) * incy + 1;
		}
		for (i = 1; i <= n; ++i) {
			mc_blas_vector_at(y, iy) = mc_blas_vector_at(x, ix);
			ix                       = ix + incx;
			iy                       = iy + incy;
		}
	}
}

#pragma mark - mc_blas_lcopy -

MC_TARGET_FUNC void mc_blas_lcopy(int n, const long double * x, int incx, long double * y, int incy)
{
	int i, m, ix, iy, mp1;

	if (n <= 0) {
		return;
	}
	if (incx == 1 && incy == 1) {
		m = n % 7;
		if (m != 0) {
			for (i = 1; i <= m; ++i) {
				mc_blas_vector_at(y, i) = mc_blas_vector_at(x, i);
			}
			if (n < 7) {
				return;
			}
		}
		mp1 = m + 1;
		for (i = mp1; i <= n; i += 7) {
			mc_blas_vector_at(y, i)     = mc_blas_vector_at(x, i    );
			mc_blas_vector_at(y, i + 1) = mc_blas_vector_at(x, i + 1);
			mc_blas_vector_at(y, i + 2) = mc_blas_vector_at(x, i + 2);
			mc_blas_vector_at(y, i + 3) = mc_blas_vector_at(x, i + 3);
			mc_blas_vector_at(y, i + 4) = mc_blas_vector_at(x, i + 4);
			mc_blas_vector_at(y, i + 5) = mc_blas_vector_at(x, i + 5);
			mc_blas_vector_at(y, i + 6) = mc_blas_vector_at(x, i + 6);
		}
	} else {
		ix = 1;
		iy = 1;
		if (incx < 0) {
			ix = (-(n) + 1) * incx + 1;
		}
		if (incy < 0) {
			iy = (-(n) + 1) * incy + 1;
		}
		for (i = 1; i <= n; ++i) {
			mc_blas_vector_at(y, iy) = mc_blas_vector_at(x, ix);
			ix                       = ix + incx;
			iy                       = iy + incy;
		}
	}
}

#endif /* !MC_BLAS_COPY_H */

/* EOF */