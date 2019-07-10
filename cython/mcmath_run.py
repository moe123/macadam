#
# # -*- coding: utf-8, tab-width: 3 -*-

# mcmath.py
#
# Copyright (C) 2019 Moe123. All rights reserved.
#

from mcmath import zeta

def rangef(start, stop, step):
	n = int((stop - start) / float(step))
	for i in range(n+1):
		yield start + i * step

for x in rangef(0, 40, 0.01):
	print("zeta(%f) = %0.40E" % (x, zeta(x)))

# EOF