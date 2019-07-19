#
# # -*- coding: utf-8, tab-width: 3 -*-

# mcmath.pyx
#
# Copyright (C) 2019 Moe123. All rights reserved.
#

cimport mcmath

def isinf(x):
	cdef int r = mcmath.mc_isinf(x)
	return r

def isnan(x):
	cdef int r = mcmath.mc_isnan(x)
	return r

def fisint(x):
	cdef int r = mcmath.mc_fisint(x)
	return r

def ffrac(x):
	cdef double r = mcmath.mc_ffrac(x)
	return r

def modf(x):
	cdef double y = 0.0
	cdef double r = mcmath.mc_modf(x, &y)
	return r, y

def zeta(x):
	cdef double r = mcmath.mc_zeta(x)
	return r

# EOF