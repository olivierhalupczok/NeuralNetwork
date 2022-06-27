#include <iostream>
#include <vector>
#include <set>

#ifndef DATASET_H
#define DATASET_H

class Dataset
{
private:
    /**
     * @brief inputs vector
     * 
     */
    std::vector<std::vector<double>> inputs;
    /**
     * @brief labels vector
     * 
     */
    std::vector<std::string> labels;
    /**
     * @brief set which stores unique labels
     * 
     */
    std::set<std::string> setOfLabels;
    /**
     * @brief number of data features in the file
     * 
     */
    size_t dataFeatures = 0;
    /**
     * @brief headers of the CSV file stored as the vector
     * 
     */
    std::vector<std::string> dataHeaders;
    /**
     * @brief EXCEPTION message when there is too few headers given
     * 
     */
    const std::string DATA_FEATURES_ZERO_OR_LESS_EXCEPTION = "You have to insert more than 0 data features";
    /**
     * @brief EXCEPTION message when data row is incomplete
     * 
     */
    const std::string DATA_FEATURES_TOO_FEW_EXCEPTION = "All lines in the input file have to have the same number of data features";

public:
/**
 * @brief Construct a new Dataset object
 * 
 * @param _dataFeatures 
 */
    Dataset(size_t _dataFeatures);
    /**
     * @brief add data to inputs and labels vectors and insert label to the set if it wasn't done beforehand
     * 
     * @param label 
     * @param _inputs 
     */
    void addDataRow(std::string label, std::vector<double> &_inputs);
    /**
     * @brief Get the Inputs object
     * 
     * @return std::vector<std::vector<double>> 
     */
    std::vector<std::vector<double>> getInputs();
    /**
     * @brief Get the Labels vector
     * 
     * @return std::vector<std::string> 
     */
    std::vector<std::string> getLabels();
    /**
     * @brief Get the Set Of Labels
     * 
     * @return std::set<std::string> set with unique labels
     */
    std::set<std::string> getSetOfLabels();
    /**
     * @brief Set the Headers
     * 
     * @param headers from the CSV file
     */
    void setHeaders(std::vector<std::string> &headers);
    /**
     * @brief Get the Headers vector
     * 
     * @return std::vector<std::string> 
     */
    std::vector<std::string> getHeaders();
    /**
     * @brief Get the Labels Encoded object
     * 
     * @return std::vector<double> codes of the label for every entity presented in the input file
     */
    std::vector<double> getLabelsEncoded();
};

#endif
