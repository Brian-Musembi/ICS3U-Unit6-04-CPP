// Copyright (c) 2021 Brian Musembi, All rights reserved
//
// Created by Brian Musembi
// Created on June 2021
// This program finds the average of ten random numbers

#include <iostream>
#include <random>


template<int rows, int columns>
float average2D(int (&array)[rows][columns]) {
    // this function finds the average

    float total = 0;
    int numOfRows = 0;
    int numOfCols = 0;
    float average;

    for (int numOfRows = 0; numOfRows < rows; numOfRows++) {
        for (int numOfCols = 0; numOfCols < rows; numOfCols++) {
            total += array[numOfRows][numOfCols];
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

    // variables
    int randomNum;
    const int rows = 4;
    const int columns = 5;
    int array[rows][columns];

    // creating 2D array
    for (int rowCounter = 0; rowCounter < rows; rowCounter++) {
        std::cout;
        for (int colCounter = 0; colCounter < columns; colCounter++) {
            std::random_device rseed;
            std::mt19937 rgen(rseed());
            std::uniform_int_distribution<int> idist(0, 50);
            randomNum = idist(rgen);
            array[rowCounter][colCounter] = randomNum;
            std::cout << randomNum << ", ";
        }
    std::cout << std::endl;
    }

    // output
    float average = average2D(array);
    std::cout << "" << std::endl;
    std::cout << "The average of all the numbers is: "
              << average << std::endl;
}
