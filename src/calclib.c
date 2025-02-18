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
