#include <stdio.h>
#include <stdlib.h>
#include "perceptron.h"
#define RAND_MAX 100

/// @brief Initializes the perceptron with specified properties.
/// @param num_inputs represent the number of features to be analyzed 
/// @param learning_rate represents the speed in which the weight is adjusted for error correction.
/// @return returns a Perceptron with allocated values and random weights.
Perceptron* percep_init(int num_inputs, double learning_rate){
    Perceptron *p = (Perceptron*)malloc(sizeof(Perceptron));
    p->num_inputs = num_inputs;
    p->learning_rate = learning_rate;
    p->weights = (double*)malloc(num_inputs * sizeof(double)); // each feature has a specified weight
    p->bias = 0.0; // no initial bias.

    int i;
    for(i = 0; i < num_inputs; i++){
        //Assign random values to each feature weight
        *(p->weights + i) = ((double)rand() / RAND_MAX) - 0.5;
    }

    return p;
}

/// @brief Determines the output of the Perceptron.
/// @param sum the sum of the bias + all features multiplied by all weighs.
/// @return Returns TRUE if the sum is greater or equal to zero, otherwise returns FALSE.
int activate(double sum){
    return sum >= 0? 1 : 0;
}

/// @brief Predict output for a given input
/// @param p the perceptron struct
/// @param inputs the features
/// @return the activated value for the sum of inputs multiplied by weights.
int percep_predict(Perceptron *p, double *inputs){
    double sum = p->bias;
    int i;
    for(i = 0; i < p->num_inputs; i++){
        sum += *(p->weights + i) * (*(inputs + i));
        // printf("\n Adding to sum: %f", *(p->weights + i) * (*(inputs + i)));
    }

    // printf("\n the sum of inputs is %f. bias: %f", sum, p->bias);

    return activate(sum);
}

/// @brief Trains the perceptron.
/// Will use the training data to loop and train the perceptron.
/// The perceptron will guess the correct answer and correct itself based on the
/// real answer (provided by labels).
/// @param p the perceptron struct
/// @param training_inputs the training data
/// @param labels the training data state (true or false)
/// @param num_samples length of training data entries
/// @param epochs number of training loops
void percep_train(Perceptron* p, double **training_inputs, int *labels, int num_samples, int epochs){
    int epoch, i;
    for(epoch = 0; epoch < epochs; epoch++){
        for(i = 0; i < num_samples; i++){
            //Will predict for each entry in the data list
            int prediction = percep_predict(p, *(training_inputs + i));
            int error = *(labels + i) - prediction;

            //Update weight and bias based on learning rate and error
            for(int j = 0; j < p->num_inputs; j++){
                *(p->weights + j) += p->learning_rate * error * (*(*(training_inputs + i) + j));
            }
            p->bias += p->learning_rate * error;
            //printf("\n Updated bias on training: %f. Error? %d, math? %f", p->bias, error, p->learning_rate * error);
            //The model will correct itself based on how far it 'missed' from the real answer
            //the correction rate is measured by the 'learning_rate' constant.
        }
    }
}

// Frees all the data tied to the perceptron.
void percep_free(Perceptron* p){
    free(p->weights);
    free(p);
}
