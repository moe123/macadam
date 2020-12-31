// # -*- coding: utf-8, tab-width: 3 -*-

// mc_blas_native.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/mc_target.h>

#ifndef MC_BLAS_NATIVE_TARGET_H
#define MC_BLAS_NATIVE_TARGET_H

#	if MC_TARGET_BLAS_USE_ACCELERATE
#		include <Accelerate/Accelerate.h>
#	elif MC_TARGET_BLAS_USE_VECLIB
#		include <vecLib/cblas.h>
#	elif MC_TARGET_BLAS_USE_MLK
#		undef  MKL_INT
#		undef  MKL_UINT
#		undef  MKL_Complex8
#		undef  MKL_Complex16
#		define MKL_INT       int
#		define MKL_UINT      unsigned int
#		define MKL_Complex8  mc_complex_float_t
#		define MKL_Complex16 mc_complex_double_t
#		include "mkl_cblas.h"
#	elif MC_TARGET_BLAS_USE_OPENBLAS
#		if defined __has_include
#			if __has_include("cblas_openblas.h")
#				include "cblas_openblas.h"
#			elif __has_include("cblas-openblas.h")
#				include "cblas-openblas.h"
#			else
#				include "cblas.h"
#		endif
#		else
#			include "cblas.h"
#		endif
#	else
#		include "cblas.h"
#	endif

#endif /* !MC_BLAS_NATIVE_TARGET_H */

/* EOF */