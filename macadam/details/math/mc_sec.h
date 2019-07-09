//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_sec.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_cos.h>

#ifndef MC_SEC_H
#define MC_SEC_H

#pragma mark - mc_sec -

static MC_TARGET_INLINE float mc_secf(float x)
{
	return 1.0f / mc_cosf(x);
}

static MC_TARGET_INLINE double mc_sec(double x)
{
	return 1.0 / mc_cos(x);
}

static MC_TARGET_INLINE long double mc_secl(long double x)
{
	return 1.0L / mc_cosl(x);
}

#endif /* !MC_SEC_H */

/* EOF */