#include <iostream>
#include <vector>

#include "dataset.h"

#ifndef INPUT_LOADER_H
#define INPUT_LOADER_H

class InputLoader
{
private:
    std::string inputFilePath;
    Dataset* data;
    const std::string EMPTY_FILE_PATH_EXCEPTION = "Given path of input file cannot be empty";
    
public:
    InputLoader(std::string _inputFilePath);
    ~InputLoader();
    Dataset getData();
};

#endif
