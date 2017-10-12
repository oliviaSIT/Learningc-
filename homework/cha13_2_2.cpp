/*#include <iostream>
#include <string>

using namespace std;

class MyClassProperty {
public:
    ~MyClassProperty() {
        cout << "Destroying MyClassProperty" << endl;
    }
};

class MyClass {
public:
    // converting constructor
    MyClass(int n) : num(n), p(new string()) {
    }
    
    MyClass(int n, const string &s) : num(n), p(new string(s)) {
    }

    MyClass(const MyClass &x) {
        num = x.num;
        p = new string(*(x.p));
    }

    MyClass& operator=(const MyClass &x) {
        num = x.num;
        p = new string(*(x.p));
        return *this;
    }

    int getNum() const {
        return num;
    }
    
    void setNum(int n) {
        num = n;
    }
    
    ~MyClass() {
        delete p;
	cout << "delete p" << endl;
    }

private:
    int num;
//    string* p;
    MyClassProperty r;
    string* p;
};

int main() {
    int i = 1;
    string s("Hello World!");
    
    MyClass mc1(i, s); // s_copy
//    MyClass mc2(mc1); // s_copy

    cout << mc1.getNum() << endl;

    return 0;
}
*/

#include <iostream>
#include <string>

using namespace std;

class MyClassProperty {
public:
    MyClassProperty() : num(0) {}

    MyClassProperty(int n) : num(n) {}

    ~MyClassProperty() {
        cout << "Destroying MyClassProperty " << num << endl;
    }

private:
    int num;
};

class MyClass {
public:
    // converting constructor
    MyClass(int n) : num(n), p(new string()), r1(1), r2(2) {
    }

    MyClass(int n, const string &s) : num(n), p(new string(s)), r1(1), r2(2) {
    }

    MyClass(const MyClass &x) {
        num = x.num;
        p = new string(*(x.p));
        r1 = MyClassProperty(1);
        r2 = MyClassProperty(2);
    }

    MyClass& operator=(const MyClass &x) {
        num = x.num;
        p = new string(*(x.p));
        r1 = MyClassProperty(1);
        r2 = MyClassProperty(2);
        return *this;
    }

    int getNum() const {
        return num;
    }

    void setNum(int n) {
        num = n;
    }

    ~MyClass() {
        delete p;
        cout << "delete p" << endl;
    }

private:
    int num;
    string* p;
    MyClassProperty r1;
    MyClassProperty r2;
};

int main() {
    int i = 1;
    string s("Hello World!");

    MyClass mc1(i, s);

    cout << mc1.getNum() << endl;

    return 0;
}
