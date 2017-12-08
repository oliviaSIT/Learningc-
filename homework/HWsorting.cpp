//Jiabin.Li
#include <iostream>
#include <string>

using namespace std;

template<typename T>

void print(T t[], size_t n) {
	for(size_t i = 0; i <= n; i++) {
		cout << t[i] << " ";
	}
	cout << endl;
}

template<typename T>
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
        os << "name:" << e.name << " age:" << e.age << " ";
	return os;
}

bool operator>(const Elephant& e1, const Elephant& e2) {
	return e1.age > e2.age;		
}

int main() {
	int x[] = {1, 2, 3, 4, 5};
	bubbleSort(x, 5);
	print(x, 5); // prints same thing

	int y[] = {6, 5, 4, 3, 2, 1};
	bubbleSort(y, 6);
	print(y, 6); // 1 2 3 4 5 6	

//	Elephant a("a", 12);
//	Elephant b("b", 2);
//	Elephant x[] = {a, b};
	Elephant e[] = { Elephant("Fred", 20), Elephant("Alice", 22), Elephant("George", 9)};
	bubbleSort(e, 3);
	print(e, 3);

	
	return 0;
}
