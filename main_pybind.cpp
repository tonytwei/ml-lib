#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include <string>
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

namespace py = pybind11;

network init_network(py::list layer_sizes, string activation, string loss, float learn_rate, bool rand) {
    // float (*activation)(float), float (*loss)(matrix &res, matrix &expected), float learn_rate, bool rand)
    vector<int> sizes;
    for (auto size : layer_sizes) {
        sizes.push_back(size.cast<int>());
    }
    return network(sizes, pyActivationFunctions[activation], pyLossFunctions[loss], learn_rate, rand);
}

int add(int i, int j) {
    return i + j;
}

PYBIND11_MODULE(ml_lib, m) {
    m.doc() = "self made machine learning library";

    m.def("add", &add, "A function that adds two numbers",
          py::arg("i") = 10, py::arg("j") = 5);

    // dosen't work lmao
    // m.def("init_network", &init_network, "Initialize a neural network");

    py::class_<network>(m, "Network")
        .def(py::init<>())  // Default constructor
        .def(py::init<vector<int>, py::function, py::function, float, bool>(),
             py::arg("sizes"), py::arg("activation"), py::arg("loss"),
             py::arg("learn_rate"), py::arg("rand"))
        .def("forward_inplace", &network::forward_inplace)
        .def("cost", &network::cost)
        .def("backprop_inplace", &network::backprop_inplace)
        .def("calc_dc_da", &network::calc_dc_da);
}
