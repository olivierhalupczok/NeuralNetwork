/**
 * @file neuron.h
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

#include "mathFuncs.h"

#ifndef NEURON_H
#define NEURON_H

class Neuron
{
private:
    /**
     * @brief weigths of input
     *
     */
    std::vector<double> weights;
    /**
     * @brief bias to calculate activation function
     *
     */
    double bias;
    /**
     * @brief activation function specified in the constructor
     *
     */
    std::function<double(double)> activationFunc;
    /**
     * @brief activation function's derivative
     *
     */
    std::function<double(double)> activationFuncDerivative;
    /**
     * @brief sum of: dot product of inputs and weights, and bias
     *
     */
    double total;
    /**
     * @brief learning coefficient
     *
     */
    double learningRate;
    /**
     * @brief inputs vector to use them in backprop
     *
     */
    std::vector<double> inputs;
    /**
     * @brief output calculated during feedforward's exec
     *
     */
    double output;
    bool isOutputAndTotalSet;

public:
    /**
     * @brief Construct a new Neuron object
     *
     * @param weightsToInit Weigths of inputs
     * @param biasToInit Bias to calculate feedforward's total
     * @param activationFuncToInit
     */
    Neuron(std::vector<double> weightsToInit, double biasToInit, std::function<double(double)> activationFuncToInit, std::function<double(double)> activationFuncDeriv, double learningRateToInit);
    /**
     * @brief Feedforward with neurons from previous layers
     *
     * @param inputs values of previous neurons
     * @return double total value of neuron
     */
    double feedforward(std::vector<double> inputsToFeed);
    /**
     * @brief Get the Total property
     *
     * @return double - sum of: dot product of inputs and weights, and bias
     */
    double getTotal();
    /**
     * @brief Get the Weights property
     *
     * @return std::vector<double> of weights
     */
    std::vector<double> getWeights();
    /**
     * @brief use backprop to adjust weight of specified index and to train network by doing so
     * 
     * @param index 
     * @param outputNeuron 
     * @param lossDeriv_outDeriv 
     * @param iterator 
     */
    void adjustWeight(size_t index, Neuron outputNeuron, std::function<double(double)> lossDeriv_outDeriv, size_t iterator);
    /**
     * @brief use backprop to adjust bias and to train network
     *
     * @param outputNeuron
     * @param lossDeriv_outDeriv
     * @param iterator
     */
    void adjustBias(Neuron outputNeuron, std::function<double(double)> lossDeriv_outDeriv, size_t iterator);
    /**
     * @brief Get the Output calculated during feedforward's execution
     *
     * @return double - output value
     */
    double getOutput();
};

#endif