//
// # -*- coding: utf-8, tab-width: 3 -*-

// mc_svdmx3.h
//
// Copyright (C) 2019 Moe123. All rights reserved.
//

#include <macadam/details/math/mc_copysign.h>
#include <macadam/details/numa/mc_mulabmxn.h>
#include <macadam/details/numa/mc_mulatbmxn.h>
#include <macadam/details/numa/mc_mgsmxn.h>
#include <macadam/mcswap.h>

#ifndef MC_SVDMX3_H
#define MC_SVDMX3_H

#pragma mark - mc_svdmx3 -

MC_TARGET_FUNC int mc_svdmx3f(int m, const float * a, float * u, float s[9], float v[9])
{
//!# The main result SVD provides is that we can write an m by n matrix A
//!# such as U'*A=S*V' with:
//!#     - U is an [m x p] orthogonal matrix. The left-singular vectors of A are a set of orthonormal eigenvectors of AA'.
//!#     - S is an [n x p] diagonal matrix. The non-negative singular values of A (found on the diagonal entries of S) are
//!#       the square roots of the non-negative eigenvalues of both AA' and A'A.
//!#     - V is an [p x p] orthogonal matrix. The right-singular vectors of A are a set of orthonormal eigenvectors of A'A.
//!#     - p=min(m, n) and in this particular case we have n=3 hence p=3.
	int i;
	float w;

//!# Step 1: Forming A'*A storing temporarily result into U.
	mc_mulatbmxnf(m, 3, 3, u, a, a);

//!# Step 2: Computing V of A'*A i.e right-singular vectors.
	if (0 == mc_eigsy3x3f(u, s, v)) {
		mc_eye3x3f(s);
		mc_mulabmxnf(m, 3, 3, u, a, v);
//!# Step 3: Computing singular-values and U such as U=A*V*S^-1.
		if (0 == mc_mgsmxnf(m, 3, u, u, s)) {
//!# Step 4: Decimeting off-diagonal residual elements.
			s[1] = 0.0f; s[2] = 0.0f;
			s[3] = 0.0f; s[5] = 0.0f;
			s[6] = 0.0f; s[7] = 0.0f;
//!# Step 5: Changing sign if required.
			if (mc_copysignf(1.0f, s[0]) < 0.0f) {
				s[0] = -s[0];
				v[0] = -v[0];
				v[3] = -v[3];
				v[6] = -v[6];
			}
			if (mc_copysignf(1.0f, s[4]) < 0.0f) {
				s[4] = -s[4];
				v[1] = -v[1];
				v[4] = -v[4];
				v[7] = -v[7];
			}
			if (mc_copysignf(1.0f, s[8]) < 0.0f) {
				s[8] = -s[8];
				v[2] = -v[2];
				v[5] = -v[5];
				v[8] = -v[8];
			}
//!# Step 6: Reordering singular-values and basis (descending i.e largest first).
			if (s[0] < s[4]) {
				mcswap_var(w, s[0], s[4]);

				mcswap_var(w, v[0], v[1]);
				mcswap_var(w, v[3], v[4]);
				mcswap_var(w, v[6], v[7]);

				for (i = 0; i < m; i++) {
					mcswap_var(w, u[(3 * i)], u[(3 * i) + 1]);
				}
			}
			if (s[0] < s[8]) {
				mcswap_var(w, s[0], s[8]);

				mcswap_var(w, v[0], v[2]);
				mcswap_var(w, v[3], v[5]);
				mcswap_var(w, v[6], v[8]);

				for (i = 0; i < m; i++) {
					mcswap_var(w, u[(3 * i)], u[(3 * i) + 2]);
				}
			}
			if (s[4] < s[8]) {
				mcswap_var(w, s[4], s[8]);

				mcswap_var(w, v[1], v[2]);
				mcswap_var(w, v[4], v[5]);
				mcswap_var(w, v[7], v[8]);

				for (i = 0; i < m; i++) {
					mcswap_var(w, u[(3 * i) + 1], u[(3 * i) + 2]);
				}
			}
			return 0;
		}
	}
	return -1;
}

