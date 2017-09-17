/*
 * author: Jiabin.Li
 */

#include<iostream>
#include<array>
#include<algorithm>

using namespace std;

unsigned long long fact(unsigned long long n) {
	unsigned long long f = 1;
	for (unsigned long long i = 1; i <= n; i++) {
		f *= i;	
	}

	return f;
}

unsigned long long fact2(unsigned long long n) {
	unsigned long long f = n;
	n--;
	if (n > 0) {
		f = f * fact2(n);
	}

	return f;
}

int fibo(int n) {
	int a = n; 
	int A[a];
	A[0] = 1;
	A[1] = 1;
	for (int i = 2; i < n; i++) {
		A[i] = A[i - 1] + A[i - 2];
	}

	return A[n - 1];
}

int fibo2(int n) {
	if (n == 1 || n == 2) {
		return 1;
	} else {
		return fibo2(n - 1) + fibo2(n - 2);
	}		
}

unsigned long long choose(int n, int r) {
	unsigned long long f1 = 1;
        int t = max(r, n-r);
	for (int i = n; i > t; i-- ) {
		f1 *= i;
	}
	return f1 / fact(n - t);
}

int main() {
  cout << fact(5) << ' ' << fact2(5) << '\n';
  cout << fact(15) << ' ' << fact2(15) << '\n';
  cout << fibo(5) << ' ' << fibo2(5) << '\n';
  cout << fibo(13) << ' ' << fibo2(13) << '\n';
  cout << choose(52,6) << '\n';
  return 0;
}
