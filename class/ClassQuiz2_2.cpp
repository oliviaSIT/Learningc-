#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

class Image {
private:
	uint32_t *rgba;
	int rows, cols;

public:
	Image(uint32_t *rgba = new uint32_t[], int r = 0, int c = 0): rgba(rgba),
								      rows(r),
								      cols(c) {
		for (size_t i = 0; i < rows * cols; i++) {
			rgba[i] = 0;
		}
	}

	Image(const Image &im) {
		rgba = new uint32_t[im.rows * im.cols];
		rows = im.rows;
		cols = im.cols;
		for (size_t i = 0; i < rows * cols; i++) {
                        rgba[i] = im.rgba[i];
                }
	}

	friend ostream& operator<<(ostream &s, const Image &im);
};

ostream& operator<<(ostream &s, const Image &im) {
	for (size_t i = 0; i < im.rows * im.cols; i++) {
		
	}
}
