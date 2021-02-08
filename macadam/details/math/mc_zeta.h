//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zeta.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_zetan.h>
#include <macadam/details/math/mc_zetap.h>

#ifndef MC_ZETA_H
#define MC_ZETA_H

#pragma mark - mc_zeta -

MC_TARGET_FUNC float mc_zetaf(const float x)
{
	if (x >= 0.0f) {
		return mc_zetapf(x);
	}
	return mc_zetanf(x);
}

MC_TARGET_FUNC double mc_zeta(const double x)
{
	if (x >= 0.0) {
		return mc_zetap(x);
	}
	return mc_zetan(x);
}

MC_TARGET_FUNC long double mc_zetal(const long double x)
{
	if (x >= 0.0L) {
		return mc_zetapl(x);
	}
	return mc_zetanl(x);
}

#endif /* !MC_ZETA_H */

/* EOF */