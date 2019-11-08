//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_numa.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#ifndef MC_NUMA_H
#define MC_NUMA_H

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

#	include <macadam/details/numa/lapack/mc_lapack_iladiag.h>
#	include <macadam/details/numa/lapack/mc_lapack_ilalc.h>
#	include <macadam/details/numa/lapack/mc_lapack_ilalr.h>
#	include <macadam/details/numa/lapack/mc_lapack_ilaprec.h>
#	include <macadam/details/numa/lapack/mc_lapack_ilatrans.h>
#	include <macadam/details/numa/lapack/mc_lapack_ilauplo.h>
#	include <macadam/details/numa/lapack/mc_lapack_lamch.h>
#	include <macadam/details/numa/lapack/mc_lapack_lamrg.h>
#	include <macadam/details/numa/lapack/mc_lapack_lartg.h>
#	include <macadam/details/numa/lapack/mc_lapack_lartgp.h>
#	include <macadam/details/numa/lapack/mc_lapack_lartgs.h>
#	include <macadam/details/numa/lapack/mc_lapack_las2.h>
#	include <macadam/details/numa/lapack/mc_lapack_lascl.h>
#	include <macadam/details/numa/lapack/mc_lapack_lascl2.h>
#	include <macadam/details/numa/lapack/mc_lapack_lasdt.h>
#	include <macadam/details/numa/lapack/mc_lapack_lasq1.h>
#	include <macadam/details/numa/lapack/mc_lapack_lasq2.h>
#	include <macadam/details/numa/lapack/mc_lapack_lasq3.h>
#	include <macadam/details/numa/lapack/mc_lapack_lasq5.h>
#	include <macadam/details/numa/lapack/mc_lapack_lasq6.h>
#	include <macadam/details/numa/lapack/mc_lapack_lasr.h>
#	include <macadam/details/numa/lapack/mc_lapack_lasrt.h>
#	include <macadam/details/numa/lapack/mc_lapack_lasv2.h>
#	include <macadam/details/numa/lapack/mc_lapack_lsamen.h>

#	include <macadam/details/numa/lapack/nonblas/mc_nonblas_gbmcv.h>
#	include <macadam/details/numa/lapack/nonblas/mc_nonblas_gemcv.h>
#	include <macadam/details/numa/lapack/nonblas/mc_nonblas_gercv.h>
#	include <macadam/details/numa/lapack/nonblas/mc_nonblas_nrmcv.h>
#	include <macadam/details/numa/lapack/nonblas/mc_nonblas_rotcv.h>
#	include <macadam/details/numa/lapack/nonblas/mc_nonblas_swpcv.h>
#	include <macadam/details/numa/lapack/nonblas/mc_nonblas_swpcv.h>
#	include <macadam/details/numa/lapack/nonblas/mc_nonblas_trsir.h>
#	include <macadam/details/numa/lapack/nonblas/mc_nonblas_trsis.h>
#	include <macadam/details/numa/lapack/nonblas/mc_nonblas_ugecv.h>
#	include <macadam/details/numa/lapack/nonblas/mc_nonblas_ugemv.h>

#	include <macadam/details/numa/mc_det2x2.h>
#	include <macadam/details/numa/mc_det3x3.h>
#	include <macadam/details/numa/mc_eig2x2.h>
#	include <macadam/details/numa/mc_eye2x2.h>
#	include <macadam/details/numa/mc_eye3x3.h>
#	include <macadam/details/numa/mc_norm1x2.h>
#	include <macadam/details/numa/mc_norm1x3.h>
#	include <macadam/details/numa/mc_norm2x1.h>
#	include <macadam/details/numa/mc_norm3x1.h>
#	include <macadam/details/numa/mc_trace2x2.h>
#	include <macadam/details/numa/mc_trace3x3.h>
#	include <macadam/details/numa/mc_tracemxn.h>
#	include <macadam/details/numa/mc_tracenxn.h>
#	include <macadam/details/numa/mc_trsi2x2.h>
#	include <macadam/details/numa/mc_trsi3x3.h>
#	include <macadam/details/numa/mc_unit1x2.h>
#	include <macadam/details/numa/mc_unit1x3.h>
#	include <macadam/details/numa/mc_unit2x1.h>
#	include <macadam/details/numa/mc_unit3x1.h>
#	include <macadam/details/numa/mc_zeye2x2.h>
#	include <macadam/details/numa/mc_zeye3x3.h>
#	include <macadam/details/numa/mc_znorm1x2.h>
#	include <macadam/details/numa/mc_znorm1x3.h>
#	include <macadam/details/numa/mc_zreig2x2.h>
#	include <macadam/details/numa/mc_zunit1x2.h>
#	include <macadam/details/numa/mc_zunit1x3.h>

#endif /* !MC_NUMA_H */

/* EOF */