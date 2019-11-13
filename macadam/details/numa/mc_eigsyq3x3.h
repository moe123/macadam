//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_eigsyq3x3.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_tredql3x3.h>
#include <macadam/details/numa/mc_tredsy3x3.h>
#include <macadam/mcswap.h>

#ifndef MC_EIGSYQ3X3_H
#define MC_EIGSYQ3X3_H

#pragma mark - mc_eigsyq3x3f -

MC_TARGET_PROC int mc_eigsyq3x3f(const float a[9], float e[3], float * v)
{
	int r;
	float w[3] = { 0 };
	if (0 == (r = mc_tredsy3x3f(a, v, e, w))) {
		if (0 == (r = mc_tredql3x3f(v, e, w))) {
			if (mc_nonnull(v)) {
				if (mc_fabsf(e[0]) > mc_fabsf(e[1])) {
					mcswap_var(w[0], e[0], e[1]);
					mcswap_var(w[0], v[0], v[1]);
					mcswap_var(w[0], v[3], v[4]);
					mcswap_var(w[0], v[6], v[7]);
				}
				if (mc_fabsf(e[0]) > mc_fabsf(e[2])) {
					mcswap_var(w[0], e[0], e[2]);
					mcswap_var(w[0], v[0], v[2]);
					mcswap_var(w[0], v[3], v[5]);
					mcswap_var(w[0], v[6], v[8]);
				}
				if (mc_fabsf(e[1]) > mc_fabsf(e[2])) {
					mcswap_var(w[0], e[1], e[2]);
					mcswap_var(w[0], v[1], v[2]);
					mcswap_var(w[0], v[4], v[5]);
					mcswap_var(w[0], v[7], v[8]);
				}
			}
		}
	}
	return r;
}

MC_TARGET_PROC int mc_eigsyq3x3(const double a[9], double e[3], double * v)
{
	int r;
	double w[3] = { 0 };
	if (0 == (r = mc_tredsy3x3(a, v, e, w))) {
		if (0 == (r = mc_tredql3x3(v, e, w))) {
			if (mc_nonnull(v)) {
				if (mc_fabs(e[0]) > mc_fabs(e[1])) {
					mcswap_var(w[0], e[0], e[1]);
					mcswap_var(w[0], v[0], v[1]);
					mcswap_var(w[0], v[3], v[4]);
					mcswap_var(w[0], v[6], v[7]);
				}
				if (mc_fabs(e[0]) > mc_fabs(e[2])) {
					mcswap_var(w[0], e[0], e[2]);
					mcswap_var(w[0], v[0], v[2]);
					mcswap_var(w[0], v[3], v[5]);
					mcswap_var(w[0], v[6], v[8]);
				}
				if (mc_fabs(e[1]) > mc_fabs(e[2])) {
					mcswap_var(w[0], e[1], e[2]);
					mcswap_var(w[0], v[1], v[2]);
					mcswap_var(w[0], v[4], v[5]);
					mcswap_var(w[0], v[7], v[8]);
				}
			}
		}
	}
	return r;
}

MC_TARGET_PROC int mc_eigsyq3x3l(const long double a[9], long double e[3], long double * v)
{
	int r;
	long double w[3] = { 0 };
	if (0 == (r = mc_tredsy3x3l(a, v, e, w))) {
		if (0 == (r = mc_tredql3x3l(v, e, w))) {
			if (mc_nonnull(v)) {
				if (mc_fabsl(e[0]) > mc_fabsl(e[1])) {
					mcswap_var(w[0], e[0], e[1]);
					mcswap_var(w[0], v[0], v[1]);
					mcswap_var(w[0], v[3], v[4]);
					mcswap_var(w[0], v[6], v[7]);
				}
				if (mc_fabsl(e[0]) > mc_fabsl(e[2])) {
					mcswap_var(w[0], e[0], e[2]);
					mcswap_var(w[0], v[0], v[2]);
					mcswap_var(w[0], v[3], v[5]);
					mcswap_var(w[0], v[6], v[8]);
				}
				if (mc_fabsl(e[1]) > mc_fabsl(e[2])) {
					mcswap_var(w[0], e[1], e[2]);
					mcswap_var(w[0], v[1], v[2]);
					mcswap_var(w[0], v[4], v[5]);
					mcswap_var(w[0], v[7], v[8]);
				}
			}
		}
	}
	return r;
}

#endif /* !MC_EIGSYQ3X3_H */

/* EOF */