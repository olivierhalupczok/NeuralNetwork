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

#include "inputLoader.h"
#include "mathFuncs.h"
#include "networkResult.h"
#include "neuralNetwork.h"
#include "logger.h"
#include "dataset.h"

size_t epochCount = 1;
CSV_Logger logger("logs/output.csv");

void logResults(NetworkResult res)
{   
    logger << epochCount++ <<std::string("\t")<< res << std::endl;
    return;
}

int main(int argc, char const *argv[])
{   
    std::vector<std::string> CSV_labels = {"epoch","loss"};
    logger.setLabels(CSV_labels);

    NeuralNetwork net(2, &sigmoid, &deriv_sigmoid, 1);
    InputLoader input("input.csv");
    Dataset d = input.getData();
    
    net.train(200, d.getInputs(), d.getLabelsEncoded(), &logResults);
    std::cout<<" - output file is ready\n";
}
