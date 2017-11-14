#include <iostream>

using namespace std;

class Complex {
private: 
	double real;
	double imag;
public:
	Complex(double r = 0.0, double i = 0.0):
		real(r), imag(i) {}

	Complex& operator=(const Complex &c) {
		real = c.real;
		imag = c.imag;
		return *this;
	}

	friend ostream& operator<<(ostream &s, const Complex &c); 
};

ostream& operator<<(ostream &s, const Complex &c) {
	if (c.imag >= 0) {
		s << c.real << "+i" << c.imag << endl;
	}else {
		s << c.real << "-i" << -1 * c.imag << endl;
	}
	return s;
}
