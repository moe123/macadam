//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_mulatbmxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_mulatb2x2.h>
#include <macadam/details/numa/mc_mulatb3x3.h>
#include <macadam/details/numa/mc_mulatbmxn.h>

#ifndef MC_MULATBNXN_H
#define MC_MULATBNXN_H

#pragma mark - mc_mulatbnxn -

MC_TARGET_FUNC void mc_mulatbnxnf(int n, float * restrict c, const float * restrict a, const float * restrict b)
{
//!# c=a'*b
	if (n == 1) {
		c[0] = a[0] * b[0];
	} else if (n == 2) {
		mc_mulatb2x2f(c, a, b);
	} else if (n == 3) {
		mc_mulatb3x3f(c, a, b);
	} else {
		mc_mulatbmxnf(n, n, n, c, a, b);
	}
}

MC_TARGET_FUNC void mc_mulatbnxn(int n, double * restrict c, const double * restrict a, const double * restrict b)
{
//!# c=a'*b
	if (n == 1) {
		c[0] = a[0] * b[0];
	} else if (n == 2) {
		mc_mulatb2x2(c, a, b);
	} else if (n == 3) {
		mc_mulatb3x3(c, a, b);
	} else {
		mc_mulatbmxn(n, n, n, c, a, b);
	}
}

MC_TARGET_FUNC void mc_mulatbnxnl(int n, long double * restrict c, const long double * restrict a, const long double * restrict b)
{
//!# c=a'*b
	if (n == 1) {
		c[0] = a[0] * b[0];
	} else if (n == 2) {
		mc_mulatb2x2l(c, a, b);
	} else if (n == 3) {
		mc_mulatb3x3l(c, a, b);
	} else {
		mc_mulatbmxnl(n, n, n, c, a, b);
	}
}

#endif /* !MC_MULATBNXN_H */

/* EOF */