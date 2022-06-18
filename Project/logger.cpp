#include <iostream>
#include <sstream>
#include <fstream>

#include "networkResult.h"
#include "logger.h"

Logger::Logger()
{
    isOutputSet = false;
}
void Logger::setOutputStream(std::ostream &stream)
{
    outputStream = &stream;
    isOutputSet = true;
}

template <class T>
Logger &Logger::operator<<(T &&dataToLog)
{
    if (!isOutputSet)
    {
        throw std::invalid_argument(OUTPUT_NOT_SET_EXCEPTION);
    }
    *outputStream << std::forward<T>(dataToLog);
    return *this;
}

Logger &Logger::operator<<(std::ostream &(*manip)(std::ostream &))
{
    if (!isOutputSet)
    {
        throw std::invalid_argument(OUTPUT_NOT_SET_EXCEPTION);
    }
    *outputStream << manip;
    return *this;
}

template Logger &Logger::operator<< <int>(int &&dataToLog);
template Logger &Logger::operator<< <std::string>(std::string &&dataToLog);
template Logger &Logger::operator<< <size_t>(size_t &&dataToLog);
template Logger &Logger::operator<< <char>(char &&dataToLog);
template Logger &Logger::operator<< <long long int>(long long int &&dataToLog);
template Logger &Logger::operator<< <NetworkResult&>(NetworkResult &dataToLog);
// template Logger &Logger::operator<< <NetworkResult&>(NetworkResult &dataToLog);

CSV_Logger:: CSV_Logger(std::string path) : Logger() {
    logFile.open(path);
    std::cout<<path;
    setOutputStream(logFile);
};

CSV_Logger::~CSV_Logger() {
    logFile.close();
}