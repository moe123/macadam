//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_randu.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/rand/mc_randi.h>
#include <macadam/details/rand/mc_randk.h>

#ifndef MC_RANDU_H
#define MC_RANDU_H

#pragma mark - mc_randu -

MC_TARGET_PROC float mc_randuf(void)
{
//!# Uniform distribution range [0, 1] (theoretically may include low and high).
#	if MC_TARGET_RAND_USE_LIBCRAND && MCLIMITS_RANDMAX < 0x1000001U
	const float a = mc_cast(float, mc_randi());
	return a / (MCLIMITS_RANDMAX + 1);
#	else
	return mc_randkf();
#	endif
}

MC_TARGET_PROC double mc_randu(void)
{
//!# Uniform distribution range [0, 1] (theoretically may include low and high).
	const double a = mc_cast(double, mc_randi());
#	if MC_TARGET_RAND_USE_LIBCRAND
	const double b = mc_cast(double, MCLIMITS_RANDMAX);
	return a / (b + 1.0);
#	else
	const double b = +2.3283064370807970000000000000000000000000E-10;
	return a * b;
#	endif
}

MC_TARGET_PROC long double mc_randul(void)
{
//!# Uniform distribution range [0, 1] (theoretically may include low and high).
	const long double a = mc_cast(long double, mc_randi());
#	if MC_TARGET_RAND_USE_LIBCRAND
	const long double b = mc_cast(long double, MCLIMITS_RANDMAX);
	return a / (b + 1.0L);
#	elif MC_TARGET_HAVE_LONG_DOUBLE
	const long double b = +2.328306437080797000000000000000000000000000000000000000000000000E-10L;
	return a * b;
#	else
	return mc_cast(long double, mc_randu());
#	endif
}

#endif /* !MC_RANDU_H */

/* EOF */