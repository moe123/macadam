//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_igamma.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_exp.h>
#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_factorial.h>
#include <macadam/details/math/mc_gamma.h>
#include <macadam/details/math/mc_lgamma.h>
#include <macadam/details/math/mc_log.h>
#include <macadam/details/math/mc_pow.h>
#include <macadam/details/math/mc_sqrt.h>

#ifndef MC_IGAMMA_H
#define MC_IGAMMA_H

#pragma mark - mc_igamma_pseries_approx0 -

MC_TARGET_FUNCTION float mc_igamma_pseriesf_approx0(float a, float z)
{
//!# Power series.
	const float e = MCLIMITS_EPSILONF;
	float term    = 1.0f / a;
	float sum     = term;
	float w       = a;
	do {
		w    += 1.0f;
		term *= z / w;
		sum  += term;
	} while (mc_fabsf(term) > mc_fabsf(sum) * e);
	return sum;
}

MC_TARGET_FUNCTION double mc_igamma_pseries_approx0(double a, double z)
{
//!# Power series.
	const double e = MCLIMITS_EPSILON;
	double term    = 1.0 / a;
	double sum     = term;
	double w       = a;
	do {
		w    += 1.0;
		term *= z / w;
		sum  += term;
	} while (mc_fabs(term) > mc_fabs(sum) * e);
	return sum;
}

MC_TARGET_FUNCTION long double mc_igamma_pseriesl_approx0(long double a, long double z)
{
//!# Power series.
	const long double e = MCLIMITS_EPSILONL;
	long double term    = 1.0L / a;
	long double sum     = term;
	long double w       = a;
	do {
		w    += 1.0L;
		term *= z / w;
		sum  += term;
	} while (mc_fabsl(term) > mc_fabsl(sum) * e);
	return sum;
}

#pragma mark - mc_igamma_cfrac_approx0 -

MC_TARGET_FUNCTION float mc_igamma_cfracf_approx0(float a, float z)
{
//!# Continued fraction.
	const float e1 = MCLIMITS_EPSILONF;
	const float e3 = e1 * 3.0f;
	float k = 1.0f, c0, c1, c2, c3, c4, c5;
	c1 = z + 1.0f - a;
	c2 = 1.0f / e3;
	c3 = 1.0f / c1;
	c5 = c3;
	do {
		c0  = k * (a - k);
		c1  = c1 +  2.0f;
		c3  = c0 * c3 + c1;
		c3  = mc_fabsf(c3) < e3 ? e3 : c3;
		c2  = c1 + c0 / c2;
		c2  = mc_fabsf(c2) < e3 ? e3 : c2;
		c3  = 1.0f / c3;
		c4  = c3 * c2;
		c5  = c5 *  c4;
		k   = k + 1.0f;
	} while (mc_fabsf(c4 - 1.0f) > e1);
	return c5;
}

MC_TARGET_FUNCTION double mc_igamma_cfrac_approx0(double a, double z)
{
//!# Continued fraction.
	const double e1 = MCLIMITS_EPSILON;
	const double e3 = e1 * 3.0;
	double k = 1.0, c0, c1, c2, c3, c4, c5;
	c1 = z + 1.0 - a;
	c2 = 1.0 / e3;
	c3 = 1.0 / c1;
	c5 = c3;
	do {
		c0 = k * (a - k);
		c1 = c1 +  2.0;
		c3 = c0 * c3 + c1;
		c3 = mc_fabs(c3) < e3 ? e3 : c3;
		c2 = c1 + c0 / c2;
		c2 = mc_fabs(c2) < e3 ? e3 : c2;
		c3 = 1.0 / c3;
		c4 = c3 * c2;
		c5 = c5 *  c4;
		k   = k + 1.0;
	} while (mc_fabs(c4 - 1.0) > e1);
	return c5;
}

MC_TARGET_FUNCTION long double mc_igamma_cfracl_approx0(long double a, long double z)
{
//!# Continued fraction.
	const long double e1 = MCLIMITS_EPSILONL;
	const long double e3 = e1 * 3.0L;
	double k = 1.0L, c0, c1, c2, c3, c4, c5;
	c1 = z + 1.0L - a;
	c2 = 1.0L / e3;
	c3 = 1.0L / c1;
	c5 = c3;
	do {
		c0 = k * (a - k);
		c1 = c1 +  2.0L;
		c3 = c0 * c3 + c1;
		c3 = mc_fabsl(c3) < e3 ? e3 : c3;
		c2 = c1 + c0 / c2;
		c2 = mc_fabsl(c2) < e3 ? e3 : c2;
		c3 = 1.0L / c3;
		c4 = c3 * c2;
		c5 = c5 *  c4;
		k  = k + 1.0L;
	} while (mc_fabsl(c4 - 1.0L) > e1);
	return c5;
}

#pragma mark - mc_igamma_lower -

MC_TARGET_FUNCTION float mc_igamma_lowerf_approx0(float a, float z)
{
//!# Lower incomplete gamma function of a and z.
	if (a > 0.0f && z > 0.0f) {
		const float y = a * mc_logf(z) - z;
		if (y < -FLT_MAX_10_EXP) {
			return 0.0f;
		}
		return mc_igamma_pseriesf_approx0(a, z) * mc_expf(y);
	}
	return MCK_NAN;
}

