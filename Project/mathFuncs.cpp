#include <math.h>
#include <vector>
#include <iostream>

#include "mathFuncs.h"

const std::string INV_ARG_MSG = "Invalid argument: ";
const std::string INV_ARG_DOT_MSG = INV_ARG_MSG + "Dot product has to be executed with 2 vectors of the same length";

double sigmoid(double arg)
{
    return 1 / (1 + std::exp(-arg));
}

double dotProductOf2Vectors(std::vector<double> vector1, std::vector<double> vector2)
{

    if (vector1.size() != vector2.size())
    {
        throw std::invalid_argument(INV_ARG_DOT_MSG);
    }

    double buffer = 0;

    for (size_t i = 0; i < vector1.size(); i++)
    {
        buffer += vector1[i] * vector2[i];
    }
    return buffer;
}