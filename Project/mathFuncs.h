/**
 * @file mathFuncs.h
 * @author Olivier Halupczok
 * @brief
 * @version 0.1
 * @date 2022-06-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef MATH_FUNCS_H
#define MATH_FUNCS_H

/**
 * @brief return value of sigmoid function (1/(1 + exp(-arg)))
 *
 * @param arg
 * @return double
 */
double sigmoid(double arg);
/**
 * @brief return dot product of two two components vectors
 *
 * @param vector1
 * @param vector2
 * @return double dot product
 */
double dotProductOf2Vectors(std::vector<double> vector1, std::vector<double> vector2);

#endif