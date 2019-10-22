//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_lapacke_iladiag.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/blas/mc_blas_lsame.h>

#ifndef MC_LAPACKE_ILADIAG_H
#define MC_LAPACKE_ILADIAG_H

#pragma mark - mc_lapacke_iladiag -

MC_TARGET_FUNC int mc_lapacke_iladiag(const char diag)
{
	int iladiag;

	switch (diag)
	{
		case 'N':
		case 'n':
			iladiag = 131;
		break;
		case 'U':
		case 'u':
			iladiag = 132;
		break;
		default:
			iladiag = -1;
	}
	return iladiag;
}

#endif /* !MC_LAPACKE_ILADIAG_H */

/* EOF */