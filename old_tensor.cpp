#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>

#define DEBUG_MODE_ON true

using namespace std;



class tensor {

    public: 
        tensor(vector<int> dimensions);
        ~tensor();
        float* tensor_body;
        vector<int> dimensions;
        int size;
        void print_true_tensor();
        bool same_dimension(tensor &t);
        int get_true_index(vector<int> indices);
        float get_value(vector<int> indices);
        void set_value(vector<int> indices, float value);
        void elementwise_add(tensor &t);
        void urand();
        void print_tensor();
        vector<int> get_psuedo_indices(int index);
    
};

tensor::tensor(vector<int> dimensions) {
    int size = 1;
    for (int i = 0; i < (int)dimensions.size(); i++) {
        size *= dimensions[i];
    }
    tensor_body = (float*) malloc(size * sizeof(float));

    for (int i = 0; i < size; i++) {
        tensor_body[i] = i;
    }

    this->tensor_body = tensor_body;
    this->dimensions = dimensions;
    this->size = size;
}

tensor::~tensor() {
    free(tensor_body);
    tensor_body = NULL;
    
}

void tensor::print_true_tensor() {
    for (int i = 0; i < size; i++) {
        cout << tensor_body[i] << " ";
    }
    cout << endl;
}

bool tensor::same_dimension(tensor &t) {
    if (dimensions.size() != t.dimensions.size()) {
        cout << "Error: dimensions do not match" << endl;
        return false;
    }
    for (int i = 0; i < (int)dimensions.size(); i++) {
        if (dimensions[i] != t.dimensions[i]) {
            cout << "Error: dimensions do not match" << endl;
            return false;
        }
    }
    return true;
}

int tensor::get_true_index(vector<int> indices) {

    if (indices.size() != dimensions.size()) {
        cout << "Error: dimensions do not match: in get_true_index" << endl;
    }



    int temp_size = size;
    int true_index = 0;
    for (int i = 0; i < (int)indices.size() - 1; i++) {
        temp_size /= dimensions[i];
        true_index += temp_size*indices[i];
    }
    true_index += indices[indices.size() - 1];

    if (true_index < 0 || true_index >= size) {
         cout << "Error: true index out of range" << endl;

         /*if (DEBUG_MODE_ON) {
            printf("\n Useful debug data: indices vector = <%d, %d>, true_index = %d\n", indices[0], indices[1], true_index);
            print_tensor;
            print_true_tensor;
         } */
    }

    return true_index;

}

vector<int> tensor::get_psuedo_indices(int true_index) {

     if (true_index < 0 || true_index >= size) {
        cout << "Error: true index out of range: in  get_psuedo_index" << endl;

    }

    vector<int> pseudo_indices(dimensions.size());

    int temp_size = size;
    int remaining_index = true_index;

    for (int i = 0; i < (int)dimensions.size() - 1; i++) {
        temp_size /= dimensions[i];
        pseudo_indices[i] = remaining_index / temp_size;
        remaining_index %= temp_size;
    }

    pseudo_indices[dimensions.size() - 1] = remaining_index;

    return pseudo_indices;
    

} 

float tensor::get_value(vector<int> indices) {



    int true_index = get_true_index(indices);
    return tensor_body[true_index];
}


void tensor::set_value(vector<int> indices, float value) {
    int true_index = get_true_index(indices);
    tensor_body[true_index] = value;
}

void tensor::elementwise_add(tensor &t) {
    if (!this->same_dimension(t)) return;

    // get size and add all together
    for (int i = 0; i < size; i++) {
        tensor_body[i] += t.tensor_body[i];
    }
}

void tensor::urand() {
    for (int i = 0; i < size; i++) {
        tensor_body[i] = ((float) rand())/RAND_MAX;
    }
}

void tensor::print_tensor() {

    //WORK IN PROGRESS
    
    cout << "[";

    vector<int> indices(dimensions.size());
    for (int i = 0; i < size; i++) {
        indices = get_psuedo_indices(i);

        cout << "{";
        for (int j = 0; j < (int) dimensions.size(); j++) {
            cout << indices[j] << " ";
        }

        cout << "} ";

    
        for (int j = 1; j < (int) dimensions.size(); j++) {
            if (indices[j] == dimensions[j] - 1) {
                cout << "\n";
            }
        }




    }

    cout << "]";
    
}




int main() {
    printf("Hello, World! lol \n");
    vector<int> dim = {2,2,3};
    tensor t(dim);

    t.print_true_tensor();
    printf("\n\n");

    t.print_tensor();


    
    return 0;
}

/*
TODO LIST
print tensor <- ollie IN PROGRESS, IMPLEMENTED FUNCTION THAT TAKES IN A TRUE INDEX AND RETURNS CORRESPONDING INDICES
n-mode product
*/

