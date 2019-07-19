#!/bin/sh

#
# # -*- coding: utf-8, tab-width: 3 -*-

# mcmath_pxd.sh
#
# Copyright (C) 2019 Moe123. All rights reserved.
#

cmd_pushd () {
	command pushd "$@" > /dev/null
}

cmd_popd () {
	command popd "$@" > /dev/null
}

function main ()
{ 
	declare -r path_self=`cd $(dirname "$0");pwd`
	declare -r path_base=`cd $(dirname "$0");cd ..;pwd`
	if [ "$(uname -s)" == "Darwin" ]
	then
		declare -r cmd_sed="gsed"
	else
		declare -r cmd_sed="sed"
	fi
	cmd_pushd "${path_base}"

	:> ${path_self}/mcmath.pxd

	echo "# BOF"                      >> ${path_self}/mcmath.pxd
	echo "from libc.stdint cimport *" >> ${path_self}/mcmath.pxd
	echo ""                           >> ${path_self}/mcmath.pxd

	echo "cdef extern from \"<macadam/details/math/mc_isfinite.h>\":" >> ${path_self}/mcmath.pxd
	echo "	int mc_isfinite(double x)"                               >> ${path_self}/mcmath.pxd
	echo ""                                                           >> ${path_self}/mcmath.pxd
	echo "cdef extern from \"<macadam/details/math/mc_isinf.h>\":"    >> ${path_self}/mcmath.pxd
	echo "	int mc_isinf(double x)"                                  >> ${path_self}/mcmath.pxd
	echo ""                                                           >> ${path_self}/mcmath.pxd
	echo "cdef extern from \"<macadam/details/math/mc_isnan.h>\":"    >> ${path_self}/mcmath.pxd
	echo "	int mc_isnan(double x)"                                  >> ${path_self}/mcmath.pxd
	echo ""                                                           >> ${path_self}/mcmath.pxd

	for f in macadam/details/math/*.h; do
		symbol=$(cat ${f} | grep -E "^MC_TARGET_FUNC (int|double) (\w)" | ${cmd_sed} -e 's/MC_TARGET_FUNC /\t/g')
		if [ ${#symbol} -ne 0 ]
		then
			header="cdef extern from \"<${f}>\":"
			echo "${header}" >> ${path_self}/mcmath.pxd
			echo "${symbol}" >> ${path_self}/mcmath.pxd
			echo ""          >> ${path_self}/mcmath.pxd
		fi
	done

	printf "# EOF" >> ${path_self}/mcmath.pxd

	cmd_popd
}

main "$@"

# EOF