MC_TARGET_FUNCTION double mc_igamma_lower_approx0(double a, double z)
{
//!# Lower incomplete gamma function of a and z.
	if (a > 0.0 && z > 0.0) {
		const double y = a * mc_log(z) - z;
		if (y < -DBL_MAX_10_EXP) {
			return 0.0;
		}
		return mc_igamma_pseries_approx0(a, z) * mc_exp(y);
	}
	return MCK_NAN;
}

MC_TARGET_FUNCTION long double mc_igamma_lowerl_approx0(long double a, long double z)
{
//!# Lower incomplete gamma function of a and z.
	if (a > 0.0L && z > 0.0L) {
		const long double y = a * mc_logl(z) - z;
		if (y < -LDBL_MAX_10_EXP) {
			return 0.0L;
		}
		return mc_igamma_pseriesl_approx0(a, z) * mc_expl(y);
	}
	return MCK_NAN;
}

#pragma mark - mc_igamma_upper_approx0 -

MC_TARGET_FUNCTION float mc_igamma_upperf_approx0(float a, float z)
{
//!# Upper incomplete gamma function of a and z.
	if (a > 0.0f && z > 0.0f) {
		const float w = a * mc_logf(z) - z;
		if (w < -FLT_MAX_10_EXP) {
			return 0.0f;
		}
		return mc_igamma_cfracf_approx0(a, z) * mc_expf(w);
	}
	return MCK_NAN;
}

MC_TARGET_FUNCTION double mc_igamma_upper_approx0(double a, double z)
{
//!# Upper incomplete gamma function of a and z.
	if (a > 0.0 && z > 0.0) {
		const double w = a * mc_log(z) - z;
		if (w < -DBL_MAX_10_EXP) {
			return 0.0;
		}
		return mc_igamma_cfrac_approx0(a, z) * mc_exp(w);
	}
	return MCK_NAN;
}

MC_TARGET_FUNCTION long double mc_igamma_upperl_approx0(long double a, long double z)
{
//!# Upper incomplete gamma function of a and z.
	if (a > 0.0L && z > 0.0L) {
		const long double w = a * mc_logl(z) - z;
		if (w < -LDBL_MAX_10_EXP) {
			return 0.0L;
		}
		return mc_igamma_cfracl_approx0(a, z) * mc_expl(w);
	}
	return MCK_NAN;
}

#pragma mark - mc_igammap_approx0 -

MC_TARGET_FUNCTION float mc_igammapf_approx0(float a, float z)
{
//!# Normalised lower incomplete gamma function of a and z.
	float p = MCK_NAN;
	if (a > 0.0f && z >= 0.0f) {
		if (z <=  0.0f) {
			return 0.0f;
		}
		const float y = a * mc_logf(z) - z;
		if (y >= -FLT_MAX_10_EXP) {
			const float w = y - mc_lgammaf(a);
			if (z < a + 1.0f) {
				p = mc_igamma_pseriesf_approx0(a, z) * mc_expf(w);
			} else {
				p = 1.0f - mc_igamma_cfracf_approx0(a, z) * mc_expf(w);
			}
		} else {
			p = 0.0f;
		}
	}
	return p;
}

MC_TARGET_FUNCTION double mc_igammap_approx0(double a, double z)
{
//!# Normalised lower incomplete gamma function of a and z.
	double p = MCK_NAN;
	if (a > 0.0 && z >= 0.0) {
		if (z <=  0.0) {
			return 0.0;
		}
		const double y = a * mc_log(z) - z;
		if (y >= -DBL_MAX_10_EXP) {
			const double w = y - mc_lgamma(a);
			if (z < a + 1.0) {
				p = mc_igamma_pseries_approx0(a, z) * mc_exp(w);
			} else {
				p = 1.0 - mc_igamma_cfrac_approx0(a, z) * mc_exp(w);
			}
		} else {
			p = 0.0;
		}
	}
	return p;
}

MC_TARGET_FUNCTION long double mc_igammapl_approx0(long double a, long double z)
{
//!# Normalised lower incomplete gamma function of a and z.
	long double p = MCK_NAN;
	if (a > 0.0L && z >= 0.0L) {
		if (z <=  0.0L) {
			return 0.0L;
		}
		const long double y = a * mc_logl(z) - z;
		if (y >= -LDBL_MAX_10_EXP) {
			const long double w = y - mc_lgammal(a);
			if (z < a + 1.0L) {
				p = mc_igamma_pseriesl_approx0(a, z) * mc_expl(w);
			} else {
				p = 1.0L - mc_igamma_cfracl_approx0(a, z) * mc_expl(w);
			}
		} else {
			p = 0.0L;
		}
	}
	return p;
}

#pragma mark - mc_igammaq_approx0 -

MC_TARGET_FUNCTION float mc_igammaqf_approx0(float a, float z)
{
//!# Normalised upper incomplete gamma function of a and z.
	float q = MCK_NAN;
	if (a > 0.0f && z >= 0.0f) {
		if (z <=  0.0f) {
			return 1.0f;
		}
		const float y = a * mc_logf(z) - z;
		if (y >= -FLT_MAX_10_EXP) {
			const float w = y - mc_lgammaf(a);
			if (z >= a + 1.0f) {
				q = mc_igamma_cfracf_approx0(a, z) * mc_expf(w);
			} else {
				q = 1.0f - mc_igamma_pseriesf_approx0(a, z) * mc_expf(w);
			}
		} else {
			q = 1.0f;
		}
	}
	return q;
}

