//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_native_spr2.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/lapack/blas/mc_blas_lsame.h>

#ifndef MC_BLAS_NATIVE_SPR2_H
#define MC_BLAS_NATIVE_SPR2_H

#pragma mark - mc_blas_native_sspr2 -

MC_TARGET_FUNC void mc_blas_native_sspr2(const char uplo, const int n, const float alpha, const float * x, const int incx, const float * y, const int incy, float * ap)
{
#	if MC_TARGET_BLAS_USE_CLAYOUT
	const enum CBLAS_ORDER order = CblasRowMajor;
#	else
	const enum CBLAS_ORDER order = CblasColMajor;
#	endif

	const enum CBLAS_UPLO uplo_x = mc_blas_lsame(uplo, 'U') ? CblasUpper : CblasLower;

#	if MC_TARGET_CPP98
	::cblas_sspr2(order, uplo_x, n, alpha, x, incx, y, incy, ap);
#	else
	cblas_sspr2(order, uplo_x, n, alpha, x, incx, y, incy, ap);
#	endif
}

#pragma mark - mc_blas_native_dspr2 -

MC_TARGET_FUNC void mc_blas_native_dspr2(const char uplo, const int n, const double alpha, const double * x, const int incx, const double * y, const int incy, double * ap)
{
#	if MC_TARGET_BLAS_USE_CLAYOUT
	const enum CBLAS_ORDER order = CblasRowMajor;
#	else
	const enum CBLAS_ORDER order = CblasColMajor;
#	endif

	const enum CBLAS_UPLO uplo_x = mc_blas_lsame(uplo, 'U') ? CblasUpper : CblasLower;

#	if MC_TARGET_CPP98
	::cblas_dspr2(order, uplo_x, n, alpha, x, incx, y, incy, ap);
#	else
	cblas_dspr2(order, uplo_x, n, alpha, x, incx, y, incy, ap);
#	endif
}

#endif /* !MC_BLAS_SPR2_H */

/* EOF */