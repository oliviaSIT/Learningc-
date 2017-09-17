/*
 * author: JIabin.Li
 */

#include<iostream>

using namespace std;

int main() {
    int a, b;
    a = (1 + 100) * 100 / 2;
    
    b = 0;
    for (int i = 1; i < 101; ++i) {
        b += i;
    }

    cout << a << " " << b <<endl;
    return 0; 
}
