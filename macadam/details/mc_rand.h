//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_rand.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#	include <macadam/details/math/mc_cos.h>
#	include <macadam/details/math/mc_exp.h>
#	include <macadam/details/math/mc_log.h>
#	include <macadam/details/math/mc_log1m.h>
#	include <macadam/details/math/mc_raise2.h>
#	include <macadam/details/math/mc_raise3.h>
#	include <macadam/details/math/mc_pow.h>
#	include <macadam/details/math/mc_sin.h>
#	include <macadam/details/math/mc_sqrt.h>
#	include <macadam/details/math/mc_zsqrt.h>

#ifndef MC_RAND_H
#define MC_RAND_H

#	undef  MCTARGET_USE_LIBCRAND
#	undef  MCTARGET_USE_MARSAGLIAMWC
#	undef  MCTARGET_USE_MARSAGLIAXOR128
#	undef  MCTARGET_USE_BOXMULLER

#	undef  MCTARGET_USE_LFSR113
#	define MCTARGET_USE_LFSR113 1

#	if MCTARGET_USE_MARSAGLIAMWC
static volatile unsigned int mc_rseeds_s[]  = { 1234, 0, 5678, 0 };
#	else
static volatile unsigned int mc_rseeds_s[]  = { 2, 8, 16, 128 };
#	endif

static volatile unsigned int mc_rand_init_s = 0;

MC_TARGET_PROC void mc_srand(
	  unsigned int s1
	, unsigned int s2
	, unsigned int s3
	, unsigned int s4
	, unsigned int s5
) {
	if (mc_rand_init_s < 1) {
		++mc_rand_init_s;
	}
	s4             = s4 + s5;
	mc_rseeds_s[0] = s1 > 2   && s1 < MCLIMITS_USMAX ? s1 : 2;
	mc_rseeds_s[1] = s2 > 8   && s2 < MCLIMITS_USMAX ? s2 : 8;
	mc_rseeds_s[2] = s3 > 16  && s3 < MCLIMITS_USMAX ? s3 : 16;
	mc_rseeds_s[3] = s4 > 128 && s4 < MCLIMITS_USMAX ? s4 : 128;
#	if MCTARGET_USE_LIBCRAND
#	if MC_TARGET_CPP98
	::srand(mc_rseeds_s[0] + mc_rseeds_s[1] + mc_rseeds_s[2] + mc_rseeds_s[3]);
#	else
	srand(mc_rseeds_s[0] + mc_rseeds_s[1] + mc_rseeds_s[2] + mc_rseeds_s[3]);
#	endif
#	elif MCTARGET_USE_MARSAGLIAMWC
	mc_rseeds_s[0] = s1 > 1234 && s1 < MCLIMITS_USMAX ? s1 : 1234;
	mc_rseeds_s[1] = s2 > 5678 && s2 < MCLIMITS_USMAX ? s2 : 5678;
	mc_rseeds_s[0] = mc_rseeds_s[0] + mc_rseeds_s[2];
	mc_rseeds_s[1] = mc_rseeds_s[2] + mc_rseeds_s[3];
#	endif
}

MC_TARGET_PROC void mc_ssrand()
{
//!# Auto-generating seeds based on an approximation of
//!# processor time used. Not perfect but fast and portable.
	unsigned int s1 = 1, s2 = 9, s3 = 17, s4 = 129, s5 = 183;
	unsigned long x;
#	if MC_TARGET_CPP98
	::clock_t clck0, clck1;
#	else
	clock_t clck0, clck1;
#	endif
#	if MC_TARGET_CPP98
	clck0 = ::clock();
#	else
	clck0 = clock();
#	endif
	x     = mc_cast_exp(unsigned long, clck0 * CLOCKS_PER_SEC);
	s2    = s2 + mc_cast_exp(unsigned int, x >> 3 & 0xFF);
	s1    = s1 + mc_cast_exp(unsigned int, x >> 1 & 0xFF);
//!# Consuming CPU cycles (guard).
	while (s1 < 16) { ++s1; ++s2; ++s3; ++s4; ++s5; }
//!# Fetching clock approximation.
#	if MC_TARGET_CPP98
	clck1 = ::clock();
#	else
	clck1 = clock();
#	endif
	x     = mc_cast_exp(unsigned long, clck1 * CLOCKS_PER_SEC);
//!# Building seeds from whatever is there.
	s5    = s5 + mc_cast_exp(unsigned int, x >> 9 & 0xFF);
	s4    = s4 + mc_cast_exp(unsigned int, x >> 7 & 0xFF);
	s3    = s3 + mc_cast_exp(unsigned int, x >> 5 & 0xFF);
	s2    = s2 + s4;
	s1    = s1 + s3;
//!# Assigning new seeds.
	mc_srand(s1, s2, s3, s4, s5);
}

