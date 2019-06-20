//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_rootn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_nthroot.h>

#ifndef MC_ROOTN_H
#define MC_ROOTN_H

#pragma mark - mc_rootn -

static MC_TARGET_INLINE float mc_rootnf(float x, unsigned int n)
{
	return mc_nthrootf(x, n);
}

static MC_TARGET_INLINE double mc_rootn(double x, unsigned int n)
{
	return mc_nthroot(x, n);
}

static MC_TARGET_INLINE long double mc_rootnl(long double x, unsigned int n)
{
	return mc_nthrootl(x, n);
}

#endif /* !MC_ROOTN_H */

/* EOF */