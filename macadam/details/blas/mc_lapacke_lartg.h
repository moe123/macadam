//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_lapacke_lartg.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/blas/mc_lapacke_lamch.h>
#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_log.h>
#include <macadam/details/math/mc_maxmag.h>
#include <macadam/details/math/mc_pow.h>
#include <macadam/details/math/mc_raise2.h>
#include <macadam/details/math/mc_round.h>
#include <macadam/details/math/mc_sqrt.h>

#ifndef MC_LAPACKE_LARTG_H
#define MC_LAPACKE_LARTG_H

#pragma mark - mc_lapacke_slartg -

MC_TARGET_FUNC void mc_lapacke_slartg(float f, float g, float * cs, float * sn, float * r)
{
	const float two = 2.0f, one = 1.0f, zero = 0.0f;

	const float afmin = mc_lapacke_slamch('S');
	const float eps   = mc_lapacke_slamch('E');
	const float afmn2 = mc_powf(mc_lapacke_slamch('B'), mc_roundf(mc_logf(afmin / eps) / mc_logf(mc_lapacke_slamch('B')) / two));
	const float afmx2 = one / afmn2;

	int count, i;
	float f1, g1, scale;

	if (g == zero) {
		*cs = one;
		*sn = zero;
		*r  = f;
	} else if (f == zero) {
		*cs = zero;
		*sn = one;
		*r  = g;
	} else {
		f1    = f;
		g1    = g;
		scale = mc_maxmag(mc_fabsf(f1), mc_fabsf(g1));
		if (scale >= afmx2) {
			count = 0;
l10:
			count = count + 1;
			f1    = f1 * afmn2;
			g1    = g1 * afmn2;
			scale = mc_maxmag(mc_fabsf(f1), mc_fabsf(g1));
			if (scale >= afmx2) {
				goto l10;
			}
			*r  = mc_sqrtf(mc_raise2f(f1) + mc_raise2f(g1));
			*cs = f1 / (*r);
			*sn = g1 / (*r);
			for (i = 1; i <= count; ++i) {
				*r = (*r) * afmx2;
			}
		} else if (scale <= afmn2) {
			count = 0;
l30:
			count = count + 1;
			f1    = f1 * afmx2;
			g1    = g1 * afmx2;
			scale = mc_maxmag(mc_fabsf(f1), mc_fabsf(g1));
			if (scale <= afmn2) {
				goto l30;
			}
			*r  = mc_sqrtf(mc_raise2f(f1) + mc_raise2f(g1));
			*cs = f1 / (*r);
			*sn = g1 / (*r);
			for (i = 1; i <= count; ++i) {
				*r = (*r) * afmn2;
			}
		} else {
			*r = mc_sqrtf(mc_raise2f(f1) + mc_raise2f(g1));
			*cs = f1 / (*r);
			*sn = g1 / (*r);
		}
		if (mc_fabsf(f) > mc_fabsf(g) && (*cs) < zero) {
			*cs = -(*cs);
			*sn = -(*sn);
			*r  = -(*r);
		}
	}
}

#pragma mark - mc_lapacke_dlartg -

