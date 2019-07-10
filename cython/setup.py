#
# # -*- coding: utf-8, tab-width: 3 -*-

# setup.py
#
# Copyright (C) 2019 Moe123. All rights reserved.
#

import sys, os

from distutils.core import setup
from Cython.Build   import cythonize

os.environ['CFLAGS'] = '-std=c99 -Wextra -pedantic -Wno-newline-eof -I../ -DMC_DISABLE_REENTRANT=1 -DMC_DISABLE_TGMATH=1'

setup(
	ext_modules = cythonize(
		  "mcmath.pyx"
		, language_level = "3"
	)
)

# EOF