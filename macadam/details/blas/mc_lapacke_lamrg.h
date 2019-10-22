//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_lapacke_lamrg.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/blas/mc_blas_access.h>

#ifndef MC_LAPACKE_LAMRG_H
#define MC_LAPACKE_LAMRG_H

#pragma mark - mc_lapacke_slamrg -

MC_TARGET_FUNC void mc_lapacke_slamrg(int n1, int n2, const float * a, int strd1, int strd2, int * index)
{
	int i, ind1, ind2, n1sv, n2sv;

	n1sv = n1;
	n2sv = n2;
	if (strd1 > 0) {
		ind1 = 1;
	} else {
		ind1 = n1;
	}
	if (strd2 > 0) {
		ind2 = n1 + 1;
	} else {
		ind2 = n1 + n2;
	}
	i = 1;

F10:
	if (n1sv > 0 && n2sv > 0) {
		if (mc_blas_vector_at(a, ind1) <= mc_blas_vector_at(a, ind2)) {
			mc_blas_vector_at(index, i) = ind1;
			i                           = i + 1;
			ind1                        = ind1 + strd1;
			n1sv                        = n1sv - 1;
		} else {
			mc_blas_vector_at(index, i) = ind2;
			i                           = i + 1;
			ind2                        = ind2 + strd2;
			n2sv                        = n2sv - 1;
		}
		goto F10;
	}

	if (n1sv == 0) {
		for (n1sv = 1; n1sv <= n2sv; ++n1sv) {
			mc_blas_vector_at(index, i) = ind2;
			i                           = i + 1;
			ind2                        = ind2 + strd2;
		}
	} else {
		for (n2sv = 1; n2sv <= n1sv; ++n2sv) {
			mc_blas_vector_at(index, i) = ind1;
			i                           = i + 1;
			ind1                        = ind1 + strd1;
		}
	}
}

#pragma mark - mc_lapacke_llamrg -

MC_TARGET_FUNC void mc_lapacke_llamrg(int n1, int n2, const long double * a, int strd1, int strd2, int * index)
{
	int i, ind1, ind2, n1sv, n2sv;

	n1sv = n1;
	n2sv = n2;
	if (strd1 > 0) {
		ind1 = 1;
	} else {
		ind1 = n1;
	}
	if (strd2 > 0) {
		ind2 = n1 + 1;
	} else {
		ind2 = n1 + n2;
	}
	i = 1;

F10:
	if (n1sv > 0 && n2sv > 0) {
		if (mc_blas_vector_at(a, ind1) <= mc_blas_vector_at(a, ind2)) {
			mc_blas_vector_at(index, i) = ind1;
			i                           = i + 1;
			ind1                        = ind1 + strd1;
			n1sv                        = n1sv - 1;
		} else {
			mc_blas_vector_at(index, i) = ind2;
			i                           = i + 1;
			ind2                        = ind2 + strd2;
			n2sv                        = n2sv - 1;
		}
		goto F10;
	}

	if (n1sv == 0) {
		for (n1sv = 1; n1sv <= n2sv; ++n1sv) {
			mc_blas_vector_at(index, i) = ind2;
			i                           = i + 1;
			ind2                        = ind2 + strd2;
		}
	} else {
		for (n2sv = 1; n2sv <= n1sv; ++n2sv) {
			mc_blas_vector_at(index, i) = ind1;
			i                           = i + 1;
			ind1                        = ind1 + strd1;
		}
	}
}

#pragma mark - mc_lapacke_dlamrg -

MC_TARGET_FUNC void mc_lapacke_dlamrg(int n1, int n2, const double * a, int strd1, int strd2, int * index)
{
	int i, ind1, ind2, n1sv, n2sv;

	n1sv = n1;
	n2sv = n2;
	if (strd1 > 0) {
		ind1 = 1;
	} else {
		ind1 = n1;
	}
	if (strd2 > 0) {
		ind2 = n1 + 1;
	} else {
		ind2 = n1 + n2;
	}
	i = 1;

F10:
	if (n1sv > 0 && n2sv > 0) {
		if (mc_blas_vector_at(a, ind1) <= mc_blas_vector_at(a, ind2)) {
			mc_blas_vector_at(index, i) = ind1;
			i                           = i + 1;
			ind1                        = ind1 + strd1;
			n1sv                        = n1sv - 1;
		} else {
			mc_blas_vector_at(index, i) = ind2;
			i                           = i + 1;
			ind2                        = ind2 + strd2;
			n2sv                        = n2sv - 1;
		}
		goto F10;
	}

	if (n1sv == 0) {
		for (n1sv = 1; n1sv <= n2sv; ++n1sv) {
			mc_blas_vector_at(index, i) = ind2;
			i                           = i + 1;
			ind2                        = ind2 + strd2;
		}
	} else {
		for (n2sv = 1; n2sv <= n1sv; ++n2sv) {
			mc_blas_vector_at(index, i) = ind1;
			i                           = i + 1;
			ind1                        = ind1 + strd1;
		}
	}
}

#endif /* !MC_LAPACKE_LAMRG_H */

/* EOF */