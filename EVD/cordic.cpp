#include "cordic.h"
#include <cmath>

void cordic_arctangent(double x, double y, double &res){
	res = atan(x/y);
}

void cordic_rotation(double x, double y, double theta, double &x_out, double &y_out){
	x_out = x*cos(theta) - y*sin(theta);
	y_out = x*sin(theta) + y*cos(theta);
}