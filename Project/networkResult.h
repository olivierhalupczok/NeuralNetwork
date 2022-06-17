
#include <vector>
#include <iostream>

#ifndef NETWORK_RESULT_H
#define NETWORK_RESULT_H

class NetworkResult
{
private:
    double loss;
    std::vector<double> predictions;

public:
    NetworkResult(double _loss, std::vector<double>& _predictions);
    double getLoss();
    std::vector<double> getPredictions();
    friend std::ostream& operator<<(std::ostream& stream, NetworkResult& result);
};

#endif