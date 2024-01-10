/*
 * ASC
 * 2020 Spring
 */
#include "utils.h"

/*
 * Add your optimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	printf("OPT SOLVER\n");

	int block_size = N / 8;
	int i, j, k, bi, bj, bk;

	double* C = calloc(N * N, sizeof(double));
	double* ASQ = calloc(N * N, sizeof(double));

	double *pA, *pA1, *pB, *pASQ;

	for (bi = 0; bi < N; bi += block_size) {
		for (bj = 0; bj < N; bj += block_size) {
			for (bk = 0; bk < N; bk += block_size) {
				for (i = 0; i < block_size; ++i) {
					for (j = 0; j < block_size; ++j) {
						pA = &A[(bj + j) * N + bk];
						pB = &B[(bi + i) * N + bk];
						for (k = 0; k < block_size; ++k) {
							C[(bi + i) * N + (bj + j)] += *pA * *pB;
							pA++;
							pB++;
						}
					}
				}
			}
		}
	}

	for (bi = 0; bi < N; bi += block_size) {
		for (bj = 0; bj < N; bj += block_size) {
			for (bk = 0; bk < N; bk += block_size) {
				for (i = 0; i < block_size; ++i) {
					for (j = 0; j < block_size; ++j) {
						pA = &A[(bi + i) * N + bk];
						pA1 = &A[bk * N + (bj + j)];
						for (k = 0; k < block_size; ++k) {
							ASQ[(bi + i) * N + (bj + j)] += *pA * *pA1;
							pA++;
							pA1 += N;
						}
					}
				}
			}
		}
		for (bj = 0; bj < N; bj += block_size) {
			for (bk = 0; bk < N; bk += block_size) {
				for (i = 0; i < block_size; ++i) {
					for (j = 0; j < block_size; ++j) {
						pASQ = &ASQ[(bi + i) * N + bk];
						pB = &B[bk * N + (bj + j)];
						for (k = 0; k < block_size; ++k) {
							C[(bi + i) * N + (bj + j)] += ASQ[(bi + i) * N + (bk + k)] * B[(bk + k) * N + (bj + j)];
							pASQ++;
							pB += N;
						}
					}
				}
			}
		}
	}

	free(ASQ);

	return C;	
}
