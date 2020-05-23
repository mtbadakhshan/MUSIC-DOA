#ifndef DEV_TOOLS_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define DEV_TOOLS_H

#include <string.h>
// #include <iostream>
// #include <stdio.h>
// #include <bitset>
#include <iostream>
#include <fstream>
// #include <iostream>
#include <sstream>
// #include <stdint.h>
// #include <math.h>
// #include<cmath>
#include "evd.h"

using namespace std;


void PrintMat(double data[][N], unsigned int row_size, unsigned int col_size, const char *description);
void ReadMat(string filename, double *data, unsigned int rows, unsigned int cols );




#endif