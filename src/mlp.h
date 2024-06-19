/* Multilayer Perceptron header file */
#include "utils.h"

typedef struct MLP_t {
    int n_layers;
    int *n_neurons;
    double **weights;
    double **biases;
    ActivationFunction *activations;
    double **z;
    double **deltas;
    double **dweights;
    double **dbiases;
} MLP;
