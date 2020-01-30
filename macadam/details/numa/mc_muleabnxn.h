//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_muleabnxn.h
//
// Copyright (C) 2019-2020 Moe123. All rights reserved.
//

#include <macadam/details/numa/mc_muleabmxn.h>

#ifndef MC_MULEABNXN_H
#define MC_MULEABNXN_H

#pragma mark - mc_muleabnxn -

MC_TARGET_FUNC void mc_muleabnxnf(int n, float * restrict c, const float * a, const float * b)
{
//!# c=a.*b i.e Hadamard product.
	mc_muleabmxnf(n, n, c, a, b);
}

MC_TARGET_FUNC void mc_muleabnxnff(int n, double * restrict c, const float * a, const float * b)
{
//!# c=a.*b i.e Hadamard product.
	mc_muleabmxnff(n, n, c, a, b);
}

MC_TARGET_FUNC void mc_muleabnxnfd(int n, double * restrict c, const float * a, const double * b)
{
//!# c=a.*b i.e Hadamard product.
	mc_muleabmxnfd(n, n, c, a, b);
}

MC_TARGET_FUNC void mc_muleabnxndf(int n, double * restrict c, const double * a, const float * b)
{
//!# c=a.*b i.e Hadamard product.
	mc_muleabmxndf(n, n, c, a, b);
}

MC_TARGET_FUNC void mc_muleabnxn(int n, double * restrict c, const double * a, const double * b)
{
//!# c=a.*b i.e Hadamard product.
	mc_muleabmxn(n, n, c, a, b);
}

MC_TARGET_FUNC void mc_muleabnxnl(int n, long double * restrict c, const long double * a, const long double * b)
{
//!# c=a.*b i.e Hadamard product.
	mc_muleabmxnl(n, n, c, a, b);
}

#endif /* !MC_MULEABNXN_H */

/* EOF */