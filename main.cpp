#include <iostream>

class Matrix {
    public:
    Matrix(const int& row, const int& column) : _row(row), _column(column) {
        _matrix = (int**)malloc(_row * sizeof(int*));

        for (int i = 0; i < _row; ++i) {
            _matrix[i] = (int*)malloc(_column * sizeof(int));
        }
    }
    virtual ~Matrix() {
        for (int i = 0; i < _row; ++i) {
            free(_matrix[i]);
            _matrix[i] = NULL;
        }
        free(_matrix);
        _matrix = NULL;
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

    delete matrixOne;
    delete matrixTwo;
    matrixOne = nullptr;
    matrixTwo = nullptr;

    return 0;
}
