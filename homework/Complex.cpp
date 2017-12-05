#include <iostream>
#include "Complex.h"

using namespace std;

template <typename Precision>

Complex::Complex<Precision> Complex::operator-() { 
                Complex::Complex<Precision> result;
                result.r = r;
                result.i = -1 * i;
                return result;
        }


ostream& operator<<(ostream& os, const Complex::Complex<Precision>& c) {
	if(c,i >= 0) {
		os << c.r << "+" << "i" << c.i << endl;
	} else {
		os << c.r << "-" << "i" << -1 * c.i << endl;
	}

	return os;
}

