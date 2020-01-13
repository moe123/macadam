//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_fisodd.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fmod.h>
#include <macadam/details/math/mc_modf.h>

#ifndef MC_FISODD_H
#define MC_FISODD_H

#pragma mark - mc_fisodd -

MC_TARGET_FUNC int mc_fisoddf(float x, int frac)
{
	if (x == 0.0f) {
		return 1;
	}
//!# Checking integral-part.
	if (frac == 1) {
		mc_modff(x, &x);
	}
//!# Returns if x is odd-integral.
	if (mc_fmodf(x, 1.0f) == 0.0f && mc_fmodf(x, 2.0f) != 0.0f) {
		return 1;
	}
	return 0;
}

MC_TARGET_FUNC int mc_fisodd(double x, int frac)
{
	if (x == 0.0) {
		return 1;
	}
//!# Checking integral-part.
	if (frac == 1) {
		mc_modf(x, &x);
	}
//!# Returns if x is odd-integral.
	if (mc_fmod(x, 1.0) == 0.0 && mc_fmod(x, 2.0) != 0.0) {
		return 1;
	}
	return 0;
}

MC_TARGET_FUNC int mc_fisoddl(long double x, int frac)
{
	if (x == 0.0L) {
		return 1;
	}
//!# Checking integral-part.
	if (frac == 1) {
		mc_modfl(x, &x);
	}
//!# Returns if x is odd-integral.
	if (mc_fmodl(x, 1.0L) == 0.0 && mc_fmodl(x, 2.0L) != 0.0) {
		return 1;
	}
	return 0;
}

#endif /* !MC_FISODD_H */

/* EOF */