/**
 * @file main.cpp
 * @author Olivier Halupczok
 * @brief
 * @version 0.1
 * @date 2022-06-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>

#include "mathFuncs.h"
// #include "neuron.h"
#include "neuralNetwork.h"

int main(int argc, char const *argv[])
{
    // placeholder
    std::vector<double> weights = {0, 1};
    double bias = 0;
    // Neuron n(weights, bias, &sigmoid);
    NeuralNetwork net(weights, bias, &sigmoid);

    std::vector<double> inputs = {2, 3};
    auto temp = net.feedforward(inputs);
    std::cout << temp;
    return 0;
}