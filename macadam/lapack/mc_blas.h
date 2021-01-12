//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#ifndef MC_BLAS_H
#define MC_BLAS_H

#	undef  MC_TARGET_BLAS_USE_CLAYOUT
#	undef  MC_TARGET_BLAS_USE_FLAYOUT
#	define MC_TARGET_BLAS_USE_CLAYOUT 1
#	define MC_TARGET_BLAS_USE_FLAYOUT 0

#	include <macadam/lapack/blas/mc_blas_abs1.h>
#	include <macadam/lapack/blas/mc_blas_access.h>
#	include <macadam/lapack/blas/mc_blas_asum.h>
#	include <macadam/lapack/blas/mc_blas_axpy.h>
#	include <macadam/lapack/blas/mc_blas_copy.h>
#	include <macadam/lapack/blas/mc_blas_dot.h>
#	include <macadam/lapack/blas/mc_blas_gbmv.h>
#	include <macadam/lapack/blas/mc_blas_gemm.h>
#	include <macadam/lapack/blas/mc_blas_gemv.h>
#	include <macadam/lapack/blas/mc_blas_ger.h>
#	include <macadam/lapack/blas/mc_blas_iamax.h>
#	include <macadam/lapack/blas/mc_blas_lsame.h>
#	include <macadam/lapack/blas/mc_blas_nrm2.h>
#	include <macadam/lapack/blas/mc_blas_rot.h>
#	include <macadam/lapack/blas/mc_blas_rotg.h>
#	include <macadam/lapack/blas/mc_blas_rotm.h>
#	include <macadam/lapack/blas/mc_blas_rotmg.h>
#	include <macadam/lapack/blas/mc_blas_sbmv.h>
#	include <macadam/lapack/blas/mc_blas_scal.h>
#	include <macadam/lapack/blas/mc_blas_spmv.h>
#	include <macadam/lapack/blas/mc_blas_spr.h>
#	include <macadam/lapack/blas/mc_blas_spr2.h>
#	include <macadam/lapack/blas/mc_blas_symm.h>
#	include <macadam/lapack/blas/mc_blas_symv.h>
#	include <macadam/lapack/blas/mc_blas_syr.h>
#	include <macadam/lapack/blas/mc_blas_syr2.h>
#	include <macadam/lapack/blas/mc_blas_syr2k.h>
#	include <macadam/lapack/blas/mc_blas_syrk.h>
#	include <macadam/lapack/blas/mc_blas_tbmv.h>
#	include <macadam/lapack/blas/mc_blas_tbsv.h>
#	include <macadam/lapack/blas/mc_blas_tpmv.h>
#	include <macadam/lapack/blas/mc_blas_tpsv.h>
#	include <macadam/lapack/blas/mc_blas_trmm.h>
#	include <macadam/lapack/blas/mc_blas_trmv.h>
#	include <macadam/lapack/blas/mc_blas_trsm.h>
#	include <macadam/lapack/blas/mc_blas_trsv.h>
#	include <macadam/lapack/blas/mc_blas_xerbla.h>

#	if MC_TARGET_BLAS_USE_NATIVE

#		include <macadam/lapack/blas/native/mc_blas_native_axpy.h>
#		include <macadam/lapack/blas/native/mc_blas_native_copy.h>
#		include <macadam/lapack/blas/native/mc_blas_native_dot.h>
#		include <macadam/lapack/blas/native/mc_blas_native_gbmv.h>
#		include <macadam/lapack/blas/native/mc_blas_native_gemm.h>
#		include <macadam/lapack/blas/native/mc_blas_native_gemv.h>
#		include <macadam/lapack/blas/native/mc_blas_native_ger.h>
#		include <macadam/lapack/blas/native/mc_blas_native_iamax.h>
#		include <macadam/lapack/blas/native/mc_blas_native_rot.h>

