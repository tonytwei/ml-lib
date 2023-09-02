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

// float leakyRELU