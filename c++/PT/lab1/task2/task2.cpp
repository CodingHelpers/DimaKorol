#include <iostream>
#include "matrix.hpp"
#include "matrix2.hpp"

using namespace std;
using namespace guap;

void demo_matrix() {
    // Пытаемся создать матрицу с неправильным размером
    try { Matrix m1(-1); } catch(std::exception& e) {
        std::cerr << e.what() << "\n";
    }

    try { Matrix m1(41); } catch(std::exception& e) {
        std::cerr << e.what() << "\n";
    }

    Matrix m1(10);

    cout << "Matrix with size " << m1.size() << endl;
    m1.Print();

    cout << endl << endl
         << "Rotated by 90 deg matrix with size " << m1.size() << endl;
    m1.Rotate();
    m1.Print();
}

void demo_matrix2() {
    Matrix2 m1(2);
    Matrix2 m2(4);
    Matrix2 m3(10);

    cout << "Original matrix 2:\n";
    m2.Print();

    cout << "\nMatrix 2 rotated 2 times:\n";
    m2.Rotate(2);
    m2.Print();

    cout << "\nOriginal matrix 3:\n";
    m3.Print();

    cout << "\nMatrix 3 rotated 400000001 times:\n";
    m3.Rotate(400000001);
    m3.Print();

    cout << "\nOriginal matrix 1:\n";
    m1.Print();

    cout << "\nSet 0:1 and 1:1 in matrix 1 to 0:\n";
    m1.Set(0, 1, 0);
    m1.Set(1, 1, 0);
    m1.Print();

    cout << "\nTrying to set 10:1 of matrix 1:\n";
    try {
        m1.Set(10, 0, 0);
    } catch(std::out_of_range& e) {
        std::cerr << e.what();
    }

    cout << "\nTrying to set 1:10 of matrix 1:\n";
    try {
        m1.Set(1, 10, 0);
    } catch(std::out_of_range& e) {
        std::cerr <<  e.what();
    }

    cout << "\nCopy matrix 1 to matrix 3:\n";
    m3.Assign(m1);
    m3.Print();


    // Тестирование арифметических операторов
    Matrix2 m4(3);
    Matrix2 m5(3);

    cout << "M4:\n";
    m4.Print();

    cout << "M5:\n";
    m5.Print();

    cout << "M4+M5=\n";
    (m4+m5).Print();

    cout << "M4-M5=\n";
    (m4-m5).Print();

    cout << "M4*M5=\n";
    (m4*m5).Print();

    cout << "M4*10=\n";
    (m4*10).Print();

    cout << "10*M4=\n";
    (10*m4).Print();

    cout << "M6 = (M4 + M5)\n";
    Matrix2 m6 = (m4 + m5);
    m6.Print();

    // Тестирование дискриминанта
    Matrix2 m7(10);
    m7.Print();
    cout << "Det: " << m7.Determinant() << endl;
}

int main() {
    demo_matrix();
    demo_matrix2();
}
