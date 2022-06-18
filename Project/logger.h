#include <iostream>
#include <fstream>

#ifndef LOGGER_H
#define LOGGER_H

class Logger
{
private:
    std::ostream *outputStream;
    bool isOutputSet;
    const std::string OUTPUT_NOT_SET_EXCEPTION = "Output of the Logger has not been set yet";

public:
    Logger();
    template <class T>
    void log(const T &&dataToLog);
    void setOutputStream(std::ostream &stream);
    template <class T>
    Logger &operator<<(T &&dataToLog);
    Logger &operator<<(std::ostream &(*manip)(std::ostream &));
};

class CSV_Logger : public Logger
{
private:
    std::ofstream logFile;
public:
    CSV_Logger(std::string path);
    ~CSV_Logger();
};


#endif