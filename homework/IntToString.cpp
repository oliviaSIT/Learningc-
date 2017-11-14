#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ofstream fs;
//	int x = 6, y = 7;
//	fs.open("IntToString.txt");
	for(int i = 0; i < 3; i++) {
		fs.open("IntToString.txt", ios::app);
		fs << i;
		fs.close();
	}
//	fs.close();
	return 0;
}
