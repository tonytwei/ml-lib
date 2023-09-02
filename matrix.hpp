#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

using namespace std;

class matrix {
public:
    // constructors
    matrix(vector<int> dimensions);
    matrix(vector<int> dimensions, bool rand);
    ~matrix();

    // attributes
    vector<int> dimensions;
    float* matrix_body;
    int size;

    // methods
    void print_true();
    // void print();
    matrix add(matrix &input);
    void add_inplace(matrix &input);
    matrix mult(matrix &input);
    void mult_inplace(matrix &input);

    int get_true_index(vector<int> &indices);
    void set_value(vector<int> &indices, float value);
    void set_value(int index, float value);
    void print();
    void urand();
    vector<int> shape();
    void print_shape();
    void transpose();
};

#endif // MATRIX_HPP
    