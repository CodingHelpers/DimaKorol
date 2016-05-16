#ifndef RATIONAL_H
#define RATIONAL_H
#include <string>

class Rational {
public:
    Rational();
    Rational(int n, int d);

    void print();

    friend Rational operator+ (const Rational& a, const Rational& b);
    friend Rational operator+ (const Rational& a, int b);
    friend Rational operator+ (int a, const Rational& b);

    friend Rational operator- (const Rational& a, const Rational& b);
    friend Rational operator- (const Rational& a, int b);
    friend Rational operator- (int a, const Rational& b);

    friend Rational operator* (const Rational& a, const Rational& b);
    friend Rational operator* (const Rational& a, int b);
    friend Rational operator* (int a, const Rational& b);

    friend Rational operator/ (const Rational& a, const Rational& b);
    friend Rational operator/ (const Rational& a, int b);
    friend Rational operator/ (int a, const Rational& b);

private:
    // Упрощени дроби и приведение к правильной
    void simplify();

    // Вычисление числителя, с учетом целой части
    int irrational_numenator() const;

    int c;   // Целое
    int num; // Числитель
    int den; // Знаменатель
};

#endif // RATIONAL_H
