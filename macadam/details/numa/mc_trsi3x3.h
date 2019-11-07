//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_trsi3x3.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcswap.h>

#ifndef MC_TRSI3X3_H
#define MC_TRSI3X3_H

#pragma mark - mc_trsi3x3 -

MC_TARGET_FUNC void mc_trsi3x3f(float a[9])
{
	float c;
	mcswap_var(c, a[3], a[1]);
	mcswap_var(c, a[2], a[6]);
	mcswap_var(c, a[7], a[5]);
}

MC_TARGET_FUNC void mc_trsi3x3(double a[9])
{
	double c;
	mcswap_var(c, a[3], a[1]);
	mcswap_var(c, a[2], a[6]);
	mcswap_var(c, a[7], a[5]);
}

MC_TARGET_FUNC void mc_trsi3x3l(long double a[9])
{
	long double c;
	mcswap_var(c, a[3], a[1]);
	mcswap_var(c, a[2], a[6]);
	mcswap_var(c, a[7], a[5]);
}

#endif /* !MC_TRSI3X3_H */

/* EOF */