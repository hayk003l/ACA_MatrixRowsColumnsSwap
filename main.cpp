#include <iostream>

class Matrix {
    public:
    Matrix(const int& row, const int& column) : _row(row), _column(column) {              // parametrize constructor
        _matrix = new int*[_row];

        for (int i = 0; i < _row; ++i) {
            _matrix[i] = new int[_column];
        }
    }

    Matrix() = default;                      // default constructor

    virtual ~Matrix() {                      // destructor
        for (int i = 0; i < _row; ++i) {
            delete[] _matrix[i];
            _matrix[i] = nullptr;
        }
        delete[] _matrix;
        _matrix = nullptr;
    }
    
    Matrix (const Matrix& obj) {             // copy constructor
        for (int i = 0; i < _row; ++i) {
            for (int j = 0; j < _column; ++j) {
                this->_matrix[i][j] = obj._matrix[i][j];
            }
        }
        this->_row = obj._row;
        this->_column = obj._column;
    }


    Matrix& operator=(const Matrix& obj) {   // operator assignment
        if (_row == obj._row && _column == obj._column) {
            for (int i = 0; i < _row; ++i) {
                for (int j = 0; j < _column; ++j) {
                        this->_matrix[i][j] = obj._matrix[i][j];
                    }
                }
            this->_row = obj._row;
            this->_column = obj._column;
            return *this;
        }
        return *this;
    }


    Matrix operator+(const Matrix& obj) const {
        
        Matrix _temp(_row, _column);
        
        if (_row == obj._row && _column == obj._column) {
            for (int i = 0; i < _row; ++i) {
                for (int j = 0; j < _column; ++j) {
                    _temp._matrix[i][j] += obj._matrix[i][j] + _matrix[i][j];
                }
            }
            return _temp;
        }
        else {
            for (int i = 0; i < _row; ++i) {
                for (int j = 0; j < _column; ++j) {
                    _temp._matrix[i][j] = _matrix[i][j];
                }
            }
        }
        return _temp;
    }

    void fillMatrix() {
        for (int i = 0; i < _row; ++i) {
            for(int j = 0; j < _column; ++j) {
                _matrix[i][j] = rand() % 100;
            }
        }

    }
    
    void printMatrix() {
        for (int i = 0; i < _row; ++i) {
            for(int j = 0; j < _column; ++j) {
                std::cout << _matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void swapMatrixRowsColumns(Matrix* matrixOne) {
        
        for (int i = 0; i < matrixOne->_column; ++i) {
            for (int j = 0; j < matrixOne->_row; ++j) {
                this->_matrix[i][j] = matrixOne->_matrix[j][i];
            }
        }
    }

    private:
    int** _matrix = nullptr;
    unsigned int _row = 0;
    unsigned int _column = 0;

};


int main() {
    unsigned int row = 0;
    unsigned int column = 0;

    std::cout << "Enter the number of MATRIX rows." << std::endl;
    std::cin >> row;

    std::cout << "Enter the number of MATRIX columns." << std::endl;
    std::cin >> column;

    Matrix* matrixOne = new Matrix(row, column);
    matrixOne->fillMatrix();

    std::cout << "Matrix before transpose." << std::endl;
    matrixOne->printMatrix();

    Matrix* matrixTwo = new Matrix(column, row);
    matrixTwo->swapMatrixRowsColumns(matrixOne);

    std::cout << "Matrix after transpose." << std::endl;

    matrixTwo->printMatrix();


    std::cout << "Matrix addition." << std::endl;

    // matrixOne = matrixOne + matrixTwo;

    Matrix* matrixThree = matrixOne;

    std::cout << "Third matrix." << std::endl;

    matrixThree->printMatrix();

    matrixThree = matrixTwo;

    std::cout << "Third matrix after assignment." << std::endl;

    matrixThree->printMatrix();
 
    delete matrixOne;
    delete matrixTwo;
    matrixOne = nullptr;
    matrixTwo = nullptr;

    return 0;
}
