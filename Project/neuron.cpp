/**
 * @file neuron.cpp
 * @author Olivier Halupczok
 * @brief 
 * @version 0.1
 * @date 2022-06-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <vector>
#include <functional>

#include "neuron.h"
#include "mathFuncs.h"

Neuron::Neuron(std::vector<double> weightsToInit, double biasToInit,  std::function<double(double)> activationFuncToInit) {
    weights = weightsToInit;
    bias = biasToInit;
    activationFunc = activationFuncToInit;
}

double Neuron::feedforward(std::vector<double> inputs) {
    double total = dotProductOf2Vectors(inputs, weights) + bias;
    return activationFunc(total);
}