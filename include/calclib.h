#ifndef CALCLIB_H
#define CALCLIB_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926535
#define EULER 2.71828182846

typedef double (*fn)(double x);
typedef double (*fn_with_ctx)(double x, void *ctx);
typedef struct{
    double *x_points;
    double *y_points;
    int count;
}LagrangeParams;

typedef struct{
    fn_with_ctx f;
    void *ctx;
} FunctionWithCtx;

int factorial(int x);
double relu(double in);
double logCurve(double in);
double dicotomy(fn function, double interval_a, double interval_b, double precision);
double lagrange_eval(double x, void *ctx);
LagrangeParams* create_lagrange_interpolator(double *x_points,double *y_points, int count);
FunctionWithCtx* createFunctionWithCtx(double *x_points, double *y_points, int count);
void free_FnWithCtx(FunctionWithCtx* fctx);

#endif