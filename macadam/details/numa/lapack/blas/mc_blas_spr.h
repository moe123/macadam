// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_spr.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/lapack/blas/mc_blas_access.h>
#include <macadam/details/numa/lapack/blas/mc_blas_lsame.h>
#include <macadam/details/numa/lapack/blas/mc_blas_xerbla.h>

#ifndef MC_BLAS_SPR_H
#define MC_BLAS_SPR_H

#pragma mark - mc_blas_sspr -

MC_TARGET_FUNC void mc_blas_sspr(const char uplo, int n, float alpha, const float * x, int incx, float * ap)
{
	const float zero = 0.0f;

	float temp;
	int i, info, ix, j, jx, k, kk, kx;

	info = 0;
	if (!mc_blas_lsame(uplo, 'U') && !mc_blas_lsame(uplo, 'L')) {
		info = 1;
	} else if (n < 0) {
		info = 2;
	} else if (incx == 0) {
		info = 5;
	}
	if (info != 0) {
		mc_blas_xerbla("SSPR  ", info);
		return;
	}

	if (n == 0 || alpha == zero) {
		return;
	}

	if (incx <= 0) {
		kx = 1 - (n - 1) * incx;
	} else if (incx != 1) {
		kx = 1;
	}

	kk = 1;
	if (mc_blas_lsame(uplo, 'U')) {
		if (incx == 1) {
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, j) != zero) {
					temp = alpha * mc_blas_vector_at(x, j);
					k    = kk;
					for (i = 1; i <= j; ++i) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + (mc_blas_vector_at(x, i) * temp);
						k                        = k + 1;
					}
				}
				kk = kk + j;
			}
		} else {
			jx = kx;
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, jx) != zero) {
					temp = alpha * mc_blas_vector_at(x, jx);
					ix   = kx;
					for (k = kk; k <= (kk + j - 1); ++k) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + (mc_blas_vector_at(x, ix) * temp);
						ix                       = ix + incx;
					}
				}
				jx = jx + incx;
				kk = kk + j;
			}
		}
	} else {
		if (incx == 1) {
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, j) != zero) {
					temp = alpha * mc_blas_vector_at(x, j);
					k    = kk;
					for (i = j; i <= n; ++i) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + (mc_blas_vector_at(x, i) * temp);
						k                        = k + 1;
					}
				}
				kk = kk + n - j + 1;
			}
		} else {
			jx = kx;
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, jx) != zero) {
					temp = alpha * mc_blas_vector_at(x, jx);
					ix   = jx;
					for (k = kk; k <= (kk + n - j); ++k) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + (mc_blas_vector_at(x, ix) * temp);
						ix                       = ix + incx;
					}
				}
				jx = jx + incx;
				kk = kk + n - j + 1;
			}
		}
	}
}

#pragma mark - mc_blas_dspr -

MC_TARGET_FUNC void mc_blas_dspr(const char uplo, int n, double alpha, const double * x, int incx, double * ap)
{
	const double zero = 0.0;

	double temp;
	int i, info, ix, j, jx, k, kk, kx;

	info = 0;
	if (!mc_blas_lsame(uplo, 'U') && !mc_blas_lsame(uplo, 'L')) {
		info = 1;
	} else if (n < 0) {
		info = 2;
	} else if (incx == 0) {
		info = 5;
	}
	if (info != 0) {
		mc_blas_xerbla("DSPR  ", info);
		return;
	}

	if (n == 0 || alpha == zero) {
		return;
	}

	if (incx <= 0) {
		kx = 1 - (n - 1) * incx;
	} else if (incx != 1) {
		kx = 1;
	}

	kk = 1;
	if (mc_blas_lsame(uplo, 'U')) {
		if (incx == 1) {
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, j) != zero) {
					temp = alpha * mc_blas_vector_at(x, j);
					k    = kk;
					for (i = 1; i <= j; ++i) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + (mc_blas_vector_at(x, i) * temp);
						k                        = k + 1;
					}
				}
				kk = kk + j;
			}
		} else {
			jx = kx;
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, jx) != zero) {
					temp = alpha * mc_blas_vector_at(x, jx);
					ix   = kx;
					for (k = kk; k <= (kk + j - 1); ++k) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + (mc_blas_vector_at(x, ix) * temp);
						ix                       = ix + incx;
					}
				}
				jx = jx + incx;
				kk = kk + j;
			}
		}
	} else {
		if (incx == 1) {
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, j) != zero) {
					temp = alpha * mc_blas_vector_at(x, j);
					k    = kk;
					for (i = j; i <= n; ++i) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + (mc_blas_vector_at(x, i) * temp);
						k                        = k + 1;
					}
				}
				kk = kk + n - j + 1;
			}
		} else {
			jx = kx;
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, jx) != zero) {
					temp = alpha * mc_blas_vector_at(x, jx);
					ix   = jx;
					for (k = kk; k <= (kk + n - j); ++k) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + (mc_blas_vector_at(x, ix) * temp);
						ix                       = ix + incx;
					}
				}
				jx = jx + incx;
				kk = kk + n - j + 1;
			}
		}
	}
}

#pragma mark - mc_blas_lspr -

MC_TARGET_FUNC void mc_blas_lspr(const char uplo, int n, long double alpha, const long double * x, int incx, long double * ap)
{
	const long double zero = 0.0L;

	long double temp;
	int i, info, ix, j, jx, k, kk, kx;

	info = 0;
	if (!mc_blas_lsame(uplo, 'U') && !mc_blas_lsame(uplo, 'L')) {
		info = 1;
	} else if (n < 0) {
		info = 2;
	} else if (incx == 0) {
		info = 5;
	}
	if (info != 0) {
		mc_blas_xerbla("LSPR  ", info);
		return;
	}

	if (n == 0 || alpha == zero) {
		return;
	}

	if (incx <= 0) {
		kx = 1 - (n - 1) * incx;
	} else if (incx != 1) {
		kx = 1;
	}

	kk = 1;
	if (mc_blas_lsame(uplo, 'U')) {
		if (incx == 1) {
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, j) != zero) {
					temp = alpha * mc_blas_vector_at(x, j);
					k    = kk;
					for (i = 1; i <= j; ++i) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + (mc_blas_vector_at(x, i) * temp);
						k                        = k + 1;
					}
				}
				kk = kk + j;
			}
		} else {
			jx = kx;
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, jx) != zero) {
					temp = alpha * mc_blas_vector_at(x, jx);
					ix   = kx;
					for (k = kk; k <= (kk + j - 1); ++k) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + (mc_blas_vector_at(x, ix) * temp);
						ix                       = ix + incx;
					}
				}
				jx = jx + incx;
				kk = kk + j;
			}
		}
	} else {
		if (incx == 1) {
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, j) != zero) {
					temp = alpha * mc_blas_vector_at(x, j);
					k    = kk;
					for (i = j; i <= n; ++i) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + (mc_blas_vector_at(x, i) * temp);
						k                        = k + 1;
					}
				}
				kk = kk + n - j + 1;
			}
		} else {
			jx = kx;
			for (j = 1; j <= n; ++j) {
				if (mc_blas_vector_at(x, jx) != zero) {
					temp = alpha * mc_blas_vector_at(x, jx);
					ix   = jx;
					for (k = kk; k <= (kk + n - j); ++k) {
						mc_blas_vector_at(ap, k) = mc_blas_vector_at(ap, k) + (mc_blas_vector_at(x, ix) * temp);
						ix                       = ix + incx;
					}
				}
				jx = jx + incx;
				kk = kk + n - j + 1;
			}
		}
	}
}

#endif /* !MC_BLAS_SPR_H */

/* EOF */