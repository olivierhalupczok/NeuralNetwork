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

#ifndef FLAG_H
#define FLAG_H

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

public:
    /**
     * @brief Construct a new Neuron object
     *
     * @param weightsToInit Weigths of inputs
     * @param biasToInit Bias to calculate feedforward's total
     * @param activationFuncToInit
     */
    Neuron(std::vector<double> weightsToInit, double biasToInit, std::function<double(double)> activationFuncToInit);
    /**
     * @brief Feedforward with neurons from previous layers
     *
     * @param inputs values of previous neurons
     * @return double total value of neuron
     */
    double feedforward(std::vector<double> inputs);
};

#endif