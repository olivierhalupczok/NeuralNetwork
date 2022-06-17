
#include <vector>
#include <iostream>

#include "networkResult.h"

NetworkResult::NetworkResult(double _loss, std::vector<double>& _predictions)
{
    loss = _loss;
    predictions = _predictions;
}
double NetworkResult::getLoss()
{
    return loss;
}
std::vector<double> NetworkResult::getPredictions()
{
    return predictions;
}
std::ostream& operator<<(std::ostream& stream, NetworkResult& result) {
    stream << result.getLoss();
    return stream;
}
