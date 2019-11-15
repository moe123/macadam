//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_mulab3x3.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_MULAB3X3_H
#define MC_MULAB3X3_H

#pragma mark - mc_mulab3x3 -

MC_TARGET_FUNC void mc_mulab3x3f(float * restrict c, const float a[9], const float b[9])
{
//!# c=a*b
	c[0] = (a[0] * b[0]) + (a[1] * b[3]) + (a[2] * b[6]);
	c[1] = (a[0] * b[1]) + (a[1] * b[4]) + (a[2] * b[7]);
	c[2] = (a[0] * b[2]) + (a[1] * b[5]) + (a[2] * b[8]);

	c[3] = (a[3] * b[0]) + (a[4] * b[3]) + (a[5] * b[6]);
	c[4] = (a[3] * b[1]) + (a[4] * b[4]) + (a[5] * b[7]);
	c[5] = (a[3] * b[2]) + (a[4] * b[5]) + (a[5] * b[8]);

	c[6] = (a[6] * b[0]) + (a[7] * b[3]) + (a[8] * b[6]);
	c[7] = (a[6] * b[1]) + (a[7] * b[4]) + (a[8] * b[7]);
	c[8] = (a[6] * b[2]) + (a[7] * b[5]) + (a[8] * b[8]);
}

MC_TARGET_FUNC void mc_mulab3x3(double * restrict c, double a[9], double b[9])
{
//!# c=a*b
	c[0] = (a[0] * b[0]) + (a[1] * b[3]) + (a[2] * b[6]);
	c[1] = (a[0] * b[1]) + (a[1] * b[4]) + (a[2] * b[7]);
	c[2] = (a[0] * b[2]) + (a[1] * b[5]) + (a[2] * b[8]);

	c[3] = (a[3] * b[0]) + (a[4] * b[3]) + (a[5] * b[6]);
	c[4] = (a[3] * b[1]) + (a[4] * b[4]) + (a[5] * b[7]);
	c[5] = (a[3] * b[2]) + (a[4] * b[5]) + (a[5] * b[8]);

	c[6] = (a[6] * b[0]) + (a[7] * b[3]) + (a[8] * b[6]);
	c[7] = (a[6] * b[1]) + (a[7] * b[4]) + (a[8] * b[7]);
	c[8] = (a[6] * b[2]) + (a[7] * b[5]) + (a[8] * b[8]);
}

MC_TARGET_FUNC void mc_mulab3x3l(long double * restrict c, long double a[9], long double b[9])
{
//!# c=a*b
	c[0] = (a[0] * b[0]) + (a[1] * b[3]) + (a[2] * b[6]);
	c[1] = (a[0] * b[1]) + (a[1] * b[4]) + (a[2] * b[7]);
	c[2] = (a[0] * b[2]) + (a[1] * b[5]) + (a[2] * b[8]);

	c[3] = (a[3] * b[0]) + (a[4] * b[3]) + (a[5] * b[6]);
	c[4] = (a[3] * b[1]) + (a[4] * b[4]) + (a[5] * b[7]);
	c[5] = (a[3] * b[2]) + (a[4] * b[5]) + (a[5] * b[8]);

	c[6] = (a[6] * b[0]) + (a[7] * b[3]) + (a[8] * b[6]);
	c[7] = (a[6] * b[1]) + (a[7] * b[4]) + (a[8] * b[7]);
	c[8] = (a[6] * b[2]) + (a[7] * b[5]) + (a[8] * b[8]);
}

#endif /* !MC_MULAB3X3_H */

/* EOF */