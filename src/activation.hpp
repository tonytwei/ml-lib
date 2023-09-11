#ifndef ACTIVATE_HPP
#define ACTIVATE_HPP

#include <math.h>
#include <unordered_map>
#include <functional>
#include <string>
#include "matrix.hpp"

using namespace std;

float ReLU(float x);
float sigmoid(float x);
float Dsigmoid(float x);
float variance_loss_function(matrix &res, matrix &expected);

using ActivationFunction = float (*)(float);
using LossFunction = float (*)(matrix &res, matrix &expected);

unordered_map<string, ActivationFunction> pyActivationFunctions = {
    {"ReLU", ReLU},
    {"sigmoid", sigmoid}
};

unordered_map<string, LossFunction> pyLossFunctions = {
    {"variance", variance_loss_function}
};

unordered_map<ActivationFunction, ActivationFunction> dActivationFunctions = {
    {sigmoid, Dsigmoid}
};

#endif // ACTIVATE_HPP
