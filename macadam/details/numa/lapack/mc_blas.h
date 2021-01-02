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

#	if MC_TARGET_BLAS_USE_NATIVE
#	include <macadam/details/numa/lapack/blas/native/mc_blas_native_copy.h>
#	include <macadam/details/numa/lapack/blas/native/mc_blas_native_gemm.h>
#	include <macadam/details/numa/lapack/blas/native/mc_blas_native_ger.h>
#	endif

#	include <macadam/details/numa/lapack/blas/mc_blas_access.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_asum.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_axpy.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_copy.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_dot.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_gbmv.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_gemm.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_gemv.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_ger.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_iamax.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_lsame.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_nrm2.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_rot.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_rotg.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_rotm.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_rotmg.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_sbmv.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_scal.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_spmv.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_spr.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_spr2.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_symm.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_symv.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_syr.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_syr2.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_syr2k.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_syrk.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_tbmv.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_tbsv.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_tpmv.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_tpsv.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_trmm.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_trmv.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_trsm.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_trsv.h>
#	include <macadam/details/numa/lapack/blas/mc_blas_xerbla.h>

#	if MC_TARGET_BLAS_USE_NATIVE
#	define mc_scopy mc_blas_native_scopy
#	define mc_dcopy mc_blas_native_dcopy
#	define mc_sgemm mc_blas_native_sgemm
#	define mc_dgemm mc_blas_native_dgemm
#	define mc_sger  mc_blas_native_sger
#	define mc_dger  mc_blas_native_dger
#	else
#	define mc_scopy mc_blas_scopy
#	define mc_dcopy mc_blas_dcopy
#	define mc_sgemm mc_blas_sgemm
#	define mc_dgemm mc_blas_dgemm
#	define mc_sger  mc_blas_sger
#	define mc_dger  mc_blas_dger
#	endif

#	define mc_lcopy mc_blas_lcopy
#	define mc_lgemm mc_blas_lgemm
#	define mc_lger  mc_blas_lger

#endif /* !MC_BLAS_H */

/* EOF */