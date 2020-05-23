#include <iostream>
#include "modules.h"

#include "dev_tools.h" // Delete after development phase

#define inv_Sqrt_2 1

using namespace std;

void unitary_matrix(complex *Q_H, unsigned int size){
	for (int i=0; i<size; i++){
		for (int j = 0; j<size; j++){
			if (i < size/2 && j < size/2){
				Q_H[i*size + j].real = (i==j) ? inv_Sqrt_2 : 0;
				Q_H[i*size + j].imag = 0;
			} 
			else if (i < size/2 && j >= size/2){
				Q_H[i*size + j].real = 0;
				Q_H[i*size + j].imag = (i+size/2 + (size%2) == j) ? inv_Sqrt_2 : 0;
			}
			else if (i >= size/2 && j < size/2){
				Q_H[i*size + j].real = (size-i-1 == j) ? inv_Sqrt_2 : 0;
				Q_H[i*size + j].imag = 0;
			}
			else if (i >= size/2 && j >= size/2){
				Q_H[i*size + j].real = 0;
				Q_H[i*size + j].imag = (-1 * ((3*size/2)-i-1+ (size%2) == j)) ? inv_Sqrt_2 : 0;
			} 
		}
	}
	if (size%2)
		Q_H[(size/2) * (1+size)].real = 1;
}

void hermitian_unitary_matrix(complex *Q_H, unsigned int size){
	for (int i=0; i<size; i++){
		for (int j = 0; j<size; j++){
			if (i < size/2 && j < size/2){
				Q_H[i*size + j].real = (i==j) ? inv_Sqrt_2 : 0;
				Q_H[i*size + j].imag = 0;
			} 
			else if (i < size/2 && j >= size/2){
				Q_H[i*size + j].real = (size - i - 1 == j) ? inv_Sqrt_2 : 0;
				Q_H[i*size + j].imag = 0;
			}
			else if (i >= size/2 && j < size/2){
				Q_H[i*size + j].real = 0;
				Q_H[i*size + j].imag = (i-size/2 - (size%2) == j) ? -1 * inv_Sqrt_2 : 0;
			}
			else if (i >= size/2 && j >= size/2){
				Q_H[i*size + j].real = 0;
				Q_H[i*size + j].imag = ((3*size/2)-i-1+ (size%2) == j) ? inv_Sqrt_2 : 0;
			} 
		}
	}
	if (size%2)
		Q_H[(size/2) * (1+size)].real = 1;
}

void mult_complex(complex &answer, complex arg1, complex arg2, bool cum){ // cum: cumulative summation

	answer.real = (cum?answer.real:0) + arg1.real * arg2.real - arg1.imag * arg2.imag;
	answer.imag = (cum?answer.imag:0) + arg1.real * arg2.imag + arg1.imag * arg2.real;
}

void mult_matrix(complex *Ans, complex *M1, complex *M2, unsigned int size_row, unsigned size_middle, unsigned int size_col){
	for (int i=0; i<size_row; i++){
		for (int j=0; j<size_col; j++){
			Ans[i*size_col + j].real = 0;
			Ans[i*size_col + j].imag = 0;
			for (int k=0; k<size_middle; k++){
				mult_complex(Ans[i*size_col + j], M1[i*size_middle+k], M2[k*size_col+j], true);

				// cout<<"(A: " << Ans[i*size_col + j].real << " + i" << Ans[i*size_col + j].imag << ", ";
				// cout<<"M1: " << M1[i*size_middle+k].real << " + i" << M1[i*size_middle+k].imag << ", ";
				// cout<<"M2: " << M2[k*size_col+j].real << " + i" << M2[k*size_col+j].imag << "), ";
			}
			// cout << endl;
		}
	}
}

void sum_matrix(double *Ans, double *M1, double *M2, unsigned int size_row, unsigned int size_col){
	for (int i=0; i<size_row; i++){
		for (int j=0; j<size_col; j++){
			Ans[i*size_col + j] = M1[i*size_col + j] + M2[i*size_col + j];
		}
	}
}

void real_matrix(double *Ans, complex *M, unsigned int size_row, unsigned int size_col){
	for (int i=0; i<size_row; i++){
		for (int j=0; j<size_col; j++){
			Ans[i*size_col + j] = M[i*size_col + j].real;
		}
	}
}

void hermitian(complex *m_H, complex *m, unsigned int size_row, unsigned size_col){ // Useless
	for (int i=0; i<size_row; i++){
		for(int j=0; j<size_col; j++){
			m_H[i*size_col + j].real = m[j*size_col + i].real;
			m_H[i*size_col + j].imag = -1 * m[j*size_col + i].imag;
		}
	}
}

void spatial_smoothing(complex *y, complex *x, complex *Q_H, unsigned int K, unsigned M){
	for(int i=0; i<M; i++){
		mult_matrix(y+i*(K-M+1), Q_H, x+i, K-M+1, K-M+1, 1);
	}
}

void corr(complex *R_xx, complex *x, unsigned int size){
	for (int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			R_xx[i*size + j].real = x[i].real * x[j].real + x[i].imag*x[j].imag;
			R_xx[i*size + j].imag = -1 * (x[i].real * x[j].real + x[i].imag*x[j].imag);
		}
	}
}

void load_num(double *A, int num, unsigned int size_row, unsigned size_col){
	for(int i=0; i<size_row*size_col; i++){
		A[i] = 0;
	}
}

// Main Blocks

void Correlation_Matrix_Section (double *Ryy, complex *x){
	// Making a Unitary Matrix
	complex Q_H[(K_SIZE-M_SIZE+1)*(K_SIZE-M_SIZE+1)];
	hermitian_unitary_matrix(Q_H, K_SIZE-M_SIZE+1);

	//Spatial Smoothing
	complex y[M_SIZE*(K_SIZE-M_SIZE+1)];
	spatial_smoothing(y, x, Q_H, K_SIZE, M_SIZE);
	PrintMat(y, M_SIZE*(K_SIZE-M_SIZE+1), 1, "Y:");

	//Temporary Matrixes
	complex Ryy_complex[(K_SIZE-M_SIZE+1)*(K_SIZE-M_SIZE+1)];
	double Ryy_temp[(K_SIZE-M_SIZE+1)*(K_SIZE-M_SIZE+1)];

	load_num(Ryy, 0, (K_SIZE-M_SIZE+1), (K_SIZE-M_SIZE+1));
	for (int i=0; i<M_SIZE; i++){
		corr(Ryy_complex, y+i*(K_SIZE-M_SIZE+1), (K_SIZE-M_SIZE+1));
		PrintMat(Ryy_complex, (K_SIZE-M_SIZE+1), (K_SIZE-M_SIZE+1), "Ryy_complex");
		real_matrix(Ryy_temp, Ryy_complex, (K_SIZE-M_SIZE+1), (K_SIZE-M_SIZE+1));
		sum_matrix(Ryy, Ryy, Ryy_temp, (K_SIZE-M_SIZE+1), (K_SIZE-M_SIZE+1));
	}
}
