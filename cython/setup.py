#
# # -*- coding: utf-8, tab-width: 3 -*-

# setup.py
#
# Copyright (C) 2019 Moe123. All rights reserved.
#

from distutils.core import setup
from Cython.Build   import cythonize

setup(
	ext_modules = cythonize(
		  "mcmath.pyx"
		, language_level = "3"
	)
)

# EOF