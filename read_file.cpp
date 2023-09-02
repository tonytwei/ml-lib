#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "read_file.hpp"

using namespace std;

#define NORM_VALUE 255.0

CSVData parseCSV(string filename, int lines) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Failed to open the file." << endl;
    }

    CSVData csvdata;
    string line;
    getline(file, line); // skip header line

    int columns = 0;
    for (char c : line) {
        if (c == ',') {
            columns += 1;
        }
    }

    string cell;
    int label;
    int count;
    int line_count = 0;
    while (getline(file, line) && line_count < lines) {
        line_count++;
        matrix *data_row = new matrix({columns, 1});
        stringstream lineStream(line);
     
        // extract label
        getline(lineStream, cell, ',');
        label = stoi(cell);
        csvdata.labels.push_back(label);

        // extract data
        count = 0;
        while (getline(lineStream, cell, ',')) {
            (*data_row).set_value(count, stoi(cell)/NORM_VALUE);
            count++;
        }
        csvdata.data.push_back(data_row);
        
    }
    return csvdata;
}