//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_dotp1xn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_DOTP1XN_H
#define MC_DOTP1XN_H

#pragma mark - mc_dotp1xn -

MC_TARGET_FUNC float mc_dotp1xnf(int n, const float * x, const float * y, int f)
{
//!# TwoProduct split factor @see mc_twoproduct.
	const float cs = mc_cast_expr(float, 4096 + 1);

	int i   = 0;
	float w = 0.0f, s = 0.0f;
	float h, q, r, x1, x2, y1, y2;

	if (n > 0) {
		switch (f) {
			case 0:
				for (; i < n; i++) {
					s = s + (x[i] * y[i]);
				}
			break;
			case 1:
				for (; i < n; i++) {
//!# Accurate dot product sum(x[i] * y[i], i=0...n-1) of two vectors.
//!# Accurate Sum and Dot Product, Takeshi Ogita, Siegfried M. Rump
//!# and Shin'ichi Oishi 2005, published in SIAM Journal on Scientific
//!# Computing (SISC), 26(6):1955-1988, 2005.

//!# TwoProduct(x[i],y[i],h,r).
					q  = x[i];
//!# split x[i] into x1,x2.
					r  = cs * q;
					x2 = r - q;
					x1 = r - x2;
					x2 = q - x1;
					r  = y[i];
//!# h=x[i]*y[i].
					h  = q * r;
//!# split y into y1,y2.
					q  = cs * r;
					y2 = q - r;
					y1 = q - y2;
					y2 = r - y1;
//!# r=x2*y2-(((h-x1*y1) - x2*y1) - x1*y2
					q  = x1 * y1;
					q  = h - q;
					y1 = y1 * x2;
					q  = q - y1;
					x1 = x1 * y2;
					q  = q - x1;
					x2 = x2 * y2;
					r  = x2 - q;
//!# (w,q)=TwoSum(w,h).
					x1 = w + h;
					x2 = x1 - w;
					y1 = x1 - x2;
					y2 = h - x2;
					q  = w - y1;
					q  = q + y2;
					w  = x1;
//!# s=s+(q+r).
					q = q + r;
					s = s + q;
				}
			break;
		}
	}
	return w + s;
}

MC_TARGET_FUNC double mc_dotp1xnff(int n, const float * x, const float * y, int f)
{
//!# TwoProduct split factor @see mc_twoproduct.
	const double cs = mc_cast_expr(double, 134217728 + 1);

	int i    = 0;
	double w = 0.0, s = 0.0;
	double h, q, r, x1, x2, y1, y2;

	if (n > 0) {
		switch (f) {
			case 0:
				for (; i < n; i++) {
					s = s + (mc_cast(double, x[i]) * mc_cast(double, y[i]));
				}
			break;
			case 1:
				for (; i < n; i++) {
//!# Accurate dot product sum(x[i] * y[i], i=0...n-1) of two vectors.
//!# Accurate Sum and Dot Product, Takeshi Ogita, Siegfried M. Rump
//!# and Shin'ichi Oishi 2005, published in SIAM Journal on Scientific
//!# Computing (SISC), 26(6):1955-1988, 2005.

//!# TwoProduct(x[i],y[i],h,r).
					q  = mc_cast(double, x[i]);
//!# split x[i] into x1,x2.
					r  = cs * q;
					x2 = r - q;
					x1 = r - x2;
					x2 = q - x1;
					r  = mc_cast(double, y[i]);
//!# h=x[i]*y[i].
					h  = q * r;
//!# split y into y1,y2.
					q  = cs * r;
					y2 = q - r;
					y1 = q - y2;
					y2 = r - y1;
//!# r=x2*y2-(((h-x1*y1) - x2*y1) - x1*y2
					q  = x1 * y1;
					q  = h - q;
					y1 = y1 * x2;
					q  = q - y1;
					x1 = x1 * y2;
					q  = q - x1;
					x2 = x2 * y2;
					r  = x2 - q;
//!# (w,q)=TwoSum(w,h).
					x1 = w + h;
					x2 = x1 - w;
					y1 = x1 - x2;
					y2 = h - x2;
					q  = w - y1;
					q  = q + y2;
					w  = x1;
//!# s=s+(q+r).
					q = q + r;
					s = s + q;
				}
			break;
		}
	}
	return w + s;
}

