//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_native_spr.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

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