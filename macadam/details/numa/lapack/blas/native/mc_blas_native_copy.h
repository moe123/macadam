// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_native_copy.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

/* \name
 *    ?copy copies a vector x, to a vector y.
 *
 * \synopsis
 *    void ?copy(n, x, incx, y, incy)
 *    int            incx, incy, n
 *    float-floating x(*), y(*)
 *
 * \purpose
 *    ?copy copies a vector x, to a vector y.
 *
 * \parameters
 *    [in]  n     - int. Specifies the number of elements in input vector(s).
 *
 *    [in]  x     - float-floating array of dimension at least (1+(n-1)*abs(incx)).
 *    [in]  incx  - int. Specifies the storage spacing between elements of x.
 *
 *    [out]  y    - float-floating array of dimension at least (1+(n-1)*abs(incy)).
 *    [in]  incy  - int. Specifies the storage spacing between elements of y.
 *
 * \examples
 *
 * \level 2 blas routine.
 *     \author Univ. of Tennessee.
 *     \author Univ. of California Berkeley.
 *     \author Univ. of Colorado Denver.
 *     \author NAG Ltd.
 */

#include <macadam/details/mc_target.h>

#ifndef MC_BLAS_NATIVE_COPY_H
#define MC_BLAS_NATIVE_COPY_H

#	if MC_TARGET_BLAS_USE_ACCELERATE
#		include <Accelerate/Accelerate.h>
#	elif MC_TARGET_BLAS_USE_VECLIB
#		include <vecLib/cblas.h>
#	elif MC_TARGET_BLAS_USE_MLK
#		undef  MKL_INT
#		undef  MKL_UINT
#		undef  MKL_Complex8
#		undef  MKL_Complex16
#		define MKL_INT       int
#		define MKL_UINT      unsigned int
#		define MKL_Complex8  mc_complex_float_t
#		define MKL_Complex16 mc_complex_double_t
#		include <mkl_cblas.h>
#	elif MC_TARGET_BLAS_USE_OPENBLAS
#		include <cblas_openblas.h>
#	else
#		include "cblas.h"
#	endif

#pragma mark - mc_blas_native_scopy -

MC_TARGET_FUNC void mc_blas_native_scopy(const int n, const float * x, const int incx, float * y, const int incy)
{
# if MC_TARGET_CPP98
	::cblas_scopy(n, x, incx, y, incy);
#	else
	cblas_scopy(n, x, incx, y, incy);
#	endif
}

#pragma mark - mc_blas_native_dcopy -

MC_TARGET_FUNC void mc_blas_native_dcopy(const int n, const double * x, const int incx, double * y, const int incy)
{
# if MC_TARGET_CPP98
	::cblas_dcopy(n, x, incx, y, incy);
#	else
	cblas_dcopy(n, x, incx, y, incy);
#	endif
}

#endif /* !MC_BLAS_NATIVE_COPY_H */

/* EOF */