//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_asech.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_acosh.h>

#ifndef MC_ASECH_H
#define MC_ASECH_H

#pragma mark - mc_asech -

MC_TARGET_FUNC float mc_asechf(float x)
{
	return mc_acoshf(1.0f / x);
}

MC_TARGET_FUNC double mc_asech(double x)
{
	return mc_acosh(1.0 / x);
}

MC_TARGET_FUNC long double mc_asechl(long double x)
{
	return mc_acoshl(1.0L / x);
}

#endif /* !MC_ASECH_H */

/* EOF */