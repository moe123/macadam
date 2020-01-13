//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_orthomxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_fisnear.h>
#include <macadam/details/math/mc_fmax.h>
#include <macadam/details/numa/mc_copymxn.h>
#include <macadam/details/numa/mc_dotpmx1.h>
#include <macadam/details/numa/mc_l2normmx1.h>
#include <macadam/details/numa/mc_zerosmx1.h>
#include <macadam/details/numa/mc_zerosnxn.h>

#ifndef MC_ORTHOMXN_H
#define MC_ORTHOMXN_H

#pragma mark - mc_orthomxn -

MC_TARGET_FUNC int mc_orthomxnf(int m, int n, const float * a, float tol, float * q, float * restrict r)
{
//!# Requires a[m x n], q[m x n] and r[n x n] if !null where 1 < m <= n.
//!# A and Q may be the same. Forming a ortho-normalized basis Q using
//!# Modified Gram-Schmidt method + a decimeting column step if norm < tol.
//!# If R is not null upper-triangle is formed.
	const int wantr = mc_nonnull(r);

	int i, j, k;
	float bnorm, cnorm, dot;
	if (m >= n) {
		if (a != q) {
			mc_copymxnf(m, n, q, a);
		}
		if (wantr) {
			mc_zerosnxnf(n, r);
		}

		if (tol <= 0.0f) {
			tol = mc_fabsf(tol);
		}
		if (tol == 0.0f) {
			tol = MCLIMITS_EPSILONF;
		}
		bnorm = 0.0f;
		for (j = 0; j < n; j++) {
			for (k = 0; k < j; k++) {
				dot = mc_dotpmx1f(m, n, k, j, q, q, 1);
				if (wantr) {
					r[(n * k) + j] = dot;
				}
				for (i = 0; i < m; i++) {
					q[(n * i) + j] = q[(n * i) + j] - (dot * q[(n * i) + k]);
				}
			}
			cnorm = mc_l2normmx1f(m, n, j, q);
			if (cnorm != 0.0f) {
				if (cnorm < tol * bnorm) {
//!# Norm is closed to zero, decimeting column.
//!# Borrowed from Mikhail Pak RSVD project.
					mc_zerosmx1f(m, n, j, q);
					q[(n * j) + j] = 1.0f;
					if (wantr) {
						r[(n * j) + j] = 1.0f;
					}
				} else {
					bnorm = mc_fmaxf(bnorm, cnorm);
					if (wantr) {
						r[(n * j) + j] = cnorm;
					}
					if (!mc_fisnearf(cnorm, 1.0f, 1)) {
						cnorm = 1.0f / cnorm;
						for (i = 0; i < m; i++) {
							q[(n * i) + j] = q[(n * i) + j] * cnorm;
						}
					}
				}
			} else {
				q[(n * j) + j] = 1.0f;
				if (wantr) {
					r[(n * j) + j] = 1.0f;
				}
			}
		}
		return 0;
	}
	return -1;
}

MC_TARGET_FUNC int mc_orthomxnff(int m, int n, const float * a, float tol, double * q, double * restrict r)
{
//!# Requires a[m x n], q[m x n] and r[n x n] if !null where 1 < m <= n.
//!# Forming a ortho-normalized basis Q using Modified Gram-Schmidt
//!# method + a decimeting column step if norm < tol. If R is not null
//!# upper-triangle is formed.
	const int wantr = mc_nonnull(r);

	int i, j, k;
	double bnorm, cnorm, dot, told;
	if (m >= n) {
		mc_copymxnff(m, n, q, a);

		if (wantr) {
			mc_zerosnxn(n, r);
		}

		if (tol <= 0.0f) {
			tol = mc_fabsf(tol);
		}
		if (tol == 0.0f) {
			tol = MCLIMITS_EPSILONF;
		}
		told  = mc_cast(double, tol);
		bnorm = 0.0;
		for (j = 0; j < n; j++) {
			for (k = 0; k < j; k++) {
				dot = mc_dotpmx1(m, n, k, j, q, q, 1);
				if (wantr) {
					r[(n * k) + j] = dot;
				}
				for (i = 0; i < m; i++) {
					q[(n * i) + j] = q[(n * i) + j] - (dot * q[(n * i) + k]);
				}
			}
			cnorm = mc_l2normmx1(m, n, j, q);
			if (cnorm != 0.0) {
				if (cnorm < told * bnorm) {
//!# Norm is closed to zero, decimeting column.
//!# Borrowed from Mikhail Pak RSVD project.
					mc_zerosmx1(m, n, j, q);
					q[(n * j) + j] = 1.0;
					if (wantr) {
						r[(n * j) + j] = 1.0;
					}
				} else {
					bnorm = mc_fmax(bnorm, cnorm);
					if (wantr) {
						r[(n * j) + j] = cnorm;
					}
					if (!mc_fisnear(cnorm, 1.0, 1)) {
						cnorm = 1.0 / cnorm;
						for (i = 0; i < m; i++) {
							q[(n * i) + j] = q[(n * i) + j] * cnorm;
						}
					}
				}
			} else {
				q[(n * j) + j] = 1.0;
				if (wantr) {
					r[(n * j) + j] = 1.0;
				}
			}
		}
		return 0;
	}
	return -1;
}

