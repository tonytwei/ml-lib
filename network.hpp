#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <vector>
#include <memory>
#include "network_connection.hpp"
#include "matrix.hpp"

using namespace std;

class network {
public:
    // constructors
    network(vector<int> sizes, float (*activation)(float), float (*Dactivation)(float), float (*loss)(matrix &res, matrix &expected), float learn_rate, bool rand);
    ~network();

    // attributes
    int num_layers;
    vector<unique_ptr<network_connection>> layers;
    float (*loss)(matrix &res, matrix &expected);
    float learn_rate;

    // methods
    void forward_inplace(matrix &input);
    float cost(matrix &input, matrix &expected_output);
    void backprop_inplace(matrix &dc_da);
    matrix calc_dc_da(matrix &input, matrix &expected_output);
};

#endif // NETWORK_HPP