MC_TARGET_PROC unsigned int mc_rand_max(void)
{
#	if MCTARGET_USE_LIBCRAND
	return mc_cast(const unsigned int, RAND_MAX);
#	elif MCTARGET_USE_MARSAGLIAMWC
	return MCLIMITS_UIMAX;
#	elif MCTARGET_USE_LFSR113
	return MCLIMITS_UIMAX;
#	else
	return MCLIMITS_UIMAX;
#	endif
}

MC_TARGET_PROC unsigned int mc_rand(void)
{
	if (mc_rand_init_s < 1) {
		++mc_rand_init_s;
		mc_ssrand();
	}
#	if MCTARGET_USE_LIBCRAND
	++mc_rand_init_s;
	if (mc_rand_init_s > 600) {
		mc_rand_init_s = 0;
	}
#	if MC_TARGET_CPP98
	return mc_cast(unsigned int, ::rand());
#	else
	return mc_cast(unsigned int, rand());
#	endif
#	elif MCTARGET_USE_MARSAGLIAMWC
//!# 32-bits Random number generator [0, UINT_MAX].
	unsigned int b;
//!# Marsaglia-multiply-with-carry.
	mc_rseeds_s[0] = 36969 * (mc_rseeds_s[0] & 0177777) + (mc_rseeds_s[0] >> 16);
	mc_rseeds_s[1] = 18000 * (mc_rseeds_s[1] & 0177777) + (mc_rseeds_s[1] >> 16);
	b              = ((mc_rseeds_s[0] << 16) ^ (mc_rseeds_s[1] & 0177777));
	if (!(b < mc_rand_max())) {
		mc_ssrand();
		return mc_rand_max();
	}
	return b;
#	elif MCTARGET_USE_LFSR113
//!# 32-bits Random number generator [0, UINT_MAX].
	unsigned int b;
//!# Tables of maximally equidistributed combined LFSR generators. Pierre L'Ecuyer.
//!# @see https://www.ams.org/journals/mcom/1999-68-225/S0025-5718-99-01039-X/S0025-5718-99-01039-X.pdf.
	b              = ((mc_rseeds_s[0] << 6 ) ^ mc_rseeds_s[0]) >> 13;
	mc_rseeds_s[0] = ((mc_rseeds_s[0] & 4294967294U) << 18) ^ b;
	b              = ((mc_rseeds_s[1] << 2 ) ^ mc_rseeds_s[1]) >> 27;
	mc_rseeds_s[1] = ((mc_rseeds_s[1] & 4294967288U) << 2 ) ^ b;
	b              = ((mc_rseeds_s[2] << 13) ^ mc_rseeds_s[2]) >> 21;
	mc_rseeds_s[2] = ((mc_rseeds_s[2] & 4294967280U) << 7 ) ^ b;
	b              = ((mc_rseeds_s[3] << 3 ) ^ mc_rseeds_s[3]) >> 12;
	mc_rseeds_s[3] = ((mc_rseeds_s[3] & 4294967168U) << 13) ^ b;
	b              = (mc_rseeds_s[0] ^ mc_rseeds_s[1] ^ mc_rseeds_s[2] ^ mc_rseeds_s[3]);

	if (!(b < mc_rand_max())) {
		mc_ssrand();
		return mc_rand_max();
	}
	return b;
#	else
//!# 32-bits Random number generator [0, UINT_MAX].
	unsigned int b, s0;
//!# @see xorshift128, Marsaglia "Xorshift RNGs" p. 5.
	b               = mc_rseeds_s[3];
	s0              = mc_rseeds_s[0];
	mc_rseeds_s[3]  = mc_rseeds_s[2];
	mc_rseeds_s[2]  = mc_rseeds_s[1];
	mc_rseeds_s[1]  = s0;
	b              ^= b << 11;
	b              ^= b >> 8;
	b               = mc_rseeds_s[0] = b ^ s0 ^ (s0 >> 19);

	if (!(b < mc_rand_max())) {
		mc_ssrand();
		return mc_rand_max();
	}
	return b;
#	endif
}