MC_TARGET_FUNC int mc_orthomxn(int m, int n, const double * a, double tol, double * q, double * restrict r)
{
//!# Requires a[m x n], q[m x n] and r[n x n] if !null where 1 < m <= n.
//!# A and Q may be the same. Forming a ortho-normalized basis Q using
//!# Modified Gram-Schmidt method + a decimeting column step if norm < tol.
//!# If R is not null upper-triangle is formed.
	const int wantr = mc_nonnull(r);

	int i, j, k;
	double bnorm, cnorm, dot;
	if (m >= n) {
		if (a != q) {
			mc_copymxn(m, n, q, a);
		}
		if (wantr) {
			mc_zerosnxn(n, r);
		}

		if (tol <= 0.0) {
			tol = mc_fabs(tol);
		}
		if (tol == 0.0) {
			tol = MCLIMITS_EPSILON;
		}
		bnorm = 0.0;
		for (j = 0; j < n; j++) {
			for (k = 0; k < j; k++) {
				dot = mc_dotpmx1(m, n, k, j, q, q, 1);
				if (wantr) {
					r[(n * k) + j] = dot;
				}
				for (i = 0; i < m; i++) {
					q[(n * i) + j] = q[(n * i) + j] - (dot * q[(n * i) + k]);
				}
			}
			cnorm = mc_l2normmx1(m, n, j, q);
			if (cnorm != 0.0) {
				if (cnorm < tol * bnorm) {
//!# Norm is closed to zero, decimeting column.
//!# Borrowed from Mikhail Pak RSVD project.
					mc_zerosmx1(m, n, j, q);
					q[(n * j) + j] = 1.0;
					if (wantr) {
						r[(n * j) + j] = 1.0;
					}
				} else {
					bnorm = mc_fmax(bnorm, cnorm);
					if (wantr) {
						r[(n * j) + j] = cnorm;
					}
					if (!mc_fisnear(cnorm, 1.0, 1)) {
						cnorm = 1.0 / cnorm;
						for (i = 0; i < m; i++) {
							q[(n * i) + j] = q[(n * i) + j] * cnorm;
						}
					}
				}
			} else {
				q[(n * j) + j] = 1.0;
				if (wantr) {
					r[(n * j) + j] = 1.0;
				}
			}
		}
		return 0;
	}
	return -1;
}

MC_TARGET_FUNC int mc_orthomxnl(int m, int n, const long double * a, long double tol, long double * q, long double * restrict r)
{
//!# Requires a[m x n], q[m x n] and r[n x n] if !null where 1 < m <= n.
//!# A and Q may be the same. Forming a ortho-normalized basis Q using
//!# Modified Gram-Schmidt method + a decimeting column step if norm < tol.
//!# If R is not null upper-triangle is formed.
	const int wantr = mc_nonnull(r);

	int i, j, k;
	long double bnorm, cnorm, dot;
	if (m >= n) {
		if (a != q) {
			mc_copymxnl(m, n, q, a);
		}
		if (wantr) {
			mc_zerosnxnl(n, r);
		}

		if (tol <= 0.0L) {
			tol = mc_fabsl(tol);
		}
		if (tol == 0.0) {
			tol = MCLIMITS_EPSILONL;
		}
		bnorm = 0.0L;
		for (j = 0; j < n; j++) {
			for (k = 0; k < j; k++) {
				dot = mc_dotpmx1l(m, n, k, j, q, q, 1);
				if (wantr) {
					r[(n * k) + j] = dot;
				}
				for (i = 0; i < m; i++) {
					q[(n * i) + j] = q[(n * i) + j] - (dot * q[(n * i) + k]);
				}
			}
			cnorm = mc_l2normmx1l(m, n, j, q);
			if (cnorm != 0.0L) {
				if (cnorm < tol * bnorm) {
//!# Norm is closed to zero, decimeting column.
//!# Borrowed from Mikhail Pak RSVD project.
					mc_zerosmx1l(m, n, j, q);
					q[(n * j) + j] = 1.0L;
					if (wantr) {
						r[(n * j) + j] = 1.0L;
					}
				} else {
					bnorm = mc_fmaxl(bnorm, cnorm);
					if (wantr) {
						r[(n * j) + j] = cnorm;
					}
					if (!mc_fisnearl(cnorm, 1.0L, 1)) {
						cnorm = 1.0L / cnorm;
						for (i = 0; i < m; i++) {
							q[(n * i) + j] = q[(n * i) + j] * cnorm;
						}
					}
				}
			} else {
				q[(n * j) + j] = 1.0L;
				if (wantr) {
					r[(n * j) + j] = 1.0L;
				}
			}
		}
		return 0;
	}
	return -1;
}

#endif /* !MC_ORTHOMXN_H */

/* EOF */