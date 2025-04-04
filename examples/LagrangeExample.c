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
    double x_points[] = {0.5, 2, 4};
    double y_points[] = {5, 13, 7};
    double x = 3;
    int count = 3;
    FunctionWithCtx *fn = createFunctionWithCtx((double*)x_points, (double*)y_points, count);
    double res = fn->f(x, fn->ctx);

    printf(" Interpolated result for %.4f = %.4f", x, res);

    system("pause");

}