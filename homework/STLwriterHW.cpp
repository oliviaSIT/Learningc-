#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Shape {
private:
	double x, y, z;
public:
	Shape(double x = 0, double y = 0, double z = 0):x(x), y(y), z(z) {}

	virtual ostream& operator<<(ostream& s, const Shape*) {
		s << "one shape" << endl;
		cout << s;
		return s;
	}
 	
	virtual ~Shape() {cout << "destroy Shape" << endl;}
};

class Cylinder : public Shape{
private:
	double r, h;
	int facets;
public:
	Cylinder(double x, double y, double z, double r, double h, int facets):Shape(x, y, z), r(r), h(h), facets(facets) {}
	
	friend ostream& operator<<(ostream& s, const Cylinder* c) {
		s << c->r << c->h << c->facets << endl;
		return s;
	}

	~Cylinder() {cout << "destroy Cylinder" << endl;}
};

class Cube: public Shape {
private:
	double size;
public:
	Cube(double x, double y, double z, double size):Shape(x, y, z), size(size) {}

        friend ostream& operator<<(ostream& s, const Cube* c) {
                 s << c->size << endl;
                 return s;
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
//        c.write("test.stl");

	return 0;
}
