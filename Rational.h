//
// Created by Alden Ahern on 4/24/21.
//

#ifndef CS202HOMEWORK5_RATIONAL_H
#define CS202HOMEWORK5_RATIONAL_H

#include <numeric>
#include <iostream>

// class invariant:
// _denominator is always > 0
template<typename T>
class Rational {
    friend std::ostream& operator<<(std::ostream &, const Rational &rhs);
    friend Rational operator+(const Rational &lhs, const Rational &rhs);
    friend Rational operator-(const Rational &lhs);
    friend bool operator==(const Rational &lhs, const Rational &rhs);
    friend bool operator<(const Rational &lhs, const Rational &rhs);

public:
    Rational(T,T=1); //NOLINT(google-explicit-constructor): Allow implicit conversion from int
    Rational(); // default constructor
    Rational & operator+=(const Rational& rhs);
    Rational & operator-=(const Rational& rhs);
    Rational & operator*=(const Rational& rhs);
    Rational & operator/=(const Rational& rhs);
    Rational & operator++();        //prefix ++
    Rational operator++(int); //postfix ++
    Rational & operator--();        //prefix --
    Rational operator--(int); //postfix --
private:
    void reduce();

    T _numerator;
    T _denominator;
};

template<typename T>
Rational<T> operator-(const Rational<T> &lhs, const Rational<T> &rhs) {return lhs + -rhs;}
// pass lhs by value because we were going to copy it anyway
template<typename T>
Rational<T> operator*(Rational<T> lhs, const Rational<T> &rhs) {return lhs *= rhs;} //Canonical
// pass lhs by value because we were going to copy it anyway
template<typename T>
Rational<T> operator/(Rational<T> lhs, const Rational<T> &rhs) {return lhs /= rhs;} //Canonical


template<typename T>
bool operator!=(const Rational<T> &lhs, const Rational<T> &rhs);
template<typename T>
bool operator>(const Rational<T> &lhs, const Rational<T> &rhs);
template<typename T>
bool operator<=(const Rational<T> &lhs, const Rational<T> &rhs);
template<typename T>
bool operator>=(const Rational<T> &lhs, const Rational<T> &rhs);

template<typename T>
Rational<T>::Rational(T num, T den) : _numerator(num), _denominator(den) {
    reduce();
}
template<typename T>
Rational<T>::Rational() : _numerator(T(0)), _denominator(T(1)) {
    reduce();
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const Rational<T> &rhs) {
    os << rhs._numerator;
    if (rhs._denominator != 1)
        os << "/" << rhs._denominator;
    return os;
}

template<typename T>
Rational<T> operator+(const Rational<T> &lhs, const Rational<T> &rhs) { //canonical
    auto temp{lhs};
    temp += rhs;
    return temp;
}

template<typename T>
Rational<T> & Rational<T>::operator+=(const Rational<T> &rhs) {
    // a/b + c/d = (ad+bc)/ad
    _numerator = _numerator * rhs._denominator + rhs._numerator * _denominator;
    _denominator *= rhs._denominator;
    reduce();
    return *this;
}

template<typename T>
void Rational<T>::reduce() {
    auto gcd = std::gcd(_numerator,_denominator);
    _numerator /= gcd;
    _denominator /= gcd;
    if (_denominator < 0) {
        _numerator *= -1;
        _denominator *= -1;
    }
}

template<typename T>
Rational<T> operator-(const Rational<T> &lhs) {
    return { -lhs._numerator, lhs._denominator };
}

template<typename T>
Rational<T> &Rational<T>::operator-=(const Rational<T> &rhs) { //Canonical
    *this = *this - rhs; //uses Rational::operator- to define operator-=
    return *this;
}

template<typename T>
Rational<T> &Rational<T>::operator*=(const Rational<T> &rhs) {
    _numerator *= rhs._numerator;
    _denominator *= rhs._denominator;
    return *this;
}

template<typename T>
Rational<T> &Rational<T>::operator/=(const Rational<T> &rhs) {
    return *this *= {rhs._denominator,rhs._numerator};
}

template<typename T>
Rational<T> & Rational<T>::operator++() {//prefix ++
    return *this += 1;
}

template<typename T>
Rational<T> Rational<T>::operator++(int) {//postfix ++
    auto copy{*this};
    ++(*this);
    return copy;
}

template<typename T>
Rational<T> & Rational<T>::operator--() {//prefix --
    return *this -= 1;
}

template<typename T>
Rational<T> Rational<T>::operator--(int) {//postfix --
    auto copy{*this};
    --(*this);
    return copy;
}

template<typename T>
bool operator==(const Rational<T> &lhs, const Rational<T> &rhs) {
    return lhs._numerator==rhs._numerator && lhs._denominator==rhs._denominator;
}

template<typename T>
bool operator<(const Rational<T> &lhs, const Rational<T> &rhs) {
    return lhs._numerator*rhs._denominator < rhs._numerator*lhs._denominator;
}

template<typename T>
bool operator!=(const Rational<T> &lhs, const Rational<T> &rhs) {//canonical
    return !(rhs==lhs);
}

template<typename T>
bool operator>(const Rational<T> &lhs, const Rational<T> &rhs) {//canonical
    return rhs<lhs;
}

template<typename T>
bool operator<=(const Rational<T> &lhs, const Rational<T> &rhs) {//canonical
    return ! (rhs>lhs);
}

template<typename T>
bool operator>=(const Rational<T> &lhs, const Rational<T> &rhs) {//canonical
    return ! (rhs<lhs);
}
#endif //CS202HOMEWORK5_RATIONAL_H
