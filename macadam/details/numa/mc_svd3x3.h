//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_svd3x3.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_fabs.h>
#include <macadam/details/math/mc_sqrt.h>
#include <macadam/details/numa/mc_mulab3x3.h>
#include <macadam/details/numa/mc_mulatb3x3.h>
#include <macadam/details/numa/mc_qr3x3.h>
#include <macadam/mcswap.h>

#ifndef MC_SVD3X3_H
#define MC_SVD3X3_H

#pragma mark - mc_svd3x3 -

MC_TARGET_FUNC int mc_svd3x3f(const float a[9], float u[9], float s[9], float v[9])
{
//!# The main result SVD provides is that we can write an m by n matrix A
//!# such as U'*A=S*V' with:
//!#     - U is an [m x p] orthogonal matrix. The left-singular vectors of A are a set of orthonormal eigenvectors of AA'.
//!#     - S is an [n x p] diagonal matrix. The non-negative singular values of M (found on the diagonal entries of Σ) are
//!#       the square roots of the non-negative eigenvalues of both AA' and A'A.
//!#     - V is an [p x p] orthogonal matrix. The right-singular vectors of A are a set of orthonormal eigenvectors of A'A.
//!#     - p=min(m, n) and in this particular case we have m=3, n=3 hence p=3.
	float s0, s1, s2, w;

//!# Step 1: Forming A'*A storing temporarily result into U.
	mc_mulatb3x3f(u, a, a);

//!# Step 2: Computing V i.e right-singular vectors and eigenvalues associated
//!# storing temporarily eigenvalues into S first three entries.
	mc_eigsy3x3f(u, s, v);

//!# Step 3: extracting eigenvalues for clarity and make them singular-values.
//!# a'a is a symmetric normal matrix, hence the singular-values are equal to 
//!# the absolute eigenvalues. Being paranoid; they should be all semi-positive definite.
	s0 = mc_fabsf(s[0]);
	s1 = mc_fabsf(s[1]);
	s2 = mc_fabsf(s[2]);

//!# Step 4: Sorting singular-values and V in descending order (i.e largest first).
//!# \note: eigsy3x3 guarantees eigenvalues to be given in ascending order regardless
//!# the sign i.e smallest first.
	mcswap_var(w, s0, s2);
	mcswap_var(w, v[0], v[2]);
	mcswap_var(w, v[3], v[5]);
	mcswap_var(w, v[6], v[8]);

//!# Step 5: Initializing S to diagonal matrix.
	s[0] = s0;   s[1] = 0.0f; s[2] = 0.0f;
	s[3] = 0.0f; s[4] = s1;   s[5] = 0.0f;
	s[6] = 0.0f; s[7] = 0.0f; s[8] = s2;

//!# Step 6: Computing U i.e left-singular vectors. Forming
//!# left-hand i.e `U-unscaled` by multiplying A per V.
	mc_mulab3x3f(u, a, v);

//!# Step 7: Using QR, used to verify error rate.
	//mc_qrgv3x3f(u, u, s);

//!# Step 7: Computing the square-root singular-values of and `scaling` U such as U=A*V*S^-1.
	if (s[0] != 0.0f) {
		s[0] = mc_sqrtf(s[0]);
		s0   = 1.0f / s[0];
		u[0] = u[0] * s0;
		u[3] = u[3] * s0;
		u[6] = u[6] * s0;
	} else {
		return -1;
	}
	if (s[4] != 0.0f) {
		s[4] = mc_sqrtf(s[4]);
		s1   = 1.0f / s[4];
		u[1] = u[1] * s1;
		u[4] = u[4] * s1;
		u[7] = u[7] * s1;
	} else {
		return -1;
	}
	if (s[8] != 0.0f) {
		s[8] = mc_sqrtf(s[8]);
		s2   = 1.0f / s[8];
		u[2] = u[2] * s2;
		u[5] = u[5] * s2;
		u[8] = u[8] * s2;
	} else {
		return -1;
	}
	return 0;
}

