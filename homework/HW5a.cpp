// created by Jiabin.Li

#include <iostream>
#include <cmath>

using namespace std;

class Vec3d {
private:
	double x, y, z;
public:
	Vec3d(double x = 0, double y = 0, double z = 0): x(x), y(y), z(z) {
	}

	Vec3d(const Vec3d &v) {
		x = v.x;
		y = v.y;
		z = v.z;
	}

	Vec3d& operator=(const Vec3d &v) {
		x = v.x;
                y = v.y;
                z = v.z;
		return *this;
	}
/*
	Vec3d& operator+(Vec3d &v1) {
               // Vec3d v;
                x = v1.x + x;
                y = v1.y + y;
                z = v1.z + z;
                return *this;
        }
*/
	double dot(const Vec3d &v) {
		double ans;
		ans = x * v.x + y * v.y + z * v.z;
		return ans;
	}

	double dist(const Vec3d &v) {
		double ans, p;
		p = pow(x - v.x, 2) + pow(y - v.y, 2) + pow(z - v.z, 2);  
		ans = sqrt (p);
		return ans;
	}

	friend ostream& operator<<(ostream &s, const Vec3d &v) {
		s << "{" << v.x << "," << v.y << "," << v.z << "}" << endl;
        	return s;
	} 

	friend Vec3d operator+(const Vec3d &v1, const Vec3d &v2);
	friend Vec3d operator-(const Vec3d &v1, const Vec3d &v2);
	friend Vec3d operator*(const Vec3d &v1, const double &scale);
	friend Vec3d operator*(const double &scale, const Vec3d &v1);
	friend double dot(const Vec3d &v1, const Vec3d &v2);
	friend double dist(const Vec3d &v1, const Vec3d &v2);
};

Vec3d operator+(const Vec3d &v1, const Vec3d &v2) {
                Vec3d v;
                v.x = v1.x + v2.x;
                v.y = v1.y + v2.y;
                v.z = v1.z + v2.z;
                return v;
        }


Vec3d operator-(const Vec3d &v1, const Vec3d &v2) {
                Vec3d v;
                v.x = v1.x - v2.x;
                v.y = v1.y - v2.y;
                v.z = v1.z - v2.z;
                return v;
        }

Vec3d operator*(const Vec3d &v1, const double &scale) {
                Vec3d v;
                v.x = v1.x * scale;
                v.y = v1.y * scale;
                v.z = v1.z * scale;
                return v;
        }


Vec3d operator*(const double &scale, const Vec3d &v1) {
                Vec3d v;
                v.x = v1.x * scale;
                v.y = v1.y * scale;
                v.z = v1.z * scale;
                return v;
        }

double dot(const Vec3d &v1, const Vec3d &v2) {
	double d;
	d = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return d;
}

double dist(const Vec3d &v1, const Vec3d &v2) {
	double ans, p;
        p = pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2) + pow(v1.z - v2.z, 2);
        ans = sqrt (p);
        return ans;
}

int main() {
/*
	Vec3d v1(1,2,3);
	cout << "v1=" << v1;
	Vec3d v2;
	cout << "v2=" << v2;
	Vec3d v3(4,5);
	Vec3d v4 = v1 + v3; 
	Vec3d v5 = v1 - v3;
	cout << "v1+v3=" << v4 << endl;
	cout << "v1-v3=" << v5 << endl; 
	double d1, di1, d2, di2;
	d1 = v1.dot(v4);
	d2 = dot(v1, v4);
	cout << "dot v1 v4:" << d1 << " "<< d2 << endl;
 	di1 = v1.dist(v4);
	di2 = dist(v1, v4);
	cout << "dist v1 v4:" << di1 << " " << di2 << endl;
	
	Vec3d v6, v7;
	v6 = v1 * 2;
	v7 = 2 * v1;
	cout << "v1=" << v1 << endl;
	cout << "v6=" << v6 << endl;
	cout << "v7=" << v7 << endl;
*/

	Vec3d a(1.0, 2.5, 3.0);
	cout << "a=" << a << endl;
	Vec3d b(1.0, 2.5); // z=0
	cout << "b=" << b << endl;
	Vec3d c(1.0); // y,z = 0
	cout << "c=" << c << endl;
	Vec3d d; // x,y,z=0
	cout << "d=" << d << endl;
	//	Vec3d e(); //THIS IS A FUNCTION!!!
	Vec3d e = a * 2; // scalar multiplication
	cout << "e=" << e << endl;
	Vec3d f = 2 * a; // reverse direction
	cout << "f=" << f << endl;
	Vec3d g = a + b; // vector addition
	cout << "g=" << g << endl;
	Vec3d h = a - b; // vector subtraction
	cout << "h=" << h << endl;
	double z1 = dot(a,b); // function
	double z2 = a.dot(b); // method
	cout << "z1=" << z1 << " z2=" << z2 << endl;
	// add static later
	double w1 = a.dist(b);
	double w2 = dist(a,b);
	cout << "w1=" << w1 << " w2=" << w2 << endl;
	return 0;	
}

