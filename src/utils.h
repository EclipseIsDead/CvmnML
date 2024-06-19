/* This file stores utility function that are broad scope and general for all files */

// Typing for global concepts for this library
typedef enum {
    INPUT_LAYER,
    HIDDEN_LAYER,
    OUTPUT_LAYER
} LayerType;

typedef enum {
    RAW,
    HEAVESIDE,
    SIGMOID,
    RELU,
    TANH,
    LEAKY_RELU
} ActivationFunction;

typedef enum {
    ZERO,
    RANDOM
} InitMethod;
