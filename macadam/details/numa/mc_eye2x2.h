//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_eye2x2.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_EYE2X2_H
#define MC_EYE2X2_H

#pragma mark - mc_eye2x2 -

MC_TARGET_FUNC void mc_eye2x2f(float a[MC_TARGET_NONNULL 4])
{
	a[0] = 1.0f; a[1] = 0.0f;
	a[2] = 0.0f; a[3] = 1.0f;
}

MC_TARGET_FUNC void mc_eye2x2(double a[MC_TARGET_NONNULL 4])
{
	a[0] = 1.0; a[1] = 0.0;
	a[2] = 0.0; a[3] = 1.0;
}

MC_TARGET_FUNC void mc_eye2x2l(long double a[MC_TARGET_NONNULL 4])
{
	a[0] = 1.0L; a[1] = 0.0L;
	a[2] = 0.0L; a[3] = 1.0L;
}

#endif /* !MC_EYE2X2_H */

/* EOF */