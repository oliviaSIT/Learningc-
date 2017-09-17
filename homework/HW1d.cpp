/* 
 * author: Jiabin.Li
 */

#include<iostream>

using namespace std;

int main() {
    float f1 = 0.0, f2 = 0.0;
    double d1 = 0.0, d2 = 0.0;
    
    for (int n = 1; n < 101; ++n) {
        f1 = f1 + 1.0 / n;
        d1 = d1 + 1.0 / n;
    }

    for (int n = 100; n > 0; --n) {
        f2 = f2 + 1.0 / n;
        d2 = d2 + 1.0 / n;
    }
    float x = 3.13 ;
    cout << "float: sum1=" << f1 << " sum2=" << f2 << " sum1-sum2=" << f1 - f2 << endl;
    cout << "double: sum1=" << d1 << " sum2=" << d2 << " sum1-sum2=" << d1 - d2 << endl;
    cout << x << endl;
    return 0; 
}
