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
    double interval_a = 0.0;
    double interval_b = 2.0;
    double precision = 0.05;
    fn function = f;

    printf("Finding square root....");
    printf("\n root = %.8f", dicotomy_temp(function, interval_a, interval_b, precision));

    system("pause");
    return EXIT_SUCCESS;
}