//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zeros1xn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_ZEROS1XN_H
#define MC_ZEROS1XN_H

#pragma mark - mc_zeros1xn -

MC_TARGET_FUNC void mc_zeros1xnf(int n, float * x)
{
#	if MC_TARGET_CPP98
	::std::fill_n(x, n, 0.0f);
#	else
#	if MC_TARGET_C11 && defined(__STDC_LIB_EXT1__)
	if (n > 0) {
		memset_s(x, mc_cast(size_t, n) * sizeof(float), 0, mc_cast(size_t, n) * sizeof(float));
	}
#	else
	int i = 0;
	for (; i < n; i++) {
		x[i] = 0.0f;
	}
#	endif
#	endif
}

MC_TARGET_FUNC void mc_zeros1xn(int n, double * x)
{
#	if MC_TARGET_CPP98
	::std::fill_n(x, n, 0.0);
#	else
#	if MC_TARGET_C11 && defined(__STDC_LIB_EXT1__)
	if (n > 0) {
		memset_s(x, mc_cast(size_t, n) * sizeof(double), 0, mc_cast(size_t, n) * sizeof(double));
	}
#	else
	int i = 0;
	for (; i < n; i++) {
		x[i] = 0.0;
	}
#	endif
#	endif
}

MC_TARGET_FUNC void mc_zeros1xnl(int n, long double * x)
{
#	if MC_TARGET_CPP98
	::std::fill_n(x, n, 0.0L);
#	else
#	if MC_TARGET_C11 && defined(__STDC_LIB_EXT1__)
	if (n > 0) {
		memset_s(x, mc_cast(size_t, n) * sizeof(long double), 0, mc_cast(size_t, n) * sizeof(long double));
	}
#	else
	int i = 0;
	for (; i < n; i++) {
		x[i] = 0.0L;
	}
#	endif
#	endif
}

#endif /* !MC_ZEROS1XN_H */

/* EOF */