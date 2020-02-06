//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_argsort1xn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcswap.h>

#ifndef MC_ARGSORT1XN_H
#define MC_ARGSORT1XN_H

#pragma mark - mc_argsort1xn_type -

#	define mc_argsort1xn_type(integer_type, n, x, k, f)                                                                              \
	mc_scope_begin                                                                                                                   \
		int __mc_argsort1xn_i = 0, __mc_argsort1xn_j;                                                                                 \
		integer_type __mc_argsort1xn_w;                                                                                               \
		for (; __mc_argsort1xn_i < n; __mc_argsort1xn_i++) {                                                                          \
			k[__mc_argsort1xn_i] = mc_cast(integer_type, __mc_argsort1xn_i);                                                           \
		}                                                                                                                             \
		for (__mc_argsort1xn_i = 0; __mc_argsort1xn_i < n; __mc_argsort1xn_i++) {                                                     \
			for (__mc_argsort1xn_j = 1; __mc_argsort1xn_j < (n - __mc_argsort1xn_i); __mc_argsort1xn_j++) {                            \
				if ((f == 1) ? (x[__mc_argsort1xn_j - 1] < x[__mc_argsort1xn_j]) : (x[__mc_argsort1xn_j - 1] > x[__mc_argsort1xn_j])) { \
					mcswap_var(__mc_argsort1xn_w, k[__mc_argsort1xn_j - 1], k[__mc_argsort1xn_j]);                                       \
				}                                                                                                                       \
			}                                                                                                                          \
		}                                                                                                                             \
	mc_scope_end

#pragma mark - mc_argsort1xn -

MC_TARGET_FUNC void mc_argsort1xnf(int n, const float * x, int * k, int f)
{
	mc_argsort1xn_type(int, n, x, k, f);
}

MC_TARGET_FUNC void mc_argsort1xn(int n, const double * x, int * k, int f)
{
	mc_argsort1xn_type(int, n, x, k, f);
}

MC_TARGET_FUNC void mc_argsort1xnl(int n, const long double * x, int * k, int f)
{
	mc_argsort1xn_type(int, n, x, k, f);
}

#endif /* !MC_ARGSORT1XN_H */

/* EOF */