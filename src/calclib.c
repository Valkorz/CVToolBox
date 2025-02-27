#include "calclib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/// @brief Gets the factorial of a given number
/// @param x The target number
int factorial(int x){
    int res = 1;
    for(int i = 1; i <= x; i++){
        res *= i;
    }
    return res;
}

/// @brief Calculates an estimate for the function root on an interval (if exists)
/// @param interval_a the upper limit of the interval
/// @param interval_b the lower limit of the interval
/// @param precision the precision
/// @return Returns the X value representing the root (where Y = 0)
double dicotomy(fn function, double interval_a, double interval_b, double precision)
{
    double k ,k_max = (log(abs(interval_b - interval_a)) - log(precision)) / log(2);
    double m = (interval_a + interval_b) / 2;
    double a = interval_a, b = interval_b, left = 0.0, right = 0.0;

    for(k = 0.0; k <= k_max; k += precision){
        printf("Current k: %.2f, max k: %.2f, m: %.6f, a: %.6f, b: %.6f", k, k_max, m, a, b);
        left = function(a) * function(m);
        right = function(b) * function(m);
        printf("\n  Left: %.2f, right: %.2f", left, right);


        if(left < 0){
            b = m;
        } else if(right < 0){
            a = m;
        } else break;

        m = (a + b) / 2;
    }

    return m;
}
