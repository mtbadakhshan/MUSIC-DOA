#include<iostream>
#include<stdio.h>
#include <bitset>
#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include<cmath>
#include "modules.h"
#include "dev_tools.h"
using namespace std;

// #define K 5
// #define N 10
// #define M 2



 main(){

 	/* Handling Input -------------------------- */
 	// Buffering the input
 	complex X_mat[K_SIZE*N_SIZE];
 	ReadMat("input.txt", X_mat, K_SIZE, N_SIZE);
 	// Capture One Snapshot 
 	complex x[K_SIZE];
 	GetCol(x, X_mat, 0, K_SIZE, N_SIZE);
 	PrintMat(x, K_SIZE, 1, "x-Snapshot");
 	/*End of Handling Input -------------------------- */

 	/* Handling Output -------------------------- */
 	double Ryy[(K_SIZE-M_SIZE+1)*(K_SIZE-M_SIZE+1)];
 	/*End of Handling Output -------------------------- */

 	/* Module Under Test -------------------------- */
	Correlation_Matrix_Section (Ryy, x);
	/* End of Module Under Test -------------------------- */

	PrintMat(Ryy, (K_SIZE-M_SIZE+1), (K_SIZE-M_SIZE+1), "Ryy");

}