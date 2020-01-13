//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_lupnxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/numa/mc_copynxn.h>
#include <macadam/details/numa/mc_eyenxn.h>
#include <macadam/mcswap.h>

#ifndef MC_LUPNXN_H
#define MC_LUPNXN_H

#pragma mark - mc_lupnxn -

MC_TARGET_FUNC int mc_lupnxnf(int n, const float * a, float * lu, float * restrict p, int * pvi)
{
//!# A and LU may be the same.
//!# Returns A=(LU)P, L and U being combined.
	const int wantpvi = mc_nonnull(pvi);
	const int wantp   = mc_nonnull(p);

	int pv = 0, i, j, k, m, r, q;
	float w, h;
	if (a != lu) {
		mc_copynxnf(n, lu, a);
	}
	if (wantpvi) {
		for (i = 0; i < n; i++) {
			pvi[i] = i;
		}
	} else if (wantp) {
		mc_eyenxnf(n, p, 0);
	}

	for (i = 0; i < n; i++) {
		w = 0.0f;
		r = i;
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
			if (wantpvi) {
				mcswap_var(q, pvi[i], pvi[r]);
			}
			for (k = 0; k < n; k++) {
				if (!wantpvi && wantp) {
					mcswap_var(w, p[(n * i) + k], p[(n * r) + k]);
				}
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
			if (w != 0.0f) {
				lu[(n * j) + i] = lu[(n * j) + i] / w;
			}
		}
	}
	return pv;
}

MC_TARGET_FUNC int mc_lupnxnff(int n, const float * a, double * lu, double * restrict p, int * pvi)
{
//!# A and LU may be the same.
//!# Returns A=(LU)P, L and U being combined.
	const int wantpvi = mc_nonnull(pvi);
	const int wantp   = mc_nonnull(p);

	int pv = 0, i, j, k, m, r, q;
	double w, h;

	mc_copynxnff(n, lu, a);

	if (wantpvi) {
		for (i = 0; i < n; i++) {
			pvi[i] = i;
		}
	} else if (wantp) {
		mc_eyenxn(n, p, 0);
	}

	for (i = 0; i < n; i++) {
		w = 0.0;
		r = i;
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
			if (wantpvi) {
				mcswap_var(q, pvi[i], pvi[r]);
			}
			for (k = 0; k < n; k++) {
				if (!wantpvi && wantp) {
					mcswap_var(w, p[(n * i) + k], p[(n * r) + k]);
				}
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
			if (w != 0.0) {
				lu[(n * j) + i] = lu[(n * j) + i] / w;
			}
		}
	}
	return pv;
}

MC_TARGET_FUNC int mc_lupnxn(int n, const double * a, double * lu, double * restrict p, int * pvi)
{
//!# A and LU may be the same.
//!# Returns A=(LU)P, L and U being combined.
	const int wantpvi = mc_nonnull(pvi);
	const int wantp   = mc_nonnull(p);

	int pv = 0, i, j, k, m, r, q;
	double w, h;

	if (a != lu) {
		mc_copynxn(n, lu, a);
	}
	if (wantpvi) {
		for (i = 0; i < n; i++) {
			pvi[i] = i;
		}
	} else if (wantp) {
		mc_eyenxn(n, p, 0);
	}

	for (i = 0; i < n; i++) {
		w = 0.0;
		r = i;
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
			if (wantpvi) {
				mcswap_var(q, pvi[i], pvi[r]);
			}
			for (k = 0; k < n; k++) {
				if (wantpvi) {
					
				} else if (wantp) {
					mcswap_var(w, p[(n * i) + k], p[(n * r) + k]);
				}
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
			if (w != 0.0) {
				lu[(n * j) + i] = lu[(n * j) + i] / w;
			}
		}
	}
	return pv;
}

MC_TARGET_FUNC int mc_lupnxnl(int n, const long double * a, long double * lu, long double * restrict p, int * pvi)
{
//!# A and LU may be the same.
//!# Returns A=(LU)P, L and U being combined.
	const int wantpvi = mc_nonnull(pvi);
	const int wantp   = mc_nonnull(p);

	int pv = 0, i, j, k, m, r, q;
	long double w, h;

	if (a != lu) {
		mc_copynxnl(n, lu, a);
	}
	if (wantpvi) {
		for (i = 0; i < n; i++) {
			pvi[i] = i;
		}
	} else if (wantp) {
		mc_eyenxnl(n, p, 0);
	}

	for (i = 0; i < n; i++) {
		w = 0.0L;
		r = i;
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
			if (wantpvi) {
				mcswap_var(q, pvi[i], pvi[r]);
			}
			for (k = 0; k < n; k++) {
				if (!wantpvi && wantp) {
					mcswap_var(w, p[(n * i) + k], p[(n * r) + k]);
				}
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
			if (w != 0.0L) {
				lu[(n * j) + i] = lu[(n * j) + i] / w;
			}
		}
	}
	return pv;
}

#endif /* !MC_LUPNXN_H */

/* EOF */