#pragma mark - mc_randsdu -

MC_TARGET_PROC float mc_randsduf(void)
{
//!# 32-bits Random number generator i.e sample from uniform
//!# distribution range [0, 1] (theoretically may include low and high).
	const float a = mc_cast(float, mc_rand());
#	if MCTARGET_USE_LIBCRAND && RAND_MAX < MCLIMITS_IMAX
	const float b = mc_cast(float, mc_rand_max());
	return a / (b + 1.0f);
#	elif MCTARGET_USE_LIBCRAND
	const float b = mc_cast(float, mc_rand_max());
	return a / b;
#	else
	const float b = +2.32830643708079700000000000000000000000E-10f;
	return a * b;
#	endif
}

MC_TARGET_PROC double mc_randsdu(void)
{
//!# 32-bits Random number generator i.e sample from uniform
//!# distribution range [0, 1] (theoretically may include low and high).
	const double a = mc_cast(double, mc_rand());
#	if MCTARGET_USE_LIBCRAND
	const double b = mc_cast(double, mc_rand_max());
	return a / (b + 1.0);
#	else
	const double b = +2.3283064370807970000000000000000000000000E-10;
	return a * b;
#	endif
}

MC_TARGET_PROC long double mc_randsdul(void)
{
#	if !MC_TARGET_MSVC_CPP
//!# 32-bits Random number generator i.e sample from uniform
//!# distribution range [0, 1] (theoretically may include low and high).
	const long double a = mc_cast(long double, mc_rand());
#	if MCTARGET_USE_LIBCRAND
	const long double b = mc_cast(long double, mc_rand_max());
	return a / (b + 1.0L);
#	else
	const long double b = +2.328306437080797000000000000000000000000000000000000000000000000E-10L;
	return a * b;
#	endif
	return mc_cast(long double, mc_randsdu());
#	endif
}

#pragma mark - mc_randuni -

MC_TARGET_FUNC float mc_randunif(float a, float b)
{
//!# 32-bits Random number generator range [a, b] i.e sample
//!# from uniform distribution (theoretically may include low, but excludes high).
	const float u = mc_randsduf();
	return a * (1.0f - u) + b * u;
}

MC_TARGET_FUNC double mc_randuni(double a, double b)
{
//!# 32-bits Random number generator range [a, b] i.e sample
//!# from uniform distribution (theoretically may include low, but excludes high).
	const double u = mc_randsdu();
	return a * (1.0 - u) + b * u;
}

MC_TARGET_FUNC long double mc_randunil(long double a, long double b)
{
//!# 32-bits Random number generator range [a, b] i.e sample
//!# from uniform distribution (theoretically may include low, but excludes high).
	const long double u = mc_randsdul();
	return a * (1.0L - u) + b * u;
}

#pragma mark - mc_randsdg -

