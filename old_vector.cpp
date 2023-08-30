#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <map>

using namespace std;
// ###############################################################################
class r1_tensor {
    public:
        r1_tensor(int size);
        ~r1_tensor();
        int size;
        float* vector_body;
        void print_true();
        void print();
        r1_tensor add(r1_tensor input);
};

r1_tensor::r1_tensor(int size) {
    float *vector_body = (float*) malloc(size * sizeof(float));

    for (int i = 0; i < size; i++) {
        vector_body[i] = i;
    }
    this->vector_body = vector_body;
    this->size = size;
}

r1_tensor::~r1_tensor() {
    free(vector_body);
    vector_body = NULL;
    
}


void r1_tensor::print_true() {
    for (int i = 0; i < size; i++) {
        cout << vector_body[i] << " ";
    }
    cout << endl;
}

void r1_tensor::print() {
    printf("[");
    for (int i = 0; i < size-1; i++) {
        printf("%f, ", vector_body[i]);
    }
    printf("%f]", vector_body[size-1]);
    cout << endl;
}

r1_tensor r1_tensor::add(r1_tensor input) {
    r1_tensor res = r1_tensor(size);
    for (int i = 0; i < size; i++) {
        res.vector_body[i] = vector_body[i] + input.vector_body[i];
    }
    return res;
}

// ###############################################################################
class r2_tensor {
    public:
        r2_tensor(int size);
        ~r2_tensor();
        int size;
        float* vector_body;
        void print_true();
        void print();
        r1_tensor dot(r1_tensor input);
};

r2_tensor::r2_tensor(int size) {
    float *vector_body = (float*) malloc(size * sizeof(float));

    for (int i = 0; i < size; i++) {
        vector_body[i] = i;
    }
    this->vector_body = vector_body;
    this->size = size;
}

r2_tensor::~r2_tensor() {
    free(vector_body);
    vector_body = NULL;
}

r1_tensor r2_tensor::dot(r1_tensor input) {
    r1_tensor res = r1_tensor(input.size);
    for (int row = 0; row < input.size; row++) {
        res.vector_body[row] = 0;
        for (int col = 0; col < input.size; col++) {
            res.vector_body[row] += vector_body[row * input.size + col] * input.vector_body[col];
        }
    }
    return res;
}


class network_layer{
    public:
        // constuctors
        network_layer(int size);
        network_layer(int size, float (*activation)(float));
        network_layer(int in_size, int out_size, float (*activation)(float));
        ~network_layer();

        // attributes
        r2_tensor weights;
        r1_tensor biases;
        float (*activation)(float);

        // methods
        r1_tensor forward(r1_tensor input);
        r1_tensor activate(r1_tensor input);
        r1_tensor backward(r1_tensor input);
        r1_tensor update(r1_tensor input);
        r1_tensor dot(r1_tensor input, r1_tensor weights);
        // r1_tensor get_weights();
        // r1_tensor get_biases();
        // void set_weights(r1_tensor weights);
        // void set_biases(r1_tensor biases);
        // void print_weights();
        // void print_biases();
        void print_true_weights();
        // void print_true_biases();
        // void print_true();
        // void print();
        // void print_true_weights_biases();
        // void print_weights_biases();
};


network_layer::network_layer(int in_size, int out_size, float (*activation)(float))
    : weights(in_size * out_size), biases(out_size), activation(activation){
}

network_layer::~network_layer() {
    weights.~r2_tensor();
    biases.~r1_tensor();
}

r1_tensor network_layer::forward(r1_tensor input) {
    r1_tensor res = weights.dot(input);
    // res.add(biases);
    // res = activate(res);

    return res;
}

r1_tensor network_layer::activate(r1_tensor input) {
    r1_tensor res = r1_tensor(input.size);
    for (int i = 0; i < input.size; i++) {
        res.vector_body[i] = activation(input.vector_body[i]);
    }
    return res;
}

r1_tensor network_layer::dot(r1_tensor input) {
    r1_tensor res = r1_tensor(size);
}



void network_layer::print_true_weights() {
    weights.print_true();
}



// activation functions
float ReLU(float x) {
    if (x > 0) return x;
    return 0;
}

float sigmoid(float x) {
    return (((float) 1)/(1+expf(-x)));
}



int main() {
    /*
    r1_tensor t(10);
    t.print_true();
    t.print();
    */
    /*
    network_layer l(10, sigmoid);
    l.print_true_weights();
    cout << l.activation(0.5) << endl;
    cout << l.activation(-0.5) << endl;
    */


    network_layer l2(10, 10, sigmoid);
    r1_tensor t = l2.forward(r1_tensor(10));
    
    return 0;
}


/*
TODO:
make superclass tensor, r1 and r2 inherits from superclass
*/