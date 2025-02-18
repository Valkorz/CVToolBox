#ifndef MLP_H
#define MLP_H
#include <stdio.h>
#include <stdlib.h>
#include "neural.h"

typedef struct MultilayerPerceptron{
    int out_num;
    int in_num;
    int n_count;
    int layer_count;
    double* features;
    LossFunction loss_function;
    Neuron** neurons;

}MultilayerPerceptron;

MultilayerPerceptron* mlp_init(int out_num, int in_num, int layer_count, Loss loss_fn);
void mlp_train(MultilayerPerceptron* mlp, int epochs);
double mlp_predict(MultilayerPerceptron* mlp, double* features, int num_inputs);
void mlp_free(MultilayerPerceptron* mlp);

#endif