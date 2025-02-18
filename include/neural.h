#ifndef NEURAL_H
#define NEURAL_H
#define DEFAULT_LEARNING_RATE 0.5
#include "calclib.h"

typedef double (*ActivationFunction)(double sum);
typedef double (*LossFunction)(double* out, double* label);

//The function that determines neuron output
typedef enum Activation{
    RELU,
    LOGISTIC_SIGMOID,
    HYPERBOLIC_TANGENT,
    ARCTANGENT,
    GUDERMANNIAN,
    ERROR,
}Activation;

//The function that generates output loss for backpropagation
typedef enum Loss{
    QUADRATIC,
    LOG,
    HINGE,
    REGRESSION,
    MEAN_ERROR,
    HUBER,
    LOG_COSH,
    QUANTILE
}Loss;

typedef struct Neuron{
    double bias;
    double learning_rate;
    double *weights;
    int num_inputs;
    int layer;
    ActivationFunction activation_function;
}Neuron;

Neuron* neuron_init(double _b, double _lr, int num_inputs, Activation act_fn);
ActivationFunction neuron_getActivation(Activation act_fn);
LossFunction neuron_getLoss(Loss loss);
double predict(Neuron* n, double* inputs);
void neuron_free(Neuron* n);

#endif