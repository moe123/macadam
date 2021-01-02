//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_zlogspace1xn.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_zadd.h>
#include <macadam/details/math/mc_zdiv.h>
#include <macadam/details/math/mc_zmul.h>
#include <macadam/details/math/mc_zpow10.h>
#include <macadam/details/math/mc_zsub.h>

#ifndef MC_ZLOGSPACE1XN
#define MC_ZLOGSPACE1XN

#pragma mark - mc_zlogspace1xn -

MC_TARGET_FUNC int mc_zlogspace1xnf(const int n, float * xr, float * xi, float x1r, float x1i, float x2r, float x2i)
{
//!# Requires x[n] where 1 < n. Draws a logspace: generates a logarithmically spaced
//!# vector `x`, i.e n points with spacing between points being (x2-x1)/(n-1).
	int i = 1;
	float stepr, stepi;
	if (n > 0) {
		if (n < 2) {
			mc_zpow10f(&xr[0], &xi[0], x2r, x2i);
		} else if (n < 3) {
			mc_zpow10f(&xr[0], &xi[0], x1r, x1i);
			mc_zpow10f(&xr[1], &xi[1], x2r, x2i);
		} else {
			mc_zsubf(&stepr, &stepi, x2r, x2i, x1r, x1i);
			mc_zdivf(&stepr, &stepi, stepr, stepi, mc_cast(float, (n - 1)), 0.0f);
			mc_zpow10f(&xr[0], &xi[0], x1r, x1i);
			mc_zpow10f(&xr[(n - 1)], &xi[(n - 1)], x2r, x2i);
			for (; i < (n - 1); i++) {
				mc_zmulf(&xr[i], &xi[i], mc_cast(float, i), 0.0f, stepr, stepi);
				mc_zaddf(&xr[i], &xi[i], x1r, x1i, xr[i], xi[i]);
				mc_zpow10f(&xr[i], &xi[i], xr[i], xi[i]);
			}
		}
		return 0;
	}
	return -1;
}

MC_TARGET_FUNC int mc_zlogspace1xnff(const int n, double * xr, double * xi, float x1r, float x1i, float x2r, float x2i)
{
//!# Requires x[n] where 1 < n. Draws a logspace: generates a logarithmically spaced
//!# vector `x`, i.e n points with spacing between points being (x2-x1)/(n-1).
	int i = 1;
	double stepr, stepi, x1rd, x1id, x2rd, x2id;
	if (n > 0) {
		x1rd = mc_cast(double, x1r);
		x1id = mc_cast(double, x1i);
		x2rd = mc_cast(double, x2r);
		x2id = mc_cast(double, x2i);
		if (n < 2) {
			mc_zpow10(&xr[0], &xi[0], x2rd, x2id);
		} else if (n < 3) {
			mc_zpow10(&xr[0], &xi[0], x1rd, x1id);
			mc_zpow10(&xr[1], &xi[1], x2rd, x2id);
		} else {
			mc_zsub(&stepr, &stepi, x2rd, x2id, x1rd, x1id);
			mc_zdiv(&stepr, &stepi, stepr, stepi, mc_cast(double, (n - 1)), 0.0);
			mc_zpow10(&xr[0], &xi[0], x1rd, x1id);
			mc_zpow10(&xr[(n - 1)], &xi[(n - 1)], x2rd, x2id);
			for (; i < (n - 1); i++) {
				mc_zmul(&xr[i], &xi[i], mc_cast(double, i), 0.0, stepr, stepi);
				mc_zadd(&xr[i], &xi[i], x1rd, x1id, xr[i], xi[i]);
				mc_zpow10(&xr[i], &xi[i], xr[i], xi[i]);
			}
		}
		return 0;
	}
	return -1;
}

MC_TARGET_FUNC int mc_zlogspace1xn(const int n, double * xr, double * xi, double x1r, double x1i, double x2r, double x2i)
{
//!# Requires x[n] where 1 < n. Draws a logspace: generates a logarithmically spaced
//!# vector `x`, i.e n points with spacing between points being (x2-x1)/(n-1).
	int i = 1;
	double stepr, stepi;
	if (n > 0) {
		if (n < 2) {
			mc_zpow10(&xr[0], &xi[0], x2r, x2i);
		} else if (n < 3) {
			mc_zpow10(&xr[0], &xi[0], x1r, x1i);
			mc_zpow10(&xr[1], &xi[1], x2r, x2i);
		} else {
			mc_zsub(&stepr, &stepi, x2r, x2i, x1r, x1i);
			mc_zdiv(&stepr, &stepi, stepr, stepi, mc_cast(double, (n - 1)), 0.0);
			mc_zpow10(&xr[0], &xi[0], x1r, x1i);
			mc_zpow10(&xr[(n - 1)], &xi[(n - 1)], x2r, x2i);
			for (; i < (n - 1); i++) {
				mc_zmul(&xr[i], &xi[i], mc_cast(double, i), 0.0, stepr, stepi);
				mc_zadd(&xr[i], &xi[i], x1r, x1i, xr[i], xi[i]);
				mc_zpow10(&xr[i], &xi[i], xr[i], xi[i]);
			}
		}
		return 0;
	}
	return -1;
}

MC_TARGET_FUNC int mc_zlogspace1xnl(const int n, long double * xr, long double * xi, long double x1r, long double x1i, long double x2r, long double x2i)
{
//!# Requires x[n] where 1 < n. Draws a logspace: generates a logarithmically spaced
//!# vector `x`, i.e n points with spacing between points being (x2-x1)/(n-1).
	int i = 1;
	long double stepr, stepi;
	if (n > 0) {
		if (n < 2) {
			mc_zpow10l(&xr[0], &xi[0], x2r, x2i);
		} else if (n < 3) {
			mc_zpow10l(&xr[0], &xi[0], x1r, x1i);
			mc_zpow10l(&xr[1], &xi[1], x2r, x2i);
		} else {
			mc_zsubl(&stepr, &stepi, x2r, x2i, x1r, x1i);
			mc_zdivl(&stepr, &stepi, stepr, stepi, mc_cast(long double, (n - 1)), 0.0L);
			mc_zpow10l(&xr[0], &xi[0], x1r, x1i);
			mc_zpow10l(&xr[(n - 1)], &xi[(n - 1)], x2r, x2i);
			for (; i < (n - 1); i++) {
				mc_zmull(&xr[i], &xi[i], mc_cast(long double, i), 0.0L, stepr, stepi);
				mc_zaddl(&xr[i], &xi[i], x1r, x1i, xr[i], xi[i]);
				mc_zpow10l(&xr[i], &xi[i], xr[i], xi[i]);
			}
		}
		return 0;
	}
	return -1;
}

#endif /* !MC_ZLOGSPACE1XN */

/* EOF */