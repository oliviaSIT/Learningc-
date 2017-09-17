/*
 * author: Jiabin.Li
 */

#include<iostream>
#include<cmath>

using namespace std;

int main() {
    cout << "Please input a number: " << endl;
    int n;
    cin >> n;

    float s1 = 0.0, s2 = 0.0;

    for (int i = 1; i <= n; i++) {
        s1 = s1 + 1.0 / (i * i);
    }

    for (int i = n; i > 0; i--) {
        s2 = s2 + 1.0 / (i * i);
    }

    cout << "forward: " << sqrt(6 * s1) << endl;
    cout << "backward: " << sqrt(6 * s2) << endl;
    
    return 0;
}
