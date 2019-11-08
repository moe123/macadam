// # -*- coding: utf-8, tab-width: 3 -*-

// mc_nonblas_trsir.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

/* \name
 *    ?trsir transpose rectangular-matrix in-place.
 * 
 * \synopsis
 *    real-floating ?trsir(m, n, x)
 *    int           n, m
 *    real-floating x(m, n)
 *
 * \purpose
 *    ?trsir transpose rectangular-matrix in-place.
 *
 * \parameters
 *    [in] m - int. Specifies the number of rows in the  input rectangular-matrix x.
 *    [in] n - int. Specifies the number of columns in the input rectangular-matrix x.
 *
 * \examples
 *
 * \level 3 nonblas routine.
 *     \author Moe123.
 */

#include <macadam/details/numa/mc_trsimxn.h>

#ifndef MC_NONBLAS_TRSIR_H
#define MC_NONBLAS_TRSIR_H

#pragma mark - mc_nonblas_strsir -

MC_TARGET_FUNC void mc_nonblas_strsir(int m, int n, float * x)
{
	mc_trsimxnf(m, n, x);
}

#pragma mark - mc_nonblas_dtrsir -

MC_TARGET_FUNC void mc_nonblas_dtrsir(int m, int n, double * x)
{
	mc_trsimxn(m, n, x);
}

#pragma mark - mc_nonblas_ltrsir -

MC_TARGET_FUNC void mc_nonblas_ltrsir(int m, int n, long double * x)
{
	mc_trsimxnl(m, n, x);
}

#endif /* !MC_NONBLAS_TRSIR_H */

/* EOF */