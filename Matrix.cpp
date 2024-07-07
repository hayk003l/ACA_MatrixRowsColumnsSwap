#include "Matrix.hpp"
    
Matrix::Matrix(const int& row, const int& column) : _row(row), _column(column) {          
    std::cout << "ctor" << std::endl;
    _matrix = new int*[_row];

    for (int i = 0; i < _row; ++i) {
        _matrix[i] = new int[_column];
    }
}                       // parametrize constructor

Matrix::Matrix() {std::cout << "def ctor" << std::endl;};                      // default constructor

Matrix::~Matrix() {                      // destructor

    for (int i = 0; i < _row; ++i) {
        delete[] _matrix[i];
        _matrix[i] = nullptr;
    }
    delete[] _matrix;
    _matrix = nullptr;
}

Matrix::Matrix (const Matrix& obj) {             // copy constructor
    std::cout << "copy ctor" << std::endl;
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
    std::cout << "move ctor" << std::endl;
    _matrix = obj._matrix;
    obj._matrix = nullptr;
    obj._row = 0;
    obj._column = 0;
}

Matrix& Matrix::operator=(Matrix&& obj){
    std::cout << "move assignment" << std::endl;
    if(this != &obj) {
        _row = obj._row;
        _column = obj._column;
        _matrix = obj._matrix;
        obj._matrix = nullptr;
        obj._row = 0;
        obj._column = 0;
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

Matrix Matrix::operator+(const Matrix& obj) {
    Matrix temp(_row, _column);
    for (int i = 0; i < _row; ++i) {
        for (int j = 0; j < _column; ++j) {
            temp._matrix[i][j] = this->_matrix[i][j] + obj._matrix[i][j];
        }
    }
    return temp;
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

int& Matrix::at(const int& row, const int& column) {
    try {
        if (row < 0 || row > _row || column < 0 || column > _column) {
            throw std::out_of_range("Error! Wrong cordinates.");
        }
    }
    catch (const std::out_of_range& err) {
        std::cout << err.what() << std::endl;
    }
    return _matrix[row][column];
}