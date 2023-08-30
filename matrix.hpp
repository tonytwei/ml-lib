#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

using namespace std;

class matrix {
public:
    // constructors
    matrix(vector<int> dimensions);
    ~matrix();

    // attributes
    vector<int> dimensions;
    float* matrix_body;
    int size;

    // methods
    void print_true();
    // void print();
    matrix add(matrix input);
    matrix dot(matrix input);
    int get_true_index(vector<int> indices);
    void set_value(vector<int> indices, float value);
};

#endif // MATRIX_HPP