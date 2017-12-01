#include <iostream>
#include <string>

using namespace std;

template<typename T>

//void print(const T& t) {
//	cout << t << endl;
//}

void bubbleSort(T x[], size_t n) {
	T temp;
	for(size_t i = 1; i < n; i++){
		for(size_t j = 0; j < n - i; j++) {
			if(x[j] > x[j + 1]) {
				temp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = temp;
			}
		}
	}
}

class Elephant {
private:
	string name;
	int age;
public:
	Elephant() {name = " "; age = 0;}
	Elephant(const string& name, int age): name(name), age(age) {}
	
	friend ostream& operator<<(ostream& os, const Elephant& e);

	friend bool operator>(const Elephant& e1, const Elephant& e2); 
};

ostream& operator<<(ostream& os, const Elephant& e) {
        os << "name:" << e.name << " age:" << e.age << endl;
	return os;
}

bool operator>(const Elephant& e1, const Elephant& e2) {
	return e1.age > e2.age;		
}

int main() {
	string y[] = {"i", "h", "he", "ha"};
	bubbleSort(y, 4);	

//	Elephant a("a", 12);
//	Elephant b("b", 2);
//	Elephant x[] = {a, b};
	Elephant e[] = { Elephant("Fred", 20), Elephant("Alice", 22), Elephant("George", 9)};
	bubbleSort(e, 3);


	for(int i = 0; i < sizeof(y) / sizeof(y[0]); i++){
		cout << y[i] << " ";
	}
	cout << endl;

	for(int i = 0; i < sizeof(e) / sizeof(e[0]); i++) {
		cout << e[i];
	}


	
	return 0;
}
