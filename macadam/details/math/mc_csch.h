//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_csch.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_sinh.h>

#ifndef MC_CSCH_H
#define MC_CSCH_H

#pragma mark - mc_csch -

MC_TARGET_FUNCTION float mc_cschf(float x)
{
	return 1.0f / mc_sinhf(x);
}

MC_TARGET_FUNCTION double mc_csch(double x)
{
	return 1.0 / mc_sinh(x);
}

MC_TARGET_FUNCTION long double mc_cschl(long double x)
{
	return 1.0L / mc_sinhl(x);
}

#endif /* !MC_CSCH_H */

/* EOF */