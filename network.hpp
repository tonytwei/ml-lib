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
    network(std::vector<int> sizes, float (*activation)(float), float (*loss) (vector<float>, vector<float>), bool rand);
    ~network();

    // attributes
    int num_layers;
    vector<unique_ptr<network_connection>> layers;

    // methods
    void forward_inplace(matrix &input);
};

#endif // NETWORK_HPP
