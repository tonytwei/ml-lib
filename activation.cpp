#include <math.h>
#include "activation.hpp"

float ReLU(float x) {
    if (x >= 0) {
        return x;
    } else {
        return 0;
    }
   
}

float sigmoid(float x) {
    return (((float) 1)/(1+expf(-x)));
}

float Dsigmoid(float x) {
    return (expf(-x))/((1+expf(-x))*(1+expf(-x)));
}

float leaky_ReLU(float x) {
    if (x >= 0) {
        return x;
    } else {
        return x * 0.1;
    }
}

float alpha_RELU(float x, float alpha) {
    if (x >= 0) {
        return x;
    } else {
        return x * alpha;
    }
}

float variance_loss_function(matrix &res, matrix &expected) {
    if (res.size != expected.size) {
        printf("\nERROR IN VARIANCE LOSS FUNCTION\n");
        return -1;
    }

    float sum = 0;
    for (int i = 0; i < res.size; i++) {
        sum += (res.matrix_body[i]-expected.matrix_body[i])*(res.matrix_body[i]-expected.matrix_body[i]);
    }

    return sum / res.size;
}
