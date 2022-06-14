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
    std::vector<double> weights = {1, 1};
    double bias = 0;
    NeuralNetwork net(weights, bias, &sigmoid, &deriv_sigmoid);

    std::vector<double> alice = {-2, -1};
    std::vector<double> bob = {25, 6};
    std::vector<double> charlie = {17, 4};
    std::vector<double> diana = {-15, -6};

    std::vector<std::vector<double>> inputs = {
        alice,
        // bob,
        // charlie,
        // diana
    };

    double aliceSex = 1;
    double bobSex = 0;
    double charlieSex = 0;
    double dianaSex = 1;

    std::vector<double> labels = {
        aliceSex,
        // bobSex,
        // charlieSex,
        // dianaSex
    };
    net.train(1, inputs, labels);
}