#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

const double PI = 3.1415926;

class Shape {
protected:
    double x, y, z;
public:
    Shape(double x = 0, double y = 0, double z = 0):x(x), y(y), z(z) {}

    virtual void toSTL(ofstream& os) const = 0 ;  
    virtual ~Shape() {}
};

class Cylinder: public Shape {
private:
    double r, h;
    int facets;
public:
    Cylinder(double x, double y, double z, double r, double h, int facets):
        Shape(x, y, z), r(r), h(h), facets(facets) {}
    
    void toSTL(ofstream& os) const {
	double x1, x2, y1, y2, x3, y3, z3;
	double z1 = z + h, z2 = z;
        for (int i = 0; i < facets; i++) {
		x1 = x + r * cos(2 * PI / facets * i); 
		x2 = x + r * cos(2 * PI / facets * (i + 1));
		y1 = y + r * sin(2 * PI / facets * i);
		y2 = y + r * sin(2 * PI / facets * (i + 1));
				
		//calculate facet normal
		x3 = h * (y2 - y1);//((p2.y-p1.y)*(p3.z-p1.z)-(p2.z-p1.z)*(p3.y-p1.y)) 		
		y3 = h * (x1 - x2);//((p2.z-p1.z)*(p3.x-p1.x)-(p2.x-p1.x)*(p3.z-p1.z))
		z3 = 0.0;//((p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x))

		//write stl
		os << "facet normal" << " " << x3 << " " << y3 << " " << z3 << endl;
		os << "outer loop" << endl;
		os << "vertex" << " " << x1 << " " << y1 << " " << z1 << endl;
		os << "vertex" << " " << x1 << " " << y1 << " " << z2 << endl;
		os << "vertex" << " " << x2 << " " << y2 << " " << z1 << endl;
		os << "endloop" << endl;
		os << "endfacet" << '\n' << endl;

		os << "facet normal" << " " << x3 << " " << y3 << " " << z3 << endl;
		os << "outer loop" << endl;
		os << "vertex" << " " << x1 << " " << y1 << " " << z2 << endl;
		os << "vertex" << " " << x2 << " " << y2 << " " << z1 << endl;
		os << "vertex" << " " << x2 << " " << y2 << " " << z2 << endl;
		os << "endloop" << endl;
		os << "endfacet" << '\n' << endl;

		os << "facet normal" << " " << 0 << " " << 0 << " " << 1 << endl;
		os << "outer loop" << endl;
		os << "vertex" << " " << x << " " << y << " " << z1 << endl;
		os << "vertex" << " " << x1 << " " << y1 << " " << z1 << endl;
		os << "vertex" << " " << x2 << " " << y2 << " " << z1 << endl;
		os << "endloop" << endl;
		os << "endfacet" << '\n' << endl;

		os << "facet normal" << " " <<0 << " " << 0 << " " << -1 << endl;
		os << "outer loop" << endl;
		os << "vertex" << " " << x << " " << y << " " << z2 << endl;
		os << "vertex" << " " << x1 << " " << y1 << " " << z2 << endl;
		os << "vertex" << " " << x2 << " " << y2 << " " << z2 << endl;
		os << "endloop" << endl;
		os << "endfacet" << '\n' << endl;
		}
    }

    ~Cylinder() {}
};

class Cube: public Shape {
private:
    double size;
public:
    Cube(double x, double y, double z, double size):
        Shape(x, y, z), size(size) {}

