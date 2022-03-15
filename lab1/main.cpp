#include <iostream>

#include "my_v.h"

/**
 * @brief main program
 * Short program for MyV testing purposes.
 * 
 * @param argc number of arguments
 * @param argv arguments array
 * @return int 
 */
int main(int argc, char const *argv[])
{
    MyV test1(50);
    test1.set(5,10);
    test1.set(6,10);
    std::cout << test1.getValue(51);
}