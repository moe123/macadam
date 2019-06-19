//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_log1pe.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_log1p.h>

#ifndef MC_LOG1PE_H
#define MC_LOG1PE_H

#pragma mark - mc_log1pe -

static MC_TARGET_INLINE float mc_log1pef(float x)
{
#	if MC_TARGET_CPP98
	return mc_log1pf(::expf(x));
#	else
	return mc_log1pf(expf(x));
#	endif
}

static MC_TARGET_INLINE double mc_log1pe(double x)
{
#	if MC_TARGET_CPP98
	return mc_log1p(::exp(x));
#	else
	return mc_log1p(exp(x));
#	endif
}

static MC_TARGET_INLINE long double mc_log1pel(long double x)
{
#	if MC_TARGET_CPP98
	return mc_log1pl(::expl(x));
#	else
	return mc_log1pl(expl(x));
#	endif
}

#endif /* !MC_LOG1PE_H */

/* EOF */