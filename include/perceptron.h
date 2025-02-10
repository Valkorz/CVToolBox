#ifndef PERCEPTRON_H
#define PERCEPTRON_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Perceptron structure
//Contains the following properties:
//
// - Weights: represents the strength in connections between
// the neurons of an artificial intelligence model (random numbers);
//
// - Bias: represents the likelyhood of the model to prefer certain
// outputs due to bias, favoring certain groups or individuals positively
// or negatively;
//
// - Number of Inputs: represents the number of features, which are the
// characteristics the model will observe for each individual piece of data;
//
// - Learning Rate: represents the amount in wich the AI model adjusts its
// parameters in each step of its optimisation algorithm.
//
// The model starts with default weights and optimises itself during the training
// process.
typedef struct Perceptron{
    double *weights;
    double bias;
    int num_inputs;
    double learning_rate;
}Perceptron;

Perceptron* percep_init(int num_inputs, double learning_rate);
Perceptron* percep_load(char* fname);
int activate(double sum);
int percep_predict(Perceptron *p, double* inputs);
void percep_train(Perceptron *p, double **training_inputs, int *labels, int num_samples, int epochs);
void percep_free(Perceptron* p);
int percep_save(Perceptron* p, char* fname);


#endif