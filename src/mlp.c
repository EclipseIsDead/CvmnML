// Multilayer Perceptron implementation

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "mlp.h"

// Initialize MLP given a number of layers, an array of layer sizes, and an array of activation functions
// the number of layers includes the input and output layers so minimum number of layers is 2
// i.e. (3, {2, 3, 1}, {SIGMOID, SIGMOID, SIGMOID}, ZERO)

void mlp_init(MLP *mlp, int num_layers, int *num_neurons, ActivationFunction *activation_functions, InitMethod init_method) {

    assert(num_layers >= 2);

    assert(num_neurons != NULL);
    assert(*(&num_neurons + 1) - num_neurons == num_layers);

    assert(activation_functions != NULL);
    assert(*(&activation_functions + 1) - activation_functions == num_layers);

    mlp->n_layers = num_layers;
    mlp->n_neurons = num_neurons;
    mlp->activations = activation_functions;

    mlp->weights = (double **) malloc((num_layers - 1) * sizeof(double **));
    mlp->biases = (double **) malloc((num_layers - 1) * sizeof(double *));

    for (int i = 0; i < num_layers - 1; i++) {
        mlp->weights[i] = (double *) malloc(num_neurons[i] * num_neurons[i + 1] * sizeof(double));
        mlp->biases[i] = (double *) malloc(num_neurons[i + 1] * sizeof(double));

        for (int j = 0; j < num_neurons[i]; j++) {
            mlp->weights[i][j] = *(double *) malloc(num_neurons[i + 1] * sizeof(double));
        }
    }

    if (init_method == ZERO) {
        for (int i = 0; i < num_layers - 1; i++) {
            int weight_index = 0;
            for (int j = 0; j < num_neurons[i]; j++) {
                for (int k = 0; k < num_neurons[i + 1]; k++) {
                    mlp->weights[i][weight_index++] = 0.0;
                }
            }
            for (int j = 0; j < num_neurons[i + 1]; j++) {
                mlp->biases[i][j] = 0.0;
            }
        }
    } else if (init_method == RANDOM) {
        for (int i = 0; i < num_layers - 1; i++) {
            int weight_index = 0;
            for (int j = 0; j < num_neurons[i]; j++) {
                for (int k = 0; k < num_neurons[i + 1]; k++) {
                    mlp->weights[i][weight_index++] = (double) rand() / (double) RAND_MAX;
                }
            }
            for (int j = 0; j < num_neurons[i + 1]; j++) {
                mlp->biases[i][j] = (double) rand() / (double) RAND_MAX;
            }
        }
    } else {
        // Should never reach here
        assert(0);
    }
}

// Free MLP memory

void mlp_free(MLP *mlp) {
    for (int i = 0; i < mlp->n_layers - 1; i++) {
        free(mlp->weights[i]);
        free(mlp->biases[i]);
    }
    free(mlp->weights);
    free(mlp->biases);
}

// main for testing

int main() {
    int num_layers = 3;
    int num_neurons[] = {2, 3, 1};
    ActivationFunction activation_functions[] = {SIGMOID, SIGMOID, SIGMOID};
    InitMethod init_method = ZERO;

    MLP mlp;

    mlp_init(&mlp, num_layers, num_neurons, activation_functions, init_method);
    mlp_free(&mlp);

    return 0;
}
