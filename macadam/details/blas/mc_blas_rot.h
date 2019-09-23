// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_rot.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

/* \name
 *    ?rot applies a plane rotation.
 * 
 * \synopsis
 *    real-floating ?rot(n, x, incx, y, incy, c, s)
 *    real-floating c, s
 *    int           incx, incy, n
 *    real-floating x(*), y(*)
 *
 * \purpose
 *    ?rot applies a plane rotation matrix to a real sequence of ordered pairs.
 *    If coefficients c and s satisfy c+s=1, the rotation matrix is orthogonal,
 *    and the transformation is called a Givens plane rotation.
 *
 * \parameters
 *    [in] n     - int. Specifies the number of elements in the input vector x and y.
 *
 *    [out] x    - real-floating array of size at least (1+(n-1)*abs(incx)).
 *    [in] incx  - int. Specifies the increment for the elements of x, incx must not be zero.
 *
 *    [out] y    - real-floating array of size at least (1+(n-1)*abs(incy)).
 *    [in] incy  - int. Specifies the increment for the elements of y, incy must not be zero.
 *
 *    [in] c     - float-floating. Specifies the cosine of the angle of rotation.
 *    [in] s     - float-floating. Specifies the sine of the angle of rotation.
 *
 * \examples
 *
 * \level 1 blas routine.
 *     \author Univ. of Tennessee
 *     \author Univ. of California Berkeley
 *     \author Univ. of Colorado Denver
 *     \author NAG Ltd.
 *     \author Jack Dongarra, Linpack.
 */

#include <macadam/details/blas/mc_blas_access.h>

#ifndef MC_BLAS_ROT_H
#define MC_BLAS_ROT_H

#pragma mark - mc_blas_srot -

MC_TARGET_FUNC void mc_blas_srot(int n, float * x, int incx, float * y, int incy, float c, float s)
{
	float temp;
	int i, ix, iy;

	if (n <= 0) {
		return;
	}
	if (incx == 1 && incy == 1) {
		for (i = 1; i <= n; ++i) {
			temp              = c * MC_BLAS_VAT(x, i) + s * MC_BLAS_VAT(y, i);
			MC_BLAS_VAT(y, i) = c * MC_BLAS_VAT(y, i) - s * MC_BLAS_VAT(x, i);
			MC_BLAS_VAT(x, i) = temp;
		}
	} else {
		ix = 1;
		iy = 1;
		if (incx < 0) {
			ix = (-(n) + 1) * incx + 1;
		}
		if (incy < 0) {
			iy = (-(n) + 1) * incy + 1;
		}
		for (i = 1; i <= n; ++i) {
			temp               = c * MC_BLAS_VAT(x, ix) + s * MC_BLAS_VAT(y, iy);
			MC_BLAS_VAT(y, iy) = c * MC_BLAS_VAT(y, iy) - s * MC_BLAS_VAT(x, ix);
			MC_BLAS_VAT(x, ix) = temp;
			ix                 = ix + incx;
			iy                 = iy + incy;
		}
	}
}

#endif /* !MC_BLAS_ROT_H */

/* EOF */