#include <iostream>
using namespace std;

class Complex {
public:
	double real;
	double imag;
      
        Complex() {
	    real = 0;
	    imag = 0;
	}

	Complex(double r, double i) {
	    real = r;
	    imag = i;
	}

	double getReal() const { 
		return real;
	}
	double getImag() const { 
		return imag;
	}

	void print() const {
		cout << real << "+i" << imag;
	}

	
        Complex add(Complex y) {
		Complex ans;
		ans.real = real + y.real;
		ans.imag = imag + y.imag;
		return ans;
	}

	Complex add(Complex x, Complex y) {
		Complex ans;
		ans.real = x.real + y.real;
		ans.imag = x.imag + y.imag;
		return ans;
	}

	
};



int main() {
	Complex c1(1.0, 2.5); // real=1.0, imag = 2.5
	Complex c2(2.0, 1.5);
	const Complex c3 = c1.add(c2);  // add two complex numbers
	c3.print(); cout << "\n";
	cout << c3.getReal() << ", " << c3.getImag() << endl;
	
	return 0;
}
