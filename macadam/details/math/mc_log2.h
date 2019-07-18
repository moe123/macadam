//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_log2.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_LOG2_H
#define MC_LOG2_H

#pragma mark - mc_log2 -

MC_TARGET_FUNC float mc_log2f(float x)
{
#	if MC_TARGET_HAVE_LOG2
#	if MC_TARGET_CPP98
	return ::log2f(x);
#	else
	return log2f(x);
#	endif
#	else
	const float y = x * MCK_KF(MCK_1_LOG2);
#	if MC_TARGET_CPP98
	return ::logf(y);
#	else
	return logf(y);
#	endif
#	endif
}

MC_TARGET_FUNC double mc_log2(double x)
{
#	if MC_TARGET_HAVE_LOG2
#	if MC_TARGET_CPP98
	return ::log2(x);
#	else
	return log2(x);
#	endif
#	else
	const double y = x * MCK_K(MCK_1_LOG2);
#	if MC_TARGET_CPP98
	return ::log(y);
#	else
	return log(y);
#	endif
#	endif
}

MC_TARGET_FUNC long double mc_log2l(long double x)
{
#	if MC_TARGET_HAVE_LOG2
#	if MC_TARGET_CPP98
	return ::log2l(x);
#	else
	return log2l(x);
#	endif
#	else
#	if (MC_TARGET_C99 || MC_TARGET_CPP17) && defined(M_LN2l)
	const long double y = x / M_LN2l;
#	else
	const long double y = x * MCK_KL(MCK_1_LOG2);
#	endif
#	if MC_TARGET_CPP98
	return ::logl(y);
#	else
	return logl(y);
#	endif
#	endif
}

#endif /* !MC_LOG1M_H */

/* EOF */