MC_TARGET_FUNCTION double mc_igammaq_approx0(double a, double z)
{
//!# Normalised upper incomplete gamma function of a and z.
	double q = MCK_NAN;
	if (a > 0.0 && z >= 0.0) {
		if (z <=  0.0) {
			return 1.0;
		}
		const double y = a * mc_log(z) - z;
		if (y >= -DBL_MAX_10_EXP) {
			const double w = y - mc_lgamma(a);
			if (z >= a + 1.0) {
				q = mc_igamma_cfrac_approx0(a, z) * mc_exp(w);
			} else {
				q = 1.0 - mc_igamma_pseries_approx0(a, z) * mc_exp(w);
			}
		} else {
			q = 1.0;
		}
	}
	return q;
}

MC_TARGET_FUNCTION long double mc_igammaql_approx0(long double a, long double z)
{
//!# Normalised upper incomplete gamma function of a and z.
	long double q = MCK_NAN;
	if (a > 0.0L && z >= 0.0L) {
		if (z <=  0.0L) {
			return 1.0L;
		}
		const long double y = a * mc_logl(z) - z;
		if (y >= -LDBL_MAX_10_EXP) {
			const long double w = y - mc_lgammal(a);
			if (z >= a + 1.0L) {
				q = mc_igamma_cfracl_approx0(a, z) * mc_expl(w);
			} else {
				q = 1.0L - mc_igamma_pseriesl_approx0(a, z) * mc_expl(w);
			}
		} else {
			q = 1.0L;
		}
	}
	return q;
}

#pragma mark - mc_igamma_taylorp -

MC_TARGET_FUNCTION float mc_igamma_taylorpf(float a, float z)
{
	const float x = a * mc_expf(-z) * (1.0f / mc_gammaf(a + 1.0f));
	const float d = mc_powf(z, x);
	float b, c, p;
	if (a <= 0.0f || z <= 0.0f) {
		return 0.0f;
	}
	b = a;
	c = 1.0f;
	p = 1.0f;
	do {
		b = b + 1.0;
		c = c * z * (1.0f / b);
		p = p + c;
	} while (c < p * MCLIMITS_EPSILONF);
	return (p * d) * (1.0f / a);
}

MC_TARGET_FUNCTION double mc_igamma_taylorp(double a, double z)
{
	const double x = a * mc_exp(-z) * (1.0 / mc_gamma(a + 1.0));
	const double d = mc_pow(z, x);
	double b, c, p;
	if (a <= 0.0 || z <= 0.0) {
		return 0.0;
	}
	b = a;
	c = 1.0;
	p = 1.0;
	do {
		b = b + 1.0;
		c = c * z * (1.0 / b);
		p = p + c;
	} while (c < p * MCLIMITS_EPSILON);
	return (p * d) * (1.0 / a);
}

MC_TARGET_FUNCTION long double mc_igamma_taylorpl(long double a, long double z)
{
	const long double x = a * mc_expl(-z) * (1.0L / mc_gammal(a + 1.0L));
	const long double d = mc_powl(z, x);
	long double b, c, p;
	if (a <= 0.0L || z <= 0.0L) {
		return 0.0L;
	}
	b = a;
	c = 1.0L;
	p = 1.0L;
	do {
		b = b + 1.0L;
		c = c * z * (1.0L / b);
		p = p + c;
	} while (c < p * MCLIMITS_EPSILONL);
	return (p * d) * (1.0L / a);
}

#pragma mark - mc_igamma_taylorq -

MC_TARGET_FUNCTION float mc_igamma_taylorqf(float a, float z)
{
	return 1.0f - mc_igamma_taylorpf(a, z);
}

MC_TARGET_FUNCTION double mc_igamma_taylorq(double a, double z)
{
	return 1.0 - mc_igamma_taylorp(a, z);
}

MC_TARGET_FUNCTION double mc_igamma_taylorql(double a, double z)
{
	return 1.0L - mc_igamma_taylorpl(a, z);
}

#pragma mark - mc_igammaqi -

MC_TARGET_FUNCTION float mc_igammaqif (float a, float z)
{
//!# Normalised upper incomplete gamma function of a and z for a integral.
	float q = mc_expf(-z), w, n;
	if (q > 0.0f && a >= 2.0f) {
		w = q;
		n = 1.0f;
		do {
			w = (w / n) * z;
			q = q + w;
			n = n + 1.0f;
		} while (n < a);
	}
	return q;
}

MC_TARGET_FUNCTION double mc_igammaqi(double a, double z)
{
//!# Normalised upper incomplete gamma function of a and z for a integral.
	double q = mc_exp(-z), w, n;
	if (q > 0.0 && a >= 2.0) {
		w = q;
		n = 1.0;
		do {
			w = (w / n) * z;
			q = q + w;
			n = n + 1.0;
		} while (n < a);
	}
	return q;
}

