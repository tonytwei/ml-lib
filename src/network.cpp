#include <vector>
#include "network.hpp"
#include "network_connection.hpp"

using namespace std;

network::network() : num_layers(0), learn_rate(0.0) {}

network::network(vector<int> sizes, float (*activation)(float), float (*loss)(matrix &res, matrix &expected), float learn_rate, bool rand)
    : loss(loss), learn_rate(learn_rate) {
    num_layers = sizes.size() - 1;
    for (int i = 0; i < num_layers; i++) {
        layers.emplace_back(make_shared<network_connection>(vector<int>{sizes[i], sizes[i + 1]}, activation, rand));
    }
}

network::~network() {
}

void network::forward_inplace(matrix &input) {
    for (int i = 0; i < num_layers; i++) {
        (*layers[i]).forward_inplace(input);
    }
}

// TODO: is redundant? remove?
float network::cost(matrix &input, matrix &expected_output) {
    return loss(input, expected_output);
}

void network::backprop_inplace(matrix &dc_da) {
    for (int i = num_layers - 1; i > -1; i--) {
        (*layers[i]).backprop_inplace(dc_da, learn_rate);
    }
}

matrix network::calc_dc_da(matrix &input, matrix &expected_output) {
    matrix res = matrix(input.dimensions);
    vector<int> idx = {0,0};
    for (int i = 0; i < input.dimensions[0]; i++) {
        idx = {i,0};
        res.set_value(idx, 2 * (input.matrix_body[i] - expected_output.matrix_body[i]));
    }
    return res;
}