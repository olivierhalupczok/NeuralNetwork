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
#include <iostream>
#include <chrono>
#include <random>

#include "mathFuncs.h"
#include "neuralNetwork.h"

NeuralNetwork::NeuralNetwork(std::vector<double> weightsVector, double biasNeuron, std::function<double(double)> activationFunc, std::function<double(double)> activationFuncDeriv)
{
    engine.seed(std::chrono::system_clock::now().time_since_epoch().count());
    static std::uniform_int_distribution<int> distro(-100, 100);

    for (size_t i = 0; i <= weightsVector.size(); i++)
    {
        std::vector<double> randomWeights;
        for (size_t j = 0; j < 2; j++)
        {
            double rand = (1.0*distro(engine))/100;
            randomWeights.push_back(rand);
        }
        double randomBias = (1.0*distro(engine))/100;


        // Neuron temp(randomWeights, randomBias, activationFunc, activationFuncDeriv, 0.1);
        Neuron temp(weightsVector, biasNeuron, activationFunc, activationFuncDeriv, 0.1);
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
void NeuralNetwork::train(long long int epochs, std::vector<std::vector<double>> inputData, std::vector<double> labels)
{
    // std::vector<std::vector<double>> epochPredictions;

    for (size_t i = 0; i < epochs; i++)
    {
        std::vector<double> currentEpochPredictions;
        for (auto t = 0; t < inputData.size(); t++)
        {
            double output = feedforward(inputData.at(t));
            std::vector<double> currentInputs = inputData.at(t);

            for (auto it = neurons.begin(); it != neurons.end(); it++)
            {
                auto iteration = it - neurons.begin();
                it->adjustWeight(0, *(neurons.end()-1), &lossDeriv_outDeriv, iteration);
                it->adjustWeight(1, *(neurons.end()-1), &lossDeriv_outDeriv, iteration);
                it->adjustBias(*(neurons.end()-1), &lossDeriv_outDeriv, iteration);
            }
            currentEpochPredictions.push_back(output);
        }

        // epochPredictions.push_back(currentEpochPredictions);
        auto loss = calc_mse_loss(labels, currentEpochPredictions);

        std::cout<<"Epoch "<<i<<" loss: "<< loss <<std::endl;
    }
}