MC_TARGET_PROC float mc_randsdgf(void)
{
#	if MCTARGET_USE_BOXMULLER
//!# Box-Muller transform. Standard gaussian (normal) distribution for mean=0, stddev=1.
	static volatile int phase_s = 0;
	static volatile float x_s   = 0.0f;
	float r = 0.0f, u, v;

	if (phase_s != 0) {
		r = x_s;
	} else {
		do {
			const float r1 = mc_randunif(0.0f, 1.0f);
			const float r2 = mc_randunif(0.0f, 1.0f);
			u              = r1;
			v              = r2;
		}
		while (u <= MCLIMITS_EPSILONF * 2.0f);
		r   = mc_sqrtf(-2.0f * mc_logf(u)) * mc_cosf(MCK_KF(MCK_2PI) * v);
		x_s = mc_sqrtf(-2.0f * mc_logf(u)) * mc_sinf(MCK_KF(MCK_2PI) * v);
	}
	phase_s = !phase_s;
	return r;
#	else
//!# Marsaglia polar transform. Standard gaussian (normal) distribution for mean=0, stddev=1.
	static volatile int phase_s = 0;
	static volatile float x_s   = 0.0f;
	float r, s0 = 0.0f, u, v, w;
	if (phase_s != 0) {
		r = x_s;
	} else {
		do {
			const float r1 = mc_randunif(0.0f, 1.0f);
			const float r2 = mc_randunif(0.0f, 1.0f);
			u              = 2.0f * r1 - 1.0f;
			v              = 2.0f * r2 - 1.0f;
			s0              = mc_raise2f(u) + mc_raise2f(v);
		} while (s0 < 1.0f && s0 > 0.0f);
		w = -2.0f * mc_logf(s0) * (1.0f / s0);
		if (w < 0.0f) {
			mc_zsqrtf(&w, &s0, w, 0.0f);
		} else {
			s0 = mc_sqrtf(w);
		}
		r   = u * s0;
		x_s = v * s0;
	}
	phase_s = !phase_s;
	return r;
#	endif
}

MC_TARGET_PROC double mc_randsdg(void)
{
#	if MCTARGET_USE_BOXMULLER
//!# Box-Muller transform. Standard gaussian (normal) distribution for mean=0, stddev=1.
	static volatile int phase_s = 0;
	static volatile double x_s  = 0.0;
	double r = 0.0, u, v;

	if (phase_s != 0) {
		r = x_s;
	} else {
		do {
			const double r1 = mc_randuni(0.0, 1.0);
			const double r2 = mc_randuni(0.0, 1.0);
			u               = r1;
			v               = r2;
		}
		while (u <= MCLIMITS_EPSILON * 2.0);
		r   = mc_sqrt(-2.0 * mc_log(u)) * mc_cos(MCK_K(MCK_2PI) * v);
		x_s = mc_sqrt(-2.0 * mc_log(u)) * mc_sin(MCK_K(MCK_2PI) * v);
	}
	phase_s = !phase_s;
	return r;
#	else
//!# Marsaglia polar transform. Standard gaussian (normal) distribution for mean=0, stddev=1.
	static volatile int phase_s = 0;
	static volatile double x_s  = 0.0;
	double r, s0 = 0.0, u, v, w;
	if (phase_s != 0) {
		r = x_s;
	} else {
		do {
			const double r1 = mc_randuni(0.0, 1.0);
			const double r2 = mc_randuni(0.0, 1.0);
			u               = 2.0 * r1 - 1.0;
			v               = 2.0 * r2 - 1.0;
			s0               = mc_raise2(u) + mc_raise2(v);
		} while (s0 < 1.0 && s0 > 0.0);
		w = -2.0 * mc_log(s0) * (1.0 / s0);
		if (w < 0.0) {
			mc_zsqrt(&w, &s0, w, 0.0);
		} else {
			s0 = mc_sqrt(w);
		}
		r   = u * s0;
		x_s = v * s0;
	}
	phase_s = !phase_s;
	return r;
#	endif
}

