//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_nnz1xn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_NNZ1XN_H
#define MC_NNZ1XN_H

#pragma mark - mc_nnz1xn -

MC_TARGET_FUNC int mc_nnz1xnf(int n, const float * x)
{
	int i = 0, c = 0;
	for (; i < n; i++) {
		if (x[i] != 0.0f) { ++c; }
	}
	return c;
}

MC_TARGET_FUNC int mc_nnz1xn(int n, const double * x)
{
	int i = 0, c = 0;
	for (; i < n; i++) {
		if (x[i] != 0.0) { ++c; }
	}
	return c;
}

MC_TARGET_FUNC int mc_nnz1xnl(int n, const long double * x)
{
	int i = 0, c = 0;
	for (; i < n; i++) {
		if (x[i] != 0.0L) { ++c; }
	}
	return c;
}

#endif /* !MC_NNZ1XN_H */

/* EOF */