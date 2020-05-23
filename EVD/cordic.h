#ifndef CORDIC_H
#define CORDIC_H

void cordic_arctangent(double x, double y, double &res);
void cordic_rotation(double x, double y, double theta, double &x_out, double &y_out);

#endif 