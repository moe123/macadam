#!/bin/sh

#
# # -*- coding: utf-8, tab-width: 3 -*-

# mcmath_pyx.sh
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

function last_index_of ()
{
	ifs_current="${IFS}"
	IFS=$'\n'
	local str=( $(echo "${1}" | fold -w1) )
	ifs_current="${IFS}"
	local index=-1
	for (( i=${#str[@]}-1 ; i>=0 ; i-- )) ; do
	 	c=${str[${i}]}
		if [ "${str[${i}]}" = "${2}" ]; then
			index=${i}
			break
		fi
	done
	echo ${index}
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

	:> "${path_self}/mcmath.pyx"

	echo "# BOF"          >> "${path_self}/mcmath.pyx"
	echo "cimport mcmath" >> "${path_self}/mcmath.pyx"
	echo ""               >> "${path_self}/mcmath.pyx"

	declare -a symbols

	ifs_current="${IFS}"
	IFS=$'\n'
	symbols=( $(cat "${path_self}/mcmath.pxd" | grep -E "^\t(double|int|unsigned int) (\w)" | ${cmd_sed} -e "s/\t//g; s/[*]/\\\*/g") )
	ifs_current="${IFS}"

	IFS=$'|'
	for i in "${!symbols[@]}"
	do
		declare -a entities
		ifs_current="${IFS}"
		IFS=$'|'
		entities=( $(echo "${symbols[${i}]}" | ${cmd_sed} -n "s/^\(.*\) mc_\(.*\)(\(.*\))/\1\|\2\|\3/p") )
		IFS="${ifs_current}"

		declare -a cparameter_pairs

		declare call_return="${entities[0]}"
		declare call_symbol="${entities[1]}"

		ifs_current="${IFS}"
		IFS=$','
		cparameter_pairs=( ${entities[2]} )
		IFS="${ifs_current}"

		unset entities

		if [ "${call_symbol}" = "modf" ]; then
			echo "def ${call_symbol}(x):"                                       >> "${path_self}/mcmath.pyx"
			echo "\tcdef double p0 = x"                                         >> "${path_self}/mcmath.pyx"
			echo "\tcdef double p1 = 0"                                         >> "${path_self}/mcmath.pyx"
			echo "\tcdef ${call_return} r0 = mcmath.mc_${call_symbol}(p0, &p1)" >> "${path_self}/mcmath.pyx"
			echo "\treturn r0, p1"                                              >> "${path_self}/mcmath.pyx"
			echo ""                                                             >> "${path_self}/mcmath.pyx"
		else
			declare -a cparameter_types
			declare -a cparameter_names
			tuple=""
			for j in "${!cparameter_pairs[@]}"; do
				cparameter_pair=$(echo "${cparameter_pairs[${j}]}" | awk '{$1=$1};1')
				index=$(last_index_of "${cparameter_pair}" ' ')
				if [[ ${index} -ge 0 ]]; then
					cparameter_types[${j}]="${cparameter_pair:0:${index}}"
					cparameter_names[${j}]="${cparameter_pair:${index} + 1}"
					if [[ ${j} -eq 0 ]]; then
						tuple="${cparameter_names[${j}]}"
					else
						tuple=$(echo "${tuple}", "${cparameter_names[${j}]}")
					fi
				fi
				unset cparameter_pair
				unset index
			done
			echo "def ${call_symbol}(${tuple}):" >> "${path_self}/mcmath.pyx"
			tuple=""
			for k in "${!cparameter_types[@]}"; do
				echo "\tcdef ${cparameter_types[${k}]/const /} p${k} = ${cparameter_names[${k}]}" >> "${path_self}/mcmath.pyx"
				if [[ ${k} -eq 0 ]]; then
					tuple="p${k}"
				else
					tuple=$(echo "${tuple}", "p${k}")
				fi
			done
			echo "\tcdef ${call_return} r0 = mcmath.mc_${call_symbol}(${tuple})" >> "${path_self}/mcmath.pyx"
			echo "\treturn r0"                                                   >> "${path_self}/mcmath.pyx"
			echo ""                                                              >> "${path_self}/mcmath.pyx"
			unset cparameter_types
			unset cparameter_names
		fi
		unset call_return
		unset call_symbol
		unset cparameter_pairs
	done

	printf "# EOF" >> "${path_self}/mcmath.pyx"

	cmd_popd
}

main "$@"

# EOF