/* 
 * author: Jiabin.Li
 */

#include<iostream>

using namespace std;

bool isPrime(unsigned long long num) {
	if (num == 1)  return false;

	if (num == 2)  return true;

        for (unsigned long long i = 2; i < num; i++) {
                if (num % i == 0) return false;
        }

        return true;
}


int countPrimes(unsigned long long a, unsigned long long b) {
	if (b < a) return -1;

	int count = 0;
	for (unsigned long long i = a; i <= b; i++ ) {
		if (isPrime(i)) count++;
	}

	return count;
}

int main() {
	unsigned long long a = 0, b = 0;
        cout << "input = " << endl;
	cin >> a >> b;
	int y;
	y = countPrimes(a, b);	
	cout << y << endl;

	return 0;
}
