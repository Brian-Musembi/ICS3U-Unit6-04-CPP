// Copyright (c) 2021 Brian Musembi, All rights reserved
//
// Created by Brian Musembi
// Created on June 2021
// This program finds the average of ten random numbers

#include <iostream>
#include <random>

template<int rows, int columns>
float AvgOfNumbers(int (&array)[rows][columns]) {
    // this function finds the average among the 2d list
    float total = 0;
    int counterRow = 0;
    int counterCol = 0;
    float average;

    for (int counterRow = 0; counterRow < rows; counterRow++) {
        for (int counterCol = 0; counterCol < rows; counterCol++) {
            total += array[counterRow][counterCol];
        }
    }
    average = total / (rows * columns);

    return average;
}

int main() {
    // this function generates random numbers and calls another function

    std::cout << "This program finds the average of ten random numbers"
              << std::endl;
    std::cout << "" << std::endl;

    // declaration
    const int rows = 4;  // constant
    const int columns = 5;  // constant
    int array[rows][columns];  // array
    int singleNumber;  // variable

    // process -- generate random numbers
    for (int rowCounter = 0; rowCounter < rows; rowCounter++) {
        std::cout;  // output
        for (int colCounter = 0; colCounter < columns; colCounter++) {
            std::random_device rseed;
            std::mt19937 rgen(rseed());  // mersenne_twister
            std::uniform_int_distribution<int> idist(0, 50);  // [1,100]
            singleNumber = idist(rgen);
            array[rowCounter][colCounter] = singleNumber;
            std::cout << singleNumber << ", ";  // output
        }
    std::cout << std::endl;  // output
    }

    // output
    float average = AvgOfNumbers(array);
    std::cout << "" << std::endl;
    std::cout << "The average of all the numbers is: " 
              << average << std::endl;
}
