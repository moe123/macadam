//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_infnormmxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>

#ifndef MC_INFNORMMXN_H
#define MC_INFNORMMXN_H

#pragma mark - mc_infnormmxn -

MC_TARGET_FUNC float mc_infnormmxnf(int m, int n, const float * a, int f)
{
//!# Requires a[m x n]. Returning the infinity norm of a.
//!# f=0: computing the maximum of the absolute row sums.
//!# f=1: computing the minimum of the absolute row sums.
	int i = 0, j;
	float nrm = 0.0f, sum;
	for (; i < m ; i++) {
		sum = 0.0f;
		for (j = 0 ; j < n ; j++) {
			sum = sum + mc_fabsf(a[(n * i) + j]);
		}
		nrm = (f == 1) ? ((nrm > sum) ? sum : nrm) : ((nrm > sum) ? nrm : sum);
	}
	return nrm;
}

MC_TARGET_FUNC double mc_infnormmxnff(int m, int n, const float * a, int f)
{
//!# Requires a[m x n]. Returning the infinity norm of a.
//!# f=0: computing the maximum of the absolute row sums.
//!# f=1: computing the minimum of the absolute row sums.
	int i = 0, j;
	double nrm = 0.0, sum;
	for (; i < m ; i++) {
		sum = 0.0;
		for (j = 0 ; j < n ; j++) {
			sum = sum + mc_fabs(mc_cast(double, a[(n * i) + j]));
		}
		nrm = (f == 1) ? ((nrm > sum) ? sum : nrm) : ((nrm > sum) ? nrm : sum);
	}
	return nrm;
}

MC_TARGET_FUNC double mc_infnormmxn(int m, int n, const double * a, int f)
{
//!# Requires a[m x n]. Returning the infinity norm of a.
//!# f=0: computing the maximum of the absolute row sums.
//!# f=1: computing the minimum of the absolute row sums.
	int i = 0, j;
	double nrm = 0.0, sum;
	for (; i < m ; i++) {
		sum = 0.0;
		for (j = 0 ; j < n ; j++) {
			sum = sum + mc_fabs(a[(n * i) + j]);
		}
		nrm = (f == 1) ? ((nrm > sum) ? sum : nrm) : ((nrm > sum) ? nrm : sum);
	}
	return nrm;
}

MC_TARGET_FUNC long double mc_infnormmxnl(int m, int n, const long double * a, int f)
{
//!# Requires a[m x n]. Returning the infinity norm of a.
//!# f=0: computing the maximum of the absolute row sums.
//!# f=1: computing the minimum of the absolute row sums.
	int i = 0, j;
	long double nrm = 0.0L, sum;
	for (; i < m ; i++) {
		sum = 0.0L;
		for (j = 0 ; j < n ; j++) {
			sum = sum + mc_fabsl(a[(n * i) + j]);
		}
		nrm = (f == 1) ? ((nrm > sum) ? sum : nrm) : ((nrm > sum) ? nrm : sum);
	}
	return nrm;
}

#endif /* !MC_INFNORMMXN_H */

/* EOF */