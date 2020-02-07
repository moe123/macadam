//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_dotpmx1.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_DOTPMX1_H
#define MC_DOTPMX1_H

#pragma mark - mc_dotpmx1 -

MC_TARGET_FUNC float mc_dotpmx1f(int m, int n, int p, int j, int k, const float * a, const float * b, int f)
{
//!# Requires a[m x n] and b[m x p].
//!# A and B may be the same.
//!# TwoProduct split factor @see mc_twoproduct.
	const float cs = mc_cast_expr(float, 4096 + 1);

	int i   = 0;
	float w = 0.0f, s = 0.0f;
	float h, q, r, x1, x2, y1, y2;

	if (m > 0) {
		switch (f) {
			case 0:
				for (; i < m; i++) {
					s = s + (a[(n * i) + j] * b[(p * i) + k]);
				}
			break;
			case 1:
				for (; i < m; i++) {
//!# Accurate dot product sum(x[i] * y[i], i=0...n-1) of two vectors.
//!# Accurate Sum and Dot Product, Takeshi Ogita, Siegfried M. Rump
//!# and Shin'ichi Oishi 2005, published in SIAM Journal on Scientific
//!# Computing (SISC), 26(6):1955-1988, 2005.

//!# TwoProduct(a[(n * i) + j],b[(p * i) + k],h,r).
					q  = a[(n * i) + j];
//!# split a[(n * i) + j] into x1,x2.
					r  = cs * q;
					x2 = r - q;
					x1 = r - x2;
					x2 = q - x1;
					r  = b[(p * i) + k];
//!# h=a[(n * i) + j]*b[(p * i) + k].
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

MC_TARGET_FUNC double mc_dotpmx1ff(int m, int n, int p, int j, int k, const float * a, const float * b, int f)
{
//!# TwoProduct split factor @see mc_twoproduct.
	const double cs = mc_cast_expr(double, 134217728 + 1);

	int i    = 0;
	double w = 0.0, s = 0.0;
	double h, q, r, x1, x2, y1, y2;

	if (m > 0) {
		switch (f) {
			case 0:
				for (; i < m; i++) {
					s = s + (mc_cast(double, a[(n * i) + j]) * mc_cast(double, b[(p * i) + k]));
				}
			break;
			case 1:
				for (; i < m; i++) {
//!# Accurate dot product sum(x[i] * y[i], i=0...n-1) of two vectors.
//!# Accurate Sum and Dot Product, Takeshi Ogita, Siegfried M. Rump
//!# and Shin'ichi Oishi 2005, published in SIAM Journal on Scientific
//!# Computing (SISC), 26(6):1955-1988, 2005.

//!# TwoProduct(a[(n * i) + j],b[(p * i) + k],h,r).
					q  = mc_cast(double, a[(n * i) + j]);
//!# split a[(n * i) + j] into x1,x2.
					r  = cs * q;
					x2 = r - q;
					x1 = r - x2;
					x2 = q - x1;
					r  = mc_cast(double, b[(p * i) + k]);
//!# h=a[(n * i) + j]*b[(p * i) + k].
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

MC_TARGET_FUNC double mc_dotpmx1(int m, int n, int p, int j, int k, const double * a, const double * b, int f)
{
//!# TwoProduct split factor @see mc_twoproduct.
	const double cs = mc_cast_expr(double, 134217728 + 1);

	int i    = 0;
	double w = 0.0, s = 0.0;
	double h, q, r, x1, x2, y1, y2;

	if (m > 0) {
		switch (f) {
			case 0:
				for (; i < m; i++) {
					s = s + (a[(n * i) + j] * b[(p * i) + k]);
				}
			break;
			case 1:
				for (; i < m; i++) {
//!# Accurate dot product sum(x[i] * y[i], i=0...n-1) of two vectors.
//!# Accurate Sum and Dot Product, Takeshi Ogita, Siegfried M. Rump
//!# and Shin'ichi Oishi 2005, published in SIAM Journal on Scientific
//!# Computing (SISC), 26(6):1955-1988, 2005.

//!# TwoProduct(a[(n * i) + j],b[(p * i) + k],h,r).
					q  = a[(n * i) + j];
//!# split a[(n * i) + j] into x1,x2.
					r  = cs * q;
					x2 = r - q;
					x1 = r - x2;
					x2 = q - x1;
					r  = b[(p * i) + k];
//!# h=a[(n * i) + j]*b[(p * i) + k].
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

MC_TARGET_FUNC long double mc_dotpmx1l(int m, int n, int p, int j, int k, const long double * a, const long double * b, int f)
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

	if (m > 0) {
		switch (f) {
			case 0:
				for (; i < m; i++) {
					s = s + (a[(n * i) + j] * b[(p * i) + k]);
				}
			break;
			case 1:
				for (; i < m; i++) {
//!# Accurate dot product sum(x[i] * y[i], i=0...n-1) of two vectors.
//!# Accurate Sum and Dot Product, Takeshi Ogita, Siegfried M. Rump
//!# and Shin'ichi Oishi 2005, published in SIAM Journal on Scientific
//!# Computing (SISC), 26(6):1955-1988, 2005.

//!# TwoProduct(a[(n * i) + j],b[(p * i) + k],h,r).
					q  = a[(n * i) + j];
//!# split a[(n * i) + j] into x1,x2.
					r  = cs * q;
					x2 = r - q;
					x1 = r - x2;
					x2 = q - x1;
					r  = b[(p * i) + k];
//!# h=a[(n * i) + j]*b[(p * i) + k].
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

#endif /* !MC_DOTPMX1_H */

/* EOF */