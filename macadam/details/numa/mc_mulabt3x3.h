//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_mulabt3x3.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_MULABT3X3_H
#define MC_MULABT3X3_H

#pragma mark - mc_mulabt3x3 -

MC_TARGET_FUNC void mc_mulabt3x3f(float * c, const float a[9], const float b[9])
{
//!# c=a*b'
		c[0] = (a[0] * b[0]) + (a[1] * b[1]) + (a[2] * b[2]);
		c[1] = (a[0] * b[3]) + (a[1] * b[4]) + (a[2] * b[5]);
		c[2] = (a[0] * b[6]) + (a[1] * b[7]) + (a[2] * b[8]);

		c[3] = (a[3] * b[0]) + (a[4] * b[1]) + (a[5] * b[2]);
		c[4] = (a[3] * b[3]) + (a[4] * b[4]) + (a[5] * b[5]);
		c[5] = (a[3] * b[6]) + (a[4] * b[7]) + (a[5] * b[8]);

		c[6] = (a[6] * b[0]) + (a[7] * b[1]) + (a[8] * b[2]);
		c[7] = (a[6] * b[3]) + (a[7] * b[4]) + (a[8] * b[5]);
		c[8] = (a[6] * b[6]) + (a[7] * b[7]) + (a[8] * b[8]);
}

MC_TARGET_FUNC void mc_mulabt3x3(double * c, double a[9], double b[9])
{
//!# c=a*b'
		c[0] = (a[0] * b[0]) + (a[1] * b[1]) + (a[2] * b[2]);
		c[1] = (a[0] * b[3]) + (a[1] * b[4]) + (a[2] * b[5]);
		c[2] = (a[0] * b[6]) + (a[1] * b[7]) + (a[2] * b[8]);

		c[3] = (a[3] * b[0]) + (a[4] * b[1]) + (a[5] * b[2]);
		c[4] = (a[3] * b[3]) + (a[4] * b[4]) + (a[5] * b[5]);
		c[5] = (a[3] * b[6]) + (a[4] * b[7]) + (a[5] * b[8]);

		c[6] = (a[6] * b[0]) + (a[7] * b[1]) + (a[8] * b[2]);
		c[7] = (a[6] * b[3]) + (a[7] * b[4]) + (a[8] * b[5]);
		c[8] = (a[6] * b[6]) + (a[7] * b[7]) + (a[8] * b[8]);
}

MC_TARGET_FUNC void mc_mulabt3x3l(long double * c, long double a[9], long double b[9])
{
//!# c=a*b'
		c[0] = (a[0] * b[0]) + (a[1] * b[1]) + (a[2] * b[2]);
		c[1] = (a[0] * b[3]) + (a[1] * b[4]) + (a[2] * b[5]);
		c[2] = (a[0] * b[6]) + (a[1] * b[7]) + (a[2] * b[8]);

		c[3] = (a[3] * b[0]) + (a[4] * b[1]) + (a[5] * b[2]);
		c[4] = (a[3] * b[3]) + (a[4] * b[4]) + (a[5] * b[5]);
		c[5] = (a[3] * b[6]) + (a[4] * b[7]) + (a[5] * b[8]);

		c[6] = (a[6] * b[0]) + (a[7] * b[1]) + (a[8] * b[2]);
		c[7] = (a[6] * b[3]) + (a[7] * b[4]) + (a[8] * b[5]);
		c[8] = (a[6] * b[6]) + (a[7] * b[7]) + (a[8] * b[8]);
}

#endif /* !MC_MULABT3X3_H */

/* EOF */