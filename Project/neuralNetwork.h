/**
 * @file neuralNetwork.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-06-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <vector>

#include "neuron.h"

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

public:
    /**
     * @brief Construct a new Neural Network object
     *
     * @param weightsVector vector of weigths to populate vector of neurons with those weights
     * @param biasNeuron initial bias for every neuron created at the very beginning
     * @param activationFunc activationFunc to activate every neuron it is constant for a lifespan of the neuron
     */
    NeuralNetwork(std::vector<double> weightsVector, double biasNeuron, std::function<double(double)> activationFunc);
    /**
     * @brief feedforward every neuron from hidden layer
     *
     * @param inputs from input layer
     * @return double output of the output neuron
     */
    double feedforward(std::vector<double> inputs);
};

#endif