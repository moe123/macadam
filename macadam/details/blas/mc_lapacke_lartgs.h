//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_lapacke_lartgs.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/blas/mc_lapacke_lamch.h>
#include <macadam/details/blas/mc_lapacke_lartgp.h>
#include <macadam/details/math/mc_fabs.h>

#ifndef MC_LAPACKE_LARTGS_H
#define MC_LAPACKE_LARTGS_H

#pragma mark - mc_lapacke_slartgs -

MC_TARGET_FUNC void mc_lapacke_slartgs(float x, float y, float sigma, float * cs, float * sn)
{
	const float negone = -1.0f, one = 1.0f, zero = 0.0f;

	const float thresh = mc_lapacke_slamch('E');

	float r, s, w, z;

	if ((sigma == zero && mc_fabsf(x) < thresh) || (mc_fabsf(x) == sigma && y == zero)) {
		z = zero;
		w = zero;
	} else if (sigma == zero) {
		if (x >= zero) {
			z = x;
			w = y;
		} else {
			z = -x;
			w = -y;
		}
	} else if (mc_fabsf(x) < thresh) {
		z = -sigma * sigma;
		w = zero;
	} else {
		if (x >= zero) {
			s = one;
		} else {
			s = negone;
		}
		z = s * (mc_fabsf(x) - sigma) * (s + sigma / x);
		w = s * y;
	}
	mc_lapacke_slartgp(w, z, sn, cs, &r);
}

#pragma mark - mc_lapacke_dlartgs -

MC_TARGET_FUNC void mc_lapacke_dlartgs(double x, double y, double sigma, double * cs, double * sn)
{
	const double negone = -1.0, one = 1.0, zero = 0.0;

	const double thresh = mc_lapacke_dlamch('E');

	double r, s, w, z;

	if ((sigma == zero && mc_fabs(x) < thresh) || (mc_fabs(x) == sigma && y == zero)) {
		z = zero;
		w = zero;
	} else if (sigma == zero) {
		if (x >= zero) {
			z = x;
			w = y;
		} else {
			z = -x;
			w = -y;
		}
	} else if (mc_fabs(x) < thresh) {
		z = -sigma * sigma;
		w = zero;
	} else {
		if (x >= zero) {
			s = one;
		} else {
			s = negone;
		}
		z = s * (mc_fabs(x) - sigma) * (s + sigma / x);
		w = s * y;
	}
	mc_lapacke_dlartgp(w, z, sn, cs, &r);
}

#pragma mark - mc_lapacke_llartgs -

MC_TARGET_FUNC void mc_lapacke_llartgs(long double x, long double y, long double sigma, long double * cs, long double * sn)
{
	const long double negone = -1.0, one = 1.0, zero = 0.0;

	const long double thresh = mc_lapacke_llamch('E');

	long double r, s, w, z;

	if ((sigma == zero && mc_fabsl(x) < thresh) || (mc_fabsl(x) == sigma && y == zero)) {
		z = zero;
		w = zero;
	} else if (sigma == zero) {
		if (x >= zero) {
			z = x;
			w = y;
		} else {
			z = -x;
			w = -y;
		}
	} else if (mc_fabsl(x) < thresh) {
		z = -sigma * sigma;
		w = zero;
	} else {
		if (x >= zero) {
			s = one;
		} else {
			s = negone;
		}
		z = s * (mc_fabsl(x) - sigma) * (s + sigma / x);
		w = s * y;
	}
	mc_lapacke_llartgp(w, z, sn, cs, &r);
}

#endif /* !MC_LAPACKE_LARTGS_H */

/* EOF */