#include <iostream>
#include <vector>
#include <set>

#include "dataset.h"

Dataset::Dataset(size_t _dataFeatures)
{
    if (!_dataFeatures)
    {
        throw std::invalid_argument(DATA_FEATURES_ZERO_OR_LESS_EXCEPTION);
    }
    dataFeatures = _dataFeatures;
}
void Dataset::addDataRow(std::string label, std::vector<double> &_inputs)
{
    if (_inputs.size() != dataFeatures)
    {
        throw std::invalid_argument(DATA_FEATURES_TOO_FEW_EXCEPTION);
    }
    setOfLabels.insert(label);
    labels.push_back(label);
    inputs.push_back(_inputs);
}
std::vector<std::vector<double>> Dataset::getInputs()
{
    return inputs;
}
std::vector<std::string> Dataset::getLabels()
{
    return labels;
}
std::set<std::string> Dataset::getSetOfLabels()
{
    return setOfLabels;
}
void Dataset::setHeaders(std::vector<std::string> &headers)
{
    dataHeaders = headers;
}
std::vector<std::string> Dataset::getHeaders()
{
    return dataHeaders;
}
std::vector<double> Dataset::getLabelsEncoded()
{
    std::vector<double> encoded;
    for (auto &&i : labels)
    {
        double currentID = std::distance(setOfLabels.begin(), setOfLabels.find(i));
        encoded.push_back(currentID);
    }
    return encoded;
}