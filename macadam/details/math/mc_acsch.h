//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_acsch.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_asinh.h>

#ifndef MC_ACSCH_H
#define MC_ACSCH_H

#pragma mark - mc_acsch -

MC_TARGET_FUNCTION float mc_acschf(float x)
{
	return mc_asinhf(1.0f / x);
}

MC_TARGET_FUNCTION double mc_acsch(double x)
{
	return mc_asinh(1.0 / x);
}

MC_TARGET_FUNCTION long double mc_acschl(long double x)
{
	return mc_asinhl(1.0L / x);
}

#endif /* !MC_ACSCH_H */

/* EOF */