#include <iostream>

using namespace std;

class MyClass {
public:
	explicit MyClass(int x = 0): x(x) {}

	int get() {
		return x;
	}
private:
	int x;
};

int main() {
	MyClass c1(1);
	MyClass c2(c1);
	
	int x1 = c1.get();
	int x2 = c2.get();
	cout << x1 << " " << x2 << endl;

	MyClass c3 = c1;
	cout << c3.get() << endl;

	MyClass c4(4);
	c3 = c4;
	cout << c3.get() << endl;
	
//	int x = 5;
//	MyClass c5 = x;
//	cout << c5.get() << endl;
	return 0;
}
