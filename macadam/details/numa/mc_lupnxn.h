//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_lupnxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/numa/mc_eyenxn.h>
#include <macadam/mcswap.h>

#ifndef MC_LUPNXN_H
#define MC_LUPNXN_H

#pragma mark - mc_lupnxn -

MC_TARGET_FUNC int mc_lupnxnf(int n, const float * a, float * lu, float * restrict p)
{
//!# A and LU may be the same.
//!# Returns A=(LU)P, L and U being combined.
	int pv = 0, i, j, k, m, r;
	float w, h;
	if (a != lu) {
		for (i = 0; i < (n * n); i++) { 
			lu[i] = a[i];
		}
	}
	mc_eyenxnf(n, p);

	for (i = 0; i < n; i++) { 
		w = 0.0f;
		for (m = i; m < n; m++) {
			h = lu[(n * m) + i];
			for (k = 0; k < i; k++) {
				 h = h - (lu[(n * m) + k] * lu[(n * k) + m]);
			}
			if (mc_fabsf(h) > w) {
				 w = mc_fabsf(h);
				 r = m;
			}
		}

		if (i != r) {
			++pv;
			for (k = 0; k < n; k++) {
				mcswap_var(w,  p[(n * i) + k],  p[(n * r) + k]);
				mcswap_var(w, lu[(n * i) + k], lu[(n * r) + k]);
			}
		}

		for (j = i; j < n; j++) {
			for (k = 0; k < i; k++) {
				lu[(n * i) + j] = lu[(n * i) + j] - (lu[(n * i) + k] * lu[(n * k) + j]);
			}
		}

		for (j = (i + 1); j < n; j++) {
			for (k = 0; k < i; k++) {
				lu[(n * j) + i] = lu[(n * j) + i] - (lu[(n * j) + k] * lu[(n * k) + i]);
			}
			w = lu[(n * i) + i];
			if (w == 0.0f) {
				mc_eyenxnf(n, lu);
				mc_eyenxnf(n, p);
				return -1;
			}
			lu[(n * j) + i] = lu[(n * j) + i] / w;
		} 
	}
	return pv;
}

MC_TARGET_FUNC int mc_lupnxnff(int n, const float * a, double * lu, double * restrict p)
{
//!# A and LU may be the same.
//!# Returns A=(LU)P, L and U being combined.
	int pv = 0, i, j, k, m, r;
	double w, h;

	for (i = 0; i < (n * n); i++) { 
		lu[i] = mc_cast(double, a[i]);
	}
	mc_eyenxn(n, p);

	for (i = 0; i < n; i++) { 
		w = 0.0;
		for (m = i; m < n; m++) {
			h = lu[(n * m) + i];
			for (k = 0; k < i; k++) {
				 h = h - (lu[(n * m) + k] * lu[(n * k) + m]);
			}
			if (mc_fabs(h) > w) {
				 w = mc_fabs(h);
				 r = m;
			}
		}

		if (i != r) {
			++pv;
			for (k = 0; k < n; k++) {
				mcswap_var(w,  p[(n * i) + k],  p[(n * r) + k]);
				mcswap_var(w, lu[(n * i) + k], lu[(n * r) + k]);
			}
		}

		for (j = i; j < n; j++) {
			for (k = 0; k < i; k++) {
				 lu[(n * i) + j] = lu[(n * i) + j] - (lu[(n * i) + k] * lu[(n * k) + j]);
			}
		}

		for (j = (i + 1); j < n; j++) {
			for (k = 0; k < i; k++) {
				lu[(n * j) + i] = lu[(n * j) + i] - (lu[(n * j) + k] * lu[(n * k) + i]);
			}
			w = lu[(n * i) + i];
			if (w == 0.0) {
				mc_eyenxn(n, lu);
				mc_eyenxn(n, p);
				return -1;
			}
			lu[(n * j) + i] = lu[(n * j) + i] / w;
		} 
	}
	return pv;
}

MC_TARGET_FUNC int mc_lupnxn(int n, const double * a, double * lu, double * restrict p)
{
//!# A and LU may be the same.
//!# Returns A=(LU)P, L and U being combined.
	int pv = 0, i, j, k, m, r;
	double w, h;

	if (a != lu) {
		for (i = 0; i < (n * n); i++) { 
			lu[i] = a[i];
		}
	}
	mc_eyenxn(n, p);

	for (i = 0; i < n; i++) { 
		w = 0.0;
		for (m = i; m < n; m++) {
			h = lu[(n * m) + i];
			for (k = 0; k < i; k++) {
				 h = h - (lu[(n * m) + k] * lu[(n * k) + m]);
			}
			if (mc_fabs(h) > w) {
				 w = mc_fabs(h);
				 r = m;
			}
		}

		if (i != r) {
			++pv;
			for (k = 0; k < n; k++) {
				mcswap_var(w,  p[(n * i) + k],  p[(n * r) + k]);
				mcswap_var(w, lu[(n * i) + k], lu[(n * r) + k]);
			}
		}

		for (j = i; j < n; j++) {
			for (k = 0; k < i; k++) {
				 lu[(n * i) + j] = lu[(n * i) + j] - (lu[(n * i) + k] * lu[(n * k) + j]);
			}
		}

		for (j = (i + 1); j < n; j++) {
			for (k = 0; k < i; k++) {
				lu[(n * j) + i] = lu[(n * j) + i] - (lu[(n * j) + k] * lu[(n * k) + i]);
			}
			w = lu[(n * i) + i];
			if (w == 0.0) {
				mc_eyenxn(n, lu);
				mc_eyenxn(n, p);
				return -1;
			}
			lu[(n * j) + i] = lu[(n * j) + i] / w;
		} 
	}
	return pv;
}

MC_TARGET_FUNC int mc_lupnxnl(int n, const long double * a, long double * lu, long double * restrict p)
{
//!# A and LU may be the same.
	int pv = 0, i, j, k, m, r;
	long double w, h;

	if (a != lu) {
		for (i = 0; i < (n * n); i++) { 
			lu[i] = a[i];
		}
	}
	mc_eyenxnl(n, p);

	for (i = 0; i < n; i++) { 
		w = 0.0L;
		for (m = i; m < n; m++) {
			h = lu[(n * m) + i];
			for (k = 0; k < i; k++) {
				 h = h - (lu[(n * m) + k] * lu[(n * k) + m]);
			}
			if (mc_fabsl(h) > w) {
				 w = mc_fabsl(h);
				 r = m;
			}
		}

		if (i != r) {
			++pv;
			for (k = 0; k < n; k++) {
				mcswap_var(w,  p[(n * i) + k],  p[(n * r) + k]);
				mcswap_var(w, lu[(n * i) + k], lu[(n * r) + k]);
			}
		}

		for (j = i; j < n; j++) {
			for (k = 0; k < i; k++) {
				 lu[(n * i) + j] = lu[(n * i) + j] - (lu[(n * i) + k] * lu[(n * k) + j]);
			}
		}

		for (j = (i + 1); j < n; j++) {
			for (k = 0; k < i; k++) {
				lu[(n * j) + i] = lu[(n * j) + i] - (lu[(n * j) + k] * lu[(n * k) + i]);
			}
			w = lu[(n * i) + i];
			if (w == 0.0L) {
				mc_eyenxnl(n, lu);
				mc_eyenxnl(n, p);
				return -1;
			}
			lu[(n * j) + i] = lu[(n * j) + i] / w;
		} 
	}
	return pv;
}

#endif /* !MC_LUPNXN_H */

/* EOF */