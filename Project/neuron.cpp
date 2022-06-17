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
#include <iostream>

#include "mathFuncs.h"
#include "neuron.h"

constexpr double LEARNING_DEFAULT_RATE = 0.01;
const std::string OUTPUT = "output";
const std::string TOTAL = "total";

std::string exceptionMsg(std::string propertyName)
{
    return "Neuron: you cannot get" + propertyName + " until you execute feedforward function";
}

Neuron::Neuron(std::vector<double> weightsToInit, double biasToInit, std::function<double(double)> activationFuncToInit, std::function<double(double)> activationFuncDeriv, double learningRateToInit = LEARNING_DEFAULT_RATE)
{
    weights = weightsToInit;
    bias = biasToInit;
    activationFunc = activationFuncToInit;
    activationFuncDerivative = activationFuncDeriv;
    learningRate = learningRateToInit;
    isOutputAndTotalSet = false;
}

double Neuron::feedforward(std::vector<double> inputsToFeed)
{
    inputs = inputsToFeed;
    total = dotProductOf2Vectors(inputs, weights) + bias;
    output = activationFunc(total);
    isOutputAndTotalSet = true;
    return output;
}

double Neuron::getTotal()
{
    if (!isOutputAndTotalSet)
        throw std::invalid_argument(exceptionMsg(TOTAL));
    return total;
}

void Neuron::adjustWeight(size_t index, Neuron outputNeuron, double lossDeriv_outDeriv_calced, size_t iterator)
{
    auto outWeightIndex = iterator == 2 ? index : iterator;
    auto outDeriv_neuronDeriv_calced = outputNeuron.getWeights().at(outWeightIndex) * activationFuncDerivative(outputNeuron.getTotal());
    auto neuronDeriv_weightDeriv_calced = inputs[index] * activationFuncDerivative(total);

    auto lossDerivweightDeriv = lossDeriv_outDeriv_calced * outDeriv_neuronDeriv_calced * neuronDeriv_weightDeriv_calced;

    weights[index] -= (learningRate * lossDerivweightDeriv);
}
void Neuron::adjustBias(Neuron outputNeuron,double lossDeriv_outDeriv_calced, size_t iterator)
{
    auto outDeriv_neuronDeriv_calced =  iterator == 2 ? 1 : outputNeuron.getWeights().at(iterator) * activationFuncDerivative(outputNeuron.getTotal());
    auto neuronDeriv_biasDeriv = activationFuncDerivative(total);
    
    auto lossDerivBiasDeriv = lossDeriv_outDeriv_calced * outDeriv_neuronDeriv_calced * neuronDeriv_biasDeriv;

    bias -= (learningRate * lossDerivBiasDeriv);
}
std::vector<double> Neuron::getWeights()
{
    return weights;
}
double Neuron::getOutput()
{
    if (!isOutputAndTotalSet)
        throw std::invalid_argument(exceptionMsg(OUTPUT));
    return output;
}