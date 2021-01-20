//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_native_spr.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

/* \name
 *    ?spmv performs the symmetric rank 1 operation:
 *    a=alpha*x*x' + a.
 *
 * \synopsis
 *    void ?spmv(uplo, n, alpha, x, incx, ap)
 *    float-floating alpha
 *    int            incx, n
 *    char           uplo
 *    float-floating ap(*), x(*)
 *
 * \purpose
 *    ?spmv performs the symmetric rank 1 operation: a=alpha*x*x' + a where alpha is a real scalar,
 *    `x` is an n element vector and `a` is an n by n symmetric matrix, supplied in packed form.
 *
 *
 * \parameters
 *    [in] uplo  - char. Specifies whether the upper or lower triangular part of the matrix `a` is supplied
 *    in the packed array `ap` as follows:
 *    UPLO='U' or 'u', the upper triangular part of `a` supplied in `ap`.
 *    UPLO='L' or 'l', the lower triangular part of `a` supplied in `ap`.
 *
 *    [in] n     - int. Specifies the order of the symmetric matrix `a`, n must be at least zero.
 *
 *    [in] alpha - float-floating. Specifies the scalar alpha.
 *
 *    [int] x    - real-floating array of size at least (1+(n-1)*abs(incx)). The incremented array `x` must
 *    contain the vector `x`.
 *
 *    [in] incx  - int. Specifies the increment for the elements of `x`, incx must not be zero.
 *
 *    [in] ap    - float-floating array of dimension (at least) ((n*(n+1))/2).
 *    With UPLO='U' or 'u', the array `ap` must contain the upper triangular part of the symmetric matrix
 *    packed sequentially, column by column, so that ap(1) contains a(1,1), ap(2) and ap(3) contain a(1,2)
 *    and a(2,2) respectively, and so on.
 *
 *    With UPLO='L' or 'l', the array ap must contain the lower triangular part of the symmetric matrix
 *    packed sequentially, column by column, so that ap(1) contains a(1,1), ap(2) and ap(3) contain a(2,1)
 *    and a(3,1) respectively, and so on.
 *
 * \examples
 *
 * \level 2 blas routine.
 *     \author Univ. of Tennessee.
 *     \author Univ. of California Berkeley.
 *     \author Univ. of Colorado Denver.
 *     \author NAG Ltd.
 *     \author Jack Dongarra, Argonne National Lab.
 *     \author Jeremy Du Croz, Nag Central Office.
 *     \author Sven Hammarling, Nag Central Office.
 *     \author Richard Hanson, Sandia National Labs.
 */

#include <macadam/lapack/blas/mc_blas_lsame.h>

#ifndef MC_BLAS_NATIVE_SPR_H
#define MC_BLAS_NATIVE_SPR_H

#pragma mark - mc_blas_native_sspr -

MC_TARGET_FUNC void mc_blas_native_sspr(const char uplo, const int n, const float alpha, const float * x, const int incx, float * ap)
{
#	if MC_TARGET_BLAS_USE_CLAYOUT
	const enum CBLAS_ORDER order = CblasRowMajor;
#	else
	const enum CBLAS_ORDER order = CblasColMajor;
#	endif

	const enum CBLAS_UPLO uplo_x = mc_blas_lsame(uplo, 'U') ? CblasUpper : CblasLower;

#	if MC_TARGET_CPP98
	::cblas_sspr(order, uplo_x, n, alpha, x, incx, ap);
#	else
	cblas_sspr(order, uplo_x, n, alpha, x, incx, ap);
#	endif
}

#pragma mark - mc_blas_native_dspr -

MC_TARGET_FUNC void mc_blas_native_dspr(const char uplo, const int n, const double alpha, const double * x, const int incx, double * ap)
{
#	if MC_TARGET_BLAS_USE_CLAYOUT
	const enum CBLAS_ORDER order = CblasRowMajor;
#	else
	const enum CBLAS_ORDER order = CblasColMajor;
#	endif

	const enum CBLAS_UPLO uplo_x = mc_blas_lsame(uplo, 'U') ? CblasUpper : CblasLower;

#	if MC_TARGET_CPP98
	::cblas_dspr(order, uplo_x, n, alpha, x, incx, ap);
#	else
	cblas_dspr(order, uplo_x, n, alpha, x, incx, ap);
#	endif
}

#endif /* !MC_BLAS_NATIVE_SPR_H */

/* EOF */