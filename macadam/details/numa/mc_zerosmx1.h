//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zerosmx1.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_ZEROSMX1_H
#define MC_ZEROSMX1_H

#pragma mark - mc_zerosmx1 -

MC_TARGET_FUNC void mc_zerosmx1f(int m, int n, int j, float * a)
{
	int i = 0;
	for (; i < m; i++) {
		a[(n * i) + j] = 0.0f;
	}
}

MC_TARGET_FUNC void mc_zerosmx1(int m, int n, int j, double * a)
{
	int i = 0;
	for (; i < m; i++) {
		a[(n * i) + j] = 0.0;
	}
}

MC_TARGET_FUNC void mc_zerosmx1l(int m, int n, int j, long double * a)
{
	int i = 0;
	for (; i < m; i++) {
		a[(n * i) + j] = 0.0L;
	}
}

#endif /* !MC_ZEROSMX1_H */

/* EOF */