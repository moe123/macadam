//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_lapacke_lartgp.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/blas/mc_lapacke_lamch.h>
#include <macadam/details/math/mc_copysign.h>
#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_fmax.h>
#include <macadam/details/math/mc_log.h>
#include <macadam/details/math/mc_pow.h>
#include <macadam/details/math/mc_raise2.h>
#include <macadam/details/math/mc_round.h>
#include <macadam/details/math/mc_sqrt.h>

#ifndef MC_LAPACKE_LARTGP_H
#define MC_LAPACKE_LARTGP_H

#pragma mark - mc_lapacke_slartgp -

MC_TARGET_FUNC void mc_lapacke_slartgp(float f, float g, float * cs, float * sn, float * r)
{
	const float two = 2.0f, one = 1.0f, zero = 0.0f;

	const float safmin = mc_lapacke_slamch('S');
	const float eps    = mc_lapacke_slamch('E');
	const float safmn2 = mc_powf(mc_lapacke_slamch('B'), mc_roundf(mc_logf(safmin / eps) / mc_logf(mc_lapacke_slamch('B')) / two));
	const float safmx2 = one / safmn2;

	int count, i;
	float f1, g1, scale;

	if (g == zero) {
		*cs = mc_copysignf(one, f);
		*sn = zero;
		*r  = mc_fabsf(f);
	} else if (f == zero) {
		*cs = zero;
		*sn = mc_copysignf(one, g);
		*r  = mc_fabsf(g);
	} else {
		f1    = f;
		g1    = g;
		scale = mc_fmaxf(mc_fabsf(f1), mc_fabsf(g1));
		if (scale >= safmx2) {
			count = 0;
F10:
			count = count + 1;
			f1    = f1 * safmn2;
			g1    = g1 * safmn2;
			scale = mc_fmaxf(mc_fabsf(f1), mc_fabsf(g1));
			if (scale >= safmx2) {
				goto F10;
			}
			*r  = mc_sqrtf(mc_raise2f(f1) + mc_raise2f(g1));
			*cs = f1 / (*r);
			*sn = g1 / (*r);
			for (i = 1; i <= count; ++i) {
				*r = (*r) * safmx2;
			}
		} else if (scale <= safmn2) {
			count = 0;
F30:
			count = count + 1;
			f1    = f1 * safmx2;
			g1    = g1 * safmx2;
			scale = mc_fmaxf(mc_fabsf(f1), mc_fabsf(g1));
			if (scale <= safmn2) {
				goto F30;
			}
			*r  = mc_sqrtf(mc_raise2f(f1) + mc_raise2f(g1));
			*cs = f1 / (*r);
			*sn = g1 / (*r);
			for (i = 1; i <= count; ++i) {
				*r = (*r) * safmn2;
			}
		} else {
			*r = mc_sqrtf(mc_raise2f(f1) + mc_raise2f(g1));
			*cs = f1 / (*r);
			*sn = g1 / (*r);
		}
		if ((*r) < zero) {
			*cs = -(*cs);
			*sn = -(*sn);
			*r  = -(*r);
		}
	}
}

#pragma mark - mc_lapacke_dlartgp -

