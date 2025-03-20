#ifndef CALCLIB_H
#define CALCLIB_H
#include <math.h>
#include <stdio.h>
#define PI 3.1415926535
#define EULER 2.71828182846

typedef double (*fn)(double x);

int factorial(int x);
double relu(double in);
double logCurve(double in);
double dicotomy(fn function, double interval_a, double interval_b, double precision);
double dicotomy_temp(fn function, double interval_a, double interval_b, double precision); //remove later

#endif