#pragma once
#include <iostream>
#include <cmath>
#include <string>

template <typename Precision>
class Complex;

template <typename Precision>
std::ostream& operator<<(std::ostream& os, const Complex<Precision>& c);

template <typename Precision>
Complex<Precision> operator+(const Complex<Precision>& c1, const Complex<Precision>& c2);

template <typename Precision>
class Complex {
private:
    Precision r, i;

public:
    Complex(Precision r = 0, Precision i = 0): r(r), i(i) {}

    Complex(const Complex<Precision>& c): r(c.r), i(c.i) {}

    Precision abs() {return sqrt(r * r + i * i);}

    Complex operator-() {
        return Complex(r, -i);
    }

    void print() {
	std::cout << "real:" << r << " imag:" << i << std::endl;
    }

    Complex& operator=(const Complex<Precision>& c) {
	r = c.r;
	i = c.i;
	return *this;
    }

    friend std::ostream& operator<<<Precision>(std::ostream& os, const Complex<Precision>& c);
   
    friend Complex<Precision> operator+<Precision>(const Complex<Precision>& c1, const Complex<Precision>& c2);

};

template <typename Precision>
std::ostream& operator<<(std::ostream& os, const Complex<Precision>& c) {
    os << Precision(c.r);
    if(c.i >= 0) {
        os << "+i" << Precision(c.i);
    } else {
        os << "-i" << Precision(-c.i);
    }

    return os;
}

template <typename Precision>
Complex<Precision> operator+(const Complex<Precision>& c1, const Complex<Precision>& c2) {
    Complex<Precision> ans(c1.r + c2.r, c1.i + c2.i);
    return ans;
}

