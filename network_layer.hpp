#ifndef NETWORK_LAYER_HPP
#define NETWORK_LAYER_HPP

#include "matrix.hpp"

class network_layer {
public:
    // constructors
    network_layer(int in_size, int out_size, float (*activation)(float)); // TODO: deleter later
    network_layer(vector<int> dimensions, float (*activation)(float));
    ~network_layer();

    // attributes
    matrix weights;
    matrix biases;
    float (*activation)(float);

    // methods
    matrix forward(matrix input);
    matrix activate(matrix input);
};

#endif // NETWORK_LAYER_HPP
