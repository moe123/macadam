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

function gen_pxd ()
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

	echo "from libc.stdint cimport *" >> ${path_self}/mcmath.pxd
	echo ""                           >> ${path_self}/mcmath.pxd

	for f in macadam/details/math/*.h; do
		header="cdef extern from \"<${f}>\":"
		symbol=$(cat ${f} | grep -E "^MC_TARGET_FUNC (\w)" | ${cmd_sed} -e 's/MC_TARGET_FUNC /\t/g')
		if [ ${#symbol} -ne 0 ]
		then
			echo "${header}" >> ${path_self}/mcmath.pxd
			echo "${symbol}" >> ${path_self}/mcmath.pxd
			echo ""          >> ${path_self}/mcmath.pxd
		fi
	done

	printf "# EOF" >> ${path_self}/mcmath.pxd

	cmd_popd
}

gen_pxd $0 

# EOF