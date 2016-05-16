/* Author: David Zaretsky
 *
 * Task:
 * Создать класс, обеспечивающего работу с рациональными дробями. Класс должен уметь
 * работать как с рациональными дробями, так и с целыми числами. Должны быть определены операции
 * сложения, вычитания, умножения и деления. Дроби должны быть упрощены и приведены к правильным.
 */

#include <iostream>
#include "rational.hpp"
using namespace std;

int main() {
    Rational pi(22, 7);
    Rational e(8, 3);
    Rational y(5, 2);

    cout << "PI: "; pi.print();
    cout << "E:  ";  e.print();
    cout << "Y:  ";  y.print();

    cout << "PI + E = "; (pi + e).print();
    cout << "PI - E = "; (pi - e).print();
    cout << "PI * E = "; (pi * e).print();
    cout << "PI / E = "; (pi / e).print();

    Rational d = pi * e;
    cout << "\nD = PI * E = "; d.print();

    cout << "D + Y = "; (d + y).print();
    cout << "D - Y = "; (d - y).print();
    cout << "D * Y = "; (d * y).print();
    cout << "D / Y = "; (d / y).print();

    return 0;
}
