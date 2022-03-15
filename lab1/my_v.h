/**
 * @file my_v.h
 * @author Olivier Halupczok
 * @brief 
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef MY_V_H
#define MY_V_H

class MyV
{
    private:
    /**
     * @brief Points to the array, that will be defined in the constructor
     * 
     */
    int *arrayPointer;
    /**
     * @brief Check if index is valid, if it is not, then throw an exception
     * 
     * @param index 
     */
    void checkIndex(const int index);
    /**
     * @brief array size
     * 
     */
    int arraySize;
    public:
    /**
     * @brief Destroy the My V object's pointers
     * 
     */
    ~MyV(); 
    /**
     * @brief Construct a new My V object with default array size of 10.
     * 
     */
    MyV(); 
    /**
     * @brief Construct a new My V object, with array size given as a parameter.
     * 
     * @param arrSize integer which will be used to define new array's size
     */
    MyV(int arrSize);
    /**
     * @brief sets value for a given index in the array
     * 
     * @param index index to save an integer
     * @param value value to be saved for the given index
     */
    void set(int index, int value);
    /**
     * @brief Get the Value from array
     * 
     * @param index to get the value from
     * @return int int for given index from the array
     */
    int getValue(int index);
};

#endif