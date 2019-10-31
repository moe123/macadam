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

#	define mc_blas_matrix_trsis(gtp, g, ng) \
/* //!# Transposing in-place square matrix g. */ \
/* //!# gtp - literal type of elements.       */ \
/* //!# g   - memory pointer.                 */ \
/* //!# ng  - number of rows and columns.     */ \
	do { \
		int __mc_blas_i = 0, __mc_blas_j; \
		int __mc_blas_n = mc_cast_exp(int, ng); \
		gtp __mc_blas_w; \
		for (; __mc_blas_i < __mc_blas_n - 2; ++__mc_blas_i) { \
			for (__mc_blas_j = __mc_blas_i + 1; __mc_blas_j < __mc_blas_n - 1; ++__mc_blas_j) { \
				__mc_blas_w                                    = g[((__mc_blas_i) * __mc_blas_n) + __mc_blas_j]; \
				g[((__mc_blas_i) * __mc_blas_n) + __mc_blas_j] = g[((__mc_blas_j) * __mc_blas_n) + __mc_blas_i]; \
				g[((__mc_blas_j) * __mc_blas_n) + __mc_blas_i] = __mc_blas_w; \
			} \
		} \
	} while (0)

#	define mc_blas_matrix_trsir(gtp, g, mg, ng) \
/* //!# Transposing in-place rectangular matrix g. */ \
/* //!# gtp - literal type of elements.            */ \
/* //!# g   - memory pointer.                      */ \
/* //!# mg  - number of rows.                      */ \
/* //!# ng  - number of columns.                   */ \
	do { \
		int __mc_blas_i = 0, __mc_blas_j, __mc_blas_k; \
		int __mc_blas_m = mc_cast_exp(int, mg); \
		int __mc_blas_n = mc_cast_exp(int, ng); \
		gtp __mc_blas_w; \
		for (; __mc_blas_i <= __mc_blas_m * __mc_blas_n - 1; ++__mc_blas_i) { \
			__mc_blas_k = __mc_blas_i; \
			__mc_blas_j = 0; \
			do { \
				++__mc_blas_j; \
				__mc_blas_k = (__mc_blas_k % __mc_blas_m) * __mc_blas_n + __mc_blas_k / __mc_blas_m; \
			} while (__mc_blas_k > __mc_blas_i); \
			if (__mc_blas_k >= __mc_blas_i && __mc_blas_j != 1) { \
				__mc_blas_w = (g)[__mc_blas_i]; \
				__mc_blas_k = __mc_blas_i; \
				do { \
					__mc_blas_j      = (__mc_blas_k % __mc_blas_m) * __mc_blas_n + __mc_blas_k / __mc_blas_m; \
					(g)[__mc_blas_k] = (__mc_blas_j == __mc_blas_i) ? __mc_blas_w : (g)[__mc_blas_j]; \
					__mc_blas_k      = __mc_blas_j; \
				} while (__mc_blas_k > __mc_blas_i); \
			} \
		} \
	} while (0)

#	if MCTARGET_BLAS_USE_CLAYOUT
#		define mc_blas_matrix_at(g, mg, ng, gj, gi) \
			mc_blas_matrix_rmj_at(g, mg, ng, ((gj) - 1), ((gi) - 1))
#	else
#		define mc_blas_matrix_at(g, mg, ng, gj, gi) \
			mc_blas_matrix_cmj_at(g, mg, ng, ((gj) - 1), ((gi) - 1))
#	endif

#endif /* !MC_BLAS_ACCESS_H */

/* EOF */