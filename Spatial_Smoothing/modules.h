#ifndef MODULES_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define MODULES_H

#define K_SIZE 5
#define M_SIZE 2

typedef struct my_complex_st{
	double real = 0 ;
	double imag = 0;
}complex;

void unitary_matrix(complex *Q_H, unsigned int size); // Delete Me!
void hermitian_unitary_matrix(complex *Q_H, unsigned int size);
void mult_complex(complex &c, complex a, complex b, bool cum);
void mult_matrix(complex *Ans, complex *M1, complex *M2, unsigned int size_row, unsigned size_middle, unsigned int size_col);
void real_matrix(double *Ans, complex *M, unsigned int size_row, unsigned int size_col);
void hermitian(complex *m_H, complex *m, unsigned int size_row, unsigned size_col); //Useless
void spatial_smoothing(complex *y, complex *x, complex *Q_H, unsigned int K, unsigned M);
void corr(complex *R_xx, complex *x, unsigned int size_row, unsigned size_col);


// Main Blocks
void Correlation_Matrix_Section (double *Ryy, complex *x);

#endif