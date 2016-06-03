#include <iostream>
#include <stdint.h>
#include <assert.h>
#include <string>

// Сумма столбков и строк
uint row_col_sum(uint** matrix, size_t msize, uint num) {
    // Проверяем размер и переданный массив
    assert(matrix != NULL && msize <= 40);


    uint sum = 0;

    // Проходим по столбцам
    for(uint y = 0; y < msize; y++) {
        sum += matrix[y][num];
    }

    // Проходим по строкам
    for(uint x = 0; x < msize; x++) {
        sum += matrix[num][x];
    }

    return sum;
}

// Инициализация матрицы числами
uint** init_matrix(size_t msize) {
    // Проверяем размер и переданный массив
    assert(msize <= 40 && "0 <= size <= 40");

    // Выделяем массив указателей
    uint** matrix = new uint*[msize];

    for(uint i = 0; i < msize; i++) {
        // Выделяем массив чисел (строку)
        matrix[i] = new uint[msize];

        // Заполняем строку числами, кроме основной диагонали
        for(uint j = 0; j < msize; j++) {
            if(i == j) {
                matrix[i][j] = 0;
            } else {
                matrix[i][j] = (i+1) + (j+1);
            }
        }
    }

    // Заполняем основуную диагональ
    for(uint i = 0; i < msize; i++) {
        matrix[i][i] = row_col_sum(matrix, msize, i);
    }

    return matrix;
}

// Поворот на 90 градусов
void rotate_90(uint** matrix, size_t msize) {
    // Проверяем размер и переданный массив
    assert(matrix != NULL && msize <= 40);

    uint temp;
    for(uint i = 0; i < msize/2; i++) {
        for(uint j = 0; j < msize/2; j++) {
            temp                         = matrix[msize-1-j][i];
            matrix[msize-1-j][i]         = matrix[msize-1-i][msize-1-j];
            matrix[msize-1-i][msize-1-j] = matrix[j]        [msize-1-i];
            matrix[j]        [msize-1-i] = matrix[i]        [j];
            matrix[i]        [j]         = temp;
        }
    }
}

// Вывод матрицы на экран
void print_matrix(uint** matrix, size_t msize) {
    // Проверяем размер и переданный массив
    assert(matrix != NULL && msize <= 40);

    for(uint i = 0; i < msize; i++) {
        for(uint j = 0; j < msize; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout<< "\n";
    }
}

int main() {
    // Задаем размер матрицы
    const size_t msize = 5;

    // Инициализируем матрицу
    uint** matrix = init_matrix(msize);

    // Выводим матрицу
    printf("Initialized matrix:\n");
    print_matrix(matrix, msize);

    // Поворачиваем и выводим матрицу
    printf("Rotated matrix:\n");
    rotate_90(matrix, msize);
    print_matrix(matrix, msize);

    return 0;
}
