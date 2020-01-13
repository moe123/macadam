//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_trilnxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_TRILNXN_H
#define MC_TRILNXN_H

#pragma mark - mc_trilnxn -

MC_TARGET_FUNC void mc_trilnxnf(int n, float * restrict c, const float * a, int f)
{
//!# f=0: default behavior.
//!# f=1: excluding diagonal.
//!# f=2: excluding diagonal and setting it to ones.
//!# f=3: including first superdiagonal.
	int i = 0, j, k = 0;
	float d;
	switch (f)
	{
		case 1:
			k = +1;
			d = 0.0f;
		break;
		case 2:
			k = +1;
			d = 1.0f;
		break;
		case 3:
			k = -1;
			d = 0.0f;
		break;
		default:
			k = 0;
			d = 0.0f;
		break;
	}
	for (; i < n; i++) {
		for (j = 0; j < n; j++) {
			c[(n * i) + j] = (i >= j + k) ? a[(n * i) + j] : ((i == j) ? d : 0.0f);
		}
	}
}

MC_TARGET_FUNC void mc_trilnxnff(int n, double * c, const float * a, int f)
{
//!# f=0: default behavior.
//!# f=1: excluding diagonal.
//!# f=2: excluding diagonal and setting it to ones.
//!# f=3: including first superdiagonal.
	int i = 0, j, k = 0;
	double d;
	switch (f)
	{
		case 1:
			k = +1;
			d = 0.0;
		break;
		case 2:
			k = +1;
			d = 1.0;
		break;
		case 3:
			k = -1;
			d = 0.0;
		break;
		default:
			k = 0;
			d = 0.0;
		break;
	}
	for (; i < n; i++) {
		for (j = 0; j < n; j++) {
			c[(n * i) + j] = (i >= j + k) ? mc_cast(double, a[(n * i) + j]) : ((i == j) ? d : 0.0);
		}
	}
}

MC_TARGET_FUNC void mc_trilnxn(int n, double * restrict c, const double * a, int f)
{
//!# f=0: default behavior.
//!# f=1: excluding diagonal.
//!# f=2: excluding diagonal and setting it to ones.
//!# f=3: including first superdiagonal.
	int i = 0, j, k = 0;
	double d;
	switch (f)
	{
		case 1:
			k = +1;
			d = 0.0;
		break;
		case 2:
			k = +1;
			d = 1.0;
		break;
		case 3:
			k = -1;
			d = 0.0;
		break;
		default:
			k = 0;
			d = 0.0;
		break;
	}
	for (; i < n; i++) {
		for (j = 0; j < n; j++) {
			c[(n * i) + j] = (i >= j + k) ? a[(n * i) + j] : ((i == j) ? d : 0.0);
		}
	}
}

MC_TARGET_FUNC void mc_trilnxnl(int n, long double * restrict c, const long double * a, int f)
{
//!# f=0: default behavior.
//!# f=1: excluding diagonal.
//!# f=2: excluding diagonal and setting it to ones.
//!# f=3: including first superdiagonal.
	int i = 0, j, k = 0;
	double d;
	switch (f)
	{
		case 1:
			k = +1;
			d = 0.0L;
		break;
		case 2:
			k = +1;
			d = 1.0L;
		break;
		case 3:
			k = -1;
			d = 0.0L;
		break;
		default:
			k = 0;
			d = 0.0L;
		break;
	}
	for (; i < n; i++) {
		for (j = 0; j < n; j++) {
			c[(n * i) + j] = (i >= j + k) ? a[(n * i) + j] : ((i == j) ? d : 0.0L);
		}
	}
}

#endif /* !MC_TRILNXN_H */

/* EOF */