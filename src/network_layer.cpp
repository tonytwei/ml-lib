#include "network_layer.hpp"
#include "matrix.hpp"

network_layer::network_layer(int in_size, int out_size, float (*activation)(float))
    : weights({in_size, out_size}), biases({1, out_size}), activation(activation){
}

network_layer::network_layer(vector<int> dimensions, float (*activation)(float))
    : weights(dimensions), biases({1, dimensions[1]}), activation(activation){
}

network_layer::~network_layer() {
    weights.~matrix();
    biases.~matrix();
}

matrix network_layer::forward(matrix input) {
    matrix res = weights.dot(input);
    res.add(biases);
    res = activate(res);

    return res;
}

matrix network_layer::activate(matrix input) {
    matrix res = matrix(input.dimensions);
    for (int i = 0; i < input.size; i++) {
        res.matrix_body[i] = activation(input.matrix_body[i]);
    }
    return res;
}