/**
 * @file logger.cpp
 * @author Olivier Halupczok
 * @brief cpp file with the definitions of the logger library
 * @version 0.1
 * @date 2022-06-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>

#include "networkResult.h"
#include "logger.h"

Logger::Logger()
{
    _isOutputSet = false;
}
void Logger::setOutputStream(std::ostream &stream)
{
    outputStream = &stream;
    _isOutputSet = true;
}
void Logger::isOutputSet()
{
    if (!_isOutputSet)
    {
        throw std::invalid_argument(OUTPUT_NOT_SET_EXCEPTION);
    }
}
template <class T>
Logger &Logger::operator<<(T &&dataToLog)
{
    isOutputSet();
    *outputStream << std::forward<T>(dataToLog);
    return *this;
}

Logger &Logger::operator<<(std::ostream &(*manip)(std::ostream &))
{
    isOutputSet();
    *outputStream << manip;
    return *this;
}

template Logger &Logger::operator<< <int>(int &&dataToLog);
template Logger &Logger::operator<< <std::string>(std::string &&dataToLog);
template Logger &Logger::operator<< <size_t>(size_t &&dataToLog);
template Logger &Logger::operator<< <char>(char &&dataToLog);
template Logger &Logger::operator<< <long long int>(long long int &&dataToLog);
template Logger &Logger::operator<< <NetworkResult &>(NetworkResult &dataToLog);
// template Logger &Logger::operator<< <NetworkResult&>(NetworkResult &dataToLog);

CSV_Logger::CSV_Logger(std::string path) : Logger()
{
    logFile.open(path);
    std::cout << path;
    setOutputStream(logFile);
};

CSV_Logger::~CSV_Logger()
{
    logFile.close();
}
void CSV_Logger::setLabels(std::vector<std::string> &labels)
{
    dataColumns = labels.size();
    if (!dataColumns)
    {
        throw std::invalid_argument(TOO_FEW_LABELS_EXCEPTION);
    }

    for (size_t i = 0; i < dataColumns; i++)
    {
        *this << (!i ? separator : (char)"") << labels[i];
    }
}
void CSV_Logger::setSeparator(char _separator) {
    separator=_separator;
}