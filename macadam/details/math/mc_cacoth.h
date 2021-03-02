//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_cacoth.h
//
// Copyright (C) 2019-2021 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_zacoth.h>

#ifndef MC_CACOTH_H
#define MC_CACOTH_H

#pragma mark - mc_cacoth -

MC_TARGET_FUNC mc_complex_float_t mc_cacothf(const mc_complex_float_t c)
{
	mc_complex_float_t z;
	float zr, zi;

	mc_zacothf(&zr, &zi, mc_cmplxrf(c), mc_cmplxif(c));
	z = mc_cmplxf(zr, zi);

	return z;
}

MC_TARGET_FUNC mc_complex_double_t mc_cacoth(const mc_complex_double_t c)
{
	mc_complex_double_t z;
	double zr, zi;

	mc_zacoth(&zr, &zi, mc_cmplxr(c), mc_cmplxi(c));
	z = mc_cmplx(zr, zi);

	return z;
}

MC_TARGET_FUNC mc_complex_long_double_t mc_cacothl(const mc_complex_long_double_t c)
{
	mc_complex_long_double_t z;
	long double zr, zi;

	mc_zacothl(&zr, &zi, mc_cmplxrl(c), mc_cmplxil(c));
	z = mc_cmplxl(zr, zi);

	return z;
}

#endif /* !MC_CACOTH_H */

/* EOF */