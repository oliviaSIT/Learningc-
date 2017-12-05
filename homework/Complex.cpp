#include <iostream>
#include "Complex.h"

using namespace std;

int main() {
    Complex<double> c(1.1, -2.1);
//    cout << sizeof(c.abs()) << endl;
    c.print();   
 
    Complex<double> x(c);
    cout << x << endl;
    x.print();    

    Complex<double> r = -c; 
    cout << r << endl;
    r.print();  
  
   // r = c;
   // cout << r << endl;

    Complex<double> d;
    d = c + x;
    d.print();    

    return 0;
}
