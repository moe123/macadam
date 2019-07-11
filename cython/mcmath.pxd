#
# # -*- coding: utf-8, tab-width: 3 -*-

# mcmath.pxd
#
# Copyright (C) 2019 Moe123. All rights reserved.
#

cdef extern from "<macadam/details/math/mc_fisint.h>":
	int mc_fisint(double x)

cdef extern from "<macadam/details/math/mc_ffrac.h>":
	double mc_ffrac(double x)

cdef extern from "<macadam/details/math/mc_modf.h>":
	double mc_modf(double x, double * y)

cdef extern from "<macadam/details/math/mc_zeta.h>":
	double mc_zeta(double x)

# EOF