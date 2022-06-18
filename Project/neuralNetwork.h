/**
 * @file neuralNetwork.h
 * @author Olivier Halupczok
 * @brief
 * @version 0.1
 * @date 2022-06-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <vector>
#include <chrono>
#include <random>
#include <functional>

#include "neuron.h"
#include "networkResult.h"

#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

class NeuralNetwork
{
private:
    /**
     * @brief vector of Neurons in Neural network
     *
     */
    std::vector<Neuron> neurons;
    std::default_random_engine engine; /** random number engine **/

public:
    /**
     * @brief Construct a new Neural Network object
     * 
     * @param numOfNeurons num of Neurons to create
     * @param activationFunc function to activate neuron
     * @param activationFuncDeriv derivative of activation function
     * @param learningRate learning rate of the neurons
     */
    NeuralNetwork(size_t numOfNeurons, std::function<double(double)> activationFunc, std::function<double(double)> activationFuncDeriv, double learningRate );
    /**
     * @brief feedforward every neuron from hidden layer
     *
     * @param inputs from input layer
     * @return double output of the output neuron
     */
    double feedforward(std::vector<double> inputs);
    /**
     * @brief train neural net
     * 
     * @param epochs determines the number of iterations through the whole dataset
     * @param inputData dataset to train on
     * @param labels evualuate training process
     * @param callback callback after training
     */
    void train(long long int epochs, std::vector<std::vector<double>> inputData, std::vector<double> labels, std::function<void(NetworkResult)> callback);
};

#endif