MC_TARGET_FUNC int mc_svdmx3ff(int m, const float * a, double * u, double s[9], double v[9])
{
//!# The main result SVD provides is that we can write an m by n matrix A
//!# such as U'*A=S*V' with:
//!#     - U is an [m x p] orthogonal matrix. The left-singular vectors of A are a set of orthonormal eigenvectors of AA'.
//!#     - S is an [n x p] diagonal matrix. The non-negative singular values of A (found on the diagonal entries of S) are
//!#       the square roots of the non-negative eigenvalues of both AA' and A'A.
//!#     - V is an [p x p] orthogonal matrix. The right-singular vectors of A are a set of orthonormal eigenvectors of A'A.
//!#     - p=min(m, n) and in this particular case we have n=3 hence p=3.
	int i;
	double w;

//!# Step 1: Forming A'*A storing temporarily result into U.
	mc_mulatbmxnff(m, 3, 3, u, a, a);

//!# Step 2: Computing V of A'*A i.e right-singular vectors.
	if (0 == mc_eigsy3x3(u, s, v)) {
		mc_eye3x3(s);
		mc_mulabmxnfd(m, 3, 3, u, a, v);
//!# Step 3: Computing singular-values and U such as U=A*V*S^-1.
		if (0 == mc_mgsmxn(m, 3, u, u, s)) {
//!# Step 4: Decimeting off-diagonal residual elements.
			s[1] = 0.0; s[2] = 0.0;
			s[3] = 0.0; s[5] = 0.0;
			s[6] = 0.0; s[7] = 0.0;
//!# Step 5: Changing sign if required.
			if (mc_copysign(1.0, s[0]) < 0.0) {
				s[0] = -s[0];
				v[0] = -v[0];
				v[3] = -v[3];
				v[6] = -v[6];
			}
			if (mc_copysign(1.0, s[4]) < 0.0) {
				s[4] = -s[4];
				v[1] = -v[1];
				v[4] = -v[4];
				v[7] = -v[7];
			}
			if (mc_copysign(1.0, s[8]) < 0.0) {
				s[8] = -s[8];
				v[2] = -v[2];
				v[5] = -v[5];
				v[8] = -v[8];
			}
//!# Step 6: Reordering singular-values and basis (descending i.e largest first).
			if (s[0] < s[4]) {
				mcswap_var(w, s[0], s[4]);

				mcswap_var(w, v[0], v[1]);
				mcswap_var(w, v[3], v[4]);
				mcswap_var(w, v[6], v[7]);

				mcswap_var(w, u[0], u[1]);
				mcswap_var(w, u[3], u[4]);
				mcswap_var(w, u[6], u[7]);
			}
			if (s[0] < s[8]) {
				mcswap_var(w, s[0], s[8]);if (s[0] < s[4]) {
				mcswap_var(w, s[0], s[4]);

				mcswap_var(w, v[0], v[1]);
				mcswap_var(w, v[3], v[4]);
				mcswap_var(w, v[6], v[7]);

				for (i = 0; i < m; i++) {
					mcswap_var(w, u[(3 * i)], u[(3 * i) + 1]);
				}
			}
			if (s[0] < s[8]) {
				mcswap_var(w, s[0], s[8]);

				mcswap_var(w, v[0], v[2]);
				mcswap_var(w, v[3], v[5]);
				mcswap_var(w, v[6], v[8]);

				for (i = 0; i < m; i++) {
					mcswap_var(w, u[(3 * i)], u[(3 * i) + 2]);
				}
			}
			if (s[4] < s[8]) {
				mcswap_var(w, s[4], s[8]);

				mcswap_var(w, v[1], v[2]);
				mcswap_var(w, v[4], v[5]);
				mcswap_var(w, v[7], v[8]);

				for (i = 0; i < m; i++) {
					mcswap_var(w, u[(3 * i) + 1], u[(3 * i) + 2]);
				}
			}

				mcswap_var(w, v[0], v[2]);
				mcswap_var(w, v[3], v[5]);
				mcswap_var(w, v[6], v[8]);

				mcswap_var(w, u[0], u[2]);
				mcswap_var(w, u[3], u[5]);
				mcswap_var(w, u[6], u[8]);
			}
			if (s[4] < s[8]) {
				mcswap_var(w, s[4], s[8]);

				mcswap_var(w, v[1], v[2]);
				mcswap_var(w, v[4], v[5]);
				mcswap_var(w, v[7], v[8]);

				mcswap_var(w, u[1], u[2]);
				mcswap_var(w, u[4], u[5]);
				mcswap_var(w, u[7], u[8]);
			}
			return 0;
		}
	}
	return -1;
}

