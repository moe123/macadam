#
# # -*- coding: utf-8, tab-width: 3 -*-

# mcmath.pyx
#
# Copyright (C) 2019 Moe123. All rights reserved.
#

cimport mcmath

def modf(x):
	cdef double y = 0.0
	cdef double r = mcmath.mc_modf(x, &y)
	return r, y

def zeta(x):
	cdef double r = mcmath.mc_zeta(x)
	return r

# EOF