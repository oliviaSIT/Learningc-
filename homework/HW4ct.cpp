#include <iostream>
#include <cstdint>
#include <iomanip>

using namespace std;

int main() {
	uint32_t i = 0xFFFFFF;
	uint32_t r = i >> 16 & 0xFF;
	uint32_t g = i >> 8 & 0xFF;
	uint32_t b = i & 0xFF;
	cout << setw(4);
	cout << i << " " << r << " " << g <<  " " << b << endl;

	return 0;
}