MC_TARGET_FUNCTION long double mc_igammaqil(long double a, long double z)
{
//!# Normalised upper incomplete gamma function of a and z for a integral.
	long double q = mc_expl(-z), w, n;
	if (q > 0.0L && a >= 2.0L) {
		w = q;
		n = 1.0L;
		do {
			w = (w / n) * z;
			q = q + w;
			n = n + 1.0L;
		} while (n < a);
	}
	return q;
}

#pragma mark - mc_igammaqh -

MC_TARGET_FUNCTION float mc_igammaqhf(float a, float z)
{
//!# Normalised upper incomplete gamma function of a and z for a half-integral.
	float q = mc_erfcf(mc_sqrtf(z)), s, w, n;
	if (q != 0.0f && a > 1.0f) {
		w = 2.0f * mc_expf(-z) * mc_sqrtf(z / MCK_KF(MCK_PI));
		s = w;
		n = 2.0f;
		do {
			w = (w / (n - 0.5f)) * z;
			s = s + w;
			n = n + 1.0f;
		} while (n < a);
		q = q + s;
	}
	return q;
}

MC_TARGET_FUNCTION double mc_igammaqh(double a, double z)
{
//!# Normalised upper incomplete gamma function of a and z for a half-integral.
	double q = mc_erfc(mc_sqrt(z)), s, w, n;
	if (q != 0.0 && a > 1.0) {
		w = 2.0 * mc_exp(-z) * mc_sqrt(z / MCK_K(MCK_PI));
		s = w;
		n = 2.0;
		do {
			w = (w / (n - 0.5)) * z;
			s = s + w;
			n = n + 1.0;
		} while (n < a);
		q = q + s;
	}
	return q;
}

MC_TARGET_FUNCTION long double mc_igammaqhl(long double a, long double z)
{
//!# Normalised upper incomplete gamma function of a and z for a half-integral.
	double q = mc_erfcl(mc_sqrt(z)), s, w, n;
	if (q != 0.0L && a > 1.0L) {
		w = 2.0L * mc_expl(-z) * mc_sqrtl(z / MCK_KL(MCK_PI));
		s = w;
		n = 2.0L;
		do {
			w = (w / (n - 0.5L)) * z;
			s = s + w;
			n = n + 1.0L;
		} while (n < a);
		q = q + s;
	}
	return q;
}

#pragma mark - mc_igammaes -

MC_TARGET_FUNCTION float mc_igammaesf(float a, float z)
{
//!# Regularized incomplete gamma function; integral 0 to z with |z| <= 1.
	float r = 0.0f, p;
	if (a > 0.0f) {
		p = 1.0f;

		r = r + (p / mc_factorialf(0.0f))  / (0.0f  + a);
		p = p * -z;
		r = r + (p / mc_factorialf(1.0f))  / (1.0f  + a);
		p = p * -z;
		r = r + (p / mc_factorialf(2.0f))  / (2.0f  + a);
		p = p * -z;
		r = r + (p / mc_factorialf(3.0f))  / (3.0f  + a);
		p = p * -z;
		r = r + (p / mc_factorialf(4.0f))  / (4.0f  + a);
		p = p * -z;
		r = r + (p / mc_factorialf(5.0f))  / (5.0f  + a);
		p = p * -z;
		r = r + (p / mc_factorialf(6.0f))  / (6.0f  + a);
		p = p * -z;
		r = r + (p / mc_factorialf(7.0f))  / (7.0f  + a);
		p = p * -z;
		r = r + (p / mc_factorialf(8.0f))  / (8.0f  + a);
		p = p * -z;
		r = r + (p / mc_factorialf(9.0f))  / (9.0f  + a);
		p = p * -z;
		r = r + (p / mc_factorialf(10.0f)) / (10.0f + a);
		p = p * -z;
		r = r + (p / mc_factorialf(11.0f)) / (11.0f + a);
		p = p * -z;
		r = r + (p / mc_factorialf(12.0f)) / (12.0f + a);
		p = p * -z;
		r = r + (p / mc_factorialf(13.0f)) / (13.0f + a);
		p = p * -z;
		r = r + (p / mc_factorialf(14.0f)) / (14.0f + a);
		p = p * -z;
		r = r + (p / mc_factorialf(15.0f)) / (15.0f + a);
		p = p * -z;
		r = r + (p / mc_factorialf(16.0f)) / (16.0f + a);
		p = p * -z;
		r = r + (p / mc_factorialf(17.0f)) / (17.0f + a);
		p = p * -z;
		r = r + (p / mc_factorialf(18.0f)) / (18.0f + a);
		p = p * -z;
		r = r + (p / mc_factorialf(19.0f)) / (19.0f + a);
		p = p * -z;
		r = r + (p / mc_factorialf(20.0f)) / (20.0f + a);

		r = mc_expf(a * mc_logf(z) + mc_logf(r) - mc_lgammaf(a));
	}
	return r;
}

