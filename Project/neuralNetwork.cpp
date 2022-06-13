/**
 * @file neuralNetwork.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-06-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <functional>
#include <vector>
#include <iterator>

#include "mathFuncs.h"
#include "neuralNetwork.h"

NeuralNetwork::NeuralNetwork(std::vector<double> weightsVector, double biasNeuron, std::function<double(double)> activationFunc)
{
    for (size_t i = 0; i <= weightsVector.size(); i++)
    {
        Neuron temp(weightsVector, biasNeuron, activationFunc);
        neurons.push_back(temp);
    }
}
double NeuralNetwork::feedforward(std::vector<double> inputs)
{
    std::vector<double> hiddenLayerOutputs;
    for (auto it = neurons.begin(); it != neurons.end() - 1; it++)
    {
        hiddenLayerOutputs.push_back(it->feedforward(inputs));
    }
    double outputOfNet = neurons[neurons.size() - 1].feedforward(hiddenLayerOutputs);
    return outputOfNet;
}