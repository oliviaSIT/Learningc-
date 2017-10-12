#include <iostream>
#include <string>
using namespace std;

class Complex {
private: 
	double real;
	double imag;
public:
	Complex() {
	real = 0.0;
	imag = 0.0;
	}

	Complex(double r): real(r){
		imag = 0.0;
	}

	Complex(double r, double i): real(r), imag(i){}

	Complex& operator=(const Complex &c) {
		real = c.real;
		imag = c.imag;
		return *this;
	}

	friend Complex operator +(const Complex &c1, const Complex &c2);
	friend Complex operator -(const Complex &c);
	friend ostream& operator <<(ostream &s, const Complex &c);
};

Complex operator +(const Complex &c1, const Complex &c2){
	Complex result;
	result.real = c1.real + c2.real;
	result.imag = c1.imag + c2.imag;
	return result;
} 

Complex operator-(const Complex &c){
	Complex d;
        d.real = d.real - c.real;
        d.imag = d.imag - c.imag;
        return d;
        }

ostream& operator <<(ostream &s, const Complex &c) {
	if (c.imag >=0) {
		s << c.real  << "+i" << c.imag << " ";
	}else {
		s << c.real  << "-i" << (-1) * c.imag << " ";
	}
	return s;
}

int main() {
	Complex c1(1.5,2.0);
	Complex c2(-1.3); // -1.3 + 0.0i
	Complex c5;  // 0+0i
//	Complex c3 = c1 + c2;
	Complex c4(1.0, 1.0);
	c4 = -c1; 
	cout << c1 << c4 << endl;
	return 0;
}
