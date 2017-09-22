/* 
 * author: Jiabin.Li
 */

#include <iostream>
#include <array>
#include <cstddef>

using namespace std;

int main() {
	int number = 123;
	
        constexpr unsigned bit = sizeof(number) / sizeof(int);

	char A[bit];
	for (unsigned i = bit - 1; i >= 0; i--) {
		A[i] = number % 10 + '0';
		number /= 10;
	}

	for (unsigned j = 0; j < bit; j++) {
		cout << A[j];
	}
	cout << endl;

	return 0;
}
