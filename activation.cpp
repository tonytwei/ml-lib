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

float variance_loss_function(vector<float> resultant_values, vector<float> expected_values) {
    
    if (resultant_values.size() != expected_values.size()) {
        printf("\nERROR IN VARIANCE LOSS FUNCTION\n");
        return -1;
    }

    float variance_loss_function_result = 0;
    for (int i = 0; i < (int)resultant_values.size(); i++) {
        variance_loss_function_result += (resultant_values[i]-expected_values[i])*(resultant_values[i]-expected_values[i]);
    }

    return variance_loss_function_result/resultant_values.size();
}
// float leakyRELU