MC_TARGET_FUNCTION double mc_igammaes(double a, double z)
{
//!# Regularized incomplete gamma function; integral 0 to z with |z| <= 1.
	double r = 0.0, p;
	if (a > 0.0) {
		p = 1.0;

		r = r + (p / mc_factorial(0.0))  / (0.0  + a);
		p = p * -z;
		r = r + (p / mc_factorial(1.0))  / (1.0  + a);
		p = p * -z;
		r = r + (p / mc_factorial(2.0))  / (2.0  + a);
		p = p * -z;
		r = r + (p / mc_factorial(3.0))  / (3.0  + a);
		p = p * -z;
		r = r + (p / mc_factorial(4.0))  / (4.0  + a);
		p = p * -z;
		r = r + (p / mc_factorial(5.0))  / (5.0  + a);
		p = p * -z;
		r = r + (p / mc_factorial(6.0))  / (6.0  + a);
		p = p * -z;
		r = r + (p / mc_factorial(7.0))  / (7.0  + a);
		p = p * -z;
		r = r + (p / mc_factorial(8.0))  / (8.0  + a);
		p = p * -z;
		r = r + (p / mc_factorial(9.0))  / (9.0  + a);
		p = p * -z;
		r = r + (p / mc_factorial(10.0)) / (10.0 + a);
		p = p * -z;
		r = r + (p / mc_factorial(11.0)) / (11.0 + a);
		p = p * -z;
		r = r + (p / mc_factorial(12.0)) / (12.0 + a);
		p = p * -z;
		r = r + (p / mc_factorial(13.0)) / (13.0 + a);
		p = p * -z;
		r = r + (p / mc_factorial(14.0)) / (14.0 + a);
		p = p * -z;
		r = r + (p / mc_factorial(15.0)) / (15.0 + a);
		p = p * -z;
		r = r + (p / mc_factorial(16.0)) / (16.0 + a);
		p = p * -z;
		r = r + (p / mc_factorial(17.0)) / (17.0 + a);
		p = p * -z;
		r = r + (p / mc_factorial(18.0)) / (18.0 + a);
		p = p * -z;
		r = r + (p / mc_factorial(19.0)) / (19.0 + a);
		p = p * -z;
		r = r + (p / mc_factorial(20.0)) / (20.0 + a);

		r = mc_exp(a * mc_log(z) + mc_log(r) - mc_lgamma(a));
	}
	return r;
}

MC_TARGET_FUNCTION long double mc_igammaesl(long double a, long double z)
{
//!# Regularized incomplete gamma function; integral 0 to z with |z| <= 1.
	long double r = 0.0L, p;
	if (a > 0.0L) {
		p = 1.0L;

		r = r + (p / mc_factoriall(0.0L))  / (0.0L  + a);
		p = p * -z;
		r = r + (p / mc_factoriall(1.0L))  / (1.0L  + a);
		p = p * -z;
		r = r + (p / mc_factoriall(2.0L))  / (2.0L  + a);
		p = p * -z;
		r = r + (p / mc_factoriall(3.0L))  / (3.0L  + a);
		p = p * -z;
		r = r + (p / mc_factoriall(4.0L))  / (4.0L  + a);
		p = p * -z;
		r = r + (p / mc_factoriall(5.0L))  / (5.0L  + a);
		p = p * -z;
		r = r + (p / mc_factoriall(6.0L))  / (6.0L  + a);
		p = p * -z;
		r = r + (p / mc_factoriall(7.0L))  / (7.0L  + a);
		p = p * -z;
		r = r + (p / mc_factoriall(8.0L))  / (8.0L  + a);
		p = p * -z;
		r = r + (p / mc_factoriall(9.0L))  / (9.0L  + a);
		p = p * -z;
		r = r + (p / mc_factoriall(10.0L)) / (10.0L + a);
		p = p * -z;
		r = r + (p / mc_factoriall(11.0L)) / (11.0L + a);
		p = p * -z;
		r = r + (p / mc_factoriall(12.0L)) / (12.0L + a);
		p = p * -z;
		r = r + (p / mc_factoriall(13.0L)) / (13.0L + a);
		p = p * -z;
		r = r + (p / mc_factoriall(14.0L)) / (14.0L + a);
		p = p * -z;
		r = r + (p / mc_factoriall(15.0L)) / (15.0L + a);
		p = p * -z;
		r = r + (p / mc_factoriall(16.0L)) / (16.0L + a);
		p = p * -z;
		r = r + (p / mc_factoriall(17.0L)) / (17.0L + a);
		p = p * -z;
		r = r + (p / mc_factoriall(18.0L)) / (18.0L + a);
		p = p * -z;
		r = r + (p / mc_factoriall(19.0L)) / (19.0L + a);
		p = p * -z;
		r = r + (p / mc_factoriall(20.0L)) / (20.0L + a);

		r = mc_expl(a * mc_logl(z) + mc_logl(r) - mc_lgammal(a));
	}
	return r;
}

#pragma mark - mc_igammaem -

