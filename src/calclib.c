#include "calclib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//gets the nth prime number using the C. P. Williams formula (1964). Gotta fix this crap, ain't working
float prime(int n){
    float res = 1;
    for(int i = 1; i <= pow(2, n); i++){
        float res_2 = 1;
        for(int j = 1; j <= i; j++){
            printf("\n res2: %.4f", res_2);
            res_2 += pow(cos(((factorial(j - 1) + 1) / (float)j) * PI), 2);
        }
        res_2 = n / res_2;
        res_2 = pow(res_2, 1.0 / n);
        printf("\n res2: %.4f", res_2);
        res += res_2;
        printf("\n res 1: %d", res);
    }

    return res;
}

//Gets the factorial equivalent of a natural number
int factorial(int x){
    int res = 1;
    for(int i = 1; i <= x; i++){
        res *= i;
    }
    return res;
}