MC_TARGET_PROC long double mc_randsdgl(void)
{
#	if MCTARGET_USE_BOXMULLER
//!# Box-Muller transform. Standard gaussian (normal) distribution for mean=0, stddev=1.
	static volatile int phase_s     = 0;
	static volatile long double x_s = 0.0L;
	long double r = 0.0L, u, v;

	if (phase_s != 0) {
		r = x_s;
	} else {
		do {
			const long double r1 = mc_randunil(0.0L, 1.0L);
			const long double r2 = mc_randunil(0.0L, 1.0L);
			u                    = r1;
			v                    = r2;
		}
		while (u <= MCLIMITS_EPSILONL  * 2.0L);
		r   = mc_sqrtl(-2.0L * mc_logl(u)) * mc_cosl(MCK_KL(MCK_2PI) * v);
		x_s = mc_sqrtl(-2.0L * mc_logl(u)) * mc_sinl(MCK_KL(MCK_2PI) * v);
	}
	phase_s = !phase_s;
	return r;
#	else
//!# Marsaglia polar transform. Standard gaussian (normal) distribution for mean=0, stddev=1.
	static volatile int phase_s     = 0;
	static volatile long double x_s = 0.0L;
	long double r, s0 = 0.0L, u, v, w;
	if (phase_s != 0) {
		r = x_s;
	} else {
		do {
			const long double r1 = mc_randunil(0.0L, 1.0L);
			const long double r2 = mc_randunil(0.0L, 1.0L);
			u                    = 2.0L * r1 - 1.0L;
			v                    = 2.0L * r2 - 1.0L;
			s0                    = mc_raise2l(u) + mc_raise2l(v);
		} while (s0 < 1.0 && s0 > 0.0);
		w = -2.0L * mc_logl(s0) * (1.0L / s0);
		if (w < 0.0L) {
			mc_zsqrtl(&w, &s0, w, 0.0L);
		} else {
			s0 = mc_sqrtl(w);
		}
		r   = u * s0;
		x_s = v * s0;
	}
	phase_s = !phase_s;
	return r;
#	endif
}

#pragma mark - mc_randlgm -

MC_TARGET_FUNC float mc_randlgmf(float a, float l)
{
//!# Log(Gamma(alpha,lambda)) generator using Marsaglia and Tsang method.
//!# Log Gamma RNG a=alpha=shape, l=lambda=scale.
	float r = 0.0f, d, c, v, u;
	unsigned int j = 0;
	if (a <= 0.0f || l <= 0.0f) {
		return r;
	}
	if ( a < 1.0f) {
		j = 1;
		a = a + 1.0f;
	}
	d = a - 1.0f / 3.0f;
	c = 1.0f / 3.0f / mc_sqrtf(d);
	do {
		do {
			r = mc_randsdgf();
			v = 1.0f + c * r;
		} while ( v <= 0 );
		v = mc_raise3f(v);
		r = mc_raise2f(r);
		u = mc_randsduf();
		if (u <= 1.0f - 0.331f * mc_raise2f(r)) {
			break;
		}
		u = mc_logf(u);
	} while(!(u <= 0.5f * r + d * (1.0f - v + mc_logf(v))));
	r = d * v;
	if (j) {
		r = r * mc_powf(1.0f - mc_randsduf(), 1.0f / (a - 1.0f));
	}
	return mc_logf(r / l);
}

MC_TARGET_FUNC double mc_randlgm(double a, double l)
{
//!# Log(Gamma(alpha,lambda)) generator using Marsaglia and Tsang method.
//!# Log Gamma RNG a=alpha=shape, l=lambda=scale.
	double r = 0.0, d, c, v, u;
	unsigned int j = 0;
	if (a <= 0.0 || l <= 0.0) {
		return r;
	}
	if ( a < 1.0) {
		j = 1;
		a = a + 1.0;
	}
	d = a - 1.0 / 3.0;
	c = 1.0 / 3.0 / mc_sqrt(d);
	do {
		do {
			r = mc_randsdg();
			v = 1.0 + c * r;
		} while ( v <= 0 );
		v = mc_raise3(v);
		r = mc_raise2(r);
		u = mc_randsdu();
		if (u <= 1.0 - 0.331 * mc_raise2(r)) {
			break;
		}
		u = mc_log(u);
	} while(!(u <= 0.5 * r + d * (1.0 - v + mc_log(v))));
	r = d * v;
	if (j) {
		r = r * mc_pow(1.0 - mc_randsdu(), 1.0 / (a - 1.0));
	}
	return mc_log(r / l);
}

