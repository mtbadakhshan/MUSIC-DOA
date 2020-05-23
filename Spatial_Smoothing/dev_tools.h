#ifndef DEV_TOOLS_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define DEV_TOOLS_H

#include "modules.h"
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <bitset>
#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdint.h>
#include <math.h>
#include<cmath>

using namespace std;

#define N_SIZE 10

void PrintRow(complex *data, unsigned int row, unsigned int col_size, const char *description);
void PrintRow(double *data, unsigned int row, unsigned int col_size, const char *description);
void PrintMat(complex *data, unsigned int row_size, unsigned int col_size, const char *description);
void PrintMat(double *data, unsigned int row_size, unsigned int col_size, const char *description);
void GetCol(complex *col, complex *data, unsigned int col_num, unsigned int row_size, unsigned int col_size);
void ReadMat(string filename, complex *data, unsigned int rows, unsigned int cols );




#endif