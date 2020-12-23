//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_iamax.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#ifndef MC_BLAS_IAMAX_H
#define MC_BLAS_IAMAX_H

#pragma mark - mc_blas_isamax -

MC_TARGET_FUNC int mc_blas_isamax(const int n, const float * x, const int incx)
{
	float max;
	int i, iamax, ix;

	iamax = 0;
	if (n < 1 || incx <= 0) {
		return iamax;
	}
	iamax = 1;
	if (n == 1) {
		return iamax;
	}
	if (incx == 1) {
		max = mc_fabsf(mc_blas_vector_at(x, 1));
		for (i = 2; i <= n; ++i) {
			if (mc_fabsf(mc_blas_vector_at(x, i)) > max) {
				iamax = i;
				max   = mc_fabsf(mc_blas_vector_at(x, i));
			}
		}
	} else {
		ix  = 1;
		max = mc_fabsf(mc_blas_vector_at(x, 1));
		ix  = ix + incx;
		for (i = 2; i <= n; ++i) {
			if (mc_fabsf(mc_blas_vector_at(x, ix)) > max) {
				iamax = i;
				max   = mc_fabsf(mc_blas_vector_at(x, ix));
			}
			ix = ix + incx;
		}
	}
	return iamax;
}

#pragma mark - mc_blas_idamax -

MC_TARGET_FUNC int mc_blas_idamax(const int n, const double * x, const int incx)
{
	double max;
	int i, iamax, ix;

	iamax = 0;
	if (n < 1 || incx <= 0) {
		return iamax;
	}
	iamax = 1;
	if (n == 1) {
		return iamax;
	}
	if (incx == 1) {
		max = mc_fabs(mc_blas_vector_at(x, 1));
		for (i = 2; i <= n; ++i) {
			if (mc_fabs(mc_blas_vector_at(x, i)) > max) {
				iamax = i;
				max   = mc_fabs(mc_blas_vector_at(x, i));
			}
		}
	} else {
		ix  = 1;
		max = mc_fabs(mc_blas_vector_at(x, 1));
		ix  = ix + incx;
		for (i = 2; i <= n; ++i) {
			if (mc_fabs(mc_blas_vector_at(x, ix)) > max) {
				iamax = i;
				max   = mc_fabs(mc_blas_vector_at(x, ix));
			}
			ix = ix + incx;
		}
	}
	return iamax;
}

#pragma mark - mc_blas_ilamax -

MC_TARGET_FUNC int mc_blas_ilamax(const int n, const long double * x, const int incx)
{
	long double max;
	int i, iamax, ix;

	iamax = 0;
	if (n < 1 || incx <= 0) {
		return iamax;
	}
	iamax = 1;
	if (n == 1) {
		return iamax;
	}
	if (incx == 1) {
		max = mc_fabsl(mc_blas_vector_at(x, 1));
		for (i = 2; i <= n; ++i) {
			if (mc_fabsl(mc_blas_vector_at(x, i)) > max) {
				iamax = i;
				max   = mc_fabsl(mc_blas_vector_at(x, i));
			}
		}
	} else {
		ix  = 1;
		max = mc_fabsl(mc_blas_vector_at(x, 1));
		ix  = ix + incx;
		for (i = 2; i <= n; ++i) {
			if (mc_fabsl(mc_blas_vector_at(x, ix)) > max) {
				iamax = i;
				max   = mc_fabsl(mc_blas_vector_at(x, ix));
			}
			ix = ix + incx;
		}
	}
	return iamax;
}

#endif /* !MC_BLAS_IAMAX_H */

/* EOF */