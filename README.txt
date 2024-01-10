===============================
Optimizing Matrix Multiplication
===============================

 The project revolves around implementing, optimizing, and
comparing matrix multiplication algorithms. The provided files
together form a comprehensive project for studying and applying
concepts related to computer architecture and optimization.

compare.c: This file contains a program that compares two upper
matrices stored in binary files with a specified tolerance.
The matrices are compared element-wise, and if the difference
exceeds the given precision, an error is reported.

main.c: This file is the main program that reads input data from a
file generates test data, runs a solver function on the data, measures
the execution time, and prints the results. It also includes the
implementation of the read_input_file, write_cmat_file, generate_data,
and run_test functions.

Makefile: This file defines the compilation rules for generating
executable files (compare and various versions of tema2_*) from
corresponding source files. Different optimization levels are applied
to the compilation.

solver_blas.c, solver_neopt.c, solver_opt.c: These files contain different
implementations of a matrix multiplication solver (my_solver). solver_blas.c
uses the BLAS library for matrix multiplication. solver_neopt.c contains a
straightforward, unoptimized implementation. solver_opt.c includes an optimized
implementation using blocked matrix multiplication.

utils.h: This header file includes function declarations and necessary includes
for the project. It also defines a struct (struct test) for storing input data
for the tests.

The chart was made for tests where N = 1200

Neoptimal:
    Simple implementation of multiplication of two matrices and addition.
Optimal:
    For the optimal solution, I used blocked matrix multiplication as an optimization for cache.
I also took pointers to iterate through my matrix.
Blas:
    I used the cblas_dgemm function to multiply the matrices. In addition, I did it manually.
Optimal_f:
    I used two flags: 
    -ffast-math : This option causes the preprocessor macro __FAST_MATH__ to be defined.
        It may, however, yield faster code for programs that do not require the guarantees
        of these specifications. 
    -floop-unroll-and-jam: Apply unroll and jam transformations on feasible loops.
        In a loop nest, this unrolls the outer loop by some factor and fuses the resulting
        multiple inner loops.
		
