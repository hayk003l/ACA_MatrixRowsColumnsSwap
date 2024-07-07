#include <iostream>

#include "Matrix.hpp"



int main() {
    // unsigned int row = 0;
    // unsigned int column = 0;

    // std::cout << "Enter the number of MATRIX rows." << std::endl;
    // std::cin >> row;

    // std::cout << "Enter the number of MATRIX columns." << std::endl;
    // std::cin >> column;

    // Matrix matrixOne(row, column);
    // matrixOne.fillMatrix();

    // std::cout << "Matrix before transpose." << std::endl;
    // matrixOne.printMatrix();

    // Matrix matrixTwo(column, row);
    // matrixTwo.swapMatrixRowsColumns(matrixOne);

    // std::cout << "Matrix after transpose." << std::endl;
    // matrixTwo.printMatrix();

    // Matrix matrixThree = matrixOne;

    // std::cout << "Third matrix." << std::endl;
    // matrixThree.printMatrix();

    // matrixThree = matrixTwo;

    // std::cout << "Third matrix after assignment." << std::endl;
    // matrixThree.printMatrix();

    // Matrix matrixObj(row, column);
    
    // matrixObj.fillMatrix();

    // matrixObj.printMatrix();

    // std::cout << std::endl;
    // matrixObj++;
    // matrixObj.printMatrix();
   

    // std::cout << std::endl;
    // ++matrixObj;
    // matrixObj.printMatrix();

    Matrix obj1(3,3);
    obj1.fillMatrix();
    obj1.printMatrix();

    try {
        std::cout << obj1.at(4, 1) << std::endl;
    }
    catch (const std::out_of_range& err) {
        std::cout << err.what() << std::endl;
    }


    return 0;
}
