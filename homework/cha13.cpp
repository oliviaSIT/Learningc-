#include <iostream>

using namespace std;

class MyClass {
public:
    MyClass(int n = 0):
        num(n) {
        cout << "constructor" << endl;
    }

    MyClass(const MyClass &other) {
        cout << "copy constructor" << endl;
        num = other.num;
    }

    ~MyClass() {
        cout << "destructor" << endl;
    }

    int getNum() {
        return num;
    }

private:
    int num;
};

class HasPtr {
public:
    HasPtr(const MyClass &s = MyClass()):
        ps(new MyClass(s)), i(0) {
    }

    HasPtr(const HasPtr &p):
        ps(new MyClass(*p.ps)), i(p.i) {
    }

    //HasPtr& operator=(const HasPtr &);

    ~HasPtr() {
        delete ps;
    }

    int getNum() {
        return ps->getNum();
    }

private:
    MyClass * ps;
    int i;
};

int main() {
    MyClass s;
    HasPtr p(s);

    cout << "get num from p " << p.getNum() << endl;

    return 0;
}
