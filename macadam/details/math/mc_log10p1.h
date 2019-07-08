//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_log10p1.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_log10.h>
#include <macadam/details/math/mc_log1p.h>

#ifndef  MC_LOG10P1_H
#define  MC_LOG10P1_H

#pragma mark -  mc_log10p1 -

static MC_TARGET_INLINE float  mc_log10p1f(float x)
{
	if (mc_fabsf(x) > 0.5f) {
		return mc_log10f(1.0f + x);
	}
	return MCK_KF(MCK_LOG10E) * mc_log1pf(x);
}

static MC_TARGET_INLINE double  mc_log10p1(double x)
{
	if (mc_fabs(x) > 0.5) {
		return mc_log10(1.0 + x);
	}
	return MCK_K(MCK_LOG10E) * mc_log1p(x);
}

static MC_TARGET_INLINE long double  mc_log10p1l(long double x)
{
	if (mc_fabsl(x) > 0.5) {
		return mc_log10l(1.0 + x);
	}
#	if (MC_TARGET_C99 || MC_TARGET_CPP17) && defined(M_LOG10El)
	return M_LOG10El * mc_log1pl(x);
#	else
	return MCK_KL(MCK_LOG10E) * mc_log1pl(x);
#	endif
}

#endif /* ! MC_LOG10P1_H */

/* EOF */