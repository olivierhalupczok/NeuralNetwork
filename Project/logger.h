/**
 * @file logger.h
 * @author Olivier Halupczok
 * @brief declarations of the logger library
 * @version 0.1
 * @date 2022-06-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <fstream>

#ifndef LOGGER_H
#define LOGGER_H

class Logger
{
private:
    /**
     * @brief Stream, to which logs are forwarded to
     *
     */
    std::ostream *outputStream;
    /**
     * @brief bool which determine if OutputStream was set yet
     *
     */
    bool _isOutputSet;
    /**
     * @brief Constant exception message displayed if the logger is called to log without specifying an output stream before
     *
     */
    const std::string OUTPUT_NOT_SET_EXCEPTION = "Output of the Logger has not been set yet";

public:
    /**
     * @brief Construct a new Logger object
     *
     */
    Logger();
    /**
     * @brief Set the Output Stream property
     *
     * @param stream which the logs will be forwarded to
     */
    void setOutputStream(std::ostream &stream);
    /**
     * @brief check if output is set, if not then throw an exception
     * 
     */
    void isOutputSet();
    /**
     * @brief Log data with << operator.
     *
     * @tparam T template to let data of many types to be logged
     * @param dataToLog Data to be printed with the logger
     * @return Logger& It returns the whole instance of the object
     */
    template <class T>
    Logger &operator<<(T &&dataToLog);
    /**
     * @brief operator with manip definition to let Logger handle io manipulators
     *
     * @param manip io manipulators like 'std::endl'
     * @return Logger& It returns instance of currently using object
     */
    Logger &operator<<(std::ostream &(*manip)(std::ostream &));
};

class CSV_Logger : public Logger
{
private:
    /**
     * @brief file to print CSV data
     *
     */
    std::ofstream logFile;
    char separator = '  ';
    size_t dataColumns;
    const std::string TOO_FEW_LABELS_EXCEPTION = "You have to insert at least 1 label";

public:
    /**
     * @brief Construct a new csv logger object
     *
     * @param path to the file
     */
    CSV_Logger(std::string path);
    /**
     * @brief Destroy the csv logger objectand close opened file
     *
     */
    ~CSV_Logger();
    /**
     * @brief prints labels into output csv file
     * 
     * @param labels 
     */
    void setLabels(std::vector<std::string>& labels);
    /**
     * @brief Set the Separator property
     * 
     * @param separator 
     */
    void setSeparator(const char separator);
};

#endif