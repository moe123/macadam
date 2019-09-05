//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_randi.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>
#include <macadam/mcconsts.h>
#include <macadam/mclimits.h>

#ifndef MC_RANDI_H
#define MC_RANDI_H

#	undef  MCTARGET_USE_LIBCRAND
#	undef  MCTARGET_USE_MARSAGLIAMWC
#	undef  MCTARGET_USE_MARSAGLIAXOR128
#	undef  MCTARGET_USE_BOXMULLER

#	undef  MCTARGET_USE_LFSR113
#	define MCTARGET_USE_LFSR113 1

#	if MCTARGET_USE_MARSAGLIAMWC
static volatile unsigned int mc_randi_seeds_s[]  = { 1234, 0, 5678, 0 };
#	else
static volatile unsigned int mc_randi_seeds_s[]  = { 2, 8, 16, 128 };
#	endif

static volatile unsigned int mc_randi_init_s = 0;

#	if MCTARGET_USE_LIBCRAND
#		define MCLIMITS_RANDMAX mc_cast(const unsigned int, RAND_MAX)
#	elif MCTARGET_USE_MARSAGLIAMWC
#		define MCLIMITS_RANDMAX MCLIMITS_UIMAX
#	elif MCTARGET_USE_LFSR113
#		define MCLIMITS_RANDMAX MCLIMITS_UIMAX
#	else
#		define MCLIMITS_RANDMAX MCLIMITS_UIMAX
#	endif

MC_TARGET_PROC void mc_srandb(
	  unsigned int s1
	, unsigned int s2
	, unsigned int s3
	, unsigned int s4
	, unsigned int s5
) {
	if (mc_randi_init_s < 1) {
		++mc_randi_init_s;
	}
	s4                  = s4 + s5;
	mc_randi_seeds_s[0] = s1 > 2   && s1 < MCLIMITS_USMAX ? s1 : 2;
	mc_randi_seeds_s[1] = s2 > 8   && s2 < MCLIMITS_USMAX ? s2 : 8;
	mc_randi_seeds_s[2] = s3 > 16  && s3 < MCLIMITS_USMAX ? s3 : 16;
	mc_randi_seeds_s[3] = s4 > 128 && s4 < MCLIMITS_USMAX ? s4 : 128;
#	if MCTARGET_USE_LIBCRAND
#	if MC_TARGET_CPP98
	::srand(mc_randi_seeds_s[0] + mc_randi_seeds_s[1] + mc_randi_seeds_s[2] + mc_randi_seeds_s[3]);
#	else
	srand(mc_randi_seeds_s[0] + mc_randi_seeds_s[1] + mc_randi_seeds_s[2] + mc_randi_seeds_s[3]);
#	endif
#	elif MCTARGET_USE_MARSAGLIAMWC
	mc_randi_seeds_s[0] = s1 > 1234 && s1 < MCLIMITS_USMAX ? s1 : 1234;
	mc_randi_seeds_s[1] = s2 > 5678 && s2 < MCLIMITS_USMAX ? s2 : 5678;
	mc_randi_seeds_s[0] = mc_randi_seeds_s[0] + mc_randi_seeds_s[2];
	mc_randi_seeds_s[1] = mc_randi_seeds_s[2] + mc_randi_seeds_s[3];
#	endif
}

MC_TARGET_PROC void mc_ssrandb()
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
	mc_srandb(s1, s2, s3, s4, s5);
}

MC_TARGET_PROC unsigned int mc_randi(void)
{
	if (mc_randi_init_s < 1) {
		++mc_randi_init_s;
		mc_ssrandb();
	}
#	if MCTARGET_USE_LIBCRAND
	++mc_randi_init_s;
	if (mc_randi_init_s > 600) {
		mc_randi_init_s = 0;
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
	mc_randi_seeds_s[0] = 36969 * (mc_randi_seeds_s[0] & 0177777) + (mc_randi_seeds_s[0] >> 16);
	mc_randi_seeds_s[1] = 18000 * (mc_randi_seeds_s[1] & 0177777) + (mc_randi_seeds_s[1] >> 16);
	b                  = ((mc_randi_seeds_s[0] << 16) ^ (mc_randi_seeds_s[1] & 0177777));
	if (!(b < MCLIMITS_RANDMAX)) {
		mc_ssrandb();
		return MCLIMITS_RANDMAX;
	}
	return b;
#	elif MCTARGET_USE_LFSR113
//!# 32-bits Random number generator [0, UINT_MAX].
	unsigned int b;
//!# Tables of maximally equidistributed combined LFSR generators. Pierre L'Ecuyer.
//!# @see https://www.ams.org/journals/mcom/1999-68-225/S0025-5718-99-01039-X/S0025-5718-99-01039-X.pdf.
	b                   = ((mc_randi_seeds_s[0] << 6 ) ^ mc_randi_seeds_s[0]) >> 13;
	mc_randi_seeds_s[0] = ((mc_randi_seeds_s[0] & 4294967294U) << 18) ^ b;
	b                   = ((mc_randi_seeds_s[1] << 2 ) ^ mc_randi_seeds_s[1]) >> 27;
	mc_randi_seeds_s[1] = ((mc_randi_seeds_s[1] & 4294967288U) << 2 ) ^ b;
	b                   = ((mc_randi_seeds_s[2] << 13) ^ mc_randi_seeds_s[2]) >> 21;
	mc_randi_seeds_s[2] = ((mc_randi_seeds_s[2] & 4294967280U) << 7 ) ^ b;
	b                   = ((mc_randi_seeds_s[3] << 3 ) ^ mc_randi_seeds_s[3]) >> 12;
	mc_randi_seeds_s[3] = ((mc_randi_seeds_s[3] & 4294967168U) << 13) ^ b;
	b                   = (mc_randi_seeds_s[0] ^ mc_randi_seeds_s[1] ^ mc_randi_seeds_s[2] ^ mc_randi_seeds_s[3]);

	if (!(b < MCLIMITS_RANDMAX)) {
		mc_ssrandb();
		return MCLIMITS_RANDMAX;
	}
	return b;
#	else
//!# 32-bits Random number generator [0, UINT_MAX].
	unsigned int b, s0;
//!# @see xorshift128, Marsaglia "Xorshift RNGs" p. 5.
	b                    = mc_randi_seeds_s[3];
	s0                   = mc_randi_seeds_s[0];
	mc_randi_seeds_s[3]  = mc_randi_seeds_s[2];
	mc_randi_seeds_s[2]  = mc_randi_seeds_s[1];
	mc_randi_seeds_s[1]  = s0;
	b                  ^= b << 11;
	b                  ^= b >> 8;
	b                   = mc_randi_seeds_s[0] = b ^ s0 ^ (s0 >> 19);

	if (!(b < MCLIMITS_RANDMAX)) {
		mc_ssrandb();
		return MCLIMITS_RANDMAX;
	}
	return b;
#	endif
}

#endif /* !MC_RANDI_H */

/* EOF */