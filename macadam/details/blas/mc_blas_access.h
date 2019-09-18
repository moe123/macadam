//
//!# # -*- coding: utf-8, tab-width: 3 -*-

//!# mc_blas_access.h
//
//!# Copyright (C) 2019 Moe123. All rights reserved.
//

#ifndef MC_BLAS_ACCESS_H
#define MC_BLAS_ACCESS_H

#	define MCTARGET_BLAS_CLAYOUT 1

#	define MC_BLAS_VAT(B, BI) B[((BI) - 1)]

#	define MC_BLAS_CMAT_RMJ(A, M, N, AI, AJ) A[((AI) * N) + (AJ)]
#	define MC_BLAS_CMAT_CMJ(A, M, N, AI, AJ) A[((AJ) * M) + (AI)]

#	if MCTARGET_BLAS_CLAYOUT
#		define MC_BLAS_MAT(A, M, N, AJ, AI) \
			MC_BLAS_CMAT_RMJ(A, M, N, ((AJ) - 1), ((AI) - 1))
#	else
#		define MC_BLAS_MAT(A, M, N, AJ, AI) \
			MC_BLAS_CMAT_CMJ(A, M, N, ((AJ) - 1), ((AI) - 1))
#	endif

#endif /* !MC_BLAS_ACCESS_H */

/* EOF */