MC_TARGET_FUNC void mc_lapacke_dlartgp(double f, double g, double * cs, double * sn, double * r)
{
	const double two = 2.0, one = 1.0, zero = 0.0;

	const double safmin = mc_lapacke_dlamch('S');
	const double eps    = mc_lapacke_dlamch('E');
	const double safmn2 = mc_pow(mc_lapacke_dlamch('B'), mc_round(mc_log(safmin / eps) / mc_log(mc_lapacke_dlamch('B')) / two));
	const double safmx2 = one / safmn2;

	int count, i;
	double f1, g1, scale;

	if (g == zero) {
		*cs = mc_copysign(one, f);
		*sn = zero;
		*r  = mc_fabs(f);
	} else if (f == zero) {
		*cs = zero;
		*sn = mc_copysign(one, g);
		*r  = mc_fabs(g);
	} else {
		f1    = f;
		g1    = g;
		scale = mc_fmax(mc_fabs(f1), mc_fabs(g1));
		if (scale >= safmx2) {
			count = 0;
F10:
			count = count + 1;
			f1    = f1 * safmn2;
			g1    = g1 * safmn2;
			scale = mc_fmax(mc_fabs(f1), mc_fabs(g1));
			if (scale >= safmx2) {
				goto F10;
			}
			*r  = mc_sqrt(mc_raise2(f1) + mc_raise2(g1));
			*cs = f1 / (*r);
			*sn = g1 / (*r);
			for (i = 1; i <= count; ++i) {
				*r = (*r) * safmx2;
			}
		} else if (scale <= safmn2) {
			count = 0;
F30:
			count = count + 1;
			f1    = f1 * safmx2;
			g1    = g1 * safmx2;
			scale = mc_fmax(mc_fabs(f1), mc_fabs(g1));
			if (scale <= safmn2) {
				goto F30;
			}
			*r  = mc_sqrt(mc_raise2(f1) + mc_raise2(g1));
			*cs = f1 / (*r);
			*sn = g1 / (*r);
			for (i = 1; i <= count; ++i) {
				*r = (*r) * safmn2;
			}
		} else {
			*r = mc_sqrt(mc_raise2(f1) + mc_raise2(g1));
			*cs = f1 / (*r);
			*sn = g1 / (*r);
		}
		if ((*r) < zero) {
			*cs = -(*cs);
			*sn = -(*sn);
			*r  = -(*r);
		}
	}
}

#pragma mark - mc_lapacke_llartgp -

MC_TARGET_FUNC void mc_lapacke_llartgp(long double f, long double g, long double * cs, long double * sn, long double * r)
{
	const long double two = 2.0f, one = 1.0f, zero = 0.0f;

	const long double safmin = mc_lapacke_llamch('S');
	const long double eps    = mc_lapacke_llamch('E');
	const long double safmn2 = mc_powl(mc_lapacke_llamch('B'), mc_roundl(mc_logl(safmin / eps) / mc_logl(mc_lapacke_llamch('B')) / two));
	const long double safmx2 = one / safmn2;

	int count, i;
	long double f1, g1, scale;

	if (g == zero) {
		*cs = mc_copysignl(one, f);
		*sn = zero;
		*r  = mc_fabsl(f);
	} else if (f == zero) {
		*cs = zero;
		*sn = mc_copysignl(one, g);
		*r  = mc_fabsl(g);
	} else {
		f1    = f;
		g1    = g;
		scale = mc_fmaxl(mc_fabsl(f1), mc_fabsl(g1));
		if (scale >= safmx2) {
			count = 0;
F10:
			count = count + 1;
			f1    = f1 * safmn2;
			g1    = g1 * safmn2;
			scale = mc_fmaxl(mc_fabsl(f1), mc_fabsl(g1));
			if (scale >= safmx2) {
				goto F10;
			}
			*r  = mc_sqrtl(mc_raise2l(f1) + mc_raise2l(g1));
			*cs = f1 / (*r);
			*sn = g1 / (*r);
			for (i = 1; i <= count; ++i) {
				*r = (*r) * safmx2;
			}
		} else if (scale <= safmn2) {
			count = 0;
F30:
			count = count + 1;
			f1    = f1 * safmx2;
			g1    = g1 * safmx2;
			scale = mc_fmaxl(mc_fabsl(f1), mc_fabsl(g1));
			if (scale <= safmn2) {
				goto F30;
			}
			*r  = mc_sqrtl(mc_raise2l(f1) + mc_raise2l(g1));
			*cs = f1 / (*r);
			*sn = g1 / (*r);
			for (i = 1; i <= count; ++i) {
				*r = (*r) * safmn2;
			}
		} else {
			*r = mc_sqrtl(mc_raise2l(f1) + mc_raise2l(g1));
			*cs = f1 / (*r);
			*sn = g1 / (*r);
		}
		if ((*r) < zero) {
			*cs = -(*cs);
			*sn = -(*sn);
			*r  = -(*r);
		}
	}
}

#endif /* !MC_LAPACKE_LARTGP_H */

/* EOF */