#ifndef NETWORK_CONNECTION_HPP
#define NETWORK_CONNECTION_HPP

#include "matrix.hpp"

class network_connection {
public:
    // constructors
    network_connection(vector<int> dimensions, float (*activation)(float));
    network_connection(vector<int> dimensions, float (*activation)(float), bool rand);
    ~network_connection();

    // attributes
    matrix weights;
    matrix biases;
    float (*activation)(float);
    float (*Dactivation)(float);
    matrix prev_a;
    matrix z;
    matrix a;

    // methods
    //matrix forward(matrix &input);
    void forward_inplace(matrix &input);
    matrix activate(matrix &input);
    matrix Dactivate(matrix &input);
    void activate_inplace(matrix &input);
    void backprop_inplace(matrix &dc_da, float learn_rate);
};

#endif // NETWORK_CONNECTION_HPP