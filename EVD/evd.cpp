#include "evd.h"
#include "cordic.h"
#include <iostream>

#define THRESHOLD 5

using namespace std;

void evd(double R[][N], double E[][N], bool* indexes, int size){
	double theta;

	// //Load I Matrix to E
	for(int i=0; i<size; i++)
		for (int j=0; j<size; j++)
			E[i][j] = (i==j);

	// Calculate EVD
	for (int k=0; k<Num_Of_Sweep; k++){
		for(int i=0; i<size-1; i++){
			for(int j=i+1; j<size; j++){
				cordic_arctangent(2*R[i][j], R[j][j]-R[i][i], theta);
				theta /= 2;
				for(int m=0; m<size; m++){
					cordic_rotation(R[i][m], R[j][m], theta, R[i][m], R[j][m]);
					if (m!=i && m!=j){
						R[m][i] = R[i][m];
						R[m][j] = R[j][m];
					}
					cordic_rotation(E[m][i], E[m][j], theta, E[m][i], E[m][j]);
				}
				cordic_rotation(R[i][i], R[i][j], theta, R[i][i], R[i][j]);
				cordic_rotation(R[j][i], R[j][j], theta, R[j][i], R[j][j]);
			}
		}
	}

	//Sorting
	for(int i=0; i<size; i++){
		indexes[i] = R[i][i] < THRESHOLD;
	}	

}