#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Shape {
private:
    double x, y, z;
public:
    Shape(double x = 0, double y = 0, double z = 0):x(x), y(y), z(z) {}

    virtual string toString () const = 0 ;  
    
    virtual ~Shape() {
        cout << "destroy Shape" << endl;
    }
};

class Cylinder: public Shape {
private:
    double r, h;
    int facets;
public:
    Cylinder(double x, double y, double z, double r, double h, int facets):
        Shape(x, y, z), r(r), h(h), facets(facets) {}
    
    virtual string toString() const {
        string result = "hello Cylinder";
        return result;
    }

    ~Cylinder() {
        cout << "destroy Cylinder" << endl;
    }
};

class Cube: public Shape {
private:
    double size;
public:
    Cube(double x, double y, double z, double size):
        Shape(x, y, z), size(size) {}

        virtual string toString() const{
            return to_string(size);
        }

    ~Cube() {cout << "destroy Cube" << endl;}
};

class CAD {
//private:
public:
    vector<Shape*> shapes;
public:
    CAD() {}

    void add(Shape* s) {
        shapes.push_back(s);
    }
	void write(const string& path) {
        	ofstream stlFile;
        	stlFile.open(path);
        	for(size_t i = 0; i < shapes.size(); i++) {
            		stlFile << shapes[i]->toString() << '\n';
		}
        	stlFile.close();
    	}
       

/*
    void write(const string& s) {
        for(size_t i = 0; i < shapes.size(); i++) {
            
        }   
    }
*/  
    ~CAD() {
        for(size_t i = 0; i < shapes.size(); i++) {
            delete shapes[i];
        }
    }
};

ostream& operator<<(ostream& os, const Shape& shape) {
    os << shape.toString();
    return os;
}

//https://www.stratasysdirect.com/resources/how-to-prepare-stl-files/
//https://www.viewstl.com/
int main() {
    CAD c;
    c.add(new Cube(0,0,0,5));
    c.add(new Cylinder(100, 0, 0, 3, 10, 10));
    for(size_t i = 0; i < c.shapes.size(); i++) {
        cout << *(c.shapes[i]);
    }
    cout << endl;
    c.write("test.stl");

    return 0;
}
/*
struct TestCase {
    bool pass;
    string description;
};

class UnitTest {
public:
    vector<TestCase> cases;
    
    void add(TestCase testCase) {
        cases.push_back(testCase);
    }

    void run() {
        for (int i = 0; i < cases.size(); i++) {
            if (!cases[i].pass)
                cout << cases[i].description << endl;
        }
    }
};

// test.cpp
void testCubeToString() {
    Cube cube(1, 2, 3, 4);
    string expectedResult = "4";
    
    if (!(cube.toString() == expectedResult)) {
        cout << cube.toString() << endl;
        return false;
    }
    return true;
}

int main() {
    testCubeToString();
    
    return 0;
}

// main.cpp
//
*/
