//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_trsi2x2.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcswap.h>

#ifndef MC_TRSI2X2_H
#define MC_TRSI2X2_H

#pragma mark - mc_trsi2x2 -

MC_TARGET_FUNC void mc_trsi2x2f(float a[4])
{
	float c;
	mcswap_var(c, a[1], a[2]);
}

MC_TARGET_FUNC void mc_trsi2x2(double a[4])
{
	double c;
	mcswap_var(c, a[1], a[2]);
}

MC_TARGET_FUNC void mc_trsi2x2l(long double a[4])
{
	long double c;
	mcswap_var(c, a[1], a[2]);
}

#endif /* !MC_TRSI2X2_H */

/* EOF */