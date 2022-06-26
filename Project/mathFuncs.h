/**
 * @file mathFuncs.h
 * @author Olivier Halupczok
 * @brief library with math functions used in the program
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
 * @brief return value of derivative of sigmoid
 *
 * @param arg
 * @return double
 */
double deriv_sigmoid(double arg);
/**
 * @brief return dot product of two two components vectors
 *
 * @param vector1
 * @param vector2
 * @return double dot product
 */
double dotProductOf2Vectors(std::vector<double> vector1, std::vector<double> vector2);
/**
 * @brief calculate mean squarred error of the neural network
 *
 * @param outputTrue labels of dataargumentsHandler
 * @param outputPredicted guesses of network
 * @return double return mean squarred error
 */
double calc_mse_loss(std::vector<double> outputTrue, std::vector<double> outputPredicted);
/**
 * @brief it calculates value of the derivative of the Loss' function of the whole network divided by the derivative of output value's(of the entire network) function
 *
 * @param label labels of the learning dataset
 * @param output output value of net
 * @return double calculated derivative
 */
double lossDeriv_outDeriv(double label, double output);

#endif