MC_TARGET_FUNCTION float mc_igammaemf(float a, float z)
{
//!# Regularized incomplete gamma function; integral 0 to z with |z| < a + 1.
	float r = 0.0f;
	float p = 1.0f / a;
	float c = p;
	float s = p;
	float d = -s + c;
	float l = s;
	float m = 0.0f;
	float e = 0.0f;
	int k   = 1;
	if (a > 0.0f) {
		r = mc_expf(a * mc_logf(z) - z - mc_lgammaf(a));
		if (r > 0.0f) {
			e = 1.0E-10f / r;
		}
		if (e <= 0.0f) {
			e = 1.0E-10f;
		}
		for (; p > e * l; k++) {
			p = p * ((1.0f / z) * (a + mc_cast(float, k)));
			c = p + d;
			s = l + c;
			d = (l - s) + c;
			l = s;
		}
		m = l;
		l = l * r;
		d = d + (1.0f / (m - l) * r);
		p = p * ((1.0f / z) * (a + mc_cast(float, k)));
		m = p + d;
		k = k + 1;
		for (; (p + d) > e * m; k++) {
			p = p * ((1.0f / z) * (a + mc_cast(float, k)));
			c = p + d;
			s = m + c;
			d = (m - s) + c;
			m = s;
		}
		r = l + ((m + d) * r);
	}
	return r;
}

MC_TARGET_FUNCTION double mc_igammaem(double a, double z)
{
//!# Regularized incomplete gamma function; integral 0 to z with |z| < a + 1.
	double r = 0.0;
	double p = 1.0 / a;
	double c = p;
	double s = p;
	double d = -s + c;
	double l = s;
	double m = 0.0;
	double e = 0.0;
	int k   = 1;
	if (a > 0.0) {
		r = mc_exp(a * mc_log(z) - z - mc_lgamma(a));
		if (r > 0.0) {
			e = 1.0E-15 / r;
		}
		if (e <= 0.0) {
			e = 1.0E-15;
		}
		for (; p > e * l; k++) {
			p = p * ((1.0 / z) * (a + mc_cast(double, k)));
			c = p + d;
			s = l + c;
			d = (l - s) + c;
			l = s;
		}
		m = l;
		l = l * r;
		d = d + (1.0 / (m - l) * r);
		p = p * ((1.0 / z) * (a + mc_cast(double, k)));
		m = p + d;
		k = k + 1;
		for (; (p + d) > e * m; k++) {
			p = p * ((1.0 / z) * (a + mc_cast(double, k)));
			c = p + d;
			s = m + c;
			d = (m - s) + c;
			m = s;
		}
		r = l + ((m + d) * r);
	}
	return r;
}

MC_TARGET_FUNCTION long double mc_igammaeml(long double a, long double z)
{
//!# Regularized incomplete gamma function; integral 0 to z with |z| < a + 1.
	long double r = 0.0L;
	long double p = 1.0L / a;
	long double c = p;
	long double s = p;
	long double d = -s + c;
	long double l = s;
	long double m = 0.0L;
	long double e = 0.0L;
	int k   = 1;
	if (a > 0.0L) {
		r = mc_expl(a * mc_logl(z) - z - mc_lgammal(a));
		if (r > 0.0L) {
			e = 1.0E-15L / r;
		}
		if (e <= 0.0L) {
			e = 1.0E-15L;
		}
		for (; p > e * l; k++) {
			p = p * ((1.0L / z) * (a + mc_cast(long double, k)));
			c = p + d;
			s = l + c;
			d = (l - s) + c;
			l = s;
		}
		m = l;
		l = l * r;
		d = d + (1.0L / (m - l) * r);
		p = p * ((1.0L / z) * (a + mc_cast(long double, k)));
		m = p + d;
		k = k + 1;
		for (; (p + d) > e * m; k++) {
			p = p * ((1.0L / z) * (a + mc_cast(long double, k)));
			c = p + d;
			s = m + c;
			d = (m - s) + c;
			m = s;
		}
		r = l + ((m + d) * r);
	}
	return r;
}

#pragma mark - mc_igammaeb -

MC_TARGET_FUNCTION float mc_igammaebf(float a, float z)
{
//!# Regularized incomplete gamma function; integral 0 to z with |z| >= a + 1.
	float r = 0.0f, p = 1.0f / a, s = p;
	int k = 1, n = mc_cast(int, (z - a - 1.0f)) + 1;
	if (a > 0.0f && n < MCLIMITS_IMAX) {
		for (; k < n; k++) {
			p = p * (1.0f / (z + mc_cast(float, k)));
			s = s + p;
		}
		r = mc_expf(mc_logf(s) + a * mc_logf(z) - z - mc_lgammaf(a)) + mc_igammaesf(a + mc_cast(float, n), z);
	}
	return r;
}

MC_TARGET_FUNCTION double mc_igammaeb(double a, double z)
{
//!# Regularized incomplete gamma function; integral 0 to z with |z| >= a + 1.
	double r = 0.0, p = 1.0 / a, s = p;
	int k = 1, n = mc_cast(int, (z - a - 1.0)) + 1;
	if (a > 0.0 && n < MCLIMITS_IMAX) {
		for (; k < n; k++) {
			p = p * (1.0 / (z + mc_cast(double, k)));
			s = s + p;
		}
		r = mc_exp(mc_log(s) + a * mc_log(z) - z - mc_lgamma(a)) + mc_igammaesf(a + mc_cast(double, n), z);
	}
	return r;
}

