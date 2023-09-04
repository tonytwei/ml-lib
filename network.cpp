#include <vector>
#include "network.hpp"
#include "network_connection.hpp"

using namespace std;

network::network(vector<int> sizes, float (*activation)(float), float (*loss)(vector<float>, vector<float>), bool rand) {
    num_layers = sizes.size() - 1;
    for (int i = 0; i < num_layers; i++) {
        layers.emplace_back(make_unique<network_connection>(vector<int>{sizes[i], sizes[i + 1]}, activation, rand));
    }
}

network::~network() {
}

void network::forward_inplace(matrix &input) {
    for (int i = 0; i < num_layers; i++) {
        (*layers[i]).forward_inplace(input);
    }
}

//void network::backprop_inplace(matrix &input)