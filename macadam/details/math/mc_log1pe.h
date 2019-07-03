//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_log1pe.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_exp.h>
#include <macadam/details/math/mc_log1p.h>

#ifndef MC_LOG1PE_H
#define MC_LOG1PE_H

#pragma mark - mc_log1pe -

static MC_TARGET_INLINE float mc_log1pef(float x)
{
	return mc_log1pf(mc_expf(x));
}

static MC_TARGET_INLINE double mc_log1pe(double x)
{
	return mc_log1p(mc_exp(x));
}

static MC_TARGET_INLINE long double mc_log1pel(long double x)
{
	return mc_log1pl(mc_expl(x));
}

#endif /* !MC_LOG1PE_H */

/* EOF */