#ifndef TYPEMATCH_H
#define TYPEMATCH_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int stringToInt(char* str, int len){
    int i;
    float res = 0.0;
    for(i = 0; i < len; i++){
        res += (*(str + len - i - 1) - '0') * (pow(10,i));
    }
    return (int)res;
}

#endif