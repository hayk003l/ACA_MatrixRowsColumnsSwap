#include "Matrix.hpp"
    
Matrix::Matrix(const int& row, const int& column) : _row(row), _column(column) {          
    _matrix = new int*[_row];

    for (int i = 0; i < _row; ++i) {
        _matrix[i] = new int[_column];
    }
}                       // parametrize constructor

Matrix::Matrix() {};                      // default constructor

Matrix::~Matrix() {                      // destructor

    for (int i = 0; i < _row; ++i) {
        delete[] _matrix[i];
        _matrix[i] = nullptr;
    }
    delete[] _matrix;
    _matrix = nullptr;
}

Matrix::Matrix (const Matrix& obj) {             // copy constructor
    
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


Matrix& Matrix::operator=(const Matrix& obj) {   // operator assignment

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

Matrix::Matrix(Matrix&& obj) : _row(obj._row), _column(obj._column) {
    _matrix = obj._matrix;
    obj._matrix = nullptr;
}

Matrix& Matrix::operator=(Matrix&& obj){
    if(this != &obj) {
        _row = obj._row;
        _column = obj._column;
        _matrix = obj._matrix;
        obj._matrix = nullptr;
    }
    return *this;
}

Matrix&  Matrix::operator++() {
    for (int i = 0; i < _row; ++i) {
        for (int j = 0; j < _column; ++j) {
            _matrix[i][j] += 3;
        }
    }
    return *this;
}

Matrix Matrix::operator++(int) {
    Matrix tempMatrix;

    for (int i = 0; i < _row; ++i) {
        for (int j = 0; j < _column; ++j) {
            tempMatrix._matrix[i][j] == _matrix[i][j];
        }
    }
    
    for (int i = 0; i < _row; ++i) {
        for (int j = 0; j < _column; ++j) {
            _matrix[i][j] += 3;
        }
    }

    return tempMatrix;
}


void Matrix::fillMatrix() const {
    for (int i = 0; i < _row; ++i) {
        for(int j = 0; j < _column; ++j) {
            _matrix[i][j] = rand() % 100;
        }
    }

}

void Matrix::printMatrix() const {
    for (int i = 0; i < _row; ++i) {
        for(int j = 0; j < _column; ++j) {
            std::cout << _matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Matrix::swapMatrixRowsColumns(Matrix& matrixOne) {
    
    for (int i = 0; i < matrixOne._column; ++i) {
        for (int j = 0; j < matrixOne._row; ++j) {
            this->_matrix[i][j] = matrixOne._matrix[j][i];
        }
    }
}