MC_TARGET_FUNC double mc_dotp1xn(int n, const double * x, const double * y, int f)
{
//!# TwoProduct split factor @see mc_twoproduct.
	const double cs = mc_cast_expr(double, 134217728 + 1);

	int i    = 0;
	double w = 0.0, s = 0.0;
	double h, q, r, x1, x2, y1, y2;

	if (n > 0) {
		switch (f) {
			case 0:
				for (; i < n; i++) {
					s = s + (x[i] * y[i]);
				}
			break;
			case 1:
				for (; i < n; i++) {
//!# Accurate dot product sum(x[i] * y[i], i=0...n-1) of two vectors.
//!# Accurate Sum and Dot Product, Takeshi Ogita, Siegfried M. Rump
//!# and Shin'ichi Oishi 2005, published in SIAM Journal on Scientific
//!# Computing (SISC), 26(6):1955-1988, 2005.

//!# TwoProduct(x[i],y[i],h,r).
					q  = x[i];
//!# split x[i] into x1,x2.
					r  = cs * q;
					x2 = r - q;
					x1 = r - x2;
					x2 = q - x1;
					r  = y[i];
//!# h=x[i]*y[i].
					h  = q * r;
//!# split y into y1,y2.
					q  = cs * r;
					y2 = q - r;
					y1 = q - y2;
					y2 = r - y1;
//!# r=x2*y2-(((h-x1*y1) - x2*y1) - x1*y2
					q  = x1 * y1;
					q  = h - q;
					y1 = y1 * x2;
					q  = q - y1;
					x1 = x1 * y2;
					q  = q - x1;
					x2 = x2 * y2;
					r  = x2 - q;
//!# (w,q)=TwoSum(w,h).
					x1 = w + h;
					x2 = x1 - w;
					y1 = x1 - x2;
					y2 = h - x2;
					q  = w - y1;
					q  = q + y2;
					w  = x1;
//!# s=s+(q+r).
					q = q + r;
					s = s + q;
				}
			break;
		}
	}
	return w + s;
}

MC_TARGET_FUNC long double mc_dotp1xnl(int n, const long double * x, const long double * y, int f)
{
//!# TwoProduct split factor @see mc_twoproduct.
#	if !MC_TARGET_MSVC_CPP
	const long double cs = mc_cast_expr(long double, 4294967296 + 1);
#	else
	const long double cs = mc_cast_expr(long double, 134217728 + 1);
#	endif

	int i         = 0;
	long double w = 0.0L, s = 0.0L;
	long double h, q, r, x1, x2, y1, y2;

	if (n > 0) {
		switch (f) {
			case 0:
				for (; i < n; i++) {
					s = s + (x[i] * y[i]);
				}
			break;
			case 1:
				for (; i < n; i++) {
//!# Accurate dot product sum(x[i] * y[i], i=0...n-1) of two vectors.
//!# Accurate Sum and Dot Product, Takeshi Ogita, Siegfried M. Rump
//!# and Shin'ichi Oishi 2005, published in SIAM Journal on Scientific
//!# Computing (SISC), 26(6):1955-1988, 2005.

//!# TwoProduct(x[i],y[i],h,r).
					q  = x[i];
//!# split x[i] into x1,x2.
					r  = cs * q;
					x2 = r - q;
					x1 = r - x2;
					x2 = q - x1;
					r  = y[i];
//!# h=x[i]*y[i].
					h  = q * r;
//!# split y into y1,y2.
					q  = cs * r;
					y2 = q - r;
					y1 = q - y2;
					y2 = r - y1;
//!# r=x2*y2-(((h-x1*y1) - x2*y1) - x1*y2
					q  = x1 * y1;
					q  = h - q;
					y1 = y1 * x2;
					q  = q - y1;
					x1 = x1 * y2;
					q  = q - x1;
					x2 = x2 * y2;
					r  = x2 - q;
//!# (w,q)=TwoSum(w,h).
					x1 = w + h;
					x2 = x1 - w;
					y1 = x1 - x2;
					y2 = h - x2;
					q  = w - y1;
					q  = q + y2;
					w  = x1;
//!# s=s+(q+r).
					q = q + r;
					s = s + q;
				}
			break;
		}
	}
	return w + s;
}

#endif /* !MC_DOTP1XN_H */

/* EOF */