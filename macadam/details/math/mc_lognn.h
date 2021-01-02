//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_lognn.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_factorial.h>
#include <macadam/details/math/mc_lgamma.h>
#include <macadam/details/math/mc_log.h>

#ifndef MC_LOGNN_H
#define MC_LOGNN_H

#pragma mark - mc_lognn -

MC_TARGET_FUNC float mc_lognnf(unsigned int n)
{
//!# Returns log(n!).
	const unsigned int max_factorial = 35;
	if (n < max_factorial) {
		return mc_logf(mc_factorialf(n));
	}
	return mc_lgammaf(mc_cast(float, n) + 1.0f);
}

MC_TARGET_FUNC double mc_lognn(unsigned int n)
{
//!# Returns log(n!).
	const unsigned int max_factorial = 171;
	if (n < max_factorial) {
		return mc_log(mc_factorial(n));
	}
	return mc_lgamma(mc_cast(double, n) + 1.0);
}

MC_TARGET_FUNC long double mc_lognnl(unsigned int n)
{
//!# Returns log(n!).
#	if MC_TARGET_LONG_DOUBLE_UNAVAILABLE
	const unsigned int max_factorial = 171;
#	else
	const unsigned int max_factorial = 1755;
#	endif
	if (n < max_factorial) {
		return mc_logl(mc_factoriall(n));
	}
	return mc_lgammal(mc_cast(long double, n) + 1.0L);
}

#endif /* !MC_LOGNN_H */

/* EOF */