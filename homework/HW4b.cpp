//author: Jiabin.Li

#include <iostream>
#include <cstdint>

using namespace std;

class Matrix {
private:
	double* m;
	uint32_t rows, cols;
public:
	Matrix() {
		m = new double[]
		rows = 0;
		cols = 0;
	}

	Matrix(uint32_t rows, uint32_t cols, double val = 0) {
		m = new double[rows * cols];
		for (uint32_t i = 0; i < rows * cols; ++i)
			m[i] = val;
	}


// copy constructor
	Matrix(const Matrix& orig) : m(new double[orig.rows * orig.cols]),			       
			             rows(orig.rows),
                                     cols(orig.cols) {
					for (uint32_t i = 0; i < rows *cols; ++i)
						m[i] = orig.m[i];
				}	

// =
	Matrix& operator = (const Matrix& orig) {
		Matrix copy(orig);
		swap(copy.m,m);
		rows = orig.rows;
		cols = orig.cols;
	
		return this; 
	}

        ~Matrix() {
            delete [] m;

        //return m[r][c]
	double& operator ()(uint32_t r, uint32_t c) {
		return m[r*cols + c];
	}

	
	friend Matrix operator +(const Matrix& a, const Matrix& b);  
	friend Matrix operator -(const Matrix& a, const Matrix& b); 
	friend Matrix operator *(const Matrix& a, const Matrix& b);
	friend ostream& operator <<(ostream& s, const Matrix& a); 
};

	Matrix operator +(const Matrix& a, const Matrix& b) {
                Matrix result(a.rows, a.cols);
               	for (uint32_t i = 0; i < a.rows * a.cols; i++)
                      result.m[i] = a.m[i] + b.m[i];

               	return result;
        }

	Matrix operator -(const Matrix& a, const Matrix& b) {
                Matrix result(a.rows, a.cols);
                for (uint32_t i = 0; i < a.rows * a.cols; i++)
                      result.m[i] = a.m[i] - b.m[i];

                return result;
        }

	ostream& operator <<(ostream& s, const Matrix& a) {
                for (uint32_t i = 0; i < a.rows; i++) {
                        for (uint32_t j = 0; j< a.cols; j++) {
                                s << a.m[i * rows + j];
                        }
                s << '\n';
                }
                return s;
        }



int main() {
	Matrix a(3,4, 5.2); 
	Matrix b(3,4); 
	cout << a << endl;

	Matrix c(3,4,1.2);

	cout << c(2,2) << endl;
	c(0,0) = -1.5;
	cout << c << endl

	Matrix d = a + c;
	cout << d << endl;

	Matrix e = a - c;
	cout << e << endl;

	//optional
	Matrix f(4,3,1.5);
	Matrix g = f * b; // matrix multiplication
	cout << g << endl;
}
