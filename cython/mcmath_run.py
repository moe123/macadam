#
# # -*- coding: utf-8, tab-width: 3 -*-

# mcmath_run.py
#
# Copyright (C) 2019 Moe123. All rights reserved.
#

from mcmath import fisint, ffrac, modf, zeta

def rangef(start, stop, step):
	n = int((stop - start) / float(step))
	for i in range(n + 1):
		yield start + i * step

print("")

for x in rangef(1, 10, 0.25):
	print("fisint(%0.7E) = %d" % (x, fisint(x)))

print("")

for x in rangef(1, 5, 0.022):
	print("ffrac(%0.7E) = %0.7f" % (x, ffrac(x)))

print("")

for x in rangef(1, 5, 0.025):
	print("modf(%0.7E) = %s" % (x, modf(x)))

print("")

for x in rangef(0, 10, 0.01):
	print("zeta(%0.7E) = %0.15E" % (x, zeta(x)))

# EOF