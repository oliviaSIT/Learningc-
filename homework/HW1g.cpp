/* 
 * author: Jiabin.Li
 */

#include<iostream>
#include<array>

using namespace std;

int main() {
	int number = 123;
	
	unsigned bit = 1;
	int temp = number;
	while (temp / 10 > 0) {
		bit++;
		temp /= 10;
	}

	char A[bit];
	for (unsigned i = bit; i >= 0; i--) {
		A[i] = number % 10 + '0';
		number /= 10;
	}

	for (unsigned j = 0; j < bit; j++) {
		cout << A[j];
	}
	cout << endl << bit << endl;

	return 0;
}
