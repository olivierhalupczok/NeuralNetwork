#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "dataset.h"
#include "inputLoader.h"

InputLoader::InputLoader(std::string _inputFilePath)
{
    if (_inputFilePath.length() <= 1)
    {
        throw std::invalid_argument(EMPTY_FILE_PATH_EXCEPTION);
    }

    inputFilePath = _inputFilePath;
    std::ifstream file(inputFilePath);
    std::string line;
    if(!file.good()) {
        throw std::invalid_argument("cannot find or open input file");
    }
    if (file.is_open())
    {

        //load csv data headers
        if (getline(file, line))
        {
            std::vector<std::string> headers;
            std::istringstream ss(line);
            while (!ss.eof())
            {
                std::string currentHeader;
                ss >> currentHeader;
                headers.push_back(currentHeader);
            }
            if (ss.fail())
            {
                throw std::invalid_argument("Couldn't parse data headers corrctly");
            }
            data = new Dataset(headers.size() - 1);
            data->setHeaders(headers);
            line = "";
        }
        //load csv data
        while (getline(file, line))
        {
            std::vector<double> dataFeatures;
            std::string label;
            std::istringstream ss(line);
            ss >> label;
            while (!ss.eof())
            {
                double buffer;
                ss >> buffer;
                if (ss.fail())
                {
                    throw std::invalid_argument("Invalid argument: Expected number, but got string instead, while reading input file");
                }
                dataFeatures.push_back(buffer);
            }
            data->addDataRow(label, dataFeatures);
        }
    }
}
InputLoader::~InputLoader() {
    delete data;
}
Dataset InputLoader::getData() {
    return *data;
}