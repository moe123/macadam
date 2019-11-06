//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_det3x3.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcswap.h>

#ifndef MC_DET3X3_H
#define MC_DET3X3_H

#pragma mark - mc_det3x3 -

MC_TARGET_FUNC float mc_det3x3f(const float MC_TARGET_NONNULL(a, 9))
{
	return a[0] * ((a[4] * a[8]) - (a[7] * a[5]))
		  - a[1] * (a[3]  * a[8]  - a[6]  * a[5])
		  + a[2] * (a[3]  * a[7]  - a[6]  * a[4]);
}

MC_TARGET_FUNC double mc_det3x3(const double MC_TARGET_NONNULL(a, 9))
{
	return a[0] * ((a[4] * a[8]) - (a[7] * a[5]))
		  - a[1] * (a[3]  * a[8]  - a[6]  * a[5])
		  + a[2] * (a[3]  * a[7]  - a[6]  * a[4]);
}

MC_TARGET_FUNC long double mc_det3x3l(const long double MC_TARGET_NONNULL(a, 9))
{
	return a[0] * ((a[4] * a[8]) - (a[7] * a[5]))
		  - a[1] * (a[3]  * a[8]  - a[6]  * a[5])
		  + a[2] * (a[3]  * a[7]  - a[6]  * a[4]);
}

#endif /* !MC_DET3X3_H */

/* EOF */