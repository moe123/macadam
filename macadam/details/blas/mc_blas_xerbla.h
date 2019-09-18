//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_xerbla.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#ifndef MC_BLAS_XERBLA_H
#define MC_BLAS_XERBLA_H

MC_TARGET_FUNC void mc_blas_xerbla(const char * srname, int info)
{
	fprintf(stderr,
		"** On entry to %6s, parameter number %2d had an illegal value.\n"
		, srname
		, info
	);
}

#endif /* !MC_BLAS_XERBLA_H */

/* EOF */