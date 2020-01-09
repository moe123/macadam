//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_eyenxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_zerosnxn.h>

#ifndef MC_EYENXN_H
#define MC_EYENXN_H

#pragma mark - mc_eyenxn -

MC_TARGET_FUNC void mc_eyenxnf(int n, float * a, int f)
{
//!# f=0: set main diagonal to ones and zeroing other elements.
//!# f=1: only set main diagonal to ones.
	int i = 0;
	if (f == 0) {
		mc_zerosnxnf(n, a);
	}
	for (; i < n; i++) {
		a[(n * i) + i] = 1.0f;
	}
}

MC_TARGET_FUNC void mc_eyenxn(int n, double * a, int f)
{
//!# f=0: set main diagonal to ones and zeroing other elements.
//!# f=1: only set main diagonal to ones.
	int i = 0;
	if (f == 0) {
		mc_zerosnxn(n, a);
	}
	for (; i < n; i++) {
		a[(n * i) + i] = 1.0;
	}
}

MC_TARGET_FUNC void mc_eyenxnl(int n, long double * a, int f)
{
//!# f=0: set main diagonal to ones and zeroing other elements.
//!# f=1: only set main diagonal to ones.
	int i = 0;
	if (f == 0) {
		mc_zerosnxnl(n, a);
	}
	for (; i < n; i++) {
		a[(n * i) + i] = 1.0L;
	}
}

#endif /* !MC_EYENXN_H */

/* EOF */