//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_asec.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_acos.h>

#ifndef MC_ASEC_H
#define MC_ASEC_H

#pragma mark - mc_asec -

MC_TARGET_FUNCTION float mc_asecf(float x)
{
	return mc_acosf(1.0f / x);
}

MC_TARGET_FUNCTION double mc_asec(double x)
{
	return mc_acos(1.0 / x);
}

MC_TARGET_FUNCTION long double mc_asecl(long double x)
{
	return mc_acosl(1.0L / x);
}

#endif /* !MC_ASEC_H */

/* EOF */