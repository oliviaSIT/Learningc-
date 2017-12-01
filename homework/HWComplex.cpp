#include "Complex.h"
#include <iostream>

using namespace std;
/*
ostream& operator<<(ostream& os, const Complex<Precision>& c) {
	if(c.i < 0) {
		os << c.p << c.i << "i" << endl;
	} else {
		os << c.p << "+" << c.i << "i" << endl;
	} 

	return os;
}
*/
int main() {
//	float x = 1;
//	double y = 1.0000000000;
//	long double z = 1.000000000000000000009999999;
	Complex<double> a(1.0,2.5);
	Complex<float> b(1.0f, 2.5f);
//	cout << a << b << endl;
	return 0;
}
