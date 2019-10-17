//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_lapacke_lamch.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_LAPACKE_LAMCH_H
#define MC_LAPACKE_LAMCH_H

#pragma mark - mc_lapacke_slamch -

MC_TARGET_FUNC float mc_lapacke_slamch(const char cmach)
{
	const float one = 1.0f, zero = 0.0f;

	float lamch, sfmin, small;
	
	switch (cmach)
	{
		case 'B':
		case 'b':
			lamch = FLT_RADIX;
		break;
		case 'E':
		case 'e':
			lamch = FLT_EPSILON;
		break;
		case 'L':
		case 'l':
			lamch = FLT_MAX_EXP;
		break;
		case 'M':
		case 'm':
			lamch = FLT_MIN_EXP;
		break;
		case 'N':
		case 'n':
			lamch = FLT_MANT_DIG;
		break;
		case 'P':
		case 'p':
			lamch = FLT_RADIX * FLT_EPSILON;
		break;
		case 'R':
		case 'r':
			lamch = FLT_ROUNDS < 2 ? one : zero;
		break;
		case 'S':
		case 's':
			sfmin = FLT_MIN;
			small = one / FLT_MAX;
			if (small >= sfmin) {
				sfmin = small * (one + FLT_EPSILON);
			}
			lamch = sfmin;
		break;
		case 'U':
		case 'u':
			lamch = FLT_MIN;
		break;
		default:
			lamch = zero;
	}
	return lamch;
}

#pragma mark - mc_lapacke_dlamch -

MC_TARGET_FUNC double mc_lapacke_dlamch(const char cmach)
{
	const double one = 1.0, zero = 0.0;

	double lamch, sfmin, small;
	
	switch (cmach)
	{
		case 'B':
		case 'b':
			lamch = FLT_RADIX;
		break;
		case 'E':
		case 'e':
			lamch = DBL_EPSILON;
		break;
		case 'L':
		case 'l':
			lamch = DBL_MAX_EXP;
		break;
		case 'M':
		case 'm':
			lamch = DBL_MIN_EXP;
		break;
		case 'N':
		case 'n':
			lamch = DBL_MANT_DIG;
		break;
		case 'P':
		case 'p':
			lamch = FLT_RADIX * DBL_EPSILON;
		break;
		case 'R':
		case 'r':
			lamch = FLT_ROUNDS < 2 ? one : zero;
		break;
		case 'S':
		case 's':
			sfmin = DBL_MIN;
			small = one / DBL_MAX;
			if (small >= sfmin) {
				sfmin = small * (one + DBL_EPSILON);
			}
			lamch = sfmin;
		break;
		case 'U':
		case 'u':
			lamch = DBL_MIN;
		break;
		default:
			lamch = zero;
	}
	return lamch;
}

#pragma mark - mc_lapacke_llamch -

MC_TARGET_FUNC long double mc_lapacke_llamch(const char cmach)
{
	const long double one = 1.0L, zero = 0.0L;

	long double lamch, sfmin, small;
	
	switch (cmach)
	{
		case 'B':
		case 'b':
			lamch = FLT_RADIX;
		break;
		case 'E':
		case 'e':
			lamch = LDBL_EPSILON;
		break;
		case 'L':
		case 'l':
			lamch = LDBL_MAX_EXP;
		break;
		case 'M':
		case 'm':
			lamch = LDBL_MIN_EXP;
		break;
		case 'N':
		case 'n':
			lamch = LDBL_MANT_DIG;
		break;
		case 'P':
		case 'p':
			lamch = FLT_RADIX * LDBL_EPSILON;
		break;
		case 'R':
		case 'r':
			lamch = FLT_ROUNDS < 2 ? one : zero;
		break;
		case 'S':
		case 's':
			sfmin = LDBL_MIN;
			small = one / LDBL_MAX;
			if (small >= sfmin) {
				sfmin = small * (one + LDBL_EPSILON);
			}
			lamch = sfmin;
		break;
		case 'U':
		case 'u':
			lamch = LDBL_MIN;
		break;
		default:
			lamch = zero;
	}
	return lamch;
}

#endif /* !MC_LAPACKE_LAMCH_H */

/* EOF */