MC_TARGET_FUNC int mc_svd3x3ff(const float a[9], double u[9], double s[9], double v[9])
{
//!# The main result SVD provides is that we can write an m by n matrix A
//!# such as U'*A=S*V' with:
//!#     - U is an [m x p] orthogonal matrix. The left-singular vectors of A are a set of orthonormal eigenvectors of AA'.
//!#     - S is an [n x p] diagonal matrix. The non-negative singular values of M (found on the diagonal entries of Σ) are
//!#       the square roots of the non-negative eigenvalues of both AA' and A'A.
//!#     - V is an [p x p] orthogonal matrix. The right-singular vectors of A are a set of orthonormal eigenvectors of A'A.
//!#     - p=min(m, n) and in this particular case we have m=3, n=3 hence p=3.
	double s0, s1, s2, w;

//!# Step 1: Forming A'*A storing temporarily result into U.
	mc_mulatb3x3ff(u, a, a);

//!# Step 2: Computing V i.e right-singular vectors and eigenvalues associated
//!# storing temporarily eigenvalues into S first three entries.
	mc_eigsy3x3(u, s, v);

//!# Step 3: extracting eigenvalues for clarity and make them singular-values.
//!# a'a is a symmetric normal matrix, hence the singular-values are equal to 
//!# the absolute eigenvalues. Being paranoid; they should be all semi-positive definite.
	s0 = mc_fabs(s[0]);
	s1 = mc_fabs(s[1]);
	s2 = mc_fabs(s[2]);

//!# Step 4: Sorting singular-values and V in descending order (i.e largest first).
//!# \note: eigsy3x3 guarantees eigenvalues to be given in ascending order regardless
//!# the sign i.e smallest first.
	mcswap_var(w, s0, s2);
	mcswap_var(w, v[0], v[2]);
	mcswap_var(w, v[3], v[5]);
	mcswap_var(w, v[6], v[8]);

//!# Step 5: Initializing S to diagonal matrix.
	s[0] = s0;  s[1] = 0.0; s[2] = 0.0;
	s[3] = 0.0; s[4] = s1;  s[5] = 0.0;
	s[6] = 0.0; s[7] = 0.0; s[8] = s2;

//!# Step 6: Computing U i.e left-singular vectors. Forming
//!# left-hand i.e `U-unscaled` by multiplying A per V.
	mc_mulab3x3fd(u, a, v);

//!# Step 7: Computing the square-root singular-values of and `scaling` U such as U=A*V*S^-1.
	if (s[0] != 0.0) {
		s[0] = mc_sqrt(s[0]);
		s0   = 1.0 / s[0];
		u[0] = u[0] * s0;
		u[3] = u[3] * s0;
		u[6] = u[6] * s0;
	} else {
		return -1;
	}
	if (s[4] != 0.0) {
		s[4] = mc_sqrt(s[4]);
		s1   = 1.0 / s[4];
		u[1] = u[1] * s1;
		u[4] = u[4] * s1;
		u[7] = u[7] * s1;
	} else {
		return -1;
	}
	if (s[8] != 0.0) {
		s[8] = mc_sqrt(s[8]);
		s2   = 1.0 / s[8];
		u[2] = u[2] * s2;
		u[5] = u[5] * s2;
		u[8] = u[8] * s2;
	} else {
		return -1;
	}
	return 0;
}

MC_TARGET_FUNC int mc_svd3x3(const double a[9], double u[9], double s[9], double v[9])
{
//!# The main result SVD provides is that we can write an m by n matrix A
//!# such as U'*A=S*V' with:
//!#     - U is an [m x p] orthogonal matrix. The left-singular vectors of A are a set of orthonormal eigenvectors of AA'.
//!#     - S is an [n x p] diagonal matrix. The non-negative singular values of M (found on the diagonal entries of Σ) are
//!#       the square roots of the non-negative eigenvalues of both AA' and A'A.
//!#     - V is an [p x p] orthogonal matrix. The right-singular vectors of A are a set of orthonormal eigenvectors of A'A.
//!#     - p=min(m, n) and in this particular case we have m=3, n=3 hence p=3.
	double s0, s1, s2, w;

//!# Step 1: Forming A'*A storing temporarily result into U.
	mc_mulatb3x3(u, a, a);

//!# Step 2: Computing V i.e right-singular vectors and eigenvalues associated
//!# storing temporarily eigenvalues into S first three entries.
	mc_eigsy3x3(u, s, v);

//!# Step 3: extracting eigenvalues for clarity and make them singular-values.
//!# a'a is a symmetric normal matrix, hence the singular-values are equal to 
//!# the absolute eigenvalues. Being paranoid; they should be all semi-positive definite.
	s0 = mc_fabs(s[0]);
	s1 = mc_fabs(s[1]);
	s2 = mc_fabs(s[2]);

//!# Step 4: Sorting singular-values and V in descending order (i.e largest first).
//!# \note: eigsy3x3 guarantees eigenvalues to be given in ascending order regardless
//!# the sign i.e smallest first.
	mcswap_var(w, s0, s2);
	mcswap_var(w, v[0], v[2]);
	mcswap_var(w, v[3], v[5]);
	mcswap_var(w, v[6], v[8]);

//!# Step 5: Initializing S to diagonal matrix.
	s[0] = s0;  s[1] = 0.0; s[2] = 0.0;
	s[3] = 0.0; s[4] = s1;  s[5] = 0.0;
	s[6] = 0.0; s[7] = 0.0; s[8] = s2;

//!# Step 6: Computing U i.e left-singular vectors. Forming
//!# left-hand i.e `U-unscaled` by multiplying A per V.
	mc_mulab3x3(u, a, v);

//!# Step 7: Using QR, used to verify error rate.
	//mc_qrgv3x3(u, u, s);

//!# Step 7: Computing the square-root singular-values of and `scaling` U such as U=A*V*S^-1.
	if (s[0] != 0.0) {
		s[0] = mc_sqrt(s[0]);
		s0   = 1.0 / s[0];
		u[0] = u[0] * s0;
		u[3] = u[3] * s0;
		u[6] = u[6] * s0;
	} else {
		return -1;
	}
	if (s[4] != 0.0) {
		s[4] = mc_sqrt(s[4]);
		s1   = 1.0 / s[4];
		u[1] = u[1] * s1;
		u[4] = u[4] * s1;
		u[7] = u[7] * s1;
	} else {
		return -1;
	}
	if (s[8] != 0.0) {
		s[8] = mc_sqrt(s[8]);
		s2   = 1.0 / s[8];
		u[2] = u[2] * s2;
		u[5] = u[5] * s2;
		u[8] = u[8] * s2;
	} else {
		return -1;
	}
	return 0;
}

