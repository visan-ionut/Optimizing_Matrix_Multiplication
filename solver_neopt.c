/*
 * ASC
 * 2020 Spring
 */
#include "utils.h"

/*
 * Add your unoptimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	printf("NEOPT SOLVER\n");
	int i, j, k;
	double* C = calloc(N * N, sizeof(double));
	double* ASQ = calloc(N * N, sizeof(double));
	
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			for (k = 0; k < N; ++k) {
				C[i * N + j] += B[i * N + k] * A[j * N + k]; 
			}
		}
	}

	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			for (k = 0; k < N; ++k) {
				ASQ[i * N + j] += A[i * N + k] * A[k * N + j];
			}
		}
		for (j = 0; j < N; ++j) {
			for (k = 0; k < N; ++k) {
				C[i * N + j] += ASQ[i * N + k] * B[k * N + j];
			}
		}
	}

	free(ASQ);

	return C;
}
