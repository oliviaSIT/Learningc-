#include <iostream>
#include <string>

using namespace std;

class Person {
private:
	string FirstName;
	string LastName;
	double weight;

public:
	Person(string FN = "", string LN = "", double w = 0):FirstName(FN),
							     LastName(LN),
							     weight(w) {}
	
	Person& operator=(const Person &p){
		FirstName = p.FirstName;
		LastName = p.LastName;
		weight = p.weight;
		return *this;
	}	

	void setName(const string &FN, const string &LN) {
		FirstName = FN;
		LastName = LN;
	}

	friend Person operator+(const Person &p1, const Person &p2);	
	friend ostream& operator<<(ostream &s, const Person &p); 
};

ostream& operator<<(ostream &s, const Person &p) {
	s << p.FirstName << " " << p.LastName << " " << p.weight << endl;
	return s;
}

Person operator+(const Person &p1, const Person &p2) {
	Person p;
	p.weight = p1.weight + p2.weight;
	return p;
}

int main() {
	Person p;
	cout << p << endl;
	p.setName("Satan", "Trump");
	cout << p << endl;
	Person p1("Jiabin", "Li", 107);
	p = p1;
	cout << p << endl;
	Person p2 = p1;
	Person p3 = p1 + p2;
	cout << p3 << endl;
	return 0;
}