MC_TARGET_FUNC int mc_svdmx3(int m, const double * a, double * u, double s[9], double v[9])
{
//!# The main result SVD provides is that we can write an m by n matrix A
//!# such as U'*A=S*V' with:
//!#     - U is an [m x p] orthogonal matrix. The left-singular vectors of A are a set of orthonormal eigenvectors of AA'.
//!#     - S is an [n x p] diagonal matrix. The non-negative singular values of A (found on the diagonal entries of S) are
//!#       the square roots of the non-negative eigenvalues of both AA' and A'A.
//!#     - V is an [p x p] orthogonal matrix. The right-singular vectors of A are a set of orthonormal eigenvectors of A'A.
//!#     - p=min(m, n) and in this particular case we have n=3 hence p=3.
	int i;
	double w;

//!# Step 1: Forming A'*A storing temporarily result into U.
	mc_mulatbmxn(m, 3, 3, u, a, a);

//!# Step 2: Computing V of A'*A i.e right-singular vectors.
	if (0 == mc_eigsy3x3(u, s, v)) {
		mc_eye3x3(s);
		mc_mulabmxn(m, 3, 3, u, a, v);
//!# Step 3: Computing singular-values and U such as U=A*V*S^-1.
		if (0 == mc_mgsmxn(m, 3, u, u, s)) {
//!# Step 4: Decimeting off-diagonal residual elements.
			s[1] = 0.0; s[2] = 0.0;
			s[3] = 0.0; s[5] = 0.0;
			s[6] = 0.0; s[7] = 0.0;
//!# Step 5: Changing sign if required.
			if (mc_copysign(1.0, s[0]) < 0.0) {
				s[0] = -s[0];
				v[0] = -v[0];
				v[3] = -v[3];
				v[6] = -v[6];
			}
			if (mc_copysign(1.0, s[4]) < 0.0) {
				s[4] = -s[4];
				v[1] = -v[1];
				v[4] = -v[4];
				v[7] = -v[7];
			}
			if (mc_copysign(1.0, s[8]) < 0.0) {
				s[8] = -s[8];
				v[2] = -v[2];
				v[5] = -v[5];
				v[8] = -v[8];
			}
//!# Step 6: Reordering singular-values and basis (descending i.e largest first).
			if (s[0] < s[4]) {
				mcswap_var(w, s[0], s[4]);

				mcswap_var(w, v[0], v[1]);
				mcswap_var(w, v[3], v[4]);
				mcswap_var(w, v[6], v[7]);

				for (i = 0; i < m; i++) {
					mcswap_var(w, u[(3 * i)], u[(3 * i) + 1]);
				}
			}
			if (s[0] < s[8]) {
				mcswap_var(w, s[0], s[8]);

				mcswap_var(w, v[0], v[2]);
				mcswap_var(w, v[3], v[5]);
				mcswap_var(w, v[6], v[8]);

				for (i = 0; i < m; i++) {
					mcswap_var(w, u[(3 * i)], u[(3 * i) + 2]);
				}
			}
			if (s[4] < s[8]) {
				mcswap_var(w, s[4], s[8]);

				mcswap_var(w, v[1], v[2]);
				mcswap_var(w, v[4], v[5]);
				mcswap_var(w, v[7], v[8]);

				for (i = 0; i < m; i++) {
					mcswap_var(w, u[(3 * i) + 1], u[(3 * i) + 2]);
				}
			}
			return 0;
		}
	}
	return -1;
}

