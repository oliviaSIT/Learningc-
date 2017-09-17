/*
 * author: Jiabin.Li
 */

#include<iostream>
#include<cstdint>

using namespace std;

class solution {
public:
    int64_t test(int n) {
        int64_t answer = 1;
        for (int i = 1; i <= n; i++) {
            answer *= i;
        }
    return answer;
    }
};

int main() {
    solution x;
    
    cout << x.test(10) << endl;
    cout << x.test(20) << endl;
    cout << x.test(30) << endl;

    return 0;
}