MC_TARGET_FUNC void mc_lapacke_dlartg(double f, double g, double * cs, double * sn, double * r)
{
	const double two = 2.0, one = 1.0, zero = 0.0;

	const double afmin = mc_lapacke_dlamch('S');
	const double eps   = mc_lapacke_dlamch('E');
	const double afmn2 = mc_pow(mc_lapacke_dlamch('B'), mc_round(mc_log(afmin / eps) / mc_log(mc_lapacke_dlamch('B')) / two));
	const double afmx2 = one / afmn2;

	int count, i;
	double f1, g1, scale;

	if (g == zero) {
		*cs = one;
		*sn = zero;
		*r  = f;
	} else if (f == zero) {
		*cs = zero;
		*sn = one;
		*r  = g;
	} else {
		f1    = f;
		g1    = g;
		scale = mc_maxmag(mc_fabs(f1), mc_fabs(g1));
		if (scale >= afmx2) {
			count = 0;
l10:
			count = count + 1;
			f1    = f1 * afmn2;
			g1    = g1 * afmn2;
			scale = mc_maxmag(mc_fabs(f1), mc_fabs(g1));
			if (scale >= afmx2) {
				goto l10;
			}
			*r  = mc_sqrt(mc_raise2(f1) + mc_raise2(g1));
			*cs = f1 / (*r);
			*sn = g1 / (*r);
			for (i = 1; i <= count; ++i) {
				*r = (*r) * afmx2;
			}
		} else if (scale <= afmn2) {
			count = 0;
l30:
			count = count + 1;
			f1    = f1 * afmx2;
			g1    = g1 * afmx2;
			scale = mc_maxmag(mc_fabs(f1), mc_fabs(g1));
			if (scale <= afmn2) {
				goto l30;
			}
			*r  = mc_sqrt(mc_raise2(f1) + mc_raise2(g1));
			*cs = f1 / (*r);
			*sn = g1 / (*r);
			for (i = 1; i <= count; ++i) {
				*r = (*r) * afmn2;
			}
		} else {
			*r = mc_sqrt(mc_raise2(f1) + mc_raise2(g1));
			*cs = f1 / (*r);
			*sn = g1 / (*r);
		}
		if (mc_fabs(f) > mc_fabs(g) && (*cs) < zero) {
			*cs = -(*cs);
			*sn = -(*sn);
			*r  = -(*r);
		}
	}
}

#pragma mark - mc_lapacke_llartg -

MC_TARGET_FUNC void mc_lapacke_llartg(long double f, long double g, long double * cs, long double * sn, long double * r)
{
	const long double two = 2.0f, one = 1.0f, zero = 0.0f;

	const long double afmin = mc_lapacke_llamch('S');
	const long double eps   = mc_lapacke_llamch('E');
	const long double afmn2 = mc_powl(mc_lapacke_llamch('B'), mc_roundl(mc_logl(afmin / eps) / mc_logl(mc_lapacke_llamch('B')) / two));
	const long double afmx2 = one / afmn2;

	int count, i;
	long double f1, g1, scale;

	if (g == zero) {
		*cs = one;
		*sn = zero;
		*r  = f;
	} else if (f == zero) {
		*cs = zero;
		*sn = one;
		*r  = g;
	} else {
		f1    = f;
		g1    = g;
		scale = mc_maxmag(mc_fabsl(f1), mc_fabsl(g1));
		if (scale >= afmx2) {
			count = 0;
l10:
			count = count + 1;
			f1    = f1 * afmn2;
			g1    = g1 * afmn2;
			scale = mc_maxmag(mc_fabsl(f1), mc_fabsl(g1));
			if (scale >= afmx2) {
				goto l10;
			}
			*r  = mc_sqrtl(mc_raise2l(f1) + mc_raise2l(g1));
			*cs = f1 / (*r);
			*sn = g1 / (*r);
			for (i = 1; i <= count; ++i) {
				*r = (*r) * afmx2;
			}
		} else if (scale <= afmn2) {
			count = 0;
l30:
			count = count + 1;
			f1    = f1 * afmx2;
			g1    = g1 * afmx2;
			scale = mc_maxmag(mc_fabsl(f1), mc_fabsl(g1));
			if (scale <= afmn2) {
				goto l30;
			}
			*r  = mc_sqrtl(mc_raise2l(f1) + mc_raise2l(g1));
			*cs = f1 / (*r);
			*sn = g1 / (*r);
			for (i = 1; i <= count; ++i) {
				*r = (*r) * afmn2;
			}
		} else {
			*r = mc_sqrtl(mc_raise2l(f1) + mc_raise2l(g1));
			*cs = f1 / (*r);
			*sn = g1 / (*r);
		}
		if (mc_fabsl(f) > mc_fabsl(g) && (*cs) < zero) {
			*cs = -(*cs);
			*sn = -(*sn);
			*r  = -(*r);
		}
	}
}

#endif /* !MC_LAPACKE_LARTG_H */

/* EOF */