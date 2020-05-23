#include "evd.h"
#include "dev_tools.h"
#include "cordic.h"

main(){
	
	double R[N][N];
	double E[N][N];
	bool indexes[N];
	ReadMat("input.txt", *R, N, N );
	PrintMat(R, N, N, "Ryy");

	evd(R, E, indexes, N);

	PrintMat(R, N, N, "Ryy");

	PrintMat(E, N, N, "E");

	cout << "Indexes" << endl;
	for(int i=0; i<N; i++){
		cout << indexes[i] << ", ";
	}
	cout <<endl;
	
}