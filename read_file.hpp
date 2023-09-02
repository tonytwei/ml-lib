#ifndef READ_FILE_HPP
#define READ_FILE_HPP

#include <string>
#include <vector>
#include "matrix.hpp"

using namespace std;

struct CSVData {
    vector<int> labels;
    vector<matrix*> data;
};

CSVData parseCSV(string filename, int lines);

#endif // READ_FILE_HPP
