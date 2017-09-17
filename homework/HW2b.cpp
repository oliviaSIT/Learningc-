/*
 * author: Jiabin.Li
 */

#include<iostream>
using namespace std;

bool isPrime(unsigned long long num) {
	if (num == 1) return false;

	if (num == 2) return true;

	for (unsigned long long i = 2; i < num; i++) {
		if (num % i == 0) return false;
	}

	return true;
}

int main() {
	unsigned long long x;
	cin >> x;

	bool y = isPrime(x);
	if (y) {
     	   cout << "is prime" << endl;
        } else {
	   cout << "not prime" << endl;
	}

        return 0;
}
