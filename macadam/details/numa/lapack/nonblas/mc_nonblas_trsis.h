// # -*- coding: utf-8, tab-width: 3 -*-

// mc_nonblas_trsis.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

/* \name
 *    ?trsis transpose square-matrix in-place.
 * 
 * \synopsis
 *    real-floating ?trsis(n, x)
 *    int           n
 *    real-floating x(n, n)
 *
 * \purpose
 *    ?trsis transpose square-matrix in-place.
 *
 * \parameters
 *    [in] n  - int. Specifies the order of the input square-matrix x.
 *    [out] x - real-floating array of dimension (n, n).
 *
 * \examples
 *
 * \level 3 nonblas routine.
 *     \author Moe123.
 */

#include <macadam/details/numa/mc_trsinxn.h>

#ifndef MC_NONBLAS_TRSIS_H
#define MC_NONBLAS_TRSIS_H

#pragma mark - mc_nonblas_strsis -

MC_TARGET_FUNC void mc_nonblas_strsis(int n, float * x)
{
	mc_trsinxnf(n, x);
}

#pragma mark - mc_nonblas_dtrsis -

MC_TARGET_FUNC void mc_nonblas_dtrsis(int n, double * x)
{
	mc_trsinxn(n, x);
}

#pragma mark - mc_nonblas_ltrsis -

MC_TARGET_FUNC void mc_nonblas_ltrsis(int n, long double * x)
{
	mc_trsinxnl(n, x);
}

#endif /* !MC_NONBLAS_TRSIS_H */

/* EOF */