#		define mc_saxpy  mc_blas_native_saxpy
#		define mc_daxpy  mc_blas_native_daxpy
#		define mc_caxpy  mc_blas_native_caxpy
#		define mc_zaxpy  mc_blas_native_zaxpy
#		define mc_scopy  mc_blas_native_scopy
#		define mc_dcopy  mc_blas_native_dcopy
#		define mc_ccopy  mc_blas_native_ccopy
#		define mc_zcopy  mc_blas_native_zcopy
#		define mc_sdot   mc_blas_native_sdot
#		define mc_ddot   mc_blas_native_ddot
#		define mc_cdotc  mc_blas_native_cdotc
#		define mc_zdotc  mc_blas_native_zdotc
#		define mc_cdotu  mc_blas_native_cdotu
#		define mc_zdotu  mc_blas_native_zdotu
#		define mc_sgbmv  mc_blas_native_sgbmv
#		define mc_dgbmv  mc_blas_native_dgbmv
#		define mc_cgbmv  mc_blas_native_cgbmv
#		define mc_zgbmv  mc_blas_native_zgbmv
#		define mc_sgemm  mc_blas_native_sgemm
#		define mc_dgemm  mc_blas_native_dgemm
#		define mc_cgemm  mc_blas_native_cgemm
#		define mc_zgemm  mc_blas_native_zgemm
#		define mc_sgemv  mc_blas_native_sgemv
#		define mc_dgemv  mc_blas_native_dgemv
#		define mc_cgemv  mc_blas_native_cgemv
#		define mc_zgemv  mc_blas_native_zgemv
#		define mc_sger   mc_blas_native_sger
#		define mc_dger   mc_blas_native_dger
#		define mc_cgerc  mc_blas_native_cgerc
#		define mc_zgerc  mc_blas_native_zgerc
#		define mc_cgeru  mc_blas_native_cgeru
#		define mc_zgeru  mc_blas_native_zgeru
#		define mc_isamax mc_blas_native_isamax
#		define mc_idamax mc_blas_native_idamax
#		define mc_icamax mc_blas_native_icamax
#		define mc_izamax mc_blas_native_izamax
#		define mc_srot   mc_blas_native_srot
#		define mc_drot   mc_blas_native_drot

#	if !MC_TARGET_BLAS_USE_OPENBLAS
#		define mc_csrot  mc_blas_native_csrot
#		define mc_zdrot  mc_blas_native_zdrot
#	else
#		define mc_csrot  mc_blas_csrot
#		define mc_zdrot  mc_blas_zdrot
#	endif

#	else

#		define mc_saxpy  mc_blas_saxpy
#		define mc_daxpy  mc_blas_daxpy
#		define mc_caxpy  mc_blas_caxpy
#		define mc_zaxpy  mc_blas_zaxpy
#		define mc_scopy  mc_blas_scopy
#		define mc_dcopy  mc_blas_dcopy
#		define mc_ccopy  mc_blas_ccopy
#		define mc_zcopy  mc_blas_zcopy
#		define mc_sdot   mc_blas_sdot
#		define mc_ddot   mc_blas_ddot
#		define mc_cdotc  mc_blas_cdotc
#		define mc_zdotc  mc_blas_zdotc
#		define mc_cdotu  mc_blas_cdotu
#		define mc_zdotu  mc_blas_zdotu
#		define mc_sgbmv  mc_blas_sgbmv
#		define mc_dgbmv  mc_blas_dgbmv
#		define mc_cgbmv  mc_blas_cgbmv
#		define mc_zgbmv  mc_blas_zgbmv
#		define mc_sgemm  mc_blas_sgemm
#		define mc_dgemm  mc_blas_dgemm
#		define mc_cgemm  mc_blas_cgemm
#		define mc_zgemm  mc_blas_zgemm
#		define mc_sgemv  mc_blas_sgemv
#		define mc_dgemv  mc_blas_dgemv
#		define mc_cgemv  mc_blas_cgemv
#		define mc_zgemv  mc_blas_zgemv
#		define mc_sger   mc_blas_sger
#		define mc_dger   mc_blas_dger
#		define mc_cgerc  mc_blas_cgerc
#		define mc_zgerc  mc_blas_zgerc
#		define mc_cgeru  mc_blas_cgeru
#		define mc_zgeru  mc_blas_zgeru
#		define mc_isamax mc_blas_isamax
#		define mc_idamax mc_blas_idamax
#		define mc_icamax mc_blas_icamax
#		define mc_izamax mc_blas_izamax
#		define mc_srot   mc_blas_srot
#		define mc_drot   mc_blas_drot
#		define mc_csrot  mc_blas_csrot
#		define mc_zdrot  mc_blas_zdrot
#	endif

#	define mc_laxpy  mc_blas_laxpy
#	define mc_qaxpy  mc_blas_qaxpy
#	define mc_lcopy  mc_blas_lcopy
#	define mc_qcopy  mc_blas_qcopy
#	define mc_ldot   mc_blas_ldot
#	define mc_qdotc  mc_blas_qdotc
#	define mc_qdotu  mc_blas_qdotu
#	define mc_lgbmv  mc_blas_lgbmv
#	define mc_qgbmv  mc_blas_qgbmv
#	define mc_lgemm  mc_blas_lgemm
#	define mc_qgemm  mc_blas_qgemm
#	define mc_lgemv  mc_blas_lgemv
#	define mc_qgemv  mc_blas_qgemv
#	define mc_lger   mc_blas_lger
#	define mc_qgerc  mc_blas_qgerc
#	define mc_qgeru  mc_blas_qgeru
#	define mc_ilamax mc_blas_ilamax
#	define mc_iqamax mc_blas_iqamax
#	define mc_lrot   mc_blas_lrot
#	define mc_qlrot  mc_blas_qlrot

#endif /* !MC_BLAS_H */

/* EOF */