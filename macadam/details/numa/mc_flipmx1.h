//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_flipmx1.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_FLIPMX1_H
#define MC_FLIPMX1_H

#pragma mark - mc_flipmx1 -

MC_TARGET_FUNC void mc_flipmx1f(int m, int n, int j, float * c, const float * a)
{
//!# Requires c[m x n] and a[m x n].
//!# C and A may be the same. Reversing order of elements
//!# in column vector a_:j and storing the result into column vector c_:j.
	int p = 0, q = m - 1;
	float w;
	if (a != c) {
		while (q >= 0) {
			c[(n * p) + j] = a[(n * q) + j]; ++p; --q;
		}
	} else {
		while (p < q) {
			mcswap_var(w, c[(n * p) + j], c[(n * q) + j]); ++p; --q;
		}
	}
}

MC_TARGET_FUNC void mc_flipmx1ff(int m, int n, int j, double * c, const float * a)
{
//!# Requires c[n] and a[n].
//!# Reversing order of elements in column vector a_:j
//!# and storing the result into column vector c_:j.
	int p = 0, q = m - 1;
	while (q >= 0) {
		c[(n * p) + j] = mc_cast(double, a[(n * q) + j]); ++p; --q;
	}
}

MC_TARGET_FUNC void mc_flipmx1(int m, int n, int j, double * c, const double * a)
{
//!# Requires c[n] and a[n].
//!# C and A may be the same. Reversing order of elements
//!# in column vector a_:j and storing the result into column vector c_:j.
	int p = 0, q = m - 1;
	double w;
	if (a != c) {
		while (q >= 0) {
			c[(n * p) + j] = a[(n * q) + j]; ++p; --q;
		}
	} else {
		while (p < q) {
			mcswap_var(w, c[(n * p) + j], c[(n * q) + j]); ++p; --q;
		}
	}
}

MC_TARGET_FUNC void mc_flipmx1l(int m, int n, int j, long double * c, const long double * a)
{
//!# Requires c[n] and a[n].
//!# C and A may be the same. Reversing order of elements
//!# in column vector a_:j and storing the result into column vector c_:j.
	int p = 0, q = m - 1;
	long double w;
	if (a != c) {
		while (q >= 0) {
			c[(n * p) + j] = a[(n * q) + j]; ++p; --q;
		}
	} else {
		while (p < q) {
			mcswap_var(w, c[(n * p) + j], c[(n * q) + j]); ++p; --q;
		}
	}
}

#endif /* !MC_FLIPMX1_H */

/* EOF */