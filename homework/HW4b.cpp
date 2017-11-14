//author: Jiabin.Li

#include <iostream>
#include <cstdint>
#include <utility>

class BadSize {
	
};

using namespace std;

class Matrix {
private:
	double* m;
	uint32_t rows, cols;
public:
	Matrix(uint32_t r = 0, uint32_t c = 0, double val = 0) {
		m = new double[r * c];
		for (uint32_t i = 0; i < r * c; ++i)
			m[i] = val;

		rows = r;
		cols = c;
	}

// copy constructor
	Matrix(const Matrix &orig) : m(new double[orig.rows * orig.cols]),			       
			             rows(orig.rows),
                                     cols(orig.cols) {
					for (uint32_t i = 0; i < rows * cols; ++i)
						m[i] = orig.m[i];
				}	


	Matrix& operator=(const Matrix &orig) {
		Matrix copy(orig);
		swap(copy.m,m);
		rows = copy.rows;
		cols = copy.cols;
	
		return *this; 
	}
	
	double& operator()(uint32_t r, uint32_t c) {
		return m[(r - 1) * cols + c - 1];
	}

        ~Matrix() {
            delete [] m;

        }

	friend ostream& operator<<(ostream& s, const Matrix& a); 
	friend Matrix operator+(const Matrix &a, const Matrix &b); 
	friend Matrix operator-(const Matrix &a, const Matrix &b);
	friend Matrix operator*(Matrix &a, Matrix &b);
};

ostream& operator<<(ostream &s, const Matrix &a) {
                for (uint32_t i = 0; i < a.rows; i++) {
                        for (uint32_t j = 0; j< a.cols; j++) {
                                s << a.m[i * a.cols + j] << ' ';
                        }
                s << '\n';
                }
                return s;
        }

Matrix operator+(const Matrix &a, const Matrix &b) {
		if (a.rows != b.rows || a.cols != b.cols)
			throw BadSize();

                Matrix result(a.rows, a.cols);
               	for (uint32_t i = 0; i < a.rows * a.cols; i++)
                      result.m[i] = a.m[i] + b.m[i];

               	return result;
        }

Matrix operator-(const Matrix &a, const Matrix &b) {
		if (a.rows != b.rows || a.cols != b.cols)
                        throw BadSize();

                Matrix result(a.rows, a.cols);
                for (uint32_t i = 0; i < a.rows * a.cols; i++)
                      result.m[i] = a.m[i] - b.m[i];

                return result;
        }

Matrix operator*(Matrix &a, Matrix &b) {
		if (a.cols != b.rows)
                        throw BadSize();

                Matrix result(a.rows, b.cols);
                for (uint32_t i = 0; i < a.rows; i++) {
			for (uint32_t j = 0; j < b.cols; j++) {
				for(uint32_t l = 0; l < a.cols; l++) {
                 			result.m[i * a.cols + j] += a.m[i * a.cols + l] * b.m[l * b.cols + j];
				}       
			}
		}
                return result;
        }



int main() {

//optional
	Matrix m1(3,3,1);
	m1(2,2) = 2;
	m1(3,1) = 3;
/*	for (uint32_t i = 0; i < 3; i++ ) {
		for (uint32_t j = 0; j < 3; j++) {
			m1(i,j) = i + j;
		}
	}
*/	
	cout << m1 << endl;
	Matrix m2 (3,3);
	m2(1,1) = 1;
	m2(2,2) = 1;
	m2(3,3) = 1;
	cout << m2 << endl;
	Matrix m3;
	m3 = m1 * m2; // matrix multiplication
	cout << m3 << endl;

	return 0;
}
