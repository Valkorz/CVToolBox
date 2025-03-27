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
    // printf("| l | a | b | m | f(a) | f(b) | f(m) | f(a)*f(m) | f(m)*f(b) | b-a < e | |f(m)| < e |");
    double k ,k_max = (log(abs(interval_b - interval_a)) - log(precision)) / log(2);
    double m = (interval_a + interval_b) / 2;
    double a = interval_a, b = interval_b, left = 0.0, right = 0.0;

    for(k = 0.0; k <= k_max; k += precision){
        left = function(a) * function(m);
        right = function(b) * function(m);
        // printf("\n| %d | %.5f | %.5f | %.5f | %.5f | %.5f | %.5f | %.5f | %.5f | %s | %s |", i, a, b, m, function(a), function(b), function(m), function(a)*function(m), function(b)*function(m), (left < 0)? "-" : "+", (right < 0)? "-" : "+");

        if(left < 0){
            b = m;
        } else if(right < 0){
            a = m;
        } else break;

        m = (a + b) / 2;
    }

    return m;
}

/// @brief Represents the interpolated polynomial equation for a set of x and f(x) values stored as context.
/// @param x the x value
/// @param ctx the function context as LagrangeParams
/// @return The corresponding y or f(x) value.
double lagrange_eval(double x, void *ctx){
    LagrangeParams *params = (LagrangeParams*)ctx;
    double result = 0;

    for(int i = 0; i < params->count; i++){
        double term = *(params->y_points + i); 
        for(int j = 0; j < params->count; j++){
            if(i != j){
                term *= (x - *(params->x_points + j)) / (*(params->x_points + i) - *(params->x_points + j));
            }
        }
        result += term;
    }

    return result;
}

/// @brief Stores the interpolation data in a struct
/// @param x_points the relevant x points to be used in interpolation
/// @param y_points the relevant y points (or f(x)) to be used in interpolation
/// @param count the number of x points
/// @return Returns the params struct.
LagrangeParams *create_lagrange_interpolator(double *x_points, double *y_points, int count){
    LagrangeParams *params = malloc(sizeof(LagrangeParams));
    if(!params) return NULL;

    params->x_points = malloc(sizeof(double) * count);
    params->y_points = malloc(sizeof(double) * count);
    if(!params->x_points || !params->y_points){
        free(params->x_points);
        free(params->y_points);
        free(params);
        return NULL;
    }
    
}

/// @brief Creates a 'function with context' struct that stores the lagrange interpolation data and the evaluator function
/// @param x_points The X points
/// @param y_points The Y or f(X) points
/// @param count the count of Y points 
/// @return the instantiated struct.
FunctionWithCtx* createFunctionWithCtx(double *x_points, double *y_points, int count){
    FunctionWithCtx* fwc = (FunctionWithCtx*)malloc(sizeof(FunctionWithCtx));
    fwc->ctx = create_lagrange_interpolator(x_points, y_points, count);
    fwc->f = lagrange_eval;
    return fwc;
}

void free_FnWithCtx(FunctionWithCtx* fctx){
    free(fctx->ctx);
    free(fctx);
}
