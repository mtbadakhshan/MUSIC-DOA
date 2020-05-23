#include "dev_tools.h"


using namespace std;


void PrintRow(complex *data, unsigned int row, unsigned int col_size, const char *description){
	if (description[0] != '\0'){
		cout << description << endl;
	}
	for(int j=0; j < col_size; j++){
		if (data[col_size*row + j].imag >= 0)
			cout << data[col_size*row + j].real << "+" <<  data[col_size*row + j].imag << "i, ";
		else
			cout << data[col_size*row + j].real <<  data[col_size*row + j].imag << "i, ";
	}
	cout << endl;
}

void PrintRow(double *data, unsigned int row, unsigned int col_size, const char *description){
	if (description[0] != '\0'){
		cout << description << endl;
	}
	for(int j=0; j < col_size; j++){
		cout << data[col_size*row + j] << ", ";
	}
	cout << endl;
}

void PrintMat(double *data, unsigned int row_size, unsigned int col_size, const char *description){
	cout << description << endl;
	for(int i = 0; i < row_size; i++){
		PrintRow(data, i, col_size, "");
	}
}

void PrintMat(complex *data, unsigned int row_size, unsigned int col_size, const char *description){
	cout << description << endl;
	for(int i = 0; i < row_size; i++){
		PrintRow(data, i, col_size, "");
	}
}

void GetCol(complex *col, complex *data, unsigned int col_num, unsigned int row_size, unsigned int col_size){
	for(int i=0; i< row_size; i++){
		col[i] = data[i*col_size + col_num];
	}
}

void ReadMat(string filename, complex *data, unsigned int rows, unsigned int cols ){

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
			double real=0, im=0;
			char plusorminus = '\0', ichar = '\0';
			SS_Value>>real>>plusorminus>>im>>ichar;
			switch (plusorminus){
				case	'-': im=-im; break;
				case	'i': im=real; real=0; break;
				case	'\0': im=0; break;
			}
	        data[y*cols + x].real = real;
	        data[y*cols + x].imag = im;
	        x++;
	    //cout << F_Value << endl;
		}
	    y++;
	}
	IS_File.close();
}
