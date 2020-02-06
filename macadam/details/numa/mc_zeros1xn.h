//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zeros1xn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_ZEROS1XN_H
#define MC_ZEROS1XN_H

#pragma mark - mc_zeros1xn_type -

#	if MC_TARGET_CPP98
#		define mc_zeros1xn_type(type, n, x) \
		mc_scope_begin                      \
			if (mc_cast_expr(int, n) > 0) {  \
				::std::fill_n(x, n, 0.0);     \
			}                                \
		mc_scope_end
#	elif MC_TARGET_C11 && defined(__STDC_LIB_EXT1__)
#		define mc_zeros1xn_type(type, n, x)                                                         \
		mc_scope_begin                                                                              \
			if (mc_cast_expr(int, n) > 0) {                                                          \
				memset_s(x, mc_cast(size_t, n) * sizeof(type), 0, mc_cast(size_t, n) * sizeof(type)); \
			}                                                                                        \
		mc_scope_end
#	else
#		define mc_zeros1xn_type(type, n, x)                                              \
		mc_scope_begin                                                                   \
			int __mc_zeros1xn_type_i = 0;                                                 \
			for (; __mc_zeros1xn_type_i < mc_cast_expr(int, n); __mc_zeros1xn_type_i++) { \
				x[__mc_zeros1xn_type_i] = mc_cast_expr(type, 0);                           \
			}                                                                             \
		mc_scope_end
#	endif

#pragma mark - mc_zeros1xn -

MC_TARGET_FUNC void mc_zeros1xnf(int n, float * x)
{
	mc_zeros1xn_type(float, n, x);
}

MC_TARGET_FUNC void mc_zeros1xn(int n, double * x)
{
	mc_zeros1xn_type(double, n, x);
}

MC_TARGET_FUNC void mc_zeros1xnl(int n, long double * x)
{
	mc_zeros1xn_type(long double, n, x);
}

#endif /* !MC_ZEROS1XN_H */

/* EOF */