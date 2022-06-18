/**
 * @file networkResult.h
 * @author Olivier Halupczok
 * @brief 
 * @version 0.1
 * @date 2022-06-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <vector>
#include <iostream>

#ifndef NETWORK_RESULT_H
#define NETWORK_RESULT_H

class NetworkResult
{
private:
    /**
     * @brief loss of the given epoch
     *
     */
    double loss;
    /**
     * @brief predictions of the given epoch
     *
     */
    std::vector<double> predictions;

public:
    /**
     * @brief Construct a new Network Result object
     *
     * @param _loss loss of the given epoch
     * @param _predictions predictions of the given epoch
     */
    NetworkResult(double _loss, std::vector<double> &_predictions);
    /**
     * @brief Get the Loss property
     *
     * @return double
     */
    double getLoss();
    /**
     * @brief Get the Predictions property
     *
     * @return std::vector<double>
     */
    std::vector<double> getPredictions();
    /**
     * @brief print loss to the stream
     *
     * @param stream stream which the data is printed into
     * @param result result of the given epoch
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &stream, NetworkResult &result);
};

#endif