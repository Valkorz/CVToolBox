#ifndef PERCEPTRON_H
#define PERCEPTRON_H
#define SAMPLE_SIZE 3
#include "collections.h"
#include <stdio.h>

//Todo: finish adapting C# code

typedef struct{
    double w[3];
    int learnArray[4][3];
    double _net;

} perceptron;

void initialize(perceptron* percep)
{
    //AND table 
    percep->learnArray[0][0] = 0;
    percep->learnArray[0][1] = 0;
    percep->learnArray[0][2] = 0;

    percep->learnArray[1][0] = 0;
    percep->learnArray[1][1] = 1;
    percep->learnArray[1][2] = 0;

    percep->learnArray[2][0] = 1;
    percep->learnArray[2][1] = 0;
    percep->learnArray[2][2] = 0;

    percep->learnArray[3][0] = 1;
    percep->learnArray[3][1] = 1;
    percep->learnArray[3][2] = 1;

    percep->w[0] = 0;
    percep->w[1] = 0;
    percep->w[2] = 0;
}

void classifySample(int* sample){

    // weights found post training
    int weights[] = {2,1,3};

    // linearly split data post tranining
    double u = (double)computeSum(sample, weights, SAMPLE_SIZE);

    int y = activationTreshold(u);

    printf((y > 0) ? "Class A Sample >= 0" : "HelloWorld < 0");
}

int activationTreshold(double u){
    return (u >= 0) ? 1.0 : 0.0;
}

int execute(perceptron* percep, int x1, int x2){
    percep->_net = 
        (x1 * percep->w[0]) + 
        (x2 * percep->w[1]) + 
        ((-1) * percep->w[2]);

    return (percep->_net >= 0) ? 1 : 0;
}

// void Train(perceptron* percep){
//     int trained = true;
//     int len = 
//         (sizeof(percep->learnArray) / sizeof(*(percep->learnArray)) *
            
//     // for(int i = 0; i < percep.)
// }

#endif