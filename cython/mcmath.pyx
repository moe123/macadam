#
# # -*- coding: utf-8, tab-width: 3 -*-

# mcmath.pyx
#
# Copyright (C) 2019 Moe123. All rights reserved.
#

cimport mcmath

def zeta(x):
	return mcmath.mc_zeta(x)

# EOF