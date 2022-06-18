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
#include <functional>

#include "mathFuncs.h"
#include "networkResult.h"
#include "neuralNetwork.h"
#include "logger.h"

size_t epochCount = 1;
CSV_Logger logger("logs/output.csv");

void logResults(NetworkResult res)
{   
    logger << epochCount++ <<std::string("  ")<< res << std::endl;
    return;
}

int main(int argc, char const *argv[])
{
    logger << std::string("epoch    loss") << std::endl;

    NeuralNetwork net(2, &sigmoid, &deriv_sigmoid, 1);

    std::vector<double> alice = {-2, -1};
    std::vector<double> bob = {25, 6};
    std::vector<double> charlie = {17, 4};
    std::vector<double> diana = {-15, -6};

    std::vector<std::vector<double>> inputs = {
        alice,
        bob,
        charlie,
        diana};

    double aliceSex = 1;
    double bobSex = 0;
    double charlieSex = 0;
    double dianaSex = 1;

    std::vector<double> labels = {
        aliceSex,
        bobSex,
        charlieSex,
        dianaSex

    };

    net.train(200, inputs, labels, &logResults);
    std::cout<<"output file is ready";
}
