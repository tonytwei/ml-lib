#ifndef ACTIVATE_HPP
#define ACTIVATE_HPP

#include <math.h>

float ReLU(float x);
float sigmoid(float x);
float dsigmoid(float x);
float variance_loss_function(matrix &res, matrix &expected);

#endif // ACTIVATE_HPP
