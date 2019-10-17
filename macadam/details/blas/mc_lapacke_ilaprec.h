//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_lapacke_ilaprec.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/blas/mc_blas_lsame.h>

#ifndef MC_LAPACKE_ILAPREC_H
#define MC_LAPACKE_ILAPREC_H

#pragma mark - mc_lapacke_ilaprec -

MC_TARGET_FUNC int mc_lapacke_ilaprec(const char prec)
{
	int ilaprec;

	if (mc_blas_lsame(prec, 'S')) {
		ilaprec = 211;
	} else if (mc_blas_lsame(prec, 'D')) {
		ilaprec = 212;
	} else if (mc_blas_lsame(prec, 'I')) {
		ilaprec = 213;
	} else if (mc_blas_lsame(prec, 'X') || mc_blas_lsame(prec, 'E')) {
		ilaprec = 214;
	} else {
		ilaprec = -1;
	}
	return ilaprec;
}

#endif /* !MC_LAPACKE_ILAPREC_H */

/* EOF */