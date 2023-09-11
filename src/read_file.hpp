#ifndef READ_FILE_HPP
#define READ_FILE_HPP

#include <string>
#include <vector>
#include "matrix.hpp"

using namespace std;

struct CSVData {
    vector<int> labels;
    vector<matrix*> data;
    vector<matrix*> expected;
};

CSVData parseCSV(string filename, int data_size, int expected_size);

#endif // READ_FILE_HPP
