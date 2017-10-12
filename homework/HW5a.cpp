#include <iostream>

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

	friend ostream& operator<<(ostream &s, const Vec3d &v) {
		s << "{" << v.x << "," << v.y << "," << v.z << "}" << endl;
        	return s;
	} 

	friend Vec3d operator+(Vec3d &v1, Vec3d &v2);
	friend Vec3d operator-(Vec3d &v1, Vec3d &v2);
	friend Vec3d operator*(Vec3d &v, double n);

};

Vec3d operator+(Vec3d &v1, Vec3d &v2) {
                Vec3d v;
                v.x = v1.x + v2.x;
                v.y = v1.y + v2.y;
                v.z = v1.z + v2.z;
                return v;
        }

Vec3d operator-(Vec3d &v1, Vec3d &v2) {
                Vec3d v;
                v.x = v1.x - v2.x;
                v.y = v1.y - v2.y;
                v.z = v1.z - v2.z;
                return v;
        }



int main() {
	Vec3d v1(1,2,3);
	cout << "v1=" << v1;
	Vec3d v2;
	cout << "v2=" << v2;
	Vec3d v3(4,5);
	Vec3d v4; 
	v4 = v1 + v3;
	cout << "v4=" << v4 << endl;
//	v2 =+ v3;
//	cout << "v2=+v3:" << v2 << endl; 
	return 0;	
}

