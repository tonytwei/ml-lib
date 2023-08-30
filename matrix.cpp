#include <iostream>
#include <vector>
#include "matrix.hpp"

using namespace std;

int DEFAULT_MATRIX_VALUE = 0;

matrix::matrix(vector<int> dimensions) {
    int size = 1;
    for (int i = 0; i < (int)dimensions.size(); i++) {
        size *= dimensions[i];
    }
    matrix_body = (float*) malloc(size * sizeof(float));

    for (int i = 0; i < size; i++) {
        matrix_body[i] = DEFAULT_MATRIX_VALUE;
    }

    this->matrix_body = matrix_body;
    this->dimensions = dimensions;
    this->size = size;
}

matrix::~matrix() {
    free(matrix_body);
    matrix_body = NULL;
    
}

void matrix::print_true() {
    for (int i = 0; i < size; i++) {
        cout << matrix_body[i] << " ";
    }
    cout << endl;
}

matrix matrix::add(matrix input) {
    matrix res = matrix(dimensions);
    for (int i = 0; i < size; i++) {
        res.matrix_body[i] = matrix_body[i] + input.matrix_body[i];
    }
    return res;
}

matrix matrix::dot(matrix input) {
    vector<int> dimensions = {this->dimensions[0], input.dimensions[1]};
    matrix res = matrix(dimensions);

    for (int i = 0; i < dimensions[0]; i++) {
        float sum = 0;
        for (int j = 0; j < dimensions[1]; j++) {
            sum += matrix_body[i*dimensions[1] + j] * input.matrix_body[j*input.dimensions[1] + i];
        }
        res.matrix_body[i] = sum;
    }
    return res;
}

int matrix::get_true_index(vector<int> indices) {
    int index = 0;
    for (int i = 0; i < (int)indices.size(); i++) {
        index += indices[i] * dimensions[i+1];
    }
    return index;
}

void matrix::set_value(vector<int> indices, float value) {
    int index = get_true_index(indices);
    matrix_body[index] = value;
}

int main() {
    matrix mA = matrix({1, 3});
    mA.set_value({0, 0}, 4);
    mA.set_value({0, 1}, 6);
    mA.set_value({0, 2}, 8);
    mA.print_true(); // ans should be 4 6 8

    matrix mB = matrix({3, 1});
    mB.set_value({0, 0}, 3);
    mB.set_value({1, 0}, 2);
    mB.set_value({2, 0}, 5);
    mB.print_true(); // ans should be 3 2 5
    // matrix res = mA.dot(mB);

    // res.print_true(); // ans should be 64
}