#include <iostream>
#include <string>

using namespace std;

template<typename T>


void bubbleSort(T x[], int n) {
//	T temp;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < n - i; j++) {
			if(x[j] > x[j + 1]) {
				swap(x[j], x[j + 1]);
			}
		}
	}
}

class Elephant {
private:
	string name;
	int age;
public:
	Elephant(const string name, int age): name(name), age(age) {}
	
	friend ostream& operator<<(ostream& os, const Elephant& e);

	friend bool operator>(const Elephant& e1, const Elephant& e2); 
};

ostream& operator<<(ostream& os, const Elephant& e) {
        cout << "name:" << e.name << " age:" << e.age << endl;
	return os;
}

bool operator>(const Elephant& e1, const Elephant& e2) {
	return e1.age > e2.age;		
}

int main() {
	string y[] = {"i", "h", "he", "ha"};
	bubbleSort(y, 4);	

	Elephant a("a", 12);
	Elephant b("b", 2);
	Elephant x[] = {a, b};
	bubbleSort(x, 2);

	for(int i = 0; i < sizeof(y) / sizeof(y[0]); i++){
		cout << y[i] << " ";
	}
	cout << endl;

	for(int i = 0; i < sizeof(x) / sizeof(x[0]); i++) {
		cout << x[i];
	}

	return 0;
}
