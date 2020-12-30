//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_native_gemm.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

/* \name
 *    ?gemm performs one of the matrix-matrix operations:
 *    c=alpha*op(a)*op(b) + beta*c where op(x)=x or op(x)=x'.
 *
 * \synopsis
 *    void ?gemm(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc)
 *    real-floating alpha, beta
 *    int           k, lda, ldb, ldc, m, n
 *    char          transa, transb
 *    real-floating a(lda, *), b(ldb, *), c(ldc, *)
 *
 * \purpose
 *    ?gemm performs one of the matrix-matrix operations: c=alpha*op(a)*op(b) + beta*c where
 *    op(x)=x or op(x)=x' alpha and beta are scalars, and a, b and c are matrices, with op(a)
 *    an m by k matrix, op(b) a k by n matrix and c an m by n matrix.
 *
 * \parameters
 *    [in] transa - char. Specifies the form of op(a) to be used in the matrix multiplication as follows:
 *    transa='N' or 'n', op(a)=a.
 *    transa='T' or 't', op(a)=a'.
 *    transa='C' or 'c', op(a)=a'.
 *
 *    [in] transb - char. Specifies the form of op(b) to be used in the matrix multiplication as follows:
 *    transb='N' or 'n', op(b)=b.
 *    transb='T' or 't', op(b)=b'.
 *    transb='C' or 'c', op(b)=b'.
 *
 *    [in] m      - int. Specifies the number of rows of the matrix op(a) and of the matrix c, m must be
 *    at least zero.
 *
 *    [in] n      - int. Specifies the number of columns of the matrix op(b) and the number of columns of
 *    the matrix c, n must be at least zero.
 *
 *    [in] k      - int. Specifies  the number of columns of the matrix op(a) and the number of rows of
 *    the matrix op(b), k must be at least zero.
 *
 *    [in] alpha  - real-floating. Specifies the scalar alpha.
 *
 *    [in] a      - real-floating array of dimension (lda, ka), where ka is k when transa='N' or 'n' and
 *    is m otherwise. Prior entry with transa='N' or 'n', the leading m by k part of the array a must
 *    contain the matrix a, otherwise the leading k by m part of the array a must contain the matrix a.
 *
 *    [in] lda    - int. Specifies the first dimension of a. When transa='N' or 'n' then
 *    lda must be at least max(1, m), otherwise lda must be at least max(1, k).
 *
 *    [in] b      - real-floating array of dimension (ldb, kb), where kb is n when transb='N' or 'n' and
 *    is k otherwise. Prior entry with transb='N' or 'n', the leading k by n part of the array b must
 *    contain the matrix b, otherwise the leading n by k part of the array b must contain the matrix b.
 *
 *    [in] ldb    - int. Specifies the first dimension of b. When transb='N' or 'n' then
 *    ldb must be at least max(1, k), otherwise ldb must be at least max(1, n).
 *
 *    [in] beta   - real-floating. Specifies the scalar beta. When beta is supplied as zero then c need
 *    not be set on input.
 *
 *    [out] c     - real-floating array of dimension (ldc, n). Prior entry the leading  m by n part of the
 *    array c must contain the matrix c, except when beta is set to zero, in which case c need not be set
 *    on entry, c is overwritten by the m by n matrix (alpha*op(a)*op(b) + beta*c).
 *
 *    [in] ldc    - int. Specifies the first dimension of c, ldc must be at least max(1, m).
 *
 * \examples
 *
 * \level 3 blas routine.
 *     \author Univ. of Tennessee.
 *     \author Univ. of California Berkeley.
 *     \author Univ. of Colorado Denver.
 *     \author NAG Ltd.
 *     \author Jack Dongarra, Argonne National Laboratory.
 *     \author Iain Duff, AERE Harwell.
 *     \author Jeremy Du Croz, Numerical Algorithms Group Ltd.
 *     \author Sven Hammarling, Numerical Algorithms Group Ltd.
 */

#include <macadam/details/numa/lapack/blas/mc_blas_lsame.h>

#ifndef MC_BLAS_NATIVE_GEMM_H
#define MC_BLAS_NATIVE_GEMM_H

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

#pragma mark - mc_blas_native_sgemm -

MC_TARGET_FUNC void mc_blas_native_sgemm(const char transa, const char transb, const int m, const int n, const int k, float alpha, const float * a, const int lda, const float * b, const int ldb, float beta, float * c, const int ldc)
{
#	if MC_TARGET_BLAS_USE_CLAYOUT
	const enum CBLAS_ORDER order = CblasRowMajor;
#	else
	const enum CBLAS_ORDER order = CblasColMajor;
#	endif

	const enum CBLAS_TRANSPOSE trans_a = mc_blas_lsame(transa, 'N') ? CblasNoTrans : (mc_blas_lsame(transa, 'T') ? CblasTrans : CblasConjTrans);
	const enum CBLAS_TRANSPOSE trans_b = mc_blas_lsame(transb, 'N') ? CblasNoTrans : (mc_blas_lsame(transb, 'T') ? CblasTrans : CblasConjTrans);

# if MC_TARGET_CPP98
	::cblas_sgemm(order, trans_a, trans_b, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
#	else
	cblas_sgemm(order, trans_a, trans_b, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
#	endif
}

#pragma mark - mc_blas_native_dgemm -

MC_TARGET_FUNC void mc_blas_native_dgemm(const char transa, const char transb, const int m, const int n, const int k, double alpha, const double * a, const int lda, const double * b, const int ldb, double beta, double * c, const int ldc)
{
#	if MC_TARGET_BLAS_USE_CLAYOUT
	const enum CBLAS_ORDER order = CblasRowMajor;
#	else
	const enum CBLAS_ORDER order = CblasColMajor;
#	endif

	const enum CBLAS_TRANSPOSE trans_a = mc_blas_lsame(transa, 'N') ? CblasNoTrans : (mc_blas_lsame(transa, 'T') ? CblasTrans : CblasConjTrans);
	const enum CBLAS_TRANSPOSE trans_b = mc_blas_lsame(transb, 'N') ? CblasNoTrans : (mc_blas_lsame(transb, 'T') ? CblasTrans : CblasConjTrans);

# if MC_TARGET_CPP98
	::cblas_dgemm(order, trans_a, trans_b, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
#	else
	cblas_dgemm(order, trans_a, trans_b, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
#	endif
}

#endif /* !MC_BLAS_NATIVE_GEMM_H */

/* EOF */