#include <iostream>
#include "Complex.h"

using namespace std;

int main(){
  Complex<float> a(1.0f, 1.5f);
  Complex<double> b(1.0, 1.5);
  Complex<long double> c(1.0L, 2.5L);

  Complex<double> d(1.5, 1.0);
  Complex<double> e = b + d;
  cout << e << '\n';
  cout << a.abs() << '\n'; // compute the absolute value 
  cout << b.abs() << '\n'; // compute the absolute value 
  cout << c.abs() << '\n'; // compute the absolute value 
   

    return 0;
}
