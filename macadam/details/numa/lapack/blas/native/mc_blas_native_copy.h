// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_copy.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_BLAS_NATIVE_COPY_H
#define MC_BLAS_NATIVE_COPY_H

#	if MC_TARGET_BLAS_USE_ACCELERATE
#		include <Accelerate/Accelerate.h>
#	elif MC_TARGET_BLAS_USE_VECLIB
#		include <vecLib/cblas.h>
#	elif MC_TARGET_BLAS_USE_MLK
#		define MKL_Complex8  mc_complex_float_t
#		define MKL_Complex16 mc_complex_double_t
#		include <mkl_cblas.h>
#	else
#		include "cblas.h"
#	endif

#pragma mark - mc_blas_native_scopy -

MC_TARGET_FUNC void mc_blas_native_scopy(const int n, const float * x, const int incx, float * y, const int incy)
{
	cblas_scopy(n, x, incx, y, incy);
}

#pragma mark - mc_blas_native_dcopy -

MC_TARGET_FUNC void mc_blas_native_dcopy(const int n, const double * x, const int incx, double * y, const int incy)
{
	cblas_dcopy(n, x, incx, y, incy);
}

#endif /* !MC_BLAS_NATIVE_COPY_H */

/* EOF */