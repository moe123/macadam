//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_copy1xn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_COPY1XN_H
#define MC_COPY1XN_H

#pragma mark - mc_copy1xn -

MC_TARGET_FUNC void mc_copy1xnf(int n, float * y, const float * x)
{
#	if MC_TARGET_CPP98
		::memcpy(y, x, n * sizeof(float));
#	elif MC_TARGET_C11 && defined(__STDC_LIB_EXT1__)
	if (n > 0) {
		memcpy_s(y, mc_cast(size_t, n) * sizeof(float), x, mc_cast(size_t, n) * sizeof(float));
	}
#	else
	int i = 0;
	for (; i < n; i++) {
		y[i] = x[i];
	}
#	endif
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
#	if MC_TARGET_CPP98
		::memcpy(y, x, n * sizeof(double));
#	elif MC_TARGET_C11 && defined(__STDC_LIB_EXT1__)
	if (n > 0) {
		memcpy_s(y, mc_cast(size_t, n) * sizeof(double), x, mc_cast(size_t, n) * sizeof(double));
	}
#	else
	int i = 0;
	for (; i < n; i++) {
		y[i] = x[i];
	}
#	endif
}

MC_TARGET_FUNC void mc_copy1xnl(int n, long double * y, const long double * x)
{
#	if MC_TARGET_CPP98
		::memcpy(y, x, n * sizeof(long double));
#	elif MC_TARGET_C11 && defined(__STDC_LIB_EXT1__)
	if (n > 0) {
		memcpy_s(y, mc_cast(size_t, n) * sizeof(long double), x, mc_cast(size_t, n) * sizeof(long double));
	}
#	else
	int i = 0;
	for (; i < n; i++) {
		y[i] = x[i];
	}
#	endif
}

#endif /* !MC_COPY1XN_H */

/* EOF */