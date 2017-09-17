#include <iostream>
#include <cstdint>
#include <string>
using namespace std;

int main() {
 uint8_t a = 0;// 0,...,255 sizeof(a)
 uint16_t b = 0;//0 .. 65535
 uint32_t c = 1241241;
 uint64_t d = 0;

 int32_t i = -1241;
 
 bool x =false;// sizeof(x)
 x = true;

 double d1 = 1.2345; // sizeof(d1) == 8 possible computer = 1
 char y = 'x';
 y = '\n'; // \t tab \xof character 0*16+15
 float f = 1.5f;
 long double d2 = 1.2345L;
 y = '\''; // quote
 y = '\\'; // backslash
 string s = "abc";
 return 0;
}


