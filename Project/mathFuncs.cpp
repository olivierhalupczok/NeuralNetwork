/**
 * @file mathFuncs.cpp
 * @author Olivier Halupczok
 * @brief Library with math functions used in the program
 * @version 0.1
 * @date 2022-06-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <math.h>
#include <vector>
#include <iostream>

#include "mathFuncs.h"

const std::string INV_ARG_MSG = "Invalid argument: ";
const std::string INV_VECTORS_MSG = " has to be executed with 2 vectors of the same length";
const std::string DOT_PRODUCT = "dot product";
const std::string MSE = "MSE loss calculation";

std::string invArgVectorsMsg(std::string nameOfFunc)
{
    return INV_ARG_MSG + nameOfFunc + INV_VECTORS_MSG;
}
double sigmoid(double arg)
{
    return 1 / (1 + std::exp(-arg));
}
double deriv_sigmoid(double arg)
{
    auto fx = sigmoid(arg);
    return fx * (1 - fx);
}
double dotProductOf2Vectors(std::vector<double> vector1, std::vector<double> vector2)
{

    if (vector1.size() != vector2.size())
    {
        throw std::invalid_argument(invArgVectorsMsg(DOT_PRODUCT));
    }

    double buffer = 0;

    for (size_t i = 0; i < vector1.size(); i++)
    {
        buffer += vector1[i] * vector2[i];
    }
    return buffer;
}
double calc_mse_loss(std::vector<double> outputTrue, std::vector<double> outputPredicted)
{
    if (outputTrue.size() != outputPredicted.size())
    {
        throw std::invalid_argument(invArgVectorsMsg(MSE));
    }
    auto numOfSamples = outputTrue.size();
    double accumulator = 0;
    for (size_t i = 0; i < numOfSamples; i++)
    {
        auto currentError = outputTrue[i] - outputPredicted[i];
        accumulator += currentError * currentError;
    }
    return (accumulator / numOfSamples);
}
double lossDeriv_outDeriv(double label, double output)
{
    return -2 * (label - output);
}