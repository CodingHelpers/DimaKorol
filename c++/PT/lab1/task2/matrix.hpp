#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <stdint.h>
#include <stddef.h>

namespace guap {

class Matrix {
public:
    // Конструктор матрицы, принимает размер
    Matrix(size_t size);
   ~Matrix();

    /* Поворот матрицы на 90 градусов */
    void Rotate();

    /* Вывод матрицы на экран */
    void Print();

    size_t size() const;

protected:
    void Init();
    void InitMemory();
    void Free();

    int ColRowSum(size_t n);

    size_t _size;
    int** _matrix;
};

}

#endif