MC_TARGET_FUNCTION long double mc_igammaebl(long double a, long double z)
{
//!# Regularized incomplete gamma function; integral 0 to z with |z| >= a + 1.
	long double r = 0.0L, p = 1.0L / a, s = p;
	int k = 1, n = mc_cast(int, (z - a - 1.0L)) + 1;
	if (a > 0.0L && n < MCLIMITS_IMAX) {
		for (; k < n; k++) {
			p = p * (1.0L / (z + mc_cast(long double, k)));
			s = s + p;
		}
		r = mc_expl(mc_logl(s) + a * mc_logl(z) - z - mc_lgammal(a)) + mc_igammaesf(a + mc_cast(long double, n), z);
	}
	return r;
}

#pragma mark - mc_igammae -

MC_TARGET_FUNCTION float mc_igammaef(float z, float a)
{
//!# Regularized incomplete gamma function; integral 0 to z.
	if (z == 0.0f || !(a > 0.0f)) {
		return 0.0f;
	}
	if (mc_fabsf(z) <= 1.0f) {
		return mc_igammaes(a, z);
	}
	if (mc_fabsf(z) <= (a + 1.0f)) {
		return mc_igammaemf(a, z);
	}
	return mc_igammaebf(a, z);
}

MC_TARGET_FUNCTION double mc_igammae(double z, double a)
{
//!# Regularized incomplete gamma function; integral 0 to z.
	if (z == 0.0 || !(a > 0.0)) {
		return 0.0;
	}
	if (mc_fabs(z) <= 1.0) {
		return mc_igammaes(a, z);
	}
	if (mc_fabs(z) <= (a + 1.0)) {
		return mc_igammaem(a, z);
	}
	return mc_igammaeb(a, z);
}

MC_TARGET_FUNCTION long double mc_igammael(long double z, long double a)
{
//!# Regularized incomplete gamma function; integral 0 to z.
	if (z == 0.0L || !(a > 0.0L)) {
		return 0.0L;
	}
	if (mc_fabsl(z) <= 1.0L) {
		return mc_igammaesl(a, z);
	}
	if (mc_fabsl(z) <= (a + 1.0L)) {
		return mc_igammaeml(a, z);
	}
	return mc_igammaebl(a, z);
}

#pragma mark - mc_igammapq_pseries -

MC_TARGET_FUNCTION float mc_igammapq_pseriesf(float a, float z)
{
//!# Power series, regularized.
	const float e = MCLIMITS_EPSILONF;
	float term    = 1.0f / a;
	float sum     = term;
	float w       = a;
	for(;;) {
		w    += 1.0f;
		term *= z / w;
		sum  += term;
		if (mc_fabsf(term) < mc_fabsf(sum) * e) { 
			const float w = -z + a * mc_logf(z) - mc_lgammaf(a);
			sum = sum * mc_expf(w);
			break;
		}
	}
	return sum;
}

MC_TARGET_FUNCTION double mc_igammapq_pseries(double a, double z)
{
//!# Power series, regularized.
	const double e = MCLIMITS_EPSILON;
	double term    = 1.0 / a;
	double sum     = term;
	double w       = a;
	for(;;) {
		w    += 1.0;
		term *= z / w;
		sum  += term;
		if (mc_fabs(term) < mc_fabs(sum) * e) { 
			const double w = -z + a * mc_log(z) - mc_lgamma(a);
			sum = sum * mc_exp(w);
			break;
		}
	}
	return sum;
}

MC_TARGET_FUNCTION long double mc_igammapq_pseriesl(long double a, long double z)
{
//!# Power series, regularized.
	const long double e = MCLIMITS_EPSILON;
	long double term    = 1.0 / a;
	long double sum     = term;
	long double w       = a;
	for(;;) {
		w    += 1.0L;
		term *= z / w;
		sum  += term;
		if (mc_fabsl(term) < mc_fabsl(sum) * e) {
			const long double w = -z + a * mc_logl(z) - mc_lgammal(a);
			sum = sum * mc_expl(w);
			break;
		}
	}
	return sum;
}

#pragma mark - mc_igammapq_cfrac -

MC_TARGET_FUNCTION float mc_igammapq_cfracf(float a, float z)
{
	const float e1 = MCLIMITS_EPSILONF;
	const float e2 = e1 * 2.0f;
	float fa       = 1.0f - a + z;
	if (fa == 0.0f) {
		fa = e2;
	}
	float aa, ba, ca, c0 = fa, da, d0 = 0.0f, de = 0.0f;
	float k = 1.0f;
	do {
		ba = (1.0f + k * 2.0f) - a + z;
		aa = k * (a - k);
		da = ba + aa * d0;
		if (da == 0.0f) {
			da = e2;
		}
		ba = (1.0f + k * 2.0f) - a + z;
		aa = k * (a - k);
		ca = ba + aa / c0;
		if (ca == 0.0f) {
			ca = e2;
		}
		da = 1.0f / da;
		de = ca * da;
		fa = fa * de;
		d0 = da;
		c0 = ca;
		k  = k + 1.0f;
	} while(mc_fabsf(de - 1.0f) > e1);
	return fa;
}

