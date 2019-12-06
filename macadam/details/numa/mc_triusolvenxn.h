//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_triusolvenxn.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_zeros1xn.h>

#ifndef MC_TRIUSOLVENXN_H
#define MC_TRIUSOLVENXN_H

#pragma mark - MC_TRIUSOLVENXN_H -

MC_TARGET_FUNC int mc_triusolvenxnf(int n, const float * u, const float * b, float * x)
{
//!# B and X may be the same. Solving the non-singular upper
//!# triangular system Ux=b, where u[n x n], b[n x 1], and x[n x 1].
	int i, j;
	float w;
	if (x != b) {
		for (i = 0; i < n; i++) {
			x[i] = b[i];
		}
	}
	for (j = (n - 1); j > 0; j--) {
		w = u[(n * j) + j];
		if (w == 0.0f) {
			mc_zeros1xnf(n, x);
			return -1;
		}
		x[j] = x[j] / w;
		for (i = 0; i < j; i++) {
			x[i] = x[i] - x[j] * u[(n * i) + j];
		}
	}
	w = u[0];
	if (w == 0.0f) {
		mc_zeros1xnf(n, x);
		return -1;
	}
	x[0] = x[0] / w;
	return 0;
}

MC_TARGET_FUNC int mc_triusolvenxnff(int n, const float * u, const float * b, double * x)
{
//!# Solving the non-singular upper triangular system
//!# Ux=b, where u[n x n], b[n x 1], and x[n x 1].
	int i, j;
	double w;
	for (i = 0; i < n; i++) {
		x[i] = mc_cast(double, b[i]);
	}
	for (j = (n - 1); j > 0; j--) {
		w = mc_cast(double, u[(n * j) + j]);
		if (w == 0.0) {
			mc_zeros1xn(n, x);
			return -1;
		}
		x[j] = x[j] / w;
		for (i = 0; i < j; i++) {
			x[i] = x[i] - x[j] * mc_cast(double, u[(n * i) + j]);
		}
	}
	w = mc_cast(double, u[0]);
	if (w == 0.0) {
		mc_zeros1xn(n, x);
		return -1;
	}
	x[0] = x[0] / w;
	return 0;
}

MC_TARGET_FUNC int mc_triusolvenxn(int n, const double * u, const double * b, double * x)
{
//!# B and X may be the same. Solving the non-singular upper
//!# triangular system Ux=b, where u[n x n], b[n x 1], and x[n x 1].
	int i, j;
	double w;
	if (x != b) {
		for (i = 0; i < n; i++) {
			x[i] = b[i];
		}
	}
	for (j = (n - 1); j > 0; j--) {
		w = u[(n * j) + j];
		if (w == 0.0) {
			mc_zeros1xn(n, x);
			return -1;
		}
		x[j] = x[j] / w;
		for (i = 0; i < j; i++) {
			x[i] = x[i] - x[j] * u[(n * i) + j];
		}
	}
	w = u[0];
	if (w == 0.0) {
		mc_zeros1xn(n, x);
		return -1;
	}
	x[0] = x[0] / w;
	return 0;
}

MC_TARGET_FUNC int mc_triusolvenxnl(int n, const long double * u, const long double * b, long double * x)
{
//!# B and X may be the same. Solving the non-singular upper
//!# triangular system Ux=b, where u[n x n], b[n x 1], and x[n x 1].
	int i, j;
	long double w;
	if (x != b) {
		for (i = 0; i < n; i++) {
			x[i] = b[i];
		}
	}
	for (j = (n - 1); j > 0; j--) {
		w = u[(n * j) + j];
		if (w == 0.0L) {
			mc_zeros1xnl(n, x);
			return -1;
		}
		x[j] = x[j] / w;
		for (i = 0; i < j; i++) {
			x[i] = x[i] - x[j] * u[(n * i) + j];
		}
	}
	w = u[0];
	if (w == 0.0L) {
		mc_zeros1xnl(n, x);
		return -1;
	}
	x[0] = x[0] / w;
	return 0;
}

#endif /* !MC_TRIUSOLVENXN_H */

/* EOF */