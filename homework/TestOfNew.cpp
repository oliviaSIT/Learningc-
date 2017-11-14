#include <iostream>

using namespace std;

int main() {
	int* p1 = new int[32];
//	int* p2 = new int[32];
//	for (int i = 0; i < 32; i++) {

	cout << p1 << endl;
	cout << &p1[1] << endl;
	return 0;
}
