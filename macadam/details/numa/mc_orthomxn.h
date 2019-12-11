//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_orthomxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_fmax.h>
#include <macadam/details/numa/mc_dotpmx1.h>
#include <macadam/details/numa/mc_l2normmx1.h>

#ifndef MC_ORTHOMXN_H
#define MC_ORTHOMXN_H

#pragma mark - mc_orthomxn -

int mc_orthomxnf(int m, int n, const float * a, float tol, float * q)
{
//!# A and Q may be the same. Forming a ortho-normalized
//!# basis Q using Modified Gram-Schmidt method.
	int i, j, k;
	float bnorm, cnorm, dot;
	if (m >= n) {
		if (a != q) {
			for (i = 0; i < (m * n); i++) {
				q[i] = a[i];
			}
		}
		if (tol <= 0.0f) {
			tol = mc_fabsf(tol);
		}
		if (tol < MCLIMITS_TINYF) {
			tol = MCLIMITS_TINYF;
		}
		bnorm = 0.0f;
		for (j = 0; j < n; j++) {
			for (k = 0; k < j; k++) {
				dot = mc_dotpmx1f(m, n, k, j, q, 1);
				for (i = 0; i < m; i++) {
					q[(n * i) + j] = q[(n * i) + j] - (dot * q[(n * i) + k]);
				}
			}
			cnorm = mc_l2normmx1f(m, n, j, q);
			if (cnorm != 0.0f) {
				if (cnorm < tol * bnorm) {
//!# Norm is closed to zero, decimeting column.
					for (i = 0; i < m; i++) {
						q[(n * i) + j] = 0.0f;
					}
				} else {
					bnorm = mc_fmaxf(bnorm, cnorm);
					cnorm = 1.0f / cnorm;
					for (i = 0; i < m; i++) {
						q[(n * i) + j] = q[(n * i) + j] * cnorm;
					}
				}
			}
		}
		return 0;
	}
	return -1;
}

int mc_orthomxnff(int m, int n, const float * a, float tol, double * q)
{
//!# Forming a ortho-normalized basis Q
//!# using Modified Gram-Schmidt method.
	int i, j, k;
	double bnorm, cnorm, dot, told;
	if (m >= n) {
		for (i = 0; i < (m * n); i++) {
			q[i] = mc_cast(double, a[i]);
		}
		told = mc_cast(double, tol);
		if (told <= 0.0) {
			told = mc_fabs(told);
		}
		if (told < MCLIMITS_TINY) {
			told = MCLIMITS_TINY;
		}
		bnorm = 0.0;
		for (j = 0; j < n; j++) {
			for (k = 0; k < j; k++) {
				dot = mc_dotpmx1(m, n, k, j, q, 1);
				for (i = 0; i < m; i++) {
					q[(n * i) + j] = q[(n * i) + j] - (dot * q[(n * i) + k]);
				}
			}
			cnorm = mc_l2normmx1(m, n, j, q);
			if (cnorm != 0.0) {
				if (cnorm < told * bnorm) {
//!# Norm is closed to zero, decimeting column.
					for (i = 0; i < m; i++) {
						q[(n * i) + j] = 0.0;
					}
				} else {
					bnorm = mc_fmax(bnorm, cnorm);
					cnorm = 1.0 / cnorm;
					for (i = 0; i < m; i++) {
						q[(n * i) + j] = q[(n * i) + j] * cnorm;
					}
				}
			}
		}
		return 0;
	}
	return -1;
}

int mc_orthomxn(int m, int n, const double * a, double tol, double * q)
{
//!# A and Q may be the same. Forming a ortho-normalized
//!# basis Q using Modified Gram-Schmidt method.
	int i, j, k;
	double bnorm, cnorm, dot;
	if (m >= n) {
		if (a != q) {
			for (i = 0; i < (m * n); i++) {
				q[i] = a[i];
			}
		}
		if (tol <= 0.0) {
			tol = mc_fabs(tol);
		}
		if (tol < MCLIMITS_TINY) {
			tol = MCLIMITS_TINY;
		}
		bnorm = 0.0;
		for (j = 0; j < n; j++) {
			for (k = 0; k < j; k++) {
				dot = mc_dotpmx1(m, n, k, j, q, 1);
				for (i = 0; i < m; i++) {
					q[(n * i) + j] = q[(n * i) + j] - (dot * q[(n * i) + k]);
				}
			}
			cnorm = mc_l2normmx1(m, n, j, q);
			if (cnorm != 0.0) {
				if (cnorm < tol * bnorm) {
//!# Norm is closed to zero, decimeting column.
					for (i = 0; i < m; i++) {
						q[(n * i) + j] = 0.0;
					}
				} else {
					bnorm = mc_fmax(bnorm, cnorm);
					cnorm = 1.0 / cnorm;
					for (i = 0; i < m; i++) {
						q[(n * i) + j] = q[(n * i) + j] * cnorm;
					}
				}
			}
		}
		return 0;
	}
	return -1;
}

int mc_orthomxnl(int m, int n, const long double * a, long double tol, long double * q)
{
//!# A and Q may be the same. Forming a ortho-normalized
//!# basis Q using Modified Gram-Schmidt method.
	int i, j, k;
	long double bnorm, cnorm, dot;
	if (m >= n) {
		if (a != q) {
			for (i = 0; i < (m * n); i++) {
				q[i] = a[i];
			}
		}
		if (tol <= 0.0L) {
			tol = mc_fabsl(tol);
		}
		if (tol < MCLIMITS_TINYL) {
			tol = MCLIMITS_TINYL;
		}
		bnorm = 0.0L;
		for (j = 0; j < n; j++) {
			for (k = 0; k < j; k++) {
				dot = mc_dotpmx1l(m, n, k, j, q, 1);
				for (i = 0; i < m; i++) {
					q[(n * i) + j] = q[(n * i) + j] - (dot * q[(n * i) + k]);
				}
			}
			cnorm = mc_l2normmx1l(m, n, j, q);
			if (cnorm != 0.0L) {
				if (cnorm < tol * bnorm) {
//!# Norm is closed to zero, decimeting column.
					for (i = 0; i < m; i++) {
						q[(n * i) + j] = 0.0L;
					}
				} else {
					bnorm = mc_fmaxl(bnorm, cnorm);
					cnorm = 1.0L / cnorm;
					for (i = 0; i < m; i++) {
						q[(n * i) + j] = q[(n * i) + j] * cnorm;
					}
				}
			}
		}
		return 0;
	}
	return -1;
}

#endif /* !MC_ORTHOMXN_H */

/* EOF */