MC_TARGET_FUNC int mc_svdmx3l(int m, const long double * a, long double * u, long double s[9], long double v[9])
{
//!# The main result SVD provides is that we can write an m by n matrix A
//!# such as U'*A=S*V' with:
//!#     - U is an [m x p] orthogonal matrix. The left-singular vectors of A are a set of orthonormal eigenvectors of AA'.
//!#     - S is an [n x p] diagonal matrix. The non-negative singular values of A (found on the diagonal entries of S) are
//!#       the square roots of the non-negative eigenvalues of both AA' and A'A.
//!#     - V is an [p x p] orthogonal matrix. The right-singular vectors of A are a set of orthonormal eigenvectors of A'A.
//!#     - p=min(m, n) and in this particular case we have n=3 hence p=3.
	int i;
	long double w;

//!# Step 1: Forming A'*A storing temporarily result into U.
	mc_mulatbmxnl(m, 3, 3,u, a, a);

//!# Step 2: Computing V of A'*A i.e right-singular vectors.
	if (0 == mc_eigsy3x3l(u, s, v)) {
		mc_eye3x3l(s);
		mc_mulabmxnl(m, 3, 3, u, a, v);
//!# Step 3: Computing singular-values and U such as U=A*V*S^-1.
		if (0 == mc_mgsmxnl(m, 3, u, u, s)) {
//!# Step 4: Decimeting off-diagonal residual elements.
			s[1] = 0.0L; s[2] = 0.0L;
			s[3] = 0.0L; s[5] = 0.0L;
			s[6] = 0.0L; s[7] = 0.0L;
//!# Step 5: Changing sign if required.
			if (mc_copysignl(1.0L, s[0]) < 0.0L) {
				s[0] = -s[0];
				v[0] = -v[0];
				v[3] = -v[3];
				v[6] = -v[6];
			}
			if (mc_copysignl(1.0L, s[4]) < 0.0L) {
				s[4] = -s[4];
				v[1] = -v[1];
				v[4] = -v[4];
				v[7] = -v[7];
			}
			if (mc_copysignl(1.0L, s[8]) < 0.0L) {
				s[8] = -s[8];
				v[2] = -v[2];
				v[5] = -v[5];
				v[8] = -v[8];
			}
//!# Step 6: Reordering singular-values and basis (descending i.e largest first).
			if (s[0] < s[4]) {
				mcswap_var(w, s[0], s[4]);

				mcswap_var(w, v[0], v[1]);
				mcswap_var(w, v[3], v[4]);
				mcswap_var(w, v[6], v[7]);

				for (i = 0; i < m; i++) {
					mcswap_var(w, u[(3 * i)], u[(3 * i) + 1]);
				}
			}
			if (s[0] < s[8]) {
				mcswap_var(w, s[0], s[8]);

				mcswap_var(w, v[0], v[2]);
				mcswap_var(w, v[3], v[5]);
				mcswap_var(w, v[6], v[8]);

				for (i = 0; i < m; i++) {
					mcswap_var(w, u[(3 * i)], u[(3 * i) + 2]);
				}
			}
			if (s[4] < s[8]) {
				mcswap_var(w, s[4], s[8]);

				mcswap_var(w, v[1], v[2]);
				mcswap_var(w, v[4], v[5]);
				mcswap_var(w, v[7], v[8]);

				for (i = 0; i < m; i++) {
					mcswap_var(w, u[(3 * i) + 1], u[(3 * i) + 2]);
				}
			}
			return 0;
		}
	}
	return -1;
}

#endif /* !MC_SVDMX3_H */

/* EOF */