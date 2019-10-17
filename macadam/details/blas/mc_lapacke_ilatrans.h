//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_lapacke_ilatrans.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/blas/mc_blas_lsame.h>

#ifndef MC_LAPACKE_ILATRANS_H
#define MC_LAPACKE_ILATRANS_H

#pragma mark - mc_lapacke_ilatrans -

MC_TARGET_FUNC int mc_lapacke_ilatrans(const char trans)
{
	int ilatrans;

	if (mc_blas_lsame(trans, 'N')) {
		ilatrans = 111;
	} else if (mc_blas_lsame(trans, 'T')) {
		ilatrans = 112;
	} else if (mc_blas_lsame(trans, 'C')) {
		ilatrans = 113;
	} else {
		ilatrans = -1;
	}
	return ilatrans;
}

#endif /* !MC_LAPACKE_ILATRANS_H */

/* EOF */