MC_TARGET_FUNCTION double mc_igammapq_cfrac(double a, double z)
{
	const double e1 = MCLIMITS_EPSILONF;
	const double e2 = e1 * 2.0;
	double fa       = 1.0 - a + z;
	if (fa == 0.0) {
		fa = e2;
	}
	double aa, ba, ca, c0 = fa, da, d0 = 0.0, de = 0.0;
	double k = 1.0;
	do {
		ba = (1.0 + k * 2.0) - a + z;
		aa = k * (a - k);
		da = ba + aa * d0;
		if (da == 0.0) {
			da = e2;
		}
		ba = (1.0 + k * 2.0) - a + z;
		aa = k * (a - k);
		ca = ba + aa / c0;
		if (ca == 0.0) {
			ca = e2;
		}
		da = 1.0 / da;
		de = ca * da;
		fa = fa * de;
		d0 = da;
		c0 = ca;
		k  = k + 1.0;
	} while(mc_fabs(de - 1.0) > e1);
	return fa;
}

MC_TARGET_FUNCTION long double mc_igammapq_cfracl(long double a, long double z)
{
	const long double e1 = MCLIMITS_EPSILONF;
	const long double e2 = e1 * 2.0L;
	long double fa       = 1.0L - a + z;
	if (fa == 0.0L) {
		fa = e2;
	}
	long double aa, ba, ca, c0 = fa, da, d0 = 0.0L, de = 0.0L;
	long double k = 1.0L;
	do {
		ba = (1.0L + k * 2.0L) - a + z;
		aa = k * (a - k);
		da = ba + aa * d0;
		if (da == 0.0L) {
			da = e2;
		}
		ba = (1.0L + k * 2.0L) - a + z;
		aa = k * (a - k);
		ca = ba + aa / c0;
		if (ca == 0.0L) {
			ca = e2;
		}
		da = 1.0L / da;
		de = ca * da;
		fa = fa * de;
		d0 = da;
		c0 = ca;
		k  = k + 1.0L;
	} while(mc_fabsl(de - 1.0L) > e1);
	return fa;
}

#pragma mark - mc_igammap_approx1 -

MC_TARGET_FUNCTION float mc_igammapf_approx1(float a, float z)
{
//!# Normalised lower incomplete gamma function of a and z.
	float p = MCK_NAN;
	if (!(z <= 0.0f || a < 0.0f)) {
		if (z < (a + 1.0f)) {
			p = mc_igammapq_pseriesf(a, z);
		} else {
			p = 1.0f / mc_igammapq_cfracf(a, z);
			p = 1.0f - (mc_expf(a * mc_logf(z) - z - mc_lgammaf(a)) * p);
		}
	}
	return p;
}

MC_TARGET_FUNCTION double mc_igammap_approx1(double a, double z)
{
//!# Normalised lower incomplete gamma function of a and z.
	double p = MCK_NAN;
	if (!(z <= 0.0 || a < 0.0)) {
		if (z < (a + 1.0)) {
			p = mc_igammapq_pseries(a, z);
		} else {
			p = 1.0 / mc_igammapq_cfrac(a, z);
			p = 1.0 - (mc_exp(a * mc_log(z) - z - mc_lgamma(a)) * p);
		}
	}
	return p;
}

MC_TARGET_FUNCTION long double mc_igammapl_approx1(long double a, long double z)
{
//!# Normalised lower incomplete gamma function of a and z.
	long double p = MCK_NAN;
	if (!(z <= 0.0L || a < 0.0L)) {
		if (z < (a + 1.0L)) {
			p = mc_igammapq_pseriesl(a, z);
		} else {
			p = 1.0L / mc_igammapq_cfracl(a, z);
			p = 1.0L - (mc_expl(a * mc_logl(z) - z - mc_lgammal(a)) * p);
		}
	}
	return p;
}

#pragma mark - mc_igammaq_approx1 -

MC_TARGET_FUNCTION float mc_igammaqf_approx1(float a, float z)
{
//!# Normalised upper incomplete gamma function of a and z.
	float q = MCK_NAN;
	if (!(z <= 0.0f || a < 0.0f)) {
		if (z < (a + 1.0f)) {
			q = 1.0f - mc_igammapq_pseriesf(a, z);
		} else {
			q = 1.0f / mc_igammapq_cfracf(a, z);
			q = mc_expf(a * mc_logf(z) - z - mc_lgammaf(a)) * q;
		}
	}
	return q;
}

MC_TARGET_FUNCTION double mc_igammaq_approx1(double a, double z)
{
//!# Normalised upper incomplete gamma function of a and z.
	double q = MCK_NAN;
	if (!(z <= 0.0 || a < 0.0)) {
		if (z < (a + 1.0)) {
			q = 1.0 - mc_igammapq_pseries(a, z);
		} else {
			q = 1.0 / mc_igammapq_cfrac(a, z);
			q = mc_exp(a * mc_log(z) - z - mc_lgamma(a)) * q;
		}
	}
	return q;
}

MC_TARGET_FUNCTION long double mc_igammaql_approx1(long double a, long double z)
{
//!# Normalised upper incomplete gamma function of a and z.
	long double q = MCK_NAN;
	if (!(z <= 0.0L || a < 0.0L)) {
		if (z < (a + 1.0L)) {
			q = 1.0L - mc_igammapq_pseriesl(a, z);
		} else {
			q = 1.0L / mc_igammapq_cfracl(a, z);
			q = mc_expl(a * mc_logl(z) - z - mc_lgammal(a)) * q;
		}
	}
	return q;
}

#endif /* !MC_IGAMMA_H */

/* EOF */