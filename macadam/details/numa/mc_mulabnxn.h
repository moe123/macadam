//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_mulabnxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_mulab2x2.h>
#include <macadam/details/numa/mc_mulab3x3.h>
#include <macadam/details/numa/mc_mulabmxn.h>

#ifndef MC_MULABNXN_H
#define MC_MULABNXN_H

#pragma mark - mc_mulabnxn -

MC_TARGET_FUNC void mc_mulabnxnf(int n, float * restrict c, const float * restrict a, const float * restrict b)
{
//!# c=a*b
	if (n == 1) {
		c[0] = a[0] * b[0];
	} else if (n == 2) {
		mc_mulab2x2f(c, a, b);
	} else if (n == 3) {
		mc_mulab3x3f(c, a, b);
	} else {
		mc_mulabmxnf(n, n, n, c, a, b);
	}
}

MC_TARGET_FUNC void mc_mulabnxn(int n, double * restrict c, const double * restrict a, const double * restrict b)
{
//!# c=a*b
	if (n == 1) {
		c[0] = a[0] * b[0];
	} else if (n == 2) {
		mc_mulab2x2(c, a, b);
	} else if (n == 3) {
		mc_mulab3x3(c, a, b);
	} else {
		mc_mulabmxn(n, n, n, c, a, b);
	}
}

MC_TARGET_FUNC void mc_mulabnxnl(int n, long double * restrict c, const long double * restrict a, const long double * restrict b)
{
//!# c=a*b
	if (n == 1) {
		c[0] = a[0] * b[0];
	} else if (n == 2) {
		mc_mulab2x2l(c, a, b);
	} else if (n == 3) {
		mc_mulab3x3l(c, a, b);
	} else {
		mc_mulabmxnl(n, n, n, c, a, b);
	}
}

#endif /* !MC_MULABNXN_H */

/* EOF */