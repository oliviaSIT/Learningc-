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
	Matrix() {
		m = new double[1];
		rows = 1;
		cols = 1;
	}

	Matrix(uint32_t r, uint32_t c, double val = 0) {
		m = new double[r * c];
		for (uint32_t i = 0; i < r * c; ++i)
			m[i] = val;

		rows = r;
		cols = c;
	}

// copy constructor
	Matrix(const Matrix& orig) : m(new double[orig.rows * orig.cols]),			       
			             rows(orig.rows),
                                     cols(orig.cols) {
					for (uint32_t i = 0; i < rows * cols; ++i)
						m[i] = orig.m[i];
				}	


	Matrix& operator = (const Matrix& orig) {
		Matrix copy(orig);
		swap(copy.m,m);
		rows = copy.rows;
		cols = copy.cols;
	
		return *this; 
	}
	
	double& operator ()(uint32_t r, uint32_t c) {
		return m[r * cols + c];
	}

        ~Matrix() {
            delete [] m;

        }

	friend ostream& operator <<(ostream& s, const Matrix& a); 
	friend Matrix operator +(const Matrix& a, const Matrix& b); 
	friend Matrix operator -(const Matrix& a, const Matrix& b);
	friend Matrix operator *(const Matrix& a, const Matrix& b);
};

ostream& operator <<(ostream& s, const Matrix& a) {
                for (uint32_t i = 0; i < a.rows; i++) {
                        for (uint32_t j = 0; j< a.cols; j++) {
                                s << a.m[i * a.cols + j] << ' ';
                        }
                s << '\n';
                }
                return s;
        }

Matrix operator +(const Matrix& a, const Matrix& b) {
		if (a.rows != b.rows || a.cols != b.cols)
			throw BadSize();

                Matrix result(a.rows, a.cols);
               	for (uint32_t i = 0; i < a.rows * a.cols; i++)
                      result.m[i] = a.m[i] + b.m[i];

               	return result;
        }

Matrix operator -(const Matrix& a, const Matrix& b) {
		if (a.rows != b.rows || a.cols != b.cols)
                        throw BadSize();

                Matrix result(a.rows, a.cols);
                for (uint32_t i = 0; i < a.rows * a.cols; i++)
                      result.m[i] = a.m[i] - b.m[i];

                return result;
        }

Matrix operator *(const Matrix& a, const Matrix& b) {
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
	Matrix m1(3,4); 
	m1(1,2) = 1.5;
	m1(2,2) = -1.0; 
	cout << m1 << endl;

	Matrix m2(3,4,3.0);

	try {
		cout << m2(1,1) << endl;
		Matrix m3 = m1 + m2;
		Matrix m4(2,2);
		Matrix m5 = m1 + m4; // not the same size!!!!!!
	} catch(const BadSize& e) {
		cout << "Matrices of two different size" << endl;
	}

//optional
	Matrix m(4,3,1.5);
	Matrix ans = m * m1; // matrix multiplication
	cout << ans << endl;

	return 0;
}
