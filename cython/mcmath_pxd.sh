#!/bin/sh

#
# # -*- coding: utf-8, tab-width: 3 -*-

# mcmath_pxd.sh
#
# Copyright (C) 2019 Moe123. All rights reserved.
#

cmd_pushd ()
{
	command pushd "$@" > /dev/null
}

cmd_popd ()
{
	command popd "$@" > /dev/null
}

cmd_exists () {
	type "$1" &> /dev/null;
}

function main ()
{ 
	declare -r path_self=$(cd $(dirname "$0");pwd)
	declare -r path_base=$(cd $(dirname "$0");cd ..;pwd)
	if [ "$(uname -s)" == "Darwin" ]
	then
		if (cmd_exists gsed); then
			declare -r cmd_sed="gsed"
		else
			echo "Please install gsed cli."
			echo "https://www.macports.org/ports.php?by=library&substr=gsed"
			exit 1
		fi
	else
		declare -r cmd_sed="sed"
	fi

	cmd_pushd "${path_base}"

	declare -a special
	special=( "fisint" "isfinite" "isinf" "isnan" "nchoosek")

	:> "${path_self}/mcmath.pxd"

	echo "# BOF"                      >> "${path_self}/mcmath.pxd"
	echo "from libc.stdint cimport *" >> "${path_self}/mcmath.pxd"
	echo ""                           >> "${path_self}/mcmath.pxd"

	for i in "${!special[@]}"; do 
		fn="${special[${i}]}"
		if [ "${fn}" = "nchoosek" ]; then
			echo "cdef extern from \"<macadam/details/math/mc_${fn}.h>\":" >> "${path_self}/mcmath.pxd"
			echo "\tunsigned int mc_${fn}(unsigned int n, unsigned int k)" >> "${path_self}/mcmath.pxd"
			echo ""                                                        >> "${path_self}/mcmath.pxd"
		else
			echo "cdef extern from \"<macadam/details/math/mc_${fn}.h>\":" >> "${path_self}/mcmath.pxd"
			echo "\tint mc_${fn}(double x)"                                >> "${path_self}/mcmath.pxd"
			echo ""                                                        >> "${path_self}/mcmath.pxd"
		fi
	done

	for f in macadam/details/math/*.h; do
		symbols=$(cat ${f} | grep -E "^MC_TARGET_FUNC double (\w)" | ${cmd_sed} -e "s/MC_TARGET_FUNC /\t/g")
		if [ ${#symbols} -ne 0 ]
		then
			header="cdef extern from \"<${f}>\":"
			echo "${header}" >> "${path_self}/mcmath.pxd"
			echo "${symbols}" >> "${path_self}/mcmath.pxd"
			echo ""          >> "${path_self}/mcmath.pxd"
		fi
	done

	printf "# EOF" >> "${path_self}/mcmath.pxd"

	cmd_popd
}

main "$@"

# EOF