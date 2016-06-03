#include "matrix.hpp"
#include <iostream>
#include <stdexcept>

namespace guap {

Matrix::Matrix(size_t size) :
    _size(size),
    _matrix(NULL)
{
    if(_size > 40) {
        throw std::logic_error("ERROR: Size range must be: 0 <= size <= 40");
    }
    Init();
}

Matrix::~Matrix() {
    Free();
}

void
Matrix::Init() {
    InitMemory();

    // Инициализация значений в матрице
    for(uint i = 0; i < _size; i++) {
        for(uint j = 0; j < _size; j++) {
            if(i == j) {
                _matrix[i][j] = 0;
            } else {
                _matrix[i][j] = (i+1) + (j+1);
            }
        }
    }

    // Инициализация главной диагонали
    for(uint i = 0; i < _size; i++) {
        _matrix[i][i] = ColRowSum(i);
    }
}

void
Matrix::Rotate() {
    for(uint y = 0; y < _size/2; y++) {
        size_t s = _size;
        for(uint x = 0; x < s/2; x++) {
            int temp             = _matrix[s-1-x][y];
            _matrix[s-1-x][y]     = _matrix[s-1-y][s-1-x];
            _matrix[s-1-y][s-1-x] = _matrix[x]    [s-1-y];
            _matrix[x]    [s-1-y] = _matrix[y]    [x];
            _matrix[y]    [x]     = temp;
        }
    }
}

void
Matrix::Print() {
    for(uint16_t i = 0; i < _size; i++) {
        for(uint16_t j = 0; j < _size; j++) {
            std::cout << _matrix[i][j] << " ";
        }
        std::cout << "\n\n";
    }
}

size_t
Matrix::size() const {
    return _size;
}

void
Matrix::InitMemory() {
    // Проверка на случай, если память уже зарезервирована, во избежание утечки памяти
    if(_matrix != NULL) {
        Free();
    }

    // Выделение памяти для указателей
    _matrix = new int*[_size];

    // Выделение строк
    for(size_t i = 0; i < _size; i++) {
        _matrix[i] = new int[_size];
    }
}

void
Matrix::Free() {
    for(uint i = 0; i < _size; i++) {
        delete[] _matrix[i];
    }

    if(_matrix != NULL) {
        delete[] _matrix;
    }
}

int
Matrix::ColRowSum(size_t n) {
    uint16_t sum = 0;

    // Проход по строкам
    for(uint y = 0; y < _size; y++) {
        sum += _matrix[y][n];
    }

    // Проход по столбцам
    for(uint x = 0; x < _size; x++) {
        sum += _matrix[n][x];
    }

    return sum;
}


}
