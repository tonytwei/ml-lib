#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <random>
#include "matrix.hpp" // Include your matrix.hpp file here

namespace py = pybind11;

std::random_device rd;
std::mt19937 gen(rd());

#define DEFAULT_MATRIX_VALUE 0

float ReLU(float x) {
    if (x >= 0) {
        return x;
    } else {
        return 0;
    }
}

float sigmoid(float x) {
    return 1.0f / (1.0f + expf(-x));
}

PYBIND11_MODULE(ml_lib, m) {
    m.doc() = "ml_lib module";

    // Bind your matrix class here using PYBIND11 class_
    py::class_<matrix>(m, "Matrix")
        .def(py::init<std::vector<int>>())
        .def(py::init<std::vector<int>, bool>())
        .def("print_true", &matrix::print_true)
        .def("print", &matrix::print)
        .def("urand", &matrix::urand)
        .def("nrand", &matrix::nrand)
        .def("add", &matrix::add)
        .def("add_inplace", &matrix::add_inplace)
        .def("mult", &matrix::mult)
        .def("mult_inplace", &matrix::mult_inplace)
        .def("get_true_index", &matrix::get_true_index)
        .def("get_psuedo_indices", &matrix::get_psuedo_indices)
        .def("set_value", py::overload_cast<vector<int>&, float>(&matrix::set_value))
        .def("set_value", py::overload_cast<int, float>(&matrix::set_value))
        .def("print_shape", &matrix::print_shape)
        .def("copy", &matrix::copy)
        .def("get_max_index", &matrix::get_max_index)
        .def("transpose_inplace", &matrix::transpose_inplace)
        .def("hammard_product_inplace", &matrix::hammard_product_inplace)
        .def("scalar_mult_inplace", &matrix::scalar_mult_inplace)
        .def("true_dot", &matrix::true_dot)
        .def("sub_inplace", &matrix::sub_inplace);

    // Bind your ReLU and sigmoid functions
    m.def("ReLU", &ReLU, "ReLU function");
    m.def("sigmoid", &sigmoid, "Sigmoid function");
}
