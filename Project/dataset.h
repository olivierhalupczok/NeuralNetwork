#include <iostream>
#include <vector>
#include <set>

#ifndef DATASET_H
#define DATASET_H

class Dataset
{
private:
    std::vector<std::vector<double>> inputs;
    std::vector<std::string> labels;
    std::set<std::string> setOfLabels;
    size_t dataFeatures = 0;
    std::vector<std::string> dataHeaders;
    const std::string DATA_FEATURES_ZERO_OR_LESS_EXCEPTION = "You have to insert more than 0 data features";
    const std::string DATA_FEATURES_TOO_FEW_EXCEPTION = "All lines in the input file have to have the same number of data features";

public:
    Dataset(size_t _dataFeatures);
    void addDataRow(std::string label, std::vector<double> &_inputs);
    std::vector<std::vector<double>> getInputs();
    std::vector<std::string> getLabels();
    std::set<std::string> getSetOfLabels();
    void setHeaders(std::vector<std::string> &headers);
    std::vector<std::string> getHeaders();
    std::vector<double> getLabelsEncoded();
};

#endif
