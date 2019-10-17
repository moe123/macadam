//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_access.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#ifndef MC_BLAS_ACCESS_H
#define MC_BLAS_ACCESS_H

#	undef  MCTARGET_BLAS_USE_CLAYOUT
#	define MCTARGET_BLAS_USE_CLAYOUT 1

#	define mc_blas_vector_at(g, gi) g[((gi) - 1)]

#	define mc_blas_matrix_rmj_at(g, mg, ng, gi, gj) g[((gi) * (ng)) + (gj)]
#	define mc_blas_matrix_cmj_at(g, mg, ng, gi, gj) g[((gj) * (mg)) + (gi)]

#	if MCTARGET_BLAS_USE_CLAYOUT
#		define mc_blas_matrix_at(g, mg, ng, gj, gi) \
			mc_blas_matrix_rmj_at(g, mg, ng, ((gj) - 1), ((gi) - 1))
#	else
#		define mc_blas_matrix_at(g, mg, ng, gj, gi) \
			mc_blas_matrix_cmj_at(g, mg, ng, ((gj) - 1), ((gi) - 1))
#	endif

#endif /* !MC_BLAS_ACCESS_H */

/* EOF */