#include <iostream>
#include <vector>

#include "dataset.h"

#ifndef INPUT_LOADER_H
#define INPUT_LOADER_H

class InputLoader
{
private:
/**
 * @brief path to the input file
 * 
 */
    std::string inputFilePath;
    /**
     * @brief pointer to the data object
     * 
     */
    Dataset* data;
    /**
     * @brief EXCEPTION MSG when constructor argument is empty
     * 
     */
    const std::string EMPTY_FILE_PATH_EXCEPTION = "Given path of input file cannot be empty";
    
public:
    /**
     * @brief Construct a new Input Loader object
     * 
     * @param _inputFilePath path to the input file
     */
    InputLoader(std::string _inputFilePath);
    /**
     * @brief Destroy the Input Loader object and its pointers
     * 
     */
    ~InputLoader();
    /**
     * @brief Get the Data object
     * 
     * @return Dataset 
     */
    Dataset getData();
};

#endif
