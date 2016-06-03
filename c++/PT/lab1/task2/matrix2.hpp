#ifndef MATRIX2_H
#define MATRIX2_H
#include <stddef.h>

namespace guap {
class Matrix2 {
public:
    Matrix2();
    Matrix2(size_t size);

    // Копирующие конструкторы
    Matrix2(const Matrix2& copy_from);
    Matrix2(const Matrix2* copy_from);

    // Методы копирования матрицы
    void Assign(const Matrix2& assign_from);
    void Assign(const Matrix2* assign_from);

    // Изменение размера матрицы
    void Resize(size_t new_size);

    // Вращение матрицы
    void Rotate(int n);

    // Установка значения элемента матрицы
    void Set(int i, int j, int value);

    // Получение значения элемента матрицы
    int Get(int i, int j);

    // Вывод матрицы на экран
    void Print();

    // Операторы присвоения
    Matrix2& operator= (Matrix2& b);
    Matrix2& operator= (int b);

    // Арифметические операторы
    friend Matrix2 operator+ (const Matrix2& a, const Matrix2& b);
    friend Matrix2 operator- (const Matrix2& a, const Matrix2& b);
    friend Matrix2 operator* (const Matrix2& a, const Matrix2& b);
    friend Matrix2 operator* (const Matrix2& a, int b);
    friend Matrix2 operator* (int b, const Matrix2& a);

    // Вычисление детерминанта
    int Determinant();

    size_t size() const;

protected:
    void Init();
    void InitMemory();
    void Free();

    int ColRowSum(size_t n);

    int Determinant(int** matrix, const size_t size);

    size_t _size;
    int** _matrix;
};

}

#endif
