//author: Jiabin.Li

#include <iostream>
#include <cstdint>
#include <iomanip>
#include <bitset>

using namespace std;

class Bitmap {
private:
	uint32_t* rgba;
	uint32_t rows,cols;
public:
	Bitmap() {
		rgba = new uint32_t[1];
		rows = 0;
		cols = 0;
	}   

	Bitmap(uint32_t r, uint32_t c) {
		rows = r;
                cols = c;
		rgba = new uint32_t[r * c];
		for (uint32_t i = 0; i < r * c; i++) {
			rgba[i] = 0;
		}
	}

	// copy constructor
        Bitmap(const Bitmap& orig): rgba(new uint32_t[orig.rows * orig.cols]),
                                    rows(orig.rows),
                                    cols(orig.cols) {
                                        for (uint32_t i = 0; i < rows * cols; ++i)
                                                rgba[i] = orig.rgba[i];
                                }


        Bitmap& operator=(const Bitmap& orig) {
                Bitmap copy(orig);
                swap(copy.rgba,rgba);
                rows = copy.rows;
                cols = copy.cols;

                return *this;
        }
/*
	uint32_t operator()(uint32_t c, uint32_t r) {
                return rgba[r * cols + c];
        }
	
*/
	uint32_t& operator()(uint32_t c, uint32_t r) {
                return rgba[r * cols + c];
        }

	
        ~Bitmap() {
            delete [] rgba;
        }

	Bitmap& horizLine(uint32_t c1, uint32_t c2, uint32_t r, uint32_t x) {
		for (uint32_t i = c1; i <= c2; i++) {
			rgba[r * cols + i] = x;
		}
		return *this;
	}

	Bitmap& vertLine(uint32_t r1, uint32_t r2, uint32_t c, uint32_t x) {
                for (uint32_t i = r1; i <= r2; i++) {
                        rgba[i * cols + c] = x;
                }
                return *this;
        }
	
	friend ostream& operator<<(ostream& s, const Bitmap& a);	

};

ostream& operator<<(ostream& s, const Bitmap& a) {
	bitset<32> rgb;
	bitset<8> r, g, b;
	for (uint32_t i = 0; i < a.rows; i++) {
                for (uint32_t j = 0; j< a.cols; j++) {
			rgb = a.rgba[i * a.cols + j];
			for (size_t k = 0; k < 8; k++) {
		                b[k] = rgb[k];
				g[k] = rgb[k + 8];
				r[k] = rgb[k + 16];
			}
			s << setw(10) << b.to_ulong() << "," << g.to_ulong() << "," << r.to_ulong() << " ";
                }
		s << endl;		
	}
	return s;
}

int main() {
	Bitmap b1(3,5); // rows,cols 
	cout << b1;
	Bitmap b2(10,20);
	b2.horizLine(3, 15, 0, 0xFF00FF); // go from (3,0) to (15,0) writing color
	b2.vertLine(0, 8, 0, 0x000100);// go from (0,0) to (0,8) writing color
	cout << b2;
	uint32_t y = b2(0,8);
	cout << y << endl;

/*	uint32_t x =16711935;
	bitset<32> rgb(x);
	bitset<8> r, g, b;
	for (size_t i = 0; i < 8; i++) 
		b[i] = rgb[i + 8]; 	
	cout << b << endl;
*/
	return 0;
}	
