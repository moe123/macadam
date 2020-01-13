//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_unitmxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_unitmx1.h>

#ifndef MC_UNITMXN_H
#define MC_UNITMXN_H

#pragma mark - mc_unitmxn -

MC_TARGET_FUNC void mc_unitmxnf(int m, int n, float * a)
{
	int j = 0;
	for (; j < n; j++) {
		mc_unitmx1f(m, n, j, a);
	}
}

MC_TARGET_FUNC void mc_unitmxn(int m, int n, double * a)
{
	int j = 0;
	for (; j < n; j++) {
		mc_unitmx1(m, n, j, a);
	}
}

MC_TARGET_FUNC void mc_unitmxnl(int m, int n, long double * a)
{
	int j = 0;
	for (; j < n; j++) {
		mc_unitmx1l(m, n, j, a);
	}
}

#endif /* !MC_UNITMXN_H */

/* EOF */