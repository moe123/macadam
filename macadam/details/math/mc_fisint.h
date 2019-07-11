//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_fisint.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_trunc.h>
#include <macadam/details/math/mc_ffrac.h>

#ifndef MC_FISINT_H
#define MC_FISINT_H

#pragma mark - mc_fisint -

static MC_TARGET_INLINE int mc_fisintf(float x)
{
	if (x == mc_truncf(x)) {
		return 1;
	}
	if (0.0f == mc_ffracf(x)) {
		return 1;
	}
	return 0;
}

static MC_TARGET_INLINE double mc_fisint(double x)
{
	if (x == mc_trunc(x)) {
		return 1;
	}
	if (0.0 == mc_ffrac(x)) {
		return 1;
	}
	return 0;
}

static MC_TARGET_INLINE long double mc_fisintl(long double x)
{
	if (x == mc_truncl(x)) {
		return 1;
	}
	if (0.0 == mc_ffracl(x)) {
		return 1;
	}
	return 0;
}

#endif /* !MC_FISINT_H */

/* EOF */