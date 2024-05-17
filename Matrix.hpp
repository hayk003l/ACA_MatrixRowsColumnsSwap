#ifndef __MATRIX__
#define __MATRIX__
#include <iostream>

class Matrix {

public:
    Matrix(const int& row, const int& column);
    Matrix();
    virtual ~Matrix();
    Matrix (const Matrix& obj);
    Matrix& operator=(const Matrix& obj);
    Matrix(Matrix&& obj);
    Matrix& operator=(Matrix&& obj);
    Matrix& operator++();
    Matrix operator++(int);

public:
    void fillMatrix() const;
    void printMatrix() const;
    void swapMatrixRowsColumns(Matrix& matrixOne);


private:
    int** _matrix = nullptr;
    unsigned int _row = 0;
    unsigned int _column = 0;
};

#endif // __MATRIX__