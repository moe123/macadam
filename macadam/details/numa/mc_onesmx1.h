//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_onesmx1.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_ONESMX1_H
#define MC_ONESMX1_H

#pragma mark - mc_onesmx1 -

MC_TARGET_FUNC void mc_onesmx1f(int m, int n, int j, float * a)
{
	int i = 0;
	for (; i < m; i++) {
		a[(n * i) + j] = 1.0f;
	}
}

MC_TARGET_FUNC void mc_onesmx1(int m, int n, int j, double * a)
{
	int i = 0;
	for (; i < m; i++) {
		a[(n * i) + j] = 1.0;
	}
}

MC_TARGET_FUNC void mc_onesmx1l(int m, int n, int j, long double * a)
{
	int i = 0;
	for (; i < m; i++) {
		a[(n * i) + j] = 1.0L;
	}
}

#endif /* !MC_ONESMX1_H */

/* EOF */