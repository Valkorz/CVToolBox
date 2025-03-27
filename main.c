#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "calclib.h"
#include <math.h>

double f(double x){
    return pow(EULER, x) + x - 3;
}

int main()
{
    double x_points[] = {0.25, 0.55, 0.78};
    double y_points[] = {7.1338, 9.1662, 11.5545};
    double x = 0.25;
    int count = 3;
    FunctionWithCtx *fn = createFunctionWithCtx((double*)x_points, (double*)y_points, count);
    double res = fn->f(x, fn->ctx);

    printf(" Interpolated result for %.4f = %.4f", x, res);

    system("pause");

}