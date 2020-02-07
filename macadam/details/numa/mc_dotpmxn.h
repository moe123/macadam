//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_dotpmxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_dotp1xn.h>
#include <macadam/details/numa/mc_dotpmx1.h>

#ifndef MC_DOTPMXN_H
#define MC_DOTPMXN_H

#pragma mark - mc_dotpmxn -

MC_TARGET_FUNC void mc_dotpmxnf(int m, int n, int p, float * restrict c, const float * a, const float * b, int d, int f)
{
//!# Returns dotp of A and B such as c[1 x q]=sum(a_ij.*b_ij) where q=m when d=0 and q=n when d=1 and n <= p.
//!# f=0 computing the dot product of each rows.
//!# f=0 computing the dot product of each columns.
	int i = 0;
	switch (d)
	{
		case 0:
			for (; i < m; i++) {
				const float * x = a + (n * i);
				const float * y = b + (p * i);
				c[i]            = mc_dotp1xnf(n, x, y, f);
			}
		break;
		case 1:
			for (; i < n; i++) {
				c[i] = mc_dotpmx1f(m, n, p, i, i, a, b, f);
			}
		break;
	}
}

MC_TARGET_FUNC void mc_dotpmxnff(int m, int n, int p, double * restrict c, const float * a, const float * b, int d, int f)
{
//!# Returns dotp of A and B such as c[1 x q]=sum(a_ij.*b_ij) where q=m when d=0 and q=n when d=1 and n <= p.
//!# f=0 computing the dot product of each rows.
//!# f=0 computing the dot product of each columns.
	int i = 0;
	switch (d)
	{
		case 0:
			for (; i < m; i++) {
				const float * x = a + (n * i);
				const float * y = b + (p * i);
				c[i]            = mc_dotp1xnff(n, x, y, f);
			}
		break;
		case 1:
			for (; i < n; i++) {
				c[i] = mc_dotpmx1ff(m, n, p, i, i, a, b, f);
			}
		break;
	}
}

MC_TARGET_FUNC void mc_dotpmxn(int m, int n, int p, double * restrict c, const double * a, const double * b, int d, int f)
{
//!# Returns dotp of A and B such as c[1 x q]=sum(a_ij.*b_ij) where q=m when d=0 and q=n when d=1 and n <= p.
//!# f=0 computing the dot product of each rows.
//!# f=0 computing the dot product of each columns.
	int i = 0;
	switch (d)
	{
		case 0:
			for (; i < m; i++) {
				const double * x = a + (n * i);
				const double * y = b + (p * i);
				c[i]             = mc_dotp1xn(n, x, y, f);
			}
		break;
		case 1:
			for (; i < n; i++) {
				c[i] = mc_dotpmx1(m, n, p, i, i, a, b, f);
			}
		break;
	}
}

MC_TARGET_FUNC void mc_dotpmxnl(int m, int n, int p, long double * restrict c, const long double * a, const long double * b, int d, int f)
{
//!# Returns dotp of A and B such as c[1 x q]=sum(a_ij.*b_ij) where q=m when d=0 and q=n when d=1 and n <= p.
	int i = 0;
	switch (d)
	{
		case 0:
			for (; i < m; i++) {
				const long double * x = a + (n * i);
				const long double * y = b + (p * i);
				c[i]                  = mc_dotp1xnl(n, x, y, f);
			}
		break;
		case 1:
			for (; i < n; i++) {
				c[i] = mc_dotpmx1l(m, n, p, i, i, a, b, f);
			}
		break;
	}
}

#endif /* !MC_DOTPMXN_H */

/* EOF */