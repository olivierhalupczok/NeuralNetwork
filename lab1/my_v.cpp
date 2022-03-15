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
#include <iostream>

#include "my_v.h"
constexpr int DEFAULT_ARRAY_SIZE = 10;

MyV::MyV() {
    MyV(DEFAULT_ARRAY_SIZE);
};
MyV::~MyV() {
    delete[] arrayPointer;
}
MyV::MyV(const int arrSize) {
    arrayPointer = new int[arrSize];
    arraySize = arrSize;
}
void MyV::set(int index, int value) {
    checkIndex(index);
    arrayPointer[index] = value;
}
int MyV::getValue(int index) {
    checkIndex(index);
    return arrayPointer[index];
}
void MyV::checkIndex(const int index) {
    if (index >= arraySize || index < 0)
    {
        throw std::invalid_argument("Invalid index: Given index exceeds array's range");
    }
}