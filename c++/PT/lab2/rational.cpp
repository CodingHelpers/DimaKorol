#include "rational.hpp"
#include <iostream>

Rational::Rational(int n, int d) : c(0), num(n), den(d) {
    simplify();
}

Rational::Rational() : Rational(0, 1) {}

void Rational::simplify() {
    // Находим наибольший общий делитель числителя и знаменателя
    int t;
    int gcd = num;
    int b   = den;

    if(gcd < b) {
        t = gcd;
        gcd = b;
        b = t;
    }

    while(b) {
        t = b;
        b = gcd % b;
        gcd = t;
    }

    // Делим числитель и знаменатель на общий делитель
    num = irrational_numenator() / gcd;
    den = den / gcd;

    // Рационализируем дробь
    c = num / den;
    num = num % den;
}

int Rational::irrational_numenator() const {
    return num + c * den;
}

void Rational::print() {
    std::cout << c << "_" << num << "/" << den << std::endl;
}

Rational operator+ (const Rational& a, const Rational& b) {
    // Копируем исходные данные во временные переменные
    int tnuma = a.irrational_numenator();
    int tnumb = b.irrational_numenator();
    int tdena = a.den;
    int tdenb = b.den;

    // Приводим к общему знаменателю
    int numa = tnuma * tdenb;
    int numb = tnumb * tdena;

    // Знаменатель итоговой дроби
    int den  = tdenb * tdena;

    // Числитель итоговой дроби
    int num = numa + numb;

    // Создаем и возвращаем новую дробь
    return Rational(num, den);
}

Rational operator+ (const Rational& a, int b) {
    // Создаем временную дробь для второго аргемента
    Rational br(b, 1);

    // Используем объявленный выше operator+ (const Rational& a, const Rational& b)
    return a + br;
}

Rational operator+ (int a, const Rational& b) {
    return b + a;
}

Rational operator- (const Rational& a, const Rational& b) {
    // Копируем исходные данные во временные переменные
    int tnuma = a.irrational_numenator();
    int tnumb = b.irrational_numenator();
    int tdena = a.den;
    int tdenb = b.den;

    // Приводим к общему знаменателю
    int numa = tnuma * tdenb;
    int numb = tnumb * tdena;

    // Знаменатель итоговой дроби
    int den  = tdenb * tdena;

    // Числитель итоговой дроби
    int num = numa - numb;

    // Создаем и возвращаем новую дробь
    return Rational(num, den);
}

Rational operator- (const Rational& a, int b) {
    // Создаем временную дробь для второго аргемента
    Rational br(b, 1);

    // Используем объявленный выше operator- (const Rational& a, const Rational& b)
    return a - br;
}

Rational operator- (int a, const Rational& b) {
    // Создаем временную дробь для второго аргемента
    Rational ar(a, 1);

    // Используем объявленный выше operator- (const Rational& a, const Rational& b)
    return ar - b;
}

Rational operator* (const Rational& a, const Rational& b) {
    // Копируем исходные данные во временные переменные
    int numa = a.irrational_numenator();
    int numb = b.irrational_numenator();
    int dena = a.den;
    int denb = b.den;

    // Расчитываем числитель и знаменатель итоговой дроби
    int num = numa * numb;
    int den = dena * denb;

    // Создаем и возвращаем итоговую дробт
    return Rational(num, den);
}

Rational operator* (const Rational& a, int b) {
    // Создаем временную дробь для второго аргемента
    Rational br(b, 1);

    // Используем объявленный выше operator* (const Rational& a, const Rational& b)
    return a * br;
}

Rational operator* (int a, const Rational& b) {
    return b * a;
}

Rational operator/ (const Rational& a, const Rational& b) {
    // Копируем исходные данные во временные переменные
    int numa = a.irrational_numenator();
    int numb = b.irrational_numenator();
    int dena = a.den;
    int denb = b.den;

    // Расчитываем числитель и знаменатель итоговой дроби
    int num = numa * denb;
    int den = dena * numb;

    // Создаем и возвращаем итоговую дробт
    return Rational(num, den);
}

Rational operator/ (const Rational& a, int b) {
    // Создаем временную дробь для второго аргемента
    Rational br(b, 1);

    // Используем объявленный выше operator/ (const Rational& a, const Rational& b)
    return a / br;
}

Rational operator/ (int a, const Rational& b) {
    // Создаем временную дробь для второго аргемента
    Rational ar(a, 1);

    // Используем объявленный выше operator/ (const Rational& a, const Rational& b)
    return ar / b;
}
