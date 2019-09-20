//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_randu.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/rand/mc_randi.h>

#ifndef MC_RANDU_H
#define MC_RANDU_H

#pragma mark - mc_randu -

MC_TARGET_PROC float  mc_randuf(void)
{
//!# 32-bits Random number generator i.e sample from uniform
//!# distribution range [0, 1] (theoretically may include low and high).
	const float a = mc_cast(float, mc_randi());
#	if MCTARGET_RAND_USE_LIBCRAND && RAND_MAX < MCLIMITS_IMAX
	const float b = mc_cast(float, MCLIMITS_RANDMAX);
	return a / (b + 1.0f);
#	elif MCTARGET_RAND_USE_LIBCRAND
	const float b = mc_cast(float, MCLIMITS_RANDMAX);
	return a / b;
#	else
	const float b = +2.32830643708079700000000000000000000000E-10f;
	return a * b;
#	endif
}

MC_TARGET_PROC double  mc_randu(void)
{
//!# 32-bits Random number generator i.e sample from uniform
//!# distribution range [0, 1] (theoretically may include low and high).
	const double a = mc_cast(double, mc_randi());
#	if MCTARGET_RAND_USE_LIBCRAND
	const double b = mc_cast(double, MCLIMITS_RANDMAX);
	return a / (b + 1.0);
#	else
	const double b = +2.3283064370807970000000000000000000000000E-10;
	return a * b;
#	endif
}

MC_TARGET_PROC long double  mc_randul(void)
{
#	if !MC_TARGET_MSVC_CPP
//!# 32-bits Random number generator i.e sample from uniform
//!# distribution range [0, 1] (theoretically may include low and high).
	const long double a = mc_cast(long double, mc_randi());
#	if MCTARGET_RAND_USE_LIBCRAND
	const long double b = mc_cast(long double, MCLIMITS_RANDMAX);
	return a / (b + 1.0L);
#	else
	const long double b = +2.328306437080797000000000000000000000000000000000000000000000000E-10L;
	return a * b;
#	endif
	return mc_cast(long double,  mc_randu());
#	endif
}

#endif /* !MC_RANDU_H */

/* EOF */