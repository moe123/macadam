//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_centermxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_meanmx1.h>
#include <macadam/details/numa/mc_mstddmx1.h>

#ifndef MC_CENTERMXN_H
#define MC_CENTERMXN_H

#pragma mark - mc_centermxn -

MC_TARGET_FUNC void mc_centermxnf(int m, int n, float * c, const float * a, int f)
{
//!# Requires c[m x n] and a[m x n] where 1 < n <= m. C and A may be
//!# the same. Centering A matrix to its column mean.
	int i, j = 0;
	float mj, wj;
	switch (f) {
		case 0:
			for (; j < n; j++) {
				mj = mc_meanmx1f(m, n, j, a, 1, 5);
				for (i = 0; i < m; i++) {
					c[(n * i) + j] = a[(n * i) + j] - mj;
				}
			}
		break;
		case 1:
			for (; j < n; j++) {
				mc_mstddmx1f(m, n, j, a, 1, &mj, &wj);
				if (wj != 0.0f ) {
					wj = 1.0f / wj;
				}
				for (i = 0; i < m; i++) {
					c[(n * i) + j] = (a[(n * i) + j] - mj) * wj;
				}
			}
		break;
		case 2:
			mj = mc_meanmx1f(m, n, j, a, 1, 5);
			wj = mc_hypot2f(1.0f, mj);
			if (wj != 0.0f ) {
				wj = 1.0f / wj;
			}
			for (i = 0; i < m; i++) {
				c[(n * i) + j] = (a[(n * i) + j] - mj) * wj;
			}
		break;
	}
}

MC_TARGET_FUNC void mc_centermxnff(int m, int n, double * c, const float * a, int f)
{
//!# Requires c[m x n] and a[m x n] where 1 < n <= m. Centering
//!# A matrix to its column mean.
	int i, j = 0;
	double mj, wj;
	switch (f) {
		case 0:
			for (; j < n; j++) {
				mj = mc_meanmx1ff(m, n, j, a, 1, 5);
				for (i = 0; i < m; i++) {
					c[(n * i) + j] = mc_cast(double, a[(n * i) + j]) - mj;
				}
			}
		break;
		case 1:
			for (; j < n; j++) {
				mc_mstddmx1ff(m, n, j, a, 1, &mj, &wj);
				if (wj != 0.0) {
					wj = 1.0 / wj;
				}
				for (i = 0; i < m; i++) {
					c[(n * i) + j] = (mc_cast(double, a[(n * i) + j]) - mj) * wj;
				}
			}
		break;
		case 2:
			mj = mc_meanmx1ff(m, n, j, a, 1, 5);
			wj = mc_hypot2(1.0, mj);
			if (wj != 0.0) {
				wj = 1.0 / wj;
			}
			for (i = 0; i < m; i++) {
				c[(n * i) + j] = (mc_cast(double, a[(n * i) + j]) - mj) * wj;
			}
		break;
	}
}


MC_TARGET_FUNC void mc_centermxn(int m, int n, double * c, const double * a, int f)
{
//!# Requires c[m x n] and a[m x n] where 1 < n <= m. C and A may be
//!# the same. Centering A matrix to its column mean.
	int i, j = 0;
	double mj, wj;
	switch (f) {
		case 0:
			for (; j < n; j++) {
				mj = mc_meanmx1(m, n, j, a, 1, 5);
				for (i = 0; i < m; i++) {
					c[(n * i) + j] = a[(n * i) + j] - mj;
				}
			}
		break;
		case 1:
			for (; j < n; j++) {
				mc_mstddmx1(m, n, j, a, 1, &mj, &wj);
				if (wj != 0.0) {
					wj = 1.0 / wj;
				}
				for (i = 0; i < m; i++) {
					c[(n * i) + j] = (a[(n * i) + j] - mj) * wj;
				}
			}
		break;
		case 2:
			mj = mc_meanmx1(m, n, j, a, 1, 5);
			wj = mc_hypot2(1.0, mj);
			if (wj != 0.0) {
				wj = 1.0 / wj;
			}
			for (i = 0; i < m; i++) {
				c[(n * i) + j] = (a[(n * i) + j] - mj) * wj;
			}
		break;
	}
}

MC_TARGET_FUNC void mc_centermxnl(int m, int n, long double * c, const long double * a, int f)
{
//!# Requires c[m x n] and a[m x n] where 1 < n <= m. C and A may be
//!# the same. Centering A matrix to its column mean.
	int i, j = 0;
	long double mj, wj;
	switch (f) {
		case 0:
			for (; j < n; j++) {
				mj = mc_meanmx1l(m, n, j, a, 1, 5);
				for (i = 0; i < m; i++) {
					c[(n * i) + j] = a[(n * i) + j] - mj;
				}
			}
		break;
		case 1:
			for (; j < n; j++) {
				mc_mstddmx1l(m, n, j, a, 1, &mj, &wj);
				if (wj != 0.0L) {
					wj = 1.0L / wj;
				}
				for (i = 0; i < m; i++) {
					c[(n * i) + j] = (a[(n * i) + j] - mj) * wj;
				}
			}
		break;
		case 2:
			mj = mc_meanmx1l(m, n, j, a, 1, 5);
			wj = mc_hypot2l(1.0, mj);
			if (wj != 0.0L) {
				wj = 1.0L / wj;
			}
			for (i = 0; i < m; i++) {
				c[(n * i) + j] = (a[(n * i) + j] - mj) * wj;
			}
		break;
	}
}

#endif /* !MC_CENTERMXN_H */

/* EOF */