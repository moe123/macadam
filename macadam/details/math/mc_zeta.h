//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zeta.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_zetap.h>

#ifndef MC_ZETA_H
#define MC_ZETA_H

#pragma mark - mc_zeta -

MC_TARGET_FUNCTION float mc_zetaf(float x)
{
	if (x >= 0.0) {
		return mc_zetapf(x);
	}
	return MCK_NAN;
}

MC_TARGET_FUNCTION double mc_zeta(double x)
{
	if (x >= 0.0) {
		return mc_zetap(x);
	}
	return MCK_NAN;
}

MC_TARGET_FUNCTION long double mc_zetal(long double x)
{
	if (x >= 0.0L) {
		return mc_zetapl(x);
	}
	return MCK_NAN;
}

#endif /* !MC_ZETA_H */

/* EOF */