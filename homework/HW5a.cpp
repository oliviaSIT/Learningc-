#include <iostream>
#include <cmath>

using namespace std;

class Vec3d {
private:
	double x, y, z;
public:
	Vec3d(double x = 0, double y = 0, double z = 0): x(x), y(y), z(z) {
	}

	Vec3d(Vec3d &v) {
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

	Vec3d& operator+(Vec3d &v1) {
               // Vec3d v;
                x = v1.x + x;
                y = v1.y + y;
                z = v1.z + z;
                return *this;
        }

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

//	friend Vec3d operator+(Vec3d &v1, Vec3d &v2);
	friend Vec3d operator-(const Vec3d &v1, const Vec3d &v2);
	friend Vec3d operator*(const Vec3d &v1, const double &scale);
	friend Vec3d operator*(const double &scale, const Vec3d &v1);
	friend double dot(const Vec3d &v1, const Vec3d &v2);
	friend double dist(const Vec3d &v1, const Vec3d &v2);
};

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
	Vec3d v1(1,2,3);
	cout << "v1=" << v1;
	Vec3d v2;
	cout << "v2=" << v2;
	Vec3d v3(4,5);
	Vec3d v4; 
	v4 = v1 - v3; 
	double d, di;
//	d = v1.dot(v4);
//	cout << "v4=" << v4 << endl;
	d = dot(v1, v4);
	cout << "dot v1 v4:" << d << endl;
 	di = dist(v1, v4);
	cout << "dist v1 v4:" << di << endl;
	
	Vec3d v5;
	v5 = v1 * 2;
	cout << "v5=" << v5 << endl;

	return 0;	
}

