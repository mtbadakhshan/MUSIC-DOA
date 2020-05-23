#include "dev_tools.h"

using namespace std;

void PrintMat(double data[][N], unsigned int row_size, unsigned int col_size, const char *description){
	cout << description << endl;
	for(int i = 0; i < row_size; i++){
		for (int j=0; j<col_size; j++){
			cout<<data[i][j]<<',';
		}
		cout<<endl;
	}
}


void ReadMat(string filename, double *data, unsigned int rows, unsigned int cols ){

	ifstream        IS_File;
	string          ST_Line;
	stringstream    SS_Line;
	stringstream    SS_Value;
	unsigned int    y           = 0;
	unsigned int    x           = 0;
	string F_Value;

	//
	IS_File.open(filename);
	while(getline(IS_File, ST_Line))
	{
	    SS_Line.clear();
	    SS_Line << ST_Line;
	    x = 0;


		while(getline(SS_Line, F_Value, ',')) {
			// cout << F_Value << '\n';
			SS_Value.clear();
	    	SS_Value << F_Value;
			double num=0;
			SS_Value>>num;

	        data[y*cols + x] = num;
	        x++;
	    //cout << F_Value << endl;
		}
	    y++;
	}
	IS_File.close();
}
