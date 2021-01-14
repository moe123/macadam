//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_native_scal.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/lapack/blas/mc_blas_access.h>

#ifndef MC_BLAS_NATIVE_SCAL_H
#define MC_BLAS_NATIVE_SCAL_H

#pragma mark - mc_blas_native_sscal -

MC_TARGET_FUNC void mc_blas_native_sscal(const int n, float a, float * x, const int incx)
{
#	if MC_TARGET_CPP98
	::cblas_sscal(n, a, x, incx);
#	else
	cblas_sscal(n, a, x, incx);
#	endif
}

#pragma mark - mc_blas_native_dscal -

MC_TARGET_FUNC void mc_blas_native_dscal(const int n, double a, double * x, const int incx)
{
#	if MC_TARGET_CPP98
	::cblas_dscal(n, a, x, incx);
#	else
	cblas_dscal(n, a, x, incx);
#	endif
}

#pragma mark - mc_blas_native_cscal -

MC_TARGET_FUNC void mc_blas_native_cscal(const int n, mc_complex_float_t a, mc_complex_float_t * x, const int incx)
{
#	if MC_TARGET_CPP98
	::cblas_cscal(n, &a, x, incx);
#	else
	cblas_cscal(n, &a, x, incx);
#	endif
}

#pragma mark - mc_blas_native_zscal -

MC_TARGET_FUNC void mc_blas_native_zscal(const int n, mc_complex_double_t a, mc_complex_double_t * x, const int incx)
{
#	if MC_TARGET_CPP98
	::cblas_zscal(n, &a, x, incx);
#	else
	cblas_zscal(n, &a, x, incx);
#	endif
}

#endif /* !MC_BLAS_SCAL_H */

/* EOF */