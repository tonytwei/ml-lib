#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <map>

#include "network_layer.hpp"
#include "matrix.hpp"

using namespace std;

// activation functions
float ReLU(float x) {
    if (x > 0) return x;
    return 0;
}

float sigmoid(float x) {
    return (((float) 1)/(1+expf(-x)));
}

int main() {
    vector<int> dimensions = {2, 3};
    network_layer layer = network_layer(dimensions, sigmoid);

    matrix identity = matrix({5, 5});
    for (int i = 0; i < identity.dimensions[0]; i++) {
        for (int j = 0; j < identity.dimensions[1]; j++) {
            if (i == j) {
                identity.matrix_body[i*identity.dimensions[1] + j] = 1;
            }
        }
    }

    matrix mA = matrix({1, 3});
    matrix mB = matrix({3, 1});
    matrix res = mA.dot(mB);
    res.print_true();

    return 0;
}