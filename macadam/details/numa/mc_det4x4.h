//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_det4x4.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_DET4X4_H
#define MC_DET4X4_H

#pragma mark - mc_det4x4 -

MC_TARGET_FUNC float mc_det4x4f(const float a[9])
{
	return a[3] * a[6] * a[9]  * a[12] - a[2] * a[7] * a[9]  * a[12]
		  - a[3] * a[5] * a[10] * a[12] + a[1] * a[7] * a[10] * a[12]
		+
		    a[2] * a[5] * a[11] * a[12] - a[1] * a[6] * a[11] * a[12]
		  - a[3] * a[6] * a[8]  * a[13] + a[2] * a[7] * a[8]  * a[13]
		+
		    a[3] * a[4] * a[10] * a[13] - a[0] * a[7] * a[10] * a[13]
		  - a[2] * a[4] * a[11] * a[13] + a[0] * a[6] * a[11] * a[13]
		+
		    a[3] * a[5] * a[8]  * a[14] - a[1] * a[7] * a[8]  * a[14]
		  - a[3] * a[4] * a[9]  * a[14] + a[0] * a[7] * a[9]  * a[14]
		+
		    a[1] * a[4] * a[11] * a[14] - a[0] * a[5] * a[11] * a[14]
		  - a[2] * a[5] * a[8]  * a[15] + a[1] * a[6] * a[8]  * a[15]
		+
		    a[2] * a[4] * a[9]  * a[15] - a[0] * a[6] * a[9]  * a[15]
		  - a[1] * a[4] * a[10] * a[15] + a[0] * a[5] * a[10] * a[15];
}

MC_TARGET_FUNC double mc_det4x4(const double a[9])
{
	return a[3] * a[6] * a[9]  * a[12] - a[2] * a[7] * a[9]  * a[12]
		  - a[3] * a[5] * a[10] * a[12] + a[1] * a[7] * a[10] * a[12]
		+
		    a[2] * a[5] * a[11] * a[12] - a[1] * a[6] * a[11] * a[12]
		  - a[3] * a[6] * a[8]  * a[13] + a[2] * a[7] * a[8]  * a[13]
		+
		    a[3] * a[4] * a[10] * a[13] - a[0] * a[7] * a[10] * a[13]
		  - a[2] * a[4] * a[11] * a[13] + a[0] * a[6] * a[11] * a[13]
		+
		    a[3] * a[5] * a[8]  * a[14] - a[1] * a[7] * a[8]  * a[14]
		  - a[3] * a[4] * a[9]  * a[14] + a[0] * a[7] * a[9]  * a[14]
		+
		    a[1] * a[4] * a[11] * a[14] - a[0] * a[5] * a[11] * a[14]
		  - a[2] * a[5] * a[8]  * a[15] + a[1] * a[6] * a[8]  * a[15]
		+
		    a[2] * a[4] * a[9]  * a[15] - a[0] * a[6] * a[9]  * a[15]
		  - a[1] * a[4] * a[10] * a[15] + a[0] * a[5] * a[10] * a[15];
}

MC_TARGET_FUNC long double mc_det4x4l(const long double a[9])
{
	return a[3] * a[6] * a[9]  * a[12] - a[2] * a[7] * a[9]  * a[12]
		  - a[3] * a[5] * a[10] * a[12] + a[1] * a[7] * a[10] * a[12]
		+
		    a[2] * a[5] * a[11] * a[12] - a[1] * a[6] * a[11] * a[12]
		  - a[3] * a[6] * a[8]  * a[13] + a[2] * a[7] * a[8]  * a[13]
		+
		    a[3] * a[4] * a[10] * a[13] - a[0] * a[7] * a[10] * a[13]
		  - a[2] * a[4] * a[11] * a[13] + a[0] * a[6] * a[11] * a[13]
		+
		    a[3] * a[5] * a[8]  * a[14] - a[1] * a[7] * a[8]  * a[14]
		  - a[3] * a[4] * a[9]  * a[14] + a[0] * a[7] * a[9]  * a[14]
		+
		    a[1] * a[4] * a[11] * a[14] - a[0] * a[5] * a[11] * a[14]
		  - a[2] * a[5] * a[8]  * a[15] + a[1] * a[6] * a[8]  * a[15]
		+
		    a[2] * a[4] * a[9]  * a[15] - a[0] * a[6] * a[9]  * a[15]
		  - a[1] * a[4] * a[10] * a[15] + a[0] * a[5] * a[10] * a[15];
}

#endif /* !MC_DET4X4_H */

/* EOF */