MC_TARGET_FUNC long double mc_randlgml(long double a, long double l)
{
//!# Log(Gamma(alpha,lambda)) generator using Marsaglia and Tsang method.
//!# Log Gamma RNG a=alpha=shape, l=lambda=scale.
	long double r = 0.0L, d, c, v, u;
	unsigned int j = 0;
	if (a <= 0.0L || l <= 0.0L) {
		return r;
	}
	if (a < 1.0L) {
		j = 1;
		a = a + 1.0L;
	}
	d = a - 1.0L / 3.0L;
	c = 1.0L / 3.0L / mc_sqrtl(d);
	do {
		do {
			r = mc_randsdgl();
			v = 1.0L + c * r;
		} while ( v <= 0 );
		v = mc_raise3l(v);
		r = mc_raise2l(r);
		u = mc_randsdul();
		if (u <= 1.0L - 0.331L * mc_raise2l(r)) {
			break;
		}
		u = mc_logl(u);
	} while(!(u <= 0.5L * r + d * (1.0L - v + mc_logl(v))));
	r = d * v;
	if (j) {
		r = r * mc_powl(1.0L - mc_randsdul(), 1.0L / (a - 1.0L));
	}
	return mc_logl(r / l);
}

#pragma mark - mc_randgss -

MC_TARGET_FUNC float mc_randgssf(float mu, float std1)
{
//!# Random number from Gaussian (normal) distribution with given mean and stddev.
	return mu + std1 * mc_randsdgf();
}

MC_TARGET_FUNC double mc_randgss(double mu, double std1)
{
//!# Random number from Gaussian (normal) distribution with given mean and stddev.
	return mu + std1 * mc_randsdg();
}

MC_TARGET_FUNC long double mc_randgssl(long double mu, long double std1)
{
//!# Random number from Gaussian (normal) distribution with given mean and stddev.
	return mu + std1 * mc_randsdgl();
}

#pragma mark - mc_randlgs -

MC_TARGET_FUNC float mc_randlgsf(float mu, float std1)
{
//!# Random number from Log normal distribution with given mean and stddev.
	return mc_expf(mc_randgssf(mu, std1));
}

MC_TARGET_FUNC double mc_randlgs(double mu, double std1)
{
//!# Random number from Log normal distribution with given mean and stddev.
	return mc_exp(mc_randgss(mu, std1));
}

MC_TARGET_FUNC long double mc_randlgsl(long double mu, long double std1)
{
//!# Random number from Log normal distribution with given mean and stddev.
	return mc_expl(mc_randgssl(mu, std1));
}

#pragma mark - mc_randgam -

MC_TARGET_FUNC float mc_randgamf(float a, float l)
{
//!# Gamma(alpha,lambda) generator using Marsaglia and Tsang method.
//!# Gamma RNG a=alpha=shape, l=lambda=scale.
	return mc_expf(mc_randlgmf(a, l));
}

MC_TARGET_FUNC double mc_randgam(double a, double l)
{
//!# Gamma(alpha,lambda) generator using Marsaglia and Tsang method.
//!# Gamma RNG a=alpha=shape, l=lambda=scale.
	return mc_exp(mc_randlgm(a, l));
}

MC_TARGET_FUNC long double mc_randgaml(long double a, long double l)
{
//!# Gamma(alpha,lambda) generator using Marsaglia and Tsang method.
//!# Gamma RNG a=alpha=shape, l=lambda=scale.
	return mc_expl(mc_randlgml(a, l));
}

#pragma mark -  mc_randexp -

