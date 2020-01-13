//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_mulabtmxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_mulabt2x2.h>
#include <macadam/details/numa/mc_mulabt3x3.h>
#include <macadam/details/numa/mc_mulabtmxn.h>

#ifndef MC_MULABTNXN_H
#define MC_MULABTNXN_H

#pragma mark - mc_mulabtnxn -

MC_TARGET_FUNC void mc_mulabtnxnf(int n, float * restrict c, const float * a, const float * b)
{
//!# c=a*b'
	if (n == 1) {
		c[0] = a[0] * b[0];
	} else if (n == 2) {
		mc_mulabt2x2f(c, a, b);
	} else if (n == 3) {
		mc_mulabt3x3f(c, a, b);
	} else {
		mc_mulabtmxnf(n, n, n, c, a, b);
	}
}

MC_TARGET_FUNC void mc_mulabtnxn(int n, double * restrict c, const double * a, const double * b)
{
//!# c=a*b'
	if (n == 1) {
		c[0] = a[0] * b[0];
	} else if (n == 2) {
		mc_mulabt2x2(c, a, b);
	} else if (n == 3) {
		mc_mulabt3x3(c, a, b);
	} else {
		mc_mulabtmxn(n, n, n, c, a, b);
	}
}

MC_TARGET_FUNC void mc_mulabtnxnl(int n, long double * restrict c, const long double * a, const long double * b)
{
//!# c=a*b'
	if (n == 1) {
		c[0] = a[0] * b[0];
	} else if (n == 2) {
		mc_mulabt2x2l(c, a, b);
	} else if (n == 3) {
		mc_mulabt3x3l(c, a, b);
	} else {
		mc_mulabtmxnl(n, n, n, c, a, b);
	}
}

#endif /* !MC_MULABTNXN_H */

/* EOF */