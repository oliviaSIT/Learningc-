#include <iostream>
#include <fstream>
#include <string>
#include <array>

using namespace std;

class GameLife {
public:
    GameLife(): 
        generation(0),
        frequency(0)
    {
        L[3][3] = {};
    }

    void read(string file) {
        ifstream fs(file);
        for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			fs >> L[i][j];
		}
	}

        fs.close();
	for (int i = 0; i <= 2; i++) {
                for (int j = 0; j <= 2; j++) {
                        cout << L[i][j];
                }
	cout << endl;
        }

    }

private:
    int generation;
    int frequency;
    int L[10][10];
};

int main() {
    GameLife solution;
    solution.read("test.dat");
}
