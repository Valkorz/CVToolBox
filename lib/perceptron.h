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

//Initializes the perceptron with specified properties.
Perceptron* percep_init(int num_inputs, double learning_rate){
    Perceptron *p = (Perceptron*)malloc(sizeof(Perceptron));
    p->num_inputs = num_inputs;
    p->learning_rate = learning_rate;
    p->weights = (double*)malloc(num_inputs * sizeof(double)); //each feature has a specified weight
    p->bias = 0.0; //No initial bias

    int i;
    for(i = 0; i < num_inputs; i++){
        //Assign random values to each feature weight
        *(p->weights + i) = ((double)rand() / RAND_MAX) - 0.5;
    }

    return p;
}

//Step function that returns 1 if input is greater or equal to 0,
//otherwise it returns 0. Used to determine the output of the Perceptron.
int activate(double sum){
    return sum >= 0? 1 : 0;
}

//Predict output for a given input.
//Calculates the weightened sum of the inputs plus the bias. The result
//is applied to the activation function which then produces a binary (true/false)
//output.
int predict(Perceptron *p, double *inputs){
    double sum = p->bias;
    int i;
    for (i = 0; i < p->num_inputs; i++){
        sum += *(p->weights + i) * (*(inputs + i));
    }
    return activate(sum);
}

//Trains the perceptron by adjusting weight and bias for each training input.
//the function takes in training inputs (these being the sum of each feature),
//labels who tell the model which data is positive (1) or negative (0), the
//number of samples to be used in training and the epochs (number of times the AI
//will process the data).
void train(Perceptron *p, double **training_inputs, int *labels, int num_samples, int epochs) {
    int epoch, i;
    for(epoch = 0; epoch < epochs; epoch++){
        for(i = 0; i < num_samples; i++){
            int prediction = predict(p, *(training_inputs + i));
            int error = *(labels + i) - prediction;

            //Update weights and bias
            for(int j = 0; j < p->num_inputs; j++){
                *(p->weights + j) += p->learning_rate * error * (*(*(training_inputs + i)) + j);
            }
            p->bias += p->learning_rate * error;

            //The model will correct itself based on how far it 'missed' from the real answer
            //the correction rate is measured by the 'learning_rate' constant.
        }
    }
}

void percep_free(Perceptron *p){
    free(p->weights);
    free(p);
}

#endif