//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_copy1xn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_COPY1XN_H
#define MC_COPY1XN_H

#pragma mark - mc_copy1xn_type -

#	if MC_TARGET_CPP98
#		define mc_copy1xn_type(type, n, y, x)                         \
		mc_scope_begin                                                \
			if (mc_cast_expr(int, n) > 0) {                            \
				::memcpy(y, x, mc_cast_expr(size_t, n) * sizeof(type)); \
			}                                                          \
		mc_scope_end
#	elif MC_TARGET_C11 && defined(__STDC_LIB_EXT1__)
#		define mc_copy1xn_type(type, n, y, x)                                                                 \
		mc_scope_begin                                                                                        \
			if (mc_cast_expr(int, n) > 0) {                                                                    \
				memcpy_s(y, mc_cast_expr(size_t, n) * sizeof(type), x, mc_cast_expr(size_t, n) * sizeof(type)); \
			}                                                                                                  \
		mc_scope_end
#	else
#		define mc_copy1xn_type(type, n, y, x)                                          \
		mc_scope_begin                                                                 \
			int __mc_copy1xn_type_i = 0;                                                \
			for (; __mc_copy1xn_type_i < mc_cast_expr(int, n); __mc_copy1xn_type_i++) { \
				y[__mc_copy1xn_type_i] = mc_cast_expr(type, x[__mc_copy1xn_type_i]);     \
			}                                                                           \
		mc_scope_end
#	endif

#pragma mark - mc_copy1xn -

MC_TARGET_FUNC void mc_copy1xnf(int n, float * y, const float * x)
{
	mc_copy1xn_type(float, n, y, x);
}

MC_TARGET_FUNC void mc_copy1xnff(int n, double * y, const float * x)
{
	int i = 0;
	for (; i < n; i++) {
		y[i] = mc_cast(double, x[i]);
	}
}

MC_TARGET_FUNC void mc_copy1xn(int n, double * y, const double * x)
{
	mc_copy1xn_type(double, n, y, x);
}

MC_TARGET_FUNC void mc_copy1xnl(int n, long double * y, const long double * x)
{
	mc_copy1xn_type(long double, n, y, x);
}

#endif /* !MC_COPY1XN_H */

/* EOF */