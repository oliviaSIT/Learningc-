#pragma once
#include <iostream>
#include <cmath>

template <typename Precision>
class Complex {
private:
	Precision r, i;
public:
	Complex<Precision>(Precision r, Precision i): r(r), i(i) {}

	Complex<Precision>(const Complex<Precision>& c): r(c.r), i(c.i) {}

	Precision abs() {return sqrt(r * r + i * i);}

	Complex<Precision> operator-();

	friend std::ostream& operator<<(std::ostream& os, const Complex<Precision>& c);
};
