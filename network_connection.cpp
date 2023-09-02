#include "network_connection.hpp"
#include "matrix.hpp"

network_connection::network_connection(vector<int> dimensions, float (*activation)(float))
    : weights({dimensions[1], dimensions[0]}), biases({dimensions[1], 1}), activation(activation){
}

network_connection::network_connection(vector<int> dimensions, float (*activation)(float), bool rand)
    : weights({dimensions[1], dimensions[0]}, rand), biases({dimensions[1], 1}, rand), activation(activation){
}

network_connection::network_connection(vector<int> dimensions, bool rand)
    : weights({dimensions[1], dimensions[0]}, rand), biases({dimensions[1], 1}, rand){
}
network_connection::~network_connection() {
}

void network_connection::forward_inplace(matrix &input) {
    weights.mult_inplace(input);
    biases.add_inplace(input);
    activate_inplace(input);
}
/*
matrix* network_connection::forward_inplace(matrix &input) {
    input = weights.mult(input);
    input.add(biases);
    input = activate(input);
    return &input;
}
*/

matrix network_connection::activate(matrix &input) {
    matrix res = matrix(input.dimensions);
    for (int i = 0; i < input.size; i++) {
        res.matrix_body[i] = activation(input.matrix_body[i]);
    }
    return res;
}

void network_connection::activate_inplace(matrix &input) {
    for (int i = 0; i < input.size; i++) {
        input.matrix_body[i] = activation(input.matrix_body[i]);
    }
}