MC_TARGET_FUNC int mc_svd3x3l(const long double a[9], long double u[9], long double s[9], long double v[9])
{
//!# The main result SVD provides is that we can write an m by n matrix A
//!# such as U'*A=S*V' with:
//!#     - U is an [m x p] orthogonal matrix. The left-singular vectors of A are a set of orthonormal eigenvectors of AA'.
//!#     - S is an [n x p] diagonal matrix. The non-negative singular values of M (found on the diagonal entries of Σ) are
//!#       the square roots of the non-negative eigenvalues of both AA' and A'A.
//!#     - V is an [p x p] orthogonal matrix. The right-singular vectors of A are a set of orthonormal eigenvectors of A'A.
//!#     - p=min(m, n) and in this particular case we have m=3, n=3 hence p=3.
	long double s0, s1, s2, w;

//!# Step 1: Forming A'*A storing temporarily result into U.
	mc_mulatb3x3l(u, a, a);

//!# Step 2: Computing V i.e right-singular vectors and eigenvalues associated
//!# storing temporarily eigenvalues into S first three entries.
	mc_eigsy3x3l(u, s, v);

//!# Step 3: extracting eigenvalues for clarity and make them singular-values.
//!# a'a is a symmetric normal matrix, hence the singular-values are equal to 
//!# the absolute eigenvalues. Being paranoid; they should be all semi-positive definite.
	s0 = mc_fabsl(s[0]);
	s1 = mc_fabsl(s[1]);
	s2 = mc_fabsl(s[2]);

//!# Step 4: Sorting singular-values and V in descending order (i.e largest first).
//!# \note: eigsy3x3 guarantees eigenvalues to be given in ascending order regardless
//!# the sign i.e smallest first.
	mcswap_var(w, s0, s2);
	mcswap_var(w, v[0], v[2]);
	mcswap_var(w, v[3], v[5]);
	mcswap_var(w, v[6], v[8]);

//!# Step 5: Initializing S to diagonal matrix.
	s[0] = s0;   s[1] = 0.0L; s[2] = 0.0L;
	s[3] = 0.0L; s[4] = s1;   s[5] = 0.0L;
	s[6] = 0.0L; s[7] = 0.0L; s[8] = s2;

//!# Step 6: Computing U i.e left-singular vectors. Forming
//!# left-hand i.e `U-unscaled` by multiplying A per V.
	mc_mulab3x3l(u, a, v);

//!# Step 7: Using QR, used to verify error rate.
	//mc_qrgv3x3l(u, u, s);

//!# Step 7: Computing the square-root singular-values of and `scaling` U such as U=A*V*S^-1.
	if (s[0] != 0.0L) {
		s[0] = mc_sqrtl(s[0]);
		s0   = 1.0L / s[0];
		u[0] = u[0] * s0;
		u[3] = u[3] * s0;
		u[6] = u[6] * s0;
	} else {
		return -1;
	}
	if (s[4] != 0.0L) {
		s[4] = mc_sqrtl(s[4]);
		s1   = 1.0L / s[4];
		u[1] = u[1] * s1;
		u[4] = u[4] * s1;
		u[7] = u[7] * s1;
	} else {
		return -1;
	}
	if (s[8] != 0.0L) {
		s[8] = mc_sqrtl(s[8]);
		s2   = 1.0L / s[8];
		u[2] = u[2] * s2;
		u[5] = u[5] * s2;
		u[8] = u[8] * s2;
	} else {
		return -1;
	}
	return 0;
}

#endif /* !MC_SVD3X3_H */

/* EOF */