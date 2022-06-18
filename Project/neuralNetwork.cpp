/**
 * @file neuralNetwork.cpp
 * @author Olivier Halupczok
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
#include "networkResult.h"
#include "neuralNetwork.h"

NeuralNetwork::NeuralNetwork(size_t numOfNeurons, std::function<double(double)> activationFunc, std::function<double(double)> activationFuncDeriv, double learningRate)
{
    engine.seed(std::chrono::system_clock::now().time_since_epoch().count());
    static std::uniform_int_distribution<int> distro(0, 200);

    for (size_t i = 0; i <= numOfNeurons; i++)
    {
        std::vector<double> randomWeights;
        for (size_t j = 0; j < 2; j++)
        {
            double random = 1.0 * distro(engine);
            double rand = (random - 100) / 100;
            randomWeights.push_back(rand);
        }
        double randomBias = (1.0 * distro(engine) - 100) / 100;

        Neuron temp(randomWeights, randomBias, activationFunc, activationFuncDeriv, learningRate);
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
void NeuralNetwork::train(long long int epochs, std::vector<std::vector<double>> inputData, std::vector<double> labels, std::function<void(NetworkResult)> callback)
{
    for (size_t i = 0; i < epochs; i++)
    {
        std::vector<double> currentEpochPredictions;
        for (auto t = 0; t < inputData.size(); t++)
        {
            double output = feedforward(inputData.at(t));
            auto outputNeuron = *(neurons.end() - 1);
            std::vector<double> currentInputs = inputData.at(t);

            for (auto it = neurons.begin(); it != neurons.end(); it++)
            {
                auto iteration = it - neurons.begin();
                auto lossDerivCalced = lossDeriv_outDeriv(labels[t], output);

                it->adjustWeight(0, outputNeuron, lossDerivCalced, iteration);
                it->adjustWeight(1, outputNeuron, lossDerivCalced, iteration);
                it->adjustBias(outputNeuron, lossDerivCalced, iteration);
            }
            currentEpochPredictions.push_back(output);
        }

        auto loss = calc_mse_loss(labels, currentEpochPredictions);
        NetworkResult result(loss, currentEpochPredictions);
        callback(result);
    }
}