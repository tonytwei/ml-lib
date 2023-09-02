#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <map>

#include <thread>
#include <chrono>

#include "network_connection.hpp"
#include "network_connection.cpp"
#include "matrix.hpp"
#include "matrix.cpp"
#include "activation.hpp"
#include "activation.cpp"
#include "read_file.hpp"
#include "read_file.cpp"
#include "network.hpp"
#include "network.cpp"

using namespace std;

#define READ_FILE true
#define FILE_NAME "data/mnist_test.csv"
#define DATA_SIZE 10

int main() {
    CSVData csvdata;
    if (READ_FILE) {
        csvdata = parseCSV(FILE_NAME, DATA_SIZE);
    }
    
    vector<int> sizes = {784, 300, 300, 20};
    network net = network(sizes, ReLU, true);
    
    for (int i = 0; i < DATA_SIZE; i++) {
        matrix* ptr = csvdata.data[i];
        net.forward_inplace(*ptr);
        (*ptr).print_true();
    }
    
    cout << "Reached end of main" << endl;
    return 0;
}
/*
TODO list

    CONNECTION: WEIGHTS, BIASES -> RESULTANT NODES -> F(Z) , WE ALSO NEED TO STORE Z
    NEED FORWARD IN PLACE NOT TO PASS THROUGH ACTIVATION FUNCTION, NEED SEPARATE CALL.
    FOR BACKPROP.
*/