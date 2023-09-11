#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <map>

#include <thread>
#include <chrono>

#include "src/network_connection.hpp"
#include "src/network_connection.cpp"
#include "src/matrix.hpp"
#include "src/matrix.cpp"
#include "src/activation.hpp"
#include "src/activation.cpp"
#include "src/read_file.hpp"
#include "src/read_file.cpp"
#include "src/network.hpp"
#include "src/network.cpp"

using namespace std;

#define READ_FILE true
#define FILE_NAME "data/mnist_test.csv"
#define DATA_SIZE 10000
#define NET_OUT_SIZE 10
#define LEARN_RATE 0.01

int main() {
	CSVData csvdata;
	if (READ_FILE) {
		csvdata = parseCSV(FILE_NAME, DATA_SIZE, NET_OUT_SIZE);
	}
	
	vector<int> layer_sizes = {784, 200, 200, NET_OUT_SIZE};
	network net = network(layer_sizes, sigmoid,
			variance_loss_function, LEARN_RATE, true);
	
	int correct_count = 0;

	for (int i = 0; i < DATA_SIZE; i++) {
		matrix* ptr = csvdata.data[i];
		net.forward_inplace(*ptr);
		//(*ptr).print_true();

		if (ptr->get_max_index() == csvdata.expected[i]->get_max_index()) {
			correct_count++;
		}
		cout << correct_count << "/" << i + 1 << endl;
		cout << (float)correct_count / (i + 1.0) << endl;
		
		matrix dc_da = net.calc_dc_da(*ptr, *csvdata.expected[i]);
		net.backprop_inplace(dc_da);
	}
	
	cout << "Reached end of main" << endl;
	return 0;
}
/*
TODO list
	NVDA.csv pandas pre processing
	save/load network
*/