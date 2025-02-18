#include <stdio.h>
#include <stdlib.h>
#include "neural.h"
#include "calclib.h"

ActivationFunction neuron_getActivation(Activation act_fn){
    switch(act_fn){
        case RELU:
            return relu;
        case LOGISTIC_SIGMOID:
            return logCurve;
        default: return relu;
    }
}