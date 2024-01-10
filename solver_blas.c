/*
 * ASC
 * 2020 Spring
 */
#include "utils.h"
#include <cblas.h>

/* 
 * Add your BLAS implementation here
 */
double* my_solver(int N, double *A, double *B) {
	printf("BLAS SOLVER\n");
	
	int i;
	
	double* C = calloc(N * N, sizeof(double));
	double* ASQ = calloc(N * N, sizeof(double));
	double* ASQB = calloc(N * N, sizeof(double));

	for (i = 0; i < N * N; ++i) {
		C[i] = 0;
		ASQ[i] = 0;
		ASQB[i] = 0; 
	}
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasTrans, 
                N, N, N, 1, B, N, A, N, 0, C, N);
	
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 
                N, N, N, 1, A, N, A, N, 0, ASQ, N);

	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 
                N, N, N, 1, ASQ, N, B, N, 0, ASQB, N);

	for (i = 0; i < N * N; ++i) {
		C[i] += ASQB[i];
	}

	return C;
}
