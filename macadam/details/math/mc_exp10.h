//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_exp10.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_EXP10_H
#define MC_EXP10_H

#pragma mark - mc_exp10 -

MC_TARGET_FUNC float mc_exp10f(float x)
{
#	if MC_TARGET_CPP98
#	if (defined(__GLIBC__) || defined(_GNU_SOURCE))
	return ::exp10f(x);
#	elif MC_TARGET_APPLEXM
	return ::__exp10f(x);
#	else
	return ::expf(MCK_KF(MCK_LOGE10) * x);
#	endif
#	else
#	if (defined(__GLIBC__) || defined(_GNU_SOURCE))
	return exp10f(x);
#	elif MC_TARGET_APPLEXM
	return __exp10f(x);
#	else
	return expf(MCK_KF(MCK_LOGE10) * x);
#	endif
#	endif
}

MC_TARGET_FUNC double mc_exp10(double x)
{
#	if MC_TARGET_CPP98
#	if (defined(__GLIBC__) || defined(_GNU_SOURCE))
	return ::exp10(x);
#	else
	return ::exp(MCK_K(MCK_LOGE10) * x);
#	endif
#	else
#	if (defined(__GLIBC__) || defined(_GNU_SOURCE))
	return exp10(x);
#	else
	return exp(MCK_K(MCK_LOGE10) * x);
#	endif
#	endif
}

MC_TARGET_FUNC long double mc_exp10l(long double x)
{
#	if MC_TARGET_CPP98
#	if (defined(__GLIBC__) || defined(_GNU_SOURCE))
	return ::exp10l(x);
#	else
#	if MC_TARGET_CPP17 && defined(M_LN10l)
	return ::expl(M_LN10l * x);
#	elif MC_TARGET_CPP17 && defined(M_LN10L)
	return ::expl(M_LN10L * x);
#	else
	return ::expl(MCK_KL(MCK_LOGE10) * x);
#	endif
#	endif
#	else
#	if (defined(__GLIBC__) || defined(_GNU_SOURCE))
	return exp10l(x);
#	else
#	if MC_TARGET_C99 && defined(M_LN10l)
	return expl(M_LN10l * x);
#	elif MC_TARGET_C99 && defined(M_LN10L)
	return expl(M_LN10L * x);
#	else
	return expl(MCK_KL(MCK_LOGE10) * x);
#	endif
#	endif
#	endif
}

#endif /* !MC_EXP10_H */

/* EOF */