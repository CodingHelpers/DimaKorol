#include "matrix2.hpp"
#include <stdexcept>
#include <iostream>

namespace guap {

using std::to_string;

Matrix2::Matrix2()                         : _size(0), _matrix(NULL) {}
Matrix2::Matrix2(const Matrix2* copy_from) : Matrix2(*copy_from) {}
Matrix2::Matrix2(size_t size)              : _size(size), _matrix(NULL) {
    if(_size > 40) {
        throw std::logic_error("ERROR: Size range must be: 0 <= size <= 40");
    }
    Init();
}

Matrix2::Matrix2(const Matrix2& copy_from) {
    Assign(copy_from);
}

void
Matrix2::Assign(const Matrix2* from) {
    return Assign(*from);
}

void
Matrix2::Assign(const Matrix2& from) {
    if(this == &from) {
        return;
    }

    _size = from.size();
    InitMemory();

    for(size_t i = 0; i < _size; i++) {
        for(size_t j = 0; j < _size; j++) {
            _matrix[i][j] = from._matrix[i][j];
        }

    }
}

void
Matrix2::Resize(size_t new_size) {
    _size = new_size;
    Init();
}

void
Matrix2::Rotate(int n) {
    bool neg = (n < 0) ? true : false;

    n = abs(n) % 4;
    if(n == 0 || n == 4) {
        return;
    }

    n = (neg) ? 4 - n
              : n;

    for(int i = 0; i < n; i++) {
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
}

void
Matrix2::Print() {
    for(uint16_t i = 0; i < _size; i++) {
        for(uint16_t j = 0; j < _size; j++) {
            std::cout << _matrix[i][j] << " ";
        }
        std::cout << "\n\n";
    }
}

size_t
Matrix2::size() const {
    return _size;
}

void
Matrix2::Init() {
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
Matrix2::InitMemory() {
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
Matrix2::Free() {
    for(uint i = 0; i < _size; i++) {
        delete[] _matrix[i];
    }

    if(_matrix != NULL) {
        delete[] _matrix;
    }
}

int
Matrix2::ColRowSum(size_t n) {
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

// Установка значения элемента матрицы
void
Matrix2::Set(int i, int j, int value) {
    if(i < 0 || i >= _size || j < 0 || j >= _size) {
        throw std::out_of_range("Matrix boundary error");
    }
    _matrix[i][j] = value;
}

// Получение значения элемента матрицы
int
Matrix2::Get(int i, int j) {
    if(i < 0 || i >= _size || j < 0 || j >= _size) {
        throw std::out_of_range("Matrix boundary error");
    }
    return _matrix[i][j];
}


Matrix2&
Matrix2::operator= (Matrix2& b) {
    Assign(b);
    return *this;
}

Matrix2 operator+ (const Matrix2& a, const Matrix2& b) {
    if(a.size() != b.size()) {
        throw std::logic_error("a.size() != b.size()");
    }

    size_t size  = a.size();

    Matrix2 c;
    c.Resize(size);

    for(uint i = 0; i < size; i++) {
        for(uint j = 0; j < size; j++) {
            c._matrix[i][j] = a._matrix[i][j] + b._matrix[i][j];
        }
    }

    return c;
}

Matrix2 operator- (const Matrix2& a, const Matrix2& b) {
    if(a.size() != b.size()) {
        throw std::logic_error("a.size() != b.size()");
    }

    size_t size  = a.size();

    Matrix2 c;
    c.Resize(size);

    for(uint i = 0; i < size; i++) {
        for(uint j = 0; j < size; j++) {
            c._matrix[i][j] = a._matrix[i][j] - b._matrix[i][j];
        }
    }

    return c;
}

Matrix2 operator* (const Matrix2& a, const Matrix2& b) {
    if(a.size() != b.size()) {
        throw std::logic_error("a.size() != b.size()");
    }

    size_t size  = a.size();

    Matrix2 c;
    c.Resize(size);

    for(uint i = 0; i < size; i++) {
        for(uint j = 0; j < size; j++) {
            int c_ij = 0;
            for(uint k = 0; k < size; k++) {
                c_ij += a._matrix[i][k] + a._matrix[k][j];
            }
            c.Set(i,j,c_ij);
        }
    }

    return c;
}

Matrix2 operator* (const Matrix2& a, int b) {
    size_t size  = a.size();

    Matrix2 c;
    c.Resize(size);

    for(uint i = 0; i < size; i++) {
        for(uint j = 0; j < size; j++) {
            c._matrix[i][j] = a._matrix[i][j] * b;
        }
    }

    return c;
}

Matrix2 operator* (int b, const Matrix2& a) {
    return a*b;
}

int
Matrix2::Determinant() {
    if(!_matrix) {
        throw std::logic_error("Matrix must be initialized first");
    }

    if(_size < 1) {
        throw std::logic_error("Matrix size mast be >= 1 to calculate discriminant");
    }


    return Determinant(_matrix, _size);
}

int
Matrix2::Determinant(int** matrix, const size_t size) {
    if(size == 1) {
        return matrix[0][0];
    }

    if(size == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
    }

    int64_t d = 0;

    int* p[size-1];
    for(uint i = 0; i < size; i++) {
        uint j;
        for(j = 0; j < size-1; j++) {
            if(j < i) {
                p[j] = matrix[j];
            } else {
                p[j] = matrix[j+1];
            }
        }

        int k = ((i+j) % 2) ? -1 : 1;
        d += k * Determinant(p, size-1) * matrix[i][size-1];
    }

    return d;
}

}
