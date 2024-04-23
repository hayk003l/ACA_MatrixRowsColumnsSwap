#include <iostream>

class Matrix {
    public:
    
    Matrix(const int& row, const int& column) : _row(row), _column(column) {          
        _matrix = new int*[_row];

        for (int i = 0; i < _row; ++i) {
            _matrix[i] = new int[_column];
        }
    }                       // parametrize constructor

    Matrix() {};                      // default constructor

    virtual ~Matrix() {                      // destructor

        for (int i = 0; i < _row; ++i) {
            delete[] _matrix[i];
            _matrix[i] = nullptr;
        }
        delete[] _matrix;
        _matrix = nullptr;
    }
    
    Matrix (const Matrix& obj) {             // copy constructor
        
        this->_row = obj._row;
        this->_column = obj._column;
        _matrix = new int*[_row];

        for (int i = 0; i < _row; ++i) {
            _matrix[i] = new int[_column];
        }
        for (int i = 0; i < _row; ++i) {
            for (int j = 0; j < _column; ++j) {
                this->_matrix[i][j] = obj._matrix[i][j];
            }
        }
        this->_row = obj._row;
        this->_column = obj._column;
    }


    Matrix& operator=(const Matrix& obj) {   // operator assignment
    
        if (this != &obj) {
       

        if (_row != obj._row || _column != obj._column) {
            
            for (int i = 0; i < _row; ++i) {
                delete[] _matrix[i];
                _matrix[i] = nullptr;
            }
            delete[] _matrix;
            _matrix = nullptr;
            
            this->_row = obj._row;
            this->_column = obj._column;

            _matrix = new int*[_row];

            for (int i = 0; i < _row; ++i) {
                _matrix[i] = new int[_column];
            }
        }
        
        for (int i = 0; i < _row; ++i) {
            for (int j = 0; j < _column; ++j) {
                _matrix[i][j] = obj._matrix[i][j];
            }
        }
        
        }
        
        return *this;
    }



    void fillMatrix() const {
        for (int i = 0; i < _row; ++i) {
            for(int j = 0; j < _column; ++j) {
                _matrix[i][j] = rand() % 100;
            }
        }

    }
    
    void printMatrix() const {
        for (int i = 0; i < _row; ++i) {
            for(int j = 0; j < _column; ++j) {
                std::cout << _matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void swapMatrixRowsColumns(Matrix& matrixOne) {
        
        for (int i = 0; i < matrixOne._column; ++i) {
            for (int j = 0; j < matrixOne._row; ++j) {
                this->_matrix[i][j] = matrixOne._matrix[j][i];
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

    Matrix matrixOne(row, column);
    matrixOne.fillMatrix();

    std::cout << "Matrix before transpose." << std::endl;
    matrixOne.printMatrix();

    Matrix matrixTwo(column, row);
    matrixTwo.swapMatrixRowsColumns(matrixOne);

    std::cout << "Matrix after transpose." << std::endl;
    matrixTwo.printMatrix();

    Matrix matrixThree = matrixOne;

    std::cout << "Third matrix." << std::endl;
    matrixThree.printMatrix();

    matrixThree = matrixTwo;

    std::cout << "Third matrix after assignment." << std::endl;
    matrixThree.printMatrix();


    return 0;
}