MC_TARGET_FUNC float mc_randexpf(float l)
{
//!# Exponential distribution generator.
	const float u = mc_randsduf();
	const float s = 1.0f / (l > 0.0f ? l : 1.0f);
	return -mc_log1mf(u) * s;
}

MC_TARGET_FUNC double mc_randexp(double l)
{
//!# Exponential distribution generator.
	const double u = mc_randsdu();
	const double s = 1.0 / (l > 0.0 ? l : 1.0);
	return -mc_log1m(u) * s;
}

MC_TARGET_FUNC long double mc_randexpl(long double l)
{
//!# Exponential distribution generator.
	const long double u = mc_randsdul();
	const long double s = 1.0L / (l > 0.0L ? l : 0.0L);
	return -mc_log1ml(u) * s;
}

#pragma mark -  mc_randci2 -

MC_TARGET_FUNC float mc_randci2f(float df)
{
//!# Chisquare distribution generator. df=degree of freedom.
	return 2.0f * mc_randgamf(df * 0.5f, 1.0f);
}

MC_TARGET_FUNC double mc_randci2(double df)
{
//!# Chisquare distribution generator. df=degree of freedom.
	return 2.0 * mc_randgam(df * 0.5, 1.0);
}

MC_TARGET_FUNC long double mc_randci2l(long double df)
{
//!# Chisquare distribution generator. df=degree of freedom.
	return 2.0L * mc_randgaml(df * 0.5L, 1.0L);
}

#pragma mark -  mc_randwbl -

MC_TARGET_FUNC float mc_randwblf(float a)
{
//!# Weibull distribution generator. a=alpha=shape.
	return a != 0.0f ? (a == 1.0f ? mc_randexpf(1.0f) : mc_powf(mc_randexpf(1.0f), 1.0f / a)) : 0.0f;
}

MC_TARGET_FUNC double mc_randwbl(double a)
{
//!# Weibull distribution generator. a=alpha=shape.
	return a != 0.0 ? (a == 1.0 ? mc_randexp(1.0f) : mc_pow(mc_randexp(1.0), 1.0 / a)) : 0.0;
}

MC_TARGET_FUNC long double mc_randwbll(long double a)
{
//!# Weibull distribution generator. a=alpha=shape.
	return a != 0.0L ? (a == 1.0L ? mc_randexpl(1.0f) : mc_powl(mc_randexpl(1.0), 1.0L / a)) : 0.0L;
}

#pragma mark -  mc_randbta -

MC_TARGET_FUNC float mc_randbtaf(float a, float b)
{
//!# Beta distribution generator.
	const float x = mc_randgamf(a, 1.0f);
	const float y = mc_randgamf(b, 1.0f);
	const float z = x + y;
	return z != 0.0f ? x / z : 0.0f;
}

MC_TARGET_FUNC double mc_randbta(double a, double b)
{
//!# Beta distribution generator.
	const double x = mc_randgam(a, 1.0);
	const double y = mc_randgam(b, 1.0);
	const double z = x + y;
	return z != 0.0 ? x / z : 0.0;
}

MC_TARGET_FUNC long double mc_randbtal(long double a, long double b)
{
//!# Beta distribution generator.
	const long double x = mc_randgaml(a, 1.0L);
	const long double y = mc_randgaml(b, 1.0L);
	const long double z = x + y;
	return z != 0.0L ? x / z : 0.0L;
}

#pragma mark -  mc_randpto -

MC_TARGET_FUNC float mc_randptof(float a)
{
//!# Pareto distribution generator.
	const float x = mc_randexpf(1.0f) / a;
	return mc_expf(x) - 1.0f;
}

MC_TARGET_FUNC double mc_randpto(double a)
{
//!# Pareto distribution generator.
	const double x = mc_randexp(1.0) / a;
	return mc_exp(x) - 1.0;
}

MC_TARGET_FUNC long double mc_randptol(long double a)
{
//!# Pareto distribution generator.
	const long double x = mc_randexpl(1.0L) / a;
	return mc_expl(x) - 1.0;
}

#endif /* !MC_RAND_H */

/* EOF */