    void toSTL(ofstream& os) const {
        os << "facet normal" << " " << "0 0 -1" << endl;
        os << "outer loop" << endl;
        os << "vertex" << " " << x << " " << y << " " << z << endl;
        os << "vertex" << " " << x + size << " " << y << " " << z << endl;
        os << "vertex" << " " << x + size << " " << y + size << " " << z << endl;
        os << "endloop" << endl;
        os << "endfacet" << '\n' << endl;

	os << "facet normal" << " " << "0 0 -1" << endl;
        os << "outer loop" << endl;
        os << "vertex" << " " << x << " " << y << " " << z << endl;
        os << "vertex" << " " << x << " " << y + size << " " << z << endl;
        os << "vertex" << " " << x + size << " " << y + size << " " << z << endl;
        os << "endloop" << endl;
        os << "endfacet" << '\n' << endl;
	
	os << "facet normal" << " " << "0 -1 0" << endl;
        os << "outer loop" << endl;
        os << "vertex" << " " << x << " " << y << " " << z << endl;
        os << "vertex" << " " << x + size << " " << y << " " << z << endl;
        os << "vertex" << " " << x + size << " " << y << " " << z + size << endl;
        os << "endloop" << endl;
        os << "endfacet" << '\n' << endl;

	os << "facet normal" << " " << "0 -1 0" << endl;
        os << "outer loop" << endl;
        os << "vertex" << " " << x << " " << y << " " << z << endl;
        os << "vertex" << " " << x << " " << y << " " << z + size<< endl;
        os << "vertex" << " " << x + size << " " << y << " " << z + size << endl;
        os << "endloop" << endl;
        os << "endfacet" << '\n' << endl;

	os << "facet normal" << " " << "-1 0 0" << endl;
        os << "outer loop" << endl;
        os << "vertex" << " " << x << " " << y << " " << z << endl;
        os << "vertex" << " " << x << " " << y + size << " " << z << endl;
        os << "vertex" << " " << x << " " << y + size << " " << z + size << endl;
        os << "endloop" << endl;
        os << "endfacet" << '\n' << endl;

	os << "facet normal" << " " << "-1 0 0" << endl;
        os << "outer loop" << endl;
        os << "vertex" << " " << x << " " << y << " " << z << endl;
        os << "vertex" << " " << x << " " << y + size << " " << z + size << endl;
        os << "vertex" << " " << x << " " << y << " " << z + size << endl;
        os << "endloop" << endl;
        os << "endfacet" << '\n' << endl;

	os << "facet normal" << " " << "1 0 0" << endl;
        os << "outer loop" << endl;
        os << "vertex" << " " << x + size << " " << y << " " << z << endl;
        os << "vertex" << " " << x + size << " " << y + size << " " << z << endl;
        os << "vertex" << " " << x + size << " " << y + size << " " << z + size << endl;
        os << "endloop" << endl;
        os << "endfacet" << '\n' << endl;
	
	os << "facet normal" << " " << "1 0 0" << endl;
        os << "outer loop" << endl;
        os << "vertex" << " " << x + size << " " << y << " " << z << endl;
        os << "vertex" << " " << x + size << " " << y + size << " " << z + size << endl;
        os << "vertex" << " " << x + size << " " << y << " " << z + size << endl;
        os << "endloop" << endl;
        os << "endfacet" << '\n' << endl;

	os << "facet normal" << " " << "0 0 1" << endl;
        os << "outer loop" << endl;
        os << "vertex" << " " << x << " " << y << " " << z + size << endl;
        os << "vertex" << " " << x + size << " " << y << " " << z + size << endl;
        os << "vertex" << " " << x + size << " " << y + size << " " << z + size << endl;
        os << "endloop" << endl;
        os << "endfacet" << '\n' << endl;

        os << "facet normal" << " " << "0 0 1" << endl;
        os << "outer loop" << endl;
        os << "vertex" << " " << x << " " << y << " " << z + size << endl;
        os << "vertex" << " " << x << " " << y + size << " " << z + size << endl;
        os << "vertex" << " " << x + size << " " << y + size << " " << z + size << endl;
        os << "endloop" << endl;
        os << "endfacet" << '\n' << endl;

	os << "facet normal" << " " << "0 1 0" << endl;
        os << "outer loop" << endl;
        os << "vertex" << " " << x << " " << y + size << " " << z << endl;
        os << "vertex" << " " << x + size << " " << y + size << " " << z << endl;
        os << "vertex" << " " << x + size << " " << y + size << " " << z + size << endl;
        os << "endloop" << endl;
        os << "endfacet" << '\n' << endl;

        os << "facet normal" << " " << "0 1 0" << endl;
        os << "outer loop" << endl;
        os << "vertex" << " " << x << " " << y + size << " " << z << endl;
        os << "vertex" << " " << x << " " << y + size << " " << z + size<< endl;
        os << "vertex" << " " << x + size << " " << y + size << " " << z + size << endl;
        os << "endloop" << endl;
	os << "endfacet" << '\n' << endl;	
    }

    ~Cube() {}
};

class CAD {
public:
    vector<Shape*> shapes;
public:
    CAD() {}

    void add(Shape* s) {
        shapes.push_back(s);
    }

    void write(const string& path) {
        	ofstream os;
        	os.open(path, ofstream::app);
		os << "solid shape" << endl;

        	for(size_t i = 0; i < shapes.size(); i++) {
            		shapes[i]->toSTL(os);
		}
		
		os << "endsolid shape" << endl;
        	os.close();
    	}   

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
    c.write("test.stl");

    return 0;
}

