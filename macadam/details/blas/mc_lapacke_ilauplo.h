//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_lapacke_ilauplo.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/blas/mc_blas_lsame.h>

#ifndef MC_LAPACKE_ILAUPLO_H
#define MC_LAPACKE_ILAUPLO_H

#pragma mark - mc_lapacke_ilauplo -

MC_TARGET_FUNC int mc_lapacke_ilauplo(const char uplo)
{
	int ilauplo;

	if (mc_blas_lsame(uplo, 'U')) {
		ilauplo = 121;
	} else if (mc_blas_lsame(uplo, 'L')) {
		ilauplo = 122;
	} else {
		ilauplo = -1;
	}
	return ilauplo;
}

#endif /* !MC_LAPACKE_ILAUPLO_H */

/* EOF */