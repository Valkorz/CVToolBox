#ifndef COLLECTIONS_H
#define COLLECTIONS_H

#include <stdio.h>

int computeSum(int* sample, int* weights, int size){
    int sum = 0;

    for(int i = 0; i < size; i++, sample++, weights++){
        sum += (*sample) * (*weights);
    }

    return sum;
}

int getLengthInt(int* arr){
    return *(&arr + 1) - arr;
}

int getLengthInt2D(int* arr){

}

#endif